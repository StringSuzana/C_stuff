#include <stdio.h>
#include <stdlib.h>

int main() {
    char name2[20] = {'Z', 'u', 'z', 'i'};
    const char* name = "Suzi";
    int a = 60;
    int* bla = &a;
    ;

    printf("%s, %d", name2, sizeof(name));
    return 0;
}
