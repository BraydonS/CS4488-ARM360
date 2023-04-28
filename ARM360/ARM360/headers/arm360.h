#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_arm360.h"
#include "Orchestrator.h"

class ARM360 : public QMainWindow
{
    Q_OBJECT

public:
    ARM360(QWidget *parent = nullptr);
    ~ARM360();

private:
    Ui::ARM360Class ui;
    void incrimententTotalStates();
    void executeStep();
    void highlightRegisters();
    void clearRegisters();
    void initializeMemoryTable();
    void getRegisters();
    short stringToShort(std::string);
    char* vectorToCharArray(std::vector<char> vector);
    void setCurrentProgram(std::string file);
    void updateFileWithInput();
    Orchestrator* orc;
    int totalStates;
    bool badBool;
    std::string programFile;
    std::string programFileContents;

private slots:
    void onLoadClicked();
    void onDecimalToHexClicked();
    void onHexToDecimalClicked();
    void onBuildClicked();
    void abortProgram();
    void runProgram();
};
