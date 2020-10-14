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

typedef long long ll;
using namespace std;
//typedef vector<vector<ll> > matrix;
#define pll pair<ll,ll>

//[출처] [C++] 이진탐색트리, Binary Search Tree|작성자 거북찡
//http://blog.naver.com/PostView.nhn?blogId=7005ye&logNo=220691962788&categoryNo=59&parentCategoryNo=0&viewDate=&currentPage=1&postListTopCurrentPage=1&from=postView

class treeNode{
	friend class tree;
	private:
		int value;
		treeNode *left,*right;
		treeNode(int val) : value(val),left(NULL),right(NULL) {}	//생성자 
};

class tree{
	private:
		void recursiveInsert(treeNode *&,int);
		void recursiveRemove(treeNode *&,int);
		void preorderTraverse(treeNode *);
		void inorderTraverse(treeNode *);
		void postorderTraverse(treeNode *);
	public:
		treeNode *root;
		tree() : root(NULL) {}	//생성자 
		void insert(int);
		void remove(int);
		void preorder();
		void inorder();
		void postorder();	
};

void tree::recursiveInsert(treeNode *&node,int val){
	if(node==NULL) node=new treeNode(val);
	else if(val > node->value) recursiveInsert(node->right,val);	//삽입할 값이 현재 노드값보다 크면 오른쪽으로 탐색 진행 
	else if(val < node->value) recursiveInsert(node->left,val);		//삽입할 값이 현재 노드값보다 작으면 왼쪽으로 탐색 진행 
}

void tree::recursiveRemove(treeNode *&node,int val){
	treeNode *removal = new treeNode(0);
	if(node==NULL) return;	//삭제할 값이 이진트리에 없을 때. 
	else if(val > node->value) recursiveRemove(node->right,val);	//삭제할 값이 현재 노드값보다 크면 오른쪽으로 탐색 진행 
	else if(val < node->value) recursiveRemove(node->left,val);		//삭제할 값이 현재 노드값보다 작으면 왼쪽으로 탐색 진행
	
	else{	//삭제할 노드를 찾음:: val==node->value
		 //case 1: 삭제할 노드의 자식이 없을 때.
		 //case 2: 1)  삭제할 노드의 자식이 오른쪽만 있을 때
		 //case 2: 2)  삭제할 노드의 자식이 왼쪽만 있을 때
		 //case 3: 삭제할 노드의 자식이 둘 다 있을 때
		 
		 //case 1
		 if(node->left==NULL && node->right==NULL){
		 	delete node,node=NULL;
		 }
		 //case 2-1
		 else if(node->left==NULL){
		 	removal=node;
		 	node=node->right; //?
		 	delete removal;
		 }
		 //case 2-2
		 else if(node->right==NULL){
		 	removal=node;
		 	node=node->left;
		 	delete removal;
		 }
		 //case 3
		 else {
		 	removal=node->right;
		 	while(removal->left !=NULL) removal=removal->left;
		 	int minval=removal->value;
		 	recursiveRemove(root,minval);
		 	node->value=minval;
		 }	
	} 
}

void tree::preorderTraverse(treeNode *node){
	if(node==NULL) return;
	cout<<node->value<<"\n";
	preorderTraverse(node->left);
	preorderTraverse(node->right);	
}

void tree::inorderTraverse(treeNode *node){
	if(node==NULL) return;
	inorderTraverse(node->left);
	cout<<node->value<<"\n";
	inorderTraverse(node->right);
}

void tree::postorderTraverse(treeNode *node){
	if(node==NULL) return;
	postorderTraverse(node->left);
	postorderTraverse(node->right);
	cout<<node->value<<"\n";
}

///////////////////WRAPPING FUNCTION(함수들을 main에서 편하게 사용할수 있게 WRAP해줍니다)//////////////////////
void tree::insert(int val){
	recursiveInsert(root,val);
}

void tree::remove(int val){
	recursiveRemove(root,val);
}

void tree::preorder(){
	preorderTraverse(root);
}

void tree::inorder(){
	inorderTraverse(root);
}

void tree::postorder(){
	postorderTraverse(root);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	tree* t =new tree;
	t->insert(1);
	t->insert(3);
	t->insert(2);
	t->insert(4);
	t->preorder();
	
}



