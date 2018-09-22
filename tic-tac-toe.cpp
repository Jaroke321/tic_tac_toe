#include "tic-tac-toe.h"
#include <string>
#include <iostream>

int main()
{
    //create player1 and player2 variables and game object
    std::string player1;
    std::string player2;
    Game gameboard;
    int row, column;
    int winner = 0;

    //prompt players for names
    std::cout<<"what is your name player 1?\n";
    std::cin>>player1;
    gameboard.setName(player1, 1);
    std::cout<<"what is your name player2?\n";
    std::cin>>player2;
    gameboard.setName(player2, 2);
    //print starting board
    gameboard.printBoard();

    for(int i = 0; i < 8; i++)
    {
        //players 1 move
        std::cout<<"It is "<<gameboard.getName(1)<<"'s turn\n\n";
        std::cin>>row;
        std::cin>>column;
        gameboard.move(row, column, 'x');
        gameboard.printBoard();
        winner = gameboard.checkWinner();

        if(winner == 1)
        {
            std::cout<<"player 1 wins";
            break;
        }

        //players2 move
        std::cout<<"It is "<<gameboard.getName(2)<<"'s turn\n\n";
        std::cin>>row;
        std::cin>>column;
        gameboard.move(row, column, 'o');
        gameboard.printBoard();
        winner = gameboard.checkWinner();

        if(winner == 2)
        {
            std::cout<<"player 2 wins";
            break;
        }
    }
    if(winner == 0){
        std::cout<<"Tied game!!!";
    }
    return 0;
}
