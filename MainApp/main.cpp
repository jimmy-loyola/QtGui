#include <Qt/QApplication.h>
#include <Qt/QMainWindow.h>
#include "MainApp.h"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  MainApp mainGuiApp;
  mainGuiApp.show();

  return app.exec();
}
