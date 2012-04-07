#ifndef AD_H
#define AD_H

#include <AL/al.h>
#include <AL/alut.h>
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

typedef struct Sound
{
    ALuint id;
    string *name;
    ALuint Buffer;
    ALuint Source;
    ALfloat pitch;
    ALfloat gain;
    ALfloat SourcePos[3];
    ALfloat SourceVel[3];
    ALfloat SourceDir[3];

}Sound;

class audioDevice
{
public:
    //configuração do Som
    static ALCcontext *Context;
    static ALCdevice *Device;
    static int countRes;
    //Quanto mais proximo de zero o parametro de decaimento menor será o decaimento
    static float decayParameter;

    //Propriedades do ouvinte
    static ALfloat ListenerPos[3];
    static ALfloat ListenerVel[3];
    static ALfloat ListenerOri[3];

    static vector <Sound> sound;


    static void initilize( float decayParameter = 0 );
    static int loadWAV(string filename);
    static bool playSound(int id, bool loop = false);
    static bool stopSound(int id);
    static void setSrcAttributes(int id, float srcPos[3], float srcVel[3], float srcDir[3], float gain = 1, float pitch = 1);
    static void setLstAttributes(float lstPos[3], float lstVel[3], float lstOri[]);
    static void setDecayParameter( float decayParameter );
};

#endif
