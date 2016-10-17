#ifndef UI_H_
#define UI_H_
#include <string>
#include <set>
#include "Board.h"
#include "Square.h"
#include "Tile.h"
#include "Player.h"

class UI {
	public:
		UI();
		~UI();
		void getNameInput(int numberUsers);
		int getNumUsers();
		void placeTileCheck();
		void exchangeTileCheck();
		std::string getMoves(Player* currPlayer);
		void printBoard(Board* board, Square*** square);
		void printScores(int numUsers, std::vector<Player*> players);
		void showHand();
		void listMoves();
		void whosTurn(std::string playerName);
		void printPlayerTiles(std::set<Tile*> playerTiles);
		void validWord();
	private:
};


#endif /* UI_H_ */