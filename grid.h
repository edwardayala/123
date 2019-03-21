//grid.h file
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#ifndef _GRID
#define _GRID

#define NUM_CELLS  50			//Total number of cells if placed randomly
#define LIVE_IMAGE 'O'			//Image for live cells
#define DEAD_IMAGE '-'			//Image for dead cells
#define NUM_RUNS 15				//The number of runs (generation) to run the simulation
#define NUM_DISPLAY 1			//How frequently to print the grid with cells

//Predeclaration
class Grid;

//Coordinates of a cell (square)
class Coordinate
{
public:
	//Constructors
    Coordinate(){ _x = 0; _y = 0; }
	Coordinate(int x, int y){ _x = x; _y = y; }

	~Coordinate(){}

	int getX() {return _x;}
	int getY() {return _y;}
	void setX( int anX ){ _x = anX; }
	void setY( int aY ){ _y = aY; }

private:
	int _x;
	int _y;
};

//A living thing that serves the parent class of Cell class 
class Square
{
public:
	Square( Grid * aGrid, Coordinate * aCoord);
	~Square();

	Grid * getGrid();
	Coordinate * getCoordinate();
	
	//Virtual functions for dynamic binding
    virtual bool getLiveInfo();
	virtual char getImage();
	virtual void setImage(char);
	virtual void print();
	virtual void update();
	
private:
	Grid * _grid;			//The grid where this square lives on 
	Coordinate * _coord;	//Coordinates of this square 
};

//Cell class (child class of Square class)
class Cell : public Square
{
public:
	Cell( Grid * aGrid, Coordinate * aCoord, char aImage, int f );
	char getImage();
	void setImage(char);
	bool getLiveInfo();
	void setLiveInfo(bool);
	int countLiveNeighbors();
	void resetLifeSpan();
	void incrementLiveSpan();
	void update();
	void print();

private:
	char _image;	//For example: cell: O, square: -
	int _lifeSpan;  //The number of generations this cell has lived
	bool _toBeLive; //True if this cell will be live next generation
};

//A 2D grid where squares (cells) live on
class Grid
{
public:
    Grid(int ** states, int r, int c);
    ~Grid();

	void run();
    void display();
    void getStats();
	int getRows();
	int getCols();
	Square * getSquare(int x, int y);

private:
	int rows;			  //The number of rows of this grid
	int cols;			  //The number of columns of this grid
	Square *** _squares;  //A 2D array of pointers to squares (parent class of cells)
};


#endif