#include "audiodevice.h"
#include <QMessageBox>
#include <QString>

//configuração do Som
ALCcontext *audioDevice::Context;
ALCdevice *audioDevice::Device;
int audioDevice::countRes;
//Quanto mais proximo de zero o parametro de decaimento menor será o decaimento
float audioDevice::decayParameter;

//Propriedades do ouvinte
ALfloat audioDevice::ListenerPos[3];
ALfloat audioDevice::ListenerVel[3];
ALfloat audioDevice::ListenerOri[3];

vector <Sound> audioDevice::sound;

void audioDevice::initilize( float decayParameter )
{
    alutInit (0, NULL);
    countRes = 0;

    audioDevice::decayParameter = decayParameter;
}

int audioDevice::loadWAV(string filename)
{
    for( int i = 0; i<countRes; i++ )
    {
        if( *(sound[i].name) == filename )
            return i;
    }

    sound.resize(countRes+1);
    alGenBuffers(1, &sound[countRes].Buffer);
    alGenSources(1, &sound[countRes].Source);

    sound[countRes].Buffer = alutCreateBufferFromFile((filename).c_str());
    if (sound[countRes].Buffer == AL_NONE) {
        FILE *f = fopen("debug.txt", "a");
        fprintf(f,"Não foi possivel carregar o arquivo %s\n", filename.c_str());
        fclose(f);
        printf("Could not load %s\n", "test.wav");
        return -1;
    }
    sound[countRes].pitch = 1.0f;
    alSourcei (sound[countRes].Source, AL_BUFFER, sound[countRes].Buffer);
    alSourcei (sound[countRes].Source, AL_LOOPING, AL_FALSE);
    sound[countRes].name = new string(filename);

    Context = alcGetCurrentContext();
    Device = alcGetContextsDevice(Context);
    countRes++;
    return countRes-1;
}

bool audioDevice::playSound(int id, bool loop)
{
    if( id < 0 || id > countRes - 1 )
        return false;

//    float sourcePos[3];
//    float listenerPos[3];
//    sourcePos[0] = sound[id].sourcePos[0]*decayParameter;
//    sourcePos[1] = sound[id].sourcePos[1]*decayParameter;
//    sourcePos[2] = sound[id].sourcePos[2]*decayParameter;
//    listenerPos[0] = this->listenerPos[0]*decayParameter;
//    listenerPos[1] = this->listenerPos[1]*decayParameter;
//    listenerPos[2] = this->listenerPos[2]*decayParameter;

    alSourcei (sound[id].Source,AL_LOOPING, loop );

    alSourcePlay(sound[id].Source);

    return true;
}

void audioDevice::setSrcAttributes(int id, float srcPos[3], float srcVel[3], float srcDir[3], float gain, float pitch)
{
    if( id < 0 || id > countRes - 1 )
        return;

    sound[id].SourcePos[0] = srcPos[0]*decayParameter;
    sound[id].SourcePos[1] = srcPos[1]*decayParameter;
    sound[id].SourcePos[2] = srcPos[2]*decayParameter;
    sound[id].SourceVel[0] = srcVel[0]*decayParameter;
    sound[id].SourceVel[1] = srcVel[1]*decayParameter;
    sound[id].SourceVel[2] = srcVel[2]*decayParameter;
    sound[id].SourceDir[0] = srcDir[0]*decayParameter;
    sound[id].SourceDir[1] = srcDir[1]*decayParameter;
    sound[id].SourceDir[2] = srcDir[2]*decayParameter;
    sound[id].pitch = gain;
    sound[id].gain = pitch;

    alSourcefv(sound[id].Source,AL_POSITION, sound[id].SourcePos );
    alSourcefv(sound[id].Source,AL_VELOCITY, sound[id].SourceVel );
    alSourcefv(sound[id].Source,AL_DIRECTION,sound[id].SourceDir );
    alSourcef (sound[id].Source, AL_PITCH, sound[id].pitch);
    alSourcef (sound[id].Source, AL_GAIN,  sound[id].gain);

}
void audioDevice::setLstAttributes(float lstPos[3], float lstVel[3], float lstOri[3])
{
    ListenerPos[0] = lstPos[0]*decayParameter;
    ListenerPos[1] = lstPos[1]*decayParameter;
    ListenerPos[2] = lstPos[2]*decayParameter;
    ListenerVel[0] = lstVel[0]*decayParameter;
    ListenerVel[1] = lstVel[1]*decayParameter;
    ListenerVel[2] = lstVel[2]*decayParameter;
    ListenerOri[0] = lstOri[0]*decayParameter;
    ListenerOri[1] = lstOri[1]*decayParameter;
    ListenerOri[2] = lstOri[2]*decayParameter;

    alListenerfv(AL_POSITION,   ListenerPos );
    alListenerfv(AL_VELOCITY,   ListenerVel );
    alListenerfv(AL_ORIENTATION,ListenerOri );
}

bool audioDevice::stopSound(int id)
{
    if( id < 0 || id > countRes - 1 )
        return false;
    alSourceStop(sound[id].Source);

    return true;
}

void audioDevice::setDecayParameter( float decayParameter )
{
    audioDevice::decayParameter = decayParameter;
}


