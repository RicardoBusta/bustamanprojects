#ifndef PIECE_H
#define PIECE_H

enum {SHAPE_SQUARE, SHAPE_BAR, SHAPE_T, SHAPE_L, SHAPE_IL, SHAPE_N, SHAPE_IN, SHAPE_LAST};

class tetris;

class piece {
public:
    //data
    tetris* t;
    float c[3]; //color
    bool m[4][4]; //matrix
    int x,y;

    //methods
    void rotate(int times); //rotate the piece counter clockwise
    void setShape(int shape); //define the shape
    bool collide_boundary(); //collide with the field boundary
    bool collide_pieces(); //collide with fixed pieces

    //constructor
    piece(tetris* parent);
    ~piece();
};

#endif //PIECE_H
