#pragma once

// ============================================================
//  The Chip8 class — the "console" you are emulating.
//
//  You will fill this file in as you work through the lessons.
//  Each TODO tells you which lesson covers it.
// ============================================================

// The tutorial's two fundamental types (Lesson 01):
typedef unsigned char  BYTE;   // 8 bits  (0-255)
typedef unsigned short WORD;   // 16 bits (0-65535)

class Chip8
{
public:
    // TODO (Lesson 01): declare CPUReset() and a bool LoadRom(const char* path)

    // TODO (Lesson 02): declare WORD GetNextOpcode() and
    //                   void ExecuteNextOpcode()

    // TODO (Lesson 04): the display code in main.cpp will need to read the
    //                   screen array — make it public or add a getter.

    // TODO (Lesson 05): declare UpdateTimers(), KeyDown(int key), KeyUp(int key)

private:
    // TODO (Lesson 01): declare the hardware state here:
    //   - game memory       (0xFFF bytes)
    //   - 16 data registers (V0-VF)
    //   - address register I
    //   - program counter
    //   - the stack         (hint: std::vector<WORD>)
    //   - screen data       (64 x 32)

    // TODO (Lesson 03): declare one member function per opcode,
    //   e.g. void Opcode1NNN(WORD opcode);  — add them as you implement them.

    // TODO (Lesson 05): declare the delay timer, sound timer,
    //   and key state array (16 keys).
};
