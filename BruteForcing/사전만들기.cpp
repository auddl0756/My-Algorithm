#include <bits/stdc++.h>

using namespace std;
#define pii pair<int,int> 
typedef long long ll;

//x+y�����̸�, 2������  ���ڷ� ������  ��� ����� �� (��������)  ������. ������ ��� 
void generate2(int x,int y,string s){
	if(x==0 && y==0){
		cout<<s<<"\n"; return;
	}
	
	if(x>0) generate2(x-1,y,s+'0');		//���������� ���� ���ڸ� ���� �� ȣ���ؼ� x���� ���ÿ� �׾� ����   
	if(y>0) generate2(x,y-1,s+'1');		//���������� ���� ���ڴ�  ���� ���ʿ� �ִ� �͵���� �ϳ��� ���ϵǸ� �� �ϳ����� y���� ������   
}

//x+y+z�����̸� 3������ ���ڷ� ������ ��� ����� �� ������. ������ ���  
void generate3(int x,int y,int z,string s){
	if(x==0 && y==0 && z==0){
		cout<<s<<"\n"; return;
	}
	if(x>0) generate3(x-1,y,z,s+'x');
	if(y>0) generate3(x,y-1,z,s+'y');
	if(z>0) generate3(x,y,z-1,s+'z');
}


int main(){
	//ios_base::sync_with_stdio(false); cin.tie(0); 
	int x,y,z; cin>>x>>y>>z; string s="";
	generate2(x,y,s);
	//generate3(x,y,z,s);
}
