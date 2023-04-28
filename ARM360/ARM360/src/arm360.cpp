#include "stdafx.h"
#include "arm360.h"
#include "Orchestrator.h"
#include <qfiledialog.h>
#include <qfile.h>
#include <qmessagebox.h>
#include <QRegularExpression.h> 
#include <array>
#include <iostream>
#include <fstream>
#include "Hex4Digit.h"

//Orchestrator * orchestrator;
// Global Variables
//Orchestrator* orc;// = Orchestrator::getInstance();
//int totalStates;// = 0;
//bool badBool;// = false;
//std::string programFile;

ARM360::ARM360(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    connect(ui.btnLoad, &QPushButton::clicked, this, &ARM360::onLoadClicked);
    connect(ui.btnDTH, &QPushButton::clicked, this, &ARM360::onDecimalToHexClicked);
    connect(ui.btnHTD, &QPushButton::clicked, this, &ARM360::onHexToDecimalClicked);
    connect(ui.btnBuild, &QPushButton::clicked, this, &ARM360::onBuildClicked);
    connect(ui.btnAbort, &QPushButton::clicked, this, &ARM360::abortProgram);
    connect(ui.btnRun, &QPushButton::clicked, this, &ARM360::runProgram);
    connect(ui.btnNext, &QPushButton::clicked, this, &ARM360::executeStep);

    orc = Orchestrator::getInstance();
    totalStates = 0;
    badBool = false;
    // Make the window transparent
    setStyleSheet("background-color: ;");
}

/// <summary>
/// Sets the current file name of the program to run.
/// </summary>
void ARM360::setCurrentProgram(std::string file){
    programFile = file;
}

/// <summary>
/// Updates the file contents with what is currently in the text box.
/// </summary>
void ARM360::updateFileWithInput() {
    std::ofstream fileToWrite;
    fileToWrite.open(programFile);
    fileToWrite << ui.txtInput->toPlainText().toStdString();
    fileToWrite.close();
    programFileContents = ui.txtInput->toPlainText().toStdString();
}

/// <summary>
/// Loads the contents of the chosen file into the text box and sets that file as the program to run.
/// </summary>
void ARM360::onLoadClicked() {

    // Just sets the text field to the contents of a txt file for now
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Text Files (*.txt)"));
    //Orchestrator * orchestrator = Orchestrator::getInstance();

    if (fileName != "")
    {
        QFile file(fileName);

        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::warning(this, tr("Warning"), tr("Cannot open file: %1").arg(file.errorString()));
            return;
        }
        setCurrentProgram(fileName.toStdString());
        QTextStream in(&file);
        QString fileContents = in.readAll();
        ui.txtInput->setText(fileContents);
        file.close();
    }
}

/// <summary>
/// Converts a given decimal number to hex
/// </summary>
void ARM360::onDecimalToHexClicked() {
    QString userDecimalInput = ui.txtDecimal->toPlainText();

    // Empty input
    if (userDecimalInput.length() == 0) {
        QMessageBox::warning(this, tr("Warning"), tr("Decimal to Hex convertion input is empty."));
        return;
    }

    // Error handling for non-digit inputs
    QRegularExpression reg("[^\\d]");
    QRegularExpressionMatch match = reg.match(userDecimalInput);
    if (match.hasMatch()) {
        QMessageBox::warning(this, tr("Warning"), tr("The input contains non-digit inputs. Please only use digits for Decimal to Hex conversion."));
        return;
    }

    int decimal = userDecimalInput.toInt();
    std::string hexOutput(HexadecimalConverter::decimalToHex(decimal).data());
    QString hexAsQString = QString::fromStdString(hexOutput);
    hexAsQString = hexAsQString.remove(5, 3); // Removing weird '???' after the conversion(last 3 characters)

    ui.txtDTHOutput->clear();
    ui.txtDTHOutput->insertPlainText(hexAsQString);
    ui.txtDTHOutput->setStyleSheet("background-color: yellow");

}

