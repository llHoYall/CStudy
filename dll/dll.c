/*******************************************************************************
 * @file		dll.c
 * @brief		Doubly Circular Linked List.
 * @author	llHoYall <hoya128@gmail.com>
 * @version	v1.0
 * @note
 *	- 2018.03.09	Created.
 ******************************************************************************/

/* Include Headers -----------------------------------------------------------*/
// Standard
#include <stdlib.h>
// System
#include "dll.h"

/* APIs ----------------------------------------------------------------------*/
eDLL_STATUS DLL_Init(ptDLL head) {
	if (head == NULL)
		return eDLL_STATUS_INVALID_ARGS;

	head->next = head;
	head->prev = head;
	return eDLL_STATUS_SUCCESS;
}

eDLL_STATUS DLL_InsertHead(const ptDLL head, const ptDLL node) {
	if ((head == NULL) || (node == NULL))
		return eDLL_STATUS_INVALID_ARGS;

	node->prev = head;
	node->next = head->next;
	head->next = node;
	(node->next)->prev = node;
	return eDLL_STATUS_SUCCESS;
}

eDLL_STATUS DLL_AppendTail(const ptDLL head, const ptDLL node) {
	if ((head == NULL) || (node == NULL))
		return eDLL_STATUS_INVALID_ARGS;

	node->prev = head->prev;
	node->next = head;
	head->prev = node;
	(node->prev)->next = node;
	return eDLL_STATUS_SUCCESS;
}

eDLL_STATUS DLL_RemoveHead(const ptDLL head, const pptDLL node) {
	if (head == NULL)
		return eDLL_STATUS_INVALID_ARGS;

	*node = head->next;
	head->next = (*node)->next;
	((*node)->next)->prev  = head;
	(*node)->prev = NULL;
	(*node)->next = NULL;
	return eDLL_STATUS_SUCCESS;
}

eDLL_STATUS DLL_RemoveTail(const ptDLL head, const pptDLL node) {
	if (head == NULL)
		return eDLL_STATUS_INVALID_ARGS;

	*node = head->prev;
	((*node)->prev)->next = head;
	head->prev = (*node)->prev;
	(*node)->prev = NULL;
	(*node)->next = NULL;
	return eDLL_STATUS_SUCCESS;
}

eDLL_STATUS DLL_RemoveAll(const ptDLL head) {
	if (head == NULL)
		return eDLL_STATUS_INVALID_ARGS;

	while (head->next != head) {
		ptDLL node;
		DLL_RemoveHead(head, (pptDLL)&node);
		free(node);
	}
	return eDLL_STATUS_SUCCESS;
}

eDLL_STATUS DLL_GetNext(const ptDLL node, pptDLL next_node) {
	if (node == NULL)
		return eDLL_STATUS_INVALID_ARGS;

	*next_node = node->next;
	return eDLL_STATUS_SUCCESS;
}
