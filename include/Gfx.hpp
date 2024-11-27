/**
* @file Gfx.hpp
* @author Hudson Schumaker
* @brief Defines the Gfx class.
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
#pragma once
#include "Pch.hpp"
#include "Dimension.hpp"

/**
* @class Gfx
* @brief The graphics hanlder class.
*
* This class provides functionality for creating and manipulating graphics.
*/
class Gfx final {
private:
    inline static Gfx* instance = nullptr;
    SDL_Window* window = nullptr;
    SDL_GLContext context = nullptr;

    int GFX_WINDOW_WIDTH = 0;
    int GFX_WINDOW_HEIGHT = 0;

    Gfx() = default;
    void setOpenGlAttributes();

public:
    ~Gfx();

    /**
     * @brief Returns the singleton instance of the Gfx class.
     * @return Pointer to the singleton instance.
    */
    static Gfx* getInstance();

    /**
     * @brief Initializes the SDL library and creates the SDL_Window and SDL_Renderer.
     * 
     * @param fullscreen If true, the window is created in fullscreen mode.
     * @param vsync If true, vsync is enabled.
    */
    void setGfxContext(bool fullscreen, bool vsync);

    /**
     * @brief Handles window resize events.
     * @param newSize 
     */
    void onWindowResize(const Dimension<int> newSize);

    /**
     * @brief Returns the SDL_Window.
     * @return Pointer to the SDL_Window.
    */
    SDL_Window* getWindow();

    /**
     * @brief Returns the SDL_Renderer.
     * @return Pointer to the SDL_Renderer.
    */
    SDL_Renderer* getRenderer();

    /**
     * @brief Returns the SDL_GLContext.
     * @return Pointer to the SDL_GLContext.
    */
    SDL_GLContext getContext();

    /**
     * @brief Shows or hides the mouse cursor.
     * @param value If true, the mouse cursor is shown. If false, the mouse cursor is hidden.
    */
    void showMouseCursor(bool value);
};
