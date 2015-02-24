// Whitney Choo
// Main file for Sodoku

#include "Puzzle.h"
using namespace std;

int main() {

	Puzzle<int> puzzle("puzzle.txt");
	puzzle.play();

	return 0;
}
