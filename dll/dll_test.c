/*******************************************************************************
 * @file		dll_test.c
 * @brief		Test dll module.
 * @author	llHoYall <hoya128@gmail.com>
 * @version	v1.0
 * @note
 *	- 2018.03.09	Created.
 ******************************************************************************/

/* Include Headers -----------------------------------------------------------*/
// Standard
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
// System
#include "dll.h"

/* Structures ----------------------------------------------------------------*/
typedef struct _tTEST {
	tDLL		node;
	uint8_t	data;
} tTEST, *ptTEST;

/* Private Variables ---------------------------------------------------------*/
static tDLL		tListHeader;

/* Private Functions ---------------------------------------------------------*/
static void printList(const ptDLL list);

/* Main Function -------------------------------------------------------------*/
int main(int argc, char* argv[]) {
	(void)argc;
	(void)argv;

	// h->h
	// h<-h
	if (DLL_Init(&tListHeader) < 0) {
		printf("[ERR] Init.\n");
	}

	// h->1->h
	// h<-1<-h
	ptTEST node1 = (ptTEST)malloc(sizeof(tTEST));
	node1->data = 1;
	if (DLL_AppendTail(&tListHeader, (ptDLL)node1) < 0) {
		printf("[ERR] Append.\n");
	}
	printList(&tListHeader);

	// h->2->1->h
	// h<-2<-1<-h
	ptTEST node2 = (ptTEST)malloc(sizeof(tTEST));
	node2->data = 2;
	if (DLL_InsertHead(&tListHeader, (ptDLL)node2) < 0) {
		printf("[ERR] Append.\n");
	}
	printList(&tListHeader);

	// h->2->1->3->h
	// h<-2<-1<-3<-h
	ptTEST node3 = (ptTEST)malloc(sizeof(tTEST));
	node3->data = 3;
	if (DLL_AppendTail(&tListHeader, (ptDLL)node3) < 0) {
		printf("[ERR] Insert Head.\n");
	}
	printList(&tListHeader);

	// h->4->2->1->3->h
	// h<-4<-2<-1<-3<-h
	ptTEST node4 = (ptTEST)malloc(sizeof(tTEST));
	node4->data = 4;
	if (DLL_InsertHead(&tListHeader, (ptDLL)node4) < 0) {
		printf("[ERR] Append.\n");
	}
	printList(&tListHeader);

	// h->4->2->1->h
	// h<-4<-2<-1<-h
	ptTEST node5 = NULL;
	if (DLL_RemoveTail(&tListHeader, (pptDLL)&node5) < 0) {
		printf("[ERR] Remove Tail.\n");
	}
	free(node5);
	printList(&tListHeader);

	// h->2->1->h
	// h<-2<-1<-h
	node5 = NULL;
	if (DLL_RemoveHead(&tListHeader, (pptDLL)&node5) < 0) {
		printf("[ERR] Remove Tail.\n");
	}
	free(node5);
	printList(&tListHeader);

	// h->h
	// h<-h
	if (DLL_RemoveAll(&tListHeader) < 0) {
		printf("[ERR] Remove All.\n");
	}
	printList(&tListHeader);

	return 0;
}

/* Private Functions ---------------------------------------------------------*/
static void printList(const ptDLL head) {
	printf("=== List ===\n");
	ptDLL		ptr = head;
	ptTEST	cur;
	while (ptr->next != head) {
		cur = NULL;
		DLL_GetNext(ptr, (pptDLL)&cur);
		printf("%p - %d\n", cur, cur->data);
		ptr = ptr->next;
	}
}
