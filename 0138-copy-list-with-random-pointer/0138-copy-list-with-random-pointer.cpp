/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        
        unordered_map<Node*, Node*> mp;
        
        Node* temp = head;
        while(temp){
            mp[temp] = new Node(temp->val); //creates new node with the same value
            temp=temp->next;
        }

        temp=head;
        while(temp){
            mp[temp]->next = mp[temp->next];
            mp[temp]->random = mp[temp->random];
            //mp[temp] represents the newly created node corresponding to temp (the original node).
            //mp[temp->next] represents the new node that corresponds to temp->next (the next original nod)
            temp=temp->next;
        }

        return mp[head];

    }
};