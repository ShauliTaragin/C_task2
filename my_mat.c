#include <math.h>
#include <stdio.h>
#define V 10
#define INF INT_MAX

void Shorted_Paths(int dist[V][V]);

void Floyd_Warshall_algorithm(int graph[V][V]){  // Time Complexity: O(V^3)
    int dist[V][V], i, j, k;
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];
    for (k = 0; k < V; k++){
        for (i = 0; i < V; i++){
            for (j = 0; j < V; j++){
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    Shorted_Paths(dist);
}

void Shorted_Paths(int dist[V][V]){
    for (int i = 0; i < V; i++){
        for (int j = 0; j < V; j++){
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf ("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

int Check_Path(int src, int dest,int graph[][]) {
    return graph[src][dest]!=0;
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
