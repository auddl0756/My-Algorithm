#include <iostream>
#include <set>

using namespace std;


void print(multiset<int> ms){	//��� 
	for(auto x:ms) cout<<x<<" "; cout<<'\n';
	
	//iterator�̿��ؼ� ����ϴ� ���. 
	//multiset<int>::iterator it;
	//for(it=ms.begin();it!=ms.end();it++) cout<<*it<<" "; cout<<"\n";	
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	//set�� �����Ǵ� multiset�� ���� ū Ư¡�� key���� �ߺ��ȴ�
	//�������� set�� ���� 
	//<set> header �ȿ� �ִ� 
	//���ĵ� ���� �����ϴϱ� pq���� ȣȯ�ε�? �ּ�,�ִ� �ѹ��� ���Ҽ� �ְ� ���Ե� ���ĵ� ���·� �Ǵϱ� 
	
	multiset<int> ms;
	ms.insert(6);
	ms.insert(1);
	ms.insert(1);
	ms.insert(3);
	
	//front ���. 
	cout<<*ms.begin()<<"\n";	
	
	//back ���. 
	auto it=ms.end();
	it--;
	cout<<*it<<'\n';
	
	//front ����
	ms.erase(ms.begin());
	print(ms);
	
	//back ����
	ms.erase(it);
	print(ms);
	
	cout<<ms.count(1)<<"\n";	//key���� � ��� �ִ��� 	
 
	
	
	


	
}




//[note]
// 1.�������� ����
// 2.��ǥ��? 
// 3.�̴پƴϴ�/�ܼ�ȭ/�ᱹ�� 
// 4.�϶���� �غ���
// 5.why this works
// 6.long long/�ð� 


