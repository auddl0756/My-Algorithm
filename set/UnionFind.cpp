const int MAX;

class Set{
private:
 int parent[MAX];
 
public:
 Set(){
  for(int i=0;i<MAX;i++)
   parent[i]=i;
 }
 
 int find(int idx){
  if(idx==parent[idx]) return idx;
  return parent[idx]=find(parent[idx]);
 }

 void merge(int idx1,int idx2){
  int p1,p2;
  p1=find(idx1); p2=find(idx2);
  if(p1==p2) return;

  parent[p1]=p2;
 }
};
