//
// Created by Pedro's Jet on 3/3/2026.
//

#ifndef TUTORIAL_TRIE_H
#define TUTORIAL_TRIE_H

#include <string>
#include <map>

using namespace std;


constexpr char Terminal = '/';

class Vertex {
    map<char, Vertex> adj;

public:
    explicit Vertex(){
        adj = map<char, Vertex>();
    }

    ~Vertex() = default;

    Vertex* GetAdj(const char k) {
        return &adj.at(k);
    }

    bool HasAdj(const char k) const {
        return adj.count(k) > 0;
    }

    void InsertAdj(const char k) {
        auto v = Vertex();
        adj.emplace(k, v);
    }
};

class Trie {
    map<char, Vertex> roots;


public:
    Trie() {
        roots = map<char, Vertex>();
    }

    void insert(const string &word) {
        const char first = word[0];
        if (roots.count(first) == 0) {
            auto v = Vertex();
            roots.emplace(first, v);
        }

        Vertex* p = &roots.at(first);
        for (int i = 1; i < word.length(); i++) {
            if (!p->HasAdj(word[i])) {
                p->InsertAdj(word[i]);
            }
            p = p->GetAdj(word[i]);
        }

        p->InsertAdj(Terminal);
    }

    bool search(const string &word) {
        const char first = word[0];
        if (roots.count(first) == 0) {
            return false;
        }

        Vertex* p = &roots.at(first);
        for (int i = 1; i < word.length(); i++) {
            if (!p->HasAdj(word[i])) {
                return false;
            }
            p = p->GetAdj(word[i]);
        }

        return p->HasAdj(Terminal);
    }

    bool startsWith(const string &prefix) {
        const char first = prefix[0];
        if (roots.count(first) == 0) {
            return false;
        }

        Vertex* p = &roots.at(first);
        for (int i = 1; i < prefix.length(); i++) {
            if (!p->HasAdj(prefix[i])) {
                return false;
            }
            p = p->GetAdj(prefix[i]);
        }

        return true;
    }
};


#endif //TUTORIAL_TRIE_H