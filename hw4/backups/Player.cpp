#include "Player.h"
#include <iostream>
#include <set>

using namespace std;

Player::Player(string name, set<Tile*> PlayerTiles){//, Bag &bag){
	mName = name;
	mScore = 0;
	mPlayerTiles = PlayerTiles;
}

set<Tile*> Player::getTiles(){return mPlayerTiles;}

Player::~Player(){}

string Player::getName(){return mName;}

void Player::setScore(int score){mScore += score;}

int Player::getScore(){return mScore;}

void Player::updatePlayerTiles(set<Tile*> newTiles){
	mPlayerTiles = newTiles;
}