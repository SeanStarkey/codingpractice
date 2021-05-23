//
// Tree data structure
//

#include <iostream>

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int newValue) {
        value = newValue;
        left = NULL;
        right = NULL;
    }

    void display(int level, bool leftDisplay) {
        for (int i=0; i<level; i++)
            std::cout << "| ";
        if (!leftDisplay)
            std::cout << ".";
        std::cout << value;
        if (leftDisplay)
            std::cout << ".";
        std::cout << std::endl;
        if (left != NULL) {
            left->display(level+1, true);
        }
        if (right != NULL) {
            right->display(level+1, false);
        }
    }

    void insertNode(Node* n) {
        if (n->value == value)
        {
            n->left = this->left;
            n->right = this;
        }
        else if (n->value < value)
        {
            if (left == NULL)
                this->left = n;
            else
                this->left->insertNode(n);
        }
        else
        {
            if (right == NULL)
                this->right = n;
            else
                this->right->insertNode(n);
        }
    }

    void inOrderTraverseDisplay() {
        if (left != NULL)
            left->inOrderTraverseDisplay();
        std::cout << value << std::endl;
        if (right != NULL)
            right->inOrderTraverseDisplay();
    }

    Node* findNode(int value_in) {
        if (value == value_in) {
            return this;
        }
        else if (value_in < value) {
            if (left == NULL)
                return NULL;
            else
                return left->findNode(value_in);
        }
        else {
            if (right == NULL)
                return NULL;
            else
                return right->findNode(value_in);
        }
    }
};


class Tree {
public:
    Tree() {
        head = NULL;
    }

    void display() {
        head->display(0, true);
    }

    void insertNode(int newValue) {
        Node* n = new Node(newValue);
        if (head == NULL)
            head = n;
        else
            head->insertNode(n);
    }

    void inOrderTraverseDisplay() {
        if (head == NULL)
            return;
        head->inOrderTraverseDisplay();
    }

    Node* findNode(int value_in) {
        return head->findNode(value_in);
    }

    bool deleteNode(int value_in) {
        return false;
    }

    bool deleteNode(Tree* node) {
        return false;
    }

private:
    int value;
    Node* head;
};


int main()
{
    Tree t;
    srand(time(NULL));
    for (int i=0; i<20; i++)
        t.insertNode(rand()%100);

    t.display();
    std::cout << std::endl;
    t.inOrderTraverseDisplay();

    std::cout << std::endl;
    bool found = false;
    while (!found)
    {
        int value = rand()%100;
        std::cout << "Looking for " << value << std::endl;
        Node* n = t.findNode(value);
        if (n != NULL) {
            found = true;
            std::cout << "Found " << value << std::endl;
        }
    }
}
