#include <primitive.h>
#ifndef GRID_H
#define GRID_H
class Grid : public Primitive
{
public:
    int32_t offset;
    Grid(int32_t offset, Uint8 r = 0, Uint8 g = 0, Uint8 b = 0, Uint8 a = 255) : offset(offset), Primitive(r, g, b, a) {};
    ~Grid() {};
    void Draw(SDL_Renderer* renderer, int height, int width);
};
#endif