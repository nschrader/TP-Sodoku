/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>


int checkSudoku(int sudoku[9][9]){
    int check = 1;
    
    for(int i=0; i < 9; i++){
        for(int j=0; j < 9; j++){
            for(int k=0; k < 9; k++){
                if(k != j || sudoku[i][j]==sudoku[i][k])
                check = 0;
                if(k != j || sudoku[j][i]==sudoku[k][i])
                check = 0;
            }
        }

    }
    
    for(int i=0; i < 3; i++){
        for(int j=0; j < 3; j++){
            for(int k=0; k < 3; k++){
                for(int l=0; l < 3; l++){
                    for(int m=0; m < 3; m++){
                        for(int n=0; n < 3; n++){
                            if(k != m || l != n || sudoku[i+k][j+m]==sudoku[i+l][j+n])
                            check = 0;
                        }
                    }
                }
            }
        }
    }

    
    return check;

}

int main() {

    int sudoku[9][9] = 
        {
            {9,0,0,1,0,0,0,0,5},
            {0,0,5,0,9,0,2,0,1},
            {8,0,0,0,4,0,0,0,0},
            {0,0,0,0,8,0,0,0,0},
            {0,0,0,7,0,0,0,0,0},
            {0,0,0,0,2,6,0,0,9},
            {2,0,0,3,0,0,0,0,6},
            {0,0,0,2,0,0,9,0,0},
            {0,0,1,9,0,4,5,7,0}
            
        };
    
    int a = checkSudoku(sudoku);
    printf("%d",a);

    return 0;

}


