//
// Daily Coding Problem #6
//
#include <iostream>

class XORListNode {
public:
    XORListNode(int value, int64_t prev);
    int value;
    int64_t both;
    XORListNode* add(int value, int64_t previous);
    void display(int64_t previous);
    XORListNode* get(int64_t prev, int index);
};

class XORList {
public:
    XORList();
    XORListNode* add(int value);
    void display();
    XORListNode* get(int index);

private:
    XORListNode* head;
};

XORList::XORList()
{
    head = NULL;
}

XORListNode::XORListNode(int value_in, int64_t prev_in) :
    value(value_in), both(prev_in ^ (int64_t)NULL)
{
}

//
// Insert node at the end of the list with value
//
XORListNode* XORList::add(int value)
{
    if (head == NULL)
    {
        head = new XORListNode(value, (int64_t)NULL);
        return head;
    }
    else
    {
        return head->add(value, (int64_t)NULL);
    }
}

// Add node to next if empty, otherwise iterate to next in list
XORListNode* XORListNode::add(int value, int64_t prev)
{
    XORListNode* next = (XORListNode*)(both ^ prev);
    if (next == NULL)
    {
        XORListNode* newNode = new XORListNode(value, (int64_t)this);
        both = prev ^ (int64_t)newNode;
        return newNode;
    }
    else
    {
        return next->add(value, (int64_t)this);
    }
}

// Iterate and display the nodes in the list
void XORList::display()
{
    if (head == NULL)
    {
        std::cout << "empty" << std::endl;
    }
    else
    {
        head->display((int64_t)NULL);
    }
}

// Display this node and call display on the next
void XORListNode::display(int64_t prev)
{
    std::cout << value << std::endl;
    XORListNode* next = (XORListNode*)(prev ^ both);
    if (next != NULL)
        next->display((int64_t)this);
}

// Return the node at index (0 based)
XORListNode* XORList::get(int index)
{
    if (head == NULL)
        return NULL;
    return head->get((int64_t)NULL, index);
}

XORListNode* XORListNode::get(int64_t prev, int index)
{
    if (index == 0)
        return this;
    XORListNode* next = (XORListNode*)(both ^ prev);
    if (next == NULL)
        return NULL;
    return next->get((int64_t)this, index-1);
}

int main()
{
    XORList list;

    list.add(2);
    list.add(3);
    list.add(5);
    list.add(7);

    list.display();

    std::cout << std::endl;
    std::cout << list.get(2)->value << std::endl;
}
