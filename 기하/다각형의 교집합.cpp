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


//�� ������ ������
//�Է¹޴� a,b,c,d�� b-a��,d-c�� ����� B,D. 
//ret : ���Ϸ��� ������ 
bool lineIntersection(VECTOR a,VECTOR b,VECTOR c,VECTOR d,VECTOR& ret){		
	double determinant = (b-a).cross_product(d-c);		//check if parrallel
	if(fabs(determinant)<DBL_EPSILON) return false;		//These are parrallel
	
	//ret=a+(b-a)*((c-a).cross_product(d-c)/b.cross_product(d));	//...error
	
	ret=a+(b-a)*((c-a).cross_product(d-c)/determinant);
	return true;		//found intersection.
} 
// a + p*B = c + q*D   ... p,q�� scalar, a,c�� ������ ������,b,d�� ���⺤��
// x,y ���к��� �����ϸ� p=((c-a) x D) /(B x D)�� �ȴ�.
// a+ p*B�� p�� �����ϸ� ���� ���Ͱ� ���´�. 


////////// �ٰ��� Ŭ����(�ڸ���) -���O�� ����
////////// ���簢��(���� �ٰ���)�� �ٰ����� ������ ���ϱ� 
typedef vector<VECTOR> polygon;

//�ٰ����� ������ ��� ������(my imple) 
void printPolygon(polygon p){
	for(int i=0;i<p.size();i++){
		cout<<p[i].x<<" "<<p[i].y<<"\n";
	}
}

//���� �����(�ݽð���� ��ȸ ����)�� �ٰ����� �������� ���Ѵ�.
//(a,b)�� �����ϴ� �������� �ٰ��� p�� �ڸ� ��, (a,b)�� ���ʿ� �ִ� �κ� 
polygon cutPoly(const polygon& p,const VECTOR& a,const VECTOR& b){
	int n=p.size();
	//p�� �� ���� ����� ���� �ִ��� ����. 
	vector<bool> inside(n,false);
	
	for(int i=0;i<n;i++) inside[i]=ccw(a,b,p[i])>=0;	//����(a,b)�� ���� �ִ��� ����::����� ���� �ִ���.
	
	polygon ret;
	
	for(int from=0;from<n;from++){
		int to=(from+1)%n;
		
		//����� ���� �ִ����� �׻� ��� �ٰ����� ����. 
		if(inside[from]) ret.push_back(p[from]);
		
		//(p[from],p[to]) ������ ����(a,b)�� �����ϸ� �������� ��� �ٰ����� ���Խ�Ų��. 
		if(inside[from]!=inside[to]){
			VECTOR cross;											// cross: ���Ϸ��� ������ 
			assert(lineIntersection(p[from],p[to],a,b,cross));		// false when parallel
			ret.push_back(cross);  
		}
	} 
	return ret; 
} 

//sutherland-hodgman alogrithm
//:: �ٰ���1�� ������ �����ϴ� �������� ����� �����鼭 �� ����鿡 ���� �� �Ǵ� �ٰ���2�� �������� �ɷ�����
//==> ���������� ���� ���� �ٰ���1�� �ٰ���2�� ������ ��������. 
//(�ٰ��� Ŭ����(�߶󳻱�)��� �� )
polygon intersection(const polygon& p,double x1,double y1,double x2,double y2){
	VECTOR a(x1,y1),b(x2,y1),c(x2,y2),d(x1,y2);	//���簢��
	polygon ret=cutPoly(p,a,b);
	ret=cutPoly(ret,b,c);
	ret=cutPoly(ret,c,d);
	ret=cutPoly(ret,d,a);
	return ret;
}

//�ܼ� �ٰ��� p�� ���̸� ���Ѵ�.
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


