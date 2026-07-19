# CHIP-8 Reference Cheat Sheet

Keep this open in a split tab while coding. Sources: the
[codeslinger tutorial](http://www.codeslinger.co.uk/pages/projects/chip8.html),
[Wikipedia](https://en.wikipedia.org/wiki/CHIP-8) (the tutorial's preferred
reference), and Cowgod's technical reference.

## Memory map

```
0x000 - 0x1FF   Interpreter area (we put the fontset at 0x000)
0x200 - 0xFFF   Game ROM + work RAM   ← programs start at 0x200
```

## Opcode notation

`NNN` = 12-bit address · `NN` = 8-bit value · `N` = 4-bit value ·
`X`, `Y` = register indices. Extract with:

```cpp
int nnn =  opcode & 0x0FFF;
int nn  =  opcode & 0x00FF;
int n   =  opcode & 0x000F;
int x   = (opcode & 0x0F00) >> 8;
int y   = (opcode & 0x00F0) >> 4;
```

## All 35 opcodes

| Opcode | Does | Notes |
|---|---|---|
| `00E0` | Clear the screen | |
| `00EE` | Return from subroutine | pop stack → PC |
| `1NNN` | Jump to NNN | PC = NNN |
| `2NNN` | Call subroutine NNN | push PC, then PC = NNN |
| `3XNN` | Skip next if VX == NN | "skip" = PC += 2 |
| `4XNN` | Skip next if VX != NN | |
| `5XY0` | Skip next if VX == VY | |
| `6XNN` | VX = NN | |
| `7XNN` | VX += NN | ⚠ does NOT touch VF |
| `8XY0` | VX = VY | |
| `8XY1` | VX \|= VY | |
| `8XY2` | VX &= VY | |
| `8XY3` | VX ^= VY | |
| `8XY4` | VX += VY | VF = 1 on carry (>255) else 0 |
| `8XY5` | VX -= VY | VF = 0 on borrow (VY>VX) else 1 |
| `8XY6` | VX >>= 1 | VF = bit shifted out |
| `8XY7` | VX = VY − VX | VF = 0 on borrow (VX>VY) else 1 |
| `8XYE` | VX <<= 1 | VF = bit shifted out |
| `9XY0` | Skip next if VX != VY | |
| `ANNN` | I = NNN | |
| `BNNN` | Jump to NNN + V0 | |
| `CXNN` | VX = rand() & NN | |
| `DXYN` | Draw sprite at (VX,VY), 8 wide, N tall, from memory[I] | XOR draw; VF = 1 if any pixel turned off |
| `EX9E` | Skip next if key VX is pressed | |
| `EXA1` | Skip next if key VX is NOT pressed | |
| `FX07` | VX = delay timer | |
| `FX0A` | Wait for a keypress, store key in VX | blocks: PC −= 2 if no key |
| `FX15` | Delay timer = VX | |
| `FX18` | Sound timer = VX | |
| `FX1E` | I += VX | |
| `FX29` | I = address of font sprite for digit VX | fontset addr + VX × 5 |
| `FX33` | BCD of VX → memory[I], [I+1], [I+2] | hundreds / tens / units |
| `FX55` | Store V0..VX (inclusive!) at memory[I…] | classic: I += X + 1 after |
| `FX65` | Load V0..VX (inclusive!) from memory[I…] | classic: I += X + 1 after |

⚠ **VF-writing opcodes (8XY4/5/6/7/E):** compute using saved copies of the
operands, write the result, set VF **last** — X may be F itself.

## The fontset (load at 0x000 in CPUReset — Lesson 01)

Sixteen 5-byte sprites: each byte is one 8-pixel row (only the high 4 bits used).

```cpp
const BYTE kFontset[80] = {
    0xF0, 0x90, 0x90, 0x90, 0xF0,   // 0
    0x20, 0x60, 0x20, 0x20, 0x70,   // 1
    0xF0, 0x10, 0xF0, 0x80, 0xF0,   // 2
    0xF0, 0x10, 0xF0, 0x10, 0xF0,   // 3
    0x90, 0x90, 0xF0, 0x10, 0x10,   // 4
    0xF0, 0x80, 0xF0, 0x10, 0xF0,   // 5
    0xF0, 0x80, 0xF0, 0x90, 0xF0,   // 6
    0xF0, 0x10, 0x20, 0x40, 0x40,   // 7
    0xF0, 0x90, 0xF0, 0x90, 0xF0,   // 8
    0xF0, 0x90, 0xF0, 0x10, 0xF0,   // 9
    0xF0, 0x90, 0xF0, 0x90, 0x90,   // A
    0xE0, 0x90, 0xE0, 0x90, 0xE0,   // B
    0xF0, 0x80, 0x80, 0x80, 0xF0,   // C
    0xE0, 0x90, 0x90, 0x90, 0xE0,   // D
    0xF0, 0x80, 0xF0, 0x80, 0xF0,   // E
    0xF0, 0x80, 0xF0, 0x80, 0x80    // F
};
```

## Keypad mapping

```
CHIP-8 pad          QWERTY
1 2 3 C             1 2 3 4
4 5 6 D      →      Q W E R
7 8 9 E             A S D F
A 0 B F             Z X C V
```

## The main loop (the whole emulator on one napkin)

```
reset CPU, load fontset, load ROM at 0x200
60 times per second:
    poll input → key state array
    repeat (opcodesPerSecond / 60) times:
        opcode = fetch 2 bytes at PC, PC += 2
        decode via switch, execute
    if delay timer > 0: delay timer--
    if sound timer > 0: sound timer--, beep while > 0
    draw 64×32 screen array, scaled up
```
