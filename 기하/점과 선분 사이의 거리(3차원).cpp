
//3���� ��ǥ�� (x1,y1,z1)~(x2,y2,z2) ���а� ��(a,b,c)������ �Ÿ� ���ϱ�. 
double pointToSegment3D(double x1,double y1,double z1,double x2,double y2,double z2,double a,double b,double c){	
	double pa,pb; 
	for(int i=0;i<100;i++){
		
		//�Ÿ� �ʹ� ũ�� �����÷ο� ��. 
		pa=(x1-a)*(x1-a)+(y1-b)*(y1-b)+(z1-c)*(z1-c);
		pb=(x2-a)*(x2-a)+(y2-b)*(y2-b)+(z2-c)*(z2-c);
		if(pa>pb){
			x1=(x1+x2)/2,y1=(y1+y2)/2,z1=(z1+z2)/2;
		}else{
			x2=(x1+x2)/2,y2=(y1+y2)/2,z2=(z1+z2)/2;
		}
	}
	return sqrt(pa);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	VECTOR a,b,c;
	double x1,y1,z1,x2,y2,z2,x3,y3,z3;
	cin>>x1>>y1>>z1>>x2>>y2>>z2>>x3>>y3>>z3;
	
	cout.precision(12);
	cout<<pointToSegment3D(x1,y1,z1,x2,y2,z2,x3,y3,z3)<<"\n";
}
