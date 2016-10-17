#ifndef MOVE_H_
#define MOVE_H_

#include <string>
#include <sstream>

class Move {
public:
	Move();

	~Move();

	std::string showTiles();

	

	//void placeTile(std::string moveType, std::string direction, int row, int column, std::string tilesPlaced);

	//void exchangeTiles(std::string tilesPlaced);

	void currTiles();

	//void parseMove(std::stringstream& ss);





private:

};


#endif /* MOVE_H_ */
