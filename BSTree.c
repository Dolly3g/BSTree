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

	if(data <= (*n)->data)
		addNode(&((*n)->left),data);
	else
		addNode(&((*n)->right),data);
};

int insert(BSTree* tree, int data){
	addNode(&tree->root,data);
	return ++tree->count;
}
