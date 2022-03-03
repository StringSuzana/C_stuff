#include <stdio.h>
typedef int (*math_ptr)(int, int); 
void do_stuff(int num) { printf("Doing stuff with: %d...\n ", num); }
void do_other_stuff(int num) {
    printf("Doing some other stuff with: %d...\n ", num);
}

int add(int a, int b) {
    printf("%d + %d = %d\n", a, b, (a + b));
    return a + b;
}
int multiply(int a, int b) {
    printf("%d * %d = %d\n", a, b, (a * b));
    return a * b;
}
void delegate_argument(math_ptr);

int main() {
    math_ptr bla;
    bla = &add;
    bla(10,6);
     // Deklaracija
    // int (*math_ptr)(int, int) = &add; //Inicijalizacija
    math_ptr ptrs[] = {add, multiply};

    for (int i = 0; i < 2; i++) {
        //int bla = ptrs[i](2, 3);
        //printf("%d\n", bla);
        delegate_argument(ptrs[i]);
    }
    
    // math_ptr(1, 2);

    return 0;
}
void delegate_argument(math_ptr p){

    printf("Here goes...\n");
    p(5,6);
    printf("Tadaa\n");
}
