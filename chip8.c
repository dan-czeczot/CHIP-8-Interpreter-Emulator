#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "chip8.h"

uint8_t ram[4096]; //4K memory locations, 1 byte size each, 0x000 - 0x1FF reserved for interpreter (and should contain font sprite data)
uint8_t V[16]; //16, 1 byte "V" registers (VF is a flag for some instructions)
uint16_t I; //2 byte index (address) register
uint8_t dt; //delay timer, dec. at 60 Hz
uint8_t st; //sound timer, dec. at 60 Hz, if >0, play tone
uint16_t pc; //12 bit program counter 0x000 - 0xFFF
uint16_t opcode; //current opcode being pointed at by the program counter
uint16_t stack[16]; //stack that stores return addresses for subroutines
uint8_t sp; //stack pointer
uint8_t keypad[16]; //16-key hex keypad for input
uint8_t gfx[2048]; //64 x 32 pixel display

void chip8_init(FILE* file)
{
    //Clear ram
    for (int i = 0; i < 4096; i++)
    {
        ram[i] = 0;
    }

    //
    //Load font data in addresses 0x000 - 0x1FF
    //

    //Fill the rest of ram starting at 0x200 with the contents of the binary file
    fread(ram + 0x200, 1, 4096 - 0x200, file);

    //Clear registers, stack, and keypad
    for (int i = 0; i < 16; i++)
    {
        V[i] = 0;
        stack[i] = 0;
        keypad[i] = 0;
    }

    //Clear index register
    I = 0;

    //Clear timers
    dt = 0;
    st = 0;

    //Set program counter to start reading at address 0x200 (start of program in ram)
    pc = 0x200;

    //Clear opcode variable
    opcode = 0;

    //Clear stack pointer
    sp = 0;

    //Clear display
    for (int i = 0; i < 2048; i++)
    {
        gfx[i] = 0;
    }

    /*//Print Test first 1000 bytes
    for (int i = 0; i < 1000; i++)
    {
        printf("%u : %i \n", ram[i], i);
    }
    */
}

void chip8_fetch()
{
    //Opcodes are 2 bytes long; the current byte on the pc and the one directly ahead
    opcode = (ram[pc] << 8) | ram[pc + 1];
}

void chip8_decode()
{
    switch (opcode >> 12)
    {
    case 0x0:
        if (opcode & 0x0FFF == 0x0E0)
        {
            //00E0 - CLS
        }
        else if (opcode & 0x0FFF == 0x0EE)
        {
            //00EE - RET
        }
        else
        {
            //0nnn - SYS (essentially nop?)
        }
        break;

    case 0x1:
        //1nnn - JP
        break;

    case 0x2:
        //2nnn - CALL
        break;

    case 0x3:
        //3xkk - SE
        break;

    case 0x4:
        //4xkk - SNE
        break;

    case 0x5:
        //5xy0 - SE
        break;
        case 0x6:
        case 0x7:
        case 0x8:
        case 0x9:
        case 0xA:
        case 0xB:
        case 0xC:
        case 0xD:
        case 0xE:
        case 0xF:
    }
}

void chip8_execute()
{

}