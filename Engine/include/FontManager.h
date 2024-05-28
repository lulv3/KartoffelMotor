// FontManager.h

#ifndef FONT_MANAGER_H
#define FONT_MANAGER_H

#include <SDL_ttf.h>
#include <string>
#include <unordered_map>

class FontManager
{
public:
    FontManager();
    ~FontManager();

    bool loadFont(const std::string &filePath, const std::string &fontName, int fontSize);
    TTF_Font *getFont(const std::string &fontName);
    void drawText(SDL_Renderer *renderer, const std::string &fontName, const std::string &text, int x, int y, SDL_Color color);

private:
    std::unordered_map<std::string, TTF_Font *> m_fonts;
};

#endif // FONT_MANAGER_H
