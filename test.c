#include<stdio.h>

int main(){
    printf("1000000 1000000 1 2\n");
    for(int i = 1; i < 1000000; i++){
        printf("%d %d\n", i, i+1);
    }
    for(int i = 1; i <= 1000000; i++){
        printf("%d\n", i);
    }
    return 0;
}