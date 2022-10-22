#include "./src/mytree.h"

int main(void) {
	BinTree tree1;
	BinTree_Init(&tree1, 20);
	
	//check root!
	printf("location '0' = %i\n", BinTree_getDataAt(&tree1, "0"));

	//add some nodes!
	if(BinTree_addNodeAt(&tree1, "01", 10) == BT_OK) {
		puts("Added child.");
	}
	
	if(BinTree_addNodeAt(&tree1, "02", 30) == BT_OK) {
		puts("Added child.");
	}

	//get those nodes!
	printf("location '01' = %i\n", "01", BinTree_getDataAt(&tree1, "01"));
	printf("location '02' = %i\n", "02", BinTree_getDataAt(&tree1, "02"));
	BinTree_Free(&tree1);
	return 0;
}
