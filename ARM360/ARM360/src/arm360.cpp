#include "stdafx.h"
#include "arm360.h"
#include "Orchestrator.h"
#include <qfiledialog.h>
#include <qfile.h>
#include <qmessagebox.h>

Orchestrator * orchestrator;

ARM360::ARM360(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    // orchestrator = Orchestrator::getInstance();
    connect(ui.btnLoad, &QPushButton::clicked, this, &ARM360::onLoadClicked);
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

ARM360::~ARM360()
{}
