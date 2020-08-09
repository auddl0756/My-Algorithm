#include <iostream>
#include <cstring>
using namespace std;

const int Alpha = 26;
int toNum(char ch) { return ch - 'a'; }

struct trieNode {
	trieNode* children[Alpha];
	bool isTerminal;

	trieNode()  {
		isTerminal = false;
		memset(children, 0, sizeof(children));
	}

	/*~trieNode() {
		for (int i = 0; i < Alpha; i++)
			if (children[i] != NULL)
				delete children[i];
	}*/

	void insert(string s,int l,int n) {
		if (l == n)
			isTerminal = true;
		else {
			int next = toNum(s[l]);

			if (children[next] == NULL)
				children[next] = new trieNode();
			children[next]->insert(s, l + 1, n);
		}
	}

	trieNode* search(string s,int l,int n) {
		if (l == n)
			return this;
		int next = toNum(s[l]);
		if (children[next] == NULL) 
			return NULL;
		return children[next]->search(s, l + 1, n);
	}

	bool existSearch(string s, int l, int n) {
		if (l == n)
			return true;
		int next = toNum(s[l]);
		if (children[next] == NULL)
			return false;
		return children[next]->existSearch(s, l + 1, n);
	}
};

int main() {
	trieNode* t=new trieNode();

	t->insert("hi",0,2);
	t->insert("hey",0,3);
	
	t->existSearch("hy", 0, 2) ? cout<<"exist" :cout<<"doesn't exist"; cout<<" in trie\n";
	t->existSearch("hey", 0, 3) ? cout<<"exist" :cout<<"doesn't exist"; cout<<" in trie\n";
	t->existSearch("hi", 0, 2) ? cout<<"exist" :cout<<"doesn't exist"; cout<<" in trie\n";
}
