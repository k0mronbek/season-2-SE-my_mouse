#include "../h/my_string.h"

void fill_null(char *str, short over) {
    for (short i = 0; i < over; i++) str[i] = '\0';
}

short my_strcmp(char *str1, char *str2) {
    for (short i = 0; str1[i] != '\0' && str2[i] != '\0'; i++)
        if (str1[i] != str2[i]) return str1[i] - str2[i];
    return 0;
}


short my_atoi(char *str) {
    short m, value = 0;

    for (short i = 0; i < str[i]; i++)
    {
        if (str[i] != '-')
        {
            m = str[i] - '0';
            value = 10 * value + m;
        }
    }
    if (str[0] == '-')
        value *= -1;

    return value;
}

short check(char* str) {
    for (short i = 0; str[i]; i++) {
        while (str[i] != '.') i++;
        if (my_strcmp(&str[i + 1], "map")) return 1;
    }
    return 0;
}

short my_isdigit(char c) {
    if (c < '0' && c > '9') return 1;
    return 0;
}
