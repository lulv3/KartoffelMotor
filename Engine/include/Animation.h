// Animation.h
#pragma once

#include <vector>
#include <string>
#include <SDL.h>

struct Frame
{
    SDL_Rect srcRect;
    int duration; // Duration of the frame in milliseconds
};

class Animation
{
public:
    Animation();
    void addFrame(const SDL_Rect &srcRect, int duration);
    void addSequence(const std::vector<Frame> &frames);
    void play();
    void pause();
    void stop();
    void update();
    void drawImGuiEditor(const std::string &animationName);
    SDL_Rect getCurrentFrame();
    bool isPlaying() const;

private:
    std::vector<Frame> frames;
    std::vector<std::vector<Frame>> sequences;
    size_t currentSequenceIndex;
    size_t currentFrameIndex;
    bool playing;
    Uint32 lastFrameTime;
};
