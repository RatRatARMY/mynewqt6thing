//
// Created by ratratarmy on 02/02/2026.
//

#include "sdl3game4.hpp"
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>
#include "newrand.hpp"
#include <sstream>
#include <iomanip>

int game4::launch() {
    const int SCREEN_WIDTH = 1152;
    const int SCREEN_HEIGHT = 864;
    const int FPS = 60;
    if (not SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Cannot init SDL for some reason: %s", SDL_GetError());
        return 1;
    }
    if (not TTF_Init()) {
        SDL_Log("Cannot init SDL_ttf for some reason: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }
    SDL_Window* window = SDL_CreateWindow("Created with SDL3", SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if (not window) {
        SDL_Log("Cannot create window for some reason: %s", SDL_GetError());
        TTF_Quit();
        SDL_Quit();
        return 1;
    }
    SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);
    if (not renderer) {
        SDL_Log("Cannot create renderer for some reason: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return 1;
    }
    SDL_Texture* bg_img = IMG_LoadTexture(renderer, "assets/sdl/spr_background3.png");
    SDL_Texture* rocketship_img = IMG_LoadTexture(renderer, "assets/sdl/spr_rocketship.png");
    SDL_Texture* star_img = IMG_LoadTexture(renderer, "assets/sdl/spr_star.png");
    SDL_Surface* icon_img = IMG_Load("assets/sdl/SDL_logo.png");
    if (icon_img) {
        SDL_SetWindowIcon(window, icon_img);
        SDL_DestroySurface(icon_img);
    }
    if (not bg_img or not rocketship_img or not star_img) {
        SDL_Log("Cannot load some images for some reason. Make sure these images are in the assets folder: %s", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return 1;
    }
    TTF_Font* common_font = TTF_OpenFont("assets/sdl/ARIAL.TTF", 24);
    if (not common_font) {
        SDL_Log("Cannot load font for some reason. Make sure this font are in the assets folder: %s", SDL_GetError());
        SDL_DestroyTexture(bg_img);
        SDL_DestroyTexture(rocketship_img);
        SDL_DestroyTexture(star_img);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return 1;
    }
    int score = 0;
    int missed = 0;
    long long can_reach = static_cast<long long>(score + missed);
    int star_x = randint(0, SCREEN_WIDTH - 91);
    int star_y = 0;
    int star_speed = 5;
    int rocketship_x = 576;
    int rocketship_y = SCREEN_HEIGHT - 185;
    int rocketship_speed = 0;
    bool can_collide = true;
    bool game_over = false;
    // main loop
    bool running = true;
    SDL_Event e;
    Uint64 last_time = SDL_GetTicksNS();
    while (running) {
        while (SDL_PollEvent(&e)) {
            switch (e.type) {
                case SDL_EVENT_QUIT:
                    running = false;
                    break;
                case SDL_EVENT_KEY_DOWN:
                    if (e.key.key == SDLK_LEFT or e.key.key == SDLK_A) {
                        rocketship_speed = -5;
                    }
                    else if (e.key.key == SDLK_RIGHT or e.key.key == SDLK_D) {
                        rocketship_speed = 5;
                    }
                    break;
                case SDL_EVENT_KEY_UP:
                    rocketship_speed = 0;
                    break;
            }
        }
        if (not game_over) {
            rocketship_x += rocketship_speed;
            if (rocketship_x < 0) rocketship_x = 0;
            else if (rocketship_x > SCREEN_WIDTH - 126) rocketship_x = SCREEN_WIDTH - 126;
            star_y += star_speed;
            float dx = static_cast<float>(rocketship_x - star_x);
            float dy = static_cast<float>(rocketship_y - star_y);
            float distance = std::sqrt(dx * dx + dy * dy);
            if (star_y > SCREEN_HEIGHT) {
                star_y = 0;
                star_x = randint(0, SCREEN_WIDTH - 91);
                can_collide = true;
                missed++;
            }
            if (can_collide and distance < 60) {
                score++;
                star_y = 0;
                star_x = randint(0, SCREEN_WIDTH - 91);
                can_collide = false;
            }
            if (star_y < 200) can_collide = true;
            if (score == std::numeric_limits<int>::max()) game_over = true;
        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_FRect bg_rect = {0, 0, static_cast<float>(SCREEN_WIDTH), static_cast<float>(SCREEN_HEIGHT)};
        SDL_RenderTexture(renderer, bg_img, nullptr, &bg_rect);
        if (not game_over) {
            SDL_FRect rocketship_rect = {static_cast<float>(rocketship_x), static_cast<float>(rocketship_y), 126, 185};
            SDL_RenderTexture(renderer, rocketship_img, nullptr, &rocketship_rect);
            SDL_FRect star_rect = {static_cast<float>(star_x), static_cast<float>(star_y), 91, 90};
            SDL_RenderTexture(renderer, star_img, nullptr, &star_rect);
        }
        SDL_Color white = {255, 255, 255, 255};
        std::string score_str = "Score: " + std::to_string(score);
        SDL_Surface* score_surface = TTF_RenderText_Solid(common_font, score_str.c_str(), 0, white);
        SDL_Texture* score_texture = SDL_CreateTextureFromSurface(renderer, score_surface);
        SDL_FRect score_rect = {0, 0, static_cast<float>(score_surface->w), static_cast<float>(score_surface->h)};
        SDL_RenderTexture(renderer, score_texture, nullptr, &score_rect);
        SDL_DestroySurface(score_surface);
        SDL_DestroyTexture(score_texture);
        std::string missed_str = "Missed: " + std::to_string(missed);
        SDL_Surface* missed_surface = TTF_RenderText_Solid(common_font, missed_str.c_str(), 0, white);
        SDL_Texture* missed_texture = SDL_CreateTextureFromSurface(renderer, missed_surface);
        SDL_FRect missed_rect = {0, 20, static_cast<float>(score_surface->w), static_cast<float>(score_surface->h)};
        SDL_RenderTexture(renderer, missed_texture, nullptr, &missed_rect);
        SDL_DestroySurface(missed_surface);
        SDL_DestroyTexture(missed_texture);
        std::string can_reach_str = "You can reach " + std::to_string(can_reach) + " star(s) if you don't miss.";
        SDL_Surface* can_reach_surface = TTF_RenderText_Solid(common_font, can_reach_str.c_str(), 0, white);
        SDL_Texture* can_reach_texture = SDL_CreateTextureFromSurface(renderer, can_reach_surface);
        SDL_FRect can_reach_rect = {0, 40, static_cast<float>(can_reach_surface->w),
            static_cast<float>(can_reach_surface->h)};
        SDL_RenderTexture(renderer, can_reach_texture, nullptr, &can_reach_rect);
        SDL_DestroySurface(can_reach_surface);
        SDL_DestroyTexture(can_reach_texture);
        if (score + missed != 0) {
            std::ostringstream oss;
            oss << std::fixed << std::setprecision(2) << static_cast<float>(score) / can_reach * 100;
            std::string percentage_str = "Percentage: " + oss.str() + "%";
            SDL_Surface* percentage_surface = TTF_RenderText_Solid(common_font, percentage_str.c_str(), 0, white);
            SDL_Texture* percentage_texture = SDL_CreateTextureFromSurface(renderer, percentage_surface);
            SDL_FRect percentage_rect = {0, 60, static_cast<float>(percentage_surface->w),
                static_cast<float>(percentage_surface->h)};
            SDL_RenderTexture(renderer, percentage_texture, nullptr, &percentage_rect);
            SDL_DestroySurface(percentage_surface);
            SDL_DestroyTexture(percentage_texture);
        }
        SDL_RenderPresent(renderer);
        Uint64 curr_time = SDL_GetTicksNS();
        Uint64 frame_time_ns = 1000000000 / FPS;
        if (curr_time - last_time < frame_time_ns) {
            SDL_DelayNS(frame_time_ns - (curr_time - last_time));
        }
        last_time = SDL_GetTicksNS();
    }
    SDL_DestroyTexture(bg_img);
    SDL_DestroyTexture(rocketship_img);
    SDL_DestroyTexture(star_img);
    TTF_CloseFont(common_font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
    return 0;
}
