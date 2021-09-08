#include <stdio.h>
#include <sys/types.h>
#include <syslog.h> 
#include <game.h>

typedef bool(*Builder)(Game *game);

static bool Game_Is_Valid(Game *game);
static bool Game_API_Initialize(Game *game);
static bool Game_Window_Initialize(Game *game);
static bool Game_Render_Initialize(Game *game);
static bool Game_Font_Initialize(Game *game);
static bool Game_Load_Fonts(Game *game);
static bool Game_Setup(Game *game);

static bool Game_Process_Input(Game *game);
static bool Game_Update(Game *game);
static bool Game_Render(Game *game);
static bool Game_Destroy(Game *game);


static void logger(const char *log_message)
{
    openlog("Game", LOG_PID | LOG_CONS , LOG_USER);
    syslog(LOG_ERR, log_message);
    closelog();
}

bool Game_Initialize(Game *game)
{
    bool status = true;

    Builder builder[] = 
    {
        Game_Is_Valid,
        Game_API_Initialize,
        Game_Window_Initialize,
        Game_Render_Initialize,
        Game_Font_Initialize,
        Game_Load_Fonts,
        Game_Setup
    };

    int build_amount = sizeof(builder)/sizeof(builder[0]);

    for(int i = 0; i < build_amount; i++)
    {
        if(!builder[i](game))
            status = false;
    }

    game->is_running = status;  

    return status;
}

bool Game_Run(Game *game)
{      
    while(game->is_running)
    {
        Game_Process_Input(game);
        Game_Update(game);
        Game_Render(game);
    }

    Game_Destroy(game);

    return true;
}

static bool Game_Is_Valid(Game *game)
{
    bool status = true;

    if (!game)
    {
        logger("Error game is NULL");
        status = false;
    }

    return status;
}


static bool Game_API_Initialize(Game *game)
{
    bool status = true;
    (void)game;

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        logger("Error initializing SDL.");
        status = false;
    }

    return status;
}

static bool Game_Window_Initialize(Game *game)
{
    bool status = true;
    game->window = SDL_CreateWindow(
        NULL,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        SDL_WINDOW_SHOWN);

    if (!game->window)
    {
        logger("Error creating SDL Window.");
        status = false;
    }

    return status;
}

static bool Game_Render_Initialize(Game *game)
{
    bool status = true;

    game->renderer = SDL_CreateRenderer(game->window, -1, 0);
    if (!game->renderer)
    {
        logger("Error creating SDL Renderer.");
        status = false;
    }

    return status;
}

static bool Game_Font_Initialize(Game *game)
{
    bool status = true;

    if(TTF_Init() < 0)
    {
        logger("Error TTF Initialize");
        status = false;
    }

    return status;
}


static bool Game_Load_Fonts(Game *game)
{
    bool status = true;
    game->font = TTF_OpenFont("Crazy-Pixel.ttf", 48);
    if(!game->font)
    {
        logger("Cannot find font file.");
        status = false;
    }
    return status;
}

static bool Game_Setup(Game *game)
{
    // Initialize values for the the ball object
    game->ball.dimension.width = 15;
    game->ball.dimension.height = 15;
    game->ball.point.x = 20;
    game->ball.point.y = 20;
    game->ball.speed.vx = 300;
    game->ball.speed.vy = 300;

    // Initialize the values for the paddle object
    game->paddle.dimension.width = 100;
    game->paddle.dimension.height = 20;
    game->paddle.point.x = (WINDOW_WIDTH / 2) - (game->paddle.dimension.width / 2);
    game->paddle.point.y = WINDOW_HEIGHT - 40;
    game->paddle.speed.vx = 0;
    game->paddle.speed.vy = 0;

    game->points = 0;

    return true;
}

static bool Game_Process_Input(Game *game)
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        game->is_running = false;
        break;
    case SDL_KEYDOWN:
        if (event.key.keysym.sym == SDLK_ESCAPE)
            game->is_running = false;
        if (event.key.keysym.sym == SDLK_LEFT)
            game->paddle.speed.vx = -800;
        if (event.key.keysym.sym == SDLK_RIGHT)
            game->paddle.speed.vx = +800;
        break;
    case SDL_KEYUP:
        if (event.key.keysym.sym == SDLK_LEFT)
            game->paddle.speed.vx = 0;
        if (event.key.keysym.sym == SDLK_RIGHT)
            game->paddle.speed.vx = 0;
        break;
    }

    return true;
}

static bool Game_Update(Game *game)
{
    // Calculate how much we have to wait until we reach the target frame time
    int time_to_wait = FRAME_TARGET_TIME - (SDL_GetTicks() - game->last_frame_time);

    // Only delay if we are too fast too update this frame
    if (time_to_wait > 0 && time_to_wait <= FRAME_TARGET_TIME)
        SDL_Delay(time_to_wait);

    // Get a delta time factor converted to seconds to be used to update my objects
    float delta_time = (SDL_GetTicks() - game->last_frame_time) / 1000.0;

    // Store the milliseconds of the current frame
    game->last_frame_time = SDL_GetTicks();

    // update ball and paddle position
    game->ball.point.x += game->ball.speed.vx * delta_time;
    game->ball.point.y += game->ball.speed.vy * delta_time;
    game->paddle.point.x += game->paddle.speed.vx * delta_time;
    game->paddle.point.y += game->paddle.speed.vy * delta_time;

    // Check for ball collision with the walls
    if (game->ball.point.x <= 0 || game->ball.point.x + game->ball.dimension.width >= WINDOW_WIDTH)
        game->ball.speed.vx = -game->ball.speed.vx;
    if (game->ball.point.y < 0)
        game->ball.speed.vy = -game->ball.speed.vy;

    // Check for ball collision with the paddle
    if (game->ball.point.y + game->ball.dimension.height >= game->paddle.point.y && game->ball.point.x + game->ball.dimension.width >= game->paddle.point.x && game->ball.point.x <= game->paddle.point.x + game->paddle.dimension.width)
        game->ball.speed.vy = -game->ball.speed.vy;

    // Prevent paddle from moving outside the boundaries of the window
    if (game->paddle.point.x <= 0)
        game->paddle.point.x = 0;
    if (game->paddle.point.x >= WINDOW_WIDTH - game->paddle.dimension.width)
        game->paddle.point.x = WINDOW_WIDTH - game->paddle.dimension.width;

    // Check for game over
    if (game->ball.point.y + game->ball.dimension.height > WINDOW_HEIGHT)
    {
        game->ball.point.x = WINDOW_WIDTH / 2;
        game->ball.point.y = 0;
    }

    return true;
}

static bool Game_Render(Game *game)
{
    SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 255);
    SDL_RenderClear(game->renderer);

    // Draw a rectangle for the ball object
    SDL_Rect ball_rect = {
        (int)game->ball.point.x,
        (int)game->ball.point.y,
        (int)game->ball.dimension.width,
        (int)game->ball.dimension.height};
    SDL_SetRenderDrawColor(game->renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(game->renderer, &ball_rect);

    // Draw a rectangle for the paddle object
    SDL_Rect paddle_rect = {
        (int)game->paddle.point.x,
        (int)game->paddle.point.y,
        (int)game->paddle.dimension.width,
        (int)game->paddle.dimension.height};
    SDL_SetRenderDrawColor(game->renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(game->renderer, &paddle_rect);

    SDL_RenderPresent(game->renderer);

    return true;
}

static bool Game_Destroy(Game *game)
{
    SDL_DestroyRenderer(game->renderer);
    SDL_DestroyWindow(game->window);
    TTF_CloseFont(game->font);
    SDL_Quit();
    return true;
}

