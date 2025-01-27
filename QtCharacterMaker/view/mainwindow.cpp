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
#include <QSettings>

const QString kSettingsFileName = "settings.ini";

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow),
  last_canvas_selected_(NULL)
{
  ui->setupUi(this);

  LoadSettings();

  edit_mode_buttons_[EDIT_MODE_IMAGE] = ui->actionEditModeImage;
  edit_mode_buttons_[EDIT_MODE_GRID] = ui->actionEditModeGrid;
  edit_mode_buttons_[EDIT_MODE_VOXEL] = ui->actionEditModeVoxel;

  if(edit_mode_buttons_.contains(Options::instance()->current_edit_mode_)){
    current_edit_mode_button_ = edit_mode_buttons_[Options::instance()->current_edit_mode_];
    current_edit_mode_button_->setChecked(true);
  }

  tool_buttons_[TOOL_SELECTION] = ui->actionSelection_Tool;
  tool_buttons_[TOOL_ZOOM] = ui->actionZoom_Tool;
  tool_buttons_[TOOL_PENCIL] = ui->actionPencil_Tool;
  tool_buttons_[TOOL_FILL] = ui->actionFill_Tool;
  tool_buttons_[TOOL_LINE] = ui->actionLine_Tool;
  tool_buttons_[TOOL_RECTANGLE] = ui->actionRectangle_Tool;
  tool_buttons_[TOOL_ELIPSE] = ui->actionElipse_Tool;

  if(tool_buttons_.contains(Options::instance()->current_tool_)){
    current_tool_button_ = tool_buttons_[Options::instance()->current_tool_];
    current_tool_button_->setChecked(true);
  }

  // Menu Actions
  connect(ui->actionOpen,SIGNAL(triggered()),this,SLOT(OpenImage()));
  connect(ui->actionSave,SIGNAL(triggered()),this,SLOT(SaveImage()));
  connect(ui->actionTile_Size,SIGNAL(triggered()),this,SLOT(SetCursorSize()));
  connect(ui->actionNew,SIGNAL(triggered()),this,SLOT(NewImage()));

  // Tool Actions
  connect(ui->actionSelection_Tool,SIGNAL(triggered()),this,SLOT(SelectSelectionTool()));
  connect(ui->actionFill_Tool,SIGNAL(triggered()),this,SLOT(SelectFillTool()));
  connect(ui->actionPencil_Tool,SIGNAL(triggered()),this,SLOT(SelectSelectionTool()));

  connect(ui->mdiArea,SIGNAL(subWindowActivated(QMdiSubWindow*)),this,SLOT(CurrentWindowChanged(QMdiSubWindow*)));
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::closeEvent(QCloseEvent *)
{
  SaveSettings();
}

void MainWindow::LoadSettings()
{
  QSettings settings(kSettingsFileName,QSettings::IniFormat);

  settings.beginReadArray("window");
  setGeometry( (settings.value("geometry").toRect()) );
  settings.beginReadArray("options");
  Options::instance()->cursor_size_ = settings.value("cursor_size").toSize();
}

void MainWindow::SaveSettings()
{
  QSettings settings(kSettingsFileName,QSettings::IniFormat);

  settings.beginWriteArray("window");
  settings.setValue("geometry",geometry());

  settings.beginWriteArray("options");
  settings.setValue("cursor_size",Options::instance()->cursor_size_);
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
  CanvasWidgetContainer *canvas_widget_container = new CanvasWidgetContainer(file_name,img);
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

void MainWindow::SelectSelectionTool()
{
  ClearToolSelection();
  Options::instance()->current_tool_ = TOOL_SELECTION;
  tool_buttons_[TOOL_SELECTION]->setChecked(true);
}

void MainWindow::SelectFillTool()
{
  ClearToolSelection();
  Options::instance()->current_tool_ = TOOL_FILL;
  tool_buttons_[TOOL_FILL]->setChecked(true);
}

void MainWindow::SelectPencilTool()
{
  ClearToolSelection();
  Options::instance()->current_tool_ = TOOL_PENCIL;
  tool_buttons_[TOOL_PENCIL]->setChecked(true);
}

void MainWindow::ClearToolSelection()
{
  QMap<int,QAction*>::iterator it = tool_buttons_.begin();
  for(;it!=tool_buttons_.end();it++){
    (*it)->setChecked(false);
  }
}

void MainWindow::PopMessage(QString message)
{
  QMessageBox *msg = new QMessageBox(this);
  msg->setText(message);
  msg->exec();
  delete msg;
}

void MainWindow::CurrentWindowChanged(QMdiSubWindow *w)
{
  if(last_canvas_selected_ != NULL){
    last_canvas_selected_->RemoveAsActiveWidget(ui->edit_image_widget);
  }

  last_canvas_selected_ = NULL;
  if( w != NULL ){
    CanvasWidgetContainer *canvas = dynamic_cast<CanvasWidgetContainer*>(w->widget());
    if( canvas != NULL ){
      //      qDebug() << canvas->file_name();
      canvas->SetAsActiveWidget(ui->edit_image_widget);
      ui->color_palette_widget->SetImagePalette(canvas->GetImagePalette());
      ui->edit_image_widget->SetImagePalette(canvas->GetImagePalette());
      ui->color_palette_widget->update();

      last_canvas_selected_ = canvas;
    }
  }


}
