#include <stdio.h>
#include "my_mat.h"
#define V 10

int graph[V][V];

int minimum(int a, int b);

void Create_Matrix(int graph [V][V]) {
    int get_num;
    for (int i = 0; i <V ; i++) {
        for (int j = 0; j <V ; j++) {
            scanf("%d" , &get_num);
            graph[i][j] = get_num;
        }
    }
    Floyd_Warshall_algorithm(graph);
}

void Floyd_Warshall_algorithm(int graph[V][V]){  
    for (int k = 0; k < V; k++){
        for (int i = 0; i < V; i++){
            for (int j = 0; j < V; j++){
                if(i!=j){
                    if (graph[i][k] != 0 && graph[k][j] != 0 && graph[i][j] == 0) {
                        graph[i][j] = graph[i][k] + graph[k][j];
                    }
                    if (graph[i][k] != 0 && graph[k][j] != 0 && graph[i][j] != 0) {
                        graph[i][j] = minimum(graph[i][j], graph[i][k] + graph[k][j]);
                    }
                }
            }
        }
    }
}
int Shortest_Path(int a, int b,int graph[V][V]) {
    return graph[a][b];
}

int Check_Path(int src, int dest,int graph[V][V]) {
    if(graph[src][dest]!=0){
        return 1;
    }
    else{
        return 0;
    }
}
int minimum(int a, int b){
    if(a < b) return a;
    return b;
}
