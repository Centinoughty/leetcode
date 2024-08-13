// Delete nodes from linked list present in array
// MEDIUM

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode* modifiedList(int* nums, int numsSize, struct ListNode* head) {
  int* array = (int*)calloc(100001, sizeof(int));
  for (int i = 0; i < numsSize; i ++) {
    array[nums[i]] = 1;
  }
  
  struct ListNode* temp = head;
  while (temp && array[temp->val] == 1) {
    head = temp = temp->next;
  }
  
  while (temp->next) {
    if (array[temp->next->val] == 1) {
      temp->next = temp->next->next;
    } else {
      temp = temp->next;
    }
  }
  
  return head;
}
