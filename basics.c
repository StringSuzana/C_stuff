#include <stdio.h>
#include <stdlib.h>
void char_array_vs_pointer();
void reference_vs_value();
void scopes();
void structs();
void ptr_manipulation();
int pass_a_by_reference(int* a_var);
int pass_a_by_value(int a_var);

typedef struct Node {
    int val;
    struct Node* prev;
    struct Node* next;
} node;

void insert_after(node* node_to_insert, node* parent);
void insert_before(node* node_to_insert, node* child);
void iterate_to_end(node* start);
void iterate_from_end(node* start);

int main() {
    char_array_vs_pointer();

    printf("Size of int %d bytes\n", sizeof(int));
    int* num;
    num = (int*)calloc(1,sizeof(int));
    *num = 3;
    printf("Value of num variable %d\n", *num);
    free(num);
    printf("Value of num variable %d", *num);
    node root = {val : 0, prev : NULL, next : NULL};
    node first = {val : 1, prev : NULL, next : NULL};
    node second = {val : 2, prev : NULL, next : NULL};
    node third = {val : 3, prev : NULL, next : NULL};
    node fourth = {val : 4, prev : NULL, next : NULL};

    insert_after(&first, &root);
    iterate_to_end(&root);

    insert_after(&second, &first);
    iterate_to_end(&root);

    insert_after(&fourth, &first);
    iterate_to_end(&root);

    iterate_from_end(&second);
    return 0;
}
void insert_after(node* node_to_insert, node* this) {
    if (this->next != NULL) {
        this->next->prev = node_to_insert;
    }
    node_to_insert->next =this->next;
    this->next = node_to_insert;
    node_to_insert->prev = this;
}
void iterate_to_end(node* start) {
    node* test = start;
    while (test != NULL) {
        printf("\nval: %d", test->val);
        test = test->next;
    }
    printf("\n------------------");
}
void iterate_from_end(node* start){
    node* test = start;
    while (test != NULL) {
        printf("\nval: %d", test->val);
        test = test->prev;
    }
    printf("\n------------------");
}
/*
void persons() {
    typedef struct Person {
        char* name;
        int age;
        struct Person* parent;
        struct Person* child;
    } person;
    void add_child_to_family(person * new_person, person * parent);
    person granny = {name : "Lucy", age : 100, parent : NULL, child : NULL};
    person mom = {name : "Mom", age : 50, parent : &granny, child : NULL};
    person luke = {name : "Luke", age : 15, parent : NULL, child : NULL};

    add_child_to_family(&mom, &granny);
    add_child_to_family(&luke, &mom);

        void add_child_to_family(person * new_person, person * parent) {
            parent->child = new_person;
            new_person->parent = parent;
        }
}
*/
void zadatak_etk() {
    int prvi = 5;
    int drugi = prvi++;
    printf("%d", drugi);

    int a = 10;
    int* p = &a;

    printf("\nadresa od a: %p\n", &a);
    printf("adresa od p: %p\n\n", &p);

    printf("*p = %d\n p = %p\n&p = %p", *p, p, &p);
}
void consts() {
    int num = 1;
    int* p_num = &num;
    int bla = 2;
    int* const cp_num = &num;  // ERROR: cp_num = &bla; =>assignment of
                               // read-only variable 'cp_num'
    const int* cp_bla = &bla;  // ERROR: *cp_bla = num; =>assignment of
                               // read-only location '*cp_bla'

    printf("num: %d p_num:  %p \n", num, p_num);
    printf("num: %d cp_num: %p \n", num, cp_num);
    printf("num: %d cp_num: %p \n", num, cp_num);
}
void structs() {
    // This is making instances=>
    struct Person {
        char* name;
        char last_name[20];
    } person_t, *p_person_t, p[10];
    person_t.name = "bla";
    // This is defining types=>
    typedef struct Student {
        char* name;
        char last_name[20];
    } student_t, *p_student_t, s[10];

    student_t suzi = {name : "Suzi", last_name : "Mazi"};
    student_t bla = {name : "bla", last_name : "bla"};
    student_t stud = {name : "bla", last_name : "bla"};
    p_student_t p_stud = &bla;
    // s stud_arr[0] = stud;

    printf("%s \n", suzi.name);
    printf("%p\n", p_stud);
    printf("%p\n", &stud);
}
void dyn_array() {
    // create dynamically array of ints, char *, and int ptr
    // array of int
    int ARR_SIZE = 10;
    int* arr = (int*)malloc(sizeof(int) * ARR_SIZE);
    arr[5] = 10;
    printf("%d", arr[5]);
}
void ptr_manipulation() {
    int arr[] = {10, 20};
    int* p = arr;
    (*p) = 8876;
    printf("arr= %p , arr[0] = %d, arr[1] = %d, \np = %p p_val= %d", arr,
           arr[0], arr[1], p, p[0]);
}
void malloc_and_free() {
    printf("Size of int %d bytes\n", sizeof(int));
    int* num;
    num = (int*)malloc(sizeof(int));
    *num = 3;
    printf("Value of num variable %d\n", *num);
    free(num);
    printf("Value of num variable %d", *num);
}
void printing_pointers() {
    int first = 66;
    int second = 2;
    int* p_first = &first;
    int* p_second = NULL;

    printf("\nDigit first: %d \nPointer: %p \n", first, &first);
    printf("\nDigit p_first: %d \nPointer: %p  \n", *p_second, p_second);

    *p_first = 200;
    printf("\n--------------");
    printf("\nDigit first: %d \nPointer: %p \n", first, &first);
    printf("\nDigit p_first: %d \nPointer: %p  \n", *p_first, p_first);
}
void char_array_vs_pointer() {
    char arr1[] = "Bla";
    char* arr2 = "Pointer";
    printf("%p , %p \n", arr1, arr2);
    printf("%p , %p \n", &arr1, &arr2);
    //0x7ffc9a2b4c4c , 0x40217b
    //0x7ffc9a2b4c4c , 0x7ffc9a2b4c40 
}
void scopes() {
    // auto => variable within function
    int mount;
    auto int month;

    // register => local variable that is stored in register instead of RAM
    // the variable has a maximum size equal to the register size (usually one
    // word)
    //    &miles is forbidden
    register int miles;

    // static => OUTSIDE of function: variable scope is restricted to the
    // current file!!! static => INSIDE of function: variable is alive during
    // the program execution, not just in function scope
    static int g_count =
        5; /* global variable if declared OUTSIDE of functions */
    static int l_count = 5; /* local variable if declared INSIDE of function */
    // extern => used to reference the global variable OR function from another
    // file
    extern int GLOBAL_VAR_IN_ANOTHER_FILE;
}
void reference_vs_value() {
    int a = 4;
    printf("a: %d", a);
    printf("\na_var: %d\n\n", pass_a_by_reference(&a));
    printf("a: %d", a);
    printf("\na_var: %d\n", pass_a_by_value(a));
    printf("a: %d \n", a);
    pass_a_by_value(a);
}

int pass_a_by_reference(int* a_var) {
    *a_var = 10;
    return *a_var;
}
int pass_a_by_value(int a_var) {
    a_var = 20;
    return a_var;
}
