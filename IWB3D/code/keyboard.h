#ifndef KEYBOARD_H
#define KEYBOARD_H

class keyboard{
public:
///Construtores///
    keyboard();
    ~keyboard();
///Atributos///
//Estados
    bool hit;
    bool release;
    bool isDown;
};

#endif //KEYBOARD_H
