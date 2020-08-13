#include <bits/stdc++.h>

using namespace std;

#define pii pair<int,int>
#define sorta(a) sort(a.begin(),a.end());
#define rsorta(a) sort(a.rbegin(),a.rend());
#define sorta2(a,n) sort(a,a+n);
#define p(a) for(int i=0;i<a.size();i++)cout<<a[i]<<" ";cout<<"\n";
#define p2(a,n) for(int i=0;i<n;i++)cout<<a[i]<<" ";cout<<"\n";

#define all(v) (v).begin(), (v).end()
#define maxi(a,b,c) max(a,max(b,c))
#define mini(a,b,c) min(a,min(b,c))

typedef long long ll;

// skill.
// from Codeforces Round #606 (Div. 1, based on Technocup 2020 Elimination Round 4)
// https://codeforces.com/blog/entry/72239
// Div1 A. As Simple as One and Two  //  Div2.C

// *************** WOW *********************************************
// Note that it is important to delete the middle letters in the last two paragraphs
// to avoid appearing a new occurrence after a line is collapsed.
// *****************************************************************

// str.find() method useage
// maybe O(N) time complexity..
// useage ::  검색대상 문자열.find(검색할 문자열)  ==>처음  찾은 문자열의 시작 인덱스를 반환. 
// useage2 :: 검색대상 문자열.find(검색할 문자열, 검색 시작 인덱스) 
// npos is a constant static member value with the greatest possible value ,means "until the end of the string".  
// maybe implication of "end possible or end position".

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s="onetwothree onetwothree";
	
	(s.find("one")==string::npos) ? cout<<"not exist\n" : cout<<"exist\n";
	cout<<s.find("one")<<"\n";
	cout<<s.find("one",3)<<"\n";
	
	int pos=0;
	for(;(pos=s.find("one",pos))!=string::npos;){	//search all "one" in string s.
		//cout<<pos<<"\n";
//		string searched(s.begin()+pos,s.begin()+pos+3);
//		cout<<searched<<"\n";
		s[pos+1]='?';
	}
}
	

