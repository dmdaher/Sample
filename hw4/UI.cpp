#include "UI.h"
#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

UI::UI(){}

UI::~UI(){}

void UI::getNameInput(int playerNumber){
	cout<<"Enter name for Player "<<playerNumber+1<<" : ";
}

int UI::getNumUsers(){
	int numUsers;
	cout<<"Please enter the number of players (1-8): ";
	cin>>numUsers;
	if(numUsers>8||numUsers<1){
		cout<<"Incorrect number of users. Retry"<<endl;
		cin >> numUsers;
	}
	return numUsers;
}
void UI::exchangeTileCheck(){
	cout<<"Invalid Exchange! Try Again."<<endl;
}
void UI::placeTileCheck(){
	cout<<"Invalid Placement! Try Again."<<endl;
}

void UI::validWord(){
	cout<<"Invalid Word. Try Again."<<endl;
}

void UI::printScores(int numUsers, vector<Player*> players){
	cout<<"Current Scores: "<<endl;
	for(int i = 0; i<numUsers; i++){
		cout<<players.at(i)->getName()<<", your score is: "<<players.at(i)->getScore()<<endl; 
	}
}

void UI::printBoard(Board* board, Square*** square){
	int counter = 1;
	cout<<"   ";
	for(int i = 0; i<board->getRows();i++){
		if(i>=9 && i<15){cout<<counter<<"  ";}
		else{
			cout<<counter<<"   ";
		}
		counter++;
	}
	cout<<endl;
	counter = 1;
	for(int i = 0; i<board->getRows(); i++)
	{
		if(i>=9 && i<15){cout<<counter<<" ";}
		else{
			cout<<counter<<"  ";
		}
		for (int j = 0; j<board->getCols(); j++)
		{
			cout<<square[i][j]->getStringMultiplier()<<" ";
		}
		counter++;
		cout<<endl;
	}
}

void UI::printPlayerTiles(set<Tile*> playerTiles){
	set<Tile*>::iterator it;
	for(it = playerTiles.begin(); it!=playerTiles.end(); it++){
		Tile* tile = *it;
		cout<<"["<< tile->getLetter() << ", "<<tile->getPoints()<< "] ";
	}
	cout<<endl;
}

void UI::whosTurn(string playerName){
	cout<<playerName<<", it's your turn!"<<endl;
}

void UI::listMoves(){

}

void UI::showHand(){

}

string UI::getMoves(Player* currPlayer){
	cout<<"To pass your turn, type PASS."<<endl
	<<"To discard tiles, type EXCHANGE, followed by a string of those tiles."<<endl
	<<"To place a word, type PLACE, followed by the following:"<<endl
	<<"first, either a | or - for vertical/horizontal placement"<<endl
    <<"second, the row (from the top), the column (from the left),"<<endl
    <<"third, a sequence of letters to place"<<endl
    <<"to use a blank tile, type ? followed by the letter you want to use it for."<<endl;
    string moveMade;
    cout<<"Your current tiles: ";
    printPlayerTiles(currPlayer->getTiles());
    cin>>moveMade;
    if(moveMade == "PASS"){
    	return "PASS";
    }
    else if(moveMade=="EXCHANGE"){
    	string tileExchange;
    	cin >> tileExchange;
    	string totalMove;
    	totalMove = moveMade+" "+tileExchange;
    	return totalMove;
    }
    else if(moveMade == "PLACE"){
    	string direction;
    	cin>>direction;
    	string strRow;
    	cin>>strRow;
    	string strColumn;
    	cin>>strColumn;
    	string tilePlaced;
    	cin>>tilePlaced;
    	string totalPlaceMove = moveMade + " "+direction + " " +strRow + " " +strColumn + " " +tilePlaced;
    	return totalPlaceMove;
    }
    else{return moveMade;}
}
//Have a function to ask for your move

//have a function to show what moves you can do
/*
To pass your turn, type PASS.
To discard tiles, type EXCHANGE, followed by a string of those tiles.
To place a word, type PLACE, followed by the following:
   first, either a | or - for vertical/horizontal placement;
   second, the row (from the top), the column (from the left),
   third, a sequence of letters to place;
   to use a blank tile, type ? followed by the letter you want to use it for.
Your current tiles: [?, 0] [A, 1] [B, 3] [R, 1] [N, 1] [O, 1] [U, 1] 
*/


// int main(){
// 	UI player;
// 	string name;
// 	int userNum;
// 	vector *names; //IS IT A POINTER? A DOUBLE POINTER? NOT A POINTER? WHY?
// 	userNum = player.getNumUsers();
// 	names = player.getNameInput();
// 	return 0;
// }