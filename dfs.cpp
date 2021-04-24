#include<iostream>
#include<map>
#include<list>
using namespace std;

class Graph{
	map<int , list<int>> m;
public:
	void addEdge(int x,int y){
		m[x].push_back(y);
		m[y].push_back(x);
	}

	void dfs_helper(int src , map<int , bool> &visited){
		cout << src << " ";
		visited[src] = true;
		for(auto nbr : m[src]){
			if(!visited[nbr]){
				dfs_helper(nbr,visited);
			}
		}
	}

	void dfs(int src){
		map<int,bool> visited;

		for(auto p : m){
			int node = p.first;
			visited[node] = false;
		}

		dfs_helper(src,visited);
	}
};

int main(){

	Graph g;
	g.addEdge(1,2);
	g.addEdge(1,0);
	g.addEdge(3,2);
	g.addEdge(0,3);
	g.addEdge(3,4);
	g.addEdge(4,5);

	g.dfs(0);

	return 0;
}