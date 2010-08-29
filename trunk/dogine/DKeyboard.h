#ifndef DKeyboard_H
#define DKeyboard_H

class DKeyboard {
public:
///Construtores///
    DKeyboard();
    ~DKeyboard();
///Atributos///
//Estados
    bool hit;
    bool release;
    bool isDown;
//Reseta
	void reset();
};

#endif //DKeyboard_H
