#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
 };

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode *pNextList1=list1, *pNextList2=list2, *pHeadNewList=NULL, *pNextNewList;

    while(1){
        if(pNextList1 == NULL && pNextList2 == NULL)
            break;
        struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newNode->next = NULL;
        if(pNextList1 == NULL){
            newNode->val = pNextList2->val;
            pNextList2 = pNextList2->next;
        }
        else if(pNextList2 == NULL){
            newNode->val = pNextList1->val;
            pNextList1 = pNextList1->next;
        }
        else{
            if(pNextList1->val < pNextList2->val){
                newNode->val = pNextList1->val;
                pNextList1 = pNextList1->next;
            }
            else{
                newNode->val = pNextList2->val;
                pNextList2 = pNextList2->next;
            }
        }
        if(pHeadNewList == NULL){
            pHeadNewList = newNode;
            pNextNewList = pHeadNewList;
        }
        else{
            pNextNewList->next = newNode;
            pNextNewList = pNextNewList->next;
        }
    }

    return pHeadNewList;
}