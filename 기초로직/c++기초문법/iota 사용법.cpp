#include <iostream>
#include <vector> 
#include <numeric>

#define all(a) a.begin(),a.end()
using namespace std;

int main(){
	vector<int> a(10);
	iota(all(a),0);
	for(int aa:a) cout<<aa<<" "; cout<<'\n';
	
}
