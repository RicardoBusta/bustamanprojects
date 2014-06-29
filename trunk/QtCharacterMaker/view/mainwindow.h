#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QMap>

namespace Ui {
class MainWindow;
}

class QMdiSubWindow;
class CanvasWidgetContainer;

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

    CanvasWidgetContainer *last_canvas_selected_;
private slots:
    // Actions
    void OpenImage();
    void OpenImageCanvas(QString file_name);
    void NewImage();
    void SaveImage();
    void SetCursorSize();

    //Tools
    void SelectSelectionTool();
    void SelectPencilTool();

    void PopMessage(QString message);
    void CurrentWindowChanged(QMdiSubWindow *w);
};

#endif // MAINWINDOW_H
