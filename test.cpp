#include <iostream>
#include <string>
#include <set>

using namespace std;



int main(){
	set<int> a;
	a.insert(1);
	a.erase(a.find(1));
	for(auto iter = a.begin();iter!=a.end();iter++){
		cout<<*iter;
	}
}