#include <iostream>
#include <vector>

using namespace std;

//from codeforces "weird sort"(div3 B)
int main(){
	vector<int> arr={7,1,3,4,6,5,2};
	bool positions[7];	//let you can change array's  'i'th element and 'i+1'th element if "positions[i]" is true
	positions[0]=true; 
	positions[2]=true;
	positions[4]=true;

	bool flag,answer=true;
	while(true){
		flag=false;
		for(int i=0;i<arr.size();i++){
			if(arr[i]<=arr[i+1]) continue;  //already sorted part => skip
			if(positions[i]==false){	//arr[i]>arr[i+1] but it can't be sorted. then answer=false
				answer=false;
				break;
			}		
			swap(arr[i],arr[i+1]);
			flag=true;			//set "flag=true" to continue sort 

		}
		if(flag==false) break;			//"flag=false" if sorting is finished 
	}

	if(answer) cout<<"YES\n";
	else cout<<"NO\n";

}

