#include "player.h"
#include "block.h"

player::player(scenario *parent):object(parent){
    w = 16;
    h = 16;
    d = 0;
    jump = false;
    djump = false;
}

player::~player(){
}

void player::drawNear(){
    glBegin(GL_QUADS);
    float drawx=x-w,drawy=y-h,drawz=z;
    glTexCoord2f( 0 , 0 );
    glVertex3f(drawx,drawy,drawz);
	drawx+=2*w;
    glTexCoord2f( 1 , 0 );
	glVertex3f(drawx,drawy,drawz);
    drawy+=2*h;
    glTexCoord2f( 1 , 1 );
    glVertex3f(drawx,drawy,drawz);
    drawx-=2*w;
    glTexCoord2f( 0 , 1 );
    glVertex3f(drawx,drawy,drawz);
    glEnd();
}

void player::drawFar(){
    glBegin(GL_QUADS);
    float drawx=x+w,drawy=y-h,drawz=z;
    glTexCoord2f( 0 , 0 );
    glVertex3f(drawx,drawy,drawz);
	drawx-=2*w;
    glTexCoord2f( 1 , 0 );
	glVertex3f(drawx,drawy,drawz);
    drawy+=2*h;
    glTexCoord2f( 1 , 1 );
    glVertex3f(drawx,drawy,drawz);
    drawx+=2*w;
    glTexCoord2f( 0 , 1 );
    glVertex3f(drawx,drawy,drawz);
    glEnd();
}

void player::resetJump(){
    jump = false;
    djump = false;
}

void player::drawThis(){
    //texture sprite;
    //sprite.loadTexture("texture\\mega.png");
    glColor3f(0.0,0.5,0.0);
    drawNear();
    drawFar();
    //delete &sprite;
}

void player::handle_prev(){
	hspeed=4*((float)(key(SDLK_RIGHT).isDown or key(SDLK_d).isDown)-(float)(key(SDLK_LEFT).isDown or key(SDLK_a).isDown));
	vspeed+=s->gravity;
	if (key(SDLK_UP).hit or key(SDLK_w).hit){
        if (jump==false){
            vspeed = 10.0f;
            jump = true;
        }else if (djump==false){
            vspeed = 10.0f;
            djump = true;
        }
    }
	if (key(SDLK_RCTRL).hit){
        setPos32(1,13);
        vspeed=0;
        jump = false;
        djump = false;
    }
    if (key(SDLK_LSHIFT).hit){
    	object *spawn = new block(s);
		spawn->setSize(32,5,16);
		spawn->setPos(x,y,z);
    	s->obstacle.push_back(spawn);
    }
}

void player::handle(){
    move(hspeed,vspeed);
    draw();
}
