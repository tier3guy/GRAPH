#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;

class graph{
	map<int , list<int>> l;
public:
	void addEdge(int x,int y){
		l[x].push_back(y);
		l[y].push_back(x);
	}

	void bfs(int src){
		queue<int> q;
		map<int,bool> visited;

		q.push(src);
		visited[src] = true;

		while(!q.empty()){
			int node = q.front();
			q.pop();
			cout << node << " ";
			for(auto nbr : l[node]){
				if(visited[nbr] != true){
					q.push(nbr);
					visited[nbr] = true;
				}
			}
		}cout << endl;
	}
};

int main(){

	graph g;
	g.addEdge(1,2);
	g.addEdge(1,0);
	g.addEdge(3,2);
	g.addEdge(0,3);
	g.addEdge(3,4);

	g.bfs(0);

	return 0;
}