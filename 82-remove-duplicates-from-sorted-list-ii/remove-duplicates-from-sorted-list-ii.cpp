/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // if(head==NULL) return NULL;
        // if(head->next==NULL) return head;
        // ListNode*temp=head;
        // ListNode*du=new ListNode(-1);
        // ListNode*d=du;
        // while(temp){
        //    if(temp->next && temp->val==temp->next->val){
        //        temp=temp->next->next;
        //     }
        //     else {
        //         d->next=temp;
        //         temp=temp->next;
        //     }
        // }
        // return du->next;
        // ListNode* deleteDuplicates(ListNode* head) {
ListNode *dummy = new ListNode(0);
dummy->next = head;
ListNode *temp = dummy;
while(head != NULL){
if(head->next and head->val == head->next->val){
while(head->next and head->val == head->next->val){
head = head->next;
}
temp->next = head->next;
}
else temp = temp->next;
head = head->next;
}
return dummy->next;
    }
    
};