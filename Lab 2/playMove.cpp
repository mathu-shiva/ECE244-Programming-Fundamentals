//
//  playMove.cpp
//  TicTacToe
//
//  Created by Tarek Abdelrahman on 2019-06-07.
//  Modified by Tarek Abdelrahman on 2020-09-17.
//  Copyright © 2019-2020 Tarek Abdelrahman. All rights reserved.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.
//
//  ECE244 Student: write your code for playMove in this file

#include "globals.h"
#include "GameState.h"

//Function Initialization
void winChecker (int number, GameState& game_state);

void playMove(GameState& game_state) {
    
    //When the game is over
    if (game_state.get_gameOver()==true)
       
        return;
    
    //Checking the validity of the move
    if(game_state.get_gameBoard(game_state.get_selectedRow(), game_state.get_selectedColumn())==Empty)
    {
        game_state.set_moveValid(true);
    }
    else
    {
        game_state.set_moveValid(false);
    }
    
    if(game_state.get_moveValid()!=true)
    {
        return;
    }
    
    //Setting turn for X turn or 0 turn
    if (game_state.get_turn()==true)
    {
        game_state.set_gameBoard(game_state.get_selectedRow(), game_state.get_selectedColumn(), X);
        game_state.set_turn(0); //We change it to zero because it represents false (0), and the next turn is for 0
    }
    
    else
    {
        game_state.set_gameBoard(game_state.get_selectedRow(), game_state.get_selectedColumn(), O);
        game_state.set_turn(1); //We change it to one because it represents true (X), and the next turn is for X
    }
    
    winChecker (-1, game_state); //Checking if 0 won the game
    winChecker (1, game_state); //Checking if X won the game
    
    //Checking for a draw
    bool draw = true;
    for (int i=0; i<=2; i++)//Rows
    {
        for (int k=0; k<=2; k++)//Columns
        {
            if(game_state.get_gameBoard(i,k)==Empty)
            {
                draw = false;//If any of the spots are empty, draw will change to false, hence it is not a draw
            }
            
        }
    }
    if (draw == true) //If the loops determine that all the spots are full, then draw will not change to false, stays the same as true
    {
        game_state.set_winCode(0);
        game_state.set_gameOver(true);
    }
}

//This function implements the checker of a potential win, according to Table 1 in the document
void winChecker (int number, GameState& game_state)
{
    if ((game_state.get_gameBoard(0,0)==number)&&(game_state.get_gameBoard(0,1)==number)&&(game_state.get_gameBoard(0,2)==number))
    {
        game_state.set_winCode(1);
        game_state.set_gameOver(true);
    }
    else if ((game_state.get_gameBoard(1,0)==number)&&(game_state.get_gameBoard(1,1)==number)&&(game_state.get_gameBoard(1,2)==number))
    {
        game_state.set_winCode(2);
        game_state.set_gameOver(true);
    }
    else if ((game_state.get_gameBoard(2,0)==number)&&(game_state.get_gameBoard(2,1)==number)&&(game_state.get_gameBoard(2,2)==number))
    {
        game_state.set_winCode(3);
        game_state.set_gameOver(true);
    }
    else if ((game_state.get_gameBoard(0,0)==number)&&(game_state.get_gameBoard(1,0)==number)&&(game_state.get_gameBoard(2,0)==number))
    {
        game_state.set_winCode(4);
        game_state.set_gameOver(true);
    }
    else if ((game_state.get_gameBoard(0,1)==number)&&(game_state.get_gameBoard(1,1)==number)&&(game_state.get_gameBoard(2,1)==number))
    {
        game_state.set_winCode(5);
        game_state.set_gameOver(true);
    }
    else if((game_state.get_gameBoard(0,2)==number)&&(game_state.get_gameBoard(1,2)==number)&&(game_state.get_gameBoard(2,2)==number))
    {
        game_state.set_winCode(6);
        game_state.set_gameOver(true);
    }
    else if((game_state.get_gameBoard(0,0)==number)&&(game_state.get_gameBoard(1,1)==number)&&(game_state.get_gameBoard(2,2)== number))
    {
        game_state.set_winCode(7);
        game_state.set_gameOver(true);
    }
    else if((game_state.get_gameBoard(0,2)==number)&&(game_state.get_gameBoard(1,1)==number)&&(game_state.get_gameBoard(2,0)==number))
    {
        game_state.set_winCode(8);
        game_state.set_gameOver(true);
    }
    
    return;
}

