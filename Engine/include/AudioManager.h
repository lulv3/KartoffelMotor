// AudioManager.h
#pragma once

#include <SDL_mixer.h>
#include <string>
#include <vector>
#include "imgui.h"

class AudioManager
{
public:
    AudioManager();
    ~AudioManager();

    bool loadSound(const std::string &filePath);
    bool playSound(int index, int loops = 0);
    void stopAllSounds();
    void pauseAllSounds();
    void resumeAllSounds();
    bool isSoundPlaying(int index);
    void setSoundVolume(int index, int volume);
    void showAudioManagerUI();

private:
    struct Sound
    {
        Mix_Chunk *chunk;
        int volume;
    };

    std::vector<Sound> m_sounds;
};
