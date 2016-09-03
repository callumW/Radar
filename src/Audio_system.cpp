#include "Audio_system.h"
#include "al.h"
#include "alc.h"
#include <cstdlib>

using namespace howling_pass;

Audio_system::Audio_system()
{
    audio_device = alcOpenDevice(NULL);
    if (audio_device) {
        audio_context = alcCreateContext(audio_device, NULL);
        alcMakeContextCurrent(audio_context);
    }
}

Audio_system::~Audio_system()
{
    audio_context = alcGetCurrentContext();
    audio_device = alcGetContextsDevice(audio_context);
    alcMakeContextCurrent(NULL);
    alcCloseDevice(audio_device);
}
