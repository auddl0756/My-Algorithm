#include <bits/stdc++.h>

#define pii pair<int,int>
#define fs first
#define sc second
#define all(v) v.begin(),v.end()
#define sorta(a) sort(all(a))

using namespace std;
typedef long long ll;

#define debug(a) for(auto x:a) cout<<x<<' '; cout<<'\n';

// given array : a
// segment Tree : t

const int MAX=1e6+100;
ll n,t[MAX*4];

void build(ll a[], int v, int tl, int tr) {
    if(tl==tr){
        t[v]=a[tl];
    }else{
        int tm=(tl+tr)/2;
        build(a,v*2,tl,tm);
        build(a,v*2+1,tm+1,tr);
        t[v]=t[v*2]+t[v*2+1];
    }
}

// v : current vertex
//tl,tr : boundaries of current vertex
//l,r : boundaries of query
ll sum(int v,int tl,int tr,int l,int r){
    if(l>r) return 0;
    if(l==tl && r==tr) return t[v]; //구하는 쿼리와 이 노드가 저장하는 범위가 꼭 일치할 때만 값 리턴
    else{   //아니면 일단 아래 자식들한테 요청
        int tm=(tl+tr)/2;
        //left child + right child
        return sum(v*2,tl,tm,l,min(tm,r)) + sum(v*2+1,tm+1,tr,max(tm+1,l),r);
    }
}

void update(int v,int tl,int tr,int pos,ll val){
    if(tl==tr){
        t[v]=val;
    }else{
        int tm=(tl+tr)/2;
        if(pos<=tm){
            update(2*v,tl,tm,pos,val);
        }else{
            update(2*v+1,tm+1,tr,pos,val);
        }
        t[v]=t[v*2]+t[v*2+1];
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int m,k; 
    cin>>n;
    cin>>m>>k;
    ll* a= new ll[n];
    for(int i=0;i<n;i++) cin>>*(a+i);
    
    build(a,1,0,n-1);

    for(int i=0;i<m+k;i++){
        ll c,l,r; cin>>c>>l>>r;
        
        if(c==1) update(1,0,n-1,l-1,r);
        else {
            l--,r--;
            cout<<sum(1,0,n-1,l,r)<<'\n';
        }
        
    }
}