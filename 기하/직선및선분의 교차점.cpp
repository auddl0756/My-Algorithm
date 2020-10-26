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
		
	//ret=a+(b-a)*((c-a).cross_product(d-c)/b.cross_product(d));	//...It was error
	
	ret=a+(b-a)*((c-a).cross_product(d-c)/determinant);
	return true;		//found intersection.
} 
// a + p*B = c + q*D   ... p,q는 scalar, a,c는 직선의 시작점,b,d는 방향벡터
// x,y 성분별로 정리하면 p=((c-a) x D) /(B x D)가 된다.
// a+ p*B에 p를 대입하면 교점 벡터가 나온다. 


//두 선분의 교차점
//(a,b)와(c,d)가 평행한 선분일 때 이들이 한 점에서 겹치는지 확인
bool parallelSegments(VECTOR a,VECTOR b,VECTOR c,VECTOR d,VECTOR& ret){
	if(b<a) swap(a,b);
	if(d<c) swap(c,d);
	if(ccw(a,b,c)!=0) return false;		//한 직선 위에 없을 때 걸러내기
	if(b<c || d<a) return false;		//절대 안 겹치는 경우 걸러내기
	if(a<c) ret=c; else ret=a;			//확실히 겹칠 때 
	return true;
} 

//a,p,b가 일직선 상에 있다고 가정. 
//a<p<b인지 확인. :: p가 a,b가 이루는 사각형 안에 있는지. 
bool inRectangle(VECTOR p,VECTOR a,VECTOR b){
	if(b<a) swap(a,b);
	return p==a || p==b || (a<p && p<b);	//== a<=p<=b인데 <=를 구현안해서 이렇게 쓴것. 
}

//(a,b) 선분과 (c,d)선분의 교점을 ret에 반환.
//교점이 여러개일 때, 아무 교점이나 반환함. 
//교점이 없을 때 false를 반환 
bool segmentIntersection(VECTOR a,VECTOR b,VECTOR c,VECTOR d,VECTOR& ret){
	//두 직선이 평행인 경우. 
	if(not lineIntersection(a,b,c,d,ret)) return parallelSegments(a,b,c,d,ret);	
	//ret이 두 선분에 동시에 포함되어 있을 경우에 true. 
	return inRectangle(ret,a,b) && inRectangle(ret,c,d);
}

//교차점은 필요없고 교차여부만 판별할 때 use ccw
//기본적으로 ccw(a,b,c)와 ccw(a,b,d)의  부호가  다르고
//ccw(c,d,a)와 ccw(c,d,b)의 부호가 달라야  교차할 것. 
bool segmentIntersects(VECTOR a,VECTOR b,VECTOR c,VECTOR d){
	double ab=ccw(a,b,c)*ccw(a,b,d);
	double cd=ccw(c,d,a)*ccw(c,d,b);
	
	// 두 선분이 한 직선 위에 있읋 때 
	if(ab==0 && cd==0){
		if(b<a) swap(a,b);
		if(d<c) swap(c,d);
		
		if(b<c || d<a) return true;
		else return false;
	}
	
	if(ab<=0 && cd<=0) return true;
	else return false; 	
} 

