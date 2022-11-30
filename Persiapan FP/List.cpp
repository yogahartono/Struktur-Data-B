#include<bits/stdc++.h>
using namespace std;

class graph{
private:
    int V;
    vector<list<int>> adj;  
public:
    graph(int V){
        this->V = V;
        adj.resize(V);
    }
    
    void addVertex(int v, int w){
        adj[v].push_back(w);
    }

        void showVertex()
    {
        for (int i = 1; i <= V; i++)
        {
            cout << i << " => ";
            list<int>::iterator it; // iterator for list
            for (it = adj[i].begin(); it != adj[i].end(); it++)
            {
                cout << *it << " "; // *it is the value of the node/ngeakses pointer nya
            }
            cout << endl;
        }
    }

    void BFS(int s, int d){
        vector<bool> visited;
        visited.resize(V,false);

        list<int> queue;
     
        visited[s] = true;
        queue.push_back(s);
     
        while(!queue.empty()){
            s = queue.front();
            cout << "(V" << s << ")";
            if (s == d) return;
            queue.pop_front();
            for (auto adjecent: adj[s]){
                if (!visited[adjecent]){
                    visited[adjecent] = true;
                    queue.push_back(adjecent);
                }
            }
        }
    }
};


 
int main()
{

    graph graph(21);
    graph.addVertex(1, 2);
    graph.addVertex(1, 3);
    graph.addVertex(1, 5);
    graph.addVertex(1, 16);
    graph.addVertex(2, 8);
    graph.addVertex(2, 15);
    graph.addVertex(3, 4);
    graph.addVertex(3, 14);
    graph.addVertex(5, 6);
    graph.addVertex(5, 13);
    graph.addVertex(6, 7);
    graph.addVertex(7, 14);
    graph.addVertex(8, 9);
    graph.addVertex(8, 17);
    graph.addVertex(9, 11);
    graph.addVertex(10, 12);
    graph.addVertex(10, 17);
    graph.addVertex(11, 15);
    graph.addVertex(11, 20);
    graph.addVertex(13, 18);
    graph.addVertex(16, 20);
    graph.addVertex(18, 19);
    
    graph.BFS(1,12);
    cout << endl;
    graph.showVertex();
 
    return 0;
}
