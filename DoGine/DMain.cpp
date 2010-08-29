#include "DMain.h"
#include "DTimer.h"


DMain::DMain(int w,int h,int d, string cap) {
    screen.width = w;
    screen.height = h;
    screen.depth = d;
    should_quit = false;
    camera.rotation.x = 0;
    camera.rotation.y = 0;
    camera.rotation.z = 0;
    caption = cap;
}

DMain::~DMain() {
}

void DMain::quit(){
    should_quit = true;
}

void DMain::text(string s){
    cout << s << endl;
}

bool DMain::init_sdl_opengl() {
    //init sdl
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_SetVideoMode(screen.width,screen.height,screen.depth,SDL_OPENGL|SDL_RESIZABLE);
    SDL_WM_SetCaption(caption.c_str(), NULL);

    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );
    //init gl
    glClearColor(0,0,0,0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glEnable(GL_TEXTURE_2D);
    return 0;
}

bool DMain::exec() {
    init_sdl_opengl();
    resize();
    //DTimer t;
    init();
    while (!should_quit) {
        events();
        paint();
        /*
        if ( t.get_ticks() < 1000 / t.get_fps() ) {
            SDL_Delay( ( 1000 / t.get_fps() ) - t.get_ticks() );
        }*/
    }
    SDL_Quit();
    return 0;
}

void DMain::resize() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //int side=min(screen.width,screen.height);
    //glViewport((side-screen.width)/-2,(side-screen.height)/-2,side,side);
    glViewport(0,0,screen.width, screen.height);
    adjust_frustum();
    adjust_camera();
    glMatrixMode(GL_TEXTURE);
    adjust_texture();
    glMatrixMode(GL_MODELVIEW);

}

void DMain::paint() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    adjust_camera();
    handle();
    SDL_GL_SwapBuffers();
}

void DMain::adjust_texture(){
    glRotatef(180.0f,0.0f,0.0f,1.0f);
    glScalef(-1.0f,1.0f,1.0f);
}

void DMain::adjust_frustum(){
    glOrtho( 0, screen.width, 0, screen.height, -5000, 5000 ); //projeção ortogonal
    //glFrustum (-320,320, -240,240, 500,6000); //projeção c/ perspectiva
    //glTranslated(0,0,-3000);
}

void DMain::adjust_camera(){
    glTranslated(screen.width/2,screen.height/2,0);
    glRotated(camera.rotation.x, 1.0, 0.0, 0.0);
    glRotated(camera.rotation.y, 0.0, 1.0, 0.0);
    glRotated(camera.rotation.z, 0.0, 0.0, 1.0);
    glTranslated(-screen.width/2,-screen.height/2,0);
    glTranslated(camera.position.x, camera.position.y, camera.position.z);
}

void DMain::events() {
    //limpar teclas cujo estado foi modificado no loop anterior
    list<int>::iterator it;
    for (it=modkeyb.begin();it!=modkeyb.end();it++) {
        key[(*it)].reset();
    }
    modkeyb.clear();
    //resetar estado do mouse
    mouse.reset();
    //agora detecta possiveis teclas
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            should_quit = true;
            break;
        case SDL_MOUSEMOTION:
            mouse.speed.x = event.button.x-mouse.position.x;
            mouse.speed.y = event.button.y-mouse.position.y;

            mouse.position.x = event.motion.x;
            mouse.position.y = event.motion.y;
            break;
        case SDL_MOUSEBUTTONDOWN:
            if (event.button.button==SDL_BUTTON_LEFT) {
                mouse.left.isDown=true;
                mouse.left.hit=true;
            }
            if (event.button.button==SDL_BUTTON_RIGHT) {
                mouse.right.isDown=true;
                mouse.right.hit=true;
            }
            if (event.button.button==SDL_BUTTON_MIDDLE) {
                mouse.middle.isDown=true;
                mouse.middle.hit=true;
            }
            break;
        case SDL_MOUSEBUTTONUP:
            if (event.button.button==SDL_BUTTON_LEFT) {
                mouse.left.isDown=false;
                mouse.left.release=true;
            }
            if (event.button.button==SDL_BUTTON_RIGHT) {
                mouse.right.isDown=false;
                mouse.right.release=true;
            }
            if (event.button.button==SDL_BUTTON_MIDDLE) {
                mouse.middle.isDown=false;
                mouse.middle.release=true;
            }
            break;
        case SDL_KEYDOWN:
            key[event.key.keysym.sym].hit=true;
            key[event.key.keysym.sym].isDown=true;
            modkeyb.push_back(event.key.keysym.sym);
            break;
        case SDL_KEYUP:
            key[event.key.keysym.sym].release=true;
            key[event.key.keysym.sym].isDown=false;
            modkeyb.push_back(event.key.keysym.sym);
            break;
        default:
            break;
        }
    }
}

