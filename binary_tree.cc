#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<queue>
#include<stack>
using namespace std;
void swap(int &a, int &b)
{
  int temp=a;
  a=b;
  b=temp;
}

//define a class for binary tree;
class bst
{
  private:
    int *_nodes;
    int _len;
  public:
    bst(int* nodes, int len);
    ~bst();
    void print();
    void pretty_print();
    void max_heapify(int pos);
    void build_max_heap();
    void in_order(int index);
    void post_order(int index);
    void pre_order(int index);
    void sort();
    int left_child(int i){return _nodes[2*i+1];};
    int right_child(int i){return _nodes[2*i+2];};
};

bst::bst(int* nodes, int len)
{
  _nodes=new int[len];
  _len = len;
  memcpy(_nodes, nodes, sizeof(int)*len);
}

bst::~bst() {}

void bst::print()
{
  for(int i=0; i< _len; i++)
    printf("%d ", _nodes[i]);
  printf("\n");
}

void bst::pre_order(int index)
{
  stack<int> nodes;
  nodes.push(0);
  while(!nodes.empty())
  {
    int index=nodes.top();
    nodes.pop();
    if(index<_len)
      printf("%d ", _nodes[index]);
    int lc = 2*index+1;
    int rc = 2*index+2;
    if(rc<_len)
      nodes.push(rc);
    if(lc<_len)
      nodes.push(lc);
  }
  printf("\n");
}


void bst::in_order(int index)
{
  if(index>=_len)
    return;
  int lc=2*index+1;
  in_order(lc);
  printf("%d ", _nodes[index]);
  int rc=2*index+2;
  in_order(rc);
}

void bst::post_order(int index)
{
  if(index>=_len)
    return;
  int lc=2*index+1;
  post_order(lc);
  int rc=2*index+2;
  post_order(rc);
  printf("%d ", _nodes[index]);
}



void bst::sort()
{
  int len=_len;
  for(int i=0; i<len; i++)
  {
    swap(_nodes[0], _nodes[len-i-1]);
    _len=_len-1;
    max_heapify(0);
  }
  _len=len;
}


//BFS
void bst::pretty_print()
{
  queue<int> nodes[2];
  queue<int> nnodes;
  nodes[0].push(0);
  int level=0;
  while(!nodes[0].empty() || !nodes[1].empty())
  {
    int i=level%2;
    while(!nodes[i].empty())
    {
      int index=nodes[i].front();
      nodes[i].pop();
      if(index<_len)
        printf("%d ", _nodes[index]);
      int lc = 2*index+1;
      int rc = 2*index+2;
      if(lc<_len)
        nodes[1-i].push(lc);
      if(rc<_len)
        nodes[1-i].push(rc);
    }
    printf("\n");
    level+=1;
  }
}

void bst::build_max_heap()
{
  int pos = _len/2;
  for(int i=pos; i>0; i--)
  {
    max_heapify(i-1);
  }
}

void bst::max_heapify(int pos)
{
  int lc=2*pos+1;
  int rc=2*pos+2;
  int largest = pos;
  if( lc < _len && _nodes[largest]< _nodes[lc])
  {
    largest = lc;
  }
  if( rc < _len &&  _nodes[largest] < _nodes[rc])
  {
    largest = rc;
  }
  if (largest != pos)
  {
    swap(_nodes[pos], _nodes[largest]);
    max_heapify(largest);
  }
}


int main(int argc, char**argv)
{
  //int tree[]={8,3,10,1,6,14,0,4,7,13,20};
  int tree[]={4,1,3,2,16,9,10,14,8,7};

  int len = sizeof(tree)/sizeof(int);
  class bst max_hp(tree, len);
  max_hp.print();
  max_hp.build_max_heap();
  max_hp.print();
  max_hp.pretty_print();

  //max_hp.in_order(0);
  //max_hp.post_order(0);
  //printf("\n");
  //max_hp.pre_order(0);
  return 0;
}

