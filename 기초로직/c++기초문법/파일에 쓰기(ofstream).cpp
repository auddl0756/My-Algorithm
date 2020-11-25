#include <bits/stdc++.h>

using namespace std;
//div3 686 b번 핵 데이터(MEMSET TLE 유발.)
 
int main(){
	ofstream fout;
	fout.open("input3.txt");

	fout<<20000<<"\n";
	for(int _=0;_<20000;_++){
		fout<<3<<"\n";
		for(int i=1;i<=3;i++){
			//fout<<rand()%2+1<<" ";	
			fout<<3<<" ";
		}fout<<"\n";
	
	}

	fout.close();

}
