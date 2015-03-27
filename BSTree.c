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

Node* handleLeaf(Node* walker,int data){
	Node* pv;
	while(walker != 0){
		if(walker->data == data){
			data<=pv->data ? (pv->left = 0) : (pv->right = 0);
			return walker;
		}
		pv = walker;
		walker = data<=walker->data ? walker->left : walker->right;
	}
	return walker;
}

Node* handleUniparous(Node* walker,int data){
	Node* pv;
	while(walker != 0){
		if(walker->data == data){		
			if(walker->data >= pv->data)
				pv->right = walker->right ? walker->right : walker->left;
			
			else
				pv->left = walker->right ? walker->right : walker->left;

			return walker;
		}
		pv = walker;
		walker = data<=walker->data ? walker->left : walker->right;
	}
	return walker;
}

int isLeaf(BSTree tree,int data){
	Node* n = find(tree,data);
	return n->left == 0 && n->right == 0;
}

int hasTwoParents(BSTree tree,int data){
	Node* n = find(tree,data);
	return n->left != 0 && n->right != 0;	
}

Node* deleteNode(BSTree* tree, int data){
	Node* walker = tree->root;
	if(isLeaf(*tree,data)){
		return handleLeaf(walker,data);
	}
	if(!hasTwoParents(*tree,data)){
		return handleUniparous(walker,data);
	}
	return walker;
}