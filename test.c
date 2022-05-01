#include<stdio.h>


void quicksort(int *data, int left, int right){
    if(left >= right){
        return;
    }
    int i = left;
    int j = right;
    int key = data[left];

    while(i != j){                  
        while(data[j] > key && i < j){
            j -= 1;
        }
        while(data[i] <= key && i < j){
            i += 1;
        }
        if(i < j){
            int temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
    }

    data[left] = data[i];
    data[i] = key;

    quicksort(data, left, i-1);
    quicksort(data, i+1, right);
}


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