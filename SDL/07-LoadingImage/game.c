#include "game.h"
#include <SDL2/SDL_image.h>

bool m_bRunning = false;
SDL_Window *m_pWindow;
SDL_Renderer *m_pRenderer;
SDL_Texture *m_pTexture;
SDL_Rect m_sourceRectangle;
SDL_Rect m_destinationRectangle;

bool init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;

    if(fullscreen)
        flags = SDL_WINDOW_FULLSCREEN;

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if(m_pWindow)
        {
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
            if(m_pRenderer)
            {
                SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
                // SDL_Surface *pTempSurface = SDL_LoadBMP("assets/rider.bmp");
                // SDL_Surface *pTempSurface = SDL_LoadBMP("assets/animate-alpha.png");
                SDL_Surface *pTempSurface = IMG_Load("assets/animate-alpha.png");
                m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
                SDL_FreeSurface(pTempSurface);

                // SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);
                m_destinationRectangle.x = m_sourceRectangle.x = 0;
                m_destinationRectangle.y = m_sourceRectangle.y = 0;
                m_destinationRectangle.w = m_sourceRectangle.w = 128;
                m_destinationRectangle.h = m_sourceRectangle.h = 82;
                

              
            }
            else 
            {
                return false;
            }
        }
        else 
        {
            return false;
        }
    }
    else 
    {
        return false;
    }

    m_bRunning = true;
    return true;
}

void render(void)
{
    SDL_RenderClear(m_pRenderer);
    // SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
    SDL_RenderCopyEx(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle, 0, 0, SDL_FLIP_NONE);

    // SDL_RenderCopy(m_pRenderer, m_pTexture, 0, 0);
    SDL_RenderPresent(m_pRenderer);
}

void update(void)
{
    m_sourceRectangle.x = 128 * (int)((SDL_GetTicks() / 100) % 6);
}

void handleEvents(void)
{
    SDL_Event event;
    if(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_QUIT:
                m_bRunning = false;
            break;

            default:
                break;
        }
    }
}

void clean(void)
{
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}

bool running(void)
{
    return m_bRunning;
}


int main(int argc, char *argv[])
{
    init("Chapter 1", 100, 100, 640, 480, false);

    while(running())
    {
        handleEvents();
        update();
        render();
    }

    clean();
    return 0;
}
