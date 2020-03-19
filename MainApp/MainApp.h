#pragma once

#include "ui_MainApp.h"
#include <QWidget>

class MainApp : public QWidget
{
  Q_OBJECT

public:
  MainApp(QWidget *parent = nullptr);
  ~MainApp();

private:
  Ui::MainApp ui;
};
