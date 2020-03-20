#include "MainApp.h"
#include <QMessageBox.h>

MainApp::MainApp(QWidget *parent)
  : QWidget(parent)
{
  ui.setupUi(this);

  // Connect button signal to appropriate slot
  connect(ui.testBtn, SIGNAL(clicked()), this, SLOT(onTestBtnClick()));
}

MainApp::~MainApp()
{
}

void MainApp::onTestBtnClick()
{
  QMessageBox::information(this, "Test Button", "Test Button click");
}
