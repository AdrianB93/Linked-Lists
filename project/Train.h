//
//  Train.h
//  Assignment 2
//
//  Created by Adrian Brown
//  Student c3145942
//  SENG1120 10 / 10 / 2011
//

#ifndef prjTrain_Train_h
#define prjTrain_Train_h
#include "LinkedList.h"
using Assignment2::LinkedList;
using Assignment2::Node;

namespace Assignment2
{
    template <typename value_type>
    class Train
    {
        public:
            //////
            // Constructor
        
            Train();
            // Pre-conditions: none
            // Post-conditions: Empty linked list
        
            ~Train();
            // Pre-conditions: none
            // Post-conditions: Linked list removed in train
        
            Train(int arr[]);
            // Pre-conditions: Array of integers. Length of array.
            // Post-conditions: New linked list with each array position copied to their own nodes.
            
            //////
            // Member functions that mutate data
        
            void addLoad(value_type i, int j);
            // Pre-conditions: Load to add as an integer. Which number carriage to add to.
            // Post-conditions: i Load added to the jth node/carriage
        
            void removeLoad(value_type i, int j);
            // Pre-conditions: Load to subtract. Which number carriage to subtract from.
            // Post-conditions: i Load subtracted to the jth node/carriage
            //                  If i is larger than the data, data is set to 0
        
            //////
            // Member functions that query data
        
            int size() const;
            // Pre-conditions: none
            // Post-conditions: Returns the integer from the listLength() function in the LinkedList class
        
            int totalLoad() const;
            // Pre-conditions: none
            // Post-conditions: Each node added together and returned.
        
            int countEmpty() const; 
            // Pre-condition: none
            // Post-condition: returns how many nodes hold the value "0"
        
            Node<value_type>* getFront() const;
            // Pre-condition: none
            // Post-condition: returns head_pointer of LinkedList
                
        private:
            // Member variables
            LinkedList<value_type> *carriages; // A linked list where nodes are represented as carraiges
    };
    
    #include "Train.template"
}

#endif
