/** 
     * JsMobileBasic API implementation
     * Copyright (c) PROPHESSOR 2018

     * This software is released under the MIT License.
     * https://opensource.org/licenses/MIT
*/

#pragma once

#include <iostream>

int Main();
bool Loop();

namespace JsMB {
#include <math.h>
#include "SDL2/SDL.h"

typedef struct {
    unsigned int     width          ;
    unsigned int     height         ;

    char            *title          ;
    SDL_Window      *sdl_window     ;
    SDL_Renderer    *sdl_renderer   ;
} $_window_t;

typedef struct {
    $_window_t      *window;

    bool            DEBUG;
    unsigned char   color[3];
    unsigned char   bgcolor[3];
} $_JsMB_t;

$_JsMB_t $JsMobileBasic;

// TODO: Header file

// SDL

bool createWindow(const char *title, unsigned short width, unsigned short height) {
    $JsMobileBasic.window->title = (char *) title;
    $JsMobileBasic.window->width = width;
    $JsMobileBasic.window->height = height;
    if($JsMobileBasic.DEBUG)
        std::cout << "createWindow(" << title
                  << ", "            << width
                  << ", "            << height
                  << ")"             << std::endl;
    if($JsMobileBasic.DEBUG)
        std::cout << "{ *title: \""  << $JsMobileBasic.window->title
                  << "\", width: "   << $JsMobileBasic.window->width
                  << ", height: "    << $JsMobileBasic.window->height
                  << " }"            << std::endl;

    $JsMobileBasic.window->sdl_window = SDL_CreateWindow(title, 0, 0, width, height, SDL_WINDOW_SHOWN);
    if($JsMobileBasic.window->sdl_window == 0x0) {
        std::cout << "[ERROR]: SDL_CreateWindow Error #" << SDL_GetError() << std::endl;
        return false;
    } else if($JsMobileBasic.DEBUG) {
        std::cout << "Initialize window - OK!" << std::endl;
    }

    $JsMobileBasic.window->sdl_renderer = SDL_CreateRenderer($JsMobileBasic.window->sdl_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if($JsMobileBasic.window->sdl_renderer == 0x0) {
        std::cout << "[ERROR]: SDL_CreateRenderer Error #" << SDL_GetError() << std::endl;
        return false;
    } else if($JsMobileBasic.DEBUG) {
        std::cout << "Initialize renderer - OK!" << std::endl;
    }

    return true;
}

void delay(int ms) {
    SDL_Delay(ms);
}

// Get

unsigned short screenWidth() {
    return $JsMobileBasic.window->width;
}

unsigned short screenHeight() {
    return $JsMobileBasic.window->height;
}

// Math
/** From math.h
     * sin
     * cos
     * tan
     * pow
     * exp
     * log
     * sqrt
     * asin
     * acos
     * atan
     * ceil
     * floor
     * abs
*/

double ctg(double x) {
    return 1 / tan(x);
}

float random(float min, float max) {
    // TODO:
    return (min + max) / 2;
}

// Graphics

bool setColor(unsigned char red, unsigned char green, unsigned char blue) {
    $JsMobileBasic.color[0] = red;
    $JsMobileBasic.color[1] = green;
    $JsMobileBasic.color[2] = blue;

    SDL_SetRenderDrawColor($JsMobileBasic.window->sdl_renderer, red, green, blue, 255);

    return true;
}

bool setBgColor(unsigned char red, unsigned char green, unsigned char blue) {
    $JsMobileBasic.bgcolor[0] = red;
    $JsMobileBasic.bgcolor[1] = green;
    $JsMobileBasic.bgcolor[2] = blue;

    return false;
}

bool cls() {
    SDL_RenderClear($JsMobileBasic.window->sdl_renderer);
    return true;
}

bool repaint() {
    SDL_RenderPresent($JsMobileBasic.window->sdl_renderer);
}

// Draw


bool drawRect(short x, short y, short width, short height) {
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = width;
    rect.h = height;

    SDL_RenderDrawRect($JsMobileBasic.window->sdl_renderer, &rect);

    return true;
}

bool fillRect(short x, short y, short width, short height) {
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = width;
    rect.h = height;

    SDL_RenderDrawRect($JsMobileBasic.window->sdl_renderer, &rect);
    SDL_RenderFillRect($JsMobileBasic.window->sdl_renderer, &rect);

    return true;
}

bool fillScreen(unsigned char red, unsigned char green, unsigned char blue) {
    unsigned char tmpcolor[3];
    tmpcolor[0] = $JsMobileBasic.color[0];
    tmpcolor[1] = $JsMobileBasic.color[1];
    tmpcolor[2] = $JsMobileBasic.color[2];

    setColor(red, green, blue);
    fillRect(0, 0, screenWidth(), screenHeight());
    setColor(tmpcolor[0], tmpcolor[1], tmpcolor[2]);

    return true;
}

// Main

bool $Loop(); // Promise =D

int $Main() {
    $JsMobileBasic.window = new $_window_t;
    $JsMobileBasic.DEBUG = true;
    
    if($JsMobileBasic.DEBUG)
        std::cout << "CJsMB_SDL2 Loaded! main();" << std::endl;

    if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "[ERROR]: SDL2 Init Error " << SDL_GetError() << std::endl;
        return 1;
    } else if($JsMobileBasic.DEBUG) {
        std::cout << "Initialize SDL - OK!" << std::endl;
    }

    int mainres = Main();
    if(mainres != 0) return mainres;

    bool loopres = true;
    while(loopres) {
        loopres = Loop();
    }
}

bool $Loop() {
    return Loop();
}

} // namespace JsMB

int main() {
    return JsMB::$Main();
}
