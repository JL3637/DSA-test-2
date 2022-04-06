#include<stdio.h>

int main(){
    int *a;
    int b;
    a = &b;
    b = 2;
    //*a = *b;

    printf("%d %d", *a, b);

    return 0;
}