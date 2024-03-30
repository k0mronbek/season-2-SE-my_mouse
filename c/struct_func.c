#include "../h/struct_func.h"

short size_get(short fd, map_size *sz) {
    sz->height = 0;
    sz->width = 0;
    sz->steps=0;
    char *num = (char *)calloc(4, sizeof(char));
    char c;
    short m = 0, flag = 0;
    while (read(fd, &c, 1) > 0) {
        if (flag == 0) {
            if (my_isdigit(c)) {
                write(2, "MAP ERROR\n", 10);
                return 1;
            }
            num[m] = c;
        }
        if (c == 'x') {
            num[m] = '\0';
            sz->height = my_atoi(num);
            fill_null(num, m);
            m = 0;
            continue;
        } else if (c == '*') {
            num[m] = '\0';
            sz->width = my_atoi(num);
            flag = 1;
            continue;
        } else if (c == '\n') break;
        m++;
    }
    free(num);
    return 0;
}

void init_maze(map_size *sz, m_map **mm) {
    *mm = (m_map *)malloc(sizeof(m_map));
    (*mm)->mmap = (char**)calloc(sz->height, sizeof(char*));
    (*mm)->imap = (int**)calloc(sz->height, sizeof(int*));
    (*mm)->start = 0;
    (*mm)->end = 0;
    for (short i = 0; i < sz->height; i++) {
        (*mm)->imap[i] = (int*)calloc(sz->width, sizeof(int));
        (*mm)->mmap[i] = (char*)calloc(sz->width + 1, sizeof(char));
    }
}

void get_map(short fd, map_size *sz, m_map *arr) {
    char c;
    for (short i = 0; i < sz->height; i++) {
        read(fd, arr->mmap[i], sz->width);
        read(fd, &c, 1);
    }
    close(fd);
}


short start_end(map_size *sz, m_map *mm) {
    short s_flag = 0, e_flag = 0;
    for (short j = 0; j < sz->width; j++) {
        if (mm->mmap[0][j] == '1') {
            s_flag = 1;
            mm->start = j;
        }
        if (mm->mmap[sz->height - 1][j] == '2') {
            e_flag = 1;
            mm->end = j;
        }
    }
    if (s_flag && e_flag)
        return 0;
    return 1;
}

void print(map_size *sz, m_map *arr) {
    printf("%dx%d* o12\n", sz->height, sz->width);
    for (short i = 0; i < sz->height; i++) printf("%s\n", arr->mmap[i]);
    printf("%d STEPS\n", sz->steps-2);
}


void map_free(map_size *sz, m_map *mm) {
    for (short i = 0; i < sz->height; i++) {
        free(mm->mmap[i]);
        free(mm->imap[i]);
    }
    free(mm->mmap);
    free(mm->imap);
    free(mm);
    free(sz);
}

