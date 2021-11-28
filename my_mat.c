#include <math.h>
#include <stdio.h>
#define V 10
#define INF 2147483647

int graph[V][V];

int minimum(int a, int b);

void Floyd_Warshall_algorithm(int graph[V][V]){  // Time Complexity: O(V^3)
    for (int k = 0; k < V; k++){
        for (int i = 0; i < V; i++){
            for (int j = 0; j < V; j++){
                if (graph[i][k] != 0 && graph[k][j] != 0 && graph[i][j] == 0) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
                if (graph[i][k] != 0 && graph[k][j] != 0 && graph[i][j] != 0) {
                    graph[i][j] = minimum(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
    }

int Short_Path(int a, int b, graph[V][V]) {
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


void Create_Matrix(int graph [][]) {
    int get_num;
    for (int i = 1; i <=10 ; i++) {
        for (int j = 1; j <=10 ; j++) {
            scanf("%d" , &get_num);
            graph[i][j] = get_num;
        }
    }
    Floyd_Warshall_algorithm(graph);
}

int main(){
    int graph[V][V] = { {0,   5,  INF, 10},
                        {INF, 0,   3, INF},
                        {INF, INF, 0,   1},
                        {INF, INF, INF, 0}
    };

    Floyd_Warshall_algorithm(graph);
    return 0;
}
