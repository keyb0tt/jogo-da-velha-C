#include <stdio.h>
#include <stdbool.h>

struct Point 
{
    int x, y;
}; 

int winCondition(int xScore, int oScore){
    if(xScore == 3){
      return 1;
    } else if(oScore == 6){
        return 2;
    }

    return 0;
}

int mainDiagonalScore(int gameState[3][3]){
    int xScore = 0, oScore = 0;
    
    for(int i = 0; i <= 2; i++){
        if(gameState[i][i] == 1){
            xScore += gameState[i][i];
        } else if(gameState[i][i] == 2){
            oScore += gameState[i][i];
        } else {
            break;
        }
    }

    return winCondition(xScore, oScore);
}

int secondDiagonalScore(int gameState[3][3]){
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

int columnScore(int gameState[3][3]){
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


int rowScore(int gameState[3][3]){
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

int gameFinished(int gameState[3][3]){
    if(mainDiagonalScore(gameState) == 1 || secondDiagonalScore(gameState) == 1 || rowScore(gameState) == 1 || columnScore(gameState) == 1){
        return 1;
    } else if(mainDiagonalScore(gameState) == 2 || secondDiagonalScore(gameState) == 2 || rowScore(gameState) == 2 || columnScore(gameState) == 2){
        return 2;
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
    int playerChoice, counter = 0;
    
    int gameState[3][3] = {
        0, 0, 0,
        0, 0, 0,
        0, 0, 0
        // 1 == X; 0 == O; 0 == NULL;
    };

    printf("\n\n<---------------------------------------------------->\n\n");
    showTable(gameState);
    printf("\n<---------------------------------------------------->\n");

    while(true){
        if(counter % 2 == 0){
            printf("\n%d° Turno, movimento do X\n", counter + 1);
            printf("Selecione a casa: ");
            scanf("%d", &playerChoice);
            printf("\n");
        } else {
            printf("\n%d° Turno, movimento do O\n", counter + 1);
            printf("Selecione a casa: ");
            scanf("%d", &playerChoice);
            printf("\n");
        }
    
        struct Point playerMovement = moveConverter(playerChoice);

        if(gameState[playerMovement.x][playerMovement.y] != 0){
            printf("\n<---------------------------------------------------->\n");
            printf("\nMovimento já realizado\n");
            printf("\n<---------------------------------------------------->\n\n");
            showTable(gameState);
            printf("\n<---------------------------------------------------->\n");
            continue;
        }

        if(counter % 2 == 0){
            gameState[playerMovement.x][playerMovement.y] = 1;
        } else {
            gameState[playerMovement.x][playerMovement.y] = 2;   
        }

        printf("<--------------Atualização do tabuleiro-------------->\n\n");
        showTable(gameState);
        printf("\n<---------------------------------------------------->\n");

        // Condições de fim de jogo
        if(gameFinished(gameState) == 1){
            printf("\nFim de jogo!\nO ganhador foi o jogador X!\n");
            printf("\n<---------------------------------------------------->\n");
            return 0;
        } else if(gameFinished(gameState) == 2){
            printf("\nFim de jogo!\nO ganhador foi o jogador O!\n");
            printf("\n<---------------------------------------------------->\n");
            return 0;
        } if(counter == 8 && gameFinished(gameState) != 1 && gameFinished(gameState) != 2){
            printf("\nFim de jogo!\nOs jogadores empataram!\n");
            printf("\n<---------------------------------------------------->\n");
            return 0;
        }

        counter++;
    }

    return 0;
}   