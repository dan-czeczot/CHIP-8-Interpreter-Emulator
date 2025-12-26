#include <stdint.h>

#include "chip8.h"

uint8_t ram[4096]; //4K memory locations, 1 byte size each, 0x000 - 0x1FF reserved for interpreter (and should contain font sprite data)
uint8_t V[16]; //16, 1 byte "V" registers (VF is a flag for some instructions)
uint8_t dt; //delay timer, dec. at 60 Hz
uint8_t st; //sound timer, dec. at 60 Hz, if >0, play tone
uint16_t pc; //12 bit program counter 0x000 - 0xFFF
uint16_t stack[16]; //stack that stores return addresses for subroutines
uint8_t sp; //stack pointer
uint8_t keypad[16]; //16-key hex keypad for input
uint8_t gfx[2048]; //64 x 32 pixel display

void chip8_init()
{

}

void chip8_fetch()
{

}

void chip8_decode()
{

}

void chip8_execute()
{

}