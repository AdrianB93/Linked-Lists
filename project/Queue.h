//
//  Queue.h
//  Assignment 2
//
//  Created by Adrian Brown
//  Student c3145942
//  SENG1120 10 / 10 / 2011
//

#ifndef prjTrain_Queue_h
#define prjTrain_Queue_h
#include "LinkedList.h"

namespace Assignment2
{
    template <typename value_type>
    class Queue
    {
        public:
            // Member variables
            // none
        
            //////
            // Constructor
        
            Queue();
            // Pre-conditions: none
            // Post-conditions: New blank linked list.
        
            ~Queue();
            // Pre-conditions: none
            // Post-conditions: Linked list removed
            
            //////
            // Member functions that mutate data
        
            void Enqueue(value_type object);
            // Pre-conditions: The object to add to the queue
            // Post-conditions: Objects nodes are placed at the end of the queue
        
            void Dequeue();
            // Pre-conditions: none
            // Post-conditions: Objects front node removed
        
            //////
            // Member functions that query data
        
            int size();
            // Pre-conditions: none
            // Post-conditions: Return amount of nodes in the linked list
            
            Node<value_type>* getFront() const;
            // Pre-condition: none
            // Post-condition: returns head_pointer of LinkedList
            
        private:
            // Member variables
            LinkedList<value_type> *queue_data;
    };
    #include "Queue.template"
}

#endif
