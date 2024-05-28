// Sound.h

#ifndef SOUND_H
#define SOUND_H

#include <SDL_mixer.h>
#include <string>
#include <memory>

class Sound
{
public:
    Sound(Mix_Chunk *chunk);
    ~Sound();

    void play(int channel = -1, int loops = 0);
    void setVolume(int volume);

private:
    Mix_Chunk *m_chunk;
};

#endif // SOUND_H
