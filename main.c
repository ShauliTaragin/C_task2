#include <stdio.h>
#include "my_mat.h"

#define V 10

int matrix[V][V];
int num1, num2;

int main(void) {
    int flag=1;
    while (flag) {
        char command =getchar();
        switch (command)
        {
        case 'A':
            for (int i = 0; i <V ; i++) {
                for (int j = 0; j <V ; j++) {
                    matrix[i][j]=0; 
                }
            }
            Create_Matrix(matrix);
            break;
        case 'B':
            scanf( "%d %d" , &num1 , &num2);
            if(Check_Path(num1,num2,matrix)){
                printf("True\n");
            }
            else{
                printf("False\n");
            }
            break;
        case 'C':
            scanf( "%d %d" , &num1 , &num2);
            if(Shortest_Path(num1,num2,matrix)!=0){
                printf("%d\n" , Shortest_Path(num1,num2,matrix));
            }
            else{
                printf("-1\n");
            }
            break;
        case 'D':
            flag =0;
            break;
        }
    }
    return 0;
}