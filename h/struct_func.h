#ifndef MY_STRUCT_H
#define MY_STRUCT_H

#include "./struct_func.h"
#include "./my_string.h"

short size_get(short fd, map_size *sz);
void init_maze(map_size *sz, m_map **mm);
void get_map(short fd, map_size *sz, m_map *arr);
short start_end(map_size *sz, m_map *mm);
void print(map_size *sz, m_map *arr);
void map_free(map_size *sz, m_map *mm);

#endif