/// <summary>
/// Converts a given hex number to decimal
/// </summary>
void ARM360::onHexToDecimalClicked() {
    QString userHexInput = ui.txtHex->toPlainText();

    // Empty input
    if (userHexInput.length() == 0) {
        QMessageBox::warning(this, tr("Warning"), tr("Hex to Decimal convertion input is empty."));
        return;
    }

    // Error handling for non-digit & non-[a-f] inputs
    QRegularExpression reg("[^a-f\\d]");
    QRegularExpressionMatch match = reg.match(userHexInput);
    if (match.hasMatch()) {
        QMessageBox::warning(this, tr("Warning"), tr("The input contains non-hex inputs. Please only use digits & a-f for Decimal to Hex conversion."));
        return;
    }

    // Convert QString to a char[]
    QByteArray array = userHexInput.toLocal8Bit().constData();
    char* buffer = array.data();

    int decimal = HexadecimalConverter::hexToDecimal(buffer);

    // Convert int back into a QString
    std::string decimalAsString = std::to_string(decimal);
    QString decimalAsQString = QString::fromStdString(decimalAsString);

    ui.txtHTDOutput->clear();
    ui.txtHTDOutput->insertPlainText(decimalAsQString);
    ui.txtHTDOutput->setStyleSheet("background-color: yellow");

}

// Function to convert a std::array<char> to a QString.
QString arrayToQString(std::array<char, 5> input) {
    QString string = "";
    for (int i = 0; i < input.size(); i++) {
        QString str = QChar(input[i]);
        string += str;
    }
    return string;
}
/// <summary>
/// Populates registers 0 - e with memory register character. This should be called whenever next is called.
/// </summary>
void ARM360::getRegisters() {
    clearRegisters();
    ProgramState* program = orc->getProgramState();
    highlightRegisters();
    ui.txtR0->insertPlainText(arrayToQString(program->registers[0].getHexChars()));
    ui.txtR1->insertPlainText(arrayToQString(program->registers[1].getHexChars()));
    ui.txtR2->insertPlainText(arrayToQString(program->registers[2].getHexChars()));
    ui.txtR3->insertPlainText(arrayToQString(program->registers[3].getHexChars()));
    ui.txtR4->insertPlainText(arrayToQString(program->registers[4].getHexChars()));
    ui.txtR5->insertPlainText(arrayToQString(program->registers[5].getHexChars()));
    ui.txtR6->insertPlainText(arrayToQString(program->registers[6].getHexChars()));
    ui.txtR7->insertPlainText(arrayToQString(program->registers[7].getHexChars()));
    ui.txtR8->insertPlainText(arrayToQString(program->registers[8].getHexChars()));
    ui.txtR9->insertPlainText(arrayToQString(program->registers[9].getHexChars()));
    ui.txtRa->insertPlainText(arrayToQString(program->registers[10].getHexChars()));
    ui.txtRb->insertPlainText(arrayToQString(program->registers[11].getHexChars()));
    ui.txtRc->insertPlainText(arrayToQString(program->registers[12].getHexChars()));
    ui.txtRd->insertPlainText(arrayToQString(program->registers[13].getHexChars()));
    ui.txtRe->insertPlainText(arrayToQString(program->registers[14].getHexChars()));

    ui.txtPC->insertPlainText(arrayToQString(program->registers[15].getHexChars()));
    ui.txtOut->insertPlainText(QString::fromStdString((program->output.getString())));

    if (ui.txtPC->toPlainText().compare("+0000") != 0) {
        //highlight the register PC
        ui.txtPC->setStyleSheet("background-color: yellow");
        ui.txtPC->clear();
        ui.txtPC->setTextBackgroundColor(Qt::yellow);
        ui.txtPC->insertPlainText(arrayToQString(program->registers[15].getHexChars()));
    }
    if (ui.txtOut->toPlainText().compare("+0000") != 0) {
        //highlight the register Out
        ui.txtOut->setStyleSheet("background-color: yellow");
        ui.txtOut->clear();
        ui.txtOut->setTextBackgroundColor(Qt::yellow);
        ui.txtOut->insertPlainText(QString::fromStdString((program->output.getString())));
    }
}

