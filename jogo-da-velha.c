#include <stdio.h>
#include <stdbool.h>

bool winCondition(int xScore, int oScore){
    if(xScore == 3 || oScore == 6){
      return true;
    }
    return 0;
}

bool mainDiagonalScore(int gameState[3][3]){
    int xScore = 0, oScore = 0;
    
    for(int i = 0; i <= 2; i++){
        if(gameState[i][i] == 1){
            xScore += gameState[i][i];
        } else if(gameState[i][i] == 2){
            oScore += gameState[i][i];
        } else{
            break;
        }
    }

    return winCondition(xScore, oScore);
}

bool secondDiagonalScore(int gameState[3][3]){
    int xScore = 0, oScore = 0, x = 2;

    for(int i = 0; i <= 2; i++){
        if(gameState[i][x] == 1){
            xScore += gameState[i][x];
        } else if(gameState[i][x] == 2){
            oScore += gameState[i][x];
        } else {
            break;
        }

        x--;
    }

    return winCondition(xScore, oScore);
}

bool columnScore(int gameState[3][3]){
    int xScore = 0, oScore = 0;

    for(int c = 0; c <= 2; c++){
        for(int r = 0; r <= 2; r++){
            if(gameState[r][c] == 1){
                xScore += gameState[r][c];
                if(xScore < 3 && r == 3){
                    xScore = 0;
                }
            }
            if(gameState[r][c] == 2){
                oScore += gameState[r][c];
                if(oScore < 6 && r == 3){
                    oScore = 0;
                } 
            } else {
                break;
            }            
        }
    }

    return winCondition(xScore, oScore);
}

bool rowScore(int gameState[3][3]){
    int xScore = 0, oScore = 0;

    for(int r = 0; r <= 2; r++){
        for(int c = 0; c <= 2; c++){
            if(gameState[c][r] == 1){
                xScore += gameState[c][r];
                if(xScore < 3 && c == 3){
                    xScore = 0;
                }
            } else if(gameState[c][r] == 2){
                oScore += gameState[c][r];
                if(oScore < 6 && c == 3){
                    oScore = 0;
                }
            } else {
                break;
            }
        }
    }

    return winCondition(xScore, oScore);
}

bool gameFinished(int gameState[3][3]){
    if(mainDiagonalScore(gameState) || secondDiagonalScore(gameState) || rowScore(gameState) || columnScore(gameState)){
        return true;
    }
    
    return 0;
}

void showTable(int gameState[3][3]){
    for(int i = 0; i <= 2; i++){
        for(int j = 0; j <= 2; j++){
            printf(" %d ", gameState[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int playerType;
    
    int gameState[3][3] = {
        1, 0, 0,
        1, 0, 0,
        1, 0, 0
        // 1 == X; 2 == O; 0 == NULL;
    };
    
    showTable(gameState);
    
    printf("\n%d\n", gameFinished(gameState));

    return 0;
}   