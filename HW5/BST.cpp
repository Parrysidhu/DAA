#include <iostream>
#include<stdlib.h>
//#include <iomanip>

using namespace std;

#include "BST.h"

//--- Definition of constructor
BST::BST()
: myRoot(0)
{}

bool BST::empty() const
{ return myRoot == 0; }


bool BST::search(const int & item) const
{
   BinNode * locptr = myRoot;
   bool found = false;
   while (!found && locptr != 0)
   {
      if (item < locptr->data)       // descend left
        locptr = locptr->left;
      else if (locptr->data < item)  // descend right
        locptr = locptr->right;
      else                           // item found
        found = true;
   }
   return found;
}


void BST::insert(const int & item)
{
   BinNode * locptr = myRoot;   // search pointer
   BinNode * parent = 0;        // pointer to parent of current node
   bool found = false;     // indicates if item already in BST
   while (!found && locptr != 0)
   {
      parent = locptr;
      if (item < locptr->data)       // descend left
         locptr = locptr->left;
      else if (locptr->data < item)  // descend right
         locptr = locptr->right;
      else                           // item found
         found = true;
   }
   if (!found)
   {                                 // construct node containing item
      locptr = new BinNode(item);
      if (parent == 0)               // empty tree
         myRoot = locptr;
      else if (item < parent->data )  // insert to left of parent
         parent->left = locptr;
      else                           // insert to right of parent
         parent->right = locptr;
   }
   else
      cout << "Item already in the tree\n";
}

//PROBLEM 1: preorder funtion
void BST::preorder(BinNode * node){
    //BinNode * locptr = myRoot;
    //BinNode * curptr;
    if(node!= NULL){
     cout<< node ->data << " ";
     preorder(node-> left);
     preorder(node-> right);
    }
}

//PROBLEM 1: inorder function
void BST::inorder(BinNode * node){

    if(node!=NULL){
        inorder(node->left);
        cout<< node->data<< " ";
        inorder(node->right);
    }
}


//PROBLEM 1: postorder function
void BST::postorder(BinNode * node){

    if(node!=NULL){
        postorder(node->left);
        postorder(node->right);
        cout<< node->data<< " ";
    }
}


//PROBLEM 1: nodecount function
int BST::nodecount(BinNode * node){

    unsigned int c=0;
    if(node!= NULL){
        c=1;
    }
    if(node->left!=NULL){

        c += nodecount(node->left);
    }
     if(node->right!=NULL){

        c += nodecount(node->right);
    }


    //cout<< c<< " ";
    return c;
}


//PROBLEM 2: Delete Node
int BST::Delnode(BinNode * node,const int & item){
    BinNode * locptr = node;
    bool found = false;

    while (!found && node != 0)
   {
      if (item < node->data)       // descend left
        node = node->left;
      else if (node->data < item)  // descend right
        node = node->right;
      else                           // item found
        found = true;
   }
      if(found = true){

        //case 1
        if(node->left==NULL && node->right==NULL){
            delete(node);
            node=NULL;
            //return node;
        }

        //case 2
        else if(node->left==NULL){
            BinNode * temp = node->right;
            node->data= temp->data;
            //node=node->right;
            delete(temp);
        }

        else if(node->right==NULL){
            BinNode * temp = node->left;
            node->data= temp->data;
            //node=node->right;
            delete(temp);
        }

        //case 3
        else{
            BinNode * temp= node->right;

            while(temp->left!= NULL){
                temp=temp->left;
            }
            node->data=temp->data;
            delete(temp);


        }
        //if(node->right==NULL){
          //  node=node->left;
            //delete(node);
            //return node;
        //}
         cout<< "\nvalues inorder after deletion:"
         inorder(locptr);

      }

   }












