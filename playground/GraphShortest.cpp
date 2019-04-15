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

pair<stack<int>, double> getShortestRoute(int iStart, int iEnd, vector<Node>& database)
{
  pair<stack<int>, double> result;
  list<pair<int, double> >::iterator it; // to iterate over neighbors
  int nuc;// node under consideration

  for (int i = 0; i < database.size(); i++)// for all nodes
  {
	  database[i].cost = 0;// set cost to zero
	  database[i].prev = -1;// set prev to -1
	  database[i].isVisited = false;// mark all as not visited
  }

  queue<int> toDoList;// create a queue of ints to store the "to-do" list
  database[iStart].isVisited = true;// mark start node as "visited"
  toDoList.push(iStart);// push it onto the "to-do" list
  while (!toDoList.empty())
  {
	  nuc = toDoList.front();// peek the node's index fromt the to do list
	  toDoList.pop();// pop the node
	  for (it = database[nuc].neighbors.begin(); it != database[nuc].neighbors.end(); ++it)// for each of that node's neighbors
	  {
		  if (database[it->first].isVisited) continue;// if neighbor has been visited, continue
		  database[it->first].cost = database[nuc].cost + 1;// set neighbor's cost to cost of node under consideration + 1
		  database[it->first].prev = nuc;// set the previous node to node under consideration
		  toDoList.push(it->first);// push neighbor to the to-do list
		  database[it->first].isVisited = true;// mark the neighbor visited
		  if (it->first == iEnd)// if the neighbor is the end
		  {
			  toDoList.empty();// empty the to do list
			  break;// finish
		  }
	  }
  }

  result.second = database[iEnd].cost;// the route's cost equals the end node's cost
  int tracer = iEnd;// use tracer to trace back the shortest route
  for (int i = 0; i < result.second + 1; i++)// for the cost+1 times
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