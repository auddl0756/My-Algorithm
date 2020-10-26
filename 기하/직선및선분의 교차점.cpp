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
		
	//ret=a+(b-a)*((c-a).cross_product(d-c)/b.cross_product(d));	//...It was error
	
	ret=a+(b-a)*((c-a).cross_product(d-c)/determinant);
	return true;		//found intersection.
} 
// a + p*B = c + q*D   ... p,q�� scalar, a,c�� ������ ������,b,d�� ���⺤��
// x,y ���к��� �����ϸ� p=((c-a) x D) /(B x D)�� �ȴ�.
// a+ p*B�� p�� �����ϸ� ���� ���Ͱ� ���´�. 


//�� ������ ������
//(a,b)��(c,d)�� ������ ������ �� �̵��� �� ������ ��ġ���� Ȯ��
bool parallelSegments(VECTOR a,VECTOR b,VECTOR c,VECTOR d,VECTOR& ret){
	if(b<a) swap(a,b);
	if(d<c) swap(c,d);
	if(ccw(a,b,c)!=0) return false;		//�� ���� ���� ���� �� �ɷ�����
	if(b<c || d<a) return false;		//���� �� ��ġ�� ��� �ɷ�����
	if(a<c) ret=c; else ret=a;			//Ȯ���� ��ĥ �� 
	return true;
} 

//a,p,b�� ������ �� �ִٰ� ����. 
//a<p<b���� Ȯ��. :: p�� a,b�� �̷�� �簢�� �ȿ� �ִ���. 
bool inRectangle(VECTOR p,VECTOR a,VECTOR b){
	if(b<a) swap(a,b);
	return p==a || p==b || (a<p && p<b);	//== a<=p<=b�ε� <=�� �������ؼ� �̷��� ����. 
}

//(a,b) ���а� (c,d)������ ������ ret�� ��ȯ.
//������ �������� ��, �ƹ� �����̳� ��ȯ��. 
//������ ���� �� false�� ��ȯ 
bool segmentIntersection(VECTOR a,VECTOR b,VECTOR c,VECTOR d,VECTOR& ret){
	//�� ������ ������ ���. 
	if(not lineIntersection(a,b,c,d,ret)) return parallelSegments(a,b,c,d,ret);	
	//ret�� �� ���п� ���ÿ� ���ԵǾ� ���� ��쿡 true. 
	return inRectangle(ret,a,b) && inRectangle(ret,c,d);
}

//�������� �ʿ���� �������θ� �Ǻ��� �� use ccw
//�⺻������ ccw(a,b,c)�� ccw(a,b,d)��  ��ȣ��  �ٸ���
//ccw(c,d,a)�� ccw(c,d,b)�� ��ȣ�� �޶��  ������ ��. 
bool segmentIntersects(VECTOR a,VECTOR b,VECTOR c,VECTOR d){
	double ab=ccw(a,b,c)*ccw(a,b,d);
	double cd=ccw(c,d,a)*ccw(c,d,b);
	
	// �� ������ �� ���� ���� �֟� �� 
	if(ab==0 && cd==0){
		if(b<a) swap(a,b);
		if(d<c) swap(c,d);
		
		if(b<c || d<a) return true;
		else return false;
	}
	
	if(ab<=0 && cd<=0) return true;
	else return false; 	
} 

