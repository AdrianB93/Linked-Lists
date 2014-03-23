//
//  Node.h
//  Assignment 2
//
//  Created by Adrian Brown
//  Student c3145942
//  SENG1120 10 / 10 / 2011
//

#ifndef prjTrain_Node_h
#define prjTrain_Node_h
#include <cstdlib>
#include <iostream>
#include "Carriage.cpp"
using namespace std;

namespace Assignment2
{
    template <typename value_type>
    class Node
    {
        
        public:
            // Member variables
            // none
            
            // Constructors
            Node(const value_type &initial_data = value_type(), Node<value_type>* initial_link = NULL);
            // Pre-conditions: The data to be put in the node. If not provided, data is it's default
            //                 The pointer to the next node. If not provided, next linked node is NULL.
            // Post-conditions: New node is initialised
        
            ~Node();
            // Pre-conditions: None
            // Post-conditions: This node deleted, next linked node repeats process
            
            //////
            // Member functions that mutate data
        
            void setData(const value_type &new_data);
            // Pre-conditions: The data to input in the node
            // Post-conditions: The data set in the node
        
            void setLink(Node<value_type> *new_link);
            // Pre-conditions: The pointer to the node to link to
            // Post-conditions: The link sets a pointer to a new node
        
        
            //////
            // Members functions that query data
        
            value_type getData() const;
            // Pre-conditions: None
            // Post-conditions: Returns the data from the node
        
            Node<value_type> *link() const;
            // Pre-conditions: None
            // Post-conditions: Returns a pointer to the next node
        
        
        private:
            // Member variables
            value_type data; // The data to be stored in the node
            Node<value_type> *next; // The next node in the linked list
        
    };
    #include "Node.template"
}

#endif
