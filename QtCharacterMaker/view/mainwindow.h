#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QMap>

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

    QMap<int,QAction*> tool_buttons_;
    QMap<int,QAction*> edit_mode_buttons_;
private slots:
    void OpenImage();
    void OpenImageCanvas(QString file_name);

    void NewImage();
    void SaveImage();

    void SetCursorSize();

    void PopMessage(QString message);
};

#endif // MAINWINDOW_H
