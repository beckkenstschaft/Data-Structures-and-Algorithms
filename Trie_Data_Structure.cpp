#include <iostream>
using namespace std;

const int ALPHABET_SIZE = 26;

class TrieNode {
public:
    TrieNode* children[ALPHABET_SIZE];
    bool endOfWord;

    TrieNode() {
        endOfWord = false;
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            children[i] = nullptr;
        }
    }

    TrieNode* getChild(char ch) {
        return children[ch - 'a'];
    }

    bool hasChild(char ch) {
        return children[ch - 'a'] != nullptr;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* current = root;

        for (char ch : word) {
            int index = ch - 'a';
            if (current->children[index] == nullptr) {
                current->children[index] = new TrieNode();
            }
            current = current->children[index];
        }

        current->endOfWord = true;
    }

    bool search(string word) {
         TrieNode* current = root;

        for (char ch : word) {
            int index = ch - 'a';
            if (current->children[index] == nullptr) {
                return false;  // Prefix not found
            }
            current = current->children[index];
        }

        return current != nullptr && current->endOfWord;  // Check if the word is a complete word
    }

    bool deleteWord(string word) {
        return deleteWordHelper(root, word, 0);
    }

private:
    bool deleteWordHelper(TrieNode* current, const string& word, int level) {
        if (current == nullptr) {
            return false;  // Word not found
        }

        if (level == word.length()) {
            if (!current->endOfWord) {
                return false;  // Word not found
            }

            current->endOfWord = false;

            // If the node has children, just mark endOfWord as false
            return true;
        }

        int index = word[level] - 'a';
        if (!current->hasChild(word[level])) {
            return false;  // Word not found
        }

        // Recursively move to the next level
        bool deleted = deleteWordHelper(current->getChild(word[level]), word, level + 1);

        // If a node was deleted down the recursion, prune current node if necessary
        if (deleted && isEmptyNode(current)) {
            delete current;
            current = nullptr;
        }

        return deleted;
    }

    bool isEmptyNode(TrieNode* node) {
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if (node->children[i] != nullptr) {
                return false;  // Node has at least one child
            }
        }
        return true;  // Node is empty
    }
};

int main() {
    Trie trie;

    string word[] = {"hey", "how", "lion", "animal", "app"};
    int size = sizeof(word) / sizeof(word[0]);
    for (int i = 0; i < size; i++) {
        trie.insert(word[i]);
    }

    // Search for words
    cout << "Search 'app': " << (trie.search("app") ? "Found" : "Not Found") << endl;
    cout << "Search 'batman': " << (trie.search("batman") ? "Found" : "Not Found") << endl;

    // Delete words
    cout << "Delete 'app': " << (trie.deleteWord("app") ? "Deleted" : "Not Found") << endl;
    cout << "Search 'app': " << (trie.search("app") ? "Found" : "Not Found") << endl;

    return 0;
}
