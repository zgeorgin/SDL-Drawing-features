#include <SDL2/SDL.h>
#ifndef PRIMITIVE_H
#define PRIMITIVE_H

class Primitive
{
public:
    Uint8 r, g, b, a;
    Primitive(Uint8 r, Uint8 g, Uint8 b, Uint8 a) : r(r), g(g), b(b), a(a) {};
    ~Primitive() {};
    void Draw(SDL_Renderer* renderer) {};
    void ChangeColor(Uint8 r, Uint8 g, Uint8 b) {this->r = r; this->g = g; this->b = b;};
};

#endif