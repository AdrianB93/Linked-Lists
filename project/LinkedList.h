//
//  LinkedList.h
//  Assignment 2
//
//  Created by Adrian Brown
//  Student c3145942
//  SENG1120 10 / 10 / 2011
//

#ifndef prjTrain_LinkedList_h
#define prjTrain_LinkedList_h
#include "Node.h"

namespace Assignment2
{
    template <typename value_type>
    class LinkedList
    {
        public:
            // Member variables
            // none
        
            // Constructors
            LinkedList();
            // Pre-conditions: none
            // Post-conditions: head_pointer and tail_pointer made NULL
        
            ~LinkedList();
            // Pre-conditions: none
            // Post-conditions: All nodes removed. head_pointer and tail_pointer made NULL
        
            //////
            // Member functions that mutate data
        
            void listHeadInsert(value_type entry);
            // Pre-conditions: The data you wish to store at the head of the linked list
            // Post-consitions: The new node is the head of the list
        
            void listInsert(Node<value_type> *previous_pointer, const value_type &entry);
            // Pre-conditions: The node you wish to insert the new node after. 
            //                 The data for the new node.
            // Post-conditions: The new node is inserted after prev_ptr
        
            void listRemove(Node<value_type> *pointer);
            // Pre-conditions: The node you wish to remove
            // Post-conditions: The node is removed from the list
        
            //////
            // Members functions that query data
        
            int listLength() const;
            // Pre-conditions: None
            // Post-conditions: A count of the nodes in the list is returned
        
            Node<value_type>* listSearch(const value_type &target) const;
            // Pre-conditions: The target that your searching for
            // Post-conditions: A pointer to the first node storing the target is returned.
            //                  If not present, a NULL pointer is returned. Uses cstlib for NULL
        
            Node<value_type>* getHeadPointer() const;
            // Pre-conditions: None
            // Post-conditions: Returns the head pointer
        
            Node<value_type>* getTailPointer() const;
            // Pre-conditions: None
            // Post-conditions: Returns the tail pointer
            
            Node<value_type>* getNode(int node) const;
            // Pre-conditions: The number node you wish to point to
            // Post-conditions: Returns the pointer to the node
        
        private:
            // Member variables
            Node<value_type> *head_pointer; // For linked list to point to the head node
            Node<value_type> *tail_pointer; // For linked list to point to the tail node
    };
    #include "LinkedList.template"
}

#endif
