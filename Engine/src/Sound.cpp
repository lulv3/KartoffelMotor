// Sound.cpp

#include "Sound.h"

Sound::Sound(Mix_Chunk *chunk)
    : m_chunk(chunk) {}

Sound::~Sound()
{
    if (m_chunk != nullptr)
    {
        Mix_FreeChunk(m_chunk);
    }
}

void Sound::play(int channel, int loops)
{
    Mix_PlayChannel(channel, m_chunk, loops);
}

void Sound::setVolume(int volume)
{
    Mix_VolumeChunk(m_chunk, volume);
}
