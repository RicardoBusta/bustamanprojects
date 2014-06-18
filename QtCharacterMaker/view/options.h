#ifndef OPTIONS_H
#define OPTIONS_H

#include <QObject>

#define myOptions (Actions::instance())

class Options : public QObject
{
  Q_OBJECT
public:
  static Options *instance();

  int selection_height_;
  int selection_width_;
private:
  explicit Options(QObject *parent = 0);
signals:

public slots:

};

#endif // OPTIONS_H
