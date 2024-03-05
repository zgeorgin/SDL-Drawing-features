#include <iostream>
#include "primitives.h"

const int WIDTH = 1920, HEIGHT = 1080;

void AnimationTest(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 143, 0, 0, 255);
    int x = 0;
    while(true)
    {
        SDL_RenderClear(renderer);
        x++;
        x%=WIDTH;
        Circle* a = new Circle(x, 200, 50, true);
        a->Draw(renderer);
        SDL_RenderPresent(renderer);
        _sleep(10);
    }
}

int main( int argc, char *argv[] )
{
    SDL_Init( SDL_INIT_EVERYTHING );

    SDL_Window *window = SDL_CreateWindow( "Hello World!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI );

    if ( NULL == window )
    {
        std::cout << "Could not create window: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer( window, -1, 0 );

    SDL_SetRenderDrawColor( renderer, 143, 0, 0, 255 );
    SDL_RenderClear( renderer );
    SDL_RenderPresent( renderer );
    
    SDL_Event windowEvent;
    while ( true )
    {

        if ( SDL_PollEvent( &windowEvent ))
        {
            if ( SDL_QUIT == windowEvent.type )
            {
                break;
            }

            if (SDL_MOUSEMOTION == windowEvent.type)
            {
                int x, y;
                /*if ( SDL_BUTTON_LEFT == windowEvent.button.button)
                {
                    SDL_GetMouseState( &x, &y);
                    SDL_SetRenderDrawColor( renderer, 0, 0, 143, 255 );
                    DrawCircle(renderer, x, y, 5);
                    SDL_RenderPresent(renderer);
                    SDL_SetRenderDrawColor( renderer, 143, 0, 0, 255 );
                }*/
                if ( SDL_BUTTON_RIGHT == windowEvent.button.button)
                {
                    SDL_GetMouseState( &x, &y);
                    SDL_SetRenderDrawColor( renderer, 143, 0, 0, 255 );
                    Circle* a = new Circle(x, y, 50, true);
                    a->Draw(renderer);
                    std::cout << x << " " << y << '\n';
                    SDL_RenderPresent(renderer);
                    SDL_SetRenderDrawColor( renderer, 0, 0, 143, 255 );
                }
            }
            if (SDL_MOUSEBUTTONDOWN == windowEvent.type)
            {
                int x, y;
                if ( SDL_BUTTON_LEFT == windowEvent.button.button)
                {
                    SDL_GetMouseState( &x, &y);
                    Rect* a = new Rect(x, y, x + 50, y + 80, true);
                    a->Draw(renderer);
                    SDL_RenderPresent(renderer);
                    delete a;

                }
                if ( SDL_BUTTON_RIGHT == windowEvent.button.button)
                {
                    SDL_GetMouseState( &x, &y);
                    Circle* a = new Circle(x, y, 50, true);
                    a->Draw(renderer);
                    std::cout << x << " " << y << '\n';
                    SDL_RenderPresent(renderer);
                    SDL_SetRenderDrawColor( renderer, 0, 0, 143, 255 );
                }
                if ( SDL_BUTTON_MIDDLE== windowEvent.button.button)
                {
                    
                }
            }

            if ( SDL_MOUSEWHEEL == windowEvent.type )
            {
                if (windowEvent.wheel.y > 0)
                {

                }
                if (windowEvent.wheel.y < 0)
                {

                }
                if (windowEvent.wheel.x > 0)
                {

                }
                if (windowEvent.wheel.x < 0)
                {
                    
                }
            }
            if ( SDL_KEYDOWN == windowEvent.type)
            { 
                if ( SDLK_a == windowEvent.key.keysym.sym )
                {
                    SDL_SetRenderDrawColor( renderer, 0, 255, 0, 255 );
                    SDL_RenderClear( renderer );
                    SDL_RenderPresent( renderer );
                }
            }
            if ( SDL_KEYUP == windowEvent.type)
            { 
                SDL_SetRenderDrawColor( renderer, 255, 0, 0, 255 );
                SDL_RenderClear( renderer );
                SDL_RenderPresent( renderer );
            }
        }
    }

    SDL_DestroyWindow ( window );
    SDL_Quit( );

    return EXIT_SUCCESS;
}