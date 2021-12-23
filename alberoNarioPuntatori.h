#ifndef ALBERONARIOPUNTATORI_H
#define ALBERONARIOPUNTATORI_H

#include <iostream>
#include "alberoNario.h"

template <class T>
class linkedTree;

template <class T>
class nodo {
    friend class linkedTree<T>;
public:
    nodo() {
        genitore = nullptr;
        primoFiglio = nullptr;
        fratello = nullptr;
    }
private:
    nodo<T>* genitore;
    nodo<T>* primoFiglio;
    nodo<T>* fratello;
    T valore;
};

template <class T>
class linkedTree : public treeN<T, nodo<T>*>{
public:
    typedef typename treeN<T, nodo<T>*>::item item;
    typedef nodo<T>* node;

    linkedTree();
    ~linkedTree();

    void create();
    bool _empty() const;
    void insRoot(node);
    node root() const;
    node parent(node) const;
    bool leaf(node) const;
    node firstChild(node) const;
    bool lastSibling(node) const;
    node nextSibling(node) const;

    void removeSubTree(node);

    void writeNode(node, item);
    item readNode(node) const;

private:
    nodo<T> *_root;
};

template <class T>
linkedTree<T>::linkedTree() {
    this->create();
}

template <class T>
linkedTree<T>::~linkedTree() {
    removeSubTree(_root);
}

template <class T>
void linkedTree<T>::create() {
    _root = nullptr;
}

template <class T>
bool linkedTree<T>::_empty() const {
    return (_root == nullptr);
}

template <class T>
void linkedTree<T>::insRoot(linkedTree<T>::node nd) {
    if(!_empty()) {
        _root = new nodo<T>;
    }
}

template <class T>
typename linkedTree<T>::node linkedTree<T>::root() const {
    return _root;
}

template <class T>
typename linkedTree<T>::node linkedTree<T>::parent(linkedTree<T>::node nd) const {
    if(nd != _root) {
        return nd->genitore;
    }
}

template <class T>
bool linkedTree<T>::leaf(linkedTree<T>::node nd) const {
    return (nd->primoFiglio == nullptr);
}

template <class T>
typename linkedTree<T>::node linkedTree<T>::firstChild(linkedTree<T>::node nd) const {
    if(!leaf(nd)) {
        return nd->primoFiglio;
    }
}

template <class T>
bool linkedTree<T>::lastSibling(linkedTree<T>::node nd) const {
    return (nd->fratello == nullptr);
}

template <class T>
typename linkedTree<T>::node linkedTree<T>::nextSibling(linkedTree<T>::node nd) const {
    if(!lastSibling(nd)) {
        return nd->fratello;
    }
}

template <class T>
void linkedTree<T>::removeSubTree(linkedTree<T>::node nd) {

    if(!leaf(nd)) {
        removeSubTree(nd->primoFiglio);
    }

    if(!lastSibling(nd)) {
        removeSubTree(nd->fratello);
    }

    if(nd == _root) {
        _root = nullptr;
    } else {
        nodo<T>* supp = nd->genitore->primoFiglio;
        while(supp->fratello != nd) {
            supp = supp->fratello;
        }

        supp->fratello = nullptr;
    }

    delete nd;
    nd = nullptr;
}

template <class T>
void linkedTree<T>::writeNode(linkedTree<T>::node nd, linkedTree<T>::item elem) {
    if(nd != nullptr) {
        nd->valore = elem;
    }
}
template <class T>
typename linkedTree<T>::item linkedTree<T>::readNode(linkedTree<T>::node nd) const {
    if(nd != nullptr) {
        return nd->valore;
    }
}

#endif


