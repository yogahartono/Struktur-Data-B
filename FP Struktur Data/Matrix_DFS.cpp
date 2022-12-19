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

class Graph {
    protected:
        int v;
        vector<string> place;
        vector<vector<int>> adj;
        vector<int> dfsResult;
        vector<int> dijkstraRes;
        int dfsWeight;

    public:
        Graph(int len) {
            v = len;
            place.assign(v+1, "");
            vector<int> l (v+1, -1);
            adj.assign(v+1, l);
            dfsResult.assign(v+1, 0);
            vector<int> vec (v+1, 0);
        }

        void addEdge(string i, int u, int v, int w){
            adj[u][v] = w;
           place[v] = i;
        }

        void showGraph(){
            for (int i = 1; i <= v; i++)
            {
                for ( int j = 1; j <= v; j++)
                {
                    if(adj[i][j] == -1) cout << ".  ";
                    else if (adj[i][j] < 10) cout << adj[i][j] << "  ";
                    else cout << adj[i][j] << " ";

                }
                cout << endl;
            }
        }

        void DFS(int start, int end){
            cout << endl;
            cout << "## Shortest path using DFS" << endl;
            dfsWeight = INT_MAX;
            vector<int> path;
            vector<bool> visited (v+1, false);
            solveDFS(start, end, path, visited, 0 );

            for (int i = 0; i < dfsResult.size(); i++)
            {
                cout << dfsResult[i] << " ";
            }

            cout << endl << "Weight = " << dfsWeight << endl;
        }

        void solveDFS(int start, int end, vector<int> path, vector<bool> visited, int currWeight){
            if(start == end) {
                path.push_back(end);
                if(currWeight < dfsWeight ) {
                    dfsWeight = currWeight;
                    dfsResult = path;
                }
                cout << currWeight << " ";
                for (int i = 0; i < path.size(); i++)
                {
                    cout <<  path[i] << " ";
                }
                cout << endl;
            }
            visited[start] = true;
            path.push_back(start);
            for ( int it = 1; it <= v; it++)
            {
                if(!visited[it] && adj[start][it] != -1){
                    int wtemp = currWeight;
                    wtemp += adj[start][it];
                    solveDFS(it, end, path, visited, wtemp);
                }
            }
        }
};

int main(){
    Graph graph(20);
	graph.addEdge("Rumah", 1, 1, 1);
	graph.addEdge("Alfamart", 1, 2, 3);
	graph.addEdge("Lapangan Komplek", 1, 3, 2);
    graph.addEdge("Coffeshop Makuta", 1, 5, 6);
    graph.addEdge("Citra Buana Residence", 1, 16, 5);
	graph.addEdge("Alfamart", 2, 2, 2);
	graph.addEdge("Hotel Alana", 2, 8, 8);
	graph.addEdge("BBQ Grill", 2, 15, 9);
	graph.addEdge("Lapangan Komplek", 3, 3, 3);
	graph.addEdge("Kost", 3, 4, 4);
	graph.addEdge("Kost", 4, 4, 4);
	graph.addEdge("Coffeeshop Makuta", 5, 5, 5);
	graph.addEdge("Kampus Poltekkes", 5, 6, 10);
	graph.addEdge("JNE Solo", 5, 13, 12);
	graph.addEdge("Kampus Poltekkes", 6, 6, 6);
	graph.addEdge("Toko Tembakau", 6, 7, 13);
	graph.addEdge("Toko Tembakau", 7, 7, 7);
	graph.addEdge("Coffeeshop Nilu", 7, 14, 17);
	graph.addEdge("Hotel Alana", 8, 8, 8);
	graph.addEdge("Kantor Solopos", 8, 9, 13);
	graph.addEdge("Kantor Imigrasi", 8, 17, 10);
	graph.addEdge("Kantor Solopos", 9, 9, 9);
	graph.addEdge("Hotel Lorin", 10, 10, 10);
	graph.addEdge("SPBU Pertamina", 10, 12, 18);
	graph.addEdge("Coffeeshop Babrak", 11, 11, 11);
	graph.addEdge("SPBU Pertamina", 12, 12, 12);
	graph.addEdge("JNE Solo", 13, 13, 13);
	graph.addEdge("Toko Cat", 13, 18, 14);
	graph.addEdge("Coffeeshop Nilu", 14, 14, 14);
	graph.addEdge("Coffeeshop Babrak", 15, 11, 13);
	graph.addEdge("Citra Buana Residence", 16, 16, 16);
	graph.addEdge("Lapangan Voli", 16, 20, 11);
	graph.addEdge("Kantor Imigrasi", 17, 17, 17);
	graph.addEdge("Hotel Lorin", 17, 10, 16);
	graph.addEdge("Toko Cat", 18, 18, 18);
	graph.addEdge("Ayam Goreng", 18, 19, 22);
	graph.addEdge("Ayam Goreng", 19, 19, 19);
	graph.addEdge("Lapangan Voli", 20, 20, 20);
    graph.showGraph();
    int start, end;
    cin >> start >> end;
    graph.DFS(start, end);

}