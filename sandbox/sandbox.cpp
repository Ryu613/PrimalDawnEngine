#include "SDL.h"
#include "SDL_vulkan.h"
#include <iostream>
#include <vector>

#include "engine/engine.hpp"

int main(int argc, char** argv) {
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window* window = SDL_CreateWindow("sandbox",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        1024, 720,
        SDL_WINDOW_SHOWN | SDL_WINDOW_VULKAN);
    if (!window) {
        SDL_Log(SDL_GetError());
        exit(2);
    }
    bool shouldClose = false;
    SDL_Event event;

    // 取vulkan实例的扩展, 第一次取数量，第二次才是真正取扩展
    unsigned int count;
    SDL_Vulkan_GetInstanceExtensions(window, &count, nullptr);
    std::vector<const char*> extensions(count);
    SDL_Vulkan_GetInstanceExtensions(window, &count, extensions.data());

    //for (auto& extension : extensions) {
    //    std::cout << extension << std::endl;
    //}

    engine::Init(extensions,
        [&](vk::Instance instance) {
            VkSurfaceKHR surface;
            if (!SDL_Vulkan_CreateSurface(window, instance, &surface)) {
                throw std::runtime_error("can't create surface");
            }
            return surface;
        }, 1024, 720);

    auto& renderer = engine::GetRenderer();

    while (!shouldClose) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                shouldClose = true;
            }
        }
        renderer.render();
    }

    engine::Quit();

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}