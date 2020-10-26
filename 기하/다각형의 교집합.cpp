#include <bits/stdc++.h>

using namespace std;

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


//두 직선의 교차점
//입력받는 a,b,c,d를 b-a로,d-c로 만든게 B,D. 
//ret : 구하려는 교차점 
bool lineIntersection(VECTOR a,VECTOR b,VECTOR c,VECTOR d,VECTOR& ret){		
	double determinant = (b-a).cross_product(d-c);		//check if parrallel
	if(fabs(determinant)<DBL_EPSILON) return false;		//These are parrallel
	
	//ret=a+(b-a)*((c-a).cross_product(d-c)/b.cross_product(d));	//...error
	
	ret=a+(b-a)*((c-a).cross_product(d-c)/determinant);
	return true;		//found intersection.
} 
// a + p*B = c + q*D   ... p,q는 scalar, a,c는 직선의 시작점,b,d는 방향벡터
// x,y 성분별로 정리하면 p=((c-a) x D) /(B x D)가 된다.
// a+ p*B에 p를 대입하면 교점 벡터가 나온다. 


////////// 다각형 클리핑(자르기) -보뭀섬 문제
////////// 직사각형(볼록 다각형)과 다각형의 교집합 구하기 
typedef vector<VECTOR> polygon;

//다각형의 꼭지점 출력 디버깅용(my imple) 
void printPolygon(polygon p){
	for(int i=0;i<p.size();i++){
		cout<<p[i].x<<" "<<p[i].y<<"\n";
	}
}

//왼쪽 반평면(반시계방향 순회 기준)과 다각형의 교집합을 구한다.
//(a,b)를 포함하는 직선으로 다각형 p를 자른 뒤, (a,b)의 왼쪽에 있는 부분 
polygon cutPoly(const polygon& p,const VECTOR& a,const VECTOR& b){
	int n=p.size();
	//p의 각 점이 반평면 내에 있는지 여부. 
	vector<bool> inside(n,false);
	
	for(int i=0;i<n;i++) inside[i]=ccw(a,b,p[i])>=0;	//직선(a,b)의 왼편에 있는지 여부::반평면 내에 있는지.
	
	polygon ret;
	
	for(int from=0;from<n;from++){
		int to=(from+1)%n;
		
		//반평면 내에 있는점은 항상 결과 다각형에 포함. 
		if(inside[from]) ret.push_back(p[from]);
		
		//(p[from],p[to]) 선분이 직선(a,b)와 교차하면 교차점을 결과 다각형에 포함시킨다. 
		if(inside[from]!=inside[to]){
			VECTOR cross;											// cross: 구하려는 교차점 
			assert(lineIntersection(p[from],p[to],a,b,cross));		// false when parallel
			ret.push_back(cross);  
		}
	} 
	return ret; 
} 

//sutherland-hodgman alogrithm
//:: 다각형1의 선분을 포함하는 직선으로 반평면 만들어가면서 그 반평면에 포함 안 되는 다각형2의 꼭지점들 걸러내기
//==> 최종적으로 남는 것이 다각형1과 다각형2의 교집합 꼭지점들. 
//(다각형 클리핑(잘라내기)라고 함 )
polygon intersection(const polygon& p,double x1,double y1,double x2,double y2){
	VECTOR a(x1,y1),b(x2,y1),c(x2,y2),d(x1,y2);	//직사각형
	polygon ret=cutPoly(p,a,b);
	ret=cutPoly(ret,b,c);
	ret=cutPoly(ret,c,d);
	ret=cutPoly(ret,d,a);
	return ret;
}

//단순 다각형 p의 넓이를 구한다.
double area(const polygon& p){
	double ret=0;
	for(int i=0;i<p.size();i++){
		int j=(i+1)%p.size();
		ret+=p[i].x*p[j].y-p[j].x*p[i].y;
	}
	return fabs(ret)/2.0;
} 

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int Q,x1,y1,x2,y2,n; cin>>Q;
	while(Q--){
		cin>>x1>>y1>>x2>>y2>>n;
		polygon p;
		for(int i=0;i<n;i++){
			int x,y; cin>>x>>y;
			p.push_back(VECTOR(x,y));
		}
		
		p=intersection(p,x1,y1,x2,y2);
		//printPolygon(p);
		cout<<area(p)<<"\n";
	}
}