void ARM360::highlightRegisters() {
    ProgramState* program = orc->getProgramState();

    // Set the text background color to yellow if the value of the register is not the default

    if (program->registers[0].getHexChars() != std::array<char, 5>{'+', '0', '0', '0', '0'}) {
        ui.txtR0->setStyleSheet("background-color: yellow");
        ui.txtR0->setTextBackgroundColor(Qt::yellow);
    }
    if (program->registers[1].getHexChars() != std::array<char, 5>{'+', '0', '0', '0', '0'}) {
        ui.txtR1->setStyleSheet("background-color: yellow");
        ui.txtR1->setTextBackgroundColor(Qt::yellow);
    }
    if (program->registers[2].getHexChars() != std::array<char, 5>{'+', '0', '0', '0', '0'}) {
        ui.txtR2->setStyleSheet("background-color: yellow");
        ui.txtR2->setTextBackgroundColor(Qt::yellow);
    }
    if (program->registers[3].getHexChars() != std::array<char, 5>{'+', '0', '0', '0', '0'}) {
        ui.txtR3->setStyleSheet("background-color: yellow");
        ui.txtR3->setTextBackgroundColor(Qt::yellow);
    }
    if (program->registers[4].getHexChars() != std::array<char, 5>{'+', '0', '0', '0', '0'}) {
        ui.txtR4->setStyleSheet("background-color: yellow");
        ui.txtR4->setTextBackgroundColor(Qt::yellow);
    }
    if (program->registers[5].getHexChars() != std::array<char, 5>{'+', '0', '0', '0', '0'}) {
        ui.txtR5->setStyleSheet("background-color: yellow");
        ui.txtR5->setTextBackgroundColor(Qt::yellow);
    }
    if (program->registers[6].getHexChars() != std::array<char, 5>{'+', '0', '0', '0', '0'}) {
        ui.txtR6->setStyleSheet("background-color: yellow");
        ui.txtR6->setTextBackgroundColor(Qt::yellow);
    }
    if (program->registers[7].getHexChars() != std::array<char, 5>{'+', '0', '0', '0', '0'}) {
        ui.txtR7->setStyleSheet("background-color: yellow");
        ui.txtR7->setTextBackgroundColor(Qt::yellow);
    }
    if (program->registers[8].getHexChars() != std::array<char, 5>{'+', '0', '0', '0', '0'}) {
        ui.txtR8->setStyleSheet("background-color: yellow");
        ui.txtR8->setTextBackgroundColor(Qt::yellow);
    }
    if (program->registers[9].getHexChars() != std::array<char, 5>{'+', '0', '0', '0', '0'}) {
        ui.txtR9->setStyleSheet("background-color: yellow");
        ui.txtR9->setTextBackgroundColor(Qt::yellow);
    }
    if (program->registers[10].getHexChars() != std::array<char, 5>{'+', '0', '0', '0', '0'}) {
        ui.txtRa->setStyleSheet("background-color: yellow");
        ui.txtRa->setTextBackgroundColor(Qt::yellow);
    }
    if (program->registers[11].getHexChars() != std::array<char, 5>{'+', '0', '0', '0', '0'}) {
        ui.txtRb->setStyleSheet("background-color: yellow");
        ui.txtRb->setTextBackgroundColor(Qt::yellow);
    }
    if (program->registers[12].getHexChars() != std::array<char, 5>{'+', '0', '0', '0', '0'}) {
        ui.txtRc->setStyleSheet("background-color: yellow");
        ui.txtRc->setTextBackgroundColor(Qt::yellow);
    }
    if (program->registers[13].getHexChars() != std::array<char, 5>{'+', '0', '0', '0', '0'}) {
        ui.txtRd->setStyleSheet("background-color: yellow");
        ui.txtRd->setTextBackgroundColor(Qt::yellow);
    }
    if (program->registers[14].getHexChars() != std::array<char, 5>{'+', '0', '0', '0', '0'}) {
        ui.txtRe->setStyleSheet("background-color: yellow");
        ui.txtRe->setTextBackgroundColor(Qt::yellow);
    }
}

void ARM360::clearRegisters() {
    ui.txtR0->setStyleSheet("");
    ui.txtR1->setStyleSheet("");
    ui.txtR2->setStyleSheet("");
    ui.txtR3->setStyleSheet("");
    ui.txtR4->setStyleSheet("");
    ui.txtR5->setStyleSheet("");
    ui.txtR6->setStyleSheet("");
    ui.txtR7->setStyleSheet("");
    ui.txtR8->setStyleSheet("");
    ui.txtR9->setStyleSheet("");
    ui.txtRa->setStyleSheet("");
    ui.txtRb->setStyleSheet("");
    ui.txtRc->setStyleSheet("");
    ui.txtRd->setStyleSheet("");
    ui.txtRe->setStyleSheet("");
    ui.txtPC->setStyleSheet("");
    ui.txtOut->setStyleSheet("");

    // Set the text background color to white for all registers
    ui.txtR0->setTextBackgroundColor(Qt::white);
    ui.txtR1->setTextBackgroundColor(Qt::white);
    ui.txtR2->setTextBackgroundColor(Qt::white);
    ui.txtR3->setTextBackgroundColor(Qt::white);
    ui.txtR4->setTextBackgroundColor(Qt::white);
    ui.txtR5->setTextBackgroundColor(Qt::white);
    ui.txtR6->setTextBackgroundColor(Qt::white);
    ui.txtR7->setTextBackgroundColor(Qt::white);
    ui.txtR8->setTextBackgroundColor(Qt::white);
    ui.txtR9->setTextBackgroundColor(Qt::white);
    ui.txtRa->setTextBackgroundColor(Qt::white);
    ui.txtRb->setTextBackgroundColor(Qt::white);
    ui.txtRc->setTextBackgroundColor(Qt::white);
    ui.txtRd->setTextBackgroundColor(Qt::white);
    ui.txtRe->setTextBackgroundColor(Qt::white);
    ui.txtOut->setTextBackgroundColor(Qt::white);
    ui.txtPC->setTextBackgroundColor(Qt::white);

    // Clear the text out of all registers
    ui.txtR0->clear();ui.txtR1->clear();ui.txtR2->clear();ui.txtR3->clear();
    ui.txtR4->clear();ui.txtR5->clear();ui.txtR6->clear();ui.txtR7->clear();
    ui.txtR8->clear();ui.txtR9->clear();ui.txtRa->clear();ui.txtRb->clear();
    ui.txtRc->clear();ui.txtRd->clear();ui.txtRe->clear();ui.txtPC->clear();
    ui.txtOut->clear();
}

