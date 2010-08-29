#include "tetris.h"
#include "game.h"
#include "piece.h"

#include <stdlib.h>

tetris::tetris(game* parent) {
    g = parent;
    p = new piece(this);
    hold = NULL;
    fixcount = 0;
    gameover = false;
    srand(time(0));
    p->setShape(rand()%SHAPE_LAST);
    p->x = SPAWNX;
    p->y = SPAWNY;
    for (int i=0;i<6;i++) {
        next[i] = new piece(this);
        next[i]->setShape(rand()%SHAPE_LAST);
        next[i]->rotate(rand()%4);
        next[i]->x = SPAWNX;
        next[i]->y = SPAWNY;
    }
    wait=0;
    //reset field
    for (int i=0;i<FIELDL;i++) {
        for (int j=0;j<FIELDC;j++) {
            field.m[i][j] = 0;
        }
        field.clearl[i]=false;
    }
}

tetris::~tetris() {
}

keyboard tetris::key(int k) {
    return g->key[k];
}

void tetris::drawTile(int x, int y, float *c) {
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3i( ( x )*TSIZE , ( y )*TSIZE ,5);
    glVertex3i( (x+1)*TSIZE , ( y )*TSIZE ,5);
    glVertex3i( (x+1)*TSIZE , (y+1)*TSIZE ,5);
    glVertex3i( ( x )*TSIZE , (y+1)*TSIZE ,5);

    glColor3fv(c);
    glVertex3i( ( x )*TSIZE+BSIZE , ( y )*TSIZE+BSIZE ,10);
    glVertex3i( (x+1)*TSIZE-BSIZE , ( y )*TSIZE+BSIZE ,10);
    glVertex3i( (x+1)*TSIZE-BSIZE , (y+1)*TSIZE-BSIZE ,10);
    glVertex3i( ( x )*TSIZE+BSIZE , (y+1)*TSIZE-BSIZE ,10);
    glEnd();
}

void tetris::draw() {
    glPushMatrix();
    //background
    glTranslated(20,20,0);
    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex3i(0,0,-1);
    glVertex3i(TSIZE*FIELDC,0,-1);
    glVertex3i(TSIZE*FIELDC,TSIZE*FIELDL,-1);
    glVertex3i(0,TSIZE*FIELDL,-1);
    glEnd();
    //end background

    //gameover screen
    if (gameover) {
        glBegin(GL_QUADS);
        glColor3f(0.5,0,0);
        glVertex3i(0,0,20);
        glVertex3i(TSIZE*FIELDC,0,20);
        glVertex3i(TSIZE*FIELDC,TSIZE*FIELDL,20);
        glVertex3i(0,TSIZE*FIELDL,20);
        glEnd();
    }
    //gameover screen

    //field
    for (int i=0;i<FIELDL;i++) {
        for (int j=0;j<FIELDC;j++) {
            if (field.m[i][j]==1) {
                drawTile(j,i,field.c[i][j]);
            }
        }
    }
    //end field
    glPopMatrix();

    //piece
    glPushMatrix();
    glTranslated(TSIZE*p->x,TSIZE*p->y,0);
    for (int i=0;i<4;i++) {
        for (int j=0;j<4;j++) {
            if (p->m[i][j]==1) {
                if (p->x+j>0 and p->x+j<=FIELDC and p->y+i>0 and p->y+i<=FIELDL)
                    drawTile(j,i,p->c);
            }
        }
    }
    glPopMatrix();
    //end piece

    //hold piece
    if (hold!=NULL) {
        glPushMatrix();
        glTranslated(120+TSIZE*FIELDC,300,0);
        for (int i=0;i<4;i++) {
            for (int j=0;j<4;j++) {
                if (hold->m[i][j]==1) {
                    drawTile(j,i,hold->c);
                }
            }
        }
        glPopMatrix();
    }
    //hold piece

    //next pieces
    for (int k=0;k<6;k++) {
        glPushMatrix();
        glTranslated(40+TSIZE*FIELDC,(5-k)*4*TSIZE,0);
        for (int i=0;i<4;i++) {
            for (int j=0;j<4;j++) {
                if (next[k]->m[i][j]==1) {
                    drawTile(j,i,next[k]->c);
                }
            }
        }
        glPopMatrix();
    }
    //end next

}

