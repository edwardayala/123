// main.cpp file
// ******************************************************************************************* //
// This program simulates a classic problem called Game of Life by Conway.
// There are two ways to get initial states of cells: a fixed pattern and random pattern
// The main is written by Yukong Zhang, April 6, 2016 (last modified)
// ******************************************************************************************* //

#include "grid.h"

void getInitialStates(string, int &, int &, int ** &); //For a fixed initial pattern
void getInitialStates(int, int, int ** &);			   //For a random pattern.

int main ()
{
	int rows, cols;				//Rows and columns of the grid
	int ** initStates = NULL;	//Initial cell states

	//For a fixed pattern
	string inputFileName;		//The file name containing initial states
	cout << "Enter the input file name for initial cell states on a grid: " << endl;
	cin >> inputFileName;
	getInitialStates(inputFileName, rows, cols, initStates);
	
	//For a random pattern
	//rows = 20;
	//cols = 20;
	//getInitialStates(rows, cols, initStates);

    Grid * gd = new Grid(initStates, rows, cols);
	
	gd->display();		//Display cells
	gd->getStats();		//Get stats of cells on a grid
	gd->run();			//Start running the simulation

	delete gd;			//Delete the grid object

	return 0;
}

//The first parameter "fileName" is the input file name containing initial states of cells. 
//The first line in the file contains rows and columns of a grid. The remaining lines contain the states represented by 
//1s meaning live and 0s dead.
//This function takes an input file name, "return" rows, columns and initial states through passing by reference.
void getInitialStates(string fileName, int & rows, int & cols, int ** & states)
{
	ifstream inData;
	inData.open(fileName);
	
	if(!inData)
	{
		cout << "The input file doesn't exist!" << endl;
		return ;
	}

	inData >> rows >> cols;

	//Create a 2D array for initial states of cells
	states = new  int * [rows];

	for( int i=0; i < rows; i++)
	{
		states[i] = new int[cols];
	}

	//Read initial states from the input file
	for ( int i = 0; i < rows; i++ )
		for ( int j = 0; j < cols; j++ )
		{
			inData >> states[i][j];
		}
}

//If we wanted to add cells on grid randomly, use the following function to generate cell states.
void getInitialStates(int rows, int cols, int ** & states)
{
	//Create a 2D array for initial states of cells
	states = new  int * [rows];

	for( int i=0; i < rows; i++)
	{
		states[i] = new int[cols];
	}

	//For each position (i, j) on the grid, specify the state for the cell, that is, live (1) or dead (0)
	for ( int i = 0; i < rows; i++ )
		for ( int j = 0; j < cols; j++ )
		{
			//The number of cells on grid is pre-specified by a constant NUM_CELLS. First calculate percentage of live cells.
			//Use that percentage to determine whether or not next cell would be live
			//Use a random generator to generate a random number and limit it to a range from 0 to 100
			//For example, we want 80 live cells on a grid of 400 squares. The percentage of live cells would be 20%.
			//If a random number generated is greater than 80, the cell to be generated would be live,
			//otherwise dead. This way we can control to generate 20% live cells approximately.

			if (rand()%100 <= 100 * NUM_CELLS/(rows*cols))
				states[i][j] = 1;
			else
				states[i][j] = 0;	
		}	
}