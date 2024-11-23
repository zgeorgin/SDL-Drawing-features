#include <primitive.h>
#ifndef CIRCLE_H
#define CIRCLE_H

class Circle : public Primitive
{
public:
    int32_t centreX, centreY, radius;
    bool painted;
    Circle(int32_t x, int32_t y, int32_t radius, bool painted = false, Uint8 r = 255, Uint8 g = 255, Uint8 b = 255, Uint8 a = 255):
     centreX(x), centreY(y), radius(radius), painted(painted), Primitive(r, g, b, a) {};
    ~Circle() {};
    void Draw(SDL_Renderer* renderer);
private:
    void DrawCircle(SDL_Renderer* renderer);
    void FillCircle(SDL_Renderer* renderer);
};

#endif