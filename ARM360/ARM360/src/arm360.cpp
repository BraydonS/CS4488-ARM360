#include "stdafx.h"
#include "arm360.h"
#include "Orchestrator.h"
#include <qfiledialog.h>
#include <qfile.h>
#include <qmessagebox.h>
#include <QRegularExpression.h> 
#include "Hex4Digit.h"
Orchestrator * orchestrator;

ARM360::ARM360(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    connect(ui.btnLoad, &QPushButton::clicked, this, &ARM360::onLoadClicked);
    connect(ui.btnDTH, &QPushButton::clicked, this, &ARM360::onDecimalToHexClicked);
    connect(ui.btnHTD, &QPushButton::clicked, this, &ARM360::onHexToDecimalClicked);
}

void ARM360::onLoadClicked() {

    // orchestrator = Orchestrator::getInstance();
    // Just sets the text field to the contents of a txt file for now
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Text Files (*.txt)"));

    if (fileName != "")
    {
        QFile file(fileName);

        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::warning(this, tr("Warning"), tr("Cannot open file: %1").arg(file.errorString()));
            return;
        }

        QTextStream in(&file);
        ui.txtInput->setText(in.readAll());
        file.close();
    }
}

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
}


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
}

// Function to convert a std::array<char> to a QString.
QString arrayToQString(std::array<char, 5> input) {
    QString string;
    for (int i = 0; i < input.size(); i++) {
        QString str = QString::number(input[i]);
        string = string + str;
    }
    return string;
}

// Populates Regesters 0 - e with memory register character. This should be called whenever next is called.
void ARM360::getRegisters() {
    Orchestrator* orc = Orchestrator::getInstance();
    ProgramState* program = orc->getProgramState();
    //QString test = arrayToQString(program->registers[0].getHexChars());
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
}

ARM360::~ARM360()
{}
