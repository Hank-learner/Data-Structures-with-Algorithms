#include <iostream>
#include <list>
#include <stack>
using namespace std;

//a graph with v vertices and its adjacency lists
class Graph{
	int V;
	list<int> *adj;
	void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);

	public:
		Graph(int V);
		void addEdge(int v, int w);
		void topologicalSort();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

//functions to check the lists for number of indegree and place it in stack
void Graph::topologicalSortUtil(int v, bool visited[],stack<int> &Stack)
{
	visited[v] = true;

	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			topologicalSortUtil(*i, visited, Stack);

	Stack.push(v);
}

//function to sort one by one calculating indegree till stack is empty
void Graph::topologicalSort()
{
    stack<int> Stack;
    bool *visited = new bool[V];
    	for (int i = 0; i < V; i++)
        	visited[i] = false;

    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            	topologicalSortUtil(i, visited, Stack);
	while (Stack.empty() == false){
		cout << Stack.top() << " ";
		Stack.pop();
	}
}

int main()
{
	Graph g(7);

	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(1, 4);
	g.addEdge(2, 4);
	g.addEdge(3, 4);
	g.addEdge(4, 5);
	g.addEdge(6, 3);

	cout << " topological sorted order : "<<endl;
	g.topologicalSort();
	cout<<endl;
	return 0;
}
