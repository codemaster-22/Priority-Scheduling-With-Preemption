#ifndef HEAP_H 
#define HEAP_H

#include "Node.h"
class Heap
{
public:
    Node* executing;
    Heap();
    void printpreorder();
    void printpreorder(int ii);
    void insert(Node* ptr);
    Node* returnmin(){ return element[1];}
    Node* deletemin();
    int nelements;
private:
    vector<Node*> element;
    int getparent(int ii){return (ii/2);}
    int getleft(int ii){return (2*ii);}
    int getright(int ii){return (2*ii)+1;}
    int percolateup(int ii);
    int percolatedown(int ii);
};

#endif
