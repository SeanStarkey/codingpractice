
#include <iostream>

class Tree
{
public:
    int value;
    Tree* left;
    Tree* right;

    Tree(int newValue)
        {
            value = newValue;
            left = NULL;
            right = NULL;
        }

    void display()
        {
            display(0, true);
        }

    void display(int level, bool leftDisplay)
        {
            for (int i=0; i<level; i++)
                std::cout << " ";
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

    void insert(int newValue)
        {
            Tree* n = new Tree(newValue);
            insert(n);
        }

    void insert(Tree* n)
        {
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
                    this->left->insert(n);
            }
            else
            {
                if (right == NULL)
                    this->right = n;
                else
                    this->right->insert(n);
            }
        }

    void traverseDisplay()
        {
            if (left != NULL)
                left->traverseDisplay();
            std::cout << value << std::endl;
            if (right != NULL)
                right->traverseDisplay();
        }
};


int main()
{
    srand(time(NULL));
    Tree* t = new Tree(rand()%100);
    for (int i=0; i<20; i++)
        t->insert(rand()%100);

    t->display();
    std::cout << std::endl;
    t->traverseDisplay();
}
