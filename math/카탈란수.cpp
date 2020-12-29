#include <bits/stdc++.h>
#define debug(a) for(int i=0;i<a.size();i++)cout<<a[i]<<" ";cout<<"\n";

typedef long long ll;
using namespace std;

/* �ǹ̸� �������� */
/* ���� ���� �� ����*/ 

const int MAX=5000;
const int mod=1e9+7;

ll Catalan[MAX+10];		//Catalan[i] : i���� ��ȣ�� �� ¥������ ����� �� 
// C[n] = sigma i from 0~n-1 (C[i] *C[n-1-i])
//�ùٸ� ��ȣ�� ����.
 
void calc_Catalan(){
	Catalan[0]=1;
	for(int i=1;i<=MAX;i++){
		for(int j=0;j<=i-1;j++){
			Catalan[i]+=Catalan[j]*Catalan[i-1-j];
			Catalan[i]%=mod;
		}
	}
}

