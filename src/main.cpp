#include <SDL.h>
#include <cstdio>
#include "chip8.h"

// ============================================================
//  Entry point. Right now this only proves your toolchain and
//  SDL2 are working (Lesson 00). You will grow it into a real
//  emulator front-end in Lessons 04 and 05:
//
//  Lesson 04: open a window, draw the 64x32 screen scaled up
//  Lesson 05: 60 FPS loop, run N opcodes per frame, keyboard
// ============================================================

int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::printf("SDL_Init failed: %s\n", SDL_GetError());
        return 1;
    }

    std::printf("Toolchain OK — SDL2 initialised.\n");

    // TEMPORARY (Lesson 01 checkpoint) — construct a Chip8 on the stack,
    // reset it, and load a ROM to prove the memory map is correct.
    // This block gets replaced by the real fetch/decode loop in Lesson 02.
    Chip8 chip8;
    chip8.CPUReset();
    chip8.LoadRom("roms/2-ibm-logo.ch8");
    chip8.ExecuteNextOpcode();
    chip8.ExecuteNextOpcode();
    chip8.ExecuteNextOpcode();
    chip8.ExecuteNextOpcode();
    chip8.ExecuteNextOpcode();
    chip8.ExecuteNextOpcode();

    // TODO (Lesson 04): create the window + renderer here

    // TODO (Lesson 04/05): the main loop:
    //   while (running) {
    //     handle SDL events (quit, key down/up)
    //     run opcodesPerFrame CPU steps
    //     update timers
    //     draw the screen
    //     wait until 1/60th of a second has passed
    //   }

    SDL_Quit();
    return 0;
}
