    // Diagonal Secundária
    int x = 2; 
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