#ifndef SQUARE_H_
#define SQUARE_H_

#include <string>

class Square{
public:
	Square(char multiplier);
	~Square();
	int calcScore();
	bool isCovered();
	void setMultiplier();
	int getMultiplier();
	char getCharMultiplier();
	std::string getStringMultiplier();
	void addTileHoriz(char tilesToPlace, int points);
	void addTileVert(char tilesToPlace, int points);
	void coverSquare();
	int getScore();
	char getSquareLetters();
	//this class basically tells you what is on the specific square of the board so you can use these 
	//squares to calculate score of word and hold the bonuses and the tiles that are on them
private:
	char mSquareLetters;
	char mCharMultiplier;
	std::string mStringMultiplier;
	int mMultiplier;
	bool mCovered;
	bool startSquare;
	int mScore;
};

#endif /* SQUARE_H_ */