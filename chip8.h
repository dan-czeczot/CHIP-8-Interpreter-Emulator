#ifndef CHIP8_H
#define CHIP8_H

#include <stdint.h>

void chip8_init(); //loads the program into memory
void chip8_fetch(); //fetches the next opcode (2 bytes) from memory
void chip8_decode(); //decodes the opcode to determine meaning
void chip8_execute(); //executes the opcode according to the proper instruction

#endif //CHIP8_H