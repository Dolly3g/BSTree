#include <stdlib.h>
#include <stdio.h>
#include "BSTree.h"

Node* createNode(int data){
	Node* n = calloc(1,sizeof(Node));
	n->data = data;
	return n;
}

BSTree createBSTree(){
	BSTree tree = {0,0};
	return tree;
}

void addNode(Node** n,int data){
	if(*n == 0){
		*n = createNode(data);
		return;
	}
	data <= (*n)->data ? addNode(&((*n)->left),data) : addNode(&((*n)->right),data);
};

int insert(BSTree* tree, int data){
	addNode(&tree->root,data);
	return ++tree->count;
}

Node* find(BSTree tree, int data){
	Node* walker = tree.root;
	while(walker != 0){
		if(data == walker->data)
			return walker;
		walker = data < walker->data ? walker->left : walker->right;
	}
	return 0;
}