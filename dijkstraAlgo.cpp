#include<iostream>
#include<map>
#include<list>
#include<set>
#include<climits>
using namespace std;


template<typename T>
class Graph{
	map<T,list<pair<T,int>>> M;
public:
	void addEdge(T src , T dest , bool bidirec, int wt){
		if(bidirec){
			M[src].push_back(make_pair(dest,wt));
			M[dest].push_back(make_pair(src,wt));
		}
		else{
			M[src].push_back(make_pair(dest,wt));
		}
	}

	void printAdj(){
		for(auto node : M){
			cout << node.first << " -> ";
			for(auto nbr : node.second){
				cout << "(" << nbr.first << " " << nbr.second << ") ";
			}cout << endl;
		}
	}

	void dijkstraAlgo(T src){
		map<T,int> distance;
		for(auto j : M){
			distance[j.first] = INT_MAX;
		}
		distance[src] = 0;

		set<pair<int,T>> s;
		s.insert(make_pair(0,src));

		while(!s.empty()){
			auto temp = *(s.begin());
			T node = temp.second;
			int nodeDist = temp.first;

			s.erase(s.begin());
			for(auto k : M[node]){
				if(((nodeDist)+ (k.second)) < distance[k.first]){
					
					auto f = s.find(make_pair(distance[k.first],k.first));
					if(f != s.end()){
						s.erase(f);
					}

					distance[k.first] = nodeDist + k.second;
					s.insert(make_pair(distance[k.first],k.first));
				}
			}
		}

		for(auto j : distance){
			cout << j.first << " -> " << j.second << "\n";
		}
	}



};

int main(){

	Graph<int> g;
    g.addEdge(1,2,1,1);
    g.addEdge(1,3,1,4);
    g.addEdge(2,3,1,1);
    g.addEdge(4,3,0,2);
    g.addEdge(1,4,1,7);

	g.dijkstraAlgo(1);

	return 0;
}