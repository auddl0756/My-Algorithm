#include <iostream>
#include <map>
using namespace std;

int main(){
	multimap<string,int> mp;
	//map 과 달리 operator [] 를 사용해서 원소 (pair<key, value>)를 추가 또는 수정이 불가능.
	mp.insert({"a",1});
	mp.insert({"a",2});
	mp.insert({"bb",4});
	mp.insert({"aa",3});
	
	

	//key 기준으로 정렬되서 저장되어 있음. 
	for(auto x:mp){
		cout<<x.first<<" "<<x.second<<'\n'; 
	}
	
	
	cout<<mp.find("a")->first<<" "<<mp.find("a")->second<<'\n';
	cout<<(++mp.find("a"))->first<<" "<<(++mp.find("a"))->second<<'\n';
	
	
	multimap<string,int>::iterator it = mp.find("aa");
	//mp.erase(it);
	mp.erase(mp.find("aa"));
	
	
	 
}
