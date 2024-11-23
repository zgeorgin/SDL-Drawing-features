#include <primitive.h>
#ifndef RECT_H
#define RECT_H

class Rect : public Primitive
{
public:
    int32_t x1, x2, y1, y2;
    bool painted;
    Rect(int32_t x1, int32_t y1, int32_t x2, int32_t y2, bool painted = false, Uint8 r = 255, Uint8 g = 255, Uint8 b = 255, Uint8 a = 255):
     x1(x1), x2(x2), y1(y1), y2(y2),  painted(painted), Primitive(r, g, b, a) {};
    ~Rect() {};
    void Draw(SDL_Renderer* renderer);
private:
    void DrawRect(SDL_Renderer* renderer);
    void FillRect(SDL_Renderer* renderer);
};

#endif
