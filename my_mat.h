#ifndef MY_MATH_H
#define MY_MATH_H
#define V 10

void Create_Matrix(int graph [V][V]);
void Floyd_Warshall_algorithm(int graph[V][V]);
int Shortest_Path(int a, int b,int graph[V][V]);
int Check_Path(int src, int dest,int graph[V][V]);
int minimum(int a, int b);

#endif