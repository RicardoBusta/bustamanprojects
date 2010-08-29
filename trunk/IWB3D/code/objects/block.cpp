#include "block.h"
#include "player.h"
#include "common.h"

block::block(scenario *parent):object(parent){
    w = 16;
    h = 16;
    d = 16;
}

block::~block(){
}

void block::drawLeft(){
    glBegin(GL_QUADS);
    float drawx=x-w, drawy=y-h, drawz=z-d;
    glTexCoord2f( 0 , tex1y );
    glVertex3f(drawx,drawy,drawz);
    drawz+=2*d;
    glTexCoord2f( tex1x , tex1y );
    glVertex3f(drawx,drawy,drawz);
    drawy+=2*h;
    glTexCoord2f( tex1x , tex2y );
    glVertex3f(drawx,drawy,drawz);
    drawz-=2*d;
    glTexCoord2f( 0 , tex2y );
    glVertex3f(drawx,drawy,drawz);
    glEnd();
}

void block::drawRight(){
    glBegin(GL_QUADS);
    float drawx=x+w, drawy=y-h, drawz=z+d;
    glTexCoord2f( tex2x , tex1y );
    glVertex3f(drawx,drawy,drawz);
    drawz-=2*d;
    glTexCoord2f( 1 , tex1y );
    glVertex3f(drawx,drawy,drawz);
    drawy+=2*h;
    glTexCoord2f( 1 , tex2y );
    glVertex3f(drawx,drawy,drawz);
    drawz+=2*d;
    glTexCoord2f( tex2x , tex2y );
    glVertex3f(drawx,drawy,drawz);
    glEnd();
}

void block::drawTop(){
    glBegin(GL_QUADS);
    float drawx=x-w, drawy=y+h, drawz=z+d;
    glTexCoord2f( tex1x , tex2y );
    glVertex3f(drawx,drawy,drawz);
    drawx+=2*w;
    glTexCoord2f( tex2x , tex2y );
    glVertex3f(drawx,drawy,drawz);
    drawz-=2*d;
    glTexCoord2f( tex2x , 1 );
    glVertex3f(drawx,drawy,drawz);
    drawx-=2*w;
    glTexCoord2f( tex1x , 1 );
    glVertex3f(drawx,drawy,drawz);
    glEnd();
}

void block::drawBottom(){
    glBegin(GL_QUADS);
    float drawx=x-w, drawy=y-h, drawz=z-d;
    glTexCoord2f( tex1x , 0 );
    glVertex3f(drawx,drawy,drawz);
    drawx+=2*w;
    glTexCoord2f( tex2x , 0 );
    glVertex3f(drawx,drawy,drawz);
    drawz+=2*d;
    glTexCoord2f( tex2x , tex1y );
    glVertex3f(drawx,drawy,drawz);
    drawx-=2*w;
    glTexCoord2f( tex1x , tex1y );
    glVertex3f(drawx,drawy,drawz);
    glEnd();

}

void block::drawNear(){
    glBegin(GL_QUADS);
    float drawx=x-w, drawy=y-h, drawz=z+d;
    glTexCoord2f( tex1x , tex1y );
    glVertex3f(drawx,drawy,drawz);
    drawx+=2*w;
    glTexCoord2f( tex2x , tex1y );
    glVertex3f(drawx,drawy,drawz);
    drawy+=2*h;
    glTexCoord2f( tex2x , tex2y );
    glVertex3f(drawx,drawy,drawz);
    drawx-=2*w;
    glTexCoord2f( tex1x , tex2y );
    glVertex3f(drawx,drawy,drawz);
    glEnd();
}

void block::drawFar(){
    glBegin(GL_QUADS);
    float drawx=x+w, drawy=y-h, drawz=z-d;
    glTexCoord2f( tex1x , tex1y );
    glVertex3f(drawx,drawy,drawz);
    drawx-=2*w;
    glTexCoord2f( tex2x , tex1y );
    glVertex3f(drawx,drawy,drawz);
    drawy+=2*h;
    glTexCoord2f( tex2x , tex2y );
    glVertex3f(drawx,drawy,drawz);
    drawx+=2*w;
    glTexCoord2f( tex1x , tex2y );
    glVertex3f(drawx,drawy,drawz);
    glEnd();
}

void block::drawThis(){
    //texture sprite;
    //sprite.loadTexture("texture\\bloco.bmp");
    glColor3f(1-w/100,1-d/100,1-h/100);
    drawLeft();
    drawRight();
    drawTop();
    drawBottom();
    drawNear();
    drawFar();
    //delete &sprite;
}

void block::handle(){
    draw();
}

void block::heroi_colide(){
    if ( (modulo(heroi->x+heroi->hspeed-x) < heroi->w+w) and (modulo(heroi->y+heroi->vspeed-y) < heroi->h+h) ){
        float tgalfa=h/w, tgbeta=modulo((y-heroi->y)/(x-heroi->x));
        if (tgalfa<tgbeta){
            if (sinal(heroi->y-y)>0){
                heroi->jump=0;
                heroi->djump=0;
            }
            heroi->vspeed=0;
            heroi->y+=( sinal(heroi->y-y)*(heroi->h+h)-(heroi->y-y) );
        }else{
            heroi->hspeed=0;
            heroi->x+=( sinal(heroi->x-x)*(heroi->w+w)-(heroi->x-x) );
        }
    }
}
