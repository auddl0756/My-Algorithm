#include <bits/stdc++.h>

using namespace std;
#define pii pair<int,int> 
typedef long long ll;

//x+y글자이며, 2종류의  글자로 구성된  모든 경우의 수 (순열같은)  만들어내기. 사전순 출력 
void generate2(int x,int y,string s){
	if(x==0 && y==0){
		cout<<s<<"\n"; return;
	}
	
	if(x>0) generate2(x-1,y,s+'0');		//사전순으로 앞인 문자를 먼저 다 호출해서 x개를 스택에 쌓아 놓고   
	if(y>0) generate2(x,y-1,s+'1');		//사전순으로 뒤인 문자는  스택 위쪽에 있는 것들부터 하나씩 리턴되면 그 하나마다 y개씩 돌리고   
}

//x+y+z글자이며 3종류의 글자로 구성된 모든 경우의 수 만들어내기. 사전순 출력  
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
