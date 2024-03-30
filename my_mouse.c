#include "./h/struct_func.h"

void convert_maze(map_size *sz, m_map **mm) {
    for (short i = 0; i < sz->height; i++)
        for (short j = 0; j < sz->width; j++) {
            (*mm)->imap[0][(*mm)->start] = 1;
            (*mm)->imap[sz->height-1][(*mm)->end] = -2;
            if((*mm)->mmap[i][j] == ' ')  (*mm)->imap[i][j] = 0;    
            else if((*mm)->mmap[i][j] == '*') (*mm)->imap[i][j] = -3;
        }
} 


void check_step(m_map**mm, short i, short j, short step) {   
    int**map = (*mm)->imap;
    if(!map[i+1][j] || map[i+1][j] == -2) map[i+1][j] = step+1;
    if(!map[i-1][j]) map[i-1][j] = step+1;
    if(!map[i][j-1]) map[i][j-1] = step+1;
    if(!map[i][j+1]) map[i][j+1] = step+1;
}

void check_path(m_map**mm, int*i, int*j, short step) {
    int**map = (*mm)->imap;
    if(map[(*i)+1][(*j)] == (step-1)) *i = (*i)+1; 
    if(map[*i-1][*j]== (step-1)) *i = *i-1;
    if(map[*i][*j-1]== (step-1)) *j = *j-1;
    if(map[*i][*j+1]== (step-1))  *j = *j + 1;
}

void drawing_maze(map_size* sz, m_map**mm, int step) {
    answer*end = (answer*)malloc(sizeof(answer));
    end->i = sz->height-2;
    end->j = (*mm)->end;
    while(step>1) {
        (*mm)->mmap[end->i][end->j] = 'o';
        check_path(mm, &(end->i), &(end->j), step); 
        step--;
    }
    free(end);
}


void short_path(map_size*sz, m_map*mm) {
    mm->imap[1][mm->start] = 2;
    short step = 2, i, j;
    while(mm->imap[sz->height-1][mm->end]==-2) {
        for(i=1; i<sz->height; i++) {
            for(j=1; j<sz->width; j++) {
                if(mm->imap[i][j]==step) check_step(&mm, i, j, step);
            }
        }  
        step++;  
    }
    sz->steps = step;
    drawing_maze(sz, &mm, step);
}

int main(int ac, char **av) {
    if (ac > 1) {
        if (check(av[1])) {
            short fd = open(av[1], O_RDONLY);
            map_size *sz = (map_size *)malloc(sizeof(map_size));
            if (size_get(fd, sz)) {
                free(sz);
                return 1;
            }
            m_map *arr = NULL;
            init_maze(sz, &arr);
            get_map(fd, sz, arr);
            if (start_end(sz, arr)) {
                write(2, "MAP ERROR", 9);
                map_free(sz, arr);
                return 1;
            }
            convert_maze(sz, &arr);
            short_path(sz, arr);
            print(sz, arr);
            map_free(sz, arr);
        }
    }
    return 0;
}