#include <iostream>
using namespace std;

#include <cstdlib>

struct cell
{
  int row; // any +/0/- value
  int col; // any +/0/- value
};
bool operator<(const cell& a, const cell& b) { return (1009*a.row + a.col < 1009 * b.row + b.col); }

#include <map>

map<cell, char> grid; // Older grid of life
map<cell, char> newGrid; // New grid for storing the next generation

//Dimensions of the grid with the origin at the center
const int MINROW = -25;
const int MAXROW = 25;
const int MINCOL = -35;
const int MAXCOL = 35;

int neighborCount(int row, int col)
{
  //Count neighboring living cells around cell at row and col
  cell temp;
  int count = 0;
  for (temp.row = row - 1; temp.row <= row + 1; temp.row++)
    for (temp.col = col - 1; temp.col <= col + 1; temp.col++)
      if (temp.row != row || temp.col != col)
        if (grid.find(temp) != grid.end())
          ++count;
  return count;
}

void initialize()
{
  //Output instructions
  cout << "List the coordinates for living cells.\n";
  cout << "Terminate the list with a special pair -1 -1\n";

  //Get input for storing living cells
  cell temp;
  char buf[100];
  while (true)
  {
    cin >> buf; temp.row = atoi(buf);
    cin >> buf; temp.col = atoi(buf);
    if (temp.row == -1 && temp.col == -1) break;
    grid[temp] = 'X';
  }
  cin.ignore();
}

void print()
{
  //Output the grid at the current generation
  cell temp;
  cout << "\nThe current Life configuration is:\n";
  
  //Nested for loop to print the grid
  for (temp.row = MINROW; temp.row <= MAXROW; temp.row++)
  {
    for (temp.col = MINCOL; temp.col <= MAXCOL; temp.col++)
      if (grid.find(temp) != grid.end())
        cout << grid[temp];
      else
        cout << ' ';
    cout << endl;
  }
  cout << endl;
}

void update()
{
  //Calculate new generation
  cell temp;
  newGrid.clear();
  
  //Nested for loops to traverse the grid
  for (temp.row = MINROW; temp.row <= MAXROW; temp.row++)
  {
    for (temp.col = MINCOL; temp.col <= MAXCOL; temp.col++)
    {
      //Process cells based on number of neighbors
      switch (neighborCount(temp.row, temp.col))
      {
        //If 2 neighbors, cell lives (copy old cell to next gen grid)
        case 2:
          if (grid.find(temp) != grid.end()) newGrid[temp] = 'X';
          break;
        //Cell with 3 neighbors lives next generation
        case 3:
          newGrid[temp] = 'X';
          break;
      } //switch - process cells based on number of neighbors
    } //for - traverse columns of grid
  } //for - traverse rows

  //Update grid
  grid = newGrid;    
};

int main()
{
  //Prep and output grid for zeroth generation
  initialize();
  print();

  //Game loop cycle
  for (int i = 1; grid.size(); i++)
  {
    //Prompt user for continuing (any normal keyboard character) or quitting (hitting enter)
    cout << "Generation " << i << ". Press ENTER to continue, X-ENTER to quit...\n";
    if (cin.get() > 31) break;
    
    //Process the grid and output the current generation
    update();
    print();
  }
} //main