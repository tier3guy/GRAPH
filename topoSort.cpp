#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;

class graph{
	map<int,list<int>> m;
public:
	void addEdge(int x,int y){
		m[x].push_back(y);
	}

	void topologicalSort(){
		list<int> ans;
		queue<int> q;

		map<int,int> indegree;
		for(auto node : m){
			int temp = node.first;
			indegree[temp] = 0;
		}

		for(auto node : m){
			int temp = node.first;
			for(auto nbr : node.second){
				indegree[nbr] += 1;
			}
		}

		for(auto node : indegree){
			if(node.second == 0){
				q.push(node.first);
			}
		}

		while(!q.empty()){
			int top = q.front();
			q.pop();
			ans.push_back(top);
			for(auto x : m[top]){
				indegree[x] -= 1;
				if(indegree[x] == 0){
					q.push(x);
				}
			}
		}

		for(auto it : ans){
			cout << it << " ";
		}cout << "\n";
	}
};

int main(){
	graph g;
	g.addEdge(1,2);
	g.addEdge(1,4);
	g.addEdge(4,6);
	g.addEdge(2,6);
	g.addEdge(5,6);
	g.addEdge(3,7);
	g.addEdge(2,3);
	g.addEdge(2,5);

	g.topologicalSort();
	return 0;
}
