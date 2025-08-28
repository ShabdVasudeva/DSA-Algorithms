/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head == nullptr) return head;
        Node* current = head;
        while (current != nullptr)
        {
            if (current->child != nullptr)
            {
                Node* next = current->next;
                current->next = flatten(current->child);
                current->child = nullptr;
                current->next->prev = current;
                while (current->next != nullptr)
                {
                    current = current->next;
                }
                if (next != nullptr)
                {
                    current->next = next;
                    current->next->prev = current;
                }
            }
            current = current->next;
        }
        return head;
    }
};