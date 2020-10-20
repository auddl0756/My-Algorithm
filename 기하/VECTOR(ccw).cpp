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
	
	//���� ���� 
	VECTOR operator + (const VECTOR& rhs) const {
		return VECTOR(x+rhs.x,y+rhs.y);
	}
	
	//���� ���� 
	VECTOR operator - (const VECTOR& rhs) const{
		return VECTOR(x-rhs.x,y-rhs.y);
	}
	
	//���� ��Į���(�Ǽ���) 
	VECTOR operator * (double rhs) const {
		return VECTOR(x*rhs,y*rhs);
	}
	
	//���� ���� 
	double norm() const { return hypot(x,y); }	//hypot(x,y) : x,y ���� ������ �����ﰢ���� ������ ���� ��ȯ 
	
	VECTOR normalize() const { return VECTOR(x/norm(),y/norm()); }
	
	//x���� ���� �������κ��� �� ���ͱ��� �ݽð� �������� �� ���� 
	double polar() const { return fmod(atan2(y,x)+2*PI,PI);}	//atan2 : arctan , fmod: �Ǽ��� ���� ���������� 
	
	//����(inner product,dot product) 
	double dot_product(const VECTOR& rhs) const { return x*rhs.x+y*rhs.y; }	
	
	//����(cross product) 
	double cross_product(const VECTOR& rhs) const { return x*rhs.y - rhs.x*y;}
	
	//�� ����(this class,������Ʈ)�� rhs�� �翵�� ����� ��ȯ  
	//�翵 = norm(a) *cos(theta) = ( a(*)b ) / norm(b) 
	VECTOR project(const VECTOR& rhs) const {
		VECTOR r =rhs.normalize();		//���̴� 1��, ���⸸ �����. 
		return r*r.dot_product(*this);	//this�� �ڱ� �ڽ��� ����Ű�� Ű����, *this:���� ��ü ��ü	
	}
};

//������ �뵵 
// a(*)b = a.x*b.x + a.y+b.y ,  '(*)' means inner product
// 	   = norm(a) * norm(b) *cos(theta)
// 1. ������ ���̰� ���ϱ�( theta = acos((a(*)b)/(norm(a)*norm(b))) ) 
// 2. ������ ���� ���� Ȯ�� (���� iff ������ ==0)

// ������ �뵵
// a x b = a.x*b.y -a.y*b.x; ,  'x' means cross product	
//		 = norm(a) * norm(b) *sin(theta) , theta: a���� b���� �ݽð� ���������� ����  
// 1. �� ���Ͱ� �̷�� ���� ����ϱ� :: ����/2 == �� ���Ϳ� ������ �̷�� �ﰢ���� ���� 
// 2. �� ������ ���� �Ǻ� : a x b =-(b x a)  ~> CCW check ���� 

//ccw: �� �� a,b,c�� ����Ű�� �� ���Ͱ� ���� ��, a,b,c�� ������� �մ� �� ������ b���� ����������� ������ 

//�������� ����b�� ���� a�� �ݽð� �����̸� ���, �ð�����̸� ����, �����̸� 0�� ���� 
double ccw(VECTOR a, VECTOR b){
	//cout<<a.x<<" "<<a.y<<" "<<b.x<<" "<<b.y<<"\n";
	return a.cross_product(b);
}

//�� p�� �������� ���� b�� ���� a�� �ݽð� �����̸� ���, �ð�����̸� ����, �����̸� 0�� ����  
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

