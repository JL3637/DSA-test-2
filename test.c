#include<stdio.h>

int main(){
    printf("1000000 100 1 100\n");
    for(int i = 1; i < 1000000; i++){
        printf("%d %d\n", i, i+1);
    }
    /*for(int i = 0; i < 100; i++){
        printf("%d\n", i+1);
    }*/

    return 0;
}