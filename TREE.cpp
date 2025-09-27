#include<bits/stdc++.h>
using namespace std;

struct Graph{
    int V; //vertex
    vector<vector<int>> adj; //adj list


    //Constructure 
    Graph(int n){
        V = n;
        adj.resize(V);
    }
    //addEdge undirected graph by default
    void addEdge(int u, int v, bool dir = false){
        adj[u].push_back(v);
        if(!dir) adj[v].push_back(u);
    }

    void printGraph() {
        cout << "Graph: \n";
        for (int i = 0; i < V; i++) {
            cout << i << " -> ";
            for (int v : adj[i]) {
                cout << v << " ";
            }
            cout << "\n";
        }
    }

    void BFS(int start){
        vector<bool> visited(V, false);
        queue<int> q;
        vector<int> d(V), p(V); //distance & parent
         

        
        visited[start] = true;
        q.push(start);
        p[start] = -1;

        cout << "BFS: ";
        while(!q.empty()){
            int u = q.front(); q.pop();
            cout << u << " ";
            for(int v: adj[u]){
            	if(!visited[v]){
            		visited[v] = true;
                	q.push(v);
                	
                	d[u] = d[v]+1; //distance updraft
                	p[u] = v; // theier parent
            	}
                
            }

        }
        cout << endl;

    }
	
	
    void DFS(int start){
    	
        static vector<bool> visited(V, false);
        visited[start] = true;
        cout << start << " ";
        
        for(auto v: adj[start]){
           if(!visited[v]){	
            
                DFS(v);
                
            }
        }
    }
};


int main(){
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    g.printGraph();
    g.BFS(0);
    cout << "DFS: ";
    
    g.DFS(0);
    return 0;
}