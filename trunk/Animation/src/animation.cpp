#include "animation.h"
#include "model.h"

animation::animation(int a, int b, int c, string d):DMain(a,b,c,d)
{
}

animation::~animation()
{
}

void animation::init()
{
    index = 0;
    wait=0;
    frames = 100;
    bone *b;
    m = new model*[frames];

    model *mod1 , *mod2, *mod3;
    mod1 = new model();
    //Stickman
    mod1->add_bone("center");

    //Corpo
    mod1->add_bone("lower_body","center");
    mod1->add_bone("upper_body","center");

    //Braço Esquerdo
    mod1->add_bone("l_up_arm", "upper_body");
    mod1->add_bone("l_low_arm" , "l_up_arm");
    mod1->add_bone("l_hand", "l_low_arm");

    //Braço Direito
    mod1->add_bone("r_up_arm", "upper_body");
    mod1->add_bone("r_low_arm" , "r_up_arm");
    mod1->add_bone("r_hand", "r_low_arm");

    //Cabeça
    mod1->add_bone("head", "upper_body");

    //Perna Esquerda
    mod1->add_bone("l_up_leg","lower_body");
    mod1->add_bone("l_low_leg","l_up_leg");
    mod1->add_bone("l_foot", "l_low_leg");

    //Perna Direita
    mod1->add_bone("r_up_leg","lower_body");
    mod1->add_bone("r_low_leg","r_up_leg");
    mod1->add_bone("r_foot", "r_low_leg");


//definindo propriedadesdomodelo


    b = mod1->get_bone("center");
    b->set_position(320,240,-100);
    b->set_length(0);
    b->set_shape(1);

    b = mod1->get_bone("lower_body");
    b->set_length(20);
    b->set_color(0,0.5,0);

    b = mod1->get_bone("upper_body");
    b->set_length(100);
    b->set_color(0,1,0);
    b->set_rotation(0,0,180);

    b = mod1->get_bone("l_up_leg");
    b->set_length(70);
    b->set_color(0,0,1);
    b->set_rotation(0,0,0);
    b->set_position(20,0,0);

    b = mod1->get_bone("l_low_leg");
    b->set_length(50);
    b->set_color(0,0,0.7);
    b->set_rotation(0,0,0);

    b = mod1->get_bone("l_foot");
    b->set_length(40);
    b->set_color(0,0,0.3);
    b->set_rotation(-90,0,0);

    b = mod1->get_bone("r_up_leg");
    b->set_length(70);
    b->set_color(0,1,1);
    b->set_rotation(0,0,0);
    b->set_position(-20,0,0);

    b = mod1->get_bone("r_low_leg");
    b->set_length(50);
    b->set_color(0,0.7,0.7);
    b->set_rotation(0,0,0);

    b = mod1->get_bone("r_foot");
    b->set_length(40);
    b->set_color(0,0.3,0.3);
    b->set_rotation(-90,0,0);

    b = mod1->get_bone("l_up_arm");
    b->set_length(50);
    b->set_color(1,0,1);
    b->set_rotation(0,0,-120);
    b->set_position(-20,0,0);

    b = mod1->get_bone("l_low_arm");
    b->set_length(50);
    b->set_color(0.7,0,0.7);
    b->set_rotation(0,0,0);

    b = mod1->get_bone("l_hand");
    b->set_length(10);
    b->set_color(0.3,0,0.3);
    b->set_rotation(0,0,0);

    b = mod1->get_bone("r_up_arm");
    b->set_length(50);
    b->set_color(1,1,0);
    b->set_rotation(0,0,120);
    b->set_position(20,0,0);

    b = mod1->get_bone("r_low_arm");
    b->set_length(50);
    b->set_color(0.7,0.7,0);
    b->set_rotation(0,0,0);

    b = mod1->get_bone("r_hand");
    b->set_length(10);
    b->set_color(0.3,0.3,0);
    b->set_rotation(0,0,0);

    b = mod1->get_bone("head");
    b->set_length(40);
    b->set_color(1,1,1);


//clonando modelo 1 no modelo 2.
    mod2 = mod1->clone_model();

//alterando modelo 2 para ficar diferente do 1.
    b = mod2->get_bone("center");
    b->set_shape(1);
    b->set_position(320,240,0);

    b = mod2->get_bone("upper_body");
    b->set_rotation(30,0,180);

    b = mod2->get_bone("head");
    b->set_rotation(-30,0,0);

    b = mod2->get_bone("l_low_leg");
    b->set_rotation(90,0,0);
    b = mod2->get_bone("r_low_leg");
    b->set_rotation(90,0,0);

    b = mod2->get_bone("l_up_leg");
    b->set_rotation(90,0,0);
    b = mod2->get_bone("r_up_leg");
    b->set_rotation(-90,0,0);

    b = mod2->get_bone("l_up_arm");
    b->set_rotation(0,0,-90);
    b = mod2->get_bone("r_up_arm");
    b->set_rotation(0,0,90);

    b = mod2->get_bone("l_low_arm");
    b->set_rotation(-90,0,0);
    b = mod2->get_bone("r_low_arm");
    b->set_rotation(-90,0,0);


    //3rd model
    mod3 = mod1->clone_model();
    b = mod3->get_bone("center");
    b->set_shape(1);
    b->set_position(320,240,100);

    int min,max,size;
    min = 0;
    max = frames/2;
    size = max-min;
    for (int i=0;i<size;i++)
    {
        //criando frames intermediários
        m[min+i] = mod1->inter(mod1, mod2, (((float)i+1)/size), (((float)i+1)/size), (((float)i+1)/size), (((float)i+1)/size));
    }
    min = frames/2;
    max = frames;
    size = max-min;
    for (int i=0;i<size;i++)
    {
        //criando frames intermediários
        m[min+i] = mod1->inter(mod2, mod3, (((float)i+1)/size), (((float)i+1)/size), (((float)i+1)/size), (((float)i+1)/size));
    }
}

void animation::handle()
{
    if (mouse.left.isDown)
    {
        camera.rotation.x += mouse.speed.y;
        camera.rotation.y += mouse.speed.x;
    }
    if (key[SDLK_c].hit)
    {
        camera.rotation.x = 0;
        camera.rotation.y = 0;
    }

    wait++;
    if (wait>=10)
    {
        wait = 0;
        index++;
        if (index>=frames)
        {
            index = 0;
        }
    }
    m[index]->handle();
}
