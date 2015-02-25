// Whitney Choo
// Main file for Sodoku

#include "Puzzle.h"
using namespace std;

int main() {

	Puzzle<int> sudoku("puzzle.txt");
	sudoku.play();

	Puzzle<char> wordoky("wordoky.txt");
	wordoky.play();

	return 0;
}
