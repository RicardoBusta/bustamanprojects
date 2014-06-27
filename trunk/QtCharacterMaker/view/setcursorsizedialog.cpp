#include "setcursorsizedialog.h"
#include "ui_setcursorsizedialog.h"

#include "view/options.h"

SetCursorSizeDialog::SetCursorSizeDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::SetCursorSizeDialog)
{
  ui->setupUi(this);

  ui->width_comboBox->setCurrentText(QString::number(Options::instance()->cursor_size_.width()));
  ui->width_comboBox_2->setCurrentText(QString::number(Options::instance()->cursor_size_.height()));

  connect(this,SIGNAL(accepted()),this,SLOT(SetOptions()));
  connect(ui->width_comboBox,SIGNAL(editTextChanged(QString)),this,SLOT(ValidateCursorSize(QString)));
}

SetCursorSizeDialog::~SetCursorSizeDialog()
{
  delete ui;
}

void SetCursorSizeDialog::SetOptions()
{
  Options::instance()->cursor_size_ = QSize(ui->width_comboBox->currentText().toInt(),ui->width_comboBox_2->currentText().toInt());
  Options::instance()->selection_.setSize( Options::instance()->cursor_size_ );
}

void SetCursorSizeDialog::ValidateCursorSize(QString text)
{
  ui->width_comboBox->setCurrentText(QString::number(text.toInt()));
}
