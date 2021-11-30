#include <stdio.h>
#include "my_mat.h"

#define V 10

int matrix[V][V];
int num1, num2;

int main(void) {
    int breaky=1;
    while (breaky==1) {
        char command =getchar();
        if (command == 'A') {
            for (int i = 0; i <V ; i++) {
                for (int j = 0; j <V ; j++) {
                    matrix[i][j]=0; // initializing the matrix to be all 0 just in case user didnt input well
                }
            }
            Create_Matrix(matrix);
        }
        else if (command == 'B') {
            scanf( "%d %d" , &num1 , &num2);
            if(Check_Path(num1,num2,matrix)){
                printf("True\n");
            }
            else{
                printf("False\n");
            }
        } 
        else if (command == 'C') {
            scanf( "%d %d" , &num1 , &num2);
            if(Shortest_Path(num1,num2,matrix)!=0){
                printf("%d\n" , Shortest_Path(num1,num2,matrix));
            }
            else{
                printf("-1\n");
            }
        }
        else if(command == 'D'){ //command is 'D'
            breaky=0;
        }
    }
    return 0;
}