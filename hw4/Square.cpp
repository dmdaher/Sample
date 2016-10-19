#include "Square.h"
#include <iostream>
#include <sstream>

using namespace std;

Square::Square(char multiplier){
	mCharMultiplier = multiplier;
	mCovered = false;
	mScore = 0;
	if(mCharMultiplier == '2' || mCharMultiplier =='3'){
		if (mCharMultiplier == '2'){
			mStringMultiplier = "2L ";
		}
		else if(mCharMultiplier == '3'){
			mStringMultiplier = "3L ";
		}
	}
	if(mCharMultiplier == 'd' || mCharMultiplier == 't'){
		if(mCharMultiplier == 'd'){
			mStringMultiplier = "2W ";
		}
		else if(mCharMultiplier == 't'){
			mStringMultiplier = "3W ";
		}
	}
	if(mCharMultiplier == '.'){
		mStringMultiplier = "...";
	}
	if(mCharMultiplier == '*'){
		mStringMultiplier = "***";
	}
}

Square::~Square(){}

void Square::setMultiplier(){
	if(mCharMultiplier == '2' || mCharMultiplier =='3'){
		if (mCharMultiplier == '2'){
			char twoChar = '2';
			int two = twoChar-48;
			mMultiplier = two;
		}
		else if(mCharMultiplier == '3'){
			char threeChar = '3';
			int three = threeChar-48;
			mMultiplier = three;
		}
	}
	if(mCharMultiplier == 'd' || mCharMultiplier == 't'){
		if(mCharMultiplier == 'd'){
			int dub = 2;
			mMultiplier = dub;
		}
		else if(mCharMultiplier == 't'){
			int trip = 3;
			mMultiplier = trip;
		}
	}
	if(mCharMultiplier == '.' || mCharMultiplier=='*'){
		mMultiplier = 1;
	}
}

char Square::getSquareLetters(){
cout<<"mSquareLetters is: "<<mSquareLetters<<endl;
	return mSquareLetters;}

void Square::addTileHoriz(char tilesToPlace, int points){
	stringstream ss;
	stringstream ss2;
	char tempTilesToPlace = tilesToPlace;
	string pointStr;
	string tilesToPlaceStr;
	ss<<tilesToPlace;
	ss>>tilesToPlaceStr;
	tilesToPlace = tempTilesToPlace;
	mSquareLetters = tilesToPlace;
	ss2<< points;
	ss2>>pointStr;
	if(pointStr == "10")
	{
		mStringMultiplier = tilesToPlace+pointStr;
	}
	else{
		mStringMultiplier = tilesToPlace+pointStr+" ";
		cout<<"mStringMultiplier is:"<<mStringMultiplier<<endl;
	}
	mScore = points;
	if(mCharMultiplier=='t'){
		mCharMultiplier = 't';
	}
	else if(mCharMultiplier=='d'){
		mCharMultiplier = 'd';
	}
	else if(mCharMultiplier=='2'){
		mScore = 2*mScore;
	}
	else if(mCharMultiplier=='3'){
		mScore = 3*mScore;
	}
	else if(mCharMultiplier == '*' || mCharMultiplier == '.'){
		mScore = points;
	}
	coverSquare();
}

char Square::getCharMultiplier(){return mCharMultiplier;}

int Square::getMultiplier(){return mMultiplier;}

int Square::getScore(){return mScore;}

void Square::addTileVert(char tilesToPlace, int points){
	stringstream ss;
	stringstream ss2;
	char tempTilesToPlace = tilesToPlace;
	string pointStr;
	string tilesToPlaceStr;
	ss<<tilesToPlace;
	ss>>tilesToPlaceStr;
	tilesToPlace = tempTilesToPlace;
	mSquareLetters = tilesToPlace;
	ss2<< points;
	ss2>>pointStr;
	if(pointStr == "10")
	{
		mStringMultiplier = tilesToPlace+pointStr;
	}
	else{
		mStringMultiplier = tilesToPlace+pointStr+" ";
		cout<<"mStringMultiplier is:"<<mStringMultiplier<<endl;
	}
	mScore = points;
	if(mCharMultiplier=='t'){
		mCharMultiplier = 't';
	}
	else if(mCharMultiplier=='d'){
		mCharMultiplier = 'd';
	}
	else if(mCharMultiplier=='2'){
		mScore = 2*mScore;
	}
	else if(mCharMultiplier=='3'){
		mScore = 3*mScore;
	}
	else if(mCharMultiplier == '*' || mCharMultiplier == '.'){
		mScore = points;
	}
	coverSquare();
}

string Square::getStringMultiplier(){return mStringMultiplier;}

bool Square::isCovered(){return mCovered;}

void Square::coverSquare(){mCovered = true;}

