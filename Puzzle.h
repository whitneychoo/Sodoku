// Whitney Choo
// Puzzle interface (.h) file

#include <fstream>
#include <iostream>
#include <vector> 
#include <cstring>
using namespace std;

template <typename T>
class Puzzle {
	public:
	Puzzle();			//constructor
	
	private:
	vector<T> vec;			
	vector <vector <T> > sodoku;	// 2D vector
};

// constructor
template <typename T>
Puzzle<T>::Puzzle(){
	string fileName;
	int value;
	cout << "Please enter a file name: ";
	cin >> fileName;

/*	ifstream inFile;
	inFile.open (fileName);
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 0; j++){
			infile >> value;
			Sodoku[i][j] = value;
	}
*/}
