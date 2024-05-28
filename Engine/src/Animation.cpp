// Animation.cpp
#include "Animation.h"
#include "imgui.h"

Animation::Animation() : currentSequenceIndex(0), currentFrameIndex(0), playing(false), lastFrameTime(0) {}

void Animation::addFrame(const SDL_Rect &srcRect, int duration)
{
    Frame frame;
    frame.srcRect = srcRect;
    frame.duration = duration;
    frames.push_back(frame);
}

void Animation::addSequence(const std::vector<Frame> &frames)
{
    sequences.push_back(frames);
}

void Animation::play()
{
    playing = true;
    lastFrameTime = SDL_GetTicks();
}

void Animation::pause()
{
    playing = false;
}

void Animation::stop()
{
    playing = false;
    currentFrameIndex = 0;
}

void Animation::update()
{
    if (playing)
    {
        Uint32 currentTime = SDL_GetTicks();
        if (currentTime - lastFrameTime >= sequences[currentSequenceIndex][currentFrameIndex].duration)
        {
            currentFrameIndex = (currentFrameIndex + 1) % sequences[currentSequenceIndex].size();
            lastFrameTime = currentTime;
        }
    }
}

void Animation::drawImGuiEditor(const std::string &animationName)
{
    ImGui::Text("Animation: %s", animationName.c_str());
    ImGui::Checkbox("Play", &playing);
    if (ImGui::Button("Stop"))
    {
        stop();
    }
}

SDL_Rect Animation::getCurrentFrame()
{
    return sequences[currentSequenceIndex][currentFrameIndex].srcRect;
}

bool Animation::isPlaying() const
{
    return playing;
}
