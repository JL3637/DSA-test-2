#include<stdio.h>

int main(){
    printf("10000 10000 2 3\n");
    for(int i = 1; i < 10000; i++){
        printf("%d %d\n", 1, i+1);
    }
    for(int i = 1; i <= 10000; i++){
        printf("%d\n", i);
    }
    return 0;
}