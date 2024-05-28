// AudioManager.cpp
#include "AudioManager.h"

AudioManager::AudioManager()
{
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        // Fehlerbehandlung bei der Initialisierung von SDL_mixer...
    }
}

AudioManager::~AudioManager()
{
    for (auto &sound : m_sounds)
    {
        Mix_FreeChunk(sound.chunk);
    }
    Mix_CloseAudio();
}

bool AudioManager::loadSound(const std::string &filePath)
{
    Mix_Chunk *chunk = Mix_LoadWAV(filePath.c_str());
    if (!chunk)
    {
        // Fehlerbehandlung beim Laden des Sounds...
        return false;
    }
    m_sounds.push_back({chunk, MIX_MAX_VOLUME});
    return true;
}

bool AudioManager::playSound(int index, int loops)
{
    if (index < 0 || index >= m_sounds.size())
    {
        // Fehlerbehandlung bei ungültigem Index...
        return false;
    }
    Mix_PlayChannel(-1, m_sounds[index].chunk, loops);
    return true;
}

void AudioManager::stopAllSounds()
{
    Mix_HaltChannel(-1);
}

void AudioManager::pauseAllSounds()
{
    Mix_Pause(-1);
}

void AudioManager::resumeAllSounds()
{
    Mix_Resume(-1);
}

bool AudioManager::isSoundPlaying(int index)
{
    if (index < 0 || index >= m_sounds.size())
    {
        // Fehlerbehandlung bei ungültigem Index...
        return false;
    }
    return Mix_Playing(index) != 0;
}

void AudioManager::setSoundVolume(int index, int volume)
{
    if (index < 0 || index >= m_sounds.size())
    {
        // Fehlerbehandlung bei ungültigem Index...
        return;
    }
    m_sounds[index].volume = volume;
    Mix_VolumeChunk(m_sounds[index].chunk, volume);
}

void AudioManager::showAudioManagerUI()
{
    ImGui::Begin("Audio Manager");
    ImGui::Text("Loaded Sounds: %d", m_sounds.size());
    if (ImGui::Button("Stop All Sounds"))
    {
        stopAllSounds();
    }
    ImGui::SameLine();
    if (ImGui::Button("Pause All Sounds"))
    {
        pauseAllSounds();
    }
    ImGui::SameLine();
    if (ImGui::Button("Resume All Sounds"))
    {
        resumeAllSounds();
    }
    ImGui::Separator();
    ImGui::Text("Sound List:");
    for (int i = 0; i < m_sounds.size(); ++i)
    {
        ImGui::Text("Sound %d", i);
        ImGui::SliderInt(("Volume##" + std::to_string(i)).c_str(), &m_sounds[i].volume, 0, MIX_MAX_VOLUME);
        if (ImGui::Button(("Play##" + std::to_string(i)).c_str()))
        {
            playSound(i);
        }
    }
    ImGui::End();
}
