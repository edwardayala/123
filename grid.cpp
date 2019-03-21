//grid.cpp file
#include "grid.h"

//Grid Constructor
Grid::Grid(int ** states, int r, int c)
{
	rows = r;
	cols = c;

	//Create a 2D array of pointers to squares
	_squares = new  Square ** [rows];

	for( int i=0; i < rows; i++)
	{
		_squares[i] = new Square * [cols];
	}

	//For each position (i, j) on the grid, add a cell
	for ( int i = 0; i < rows; i++ )
		for ( int j = 0; j < cols; j++ )
		{
			// To be completed
		}
}

//Destructor
Grid::~Grid()
{
	for ( int i = 0; i < rows; i ++ )
		for ( int j = 0; j < cols; j ++)
			// To be completed
}

//Start running the simulation
void Grid::run()
{
	//Run the simulation generation by generation
	for ( int n = 1; n <= NUM_RUNS; n ++)
	{
		//Update states of cells on the grid
		for ( int i = 0; i < rows; i ++ )
			for ( int j = 0; j < cols; j ++)
				// To be completed
				
		//Update the images of cells based whether or not cells will be live.
		// To be completed
		
		//Display grid every NUM_DISPLAY generations
		if ( n%NUM_DISPLAY == 0 )
		{
			cout << "\nRuns = " << n << endl;
			display();
			getStats();
			cout << endl;
		}
	}
}

//Display all cells on the grid
void Grid::display()
{
	//Print the images of cells on the grid
	for ( int i = 0; i < rows; i ++ )
	{
		for ( int j = 0; j < cols; j ++)
			_squares[i][j]->print();

		cout << endl;
	}
}

//Get statistics of the cells on the grid
void Grid::getStats()
{
	int numLiveCells = 0;
	int numDeadCells = 0;

	for ( int i = 0; i < rows; i ++ )
		for ( int j = 0; j < cols; j ++)
		{
			// To be completed
		}

	cout << "The number of live cells = " << numLiveCells << endl;
	cout << "The number of dead cells = " << numDeadCells << endl;
	cout << "Total cells = " << numLiveCells + numDeadCells << endl;
}

int Grid::getRows() 
{
	return rows;
}

int Grid::getCols() 
{
	return cols;
}

//Given a location (x, y), return the square object
Square * Grid::getSquare(int x, int y)
{
    return _squares[x][y];
}

//Square Constructor
Square::Square( Grid * aGrid, Coordinate * aCoord)
{
	// To be completed
}

//Destructor
Square::~Square()
{
}

//This function will be overwritten by update() in a child class (Cell)
void Square::update()
{ 
	cout << "Square update() is being called ...";
}

Grid * Square::getGrid()
{
	return _grid;
}

Coordinate * Square::getCoordinate()
{
    return _coord;
}

//This function will be overwritten by getLiveInfo() in a child class (Cell)
bool Square::getLiveInfo()
{ 
	cout << "Square getImage() is being called ...";
    return false;
}

char Square::getImage()
{
	cout << "Square getImage() is being called ...";
	return ' ';
}

void Square::setImage(char img)
{
	cout << "Square setImage is being called ...";
}


void Square::print()
{
	cout << "Square print() is being called ...";
}

//Cell constructor. Initializer will be used to initialize the parent part
Cell::Cell( Grid * aGrid, Coordinate * aCoord, char aImage, int f ) // Initializer here 
{
	// To be completed
}

bool Cell::getLiveInfo()
{
    return _toBeLive;
}

char Cell::getImage()
{
    return _image;
}

void Cell::setImage(char img)
{
    _image = img;
}

//Print out the image of this cell
void Cell::print()
{
	cout << _image << " ";
}

void Cell::setLiveInfo(bool lf)
{
	_toBeLive = lf;
}

//When a cell becomes dead, _lifeSpan will be reset to zero
void Cell::resetLifeSpan()
{
    _lifeSpan = 0;
}

//If a cell continues to be live, _lifeSpan will increment by one
void Cell::incrementLiveSpan()
{
    _lifeSpan++;    
}

//Count how many live cells among the eight neighbors using the rules
int Cell::countLiveNeighbors()
{
	Square * s;
	Coordinate * coord = this->getCoordinate();
	
	int num = 0;
	int x;
	int y;
	Grid * g = getGrid();
	int rows = g->getRows();
	int cols = g->getCols();
   
	// To be completed

	return num;
}

//Based on the number of live neighbor cells, update the state of each cell
//for next generation (run) using the rules
void Cell::update()
{
	int liveNeighbors = countLiveNeighbors();

	//Rule #2
	//Rule #3
	//Rules #1 and #4
	
	// To be completed
}