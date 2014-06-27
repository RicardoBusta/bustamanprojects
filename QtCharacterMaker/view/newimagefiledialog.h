#ifndef NEWIMAGEFILEDIALOG_H
#define NEWIMAGEFILEDIALOG_H

#include <QDialog>

namespace Ui {
class NewImageFileDialog;
}

class NewImageFileDialog : public QDialog
{
  Q_OBJECT

public:
  explicit NewImageFileDialog(QWidget *parent = 0);
  ~NewImageFileDialog();

private:
  Ui::NewImageFileDialog *ui;
};

#endif // NEWIMAGEFILEDIALOG_H
