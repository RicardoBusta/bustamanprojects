#ifndef DMouse_H
#define DMouse_H

class DMouse {
public:
//Construtor
    DMouse();
//Reset
	void reset();

//Estados
    struct LEFT_RIGHT_MIDDLE{
        bool hit;
        bool release;
        bool isDown;
    }left,right,middle;

    struct SPEED{
        int x;
        int y;
    }speed;

    struct POSITION{
        int x;
        int y;
    }position;
};

#endif //DMouse_H
