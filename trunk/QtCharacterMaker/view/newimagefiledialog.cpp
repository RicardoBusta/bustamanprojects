#include "newimagefiledialog.h"
#include "ui_newimagefiledialog.h"

#include "translations/tokens.h"

NewImageFileDialog::NewImageFileDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::NewImageFileDialog)
{
  ui->setupUi(this);

  setWindowTitle(kTranslationNewImageFileTitle);
}

NewImageFileDialog::~NewImageFileDialog()
{
  delete ui;
}
