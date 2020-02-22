#include "../include/Heap.h"
Heap::Heap()
    {
      element.push_back(NULL);
      nelements=0;
      executing=NULL;
    }
void Heap::printpreorder()
{
    if(nelements){
        printpreorder(1);
        cout<<endl;
    }
}
void Heap::printpreorder(int ii)
{ 
    if(ii>nelements)
        return;
    cout<<element[ii]->processno<<" ";
    int jj=getleft(ii);
    int kk=getright(ii);
    printpreorder(jj);
    printpreorder(kk);
}
bool check(Node* a,Node* b)
{   
    if(!a)
        return false;
    if(!b)
        return true;
    if((a->priorityvalue)<(b->priorityvalue))
        return true;
    if((a->priorityvalue)==(b->priorityvalue)&&(a->arrivaltime)<(b->arrivaltime))
        return true;
    return false;
}
int Heap::percolateup(int ii)
{
    Node* ptr=element[ii];
    int jj=getparent(ii);
    while(jj&&check(ptr,element[jj]))
    {
        element[ii]=element[jj];
        ii=jj;
        jj=getparent(ii);
    }
    return ii;
}
void Heap::insert(Node* ptr)
{
    element.push_back(ptr);
    nelements++;
    int jj=percolateup(nelements);
    element[jj]=ptr;
}
int Heap::percolatedown(int ii)
{
    Node* elast=element[nelements];
    while(ii<nelements)
    {
      int jj=getleft(ii);
      int kk=getright(ii);
      Node* ptr1=NULL;
      Node* ptr2=NULL;
      if(jj<=nelements) ptr1=element[jj];
      if(kk<=nelements) ptr2=element[kk];
      if(check(elast,ptr1)&&check(elast,ptr2))
        break;
      if(check(ptr1,ptr2))
      {
         element[ii]=element[jj];
         ii=jj;
      }
      else
      {
        element[ii]=element[kk];
        ii=kk;
      }
    }
    return ii;
}
Node* Heap::deletemin()
{   
    if(!nelements)
        return  NULL;
    Node* ptr=element[1];
    Node* elast=element[nelements];
    int jj=percolatedown(1);
    element[jj]=elast;
    nelements--;
    element.pop_back();
    return ptr;
}
void InsertintoHeap(Heap&H,vector<Node*>& V,bool b,vector<int>&p,vector<int>&q,int j)
{
    if(!V.size())
        return;
    if(!H.executing)
    {
        H.executing=V[0];
        b=true;
    }
    for(auto it:V)
    {
        if(check(it,H.executing))
        {
            if(!b)
            {
              p.push_back(H.executing->processno);
              q.push_back(j);
              b=true;
            }
            H.insert(H.executing);
            H.executing=it;
            continue;
        }
        if(it!=H.executing)
           H.insert(it);
    }
}
