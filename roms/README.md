# ROMs

Put `.ch8` ROM files in this folder. They are not committed to git.

## Where to get them (all free & legal)

CHIP-8 programs are tiny public-domain/homebrew files — unlike console ROMs,
these are freely distributable.

**Test ROMs (get these first — Lesson 06 uses them):**
- Timendus' CHIP-8 test suite: https://github.com/Timendus/chip8-test-suite
  (download `1-chip8-logo.ch8`, `3-corax+.ch8`, `4-flags.ch8`, `6-keypad.ch8`)
- IBM Logo: included in the suite above (`2-ibm-logo.ch8`) — the classic
  "first thing your emulator ever draws".

**Games:**
- https://github.com/kripod/chip8-roms (Pong, Tetris, Space Invaders, Brix…)
- https://johnearnest.github.io/chip8Archive/ (modern homebrew games)

## Download quickly from the terminal

```sh
cd roms
curl -LO https://github.com/Timendus/chip8-test-suite/raw/main/bin/1-chip8-logo.ch8
curl -LO https://github.com/Timendus/chip8-test-suite/raw/main/bin/2-ibm-logo.ch8
curl -LO https://github.com/Timendus/chip8-test-suite/raw/main/bin/3-corax+.ch8
curl -LO https://github.com/Timendus/chip8-test-suite/raw/main/bin/4-flags.ch8
curl -LO https://github.com/Timendus/chip8-test-suite/raw/main/bin/6-keypad.ch8
```
