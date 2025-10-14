#include <stdio.h>
#include <stdbool.h>

bool winCondition(int xScore, int oScore){
    if(xScore == 3 || oScore == 6){
      return true;
    }
    return 0;
}

bool gameFinished(int matriz[3][3]){
    int xScore = 0, oScore = 0;
    
    // Diagonal Principal
    for(int i = 0; i <= 2; i++){
        if(matriz[i][i] == 1){
            xScore += matriz[i][i];
        } else if(matriz[i][i] == 2){
            oScore += matriz[i][i];
        } else{
            break;
        }
        printf("\nxScore=%d oScore=%d", xScore, oScore);
    }

    if(winCondition(xScore, oScore)){
        xScore = 0; oScore = 0;
        return true;
    }
    
    // Diagonal Secundária
    int x = 2; 
    for(int i = 0; i <= 2; i++){
        if(matriz[i][x] == 1){
            xScore += matriz[i][x];
        } else if(matriz[i][x] == 2){
            oScore += matriz[i][x];
        } else {
            break;
        }

        x--;
    }

    if(winCondition(xScore, oScore)){
        xScore = 0; oScore = 0;
        return true;
    }
    
    return 0;
}

void showTable(int matriz[3][3]){
    for(int i = 0; i <= 2; i++){
        for(int j = 0; j <= 2; j++){
            printf(" %d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int playerType;
    
    int matriz[3][3] = {
        1, 0, 0,
        0, 1, 0,
        0, 0, 1
        // 1 == X; 2 == O; 0 == NULL;
    };
    
    showTable(matriz);
    
    printf("\n%d", gameFinished(matriz));

    return 0;
}   