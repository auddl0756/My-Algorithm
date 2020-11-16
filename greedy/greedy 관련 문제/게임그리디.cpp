#include <bits/stdc++.h>

#define pii pair<int,int>
#define pdi pair<double,int>
#define ppi pair<pair<int,int>,int>
#define pipi pair<pair<int,int>,pair<int,int> >
#define fs first
#define sc second

#define sorta(a) sort(a.begin(),a.end());
#define rsorta(a) sort(a.rbegin(),a.rend());
#define sorta2(a,n) sort(a,a+n);
#define debug(a) for(int i=0;i<a.size();i++)cout<<a[i]<<" ";cout<<"\n";
#define debug2(a,n) for(int i=0;i<n;i++)cout<<a[i]<<" ";cout<<"\n";

#define all(v) (v).begin(), (v).end()
#define lb(arr,num) lower_bound(all(arr),num)

#define maxi(a,b,c) max(a,max(b,c))
#define mini(a,b,c) min(a,min(b,c))
#define msi map<string,int>

typedef long long ll;
using namespace std;

#define pll pair<ll,ll>
#define pcc pair<char,char>
const int MAX=1e9+7;


//2020 ICPC, COMPFEST 12, Indonesia Multi-Provincial Contest (Unrated, Online Mirror, ICPC Rules, Teams Preferred)
//A. Arena of Greed
//https://codeforces.com/problemset/problem/1425/A
//<해설> 
//================================================================================
//We can solve this problem greedily. The tricky case is if the current number of 
//coins is a multiple of 4 greater than 8, it is optimal to take 1 coin instead of taking N2 coins. The proof:
//
//Lets say the number of of coins is 4k for some k>0. If we take 2k coins:
//
//Mr. Chanek takes 2k coins. (remaining: 2k)
//Opponent takes k coins. (remaining: k)
//The number of coins Mr. Chanek gets is 2k coins.
//
//Lets say we take 1 coin:
//
//Mr. Chanek takes 1 coin. (remaining: 4k?1)
//Opponent takes 1 coin. (remaining: 4k?2)
//Mr. Chanek takes 2k?1 coins. (remaining: 2k?1).
//Opponent takes 1 coin. (remaining: 2k?2).
//In both cases, Mr. Chanek ends up with 2k coins. However, there are 2k?2 coins
// remaining in the second example, while only k coins remain in the first example. So, if 2k?2>k, we take the second case.
// It turns out, 2k?2≤k is only true if k=1. So if the number of coins is 4, we take 2 coins, else we take 1 coin.
//
//Alternatively, you can also look at the number of coins the opponent gained. 
//On the first case, the opponent gains k coins, while on the second case, the opponent gains 2 coins.
// In both cases, we gain 2k coins. So, it's optimal to choose the option that maximizes the difference of coins gained (k or 2).
//
//For other possible number of coins:
//
//if the number of coins is even not multiple of 4, we take half coins.
//If the number of coins is odd, we take 1 coin.

//================================================================================

 
// 수학적 사고와 그리디.. 이걸 어떻게 생각해내..
// 근데 맞고보니 어려운 관찰은 아닌거 같기도 하고..
// 대충 봤을 때는 짝수개면 다 가져가는 것이 최선인 줄 알았지만..
// 상대방을 더 못살게 굴 방법(내가 짝수를 가져갔는데 가져가고 남은 것도 짝수일 때)이 존재했다. 

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	ll Q,n; cin>>Q;
	while(Q--){
		cin >>n;
		ll ans=0;
		for(int i=0;n>0;i++){
			ll toadd=0;
			
			if(n%4==0 && n>4){		
				ll k =n/4;
//				toadd = 2*k;		//this is not optimal!
//				n = 2*k;
				toadd=1;			//this is optimal
				n-=1;
			}else if(n%2==0){
				toadd=n/2;
				n/=2;
			}else{
				toadd=1;
				n-=1;
			}
			
			
			if(i%2==0){		//my turn
				ans+=toadd;	
//				cout<<i<<" "<<toadd<<" "<<n<<"\n";
			}
		}
	
		
		cout<<ans<<'\n';
	}
	
}	



// 1st wrong

//	if(i%2==0){
//				if(rem==0 && mok>2){
//					ans+=2*mok;
//					n=2*mok-2;
//				}else{
//					if(n%2==0){
//						ans+=n/2;
//						n/=2;
//					}else{
//						ans+=1;
//						n-=1;
//					}
//				}
//			}else{
//				if(rem==0 && mok>2){
//					//ans+=2*mok;
//					n=2*mok-2;
//				}else{
//					if(n%2==0){
//						//ans+=n/2;
//						n/=2;
//					}else{
//						//ans+=1;
//						n-=1;
//					}
//				}
//			}





 
//2nd wrong

//	for(int i=0;n>0;i++){
//			if(i%2==0){	//my turn
//				if(n%2==0 && (n/4)%2!=0){		//:: n이 2의 배수지만 8의 배수는 아닐 때 
//					ans+=n/2;
//					n/=2;
//				}else{
//					if(n%2){	//n이 홀수 
//						ans+=1;
//						n-=1;
//					}else{		//n이 짝수이며 4의 배수 
//						ans+=2*(n/4);
//						n=2*(n/4)-2;
//					}
//				}
//			}else{	//his turn
//					if(n%2==0 && (n/4)%2!=0){		//:: n이 2의 배수지만 4의 배수는 아닐 때 
//					//ans+=n/2;
//					n/=2;
//				}else{
//					if(n%2){	//n이 홀수 
//					//	ans+=1;
//						n-=1;
//					}else{		//n이 짝수이며 4의 배수 
//					//	ans+=2*(n/4);
//						n=2*(n/4)-2;
//					}
//				}
//			}
//			
//			
//		}


