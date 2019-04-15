#include <fstream>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <utility>
using namespace std;

#include <cstdlib>

struct Node
{
  string name;

  bool isVisited;
  list<pair<int, double> > neighbors;
  int prev;
  double cost;
};

struct Terminus
{
  int index;
  int prev;
  double cost;
};
bool operator<(const Terminus& a, const Terminus& b) { return b.cost < a.cost; }

pair<stack<int>, double> getShortestRoute(int iStart, int iEnd, vector<Node>& database)
{
  list<pair<int, double> >::iterator it;
  pair<stack<int>, double> result;

  for (int i = 0; i < database.size(); i++)// for all nodes
  {
	  database[i].cost = 0;// set cost to zero
	  database[i].prev = -1;// set prev to -1
	  database[i].isVisited = false;// mark all as not visited
  }

  std::priority_queue<Terminus> toDoList;
  Terminus thisTerminus = { iStart, -1, 0 };
  toDoList.push(thisTerminus);

  while (!toDoList.empty())
  {
	  thisTerminus = toDoList.top();// peek the terminus fromt the to do list
	  toDoList.pop();// pop the terminus
	  if (database[thisTerminus.index].isVisited == true) continue;
	  database[thisTerminus.index].isVisited = true;
	  database[thisTerminus.index].cost = thisTerminus.cost;
	  database[thisTerminus.index].prev = thisTerminus.prev;
	  if (thisTerminus.index == iEnd) break;

	  for (it = database[thisTerminus.index].neighbors.begin(); it != database[thisTerminus.index].neighbors.end(); ++it)// for each of that node's neighbors
	  {
		  if (!database[it->first].isVisited)
		  {
			  Terminus aNeighbor;
			  aNeighbor.index = it->first;
			  aNeighbor.cost = thisTerminus.cost + it->second;
			  aNeighbor.prev = thisTerminus.index;
			  toDoList.push(aNeighbor);
		  }
	  }
  }

  result.second = database[iEnd].cost;// the route's cost equals the end node's cost
  int tracer = iEnd;// use tracer to trace back the shortest route
  while (tracer != -1)// for the cost+1 times
  {
	  result.first.push(tracer);// push the index of the node
	  tracer = database[tracer].prev;// set the node to the previous one
  }

  return result;
}

int main()
{
  cout << "Programmer: Zheyi Wang\n";
  cout << "File: " << __FILE__ << endl;
  
  ifstream fin;
  fin.open("cities.txt");
  if (!fin.good()) throw "I/O error";  

  // process the input file
  vector<Node> database;
  while (fin.good()) // EOF loop
  {
    string fromCity, toCity, cost;

    // read one edge
    getline(fin, fromCity);
    getline(fin, toCity);
    getline(fin, cost);
    fin.ignore(1000, 10); // skip the separator

    // add nodes for new cities included in the edge
    int iToNode = -1, iFromNode = -1, i;
    for (i = 0; i < database.size(); i++) // seek "to" city
      if (database[i].name == fromCity)
        break;
    if (i == database.size()) // not in database yet
    {
      // store the node if it is new
      Node fromNode = {fromCity};
      database.push_back(fromNode);
    }
    iFromNode = i; 

    for (i = 0; i < database.size(); i++) // seek "from" city
      if (database[i].name == toCity)
        break;
    if (i == database.size()) // not in vector yet
    {
      // store the node if it is new
      Node toNode = {toCity};
      database.push_back(toNode);
    }
    iToNode = i; 

    // store bi-directional edges
    double edgeCost = atof(cost.c_str());
    database[iFromNode].neighbors.push_back(pair<int, double>(iToNode, edgeCost));
    database[iToNode].neighbors.push_back(pair<int, double>(iFromNode, edgeCost));
  }
  fin.close();
  cout << "Input file processed\n\n";

  while (true)
  {
    string fromCity, toCity;
    cout << "\nEnter the source city [blank to exit]: ";
    getline(cin, fromCity);
    if (fromCity.length() == 0) break;

    // find the from city
    int iFrom;
    for (iFrom = 0; iFrom < database.size(); iFrom++)
      if (database[iFrom].name == fromCity)
        break;

    cout << "Enter the destination city [blank to exit]: ";
    getline(cin, toCity);
    if (toCity.length() == 0) break;

    // find the destination city
    int iTo;
    for (iTo = 0; iTo < database.size(); iTo++)
      if (database[iTo].name == toCity)
        break;

    cout << "Route";
    pair<stack<int>, double> result = getShortestRoute(iFrom, iTo, database);
    for (; !result.first.empty(); result.first.pop())
      cout << '-' << database[result.first.top()].name;
    cout << "\nTotal edges: " << result.second;  
    cout << endl;
  }

  cout << "Done!" << endl;
  return 0;
}