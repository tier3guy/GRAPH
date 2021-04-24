#include<iostream>
#include<map>
#include<list>
using namespace std;

class Graph{
	map<int,list<int>> l;
public:
	void addEdge(int x,int y){
		l[x].push_back(y);
		l[y].push_back(x);
	}

	bool detect_cycle_helper(int src,map<int,bool> &visited,int parent){
		visited[src] = true;
		for(auto nbr : l[src]){
			if(!visited[nbr]){
				return	detect_cycle_helper(nbr,visited,src);
			}
			else if(visited[nbr] == true && nbr != parent){
				return true;
			}
		}

		return false;
	}

	bool detect_Cycle(int src){
		map<int,bool> visited;
		for(auto temp : l){
			int kyuBhai = temp.first ;
			visited[kyuBhai] = false;
		}

		bool ans = detect_cycle_helper(src,visited,-1);
		return ans;
	}
};

int main(){/*
	Graph g;
	g.addEdge(1,2);
	//g.addEdge(1,3);
	g.addEdge(2,3);
	g.addEdge(3,4);

	cout << g.detect_Cycle(1) << endl;*/
	cout << " Hello World !" << endl;

	return 0;
}
