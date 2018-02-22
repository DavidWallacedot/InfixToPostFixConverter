//David Wallace
//2/22/2018
#ifndef DYNAMICQUEUE_H
#define DYNAMICQUEUE_H
#include <iostream>
using namespace std;
template <typename T>
class Queue
{
private:
   // Structure for the queue nodes
   struct QueueNode
   {
      T value;			// Value in a node
      QueueNode *next;	// Pointer to the next node
   };

   QueueNode *front;  // The front of the queue
   QueueNode *rear;   // The rear of the queue
   int numItems;      // Number of items in the queue
public:
   // Constructor
   Queue();

   // Destructor
   ~Queue();

   // Queue operations
   void push_back(T);
   T pop_front();
   bool isEmpty() const;
   void display()const;
};

template <typename T>
Queue<T>::Queue()
{
   front = NULL;
   rear = NULL;
   numItems = 0;
}

template <typename T>
Queue<T>::~Queue()
{
  T value;   // Dummy variable for pop_front
    while(!isEmpty())
       pop_front();

}

template <typename T>
void Queue<T>::push_back(T item)
{
   QueueNode *newNode = NULL;

   // Create a new node and store num there.
   newNode = new QueueNode;
   newNode->value = item;
   newNode->next = NULL;

   // Adjust front and rear as necessary.
   if (isEmpty())
   {
      front = newNode;
      rear = newNode;
   }
   else
   {
      rear->next = newNode;
      rear = newNode;
   }

   // Update numItems.
   numItems++;
}

template <typename T>
T Queue<T>::pop_front()
{
   QueueNode *temp = NULL;

   if (isEmpty())
   {
      cout << "The queue is empty.\n";
   }
   else
   {
      // Save the front node value in num.
      T object = front->value;

      // Remove the front node and delete it.
      temp = front;
      front = front->next;
      delete temp;

      // Update numItems.
      numItems--;
	  return object;
   }
}

template <typename T>
bool Queue<T>::isEmpty() const
{
    bool status;

    if (numItems > 0)
       status = false;
    else
       status = true;
    return status;
}

template <typename T>
void Queue<T>::display()const{
	
	string display;
	QueueNode* temp = front;
	
	while(temp->next != NULL){
		if(temp->value=='\0'){}//removes \0 from display if in queue
		else{display+=temp->value;}
		temp = temp->next;
		}
	
	cout<<display<<endl;
}

#endif