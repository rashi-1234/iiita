#include<bits/stdc++.h> 
using namespace std; 
  
class Graph 
{ 
    int vertices;    // No. of vertices' 
    list<int> *adj; 
  
public: 
    Graph(int vertices);   // Constructor 
    void addEdge(int u, int v); 
    void topologicalSort(); 
}; 
  
Graph::Graph(int vertices) 
{ 
    this->vertices = vertices; 
    adj = new list<int>[vertices]; 
} 
  
void Graph::addEdge(int u, int v) 
{ 
    adj[u].push_back(v); 
} 
  
// The function to do Topological Sort. 
void Graph::topologicalSort() 
{  
    vector<int> in_degree(vertices, 0); 
    for (int u=0; u<vertices; u++) 
    { 
        list<int>::iterator itr; 
        for (itr = adj[u].begin(); itr != adj[u].end(); itr++) 
             in_degree[*itr]++; 
    } 
    queue<int> q; 
    for (int i = 0; i < vertices; i++) 
        if (in_degree[i] == 0) 
            q.push(i); 
  
    // Initialize count of visited vertices 
    int cnt = 0; 
    vector <int> top_order; 
    while (!q.empty()) 
    {  
        int u = q.front(); 
        q.pop(); 
        top_order.push_back(u); 
        list<int>::iterator itr; 
        for (itr = adj[u].begin(); itr != adj[u].end(); itr++) 
  
            // If in-degree becomes zero, add it to queue 
            if (--in_degree[*itr] == 0) 
                q.push(*itr); 
  
        cnt++; 
    } 
  
    // Check if there was a cycle 
    if (cnt != vertices) 
    { 
        cout << "There exists a cycle in the graph\n"; 
        return; 
    } 
  
    // Print topological order 
    for (int i=0; i<top_order.size(); i++) 
        cout << top_order[i] << " "; 
    cout << endl; 
} 
 
int main() 
{ 
    // Create a graph given in the above diagram 
    Graph g(6); 
    g.addEdge(5, 2); 
    g.addEdge(5, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 1); 
  
    cout << "Following is a Topological Sort of\n"; 
    g.topologicalSort(); 
  
    return 0; 
} 

