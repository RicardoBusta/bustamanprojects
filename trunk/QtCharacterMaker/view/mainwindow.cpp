#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "qtcharactermaker.h"
#include "view/actions.h"
#include "view/canvaswidgetcontainer.h"
#include "translations/tokens.h"

#include <QDebug>
#include <QLabel>
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  connect(ui->actionOpen,SIGNAL(triggered()),this,SLOT(OpenImage()));
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::OpenImage()
{
  qDebug() << "Open Image" ;
  QStringList open_files = QFileDialog::getOpenFileNames(this,kTranslationOpenImageFile);

  QStringList::iterator open_files_it = open_files.begin();
  for(;open_files_it!=open_files.end();open_files_it++){
    const QString file_name = *open_files_it;

    OpenImageCanvas(file_name);
  }
}

void MainWindow::OpenImageCanvas(QString file_name)
{
  QImage img = QImage(file_name);

  if(img.isNull()){
    PopMessage("Fail");
    return;
  }
  CanvasWidgetContainer *canvas_widget_container = new CanvasWidgetContainer();
  canvas_widget_container->canvas_widget()->SetImage(img);
  ui->mdiArea->addSubWindow(canvas_widget_container);
  canvas_widget_container->setWindowTitle(file_name);
  canvas_widget_container->show();

}

void MainWindow::PopMessage(QString message)
{
  QMessageBox *msg = new QMessageBox(this);
  msg->setText(message);
  msg->exec();
  delete msg;
}
