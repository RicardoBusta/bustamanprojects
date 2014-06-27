#ifndef SETCURSORSIZEDIALOG_H
#define SETCURSORSIZEDIALOG_H

#include <QDialog>

namespace Ui {
  class SetCursorSizeDialog;
}

class SetCursorSizeDialog : public QDialog
{
  Q_OBJECT

public:
  explicit SetCursorSizeDialog(QWidget *parent = 0);
  ~SetCursorSizeDialog();

private:
  Ui::SetCursorSizeDialog *ui;

private slots:
  void SetOptions();
  void ValidateCursorSize(QString text);
};

#endif // SETCURSORSIZEDIALOG_H
