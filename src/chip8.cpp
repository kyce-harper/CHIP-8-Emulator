#include "chip8.h"
#include <cstdio>   // FILE, fopen, fread, fclose, printf — old-school C I/O
#include <cstring>  // memset

// ============================================================
//  Chip8 implementation — written by YOU, lesson by lesson.
//
//  Lesson 01: CPUReset(), LoadRom()
//  Lesson 02: GetNextOpcode(), ExecuteNextOpcode() switch
//  Lesson 03: the 35 opcode functions
//  Lesson 05: UpdateTimers(), KeyDown(), KeyUp()
// ============================================================

// The 16 built-in font sprites (0-F), 5 bytes each = 80 bytes total.
// Lives outside the class as a plain const array — CPUReset() below
// copies it into game memory starting at address 0x0.
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

// "Chip8::" is the scope resolution operator — it tells the compiler
// this CPUReset is the definition of the CPUReset *declared inside the
// Chip8 class* in chip8.h, not a free-standing function. `void` means
// it returns nothing.
void Chip8::CPUReset()
{
    // memset(pointer, value, num_bytes) fills a block of memory with a
    // byte value. `m_GameMemory` decays to a pointer to its first
    // element here, and sizeof() gives the array's size in bytes since
    // it's a real array (not a pointer we've lost the size of).
    memset(m_GameMemory, 0, sizeof(m_GameMemory));
    memset(m_Registers, 0, sizeof(m_Registers));
    memset(m_ScreenData, 0, sizeof(m_ScreenData));

    // std::vector has a member function clear() that empties it —
    // no manual size-tracking needed like the raw arrays above.
    m_Stack.clear();

    m_AddressI = 0;
    m_ProgramCounter = 0x200;   // CHIP-8 programs always start here

    // Copy the fontset into memory at address 0x0 so opcode FX29 can
    // look sprites up later. Plain array indexing — i is scoped to the
    // for-loop only.
    for (int i = 0; i < 80; i++)
    {
        m_GameMemory[i] = kFontset[i];
    }
}

// `const char*` = a pointer to a read-only C-style string. `const`
// here is a promise to the caller (and the compiler) that LoadRom
// will not modify the characters `path` points to.
bool Chip8::LoadRom(const char* path)
{
    FILE* rom = fopen(path, "rb");   // "rb" = read, binary mode
    if (rom == nullptr)
    {
        printf("Failed to open ROM: %s\n", path);
        return false;
    }

    // fread(destination, size_of_each_element, count, stream)
    // &m_GameMemory[0x200] takes the *address* of that array element —
    // i.e. "start writing bytes here". Games load right after the
    // fontset region, at 0x200, same as the original hardware.
    size_t bytesRead = fread(&m_GameMemory[0x200], 1, sizeof(m_GameMemory) - 0x200, rom);
    fclose(rom);

    printf("Loaded %zu bytes from %s\n", bytesRead, path);

    // TEMPORARY (Lesson 01 checkpoint) — prove the memory map is right by
    // printing the first opcode's two bytes. Remove this once Lesson 02
    // gives you a real GetNextOpcode() to call instead.
    printf("First opcode bytes: %02X %02X\n", m_GameMemory[0x200], m_GameMemory[0x201]);

    return true;
}
WORD Chip8::GetNextOpcode(){
    WORD res = m_GameMemory[m_ProgramCounter];
    //Shift every bit left 8 places
    res <<= 8;
    //bitwise OR
    res |= m_GameMemory[m_ProgramCounter + 1];
    //Move past 2 -byte opcode
    m_ProgramCounter += 2;

    return res;
}
void Chip8::ExecuteNextOpcode() {
    WORD opcode = GetNextOpcode();

    switch (opcode & 0xF000){
        case 0x1000:
            Opcode1NNN(opcode);
            break;
        default:
            printf("Unhandled opcode: %04X\n", opcode);
            break;
    }
}
void Chip8::Opcode1NNN(WORD opcode){
    // jump to address NNN
    // keeps low 12 bits, throws away identifier bit
    m_ProgramCounter = opcode & 0x0FFF;
}