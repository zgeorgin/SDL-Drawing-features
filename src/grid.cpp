#include <grid.h>
void Grid::Draw(SDL_Renderer* renderer, int height, int width)
{
    Uint8 tr, tg, tb, ta;
    SDL_GetRenderDrawColor(renderer, &tr, &tg, &tb, &ta);
    SDL_SetRenderDrawColor(renderer, r, g, b, a);

    for (int x = 0; x < width; x += offset)
    {
        SDL_RenderDrawLine(renderer, x, 0, x, height/offset * offset);
    }
    for (int y = 0; y < height; y += offset)
    {
        SDL_RenderDrawLine(renderer, 0, y, width/offset * offset, y);
    }

    SDL_SetRenderDrawColor(renderer, tr, tg, tb, ta);
}