/// <summary>
/// Builds the program once you load in a program via "load".
/// </summary>
void ARM360::onBuildClicked() {
    orc->clearProgram();
    totalStates = 0;
    setCurrentProgram(programFile);
    updateFileWithInput();

    if (programFile.empty()) {
        QMessageBox::warning(this, tr("Warning"), tr("There is no program to build. Please load a program before building."));
        return;
    }

    orc->translateAndLoad(programFile);
    ui.txtMemory->clear();

    totalStates = 0;
    badBool = false;
    //initializeMemoryTable(); 

    getRegisters();
}

// UI connection to display the memory table in the UI.
void ARM360::initializeMemoryTable() {}

// Stops the currently running program and clears the register states from the UI.
void ARM360::abortProgram() {
    orc->clearProgram();
    clearRegisters();
}

// Run the whole program until the end of file is reached or an error occurs.
void ARM360::runProgram() {
    //onBuildClicked();

    while (true) {
        if (orc->getProgramState()->registers[15].getValue() == -1) {
            QMessageBox::information(this, tr("Complete"), tr("The end of the file has been reached."));
            break;
        }

        if (orc->getError() == "Orchestrator: No Error.") {
            executeStep();
            //QMessageBox::warning(this, tr("Warning"), tr("successfully ran"));
        }

        else {
            std::string orcError = ("An error has occured when running the program: " + orc->getError());
            QMessageBox::warning(this, tr("Warning"), tr(orcError.c_str()));
            break;
        }
    }
}

// Executes the next line of the program.
void ARM360::executeStep() {
    bool displayEndMessage = false;
    incrimententTotalStates();

    getRegisters();

    try {
         //There was an error in building or running.
        if (orc->getError() != "Orchestrator: No Error.") {
            std::string orcError = ("An error has occured when executing the next step: " + orc->getError());
            QMessageBox::warning(this, tr("Warning"), tr(orcError.c_str()));

            abortProgram();
            orc->translateAndLoad(programFile);
        }

        // There are more instructions past this step.
        else if (orc->getProgramState()->registers[15].getValue() != -1) {
            if (ui.txtIn->toPlainText().toStdString().size() > 0) {
                orc->sendInput(vectorToCharArray(orc->convertToHexChars(stringToShort(ui.txtIn->toPlainText().toStdString()))));
            }
            orc->next();
        }

        else if (orc->getProgramState()->registers[15].getValue() == -1) {
            displayEndMessage = true;
        }
    }
    catch (const std::exception&) {
        std::string orcError = ("An unknown error has occured");
        QMessageBox::warning(this, tr("Warning"), tr(orcError.c_str()));
        return;
    }

    // Update RAM Values here if we get to implementing it.
        if (displayEndMessage) {
            QMessageBox::information(this, tr("Complete"), tr("The end of the file has been reached."));
        }
}

char* ARM360::vectorToCharArray(std::vector<char> vec) {
    char* array = new char[5];

    for (int i = 0; i < vec.size() && i < 5; i++) {
        array[i] = vec[i];
    }
    return array;
}

// Quick funtion to convert a string to a short, because c++ doesn't have a conversion itself for some reason.
// Not proper since it doesn't check the bound of the int vs short. (use std::numeric_limits<short>).
short ARM360::stringToShort(std::string str) {
    int stringAsInt = std::stoi(str);
    return (short) stringAsInt;
}

void ARM360::incrimententTotalStates() {
    totalStates += 1;
}

ARM360::~ARM360()
{}
