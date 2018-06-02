#ifndef BST_H
#define BST_H
#include<iostream>
#include<string>
#include<queue>
#include<sstream>
using namespace std;

const int default_threshold_value=1;
namespace Binary_Search_Tree{

template<typename T>
class BST{
public:
 BST(int th=default_threshold_value);
 BST(const string input, int th=default_threshold_value);
 BST(const BST& t);//copy
 BST(BST&& t);//move
 ~BST();
 void buildFromInputString(const string input);//build tree from input string 
 const BST & operator= (const BST & t);
 const BST & operator= (BST && t);
 bool empty();
  
 void printInOrder() const;
 void printLevelOrder() const;
 int numOfNodes() const;
 int height() const;
 void makeEmpty();
 void insert(const T& v); 
 void insert(T &&v);
 void remove(const T& v);
 bool contains(const T& v);
 
 private:
  struct BSTNode{
        T element;
        int search=0;
        BSTNode *left;
        BSTNode *right;
        BSTNode(const T& theElement, BSTNode *lt, BSTNode *rt ):
          element{theElement}, left{lt}, right{rt}{}
        BSTNode(T&& theElement, BSTNode* lt, BSTNode *rt):
          element{ std::move(theElement)}, left{lt}, right{rt}{}
  };
  BSTNode *root;
  int threshold;
 
  void printInOrder(BSTNode *t) const
  { if(t != nullptr){
	printInOrder(t->left);
	cout << t->element <<" ";
	printInOrder(t->right);}}

  void printLevelOrder(BSTNode *t) const
 { 	queue<BSTNode*> tree;
	if(t==false) //if node empty, return 
		return;
	int currNodes = 1;
	int nextNodes = 0;
	tree.push(t);// push node on tree queue

	while(tree.empty() ==false){
	   BSTNode *n = tree.front();
           tree.pop();
    	   --currNodes;
		if(n)
                {cout<<n->element<<" ";
		 tree.push(n->left);
	       	 tree.push(n->right);
		nextNodes += 2;}
		if(currNodes == 0)
		{currNodes = nextNodes;
	  	nextNodes = 0;}
	}
    
 }
  void makeEmpty(BSTNode* &t){
  if( t != nullptr )
   { makeEmpty( t->left );
     makeEmpty( t->right );
      delete t; }
     t = nullptr; }

  void insert(const T& v, BSTNode *&t){
  if(t == nullptr )
     t = new BSTNode{v, nullptr, nullptr };
  else if(v< t->element)
    insert(v,t->left);
   else if(t->element <v)
    insert(v, t->right );
   else; }
  
 void remove(const T& v, BSTNode *&t){
  if(t == nullptr )
    return; // Item not found; do nothing
   if(v< t->element)
     remove(v,t->left );
   else if( t->element <v )
     remove(v, t->right );
   else if(t->left!= nullptr && t->right!= nullptr) // Two children
   { t->element = findMin( t->right )->element;
     remove( t->element, t->right ); }
   else {
    BSTNode *oldNode = t;
    t = ( t->left != nullptr ) ? t->left : t->right;
   delete oldNode; }}

   BSTNode * findMin(BSTNode *t ) const
    { if( t == nullptr )
         return nullptr;
      if( t->left == nullptr )
         return t;
      return findMin( t->left ); }

   bool contains(const T& v, BSTNode *&t)
  { if( t==nullptr ) return false;
    else if(v!=root->element)
    {  if(t->left!= nullptr){
	if(v==t->left->element){
	    t->left->search++;
       	    if(t->left->search%threshold==threshold)
               RotateLeft(t);
	       return true;}} 
        if(t->right!=nullptr){
	    if(v==t->right->element){
		t->right->search++;
		if(t->right->search%threshold==threshold)
		   RotateRight(t);
		   return true;}}
		if (v<t->element){return contains(v,t->left );} //call recursively
		if (v>t->element){return contains(v,t->right );}
		else return false;}
    else 
     {root->search=root->search+1;
      return true;}
/*
    else if( v < t->element )
   return contains( v, t->left );
   else if( t->element < v )
   return contains( v, t->right );
   else return true; */
}

  
  int numOfNodes(BSTNode *t) const{
  if(t == nullptr) return 0;
  else if(t->left == nullptr && t->right == nullptr)
    return 1;
  else 
    return numOfNodes(t->left) + numOfNodes(t->right)+1;  }


  int height(BSTNode *t) const{
   int r = 0, l= 0;
	if(t == nullptr)  return -1;
         r= height(t->right);
         l= height(t->left);
	if(l > r)
	  return l+1;
	 else
          return r+1;	
  }
   
  BSTNode * clone(BSTNode *t) const{
   if( t == nullptr )
   return nullptr;
   else
   return new BSTNode{t->element,clone(t->left),clone(t->right)};}

  void RotateLeft(BSTNode *&t){         
  BSTNode *temp = t;        
  t = t->left;        
  temp->left = t->right;         
   t->right = temp;}        

   void RotateRight(BSTNode *&t){         
   BSTNode *temp=t;          
   t=t->right;          
   temp->right=t->left;          
   t->left = temp;}    
 
};

#include "BST.hpp" 
}//end of namespace COP4530
#endif
