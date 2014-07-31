#ifndef OPTIONS_H
#define OPTIONS_H

#include <QColor>

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
  bool show_normals() const;

  bool show_wireframe() const;
  bool shaders_off() const;
  bool animation() const;
  QColor clear_color() const;
private :
  Options();

  friend class MainWindow;

  static Options *instance_;

  bool options_changed_;

  // Scene Options
  const int initial_zoom_;
  const int initial_rot_x_;
  const int initial_rot_y_;
  const int initial_rot_z_;

  // Artifacts Options
  float normal_size_;
  bool show_normals_;

  // Render Options
  bool show_wireframe_;
  bool shaders_off_;
  bool animation_;
  QColor clear_color_;
};

#endif // OPTIONS_H
