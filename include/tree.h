// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>
#include <string>

class Tree {
 public:
    explicit Tree(std::vector<char> x) {
        root = new Node;
        root->value = '/';
        SetNode(root, x);
        Prop(root);
    }
    std::string operator[](int a) const {
        if (a >= perm.size()) {
            return "";
        }
    return perm[a];
    }

    std::vector<char> GetPermutation(const Tree& tree, int n) {
        std::string r = tree[n-1];
        std::vector<char> perm;
        for (int a = 0; a < r.length(); ++a) {
            perm.push_back(r[a]);
        }
      return perm;
    }

 private:
    struct Node {
        char value;
        std::vector<Node*> current;
    };
    Node* root;
    std::vector<std::string> perm;
    void SetNode(Node* root, std::vector<char> Numbs) {
    if (!Numbs.size()) {
     return;
    }
        if (root->value != '/') {
            std::vector<char>::iterator b = Numbs.begin();
            while (b != Numbs.end()) {
                if (*b == root->value) {
                    Numbs.erase(b);
                    break;
                }
                b++;
            }
        }
    int a = 0;
        while (a < Numbs.size()) {
            root->current.push_back(new Node);
            a++;
        }
        for (int a = 0; a < root->current.size(); ++a) {
            root->current[a]->value = Numbs[a];
        }
        for (int a = 0; a < root->current.size(); ++a) {
            SetNode(root->current[a], Numbs);
        }
    }

    void Prop(Node* root, std::string w = "") {
        if (!root->current.size()) {
            w = w + root->value;
            perm.push_back(s);
            return;
        }
        if (root->value != '/') {
            w = w + root->value;
        }
        int a = 0;
        while (a < root->current.size()) {
            Prop(root->current[a], w);
            a++;
        }
    }
};

#endif  // INCLUDE_TREE_H_
