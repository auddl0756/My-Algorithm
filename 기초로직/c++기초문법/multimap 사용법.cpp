#include <iostream>
#include <map>
using namespace std;

int main(){
	multimap<string,int> mp;
	//map �� �޸� operator [] �� ����ؼ� ���� (pair<key, value>)�� �߰� �Ǵ� ������ �Ұ���.
	mp.insert({"a",1});
	mp.insert({"a",2});
	mp.insert({"bb",4});
	mp.insert({"aa",3});
	
	

	//key �������� ���ĵǼ� ����Ǿ� ����. 
	for(auto x:mp){
		cout<<x.first<<" "<<x.second<<'\n'; 
	}
	
	
	cout<<mp.find("a")->first<<" "<<mp.find("a")->second<<'\n';
	cout<<(++mp.find("a"))->first<<" "<<(++mp.find("a"))->second<<'\n';
	
	
	multimap<string,int>::iterator it = mp.find("aa");
	//mp.erase(it);
	mp.erase(mp.find("aa"));
	
	
	 
}
