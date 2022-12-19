#include <bits/stdc++.h>
#include <iostream>
#include <list>
#include <iterator>
#include <queue>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <map>


using namespace std;

class Graph
{
  int numVertices;
  list<int> *adjMatrix;
  bool *visited;

  public:
    Graph(int vertices);
    void addEdge(int src, int dest);
    void BFS(int startEdaddEdge);
    void showMatrix();
};

Graph::Graph(int vertices)
{
  numVertices = vertices;
  adjMatrix = new list<int>[vertices];
}


void Graph::addEdge(int src, int dest)
{
  adjMatrix[src].push_back(dest);
  adjMatrix[src].sort();
}

void Graph::BFS(int startEdaddEdge)
{
  visited = new bool[numVertices];
  for (int i = 0; i < numVertices; i++)
    visited[i] = false;

  list<int> queue;

  visited[startEdaddEdge] = true;
  queue.push_back(startEdaddEdge);

  list<int>::iterator i;

  while (!queue.empty())
  {
    int currEdaddEdge = queue.front();
  
 
    cout << "(V" << currEdaddEdge << ")";
    queue.pop_front();

    for (i = adjMatrix[currEdaddEdge].begin(); i != adjMatrix[currEdaddEdge].end(); ++i)
    {
      int adjEdaddEdge = *i;
      if (!visited[adjEdaddEdge])
      {
        visited[adjEdaddEdge] = true;
        queue.push_back(adjEdaddEdge);
      }
    }
  }
}

void Graph::showMatrix()
{
  for (int i = 0; i < numVertices; i++)
  {
    list<int>::iterator it;

    int track = 0;
    int through = 0;
    for (it = adjMatrix[i].begin(); it != adjMatrix[i].end(); ++it)
    {

      int temp = *it;
      if (through == 0)
      {
        while (track < temp)
        {
          cout << "0 ";
          ++track;
          through++;
        }
      }
      else
      {
        while ((track + 1) < temp)
        {
          cout << "0 ";
          ++track;
          through++;
        }
      }
      cout << "1 ";
      through++;
    }
    while ((numVertices - through) > 0)
    {
      through++;
      cout << "0 ";
    }
    cout << endl;
  }
}

int main()
{
  Graph graph(22);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 5);
    graph.addEdge(1, 16);
    graph.addEdge(2, 8);
    graph.addEdge(2, 15);
    graph.addEdge(3, 4);
    graph.addEdge(5, 6);
    graph.addEdge(5, 13);
    graph.addEdge(6, 7);
    graph.addEdge(7, 14);
    graph.addEdge(8, 9);
    graph.addEdge(8, 17);
    graph.addEdge(10, 12);
    graph.addEdge(13, 18);
    graph.addEdge(15, 11);
    graph.addEdge(16, 20);
    graph.addEdge(17, 10);
    graph.addEdge(18, 19);

  graph.BFS(1);
  cout << endl;
  graph.showMatrix();

  return 0;
}