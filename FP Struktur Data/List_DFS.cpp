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
        vector<list<int>> adj;
        map<pair<int,int>, int> weight;
        vector<int> dfsResult;
        int dfsWeight;
        vector<int> dijkstraRes;

    public:
        Graph(int len) {
            v = len;
            place.assign(v+1, "");
            list<int> l;
            adj.assign(v+1, l);
            dfsResult.assign(v+1, 0);
            vector<int> vec (v+1, 0);
        }

        void addVertex(string i, int u, int v, int w){
            adj[u].push_back(v);
            weight.insert({make_pair(u,v), w});
            place[v] = i;
        }

        void showGraph(){
            for (int i = 1; i <= v; i++)
            {
                list<int>::iterator it;
                cout << i << " => ";
                for (it = adj[i].begin(); it != adj[i].end(); it++)
                {
                    cout << *it << "(" << weight[make_pair(i, *it)] << ") ";
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
            list<int>::iterator it;
            for ( it = adj[start].begin(); it != adj[start].end(); it++)
            {
                if(!visited[*it]){
                    int wtemp = currWeight;
                    wtemp += weight[make_pair(start, *it)];
                    solveDFS(*it, end, path, visited, wtemp);
                }
            }
        }
};

int main(){
    Graph graph(20);
	graph.addVertex("Rumah", 1, 1, 1);
	graph.addVertex("Alfamart", 1, 2, 3);
	graph.addVertex("Lapangan Komplek", 1, 3, 2);
    graph.addVertex("Coffeshop Makuta", 1, 5, 6);
    graph.addVertex("Citra Buana Residence", 1, 16, 5);
	graph.addVertex("Alfamart", 2, 2, 2);
	graph.addVertex("Hotel Alana", 2, 8, 8);
	graph.addVertex("BBQ Grill", 2, 15, 9);
	graph.addVertex("Lapangan Komplek", 3, 3, 3);
	graph.addVertex("Kost", 3, 4, 4);
	graph.addVertex("Kost", 4, 4, 4);
	graph.addVertex("Coffeeshop Makuta", 5, 5, 5);
	graph.addVertex("Kampus Poltekkes", 5, 6, 10);
	graph.addVertex("JNE Solo", 5, 13, 12);
	graph.addVertex("Kampus Poltekkes", 6, 6, 6);
	graph.addVertex("Toko Tembakau", 6, 7, 13);
	graph.addVertex("Toko Tembakau", 7, 7, 7);
	graph.addVertex("Coffeeshop Nilu", 7, 14, 17);
	graph.addVertex("Hotel Alana", 8, 8, 8);
	graph.addVertex("Kantor Solopos", 8, 9, 13);
	graph.addVertex("Kantor Imigrasi", 8, 17, 10);
	graph.addVertex("Kantor Solopos", 9, 9, 9);
	graph.addVertex("Hotel Lorin", 10, 10, 10);
	graph.addVertex("SPBU Pertamina", 10, 12, 18);
	graph.addVertex("Coffeeshop Babrak", 11, 11, 11);
	graph.addVertex("SPBU Pertamina", 12, 12, 12);
	graph.addVertex("JNE Solo", 13, 13, 13);
	graph.addVertex("Toko Cat", 13, 18, 14);
	graph.addVertex("Coffeeshop Nilu", 14, 14, 14);
	graph.addVertex("Coffeeshop Babrak", 15, 11, 13);
	graph.addVertex("Citra Buana Residence", 16, 16, 16);
	graph.addVertex("Lapangan Voli", 16, 20, 11);
	graph.addVertex("Kantor Imigrasi", 17, 17, 17);
	graph.addVertex("Hotel Lorin", 17, 10, 16);
	graph.addVertex("Toko Cat", 18, 18, 18);
	graph.addVertex("Ayam Goreng", 18, 19, 22);
	graph.addVertex("Ayam Goreng", 19, 19, 19);
	graph.addVertex("Lapangan Voli", 20, 20, 20);
    graph.showGraph();

    int start, end;
    cin >> start >> end;
    graph.DFS(start, end);


}