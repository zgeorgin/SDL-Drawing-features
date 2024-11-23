#include <primitive.h>
#ifndef TRIANGLE_H
#define TRIANGLE_H
class Triangle : public Primitive
{
public:
    int32_t x1, x2, x3, y1, y2, y3;
    bool painted;
    Triangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, bool painted = false, Uint8 r = 255, Uint8 g = 255, Uint8 b = 255, Uint8 a = 255):
     x1(x1), x2(x2), y1(y1), y2(y2),  x3(x3), y3(y3), painted(painted), Primitive(r, g, b, a) {};
    ~Triangle() {};
    void Draw(SDL_Renderer* renderer);
private:
    void DrawTriangle(SDL_Renderer* renderer);
};
#endif