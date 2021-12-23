#ifndef ALBERONARIO_H
#define ALBERONARIO_H

template <class I, class N>
class treeN {
public:
    typedef I item;
    typedef N node;

    virtual void create() = 0;
    virtual bool _empty() const = 0;
    virtual void insRoot(node) = 0;
    virtual node root() const = 0;
    virtual node parent(node) const = 0;
    virtual bool leaf(node) const = 0;
    virtual node firstChild(node) const = 0;
    virtual bool lastSibling(node) const = 0;
    virtual node nextSibling(node) const = 0;

    virtual void removeSubTree(node) = 0;

    virtual void writeNode(node, item) = 0;
    virtual item readNode(node) const = 0;
};

#endif // ALBERONARIO_H
