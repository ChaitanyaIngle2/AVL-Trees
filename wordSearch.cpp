// Chaitanya Ingle
// Section 1002
// Ast. 05

// FILE: wordSearch.cpp
// DESCRIPTION: Implementation file for wordSearch class.



#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "wordSearch.h"

using namespace std;


// CONSTRUCTOR AND DESTRUCTOR



// ********************
// wordSearch()
// 	- Initializes title to empty string, order to 0, and letters to NULL.

wordSearch::wordSearch()
{
	title = "";
	order = 0;
	letters = NULL;

}

// ********************
// ~wordSearch()
//	- Deallocates memory used by letters 2-d array.

wordSearch::~wordSearch()
{
	for (int i = 0; i< order; i++)
		delete[] letters[i];
	delete []letters;
	letters = NULL;

}

// ********************
// bool readLetters(const string fName)
//	- Reads word search puzzle from file fName. Returns true if read is 
//	  successful and false otherwise.

bool wordSearch::readLetters(const string fName)
{

	
	ifstream infile;             // dictionary for word search file
	infile.open(fName.c_str());
	if (!infile)                 // check if file open was successful
		return false;
	else {                       // if successful, populate letters[][] array with word search
		char linefeed;
		char letter;

		getline(infile, title);                  // get title
		infile>> order;                          // get order number
		infile.get(linefeed);                    // Get reading marker past \n

		letters = new string*[order];            // dynamically allocate 2-d array
		for (int i = 0; i < order; i++)
			letters[i] = new string[order];

		for (int j = 0; j < order; j++)          // fill 2-d array
			for (int k = 0; k < order; k++) {
				infile>> letter;
				letters[j][k] = letter;
			}
	
		infile.close();
		return true;
	}

}

// ********************
// bool readDictionary(const string dName)	
//	- Reads list of words from dictionary dName and stores them into avl Tree.

bool wordSearch::readDictionary(const string dName)
{

	ifstream infile;         // variable for dictionary file
	infile.open(dName.c_str());
	if (!infile)             // check if file open was successful
		return false;
	else {                   // if successful, fill avlTree with dictionary words
		string temp;
		while (getline(infile, temp)) {
			insert(temp);
		} 
		
		infile.close();
		return true;
	}
		
		

}

// ********************
// void findWords()
//	- Finds all words of length >= 3 in word search puzzle, by checking if they
//	  exist in the dictionary.

void wordSearch::findWords()
{

	for (int i = 0; i < order; i++) 
		for (int j = 0; j < order; j++)
			findWords(i,j);

}

// ********************
// void showTitle() const
//	- Prints title of word search puzzle.

void wordSearch::showTitle() const
{

	cout<< title<< endl;

}

// ********************
// void showWordCount() const
//	- Prints number of words found in puzzle.

void wordSearch::showWordCount() const
{

	cout<< endl<< endl<< "Word Count: "<< wordsFound.countNodes()<< endl;

}

// ********************
// void showWords() const
//	- Prints words found in word search along with starting position and direction.

void wordSearch::showWords() const
{

	wordsFound.printTree();
	cout<< endl<< endl;

}

// ********************
// void printLetters() const
//	- Prints formatted word search puzzle.

void wordSearch::printLetters() const
{

	// Print Top Row

	cout<< "   ";
	for (int i = 0; i < order; i++)
		cout<< " ___";

	// Print Body
	
	for (int i = 0; i < order; i++) {
		cout<< endl;
		for (int j = 0; j <= order; j++) 
			cout<< "   |";
		cout<< endl<< "   | ";
	
		for (int k = 0; k < order; k++) 
			cout << letters[i][k]<<  " | ";
		cout<< endl<< "   ";
		
		for (int l = 0; l < order; l++)
			cout<< "|___";

		cout<< "|";
	}

	cout<< endl;

}

// ********************
// void findWords(int x, int y)
//	- Finds any words starting at position (x,y) and adds them to wordsFound tree.

void wordSearch::findWords(int x, int y)
{

	stringstream ssX;   // Create string stream variables of values x and y for 
	stringstream ssY;   // string storing and printing purposes
	
	ssX << x;         
	ssY << y;
	
	string word = "";   // string to hold potential word
	string printString = "";   // string to hold entire statement to be stored and printed

	// Search Right (forward)

		for (int i = y; i < order; i++) {
			word += letters[x][i];
			if (word.length() > 2) 
				if (search(word)) {
					printString = '\n' + word + " - Right (forward) from: " + "(" + ssX.str() + "," + ssY.str() + ")";
					wordsFound.insert(printString);
				}
		}
		
		word = "";
		printString = "";
			
	// Search Left (backwards)

		for (int i = y; i >= 0; i--) {
			word += letters[x][i];
			if (word.length() > 2) 
				if (search(word)) {
					printString = '\n' + word + " - Left (backwards) from: " + "(" + ssX.str() + "," + ssY.str() + ")";
					wordsFound.insert(printString);
				}
		}
		
		word = "";
		printString = "";

	// Search Down 

		for (int i = x; i < order; i++) {
			word += letters[i][y];
			if (word.length() > 2) 
				if (search(word)) {
					printString = '\n' + word + " - Down from: " + "(" + ssX.str() + "," + ssY.str() + ")";
					wordsFound.insert(printString);
				}
		}
		
		word = "";
		printString = "";

	// Search Up

		for (int i = x; i >= 0; i--) {
			word += letters[i][y];
			if (word.length() > 2) 
				if (search(word)) {
					printString = '\n' + word + " - Up from: " + "(" + ssX.str() + "," + ssY.str() + ")";
					wordsFound.insert(printString);
				}
		}
		
		word = "";
		printString = "";

	// Search Forward Down Diagonal 

		for (int i = x, j = y; i < order && j < order; i++, j++) {
			word += letters[i][j];
			if (word.length() > 2) 
				if (search(word)) {
					printString = '\n' + word + " - Forward Down Diagonal from: " + "(" + ssX.str() + "," + ssY.str() + ")";
					wordsFound.insert(printString);
				}
		}
		
		word = "";
		printString = "";

	// Search Forward Up Diagonal

		for (int i = x, j = y; i >= 0 && j < order; i--, j++) {
			word += letters[i][j];
			if (word.length() > 2) 
				if (search(word)) {
					printString = '\n' + word + " - Forward Up Diagonal from: " + "(" + ssX.str() + "," + ssY.str() + ")";
					wordsFound.insert(printString);
				}
		}
		
		word = "";
		printString = "";

	// Search Backward Down Diagonal

		for (int i = x, j = y; i < order && j >= 0; i++, j--) {
			word += letters[i][j];
			if (word.length() > 2) 
				if (search(word)) {
					printString = '\n' + word + " - Backward Down Diagonal from: " + "(" + ssX.str() + "," + ssY.str() + ")";
					wordsFound.insert(printString);
				}
		}
		
		word = "";
		printString = "";

	// Search Backward Up Diagonal

		for (int i = x, j = y; i >= 0 && j>= 0; i--, j--) {
			word += letters[i][j];
			if (word.length() > 2) 
				if (search(word)) {
					printString = '\n' + word + " - Backward Up Diagonal from: " + "(" + ssX.str() + "," + ssY.str() + ")";
					wordsFound.insert(printString);
				}
		}
		
		word = "";
		printString = ""; 

}















