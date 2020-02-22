#ifndef NODE_H 
#define NODE_H

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Node
{
public:
     int processno;
     int priorityvalue;
     int arrivaltime;
     int bursttime;
     Node(int a,int b,int c,int d);
};

#endif
