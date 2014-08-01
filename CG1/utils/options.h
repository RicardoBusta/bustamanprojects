#ifndef OPTIONS_H
#define OPTIONS_H

#include <QColor>
#include <QMap>
#include <QString>
class Options
{
public:
  static Options *instance();

  bool options_changed() const;
  void options_applied();

  int initial_zoom() const;
  int initial_rot_x() const;
  int initial_rot_y() const;
  int initial_rot_z() const;

  float normal_size() const;

  bool get_option(QString option);
  void set_option(QString option, bool v);

  QColor clear_color() const;
private :
  Options();

  static Options *instance_;

  bool options_changed_;

  // Scene Options
  const int initial_zoom_;
  const int initial_rot_x_;
  const int initial_rot_y_;
  const int initial_rot_z_;

  // Artifacts Options
  float normal_size_;

  QMap<QString,bool> check_options_;

  QColor clear_color_;
};

#endif // OPTIONS_H
