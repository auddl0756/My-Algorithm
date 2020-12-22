#include <iostream>
#include <set>

using namespace std;


void print(multiset<int> ms){	//출력 
	for(auto x:ms) cout<<x<<" "; cout<<'\n';
	
	//iterator이용해서 출력하는 방법. 
	//multiset<int>::iterator it;
	//for(it=ms.begin();it!=ms.end();it++) cout<<*it<<" "; cout<<"\n";	
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	//set과 구별되는 multiset의 가장 큰 특징은 key값이 중복된다
	//나머지는 set과 동일 
	//<set> header 안에 있다 
	//정렬된 상태 유지하니까 pq상위 호환인데? 최소,최대 한번에 구할수 있고 삽입도 정렬된 상태로 되니까 
	
	multiset<int> ms;
	ms.insert(6);
	ms.insert(1);
	ms.insert(1);
	ms.insert(3);
	
	//front 출력. 
	cout<<*ms.begin()<<"\n";	
	
	//back 출력. 
	auto it=ms.end();
	it--;
	cout<<*it<<'\n';
	
	//front 제거
	ms.erase(ms.begin());
	print(ms);
	
	//back 제거
	ms.erase(it);
	print(ms);
	
	cout<<ms.count(1)<<"\n";	//key값이 몇개 들어 있는지 	
 
	
	
	


	
}




//[note]
// 1.뭔말인지 이해
// 2.목표는? 
// 3.이다아니다/단순화/결국엔 
// 4.하란대로 해보기
// 5.why this works
// 6.long long/시간 


