#ifndef AUDIO_SYSTEM_H
#define AUDIO_SYSTEM_H
#include "alc.h"
namespace howling_pass {
class Audio_system {
public:

	Audio_system();
	~Audio_system();

private:
	ALCdevice* audio_device;
	ALCcontext* audio_context;
};
}

#endif