
//���� �� ������ �Ÿ�
//�� p���� (a,b) ������ ���� ������ ���� ���Ѵ�. 
VECTOR perpendicular(VECTOR p,VECTOR a,VECTOR b){
	return a+(p-a).project(b-a);
} 

//�� p�� (a,b)�� �̷�� ���� ������ �Ÿ��� ���Ѵ�. 
double pointToLine(VECTOR p,VECTOR a,VECTOR b){
	return (p-perpendicular(p,a,b)).norm();
}

//���� �� ������ �Ÿ��� ���ϴ� �ٸ� ���. :: my implementation
//a x b = norm(b-a)*h���� �̿��ؼ�
//h= (a x b)/norm(b-a)�� ���ϱ�. (����: norm(b-a)==0�� �� �ε� a�� b�� �ٸ��ٰ� ����.) 
double pointToLine2(VECTOR p,VECTOR a,VECTOR b){
	return fabs(a.cross_product(b)/(b-a).norm());
}

//���� ���� ������ �Ÿ� ���ϱ� :: my implementation
//�� p�� ����(a,b)�� �Ÿ��� ���Ѵ�.
//������ ���� ���� �������� ������ ���̰� �Ÿ��̰� �ƴϸ� �� ������ ���� �� ����� ������ ���̰� �Ÿ�. 
double pointToSegment(VECTOR p,VECTOR a,VECTOR b){
	VECTOR perFoot=perpendicular(p,a,b);	//������ �� 
	bool isIntersects=segmentIntersects(a,b,p,perFoot);	//������ ���� ab�� ��ġ����
	if(isIntersects) return (p-perFoot).norm();
	else return min((p-a).norm(),(p-b).norm());
}

//�̺�Ž������ ���� ���� ������ �Ÿ� ���ϱ� ::cubelover implementation
double pointToSegment2(VECTOR p,VECTOR a,VECTOR b){
	for(int i=0;i<100;i++){
		double pa=(p-a).norm(),pb=(p-b).norm();
		if(pa>pb) a=(a+b)*0.5;
		else b=(a+b)*0.5;
	}
	return (p-a).norm();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	VECTOR a[4],b[4],c[4];
	a[0].x=0,a[0].y=0;
	a[1].x=3,a[1].y=3;
	a[2].x=0,a[2].y=3;
	a[3].x=3,a[3].y=0;
	
	b[0].x=0,b[0].y=0;
	b[1].x=1,b[1].y=1;
	b[2].x=0,b[2].y=3;
	b[3].x=3,b[3].y=0;
	
	cout<<segmentIntersects(a[0],a[1],a[2],a[3])<<'\n';
	cout<<segmentIntersects(b[0],b[1],b[2],b[3])<<'\n';
	
	cout<<pointToLine(a[0],a[2],a[3])<<'\n';
	cout<<pointToLine2(a[0],a[2],a[3])<<'\n';
	
	
	c[0].x=3,c[0].y=0;
	c[1].x=-3,c[1].y=3;
	c[2].x=0,c[2].y=3;
	
	
	cout<<pointToSegment(c[0],c[1],c[2])<<"\n";
	cout<<pointToSegment2(c[0],c[1],c[2])<<"\n";
}

