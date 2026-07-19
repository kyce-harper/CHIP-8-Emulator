# CHIP-8 Emulator: Learning Project

Build your own CHIP-8 emulator in C++ by following along with the
[codeslinger CHIP-8 tutorial](http://www.codeslinger.co.uk/pages/projects/chip8.html).

This repo is a pre-built environment plus a lesson plan. The source files are
mostly empty skeletons full of `TODO` markers, and you write the emulator code
yourself, one lesson at a time. Each lesson tells you what to read, what to write,
and how to check that it works.

## How to use this repo

1. Open this folder in VSCode.
2. Start at [lessons/00-setup.md](lessons/00-setup.md) and work through the lessons in order.
3. Each lesson maps to a page of the codeslinger tutorial (with fixes and
   macOS/SDL2 adaptations noted, since the tutorial was written in 2008 for Windows).

## Lesson plan

| Lesson | Topic | Tutorial page |
|---|---|---|
| [00](lessons/00-setup.md) | Environment setup & first build | Getting Started |
| [01](lessons/01-hardware.md) | The hardware: memory, registers, reset | Step 1: The Hardware |
| [02](lessons/02-fetch-decode.md) | The fetch–decode loop | Step 2: Fetch decode loop |
| [03](lessons/03-opcodes.md) | Implementing all 35 opcodes | Step 3: Example opcodes |
| [04](lessons/04-display.md) | Drawing the screen with SDL2 | (macOS adaptation) |
| [05](lessons/05-timers-sound-input.md) | Timers, sound & keyboard input | Step 4: Timers, Sound, Input |
| [06](lessons/06-testing.md) | Test ROMs & debugging your emulator | — |
| [07](lessons/07-extras.md) | Niceties: beep sound, GUI, save states, quirks | — |

## Project layout

```
├── src/
│   ├── main.cpp      — program entry: SDL window + main loop (you build this up)
│   ├── chip8.h       — the Chip8 class declaration (you fill it in)
│   └── chip8.cpp     — the Chip8 implementation (you fill it in)
├── roms/             — put game/test ROMs here (see roms/README.md)
├── lessons/          — the step-by-step lessons
├── docs/
│   └── reference.md  — opcode cheat sheet + memory map (keep this open while coding)
├── .vscode/          — build (Cmd+Shift+B) and debug (F5) already configured
└── CMakeLists.txt    — build config (SDL2 already wired up)
```

## Quick commands

- **Build:** `Cmd+Shift+B` in VSCode (or `cmake -S . -B build && cmake --build build`)
- **Run:** `./build/chip8 roms/<some-rom>.ch8`
- **Debug:** `F5` in VSCode
