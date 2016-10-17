/*
 * Dictionary.cpp
 *
 *  Created on: Sep 18, 2016
 *      Author: kempe
 */

// The following is a suggestion for how to proceed.
// Feel free to make any changes you like.

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <set>
#include <cctype>
#include "Dictionary.h"

using namespace std;

Dictionary::Dictionary (string dictionary_file_name)
{
	ifstream dictFile (dictionary_file_name.c_str());
	string word;

	if (dictFile.is_open())
	{
		while (getline (dictFile, word))
		{
			mDictionaryset.insert(word);
			word.erase(word.length()-1); // remove end-of-line character
		
		}
		dictFile.close ();
	}
	else throw invalid_argument("Cannot open file: " + dictionary_file_name);
}

bool Dictionary::find(string wordSearch){
	for(unsigned int i = 0; i<wordSearch.length();i++){
		wordSearch[i] = tolower(wordSearch[i]);
	}
	stringstream ss;
	ss<<wordSearch;
	ss>>wordSearch;
	if(mDictionaryset.find(wordSearch)!=mDictionaryset.end()){
		return true;
	}
	else{
		return false;
	}
}