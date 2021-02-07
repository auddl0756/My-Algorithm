#include <iostream>
#include <numeric>	//std::partial_sum(range of target,begin of result iterator)
#include <vector>
#define all(v) v.begin(),v.end()
using namespace std;

//Compute partial sums of range

int main(){
	vector<int> a={1,2,3,4,5};
	vector<int> res(5);
	partial_sum(all(a),res.begin());
	for(int r:res) cout<<r<<' '; cout<<'\n';
	
}
