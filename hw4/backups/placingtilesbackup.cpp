for(unsigned int i = 0; i<completeTile.size(); i++){
					cout<<"before entering if statement for empty tiles, completeTile is: "<<completeTile[i]<<endl;
					cout<<"before entering if statement for empty tiles, is square covered? "<<mSquare[rowArrayView][colArrayView+i]->isCovered()<<endl;
					if(mSquare[rowArrayView][colArrayView+i]->isCovered()==0){
						cout<<"inside empty tile if statement, what is the letter that covers it? "<<mSquare[rowArrayView][colArrayView+i]->getSquareLetters()<<endl;
						if(counter<tilesPlacing.size()){
							mSquare[rowArrayView][colArrayView+i]->addTileHoriz(tilesPlacing[counter]->getLetter(),tilesPlacing[counter]->getPoints());
						}
						if(mSquare[rowArrayView][colArrayView+i]->getCharMultiplier() == 'd'){doubleTime = "D";}
						if(mSquare[rowArrayView][colArrayView+i]->getCharMultiplier() == 't'){triple = "T";}
						//wordScore += mSquare[rowArrayView][colArrayView+i]->getScore();
						cout<<"mSquare at hopefully beginning of completeTile should be P and is: "<<mSquare[rowArrayView][colArrayView-completeTile.size()+1+i]->getSquareLetters()<<endl;
						if(mSquare[rowArrayView][colArrayView+i-1]->isCovered()==0){
							wordScore += mSquare[rowArrayView][colArrayView+i]->getScore();
						}
						else if(){
							wordScore += mSquare[rowArrayView][colArrayView-completeTile.size()+1+i]->getScore();
						}
						counter++;
						cout<<"counter should be 2 max:"<<counter<<endl;
					}
					else{
						wordScore += mSquare[rowArrayView][colArrayView-completeTile.size()+1+i]->getScore();
						cout<<"mSquare at hopefully beginning of completeTile should be P and is: "<<mSquare[rowArrayView][colArrayView-completeTile.size()+1+i]->getSquareLetters()<<endl;
						cout<<"in the else if, so tile was covered, what is the letter that covers it? "<<mSquare[rowArrayView][colArrayView+counter]->getSquareLetters()<<endl;}
				}



				for(unsigned int i = 0; i<completeTile.size(); i++){
					cout<<"before entering if statement for empty tiles, completeTile is: "<<completeTile[i]<<endl;
					cout<<"before entering if statement for empty tiles, is square covered? "<<mSquare[rowArrayView][colArrayView+i]->isCovered()<<endl;
					if(mSquare[rowArrayView][colArrayView+i]->isCovered()==0){
						cout<<"inside empty tile if statement, what is the letter that covers it? "<<mSquare[rowArrayView][colArrayView+i]->getSquareLetters()<<endl;
						if(counter<tilesPlacing.size()){
							mSquare[rowArrayView][colArrayView+i]->addTileHoriz(tilesPlacing[counter]->getLetter(),tilesPlacing[counter]->getPoints());
						}
						if(mSquare[rowArrayView][colArrayView+i]->getCharMultiplier() == 'd'){doubleTime = "D";}
						if(mSquare[rowArrayView][colArrayView+i]->getCharMultiplier() == 't'){triple = "T";}
						wordScore += mSquare[rowArrayView][colArrayView+i]->getScore();
						counter++;
						cout<<"counter should be 2 max:"<<counter<<endl;
					}
					else{
						cout<<"in the else if, so tile was covered, what is the letter that covers it? "<<mSquare[rowArrayView][colArrayView+counter]->getSquareLetters()<<endl;}
				}