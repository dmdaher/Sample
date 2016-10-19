#ifndef MOVE_H_
#define MOVE_H_

class Move {
public:
	Move(){}

	~Move(){}

	std::string showTiles();

	void placeTile(string moveType, string direction, int row, int column, string tilesPlaced);

	void exchangeTiles(string tilesPlaced);

	void currTiles();

	void parseMove(stringstream ss);





private:

};


#endif /* MOVE_H_ */
