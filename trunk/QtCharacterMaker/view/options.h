#ifndef OPTIONS_H
#define OPTIONS_H

#include <QObject>
#include <QSize>
#include <QRect>

#define myOptions (Actions::instance())

class Options : public QObject
{
  Q_OBJECT
public:
  static Options *instance();

  QSize selection_size_;
  QSize cursor_size_;
  QRect selection_;
private:
  explicit Options(QObject *parent = 0);
signals:

public slots:

};

#endif // OPTIONS_H
