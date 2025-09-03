class Node:
    def __init__(self, val):
        self.val = val
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = self.tail = None

    def push_back(self, val):
        newNode = Node(val)
        if(self.head == None):
            self.head = self.tail = newNode
        else:
            self.tail.next = newNode
            self.tail = newNode

    def push_front(self, val):
        newNode = Node(val)
        if(self.head == None):
            self.head = self.tail = newNode
        else:
            newNode.next = self.head
            self.head = newNode

    def pop_front(self):
        if self.head is None:
            print("List is already empty")
            return

        temp = self.head
        self.head = self.head.next
        temp.next = None
        del temp

    def pop_back(self):
        if self.head is None:
            print("List is already empty")
            return

        temp = self.head
        while(temp.next != self.tail):
            temp = temp.next
        temp.next = None
        del self.tail
        self.tail = temp

    def __str__(self):
        temp = self.head
        while(temp):
            print(f"{temp.val}->", end="")
            temp = temp.next
        print("NULL")
        return ""

    def clear_list(self):
        self.head = self.tail = None

if __name__ == "__main__":
    #operations for push_front
    lst = LinkedList()
    lst.push_front(4)
    lst.push_front(3)
    lst.push_front(2)
    lst.push_front(1)
    print(lst)
    lst.pop_back()
    print(lst)
    lst.pop_front()
    print(lst)

    # operations for push_back
    lst.clear_list()
    lst.push_back(4)
    lst.push_back(3)
    lst.push_back(2)
    lst.push_back(1)
    print(lst)
    lst.pop_back()
    print(lst)
    lst.pop_front()
    print(lst)