//
// Tree data structure
//

#include <iostream>
#include <utility>

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

    Node* minValueNode(int value_in) {
        Node* current = this;
        while (current && (current->left != NULL))
            current = current->left;
        return current;
    }

};



class Tree {
public:
    Tree() {
        head = NULL;
    }

    void display() {
        if (head == NULL)
            return;
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

    void deleteNode(int value_in) {
        head = deleteNode(head, value_in);
    }

    Node* deleteNode(Node* root, int value_in) {
        if (root == NULL) {
            return NULL;
        }

        if (value_in < root->value) {
            root->left = deleteNode(root->left, value_in);
            return root;
        } else if (value_in > root->value) {
            root->right = deleteNode(root->right, value_in);
            return root;
        } else {
            if ((root->left == NULL) && (root->right == NULL)) {
                delete root;
                return NULL;
            }
            if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            } else {
                Node* temp = root->right->minValueNode(value_in);
                root->value = temp->value;
                root->right = deleteNode(root->right, temp->value);
                return root;
            }
        }
    }

private:
    Node* head;
};


int main()
{
    const int range = 100;
    const int number = 10;
    const int deletes = 5;

    Tree t;

    srand(time(NULL));
    for (int i=0; i<number; i++)
        t.insertNode(rand()%range);

    for (int i=0; i<deletes; i++)
    {
        t.display();
        std::cout << std::endl;
        t.inOrderTraverseDisplay();

        std::cout << std::endl;
        bool found = false;
        while (!found)
        {
            int value = rand()%range;
            Node* n = t.findNode(value);
            if (n != NULL) {
                found = true;
                std::cout << "Deleting... " << value << std::endl;
                std::cout << std::endl;
                t.deleteNode(value);
            }
        }
    }
    t.display();
    std::cout << std::endl;
    t.inOrderTraverseDisplay();
}
