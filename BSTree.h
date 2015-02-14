typedef struct node Node;
typedef struct BSTree BSTree;

struct node {
	Node* left;
	int data;
	Node* right;
};

struct BSTree {
	Node* root;
	int count;
};
//-------------------------Signatures-------------------

Node* createNode(int);
BSTree createBSTree(void);
int insert(BSTree*, int);
Node* find(BSTree, int);