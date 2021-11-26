#include <stdio.h>
#include "my_mat.h"

#define V 10
int matrix[V][V];

void main() {
    while (1) {
        char command;
        int num1, num2;
        scanf("%c", &command);
        if (command == 'A') {
            for (int i = 0; i <9 ; i++) {
                for (int j = 0; j <9 ; j++) {
                    matrix[i][j]=0; // initializing the matrix to be all 0 just in case user didnt input well
                }
            }
            Create_Matrix(matrix);
        } else if (command == 'B') {
            scanf( "%d" , "%d" , num1 , num2);
            if(Check_Path(num1,num2,matrix) == 1){
                printf("True\n");
            }
            else{
                printf("False\n");
            }
        } else if (command == 'C') {

        } else { //command is 'D'
            break;
        }
    }
    return 0;
}