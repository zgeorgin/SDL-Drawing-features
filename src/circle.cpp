#include <circle.h>

void Circle::DrawCircle(SDL_Renderer* renderer)
{
    const int32_t diameter = (radius * 2);
    int32_t x = (radius - 1);
    int32_t y = 0;
    int32_t tx = 1;
    int32_t ty = 1;
    int32_t error = (tx - diameter);
    while (x >= y)
    {
        //  Each of the following renders an octant of the circle
        SDL_RenderDrawPoint(renderer, centreX + x, centreY - y);
        SDL_RenderDrawPoint(renderer, centreX + x, centreY + y);
        SDL_RenderDrawPoint(renderer, centreX - x, centreY - y);
        SDL_RenderDrawPoint(renderer, centreX - x, centreY + y);
        SDL_RenderDrawPoint(renderer, centreX + y, centreY - x);
        SDL_RenderDrawPoint(renderer, centreX + y, centreY + x);
        SDL_RenderDrawPoint(renderer, centreX - y, centreY - x);
        SDL_RenderDrawPoint(renderer, centreX - y, centreY + x);
        if (error <= 0)
        {
            ++y;
            error += ty;
            ty += 2;
        }
        if (error > 0)
        {
            --x;
            tx += 2;
            error += (tx - diameter);
        }
    }
}

void Circle::FillCircle(SDL_Renderer* renderer)
{
    const int32_t diameter = (radius * 2);
    int32_t x = (radius - 1);
    int32_t y = 0;
    int32_t tx = 1;
    int32_t ty = 1;
    int32_t error = (tx - diameter);
    while (x >= y)
    {
        SDL_RenderDrawLine(renderer, centreX - y, centreY + x,
                           centreX + y, centreY + x);
        SDL_RenderDrawLine(renderer, centreX - x, centreY + y,
                           centreX + x, centreY + y);
        SDL_RenderDrawLine(renderer, centreX - x, centreY - y,
                           centreX + x, centreY - y);
        SDL_RenderDrawLine(renderer, centreX - y, centreY - x,
                           centreX + y, centreY - x);
        if (error <= 0)
        {
            ++y;
            error += ty;
            ty += 2;
        }
        if (error > 0)
        {
            --x;
            tx += 2;
            error += (tx - diameter);
        }
    }
}

void Circle::Draw(SDL_Renderer* renderer)
{
    Uint8 tr, tg, tb, ta;
    SDL_GetRenderDrawColor(renderer, &tr, &tg, &tb, &ta);
    SDL_SetRenderDrawColor(renderer, r, g, b, a);

    if (painted)
        FillCircle(renderer);

    DrawCircle(renderer);

    SDL_SetRenderDrawColor(renderer, tr, tg, tb, ta);
}