#pragma once
#include <vector>

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
    void CPUReset();
    bool LoadRom(const char* path);

   WORD GetNextOpcode();
   void ExecuteNextOpcode();

    // TODO (Lesson 04): the display code in main.cpp will need to read the
    //                   screen array — make it public or add a getter.

    // TODO (Lesson 05): declare UpdateTimers(), KeyDown(int key), KeyUp(int key)

private:
    // TODO (Lesson 01): declare the hardware state here:
    //   - game memory       (0xFFF bytes)
    BYTE m_GameMemory[0xFFF];
    //   - 16 data registers (V0-VF)
    BYTE m_Registers[16];
    //   - address register I
    WORD m_AddressI;
    //   - program counter
    WORD m_ProgramCounter;
    //   - the stack         (hint: std::vector<WORD>)
    std::vector<WORD> m_Stack;
    //   - screen data       (64 x 32)
    BYTE m_ScreenData[64][32];

    void Opcode1NNN(WORD opcode);
    // TODO (Lesson 03): declare one member function per opcode,
    //   e.g. void Opcode1NNN(WORD opcode);  — add them as you implement them.

    // TODO (Lesson 05): declare the delay timer, sound timer,
    //   and key state array (16 keys).
};
