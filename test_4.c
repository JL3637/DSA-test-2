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

void visit_every_city(int **arr, int *arr_top, int *visit_city_arr, int *visit_city_arr_top, int *visit_city_arr_2, int *visit_city_arr_top_2, int *check_visited, int *check_visited_2, int s, int r){
    push(visit_city_arr, s, visit_city_arr_top);
    check_visited[s] = 1;
    while(visit_city_arr[*visit_city_arr_top] != r){
        int cnt = 0;
        int a = *visit_city_arr_top;
        for(int i = 0; i <= arr_top[visit_city_arr[a]]; i++){
            if(check_visited[arr[visit_city_arr[a]][i]] == 0){
                push(visit_city_arr, arr[visit_city_arr[a]][i], visit_city_arr_top);
                check_visited[arr[visit_city_arr[a]][i]] = 1;
                cnt++;
            }
        }
        if(cnt == 0){
            pop(visit_city_arr, visit_city_arr_top);
        }
    }

    push(visit_city_arr_2, s, visit_city_arr_top_2);
    check_visited_2[s] = 1;
    while(visit_city_arr_2[*visit_city_arr_top_2] != r){
        int b = pop(visit_city_arr_2, visit_city_arr_top_2);
        for(int i = 0; i <= arr_top[b]; i++){
            if(check_visited_2[arr[b][i]] == 0){
                push(visit_city_arr_2, arr[b][i], visit_city_arr_top_2);
                check_visited_2[arr[b][i]] = 1;
            }
        }
    }
    pop(visit_city_arr_2, visit_city_arr_top_2);

}

void adjust_ans(int **arr, int *arr_top, int *path, int *path_top, int *ans, int n){
    int *visit = malloc(sizeof(int)*n);
    int visit_top = -1;
    for(int i = 0; i < n; i++){
        visit[i] = -1;
    }
    for(int i = 0; i <= *path_top; i++){
        int *check = calloc(n, sizeof(int));
        push(visit, path[i], &visit_top);
        check[path[i]] = 1;
        while(visit_top != -1){
            int b = pop(visit, &visit_top);
            for(int j = 0; j <= arr_top[b]; j++){
                if(check[arr[b][j]] == 0 && ans[arr[b][j]] == -1){
                    push(visit, arr[b][j], &visit_top);
                    check[arr[b][j]] = 1;
                    ans[arr[b][j]] = path[i];
                }
            }
        }
        free(check);
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
    int *visit_city_arr = malloc(sizeof(int)*n);
    int visit_city_arr_top = -1;
    int *visit_city_arr_2 = malloc(sizeof(int)*n);
    int visit_city_arr_top_2 = -1;
    int *check_visited = malloc(sizeof(int)*n);
    int *check_visited_2 = malloc(sizeof(int)*n);
    int *path = malloc(sizeof(int)*n);
    int path_top = -1;
    int *ans = malloc(sizeof(int)*n);
    for(int i = 0; i < n; i++){
        arr_top[i] = -1;
        arr[i][0] = -1;
        visit_city_arr[i] = -1;
        check_visited[i] = 0;
        visit_city_arr_2[i] = -1;
        check_visited_2[i] = 0;
        path[i] = -1;
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

    visit_every_city(arr, arr_top, visit_city_arr, &visit_city_arr_top, visit_city_arr_2, &visit_city_arr_top_2, check_visited, check_visited_2, s-1, r-1);

    int a = 0;
    for(int i = 0; i <= visit_city_arr_top; i++){
        if(visit_city_arr[i] == visit_city_arr_2[a]){
            a++;
        }
        else{
            push(path, visit_city_arr[i], &path_top);
            ans[visit_city_arr[i]] = visit_city_arr[i];
        }
    }

    adjust_ans(arr, arr_top, path, &path_top, ans, n);

    for(int i = 0; i < q; i++){
        int c;
        scanf("%d", &c);
        printf("%d\n", ans[c-1]+1);
    }

    return 0;
}