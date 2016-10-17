#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>
#include <set>
#include "Tile.h"
#include "Move.h"
#include "Bag.h"

class Player {
public:

	Player (std::string name, std::set<Tile*> PlayerTiles);

	~Player();

	int getScore();

	void setScore(int score);

	std::string getName();

	std::set<Tile*> getTiles();

	void exchangeTiles(std::string tilesPlaced);

	void placeTiles(std::string direction, int row, int column, std::string tilesPlaced);

	void updatePlayerTiles(std::set<Tile*> newTiles);

private:
	std::string mName;
	int mScore;
	std::set<Tile*> mPlayerTiles;
};


#endif /* PLAYER_H_ */