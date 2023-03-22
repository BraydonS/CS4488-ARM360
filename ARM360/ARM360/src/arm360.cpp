#include "stdafx.h"
#include "arm360.h"
#include "Orchestrator.h"
#include <qfiledialog.h>
#include <qfile.h>
#include <qmessagebox.h>
#include <QRegularExpression.h> 
Orchestrator * orchestrator;

ARM360::ARM360(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    // orchestrator = Orchestrator::getInstance();
    connect(ui.btnLoad, &QPushButton::clicked, this, &ARM360::onLoadClicked);
    connect(ui.btnDTH, &QPushButton::clicked, this, &ARM360::onDecimalToHexClicked);
    connect(ui.btnHTD, &QPushButton::clicked, this, &ARM360::onHexToDecimalClicked);
}

void ARM360::onLoadClicked() {
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
    QByteArray array = userHexInput.toLocal8Bit();
    char* buffer = array.data();

    int decimal = HexadecimalConverter::hexToDecimal(buffer);

    // Convert int back into a QString
    std::string decimalAsString = std::to_string(decimal);
    QString decimalAsQString = QString::fromStdString(decimalAsString);

    ui.txtHTDOutput->clear();
    ui.txtHTDOutput->insertPlainText(decimalAsQString);
}

ARM360::~ARM360()
{}
