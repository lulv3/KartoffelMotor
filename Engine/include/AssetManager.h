// AssetManager.h

#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <unordered_map>
#include <string>
#include <memory>
#include "Sprite.h"
#include "Texture.h"
#include "Animation.h"
#include "Sound.h"
#include "imgui.h"

class AssetManager
{
public:
    AssetManager();

    // Sprite related methods
    std::shared_ptr<Sprite> createSprite(const std::string &name, const std::string &imagePath);
    std::shared_ptr<Sprite> getSprite(const std::string &name);
    bool removeSprite(const std::string &name);
    void showSpriteEditorUI();

    // Texture related methods
    std::shared_ptr<Texture> loadTexture(const std::string &imagePath);
    std::shared_ptr<Texture> getTexture(const std::string &imagePath);
    bool removeTexture(const std::string &imagePath);
    void showTextureManagerUI();

    // Animation related methods
    std::shared_ptr<Animation> createAnimation(const std::string &name);
    std::shared_ptr<Animation> getAnimation(const std::string &name);
    bool removeAnimation(const std::string &name);
    void showAnimationEditorUI();

    // Sound related methods
    std::shared_ptr<Sound> loadSound(const std::string &soundPath);
    std::shared_ptr<Sound> getSound(const std::string &soundPath);
    bool removeSound(const std::string &soundPath);
    void showSoundManagerUI();

    // ImGui methods
    void showEditorUI();

private:
    std::unordered_map<std::string, std::shared_ptr<Sprite>> m_sprites;
    std::unordered_map<std::string, std::shared_ptr<Texture>> m_textures;
    std::unordered_map<std::string, std::shared_ptr<Animation>> m_animations;
    std::unordered_map<std::string, std::shared_ptr<Sound>> m_sounds;
};

#endif // ASSETMANAGER_H
