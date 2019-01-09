// Chaitanya Ingle
// Section 1002
// Ast. 05
//
// FILE: wordSearch.h
// DESCRIPTION: Header file for wordSearch class inherited from avlTree class.
//
// -------------------- CLASS OVERVIEW --------------------
//
// NOTE: Inherited from avlTree class.
//
//
//
// ----- PRIVATE DATA MEMBERS -----
//
//
//
// string title
//	- string to hold title of word search puzzle
//
// int order
//	- int to hold order number (dimensions) of word search puzzle
//
// string **letters
//	- pointer to dynamically allocated 2-d array of strings to hold letters
//	  from word search puzzle
//
// avlTree<string> wordsFound
//	- avlTree to hold all words found from puzzle.
//
//
//
// ----- CONSTRUCTOR AND DESTRUCTOR -----
//
//
//
// wordSearch()
// 	- Initializes title to empty string, order to 0, and letters to NULL.
//
// ~wordSearch()
//	- Deallocates memory used by letters 2-d array.
//
//
//
// -----PUBLIC FUNCTIONS -----
//
//
//
// bool readLetters(const string fName)
//	- Reads word search puzzle from file fName. Returns true if read is 
//	  successful and false otherwise.
//
// bool readDictionary(const string dName)	
//	- Reads list of words from dictionary dName and stores them into avl Tree.
//
// void findWords()
//	- Finds all words of length >= 3 in word search puzzle, by checking if they
//	  exist in the dictionary.
//
// void showTitle() const
//	- Prints title of word search puzzle.
//
// void showWordCount() const
//	- Prints number of words found in puzzle.
//
// void showWords() const
//	- Prints words found in word search along with starting position and direction.
//
// void printLetters() const
//	- Prints formatted word search puzzle.
//
//
//
// ----- PRIVATE FUNCTIONS -----
//
//
//
// void findWords(int x, int y)
//	- Finds any words starting at position (x,y) and adds them to wordsFound tree.





#include <string>
#include "avlTree.h"

using namespace std;

class wordSearch: public avlTree<string>
{
	public:
	
	// CONSTRUCTOR AND DESTRUCTOR

	wordSearch();
	~wordSearch();

	// PUBLIC FUNCTIONS
	
	bool readLetters(const string fName);
	bool readDictionary(const string dName);	
	void findWords();
	void showTitle() const;
	void showWordCount() const;
	void showWords() const;
	void printLetters() const;
	
	private:

	// PRIVATE DATA MEMBERS
	
	string title;
	int order;
	string **letters;
	avlTree<string> wordsFound;

	// PRIVATE FUNCTIONS

	void findWords(int x, int y);

};
