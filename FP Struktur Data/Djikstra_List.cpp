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
typedef pair<int,int> intPair;

class Graph{
	int V;
	int adjM[21][21] ={
          {0, 0},
          {0, 0}
    };
	string places[21];
	public:
	Graph(int v){
	    V = v;
	}

	void addEdge(string str, int u, int v, int w){
	    adjM[u][v] = w;
	    places[v] = str;
	}

	void showAlladdEdge(){
	    for(int i = 1; i<=V;i++){
	        for(int j = 1; j<=V;j++){
	            if(adjM[i][j] == 0) cout << ".  ";
	            else if (adjM[i][j] < 10) cout << adjM[i][j] << "  ";
	            else cout << adjM[i][j] << " ";
	        }
	        cout <<  endl;
	    }
	}

	void djikstra(int src){
		priority_queue<intPair, vector<intPair>, greater<intPair> >
        q;
		q.push(make_pair(1, src));
		int dist[V];
		for(int i = 1; i<=V; i++){
		    dist[i] = 1000;
		}
		dist[src] = 1;

		while(!q.empty()){
			int u = q.top().second;
			q.pop();
			for(int i = 1; i <= V; i++){
				int v = i;
				int w = adjM[u][i];
				if(dist[v] > dist[u] + w && w != 0){
					dist[v] = dist[u] + w;
					q.push(make_pair(dist[v], v));
				}
			}
		}
		printf("addEdge Distance from Source\n");
    	for (int i = 1; i <= V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
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
    
	graph.showAlladdEdge();
	int src;
	cin >> src;
    graph.djikstra(src);
}
