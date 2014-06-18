#ifndef ACTIONS_H
#define ACTIONS_H

#include <QObject>

#define myActions (Actions::instance())

class Actions : public QObject
{
  Q_OBJECT
public:
  static Actions *instance();
private:
  explicit Actions(QObject *parent = 0);

signals:
public slots:
};

#endif // ACTIONS_H
