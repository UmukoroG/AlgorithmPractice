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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> arr;
        ListNode* temp = head;//using a temp variable, preserves head for a return

        while(temp){
            arr.push_back(temp);
            temp=temp->next;
        }

        int idx = arr.size()-n;//idx to remove
        
        if(idx==0){ //removes the head pointer
            return head->next;
        }

        //linked the node before n to the node after n
        arr[idx-1]->next = arr[idx]->next;

        return head;
    }
};