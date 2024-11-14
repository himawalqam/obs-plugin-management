#include <obs-module.h>
#include "opm_main_window.h"

OPMMainWindow::OPMMainWindow(QWidget *parent)
    : QDialog(parent)
{
    ui.setupUi(this);

    setWindowTitle(QString(obs_module_text("opm.PluginCenterWindowText")));
}

OPMMainWindow::~OPMMainWindow() {

}

void OPMMainWindow::showOPMWindow()
{
    setVisible(true);
}
