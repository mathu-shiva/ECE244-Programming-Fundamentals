//
//  main.cpp
//  TicTacTo
//
//  Created by Tarek Abdelrahman on 2019-06-07.
//  Modified by Tarek Abdelrahman on 2020-09-17.
//  Copyright © 2019-2020 Tarek Abdelrahman. All rights reserved.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.
//
//  ECE244 Student: Complete the skeletal code of the main function in this file


#include <iostream>
#include <string>
using namespace std;

#include "globals.h"
#include "GameState.h"

// Function prototype for playMove
void playMove(GameState& game_state);
void printBoard (int row, int col, bool variable, char printB[3][3]);

// The main function
int main() {

    /**********************************************************************************/
    /* Create an initialized game state object                                        */
    /**********************************************************************************/
    //The below code creates the object of the GameState class
    GameState game_state;

    // Read two integers from the user that represent the row and column
    // the player would like to place an X or an O in
    // You can assume there will be no formatting errors in the input

    int row;
    int col;
    
    //Initialization of Board
    game_state.set_gameBoard(0,0,Empty);
    game_state.set_gameBoard(0,1,Empty);
    game_state.set_gameBoard(0,2,Empty);
    game_state.set_gameBoard(1,0,Empty);
    game_state.set_gameBoard(1,1,Empty);
    game_state.set_gameBoard(1,2,Empty);
    game_state.set_gameBoard(2,0,Empty);
    game_state.set_gameBoard(2,1,Empty);
    game_state.set_gameBoard(2,2,Empty);
    game_state.set_gameOver(false);
    game_state.set_turn(true);
    
   // std::cout << std::boolalpha << "gameOver: " << game_state.get_gameOver() << std::noboolalpha << endl;
   
    while (game_state.get_gameOver()== false) {
        cout << "Enter row and column of a grid cell: ";
        cin >> row >> col;
        
        
        // Check that the read row and column values are valid grid coordinates
        if ( (row < 0) || (row > 2) || (col < 0) || (col > 2) ) {
            cout << "Invalid board coordinates " << row << " " << col << endl << endl;
           continue;
        }
        
        
        
        // The coordinates are valid; set the selectedRow and selectedColumn
        // members of the game state to the read values
        // Again, the corresponding mutators of GameState must be first
        // implemented before this works
            
        // ECE244 Student: add your code here
        //Setting the entered row and column from the user into selectedRow and selected Column
        game_state.set_selectedRow(row);
        game_state.set_selectedColumn(col);
            
        // Call playMove
        playMove(game_state);
   
          
        // ECE244 Student: add your code here
            
        // Print the GameState object, as prescribed in the handout
            
        // ECE244 Student: add your code here
        cout << "Selected row " << row << " and column " << col << endl;
        cout << "Game state after playMove:" << endl;
        cout << "Board:" << endl;
        
        bool variable = game_state.get_turn();
        char printB [3][3];
        printBoard (row, col, variable, printB);
        /*
        bool variable = game_state.get_turn();
        
        char printB [3][3];
        for (int i=0; i<3; i++)
        {
            for (int k=0; k<3; k++)
            {
                if (i == row && k == col)
                {
                    if (variable)
                    {
                        printB[i][k]='O';
                    }
                    if (!variable)
                    {
                        printB[i][k]='X';
                    }
                     
                }
                else
                { 
                    if (printB [i][k]=='O'|| printB[i][k]=='X')
                    {
                        ;
                    }
                    else
                    {
                        printB[i][k]= 'B';
                    }
                }
                
            }
        }
        
        
        for (int m=0; m<3; m++)
        {
            cout << "   ";
            for (int n=0; n<3; n++)
            {
                std::cout<<printB[m][n]<<' ';
            }
            std::cout<<'\n';
        }
       */
        std::cout << std::boolalpha << "moveValid: " << game_state.get_moveValid() << std::noboolalpha << endl;
        std::cout << std::boolalpha << "gameOver: " << game_state.get_gameOver() << std::noboolalpha << endl;
        std::cout << std::boolalpha << "winCode: " << game_state.get_winCode() << std::noboolalpha << endl << endl;
        
     
        
       
    }
    

    return 0;
}

void printBoard (int row, int col, bool variable, char printB [3][3])
{
    
        
        
        for (int i=0; i<3; i++)
        {
            for (int k=0; k<3; k++)
            {
                if (i == row && k == col)
                {
                    if (variable)
                    {
                        printB[i][k]='O';
                    }
                    if (!variable)
                    {
                        printB[i][k]='X';
                    }
                     
                }
                else
                { 
                    if (printB [i][k]=='O'|| printB[i][k]=='X')
                    {
                        ;
                    }
                    else
                    {
                        printB[i][k]= 'B';
                    }
                }
                
            }
        }
        
        
        for (int m=0; m<3; m++)
        {
            cout << "   ";
            for (int n=0; n<3; n++)
            {
                std::cout<<printB[m][n]<<' ';
            }
            std::cout<<'\n';
        }
}

