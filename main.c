#include <stdio.h>
#include <stdlib.h>

#include "chip8.h"


int main(int argc, char* argv[])
{
    char* filename;
    if (argc > 0)
    {
        filename = argv[1];
    }
    else
    {
        perror("Error: A Chip-8 file was not supplied!");
        return 1;
    }
    FILE* file;
    file = fopen(filename, "rb");
    if (file == NULL)
    {
        perror("Error: Could not open file!");
        return 1;
    }
    

    return 0;
} 