#include <rect.h>
void Rect::DrawRect(SDL_Renderer* renderer)
{
    SDL_RenderDrawLine(renderer, x1, y1, x2, y1);
    SDL_RenderDrawLine(renderer, x1, y1, x1, y2);
    SDL_RenderDrawLine(renderer, x2, y1, x2, y2);
    SDL_RenderDrawLine(renderer, x1, y2, x2, y2);
}

void Rect::FillRect(SDL_Renderer* renderer)
{
    for (int c = x1; c <= x2; c++)
    {
        SDL_RenderDrawLine(renderer, c, y1, c, y2);
    }
}

void Rect::Draw(SDL_Renderer* renderer)
{
    Uint8 tr, tg, tb, ta;
    SDL_GetRenderDrawColor(renderer, &tr, &tg, &tb, &ta);
    SDL_SetRenderDrawColor(renderer, r, g, b, a);

    if (painted)
        FillRect(renderer);
    else
        DrawRect(renderer);

    SDL_SetRenderDrawColor(renderer, tr, tg, tb, ta);
}
