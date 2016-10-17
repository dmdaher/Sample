#ifndef GAMEMANAGER_H_
#define GAMEMANAGER_H_

#include "Tile.h"
#include "Dictionary.h"
#include "Bag.h"
#include "Board.h"
#include "UI.h"
#include "Player.h"
#include "Move.h"
#include <string>
#include <vector>
#include <sstream>
#include <set>

class gameManager{
public:
	gameManager(std::string dictionaryfilename, std::string boardfilename, std::string bagfilename);
	~gameManager();
	void startGame();
private:
	bool mMadeMove;
	int mTurn;
	int mNumUsers;
	Dictionary* mDict;
	Board* mBoard;
	Bag* mBag;
	UI mUI;
	Move mMove;
	Square*** mSquare;
	std::vector <Player*> mPlayers;
	bool isThereAdjacent(std::string dir, int rowArrayView, int colArrayView, std::vector<Tile*> &tilesPlacing);
	bool atStartPlease(int rowArrayView, int colArrayView);
	void copyVector(std::vector<Tile*> &tilesAdjacent, std::vector<Tile*> &tilesPlacing);
	bool doCheck(bool &fullCheck, std::string& dir, int rowArrayView, int colArrayView, std::vector<Tile*> &tilesPlacing, std::string &tilesPlaced);
	bool tileCheckCovered(std::string dir, int row, int col, std::vector<Tile*> &tilesPlacing);
	bool validWord(std::string checkWord);
	std::string addTilestoVector(std::string tilesPlaced, std::vector<Tile*> &tilesPlacing, std::set<Tile*> &currPlayerTiles);
	std::string grabRightSideWords(int rowArrayView, int colArrayView, std::string &fullWordToRightStr, std::vector<Tile*> &tilesPlacing);
	bool validAdjacency(int row, int col, std::vector<Tile*> &tilesPlacing);
	void placeTiles(std::string direction, int row, int col, std::string tilesPlaced);
	std::vector<Tile*> adjustVector(std::string tilesPlaced, std::vector<Tile*> &tilesPlacing);
	std::string validTiles(std::string tilesToGive, std::string fullSet, bool &equiv);
	void printBoard(Board* mBoard, Square*** mSquare);
	std::vector<Player*> createPlayers(int numberUsers);
	void printCurrTiles();
	void printScores(std::string playerName);
	void readMove();
	void parseMove(std::stringstream& ss);
	Player* getPlayer (int i);
	void exchangeTiles(std::string tilesToGive);
	std::string editPlayerTiles(std::string tilesToGive, std::vector<Tile*> &tilesGiving, std::set<Tile*> &currPlayerTiles);
};

#endif /* GAMEMANAGER_H_ */