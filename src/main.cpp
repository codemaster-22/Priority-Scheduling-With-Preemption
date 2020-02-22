#include "../include/Heap.h"
#include "../include/Heap.h"

int main() {
    int n;
    cin>>n;
    vector<Node*> V;
    int a,b,c,d;
    Node* ptr;
    while(n--)
    {
        cin>>a>>b>>c>>d;
        ptr=new Node(a,b,c,d);
        V.push_back(ptr);
    }
    int index=0;
    long int sum=0;
    for(auto it:V)
    {
        sum+=it->bursttime;
    }
    long int k=V[V.size()-1]->arrivaltime+50;
    k=(k>sum)?k:sum;
    vector<Node*> temp;
    Heap H;
    vector<int> p,q;
    long int j;
    for(j=0;j<=k;++j)
    { 
      while(index<V.size()&&V[index]->arrivaltime==j)
      {
          temp.push_back(V[index]);
           index++;
      }
      if(H.executing)
          H.executing->bursttime--;
      if(H.executing&&H.executing->bursttime==0)
      {
       p.push_back(H.executing->processno);
       q.push_back(j);
       Node* ptr=NULL;
       if(H.nelements)
        {
          H.printpreorder();
          ptr=H.deletemin();
        }
        H.executing=ptr;
        InsertintoHeap(H,temp,true,p,q,j);
      }
      else
      {
        InsertintoHeap(H,temp,false,p,q,j);
      }
      temp.clear();
    }
    if(H.executing)
    {
     p.push_back(H.executing->processno);
     q.push_back(j);
    }
    for(auto r:p)
    {
        cout<<r<<" ";
    }
    if(p.size())
      cout<<endl;
    for(auto s:q)
    {
        cout<<s<<" ";
    }
    return 0;
}
