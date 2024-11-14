#pragma once

#include <QtWidgets/QDialog>
#include "ui_plugincenter.h"

class OPMMainWindow : public QDialog
{
    Q_OBJECT

public:
    OPMMainWindow(QWidget *parent = nullptr);
    ~OPMMainWindow();

public:
    void showOPMWindow();

private:
    Ui::OBSPluginManagement ui;
};
