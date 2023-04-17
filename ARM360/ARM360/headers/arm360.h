#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_arm360.h"

class ARM360 : public QMainWindow
{
    Q_OBJECT

public:
    ARM360(QWidget *parent = nullptr);
    ~ARM360();

private:
    Ui::ARM360Class ui;

private slots:
    void onLoadClicked();
    void onDecimalToHexClicked();
    void onHexToDecimalClicked();
    void getRegisters();
    void onBuildClicked();
    void initializeMemoryTable();
    void setCurrentProgram(std::string program);
};
