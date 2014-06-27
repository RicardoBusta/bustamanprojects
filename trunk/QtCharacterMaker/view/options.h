#ifndef OPTIONS_H
#define OPTIONS_H

#include <QObject>
#include <QSize>
#include <QRect>

#define myOptions (Actions::instance())

enum EDIT_MODE{EDIT_MODE_IMAGE,EDIT_MODE_GRID,EDIT_MODE_VOXEL};

class Options : public QObject
{
  Q_OBJECT
public:
  static Options *instance();

  QSize cursor_size_;
  QRect selection_;
  EDIT_MODE current_edit_mode_;

private:
  explicit Options(QObject *parent = 0);
signals:

public slots:

};

#endif // OPTIONS_H
