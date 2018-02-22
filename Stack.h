//David Wallace
//2/22/2018
#ifndef DYNAMICSTACK_H
#define DYNAMICSTACK_H
#include<iostream>
using namespace std;
template <typename T>
class Stack{
	private:
   // Structure for the stack nodes
   struct StackNode
   {
      T value;          // Value in the node
      StackNode *next;  // Pointer to next node
   };
   
   StackNode *top;     // Pointer to the stack top

public:
   //Constructor
   Stack()
   { top = NULL; }
   
   // Destructor
   ~Stack();
   
   // Stack operations
   void push(T);
   T pop();
   bool isEmpty();
	T peek();
};

template <typename T>
Stack<T>::~Stack()
{
   StackNode *nodePtr, *nextNode;

   // Position nodePtr at the top of the stack.
   nodePtr = top;

   // Traverse the list deleting each node.
   while (nodePtr != NULL)
   {
      nextNode = nodePtr->next;
      delete nodePtr;
      nodePtr = nextNode;
   }
}


template <typename T>
void Stack<T>::push(T item)
{
   StackNode *newNode = NULL; // Pointer to a new node

   // Allocate a new node and store num there.
   newNode = new StackNode;
   newNode->value = item;

   // If there are no nodes in the list
   // make newNode the first node.
   if (isEmpty())
   {
      top = newNode;
      newNode->next = NULL;
   }
   else  // Otherwise, insert NewNode before top.
   {
      newNode->next = top;
      top = newNode;
   }
}

template <typename T>
T Stack<T>::pop()
{
   StackNode *temp = NULL; // Temporary pointer

   // First make sure the stack isn't empty.
   if (isEmpty())
   {
      cout << "The stack is empty. from the pop\n";
   }
   else  // pop value off top of stack
   {
	   T object = top->value;
      temp = top->next;
      delete top;
      top = temp;
	  return object;
   }
}

template <typename T>
bool Stack<T>::isEmpty()
{
   bool status;

   if (!top)
      status = true;
   else
      status = false;

   return status;
}

template <typename T>
T Stack<T>::peek()
{
   T object;
   // First make sure the stack isn't empty.
   if (isEmpty())
   {
      cout << "The stack is empty.\n";
   }
   else  
   {
      return top->value;
   }
}
#endif