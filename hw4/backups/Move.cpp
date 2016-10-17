#include "Move.h"
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;

Move::Move(){}

Move::~Move(){}

// void Move::parseMove(stringstream& ss){
// 	string moveType;
// 	string direction;
// 	int row; //do i need to declare as a string first?
// 	int column; //do i need to declare as a string first?
// 	string tilesPlaced;
// 	ss>>moveType;
// 	if(moveType == "EXCHANGE"){
// 		ss>>tilesPlaced;
// 		//exchangeTile(tilesPlaced);
// 	}
// 	else if(moveType =="PASS"){
// 		//break;
// 	}
// 	else if(moveType == "PLACE"){
// 		ss>>direction;
// 		ss>>row;
// 		//atoi(row);
// 		ss>>column;
// 		//atoi(column);
// 		ss>>tilesPlaced;
// 		//placeTile(moveType, direction, row, column, tilesPlaced);
// 	}
// }

// void Move::placeTile(string moveType, string direction, int row, int column, string tilesPlaced){


// }

// void Move::exchangeTile(string tilesPlaced){
	
// }