// Header file inclusion
#include "MainApp.h"
#include <QDebug.h>
#include <QInputDialog.h>
#include <QMessageBox.h>

// Inclusion required because we need to instantiate
// a Ui::MainApp object on it's ui member pointer
#include "ui_MainApp.h"

// If you use the QObject parenting model in your application, you'll
// have much less memory to manage but it can collide with some new C++11
// semantics, specially with smart pointers.
MainApp::MainApp(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainApp)
{
  // Creates and initializes all the UI objects/widgets
  // instances defined in the MainApp.ui designer file.
  ui->setupUi(this);

  // Qt framework offers a flexible message-exchange mechanism that is composed
  // of signal, slot and the connect function that specifies which singal is
  // linked to which slot. Qt already provides signals and slots for it classes,
  // which you can use in your application. For example, QPushButton has signal
  // clicked(). Some signals and slots features
  // - A slot remains a normal c++ function, so you can call it yourself
  // - A single signal can be linked to different slots
  // - A single slot can be called by different linked signals
  // - A connection can be made between a signal and a slot from different objects,
  //   and even between objects living inside different threads
  // To connect a signal to a slot their methods' signature must much
  // Signal and slots never return values

  bool result = connect(
    ui->btn,               // Object that will send the signal
    SIGNAL(clicked()),     // The member signal function. We want do something when the clicked signal is triggered
    this,                  // Object that will receive and handle the signal
    SLOT(onBtnClick()) // Pointer to one of the receiver's member slot function
  );

  // You can connect a signal to another signal. The second signal will be emitted when the first one is triggered
}

// The ui pointer must be cleaned in the destructor
// This desctructor will be called when MainWindow releases its own
// memory by recursively iterating through its children and calling
// their destructor.
MainApp::~MainApp()
{
  delete ui;
}

void MainApp::onBtnClick()
{
  // Qt provides an efficient way of displaying the debug
  // information with the QDebug class.
  qDebug() << "Clicked on btn button";
  bool ok;

  QString value = QInputDialog::getText(
    this,                    // Parent QWidget to which QInputDialog is attached
    tr("Dialog title"),      // Dialog title
    tr("Input Label"),       // Input label
    QLineEdit::Normal,
    tr("Input placeholder"), // Input placeholder
    &ok                      // True if OK is pressed false for cancel
  );

  QString msg;

  if (ok)
    msg = value.isEmpty() ? "Value empty" : value;
  else
    msg = "Cancel clicked";

  QMessageBox::information(this, "Inserted value", msg);
}
