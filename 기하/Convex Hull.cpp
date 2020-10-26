// convex hull(볼록 껍질)
// a)볼록(convex) 다각형 :  모든 내각이 180도 미만인 다각형.
// b)오목(concave) 다각형 : 180도가 넘는 내각이 있는 다각형.
// *단순 다각형 : 다각형의 경계가 꼬이거나 그런거 없는 다각형.(일반적으로 알고 있는 다각형)

//볼록껍질 찾는 알고리즘 중 하나인 gift wrapping algorithm.
//:: 가장 왼쪽 아래 점을 시작으로 시계방향으로 돌리면서 가장 왼쪽에 있으면서 가장 먼 점을 택하여 볼록껍질을 만들어간다. 
//O(n^2) 

//typedef vector<VECTOR> polygon; 			//already declared above.

polygon giftWrap(const vector<VECTOR>& points){
	int n=points.size();
	polygon hull;
	
	//start : 가장 왼쪽 아래 점(볼록껍질에 항상 포함되는 점) 
	VECTOR start = *min_element(all(points));		//비교자가 VECTOR 구조체에 구현되어 있다.
	hull.push_back(start); 
	
	while(true){
		//ccw(p,a,b) : 점 p를 기준으로 벡터 b가 벡터 a의 반시계 방향이면 양수, 시계방향이면 음수, 평행이면 0을 리턴  
		VECTOR ph=hull.back() , nxt=points[0];
		
		for(int i=1;i<n;i++){
			double cross=ccw(ph,nxt,points[i]);
			double dist1,dist2;
			dist1=(nxt-ph).norm();
			dist2=(points[i]-ph).norm();
			
			if(cross>0) nxt=points[i];			//더 왼쪽에 있는 것이 nxt가 되도록. 
			else if(cross==0 && dist1<dist2){	//ph,nxt,points[i]가 일직선 상에 있으면(외적==0) 거리가 더 먼 것이 nxt가 되도록. 
				nxt=points[i];
			}
		}
		
		if(nxt==start) break;
		
		hull.push_back(nxt);
	}
	return hull;
}

//다각형과 다각형의 경계 위에 있지 않은 점 q가 주어질 때, q가 다각형의 내부/외부에 있는지 판별
bool isInside(VECTOR q,const polygon& p){
	int crosses=0;
	for(int i=0;i<p.size();i++){
		int j=(i+1)%p.size();
		
		//if( not ((p[i].y >q.y && p[j].y >q.y) || (p[i].y <q.y && p[j].y <q.y) ))
		//(p[i],p[j])가 q에서 오른쪽으로 가는 반직석을 세로로 가로지르는가. 
		if((p[i].y > q.y) != (p[j].y > q.y)){
			//
			double atX = (p[j].x -p[i].x) * (q.y-p[i].y) /(p[j].y-p[i].y) +p[i].x;		//비례식 :dx1:dy1 = dx2: dy2 
			if(q.x <atX) crosses++;			//x좌표 마저 내부이면 교차점으로 카운트. 
		}
	}
	if(crosses % 2) return true;	//홀수번 교차 -> 내부 점 
	else return false;				//짝수번 교차 -> 외부 점 
} 


//두 다각형이 서로 닿거나 겹치는지 여부 반환.
//한 점이라도 겹치면 return true 
//isInside 함수만 써서 모든 변이 아닌 모든 점들을 검사하면 한 점만 겹치는 경우를 처리 못함. 
bool polygonIntersects(const polygon& p,const polygon& q){
	int n=p.size(),m=q.size();
	
	//p,q의 아무 점이나 잡았는데 포함되어 있으면 ==> 두 다각형은 겹친다. 
	if(isInside(p[0],q) || isInside(q[0],p)) return true;		
	 
	//두 다각형의 모든 변들끼리 서로 겹치는지 검사. 
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(segmentIntersects(p[i],p[(i+1)%n],q[j],q[(j+1)%m])) return true;
		}
	}
	return false;		//not intersects.
}

//15.9문제 너드인가,너드가 아닌가? 
int main() {
	//ios_base::sync_with_stdio(false); cin.tie(0);
	int Q,n,a,b,c; cin>>Q;
	while(Q--){
		cin>>n;
		polygon p1,p2;
		for(int i=0;i<n;i++){
			cin>>c>>a>>b;
			if(c==0){
				p1.push_back(VECTOR(a,b));
			}else{
				p2.push_back(VECTOR(a,b));
			}
		}
		
		if(not polygonIntersects(p1,p2)){
			cout<<"THEORY HOLDS\n";
		}else{
			cout<<"THEORY IS INVALID\n";
		}
	}
}


