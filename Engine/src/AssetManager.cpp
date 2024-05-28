// AssetManager.cpp

#include "AssetManager.h"

AssetManager::AssetManager() {}

std::shared_ptr<Sprite> AssetManager::createSprite(const std::string &name, const std::string &imagePath)
{
    auto texture = loadTexture(imagePath);
    if (!texture)
    {
        return nullptr;
    }

    auto sprite = std::make_shared<Sprite>(texture);
    m_sprites[name] = sprite;
    return sprite;
}

std::shared_ptr<Sprite> AssetManager::getSprite(const std::string &name)
{
    auto it = m_sprites.find(name);
    if (it != m_sprites.end())
    {
        return it->second;
    }
    return nullptr;
}

bool AssetManager::removeSprite(const std::string &name)
{
    return m_sprites.erase(name) > 0;
}

void AssetManager::showSpriteEditorUI()
{
    // Show Sprite Editor UI implementation
}

std::shared_ptr<Texture> AssetManager::loadTexture(const std::string &imagePath)
{
    // Load texture implementation
}

std::shared_ptr<Texture> AssetManager::getTexture(const std::string &imagePath)
{
    // Get texture implementation
}

bool AssetManager::removeTexture(const std::string &imagePath)
{
    // Remove texture implementation
}

void AssetManager::showTextureManagerUI()
{
    // Show Texture Manager UI implementation
}

std::shared_ptr<Animation> AssetManager::createAnimation(const std::string &name)
{
    // Create animation implementation
}

std::shared_ptr<Animation> AssetManager::getAnimation(const std::string &name)
{
    // Get animation implementation
}

bool AssetManager::removeAnimation(const std::string &name)
{
    // Remove animation implementation
}

void AssetManager::showAnimationEditorUI()
{
    // Show Animation Editor UI implementation
}

std::shared_ptr<Sound> AssetManager::loadSound(const std::string &soundPath)
{
    // Load sound implementation
}

std::shared_ptr<Sound> AssetManager::getSound(const std::string &soundPath)
{
    // Get sound implementation
}

bool AssetManager::removeSound(const std::string &soundPath)
{
    // Remove sound implementation
}

void AssetManager::showSoundManagerUI()
{
    // Show Sound Manager UI implementation
}

void AssetManager::showEditorUI()
{
    showSpriteEditorUI();
    showTextureManagerUI();
    showAnimationEditorUI();
    showSoundManagerUI();
}
