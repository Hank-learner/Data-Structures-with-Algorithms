#include <iostream>
#include <list>
using namespace std;

class Graph{
	int V;
	list<int> *adj;

	public:
		Graph(int V);
		void addEdge(int v, int w);
        void displaylists();
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

void Graph::displaylists()
{
    for(int i=0;i<V;i++){
        cout<<i<<" -> ";
        while(!adj[i].empty()){
            cout << "  "<<adj[i].front() ;
            adj[i].pop_front();
        }
        cout<<endl;
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

    g.displaylists();
	cout<<endl;
	return 0;
}