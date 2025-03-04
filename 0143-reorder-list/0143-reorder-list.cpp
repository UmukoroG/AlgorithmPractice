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
    void reorderList(ListNode* head) {
        vector<ListNode*> arr;

        while(head){
            arr.push_back(head);
            head=head->next;
        }

        int l=0;
        int r=arr.size()-1;

        while(l<r){
            arr[l]->next=arr[r];
            l++;

            if(l==r) break;
            
            arr[r]->next=arr[l];
            r--;
        }

        arr[r]->next = nullptr;//terminate the link list with a null ptr
    }
};