void tetris::fixPiece() {
    if (p->y+4 > FIELDL) {
        gameover = true;
    }
    for (int i=0;i<4;i++) {
        for (int j=0;j<4;j++) {
            if (p->x+j>0 and p->x+j<=FIELDC and p->y+i>0 and p->y+i<=FIELDL) {
                if (p->m[i][j]) {
                    field.m[p->y+i-1][p->x+j-1]=1;
                    for (int k=0;k<3;k++) {
                        field.c[p->y+i-1][p->x+j-1][k] = p->c[k];
                    }
                }
            }
        }
        checkLineComplete(p->y+i-1);
    }
    delete p;
}

void tetris::callNextPiece() {
    p = next[0];
    for (int i=0;i<5;i++) {
        next[i]=next[i+1];
    }
    next[5]= new piece(this);
    next[5]->setShape(rand()%SHAPE_LAST);
    next[5]->rotate(rand()%4);
    next[5]->x = SPAWNX;
    next[5]->y = SPAWNY;
}

void tetris::holdPiece() {
    if (hold == NULL) {
        hold = p;
        callNextPiece();
    } else {
        piece *temp = p;
        p = hold;
        hold = temp;
        p->x = SPAWNX;
        p->y = SPAWNY;
    }
}

void tetris::checkLineComplete(int l) {
    bool complete = true;
    for (int j=0;j<FIELDC;j++) {
        complete = complete and field.m[l][j];
    }
    if (complete) {
        field.clearl[l] = true;
    }
}

void tetris::clearLine() {
    for (int l=0;l<FIELDL;l++) {
        if (field.clearl[l] == true) {
            for (int j=0;j<FIELDC;j++) {
                for (int i=l;i<FIELDL-1;i++) {
                    field.m[i][j] = field.m[i+1][j];
                    for (int k=0;k<3;k++) {
                        field.c[i][j][k] = field.c[i+1][j][k];
                    }
                }
                field.m[FIELDL-1][j] = 0;
            }
            for (int i=l;i<FIELDL-1;i++) {
            	field.clearl[i] = field.clearl[i+1];
            }
			field.clearl[FIELDL-1] = false;
			l--;
        }
    }
}

void tetris::handle() {
	//ROTATE PIECE
    if (key(SDLK_SPACE).hit) {
        p->rotate(1);
        if (p->collide_boundary() || p->collide_pieces()) {
            p->x++;
            if (p->collide_boundary() || p->collide_pieces()) {
                p->x-=2;
                if (p->collide_boundary() || p->collide_pieces()) {
                    p->x++;
                    p->rotate(3);
                }
            }
        }
    }
    //MOVE PIECE
    if (key(SDLK_LEFT).hit) {
        p->x--;
        if (p->collide_boundary() || p->collide_pieces()) {
            p->x++;
        }else{
        	fixcount = 0;
        }
    }
    if (key(SDLK_RIGHT).hit) {
        p->x++;
        if (p->collide_boundary() || p->collide_pieces()) {
            p->x--;
        }else{
        	fixcount = 0;
        }
    }
    //DOWN FASTER BUTTON
    if (key(SDLK_DOWN).hit) {
        p->y--;
        if (p->collide_boundary() || p->collide_pieces()) {
            p->y++;
        }
    }
    //DROP PIECE BUTTON
    if (key(SDLK_UP).hit) {
        while (!(p->collide_boundary() || p->collide_pieces())) {
            p->y--;
        }
		fixcount=4;
        p->y++;
    }
    //HOLD BUTTON
    if (key(SDLK_LCTRL).hit) {
        holdPiece();
    }
    wait++;
    if (wait>WAITTIME && !gameover) {
        wait=0;
        p->y--;
        if (p->collide_boundary() || p->collide_pieces()) {
            p->y++;
            fixcount++;
        }
        if (fixcount>3) {
        	fixcount=0;
            fixPiece();
            clearLine();
            callNextPiece();
        }
    }
    draw();
}
