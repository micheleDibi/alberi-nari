#ifndef ALBERONARIOLIST_H
#define ALBERONARIOLIST_H

#include "listaVettori.h"
#include "alberoNario.h"

#define MAXNODE 100

template <class I>
class treeList : public treeN<I, int> {
public:

    typedef I item;
    typedef int node;

    treeList() {
        create();
    }

    void create() {
        nNodes = 0;

        for (int i = 0; i < MAXNODE; i++) {
            nodes[i].used = false;
            nodes[i].childs.createList();
        }
    }

    bool _empty() const {
        return (nNodes == 0);
    }

    void insRoot(node n) {
        _root = 0;
        nodes[0].used = true;
        nNodes++;
    }

    node root() const {
        return _root;
    }

    node parent(node n) const {
        positionList child;

        for(int i = 0; i < MAXNODE; i++) {
            if(!nodes[i].childs.isEmpty()) {
                child = nodes[i].childs._begin();
                bool found = false;

                while(!nodes[i].childs._end(child) && found == false) {
                    if(nodes[i].childs.readList(child) == n) {
                        found = true;
                    }

                    child = nodes[i].childs.next(child);
                }

                if(found == true) {
                    return i;
                }
            }
        }
    }

    bool leaf(node n) const {
        return (nodes[n].childs.isEmpty());
    }

    node firstChild(node n) const {
        if(!leaf(n)) {
            return (nodes[n].childs.readList(nodes[n].childs._begin()));
        }

        return -1;
    }

    bool lastSibling(node n) const {
        positionList pos;
        node p = parent(n);
        pos = nodes[p].childs._begin();

        while(!nodes[p].childs._end(pos)) {
            pos = nodes[p].childs.next(pos);
        }

        return (n == nodes[p].childs.readList(pos));
    }

    node nextSibling(node n) const {
        if(!lastSibling(n)) {
            positionList pos;
            node p = parent(n);

            pos = nodes[p].childs._begin();

            while(!nodes[p].childs._end(pos)) {

                if(nodes[p].childs.readList(pos) == n) {
                    return (nodes[p].childs.readList(nodes[p].childs.next(pos)));
                }

                pos = nodes[p].childs.next(pos);
            }
        }

        return -1;
    }

    void insFirst(node n, item elem) {
        int i;
        for(i = 0; i < MAXNODE && nodes[i].used; i++) {}

        if(i < MAXNODE) {
            nodes[i].used = true;
            nodes[i].e = elem;
            nodes[i].childs.insList(nodes[n].childs._begin(), i);
        }
    }

    void insNode(node n, item elem) {
        int i;

        for (i = 0; i < MAXNODE && nodes[i].used == true; i++) {}

        if(i < MAXNODE) {
            nodes[i].used = true;
            nodes[i].e = elem;

            node p = parent(n);
            positionList pos = nodes[p].childs._begin();
            bool found = false;

            while(!nodes[p].childs._end(pos) && !found) {
                if(!(nodes[p].childs.readList(pos)) == n) {
                    found = true;
                }

                pos = nodes[p].childs.next(pos);
            }

            nodes[p].childs.insList(pos, i);
        }
    }

    void removeSubTree(node n) {
        positionList pos;
        if(!leaf(n)) {

            while(!nodes[n].childs.isEmpty()) {
                removeSubTree(nodes[n].childs.readList(nodes[n].childs._begin()));
            }
        }

        node p = parent(n);
        pos = nodes[p].childs._begin();

        while(nodes[p].childs.readList(pos) != n) {
            pos = nodes[p].childs.next(pos);
        }

        nodes[p].childs.delList(pos);
        nodes[n].used = false;

    }

    void writeNode(node n, item elem) {
        nodes[n].e = elem;
    }

    item readNode(node n) const {
        return (nodes[n].e);
    }

    /*
    void print() const {
        cout << "\n{";
        for (int i = 0; i < MAXNODE; i++) {
            if(nodes[i].used == true) {
                cout << "\n" << readNode(i) << ":   ";

                if(!leaf(i))
                    positionList pos = nodes[i].childs._begin();

                while(!nodes[i].childs._end(pos)) {
                    cout << readNode(nodes[i].childs.) << " ";
                    pos = nodes[i].childs.next(pos);
                }

            }
        }

        cout << "\n}\n";
    }
    */

private:
    struct record {
        item e;
        bool used;
        vectorList<int> childs;
    };
    typedef vectorList<int>::position positionList;

    record nodes[MAXNODE];
    node _root;
    int nNodes;
};

#endif // ALBERONARIOLIST_H
