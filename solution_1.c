#include <stdio.h>

int calculate_length(char *s, int *length) {
    (*length)++;
    return *s && calculate_length(s+1, length);
}

int main(int argc, char *argv[]) {
    char *s = argv[1];
    int length = -1;
    calculate_length(s, &length);
    printf("length of %s is %d\n", s, length);
    return 0;
}
