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

//void ARM360::onBuildClicked() {
//    QString fileToBuild = ui.txtInput->toPlainText();
//    if (fileToBuild.length() == 0) {
//        QMessageBox::warning(this, tr("Warning"), tr("No file selected to run program."));
//        return;
//    }
//}

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
    QString intAsQString = QString::fromStdString(hexOutput);

    ui.txtDTHOutput->clear();
    ui.txtDTHOutput->insertPlainText(intAsQString);
}

ARM360::~ARM360()
{}
