#ifndef I_CANVAS_H
#define I_CANVAS_H

#include <QWidget>

namespace Ui {
class I_Canvas;
}

class I_Canvas : public QWidget
{
    Q_OBJECT
    
public:
    explicit I_Canvas(QWidget *parent = 0);
    ~I_Canvas();
    
private:
    Ui::I_Canvas *ui;
};

#endif // I_CANVAS_H
