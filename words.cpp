//  Main program for testing

#include <iostream>
#include <string>
#include <cstdlib>

#include "wordSearch.h"

using namespace std;

int main(int argc, char *argv[])
{

// *****************************************************************

	string	bars, stars;
	bars.append(65, '-');
	stars.append(65, '*');
	string	dictionaryFile;
	string	puzzleFile;

// ------------------------------------------------------------------
//  Verify command line arguments.
//	Error out if bad, set user selection if good.
//	Note, -p option only used for testing.

	if (argc == 1) {
		cout << "Usage: words -d <dictionaryFile> -p <puzzle file>" << endl;
		return 0;
	}

	if (argc != 5) {
		cout << "Error, invalid command line options." << endl;
		return	0;
	}

	if (string(argv[1]) != "-d") {
		cout << "Error, invalid dictionary file specifier." << endl;
		return	0;
	}

	if (string(argv[3]) != "-p") {
		cout << "Error, invalid puzzle file specifier." << endl;
		return	0;
	}

	dictionaryFile = string(argv[2]);
	puzzleFile = string(argv[4]);

// ------------------------------------------------------------------
//  Headers...

	cout << bars << endl << "CS 302 - Assignment #6" << endl;
	cout << "Word Search Puzzle Solver" << endl;
	cout << endl;


// ------------------------------------------------------------------

	wordSearch	pzl1;

	if (!pzl1.readDictionary(dictionaryFile)) {
		cout << "main: Read dictionary error." << endl;
		exit(1);
	}

	if (!pzl1.readLetters(puzzleFile)) {
		cout << "main: Read letters file error." << endl;
		exit(1);
	}

	cout << bars << endl;
	pzl1.showTitle();
	cout << endl;
	pzl1.printLetters();

	pzl1.findWords();
	pzl1.showWords();

	cout << endl;
	cout << "Stats:" << endl;
	pzl1.showWordCount();
	cout << "Tree Max Height: " << pzl1.height() << endl;
	cout << "Tree Node Count: " << pzl1.countNodes() << endl;
	cout << endl;

	pzl1.destroyTree();

// *****************************************************************
//  All done.

	cout << bars << endl << "Game Over, thank you for playing." << endl;

	return 0;
}

