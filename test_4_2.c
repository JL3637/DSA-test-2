#include<stdio.h>
#include<stdlib.h>

void push(int *stack, int data, int *stack_top){
    *stack_top += 1;
    stack[*stack_top] = data; 
}

int pop(int *stack, int *stack_top){
    int data = stack[*stack_top];
    stack[*stack_top] = -1;
    *stack_top -= 1;
    return data;
}

int city_check(int *arr, int arr_top, int c){
    for(int i = 0; i <= arr_top; i++){
        if(arr[i] == c){
            return 1;
        }
    }
    return 0;
}

void find_s_to_r(int **arr, int *arr_top, int *hint, int *hint_top, int *a_top, int *ans, int s, int r){
    int cnt = 0;
    int x = s;
    int prev = -1;
    push(hint, x, hint_top);
    cnt++;
    while(!city_check(arr[x], arr_top[x], r)){
        if(a_top[x] > arr_top[x]){
            for(int i = 0; i < cnt; i++){
                pop(hint, hint_top);
            }
            cnt = 0;
            prev = x;
            x = arr[x][a_top[x]];
            a_top[x]++;
            if(a_top[x] > arr_top[x]){
                a_top[x] = 0;
            }
        }
        else if(arr[x][a_top[x]] == prev){
            a_top[x]++;
            if(a_top[x] > arr_top[x]){
                a_top[x] = 0;
            }
        }
        prev = x;
        x = arr[x][a_top[x]];
        push(hint, x, hint_top);
        cnt++;
    }
    push(hint, r, hint_top);
}

void find_ans(int n, int **arr, int *arr_top, int *ans, int *hint, int *hint_top, int *cnt, int *next, int *hint_start){
    for(int i = 0; i <= *hint_top; i++){
        
    }
}

int main(){
    int n, q, s, r;
    scanf("%d%d%d%d", &n, &q, &s, &r);

    int **arr = malloc(sizeof(int*)*n);
    for(int i = 0; i < n; i++){
        arr[i] = malloc(sizeof(int)*1);
    }
    int *arr_top = malloc(sizeof(int)*n);
    int *hint = malloc(sizeof(int)*n);
    int hint_top = -1;
    int *ans = malloc(sizeof(int)*n);
    for(int i = 0; i < n; i++){
        arr_top[i] = -1;
        arr[i][0] = -1;
        hint[i] = -1;
        ans[i] = -1;
    }

    for(int i = 0; i < n-1; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        arr[a-1] = (int*)realloc(arr[a-1], sizeof(int)*(arr_top[a-1] + 2));
        arr[b-1] = (int*)realloc(arr[b-1], sizeof(int)*(arr_top[b-1] + 2));
        push(arr[a-1], b-1, &arr_top[a-1]);
        push(arr[b-1], a-1, &arr_top[b-1]);
    }

    find_s_to_r(arr, arr_top, hint, &hint_top, a_top, ans, s-1, r-1);
    int cnt = 0;
    for(int i = 0; i <= hint_top; i++){
        ans[hint[i]] = hint[i] + 1;
        cnt++;
    }
    /*int next = 0;
    int hint_start = 0;
    find_ans(n, arr, arr_top, ans, hint, &hint_top, &cnt, &next, &hint_start);*/


    for(int i = 0; i <= hint_top; i++){
        printf("%d ", hint[i]+1);
    }
    printf("\n");
    for(int i = 0; i < n; i++){
        printf("%d ", ans[i]);
    }


    return 0;
}