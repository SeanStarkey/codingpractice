//
// Trie data structure
//
// English word dictionary from git@github.com:dwyl/english-words.git'
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

const int ALPHABET_SIZE=26;

struct Node {
    char value;
    Node* next[ALPHABET_SIZE];
    bool endOfWord;

    Node(int in_value) : value(in_value) {
        for (int i=0; i<ALPHABET_SIZE; i++)
            next[i] = nullptr;
    }

    void display(int level);
    std::vector<std::string> getAllWords(std::vector<std::string> words, std::string start);
};

class Trie {
public:
    Trie();
    Node root;
    void insert(std::string word);
    void display();
    std::vector<std::string> autocomplete(std::string str);
};

Trie::Trie() : root('0') {
}

void Trie::insert(std::string word) {
    Node* currentNode = &root;
    for (int i=0; i<word.size(); i++) {
        char ch = word[i];
        int index=ch - 'a';
        if (currentNode->next[index] == NULL) {
            currentNode->next[index] = new Node(ch);
        }
        currentNode = currentNode->next[index];
    }
    currentNode->endOfWord = true;
}

void Trie::display() {
    root.display(0);
}

void Node::display(int level) {
    for (int i=0; i<ALPHABET_SIZE; i++) {
        if (next[i] != nullptr) {
            for (int i=0; i<level; i++)
                std::cout << "|  ";
            std::cout << next[i]->value;
            if (next[i]->endOfWord)
                std::cout << "]";
            std::cout << std::endl;
            next[i]->display(level+1);
        }
    }
}

std::vector<std::string> Trie::autocomplete(std::string str) {
    std::vector<std::string> wordList;

    Node* startLooking = &root;
    for (int i=0; i<str.size(); i++) {
        int index = str[i] - 'a';
        if (startLooking->next[index] == nullptr) {
            return wordList;
        }
        startLooking = startLooking->next[index];
    }

    str.pop_back();
    wordList = startLooking->getAllWords(wordList, str);
    return wordList;
}

std::vector<std::string> Node::getAllWords(std::vector<std::string> words, std::string start) {
    std::string newStart = start + value;
    if (endOfWord) {
        words.push_back(newStart);
    }
    for (int i=0; i<ALPHABET_SIZE; i++) {
        if (next[i] != nullptr) {
            words = next[i]->getAllWords(words, newStart);
        }
    }
    return words;
}

int main() {
    Trie t;

    std::fstream file("../english-words/words_alpha.txt");
    std::string word;
    while (file >> word) {
        t.insert(word);
    }

    std::vector<std::string> words = t.autocomplete("zy");
    for (int i=0; i<words.size(); i++) {
        std::cout << words[i] << std::endl;
    }
    //t.display();
}
