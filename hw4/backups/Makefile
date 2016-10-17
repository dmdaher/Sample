BIN_DIR = exe
CPPFLAGS = g++ -g -Wall

all: $(BIN_DIR)/scrabblegame

#$(BIN_DIR)/scrabblegame: $(BIN_DIR)/tile.o $(BIN_DIR)/bag.o $(BIN_DIR)/board.o $(BIN_DIR)/move.o $(BIN_DIR)/ui.o $(BIN_DIR)/player.o $(BIN_DIR)/dictionary.o $(BIN_DIR)/gamemanager.o Scrabble.cpp $(BIN_DIR)/.dirstamp
#	$(CPPFLAGS) Scrabble.cpp $(BIN_DIR)/tile.o $(BIN_DIR)/bag.o $(BIN_DIR)/board.o $(BIN_DIR)/move.o $(BIN_DIR)/ui.o $(BIN_DIR)/player.o $(BIN_DIR)/dictionary.o $(BIN_DIR)/gamemanager.o -o $(BIN_DIR)/scrabblegame

$(BIN_DIR)/scrabblegame: $(BIN_DIR)/square.o $(BIN_DIR)/bag.o $(BIN_DIR)/board.o $(BIN_DIR)/move.o $(BIN_DIR)/ui.o $(BIN_DIR)/player.o $(BIN_DIR)/dictionary.o $(BIN_DIR)/gamemanager.o Scrabble.cpp $(BIN_DIR)/.dirstamp
	$(CPPFLAGS) Scrabble.cpp $(BIN_DIR)/bag.o $(BIN_DIR)/square.o $(BIN_DIR)/board.o $(BIN_DIR)/move.o $(BIN_DIR)/ui.o $(BIN_DIR)/player.o $(BIN_DIR)/dictionary.o $(BIN_DIR)/gamemanager.o -o $(BIN_DIR)/scrabblegame

$(BIN_DIR)/bag.o: Bag.h Bag.cpp $(BIN_DIR)/.dirstamp
	$(CPPFLAGS) -c Bag.cpp -o $(BIN_DIR)/bag.o


$(BIN_DIR)/ui.o: UI.h UI.cpp $(BIN_DIR)/.dirstamp
	$(CPPFLAGS) -c UI.cpp -o $(BIN_DIR)/ui.o

$(BIN_DIR)/board.o: Board.h Board.cpp $(BIN_DIR)/.dirstamp
	$(CPPFLAGS) -c Board.cpp -o $(BIN_DIR)/board.o

$(BIN_DIR)/square.o: Square.h Square.cpp $(BIN_DIR)/.dirstamp
	$(CPPFLAGS) -c Square.cpp -o $(BIN_DIR)/square.o


$(BIN_DIR)/dictionary.o: Dictionary.h Dictionary.cpp $(BIN_DIR)/.dirstamp
	$(CPPFLAGS) -c Dictionary.cpp -o $(BIN_DIR)/dictionary.o


$(BIN_DIR)/player.o: Player.h Player.cpp $(BIN_DIR)/.dirstamp
	$(CPPFLAGS) -c Player.cpp -o $(BIN_DIR)/player.o


$(BIN_DIR)/move.o: Move.h Move.cpp $(BIN_DIR)/.dirstamp
	$(CPPFLAGS) -c Move.cpp -o $(BIN_DIR)/move.o

#$(BIN_DIR)/tile.o: Tile.h $(BIN_DIR)/.dirstamp
#	$(CPPFLAGS) -c Tile.h -o $(BIN_DIR)/tile.o


$(BIN_DIR)/gamemanager.o: gameManager.h gameManager.cpp $(BIN_DIR)/.dirstamp
	$(CPPFLAGS) -c gameManager.cpp -o $(BIN_DIR)/gamemanager.o


$(BIN_DIR)/.dirstamp:
	mkdir -p $(BIN_DIR)
	touch $(BIN_DIR)/.dirstamp

.PHONY: clean
clean:
	rm -rf $(BIN_DIR)