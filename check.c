#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkSudoku(int sudoku[9][9]){
   
    int check = 1;
    int i,j,k,l,m,n;
    
    for(i=0; i < 9; i++){
        for(j=0; j < 9; j++){
            for(k=0; k < 9; k++){
                if(k != j && sudoku[i][j]==sudoku[i][k])
                check = 0;
                if(k != j && sudoku[j][i]==sudoku[k][i])
                check = 0;
            }
        }
    }

    for(i=0; i < 3;i++){
        for(j=0; j < 3; j++){
             for(k=0;k < 3;k++){
                 for(l=0;l < 3;l++){
                      for(m=0;m < 3;m++){
                          for(n=0;n < 3;n++){
                              if(k != m && l != n && sudoku[i+k][j+l] == sudoku[i+m][j+n])
                                  check = 0;
                          }
                      }
                 }
             }
        }
    }

    return check;

}

int lireSudoku(FILE *fich,int sudoku[9][9]){
    int i,j,res;
    int val; 
    for (i=0; i<9; i++) 
             for (j=0; j<9; j++) {  
                 res=fscanf(fich, "%d",&val);
                 if (res==EOF){
                     fprintf(stderr,"Fin de ficher atteinte: manque des coefficients\n");
                      exit(-1);
                 }
                 sudoku[i][j]=val;
             }  
    return(0);
}



int main() {

    int sudoku[9][9];
    FILE *fich = fopen("sudoku1.txt","r");

    lireSudoku(fich,sudoku);
    
    int a = checkSudoku(sudoku);
    printf("%d\n",a);

    return 0;

}


