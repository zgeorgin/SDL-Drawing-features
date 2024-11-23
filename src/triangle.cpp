#include <triangle.h>

void Triangle::DrawTriangle(SDL_Renderer* renderer)
{
    SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
    SDL_RenderDrawLine(renderer, x1, y1, x3, y3);
    SDL_RenderDrawLine(renderer, x2, y2, x3, y3);
}

void Triangle::Draw(SDL_Renderer* renderer)
{
    Uint8 tr, tg, tb, ta;
    SDL_GetRenderDrawColor(renderer, &tr, &tg, &tb, &ta);
    SDL_SetRenderDrawColor(renderer, r, g, b, a);

    DrawTriangle(renderer);

    SDL_SetRenderDrawColor(renderer, tr, tg, tb, ta);
}
