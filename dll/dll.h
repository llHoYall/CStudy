/*******************************************************************************
 * @file		dll.h
 * @brief		Doubly Circular Linked List.
 * @author	llHoYall <hoya128@gmail.com>
 * @version	v1.0
 * @note
 *	- 2018.03.09	Created.
 ******************************************************************************/

#ifndef __HoYa_DOUBLY_LINKED_LIST_H__
#define __HoYa_DOUBLY_LINKED_LIST_H__

/* Enumerations --------------------------------------------------------------*/
typedef enum _eDLL_STATUS {
	eDLL_STATUS_SUCCESS			= 0,
	eDLL_STATUS_INVALID_ARGS	= -1,
} eDLL_STATUS;

/* Structures ----------------------------------------------------------------*/
typedef struct _tDLL {
	struct _tDLL*	prev;
	struct _tDLL* next;
} tDLL, *ptDLL, **pptDLL;

/* API Prototypes ------------------------------------------------------------*/
eDLL_STATUS DLL_Init(const ptDLL head);
eDLL_STATUS DLL_InsertHead(const ptDLL head, const ptDLL node);
eDLL_STATUS DLL_AppendTail(const ptDLL head, const ptDLL node);
eDLL_STATUS DLL_RemoveNode(const ptDLL node);
eDLL_STATUS DLL_RemoveHead(const ptDLL head, const pptDLL node);
eDLL_STATUS DLL_RemoveTail(const ptDLL head, const pptDLL node);
eDLL_STATUS DLL_RemoveAll(const ptDLL head);
eDLL_STATUS DLL_GetNext(const ptDLL node, pptDLL next_node);

#endif
