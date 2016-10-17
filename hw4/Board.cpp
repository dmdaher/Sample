/*
 * Board.cpp
 *
 *  Created on: Sep 18, 2016
 *      Author: kempe
 */

// The following is a suggestion for how to proceed.
// Feel free to make any changes you like.

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "Board.h"

using namespace std;

Board::Board (string board_file_name)
{
	ifstream boardFile (board_file_name.c_str());
	string row;

	_x = _y = _startx = _starty = 0; // to appease compiler
	if (!boardFile.is_open())
		throw invalid_argument("Cannot open file: " + board_file_name);
	getline (boardFile, row);
	stringstream s1 (row);
	s1 >> _x >> _y; //board size 15x15
	getline (boardFile, row);
	stringstream s2 (row);
	s2 >> _startx >> _starty; //board starting square row 8 col 8 based on txt file
	_startx --; _starty --;  // coordinates from 0 in array


	mSquare = new Square**[_y];

	char multiplier;
	for (int i = 0 ; i < _y; ++ i)
	{
		getline (boardFile, row);
		mSquare[i] = new Square*[_x];

		for (int j = 0; j < _x; ++ j)
		{
			// cout << "Here" << endl;
			// Fill in the following based on how you store the board.
			if (i == _starty && j == _startx) {
				mSquare[i][j] = new Square('*');
			}
			else 
			{
				if(row[j] == '.')
				{

					mSquare[i][j] = new Square('.');
				}
				else if(row[j] == '2')
				{
					multiplier = '2';
					mSquare[i][j] = new Square(multiplier);
				}
				else if(row[j] == '3')
				{
					multiplier = '3';
					mSquare[i][j] = new Square(multiplier);
				}
				else if(row[j] == 'd')
				{
					multiplier = 'd';
					mSquare[i][j] = new Square(multiplier);
				}
				else if(row[j] == 't')
				{
					multiplier = 't';
					mSquare[i][j] = new Square(multiplier);
				}
				else
				{
						string error = "Improper character in Board file: ";
						throw invalid_argument(error + row[j]);
			
				}
			}
		}
	}
	boardFile.close ();
}

Board::~Board(){
	for(int i = 0; i<_x;i++){
		for(int j = 0; j<_y; j++){
			delete [] mSquare[i][j];
		}
		delete [] mSquare[i];
	}
	delete [] mSquare;
}

Square*** Board::getSquare(){return mSquare;}

int Board::getStartRow(){return _startx;}
int Board::getStartCol(){return _starty;}
int Board::getRows(){return _x;}
int Board::getCols(){return _y;}
