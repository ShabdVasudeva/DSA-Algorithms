#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    Node* next;
    Node* prev;
    int val;
    
    Node(int val)
    {
        this->val = val;
        next = prev = nullptr;
    }
};

class DoublyList
{
private:
    Node* head;
    Node* tail;
public:
    DoublyList()
    {
        head = tail = nullptr;
    }

    void push_front(int val)
    {
        Node* newNode = new Node(val);
        if(head == nullptr)
        {
            head = tail = newNode;
        } else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void push_back(int val)
    {
        Node* newNode = new Node(val);
        if(head == nullptr)
        {
            head = tail = newNode;
        } else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void pop_front()
    {
        if(head == nullptr)
        {
            cout << "List is already empty" << "\n";
            return;
        }
        Node* tempNode = head;
        head = head->next;
        if(head != nullptr)
        {
            head->prev = nullptr;
        }
        tempNode->next = nullptr;
        delete tempNode;
    }

    void pop_back()
    {
        if(head == nullptr)
        {
            cout << "List is already empty" << "\n";
            return;
        }
        Node* tempNode = tail;
        tail = tail->prev;
        if(tail != nullptr)
        {
            tail->next = nullptr;
        }
        tempNode->prev = nullptr;
        delete tempNode;
    }

    void print()
    {
        Node* tempNode = head;
        while(tempNode != nullptr){
            cout << tempNode->val;
            tempNode = tempNode->next;
        }
        cout << "\n";
        delete tempNode; // for memory efficiency;
    }
};

int main() 
{
    DoublyList dll;
    dll.push_front(5);
    dll.push_front(4);
    dll.push_front(3);
    dll.push_front(2);
    dll.push_front(1);
    dll.pop_back();
    dll.print();
    dll.pop_front();
    dll.print();
    return 0;
}