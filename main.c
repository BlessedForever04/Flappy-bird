#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

// You can change according to your preference.
#define mapHeight 20
#define mapLength 80

// Some OOP flavour
struct bird{
    int groundDistance; // Distance from the ground.
    int score;
}gameBird = {10, 0};

char map[mapHeight][mapLength];

// Check if game is over or not.
bool gameOver(){
    if(map[gameBird.groundDistance][mapLength/4] == '|' || ((gameBird.groundDistance < 1) || (gameBird.groundDistance > mapHeight - 2))){
        return true;
    }
    else{
        return false;
    }
}

// Prints the complete game.
void printGame(){
    printf("Press SPACE to fly!");
    for(int i = 0; i < mapLength - 30; i++){
        printf(" ");
    }
    printf("Score: %d\n", gameBird.score);
    for(int i = 0; i < mapHeight; i++){
        for(int j = 0; j < mapLength; j++){
            if(i == gameBird.groundDistance && j == mapLength/4){
                printf("O");
            }
            else{
                printf("%c", map[i][j]);
            }
        }
        printf("\n");
    }
}

// Moves the map and increase score.
void updateState(){
    for(int i = 1; i < mapHeight - 1; i++){
        for(int j = 1; j < mapLength - 1; j++){
            if(j == mapLength - 2){
                map[i][j] = ' ';
            }
            else{
                map[i][j] = map[i][j+1];
            }
        }
    }
    gameBird.score++;
}

// Continous Keyboard input
void input(){
    if(kbhit()){
        char output  = getch();
        if((int)output == 32){
            gameBird.groundDistance -= 2;
        }
    }
    else{
        gameBird.groundDistance += 1;
    }
}

// Adds towers
void addObstracles(){
    int topTower = rand() % 14;

    for(int i = 1; i < topTower; i++){
        map[i][mapLength - 2] = '|';
    }

    for(int i = topTower + 4; i < mapHeight - 1; i++){
        map[i][mapLength - 2] = '|';
    }
}

// Main game function
void game(bool *prunGame, int difficultyFactor){
    int sleepTime = 150 - (gameBird.score / difficultyFactor);
    addObstracles();

    // Obstracle appears after 15 iterations
    for(int i = 0; i < 15; i++){
        printGame();
        input();
        updateState();
        Sleep(sleepTime);
        system("@cls||clear");
        if(gameOver()){
            printGame();
            printf("Your game is over, but you scored: %d", gameBird.score);
            *prunGame = false;
            break;
        }
    }
}

void buildMap(){
    for(int i = 0; i < mapHeight; i++){
        for(int j = 0; j < mapLength; j++){
            if((i == mapHeight - 1) || (j == mapLength - 1) || (i == 0) || (j == 0)){
                map[i][j] = '-';
            }
            else{
                map[i][j] = ' ';
            }
        }
    }
}

int main(){  
    int difficultyDecision;
    int difficultyFactor;
    bool runGame = true;

    printf("Welcome to Flappy bird, this game is designed to irritate you!\nLets see how much can you score till the end of the game.\nGame's difficulty:\n1. Easy\n2. Medium\n3. Hard\n: ");
    scanf("%d", &difficultyDecision);

    switch (difficultyDecision){
    case 1:
        difficultyFactor = 15;
        break;
    case 2:
        difficultyFactor = 10;
        break;
    case 3:
        difficultyFactor = 3;
        break;
    default:
        system("@cls||clear");
        printf("Enter the correct choice!");
        main();
    };

    srand(time(NULL));
    buildMap();

    while(runGame){
        game(&runGame, difficultyFactor);
    }

    return 0;
}