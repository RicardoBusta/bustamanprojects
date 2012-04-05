#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "glwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;

    GLWidget *glwidget;

    void resizeEvent(QResizeEvent *);

private slots:
    void timedUpdate();
    void updateSlide();

    void addIOD();
    void removeIOD();
};

#endif // MAINWINDOW_H
