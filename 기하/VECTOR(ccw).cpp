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
#define lbd(arr,num) lower_bound(all(arr),num)

#define maxi(a,b,c) max(a,max(b,c))
#define mini(a,b,c) min(a,min(b,c))
#define msi map<string,int>
using namespace std;

typedef long long ll;

//ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

const double PI =2.0*acos(0.0);	//acos(x) : arcCosine(x) ,arccos(0) =PI/2

struct VECTOR{
	double x,y;
	explicit VECTOR(double x_=0,double y_=0) : x(x_),y(y_)
	{}
	
	bool operator == (const VECTOR& rhs) const{
		return x==rhs.x && y==rhs.y;
	}
	
	bool operator < (const VECTOR& rhs) const{
		return x!=rhs.x ? x<rhs.x : y<rhs.y;
	}
	
	//벡터 덧셈 
	VECTOR operator + (const VECTOR& rhs) const {
		return VECTOR(x+rhs.x,y+rhs.y);
	}
	
	//벡터 뺄셈 
	VECTOR operator - (const VECTOR& rhs) const{
		return VECTOR(x-rhs.x,y-rhs.y);
	}
	
	//벡터 스칼라곱(실수배) 
	VECTOR operator * (double rhs) const {
		return VECTOR(x*rhs,y*rhs);
	}
	
	//벡터 길이 
	double norm() const { return hypot(x,y); }	//hypot(x,y) : x,y 변을 가지는 직각삼각형의 빗변의 길이 반환 
	
	VECTOR normalize() const { return VECTOR(x/norm(),y/norm()); }
	
	//x축의 양의 방향으로부터 이 벡터까지 반시계 방향으로 잰 각도 
	double polar() const { return fmod(atan2(y,x)+2*PI,PI);}	//atan2 : arctan , fmod: 실수에 대한 나머지연산 
	
	//내적(inner product,dot product) 
	double dot_product(const VECTOR& rhs) const { return x*rhs.x+y*rhs.y; }	
	
	//외적(cross product) 
	double cross_product(const VECTOR& rhs) const { return x*rhs.y - rhs.x*y;}
	
	//이 벡터(this class,오브젝트)를 rhs에 사영한 결과를 반환  
	//사영 = norm(a) *cos(theta) = ( a(*)b ) / norm(b) 
	VECTOR project(const VECTOR& rhs) const {
		VECTOR r =rhs.normalize();		//길이는 1로, 방향만 남기기. 
		return r*r.dot_product(*this);	//this는 자기 자신을 가르키는 키워드, *this:지금 객체 자체	
	}
};

//내적의 용도 
// a(*)b = a.x*b.x + a.y+b.y ,  '(*)' means inner product
// 	   = norm(a) * norm(b) *cos(theta)
// 1. 벡터의 사이각 구하기( theta = acos((a(*)b)/(norm(a)*norm(b))) ) 
// 2. 벡터의 직각 여부 확인 (직각 iff 내적값 ==0)

// 외적의 용도
// a x b = a.x*b.y -a.y*b.x; ,  'x' means cross product	
//		 = norm(a) * norm(b) *sin(theta) , theta: a에서 b까지 반시계 방향으로의 각도  
// 1. 두 벡터가 이루는 면적 계산하기 :: 외적/2 == 두 벡터와 원점이 이루는 삼각형의 넓이 
// 2. 두 벡터의 방향 판별 : a x b =-(b x a)  ~> CCW check 가능 

//ccw: 세 점 a,b,c를 가르키는 세 벡터가 있을 때, a,b,c를 순서대로 잇는 두 선분은 b에서 어느방향으로 꺽을지 

//원점에서 벡터b가 벡터 a의 반시계 방향이면 양수, 시계방향이면 음수, 평행이면 0을 리턴 
double ccw(VECTOR a, VECTOR b){
	//cout<<a.x<<" "<<a.y<<" "<<b.x<<" "<<b.y<<"\n";
	return a.cross_product(b);
}

//점 p를 기준으로 벡터 b가 벡터 a의 반시계 방향이면 양수, 시계방향이면 음수, 평행이면 0을 리턴  
double ccw(VECTOR p,VECTOR a,VECTOR b){
	return ccw(a-p,b-p);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	VECTOR a[3];
	int x,y;
	for(int i=0;i<3;i++){
		cin>>x>>y;
		a[i].x=x,a[i].y=y;
	}
	
	int ccw_res=ccw(a[0],a[1],a[2]);
	if(ccw_res!=0)ccw_res/=abs(ccw_res);
	cout<<ccw_res<<'\n';
}

