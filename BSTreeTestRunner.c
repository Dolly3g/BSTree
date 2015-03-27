#include <stdio.h>
typedef void TestFn(void);
typedef struct{
	char* name; 
	TestFn* fn;
} Test;

//code to be updated starts
TestFn setup,teardown,fixtureSetup,fixtureTearDown,test_createNode_creates_a_node_with_given_data,test_createBSTree_creates_a_tree,test_insert_sets_the_data_to_root_if_tree_is_empty_and_returns_1,test_insert_inserts_the_data_to_the_left_of_root_if_data_is_less_than_root,test_insert_inserts_the_data_to_the_right_of_root_if_data_is_greater_than_root,test_insert_expands_the_tree,test_insert_expands_the_tree_even_bigger,test_find_finds_you_a_node_containing_that_data,test_find_finds_you_the_first_node_containing_that_data,test_delete_deletes_the_leaf_node_the_tree_with_given_data,test_delete_deletes_the_node_with_1_right_child_from_the_tree_with_given_data,test_delete_deletes_the_node_with_1_left_child_from_the_tree_with_given_data;
Test test[] = {"test_createNode_creates_a_node_with_given_data",test_createNode_creates_a_node_with_given_data,"test_createBSTree_creates_a_tree",test_createBSTree_creates_a_tree,"test_insert_sets_the_data_to_root_if_tree_is_empty_and_returns_1",test_insert_sets_the_data_to_root_if_tree_is_empty_and_returns_1,"test_insert_inserts_the_data_to_the_left_of_root_if_data_is_less_than_root",test_insert_inserts_the_data_to_the_left_of_root_if_data_is_less_than_root,"test_insert_inserts_the_data_to_the_right_of_root_if_data_is_greater_than_root",test_insert_inserts_the_data_to_the_right_of_root_if_data_is_greater_than_root,"test_insert_expands_the_tree",test_insert_expands_the_tree,"test_insert_expands_the_tree_even_bigger",test_insert_expands_the_tree_even_bigger,"test_find_finds_you_a_node_containing_that_data",test_find_finds_you_a_node_containing_that_data,"test_find_finds_you_the_first_node_containing_that_data",test_find_finds_you_the_first_node_containing_that_data,"test_delete_deletes_the_leaf_node_the_tree_with_given_data",test_delete_deletes_the_leaf_node_the_tree_with_given_data,"test_delete_deletes_the_node_with_1_right_child_from_the_tree_with_given_data",test_delete_deletes_the_node_with_1_right_child_from_the_tree_with_given_data,"test_delete_deletes_the_node_with_1_left_child_from_the_tree_with_given_data",test_delete_deletes_the_node_with_1_left_child_from_the_tree_with_given_data};
char testFileName[] = {"BSTreeTest.c"};
void _setup(){/*CALL_SETUP*/}
void _teardown(){/*CALL_TEARDOWN*/}
void fixtureSetup(){}
void fixtureTearDown(){}
//code to be updated ends

int testCount;
int passCount;
int currentTestFailed;

int assert_expr(int expr, const char* fileName, int lineNumber, const char* expression){
	if(expr) return 0;
	currentTestFailed = 1;
	printf("\t %s : failed at %s:%d\n",expression, fileName,lineNumber);
	return 1;
}
int assert_equal(int val1, int val2, const char* fileName, int lineNumber,const char* expr1,const char* expr2){
	if(val1 == val2) return 0;
	currentTestFailed = 1;
	printf("\t %d == %d: failed in assertEqual(%s,%s) at %s:%d\n",val1,val2,expr1,expr2, fileName,lineNumber);
	return 1;
}

void runTest(char* name, TestFn test){
	testCount++,currentTestFailed=0;
	printf("**  %s\n",name);
	_setup();
		test();
	_teardown();
	if(!currentTestFailed) passCount++;	
}
int main(int argc, char const *argv[]){		
	int i,total = sizeof(test)/sizeof(Test);	
	fixtureSetup();
	testCount=0,passCount=0;
	printf("**------ %s ------\n",testFileName);
	for (i = 0; i < total; ++i)
		runTest(test[i].name,test[i].fn);	
	printf("** Ran %d tests passed %d failed %d\n",testCount,passCount,testCount-passCount);
	fixtureTearDown();	
	return 0;
}