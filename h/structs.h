#ifndef STRUCTS_H
#define STRUCTS_H

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <malloc.h>
#include <limits.h>
#include <stdbool.h>

typedef struct {
    int i;
    int j;
} answer;

typedef struct {
    short height;
    short width;
    short steps;
} map_size;


typedef struct {
    short start;
    short end;
    int **imap;
    char **mmap;
} m_map;

#endif