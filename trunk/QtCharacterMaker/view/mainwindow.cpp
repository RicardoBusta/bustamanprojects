#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "qtcharactermaker.h"
#include "view/actions.h"
#include "view/canvaswidgetcontainer.h"
#include "translations/tokens.h"
#include "view/options.h"
#include "view/setcursorsizedialog.h"
#include "view/newimagefiledialog.h"

#include <QDebug>
#include <QLabel>
#include <QFileDialog>
#include <QMessageBox>
#include <QMdiSubWindow>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  edit_mode_buttons_[EDIT_MODE_IMAGE] = ui->actionEditModeImage;
  edit_mode_buttons_[EDIT_MODE_GRID] = ui->actionEditModeGrid;
  edit_mode_buttons_[EDIT_MODE_VOXEL] = ui->actionEditModeVoxel;

  if(edit_mode_buttons_.contains(Options::instance()->current_edit_mode_)){
    edit_mode_buttons_[Options::instance()->current_edit_mode_]->toggle();
  }

  tool_buttons_[TOOL_SELECTION] = ui->actionSelection_Tool;
  tool_buttons_[TOOL_ZOOM] = ui->actionZoom_Tool;
  tool_buttons_[TOOL_PENCIL] = ui->actionPencil_Tool;
  tool_buttons_[TOOL_FILL] = ui->actionFill_Tool;
  tool_buttons_[TOOL_LINE] = ui->actionLine_Tool;
  tool_buttons_[TOOL_RECTANGLE] = ui->actionRectangle_Tool;
  tool_buttons_[TOOL_ELIPSE] = ui->actionElipse_Tool;

  if(tool_buttons_.contains(Options::instance()->current_tool_)){
    tool_buttons_[Options::instance()->current_tool_]->toggle();
  }

  connect(ui->actionOpen,SIGNAL(triggered()),this,SLOT(OpenImage()));
  connect(ui->actionSave,SIGNAL(triggered()),this,SLOT(SaveImage()));
  connect(ui->actionTile_Size,SIGNAL(triggered()),this,SLOT(SetCursorSize()));
  connect(ui->actionNew,SIGNAL(triggered()),this,SLOT(NewImage()));
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::OpenImage()
{
  //  qDebug() << "Open Image" ;
  QStringList open_files = QFileDialog::getOpenFileNames(this,kTranslationOpenImageFileTitle);

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
  CanvasWidgetContainer *canvas_widget_container = new CanvasWidgetContainer(file_name,img,ui->edit_image_widget);
  ui->mdiArea->addSubWindow(canvas_widget_container);
  canvas_widget_container->show();
}

void MainWindow::NewImage()
{
  NewImageFileDialog image_dialog(this);
  image_dialog.exec();
}

void MainWindow::SaveImage()
{
  QMdiSubWindow *win = ui->mdiArea->currentSubWindow();
  if(win != NULL){
    CanvasWidgetContainer *wid = dynamic_cast<CanvasWidgetContainer*>(win->widget());
    if(wid != NULL){
      wid->SaveImage();
    }
  }
}

void MainWindow::SetCursorSize()
{
  SetCursorSizeDialog cursor_dialog(this);
  cursor_dialog.exec();
}

void MainWindow::PopMessage(QString message)
{
  QMessageBox *msg = new QMessageBox(this);
  msg->setText(message);
  msg->exec();
  delete msg;
}
