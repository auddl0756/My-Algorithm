
//점과 선 사이의 거리
//점 p에서 (a,b) 직선에 내린 수선의 발을 구한다. 
VECTOR perpendicular(VECTOR p,VECTOR a,VECTOR b){
	return a+(p-a).project(b-a);
} 

//점 p와 (a,b)가 이루는 직선 사이의 거리를 구한다. 
double pointToLine(VECTOR p,VECTOR a,VECTOR b){
	return (p-perpendicular(p,a,b)).norm();
}

//점과 선 사이의 거리를 구하는 다른 방법. :: my implementation
//a x b = norm(b-a)*h임을 이용해서
//h= (a x b)/norm(b-a)로 구하기. (예외: norm(b-a)==0일 때 인데 a와 b가 다르다고 가정.) 
double pointToLine2(VECTOR p,VECTOR a,VECTOR b){
	return fabs(a.cross_product(b)/(b-a).norm());
}

//점과 선분 사이의 거리 구하기 :: my implementation
//점 p와 선분(a,b)의 거리를 구한다.
//수선이 선분 위에 떨어지면 수선의 길이가 거리이고 아니면 두 선분의 끝점 중 가까운 곳과의 길이가 거리. 
double pointToSegment(VECTOR p,VECTOR a,VECTOR b){
	VECTOR perFoot=perpendicular(p,a,b);	//수선의 발 
	bool isIntersects=segmentIntersects(a,b,p,perFoot);	//수선의 발이 ab와 겹치는지
	if(isIntersects) return (p-perFoot).norm();
	else return min((p-a).norm(),(p-b).norm());
}

//이분탐색으로 점과 선분 사이의 거리 구하기 ::cubelover implementation
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

