// convex hull(���� ����)
// a)����(convex) �ٰ��� :  ��� ������ 180�� �̸��� �ٰ���.
// b)����(concave) �ٰ��� : 180���� �Ѵ� ������ �ִ� �ٰ���.
// *�ܼ� �ٰ��� : �ٰ����� ��谡 ���̰ų� �׷��� ���� �ٰ���.(�Ϲ������� �˰� �ִ� �ٰ���)

//���ϲ��� ã�� �˰��� �� �ϳ��� gift wrapping algorithm.
//:: ���� ���� �Ʒ� ���� �������� �ð�������� �����鼭 ���� ���ʿ� �����鼭 ���� �� ���� ���Ͽ� ���ϲ����� ������. 
//O(n^2) 

//typedef vector<VECTOR> polygon; 			//already declared above.

polygon giftWrap(const vector<VECTOR>& points){
	int n=points.size();
	polygon hull;
	
	//start : ���� ���� �Ʒ� ��(���ϲ����� �׻� ���ԵǴ� ��) 
	VECTOR start = *min_element(all(points));		//���ڰ� VECTOR ����ü�� �����Ǿ� �ִ�.
	hull.push_back(start); 
	
	while(true){
		//ccw(p,a,b) : �� p�� �������� ���� b�� ���� a�� �ݽð� �����̸� ���, �ð�����̸� ����, �����̸� 0�� ����  
		VECTOR ph=hull.back() , nxt=points[0];
		
		for(int i=1;i<n;i++){
			double cross=ccw(ph,nxt,points[i]);
			double dist1,dist2;
			dist1=(nxt-ph).norm();
			dist2=(points[i]-ph).norm();
			
			if(cross>0) nxt=points[i];			//�� ���ʿ� �ִ� ���� nxt�� �ǵ���. 
			else if(cross==0 && dist1<dist2){	//ph,nxt,points[i]�� ������ �� ������(����==0) �Ÿ��� �� �� ���� nxt�� �ǵ���. 
				nxt=points[i];
			}
		}
		
		if(nxt==start) break;
		
		hull.push_back(nxt);
	}
	return hull;
}

//�ٰ����� �ٰ����� ��� ���� ���� ���� �� q�� �־��� ��, q�� �ٰ����� ����/�ܺο� �ִ��� �Ǻ�
bool isInside(VECTOR q,const polygon& p){
	int crosses=0;
	for(int i=0;i<p.size();i++){
		int j=(i+1)%p.size();
		
		//if( not ((p[i].y >q.y && p[j].y >q.y) || (p[i].y <q.y && p[j].y <q.y) ))
		//(p[i],p[j])�� q���� ���������� ���� �������� ���η� ���������°�. 
		if((p[i].y > q.y) != (p[j].y > q.y)){
			//
			double atX = (p[j].x -p[i].x) * (q.y-p[i].y) /(p[j].y-p[i].y) +p[i].x;		//��ʽ� :dx1:dy1 = dx2: dy2 
			if(q.x <atX) crosses++;			//x��ǥ ���� �����̸� ���������� ī��Ʈ. 
		}
	}
	if(crosses % 2) return true;	//Ȧ���� ���� -> ���� �� 
	else return false;				//¦���� ���� -> �ܺ� �� 
} 


//�� �ٰ����� ���� ��ų� ��ġ���� ���� ��ȯ.
//�� ���̶� ��ġ�� return true 
//isInside �Լ��� �Ἥ ��� ���� �ƴ� ��� ������ �˻��ϸ� �� ���� ��ġ�� ��츦 ó�� ����. 
bool polygonIntersects(const polygon& p,const polygon& q){
	int n=p.size(),m=q.size();
	
	//p,q�� �ƹ� ���̳� ��Ҵµ� ���ԵǾ� ������ ==> �� �ٰ����� ��ģ��. 
	if(isInside(p[0],q) || isInside(q[0],p)) return true;		
	 
	//�� �ٰ����� ��� ���鳢�� ���� ��ġ���� �˻�. 
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(segmentIntersects(p[i],p[(i+1)%n],q[j],q[(j+1)%m])) return true;
		}
	}
	return false;		//not intersects.
}

//15.9���� �ʵ��ΰ�,�ʵ尡 �ƴѰ�? 
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


