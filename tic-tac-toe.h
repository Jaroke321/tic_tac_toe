#ifndef TIC-TAC-TOE_H_INCLUDED
#define TIC-TAC-TOE_H_INCLUDED



#endif // TIC-TAC-TOE_H_INCLUDED

#include <iostream>
#include <string>

class Game
{
    char gameSpace[4][4];
    std::string player1, player2;

public:
    Game();
    void setName(std::string nameIn, int player);
    std::string getName(int player);
    void move(int row, int column, char symbol);
    void printBoard();
    int checkWinner();
};

Game::Game()
{
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            gameSpace[i][j] = '-';
        }
    }
}

void Game::setName(std::string nameIn, int player)
{
    if(player == 1)
    {
        player1 = nameIn;
    }

    else if(player == 2){
        player2 = nameIn;
    }
}

std::string Game::getName(int player)
{
    if(player == 1)
    {
        return player1;
    }
    else if(player == 2){
        return player2;
    }
}

void Game::move(int row, int column, char symbol)
{
    gameSpace[row][column] = symbol;
}

void Game::printBoard()
{
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            std::cout<<gameSpace[i][j]<<"\t";
        }
        std::cout<<"\n";
    }
}

int Game::checkWinner()
{
    //Check each row for winner
    int winner = 0;
    int count = 0;
    for(int i = 0; i < 4; i++){
        char firstChar = gameSpace[i][0];
        for(int j = 0; j < 4; j++){
            if(gameSpace[i][j] == firstChar){
                count++;
            }
        }
        if(count == 4){
            if(firstChar == 'x'){
                winner = 1;
            }
            else if(firstChar == 'o'){
                winner = 2;
            }
        }
        //reset count for next row
        count = 0;
    }

    //check each column for winner
    count = 0;
    for(int i = 0; i < 4; i++){
        char firstChar = gameSpace[0][i];
        for(int j = 0; j < 4; j++){
            if(gameSpace[j][i] == firstChar){
                count ++;
            }
        }
        if(count == 4){
            if(firstChar == 'x'){
                winner = 1;
            }
            else if(firstChar == 'o'){
                winner = 2;
            }
        }
        //reset count for next column
        count = 0;
    }
    //check diagnals for winner
    count = 1;
    char firstChar = gameSpace[0][0];
    if(gameSpace[1][1] == firstChar){
        count++;
    }
    if(gameSpace[2][2] == firstChar){
        count++;
    }
    if(gameSpace[3][3] == firstChar){
        count++;
    }

    if(count == 4){
        if(firstChar == 'x'){
            winner = 1;
        }
        else if(firstChar == 'o'){
            winner = 2;
        }
    }

    count = 1;
    firstChar = gameSpace[0][3];
    if(gameSpace[1][2] == firstChar){
        count++;
    }
    if(gameSpace[2][1] == firstChar){
        count++;
    }
    if(gameSpace[3][0] == firstChar){
        count++;
    }

    if(count == 4){
        if(firstChar == 'x'){
            winner = 1;
        }
        else if(firstChar == 'o'){
            winner = 2;
        }
    }
    return winner;
}
