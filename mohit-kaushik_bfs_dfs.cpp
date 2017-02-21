#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
class Graph
{
	private:
		vector< vector <int> > graph; //2D matrix representation of graph
		vector<int> visited;
	public:
		Graph(int n) //constructer
		{
			graph.resize(n); //assign memory
			visited.resize(n);
		}
		void addEdge(int src,int dest); //add an edge entry in graph matrix representation.
		void dfs(); //depth first search iterative using stack
		void bfs(); //breadth first search iteratively using queue
		void dfsRecursive(int v); //dfs recursively
		void dfsRecursiveAux(); //dfs auxilary function to fill visited vector with 0, will help in disconnected graph.
};
void Graph::addEdge(int src,int dest)
{
	graph[src].push_back(dest);
//	graph[dest].push_back(src);
}
void Graph::bfs()
{
	std::fill(visited.begin(),visited.end(),0); //make all nodes unvisited.
	queue<int> q;
	vector<int>::iterator i;
	for(i=visited.begin();i!=visited.end();i++) //this loop is for disconnected graph.
		if(visited[*i]==false)
		{
			q.push(*i);
			visited[*i]=true;
			while(!q.empty()) //queue will empty when all connected nodes will visit from starting node.
			{
				int v=q.front();
				cout<<v<<" ";
				q.pop();
				vector<int>:: iterator it;
				for(it=graph[v].begin();it!=graph[v].end();it++) //push all connected nodes in queue and make them visited.
					if(visited[*it]==false)
					{
						q.push(*it);
						visited[*it]=true;
					}
			}
		}
}
void Graph::dfs()
{
	std::fill(visited.begin(),visited.end(),0); //make all nodes unvisited.
	stack<int> s;
	vector<int>::iterator i;
	for(i=visited.begin();i!=visited.end();i++)//this loop is for disconnected graph.
		if(visited[*i]==false)
		{
			s.push(*i);
			visited[*i]=true;
			while(!s.empty())//stack will empty when all connected nodes will visit from starting node.
			{
				int v=s.top();
				cout<<v<<" ";
				s.pop();
				vector<int>:: iterator it;
				for(it=graph[v].begin();it!=graph[v].end();it++) //push all connected nodes in stack and make them visited.
					if(visited[*it]==false)
					{
						s.push(*it);
						visited[*it]=true;
					}
			}
		}
}
void Graph::dfsRecursive(int v)
{
	cout<<v<<" ";
	visited[v]=true;
	vector<int>:: iterator it;
	for(it=graph[v].begin();it!=graph[v].end();it++)
		if(visited[*it]==false)
			dfsRecursive(*it);
}
void Graph::dfsRecursiveAux()
{
	std::fill(visited.begin(),visited.end(),0); //make all nodes unvisited.
	vector<int>::iterator it;
	for(it=visited.begin();it!=visited.end();it++) //for disconnectd graph.
		if(visited[*it]==false)
			dfsRecursive(*it);
}
int main()
{
	Graph g1(10);
	g1.addEdge(0,1);
	g1.addEdge(0,2);
	g1.addEdge(1,3);
	g1.addEdge(1,4);
	g1.addEdge(2,5);
	g1.addEdge(4,6);
	g1.addEdge(4,7);
	g1.addEdge(10,11);
	cout<<"\nIterative BFS Output :\n";
	g1.bfs();
	cout<<"\nIterative DFS Output :\n";
	g1.dfs();
	cout<<"\nRecursive DFS Output :\n";
	g1.dfsRecursiveAux();
}

