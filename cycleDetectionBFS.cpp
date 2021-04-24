#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;

class Graph{
	map<int,list<int>> l;
public:
	void addEdge(int x,int y){
		l[x].push_back(y);
		l[y].push_back(x);
	}

	bool detect_Cycle(int src){
		map<int,int> visit;
		for(auto node : l){
			int temp = node.first;
			visit[temp] = -1;
		}

		queue<int> q;
		q.push(src);
		visit[src] = 0;
		while(!q.empty()){
			int toget = q.front();
			q.pop();
			visit[toget] = 1;
			for(auto nbr : l[toget]){
				if(visit[nbr] == 0){
					return true;
				}
				if(visit[nbr] == -1){
					q.push(nbr);
					visit[nbr] = 0;
				}
			}
		}

		return false;
	}
};

int main(){

	Graph g;
	g.addEdge(1,2);
 // g.addEdge(1,3);
	g.addEdge(2,3);
	g.addEdge(3,4);

	cout << g.detect_Cycle(1) << endl;

	return 0;
}