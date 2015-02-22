// Whitney Choo
// Puzzle interface (.h) file

#include <fstream>
#include <iostream>
#include <vector> 
#include <cstring>
#include <string>
using namespace std;

template <typename T>
class Puzzle {

	public:
	Puzzle();			//constructor
	
	private:
	vector<T> vec;			
	vector <vector <T> > Sodoku;	// 2D vector
};

// constructor
template <typename T>
Puzzle<T>::Puzzle(){
	vector<T> tempVec;
	string fileName;
	int value;

	cout << "Please enter a file name: ";
	cin >> fileName;

	ifstream inFile;
	inFile.open(fileName.c_str());

	while(!inFile.eof()){
		for(int i = 0; i < 9; i++){
			inFile >> value;
			tempVec.push_back(value);
		}
		Sodoku.push_back(tempVec);
		tempVec.clear();
	}		

}
