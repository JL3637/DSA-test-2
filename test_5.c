#include<stdio.h>
#include<stdlib.h>
#include "price.h"

int main(){
    int a, q, n;
    scanf("%d%d%d", &a, &q, &n);
    int *favorite_stocks = malloc(sizeof(int)*a);
    for(int i = 0; i < a; i++){
        scanf("%d", &favorite_stocks[i]);
    }



    for(int i = 0; i < q; i++){
        int s, k;
        scanf("%d%d", &s, &k);
    }

    return 0;
}