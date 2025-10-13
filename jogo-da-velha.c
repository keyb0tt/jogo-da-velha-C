#include <stdio.h>
#include <stdbool.h>

void showTable(int matriz[3][3]){
    for(int i = 0; i <= 2; i++){
        for(int j = 0; j <= 2; j++){
            printf(" %d ", matriz[i][j]);
        }
        printf("\n");
    }
}

bool gameFinished(int matriz[3][3]){
    int somaX = 0, somaO = 0;
    
    // Diagonal Principal
    for(int i = 0; i <= 2; i++){
        if(matriz[i][i] == 1){
            somaX += matriz[i][i];
        } else if(matriz[i][i] == 2){
            somaO += matriz[i][i];
        } else{
            break;
        }
        printf("\nsomax=%d somao=%d", somaX, somaO);
    }
    
    if(somaX == 3 || somaO == 6){
        return true;
    }
    somaX = 0, somaO = 0;
    
    // Diagonal Secundária
    int x = 2; 
    for(int i = 0; i <= 2; i++){
        if(matriz[i][x] == 1){
            somaX += matriz[i][x];
        } else if(matriz[i][x] == 2){
            somaO += matriz[i][x];
        } else {
            break;
        }
        x--;
    }
    
    if(somaX == 3 || somaO == 6){
        return true;
    }
    somaX = 0; somaO = 0;
    
    return 0;
}

int main(){
    int playerType;

    int matriz[3][3] = {
        0, 0, 2,
        0, 2, 0,
        2, 0, 0
        // 1 == X; 2 == O; 0 == NULL;
    };

    showTable(matriz);

    printf("\n%d", gameFinished(matriz));

    return 0;
}   