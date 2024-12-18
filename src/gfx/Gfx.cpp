#include "../../include/Gfx.hpp"

Gfx::~Gfx() {
    SDL_DestroyWindow(window);
    TTF_Quit();
    IMG_Quit();
    Mix_Quit();
    SDL_Quit();
}

Gfx* Gfx::getInstance() {
    if (instance == nullptr) {
        instance = new Gfx();
    }
    return instance;
}

void Gfx::setGfxContext(bool fullscreen, bool vsync) {
    GFX_WINDOW_WIDTH = Defs::SCREEN_WIDTH;
    GFX_WINDOW_HEIGHT = Defs::SCREEN_HEIGHT;

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }

    setOpenGlAttributes();

    unsigned long flags = SDL_WINDOW_OPENGL;
    flags |= SDL_WINDOW_RESIZABLE;
    flags |= SDL_WINDOW_ALLOW_HIGHDPI;
    if (fullscreen) flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;

    // Create SDL2 window
    window = SDL_CreateWindow("C++ SDL2 Glad OpenGL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        GFX_WINDOW_WIDTH,
        GFX_WINDOW_HEIGHT,
        flags
    );

    if (window == nullptr) {
        std::cerr << "Error: " << SDL_GetError() << std::endl;
        return;
    }

    // Set window icon
    std::string icon = "./assets/icon.png";
    SDL_Surface* iconSurface = IMG_Load(icon.c_str());
    SDL_SetWindowIcon(window, iconSurface);
    SDL_FreeSurface(iconSurface);

    // SDL_GLContext is an alias for "void*"
    context = SDL_GL_CreateContext(window);
    if (context == NULL) {
        std::cerr << "Failed to create OpenGL context: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        exit(EXIT_FAILURE);
    }

    // Initialize GLAD
    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
        std::cerr << "Failed to initialize GLAD." << std::endl;
        SDL_GL_DeleteContext(context);
        SDL_DestroyWindow(window);
        SDL_Quit();
        exit(EXIT_FAILURE);
    }

    // Enable v-sync (set 1 to enable, 0 to disable)
    SDL_GL_SetSwapInterval(vsync ? 1 : 0);

    glEnable(GL_DEPTH_TEST);
}

void Gfx::onWindowResize(const Dimension<int> newSize) {
    GFX_WINDOW_WIDTH = newSize.w;
    GFX_WINDOW_HEIGHT = newSize.h;
    SDL_SetWindowSize(window, newSize.w, newSize.h);

    // seems tobe not needed
    //glViewport(0, 0, GFX_WINDOW_WIDTH, GFX_WINDOW_HEIGHT);
}

SDL_Window* Gfx::getWindow() {
    return window;
}

SDL_GLContext Gfx::getContext() {
    return context;
}

void Gfx::showMouseCursor(bool value) {
    SDL_ShowCursor(value ? SDL_ENABLE : SDL_DISABLE);
}

void Gfx::setOpenGlAttributes() {
    // Request at 32-bit color
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);

    // Request a double-buffered, OpenGL 4.1
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
}
