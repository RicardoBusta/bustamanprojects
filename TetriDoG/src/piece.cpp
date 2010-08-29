#include "piece.h"
#include "tetris.h"

piece::piece(tetris *parent) {
    t = parent;
    x=0;
    y=0;
    for (int i=0;i<4;i++) {
        for (int j=0;j<4;j++) {
            m[i][j]=0;
        }
    }
    c[0] = 1;
    c[1] = 1;
    c[2] = 1;
}

piece::~piece() {
}

bool piece::collide_boundary() {
    for (int i=0;i<4;i++) {
        for (int j=0;j<4;j++) {
            if (m[i][j]==1) {
                if (x+j<=0 or x+j>FIELDC or y+i<=0)
                    return true;
            }
        }
    }
    return false;
}

bool piece::collide_pieces() {
    for (int i=0;i<4;i++) {
        for (int j=0;j<4;j++) {
            if (x+j>0 and x+j<=FIELDC and y+i>0 and y+i<=FIELDL) {
                if (t->field.m[y+i-1][x+j-1] and m[i][j]) {
                    return true;
                }
            }
        }
    }
    return false;
}

void piece::rotate(int times) {
    int temp;
    for (int r=0;r<times%4;r++) {
        //rotate outer matrix
        for (int i=0;i<3;i++) {
            temp = m[0][0+i];
            m[0][0+i] = m[3-i][0];
            m[3-i][0] = m[3][3-i];
            m[3][3-i] = m[0+i][3];
            m[0+i][3] = temp;
        }
        //rotate inner matrix
        temp = m[1][1];
        m[1][1] = m[2][1];
        m[2][1] = m[2][2];
        m[2][2] = m[1][2];
        m[1][2] = temp;
    }
}

void piece::setShape(int shape) {
    switch (shape) {
    case SHAPE_SQUARE:
        c[0] = 1;
        c[1] = 1;
        c[2] = 0;
        m[1][1] = 1;
        m[1][2] = 1;
        m[2][1] = 1;
        m[2][2] = 1;
        break;
    case SHAPE_BAR:
        c[0] = 0;
        c[1] = 1;
        c[2] = 1;
        m[0][1] = 1;
        m[1][1] = 1;
        m[2][1] = 1;
        m[3][1] = 1;
        break;
    case SHAPE_T:
        c[0] = 1;
        c[1] = 0;
        c[2] = 1;
        m[2][0] = 1;
        m[2][1] = 1;
        m[2][2] = 1;
        m[1][1] = 1;
        break;
    case SHAPE_L:
        c[0] = 0;
        c[1] = 0;
        c[2] = 1;
        m[0][1] = 1;
        m[1][1] = 1;
        m[2][1] = 1;
        m[2][2] = 1;
        break;
    case SHAPE_IL:
        c[0] = 1;
        c[1] = 0.5;
        c[2] = 0;
        m[0][2] = 1;
        m[1][2] = 1;
        m[2][2] = 1;
        m[2][1] = 1;
        break;
    case SHAPE_N:
        c[0] = 1;
        c[1] = 0;
        c[2] = 0;
        m[0][1] = 1;
        m[1][1] = 1;
        m[1][2] = 1;
        m[2][2] = 1;
        break;
    case SHAPE_IN:
        c[0] = 0;
        c[1] = 1;
        c[2] = 0;
        m[0][2] = 1;
        m[1][2] = 1;
        m[1][1] = 1;
        m[2][1] = 1;
        break;
	/*
    case SHAPE_TEST:
        c[0] = 0;
        c[1] = 0;
        c[2] = 0;
        for (int i=0;i<4;i++) {
            for (int j=0;j<4;j++) {
                m[i][j]=1;
            }
        }
        break;
	//*/
    }

}
