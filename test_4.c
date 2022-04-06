#include<stdio.h>
#include<stdlib.h>

void push(int *stack, int data, int *stack_top){
    *stack_top += 1;
    stack[*stack_top] = data; 
}

int city_check(int *arr, int arr_top, int c){
    for(int i = 0; i <= arr_top; i++){
        if(arr[i] == c){
            return 1;
        }
    }
    return 0;
}

void make_tree(int n, int tree[], int **arr, int *arr_top, int root_c, int city_id, int *cnt){
    tree[root_c] = city_id;
    *cnt += 1;
    if(*cnt != n){
        for(int i = 0; i < n; i++){
            if(tree[i] == -2 && city_check(arr[i], arr_top[i], root_c)){
                make_tree(n, tree, arr, arr_top, i, root_c, cnt);
            }
        }
        return;
    }
    return;
}

int walking_through_the_city(int tree_s[], int tree_r[], int c){
    while(tree_s[c] == tree_r[c] && tree_s[c] != -1){
        c = tree_s[c];
    }
    return c;
}

int main(){
    int n, q, s, r;
    scanf("%d%d%d%d", &n, &q, &s, &r);

    int **arr = malloc(sizeof(int*)*n);
    for(int i = 0; i < n; i++){
        arr[i] = malloc(sizeof(int)*1);
    }
    int *arr_top = malloc(sizeof(int)*n);
    int *tree_s = malloc(sizeof(int)*n);
    int *tree_r = malloc(sizeof(int)*n);

    for(int i = 0; i < n; i++){
        tree_s[i] = -2;
        tree_r[i] = -2;
        arr_top[i] = -1;
        arr[i][0] = -1;
    }

    for(int i = 0; i < n-1; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        arr[a-1] = (int*)realloc(arr[a-1], sizeof(int)*(arr_top[a-1] + 2));
        arr[b-1] = (int*)realloc(arr[b-1], sizeof(int)*(arr_top[b-1] + 2));
        push(arr[a-1], b-1, &arr_top[a-1]);
        push(arr[b-1], a-1, &arr_top[b-1]);
    }

    int cnt = 0;
    make_tree(n, tree_s, arr, arr_top, s-1, -1, &cnt);
    cnt = 0;
    make_tree(n, tree_r, arr, arr_top, r-1, -1, &cnt);

    for(int i = 0; i < q; i++){
        int c;
        scanf("%d", &c);
        printf("%d\n", walking_through_the_city(tree_s, tree_r, c-1) + 1);
    }

    /*for(int i = 0; i < n; i++){
        printf("%d ", tree_s[i]);
    }*/

    return 0;
}