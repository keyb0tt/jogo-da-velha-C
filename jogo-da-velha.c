#include <stdio.h>
#include <stdbool.h>

struct Point 
{
    int x, y;
}; 

bool winCondition(int xScore, int oScore){
    if(xScore == 3 || oScore == 6){
      return true;
    } else {
        return false;
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
    int xScore = 0, oScore = 0, row;
    
    for(int column = 0; column <= 2; column++){
        xScore = 0, oScore = 0, row = 0;
        do
        {
            if(gameState[row][column] == 1){
                xScore += gameState[row][column];
            }
            if(gameState[row][column] == 2){
                oScore += gameState[row][column];
            }
            if(xScore == 3 || oScore == 6){
                return winCondition(xScore, oScore);
            }
            row++;
        } 
        while(row <= 2);
    }

    return winCondition(xScore, oScore);
} 


bool rowScore(int gameState[3][3]){
    int xScore = 0, oScore = 0, column;

    for(int row = 0; row <= 2; row++){
        xScore = 0, oScore = 0, column = 0;
        do
        {
            if(gameState[row][column] == 1){
                xScore += gameState[row][column];
            }
            if(gameState[row][column] == 2){
                oScore += gameState[row][column];
            }
            if(xScore == 3 || oScore == 6){
                return winCondition(xScore, oScore);
            }
            column++;
        } 
        while(column <= 2);
    }

    return winCondition(xScore, oScore);
}

bool gameFinished(int gameState[3][3]){
    if(mainDiagonalScore(gameState) || secondDiagonalScore(gameState) || rowScore(gameState) || columnScore(gameState)){
        return true;
    }
    
    return 0;
}

struct Point moveConverter(int movement){
    int counter = 0;
    struct Point point;
    point.x = 0, point.y = 0;

    for(int r = 0; r <= 2; r++){
        for(int c = 0; c <= 2; c++){
            if(counter == movement){
                point.x = r;
                point.y = c;
                return point;
            }
            counter++;
        }
    }        
    return point;
}

void showTable(int gameState[3][3]){
    int counter = 0;

    for(int r = 0; r <= 2; r++){
        for(int c = 0; c <= 2; c++, counter++){
            if(gameState[r][c] == 1){
                printf(" X ");
            }
            if(gameState[r][c] == 2){
                printf(" O ");
            }
            if(gameState[r][c] == 0){
                printf(" %d ", counter);
            }
            if(c <= 1){
                printf("|");
            }
        }
        printf("\n");
    }
}

int main(){
    int playerType;
    
    int gameState[3][3] = {
        2, 1, 1,
        1, 2, 1,
        0, 0, 0
        // 1 == X; 0 == O; 0 == NULL;
    };
    
    printf("\n\n");
    showTable(gameState);
    printf("\n\n");
    printf("\n\ncolumn:%d\n", columnScore(gameState));
    printf("\nrow:%d\n", rowScore(gameState));

    // int playerChoice;
    // int counter = 0;
    
    // while(true){
    //     printf("\n%d° Turno\n", counter + 1);
    //     scanf("%d", &playerChoice);
    
    //     struct Point playerMovement = moveConverter(playerChoice);
    //     if(gameState[playerMovement.x][playerMovement.y] != 0){
    //         printf("\nMovimento já realizado\n");
    //         showTable(gameState);
    //         continue;
    //     }
    //     if(counter % 2 == 0){
    //         gameState[playerMovement.x][playerMovement.y] = 1;
    //     } else {
    //         gameState[playerMovement.x][playerMovement.y] = 2;   
    //     }
    //     showTable(gameState);
    //     if(gameFinished(gameState)){
    //         return 0;
    //     }

    //     counter++;
    // }

    return 0;
}   