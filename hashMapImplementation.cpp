#include<iostream>
#include<list>
#include<map>
#include<string>
using namespace std;

class graph{
	map<string,list<pair<string,int>>> l;
public:
	void addEdge(string src,string dst,bool direc,int wt){
		l[src].push_back(make_pair(dst,wt));
		if(direc){
			l[dst].push_back(make_pair(src,wt));
		}
	}

	void print(){
		for(auto src : l){
			cout << "( " << src.first << " )" << " -> ";
			for(auto eachL : src.second){
				cout << "( " << eachL.first << " " << eachL.second << " )" << " , ";
			}cout << endl;
		}
	}
};

int main(){

	graph g;
	g.addEdge("A","B",true,90);
	g.addEdge("A","D",false,50);
	g.addEdge("A","C",true,10);
	g.addEdge("B","D",true,30);
	g.addEdge("C","D",true,40);

	g.print();


	return 0;
}