#include <iostream>
#include <map>
#include <string>

using namespace std;

int t,f;

const string ROOT = "123456789012345678901";

map<string,pair<string,int>> network;

string find(string name){
	string ori = name;
	while(network[name].first != ROOT){
		name = network[name].first;
	}

	string root = name;
	name = ori;
	while(network[name].first !=ROOT){
		ori = name;
		name = network[ori].first;
		network[ori].first = root;
	}
	return name;
}

void Union(string name1, string name2){
	if(network.find(name1) == network.end()){
		network.insert( {name1, {ROOT,1} } );
	}

	string root1 = find(name1);
	int size1 = network[root1].second;
	
	if(network.find(name2) == network.end()){
		network.insert( {name2, {ROOT,1} } );
	}
	string root2 = find(name2);
	int size2 = network[root2].second;
	
	if( root1 == root2 ){
		cout<<network[root1].second<<"\n";
	}
	else{
		network[root1].first = root2;
		network[root2].second = size1+size2;
		cout<<size1+size2<<"\n";
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>t;
	while(t-->0){
		cin>>f;
		network.clear();
		while(f-->0){
			string name1,name2;
			cin>>name1>>name2;
			Union(name1,name2);
		}
	}
	return 0;
}