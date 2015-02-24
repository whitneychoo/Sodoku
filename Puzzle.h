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
	Puzzle(string fileName);		// constructor
	void print();				// prints Sodoku
	void play();				// function to play Sodoku
	void checkEmpty(int x, int y);		// checks for emptiness
	int checkValid(int x, int y, T input);	// checks validity
	void add(int x, int y, T input);	// adds piece into board
	int checkWin();				// checks if win
	private:
	vector<T> vec;			
	vector <vector <T> > Sodoku;		// 2D vector
};
// function to check for win
template <typename T>
int Puzzle<T>::checkWin(){
	int i, j, k, count = 0;
	for(i = 0; i < 9; i++){				// if any spots are equal to 0, then it is not game over yet
		for(j = 0; j < 9; j++){
			if(Sodoku[i][j] == 0)
				return 0;			// code to indicate incomplete game
		}
	}
	for(i = 0; i < 9; i++){			
		for(j = 0; j < 9; j++){
			for(k = 0; k < 9; k++){			// check the columns
				if(Sodoku[k][j] == i){
					count++;
					if(count > 1){
						return 1;
					}
				}
			}
			count = 0;
		}			
	}
	for(i = 0; i < 9; i++){			
		for(j = 0; j < 9; j++){
			for(k = 0; k < 9; k++){			// check the rows
				if(Sodoku[j][k] == i){
					count++;
					if(count > 1){
						return 1;
					}
				}
			}
			count = 0;
		}			
	}
	

// function to play Sodoku
template <typename T>
void Puzzle<T>::play(){
	int row, column;
	while(1){
		print();

		cout << "Which row would you like to play your input?: ";
		cin >> row;
		cout << "Which column would you like to play your input?: ";
		cin >> column;

		checkEmpty(row, column);

		}
}
				

// adds piece into board
template <typename T>
void Puzzle<T>::add(int x, int y, T input){
	Sodoku[x][y] = input;
}
// checks if input is valid
template <typename T>
int Puzzle<T>::checkValid(int x, int y, T input){
	int xmod, ymod, m, n;
	for(int i = 0; i < 9; i++){
		if(Sodoku[x][i] == input){						// if there is a piece in the row
			cout << "Error. Already a " << input << " in the row.\n";	// with same value, reject
			return 0;			
		}
	}
	for(int j = 0; j < 9; j++){							// if there is a piece in the column
		if(Sodoku[j][y] == input){						// with same value, reject
			cout << "Error. Already a " << input << " in the column.\n";
			return 0;
		}
	}
	
	xmod = x % 3;				// use the mod as a "code" to determine where the square is
	ymod = y % 3;
	
	switch(xmod){
		case 1: m = x-1;
			break;
		case 2: m = x-2;
			break;
		default: m = x;
			break;
	}
	switch(ymod){
		case 1: n = y-1;
			break;
		case 2: n = y-2;
			break;
		default: n = y;
			break;
	}

	for(int k = m; k < m + 3; k++){					// check the square for same entry
		for(int l = n; l < n + 3; l++){
			if(Sodoku[k][l] == input){
				cout << "Error. Already a " << input << " in the square.\n";
				return 0;
			}
		}
	}

	return 1;	// accept
}

// checks if empty
template <typename T>
void Puzzle<T>::checkEmpty(int x, int y){
	T input;
	if(Sodoku[x-1][y-1] == 0){
		cout << "What value would you like to add?: ";
		cin >> input;
		if(checkValid(x-1, y-1, input)){
			add(x-1, y-1, input);
		}
	} else {
		cout << "That spot is taken."<< endl;
	}
}


// print the Sodoku board
template <typename T>
void Puzzle<T>::print(){
	for(int i = 0; i < 9; i++){
		cout << "-------------------------------------" << endl << "| ";
		for(int j = 0; j < 9; j++){
			if(Sodoku[i][j] == 0){
				cout << "  | ";
			} else {
				
				cout << Sodoku[i][j] << " | ";
			}
		}
		cout << endl;
	}
	cout << "-------------------------------------" << endl << endl;
}

// constructor
template <typename T>
Puzzle<T>::Puzzle(string fileName){
	vector<T> tempVec;
	T value;

	ifstream inFile;			// open the file
	inFile.open(fileName.c_str());

	while(!inFile.eof()){			// while not end of file
		for(int i = 0; i < 9; i++){	// reads in a line
			inFile >> value;	// set value as what is read from inFile
			tempVec.push_back(value);	// put into temporary vector
		}
		Sodoku.push_back(tempVec);		// set sodoku board using temp vector
		tempVec.clear();			// clears the tempVec
	}		
}

