#include <iostream>
#include <fstream>

using namespace std;

void printreverse (ifstream &myfile, string revWord, int count)
{
	if(count >0)
	{
		myfile>>revWord;
		printreverse(myfile, revWord, count-1);
	}
	else return;
	cout<<revWord<<endl;
}

int main(int argc, char* argv[])
{
	ifstream file(argv[1]);
	if (file.fail()) 
	{
		cout<<"Error opening file"<<endl;
		return 1;
	}
	if (argc == 2)
	{
		int numberwords = 0;
		string word;
		file >> numberwords;
		int count = numberwords;
		printreverse(file, word, count);		
	}
	else return 1;
}