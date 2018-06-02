template<typename T>
BST<T>::BST(int th){
root=nullptr;
threshold=th;}

template<typename T>
BST<T>::BST(const string input, int th): threshold{th}, root{nullptr}
{ buildFromInputString(input);}

template<typename T> 
BST<T>::BST(const BST& t) //copy constuctor 
{root=clone(t.root);
 threshold=t.threshold;}

template<typename T>
BST<T>::BST(BST&& t) 
{ if(this!=&t){ //could be root and tyhreshold 
   std::swap(root, t.root);
   std::swap(threshold, t.threshold);}
   t.root=nullptr;}

template<typename T>
BST<T>::~BST()
{makeEmpty();}

template<typename T> void 
BST<T>::buildFromInputString(const string input)
{ stringstream x;
  x<<input;
  T element;
  while(x>>element) insert(element);}

template<typename T> const
 BST<T> & BST<T>::operator= (const BST &t) 
{ makeEmpty(); 
root=clone(t.root);
 threshold=t.threshold; 
return *this;}

template<typename T>
const BST<T> & BST<T>::operator=(BST && t)
{makeEmpty(); 
 std::swap(root, t.root);
  std::swap(threshold, t.threshold);
return *this;}

template<typename T>
void BST<T>::makeEmpty(){
 if( root!=nullptr)
   { makeEmpty(root->left);
     makeEmpty(root->right);
     delete root;}
 root=nullptr;}

template<typename T>
bool BST<T>::empty()
{ if(root==nullptr)
   return true;
return false;}

template<typename T> 
void BST<T>::printInOrder() const //call recursively (left root right)
{ printInOrder(root); }

template<typename T>
void BST<T>::printLevelOrder() const //(top->down)
{printLevelOrder(root); }

template<typename T>
int BST<T>::numOfNodes() const
{ return numOfNodes(root);}

template<typename T>
int BST<T>::height() const
{ return height(root);}

template<typename T> 
void BST<T>::insert(const T& v){ insert(v, root); }

template<typename T>
void BST<T>::remove(const T& v){ remove(v, root);}


template<typename T>
bool BST<T>::contains(const T& v){return contains(v, root); }

