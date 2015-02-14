#include "BSTree.h"
#include "expr_assert.h"

void test_createNode_creates_a_node_with_given_data(){
	Node* n = createNode(20);
	assertEqual((int)n->left,0);
	assertEqual((int)n->right,0);
	assertEqual((int)n->data,20);
}

void test_createBSTree_creates_a_tree(){
	BSTree tree = createBSTree();
	assertEqual((int)tree.root,0);
	assertEqual((int)tree.count,0);
}

void test_insert_sets_the_data_to_root_if_tree_is_empty_and_returns_1(){
	BSTree tree = createBSTree();
	assertEqual(insert(&tree,10),1);
	assertEqual(tree.root->data,10);
}

void test_insert_inserts_the_data_to_the_left_of_root_if_data_is_less_than_root(){
	BSTree tree = createBSTree();
	assertEqual(insert(&tree,10),1);
	assertEqual(insert(&tree,9),2);
	assertEqual(tree.root->left->data,9);
}

void test_insert_inserts_the_data_to_the_right_of_root_if_data_is_greater_than_root(){
	BSTree tree = createBSTree();
	assertEqual(insert(&tree,10),1);
	assertEqual(insert(&tree,11),2);
	assertEqual(tree.root->right->data,11);
}

void test_insert_expands_the_tree(){
	BSTree tree = createBSTree();
	assertEqual(insert(&tree,10),1);
	assertEqual(insert(&tree,11),2);
	assertEqual(insert(&tree,12),3);
	assertEqual(tree.root->right->right->data,12);
}

void test_insert_expands_the_tree_even_bigger(){
	BSTree tree = createBSTree();
	assertEqual(insert(&tree,10),1);
	assertEqual(insert(&tree,11),2);
	assertEqual(insert(&tree,12),3);
	assertEqual(insert(&tree,7),4);
	assertEqual(insert(&tree,9),5);
	assertEqual(tree.root->left->right->data,9);
}

void test_find_finds_you_a_node_containing_that_data (){
	BSTree tree = createBSTree();
	Node* n;
	insert(&tree,10);
	insert(&tree,11);
	insert(&tree,9);
	insert(&tree,8);
	insert(&tree,12);
	n = find(tree,8);
	assertEqual(n->data,8);
	n = find(tree,12);
	assertEqual(n->data,12);
}

void test_find_finds_you_the_first_node_containing_that_data (){
	BSTree tree = createBSTree();
	Node* n;
	insert(&tree,10);
	insert(&tree,11);
	insert(&tree,12);
	insert(&tree,12);
	n = find(tree,12);
	assertEqual(n->data,12);
}