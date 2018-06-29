template<typename T>
BET<T>::BET(int th){
root=nullptr;
threshold=th;}

template<typename T>
BET<T>::BET(const string input, int th): threshold{th}, root{nullptr}
{ buildFromInputString(input);}

template<typename T> 
BET<T>::BET(const BET& t) //copy constuctor 
{root=clone(t.root);
 threshold=t.threshold;}

template<typename T>
BET<T>::BET(BET&& t) 
{ if(this!=&t){ //could be root and tyhreshold 
   std::swap(root, t.root);
   std::swap(threshold, t.threshold);}
   t.root=nullptr;}

template<typename T>
BET<T>::~BET()
{makeEmpty();}

template<typename T> void 
BET<T>::buildFromInputString(const string input)
{ stringstream x;
  x<<input;
  T element;
  while(x>>element) insert(element);}

template<typename T> const
 BET<T> & BET<T>::operator= (const BET &t) 
{ makeEmpty(); 
root=clone(t.root);
 threshold=t.threshold; 
return *this;}

template<typename T>
const BET<T> & BET<T>::operator=(BET && t)
{makeEmpty(); 
 std::swap(root, t.root);
  std::swap(threshold, t.threshold);
return *this;}

template<typename T>
void BET<T>::makeEmpty(){
 if( root!=nullptr)
   { makeEmpty(root->left);
     makeEmpty(root->right);
     delete root;}
 root=nullptr;}

template<typename T>
bool BET<T>::empty()
{ if(root==nullptr)
   return true;
return false;}

template<typename T> 
void BET<T>::printInOrder() const //call recursively (left root right)
{ printInOrder(root); }

template<typename T>
void BET<T>::printLevelOrder() const //(top->down)
{printLevelOrder(root); }

template<typename T>
int BET<T>::numOfNodes() const
{ return numOfNodes(root);}

template<typename T>
int BET<T>::height() const
{ return height(root);}

template<typename T> 
void BET<T>::insert(const T& v){ insert(v, root); }

template<typename T>
void BET<T>::remove(const T& v){ remove(v, root);}


template<typename T>
bool BET<T>::contains(const T& v){return contains(v, root); }

