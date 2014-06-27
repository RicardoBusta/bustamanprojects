#ifndef OPTIONS_H
#define OPTIONS_H

#include <QObject>
#include <QSize>
#include <QRect>

#define myOptions (Actions::instance())

enum EDIT_MODE_ENUM{
  EDIT_MODE_IMAGE,
  EDIT_MODE_GRID,
  EDIT_MODE_VOXEL
};
enum TOOL_ENUM{
  TOOL_SELECTION,
  TOOL_ZOOM,
  TOOL_FILL,
  TOOL_PENCIL,
  TOOL_LINE,
  TOOL_RECTANGLE,
  TOOL_ELIPSE
};

class Options : public QObject
{
  Q_OBJECT
public:
  static Options *instance();

  QSize cursor_size_;
  QRect selection_;
  EDIT_MODE_ENUM current_edit_mode_;
  TOOL_ENUM current_tool_;

private:
  explicit Options(QObject *parent = 0);
signals:

public slots:

};

#endif // OPTIONS_H
