//
//  Carriage.h
//  Assignment 2
//
//  Created by Adrian Brown
//  Student c3145942
//  SENG1120 10 / 10 / 2011
//

#ifndef prjTrain_Carriage_h
#define prjTrain_Carriage_h
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

namespace Assignment2
{
    class Carriage
    {
        
    public:
        // Member variables
        // none
        
        // Constructors
        Carriage(int initial_data = 0);
        // Pre-conditions: None
        // Post-conditions: Carriage_load given either the value of the parameter, or 0
        
        ~Carriage();
        // Pre-conditions: None
        // Post-conditions: None
        
        //////
        // Member functions that mutate data
        
        void addCoal(int amount);
        // Pre-conditions: Amount you wish to add to the carriage
        // Post-conditions: Paramater added to the existing amount in carriageLoad
        
        void removeCoal(int amount);
        // Pre-conditions: Amount you wish to subtract from the carriage
        // Post-conditions: Paramater subtracted from the existing amount in carriageLoad
        
        void emptyCarriage();
        // Pre-conditions: None
        // Post-conditions: Resets the carriageLoad variable to 0        
        
            //////
            // Overload functions
        
            void operator += (int other_value);
            // Pre-conditions: Right side integer of the argument's integer value.
            // Post-conditions: Integer added to left side of arguments Carriage object.
        
            friend void operator += (int &left_value, Carriage right_carriage);
            // Pre-conditions: Left side of the arguments integer value
            //                 Right side of the argument's Carriage object.
            // Post-conditions: Carriage object added to left side of arguments integer value.
        
            void operator = (Carriage *other_carriage);
            // Pre-conditions: Right side of the argument's Carrige object.
            // Post-conditions: Left side now equals right side value from object
            
            void operator = (int other_carriage);
            // Pre-conditions: Right side of the argument's value.
            // Post-conditions: Left side now equals right side value
        
            friend int operator + (Carriage left_carriage, int right_value); 
            // Pre-conditions: Right side of the argument's value.
            // Post-conditions: return the value as if left side was added to right side value 
        
        //////
        // Members functions that query data
        
        int getLoad() const;
        // Pre-conditions: None
        // Post-conditions: Return carriage_load variable value
        
            //////
            // Overload functions
        
            bool operator == (Carriage *other_carriage) const;
            // Pre-conditions: The carriage object on the right side to compare
            // Post-conditions: Returns true if the carriage node is the same as the left node
        
            bool operator < (int right_value);
            // Pre-conditions: The carriage object on the right side to compare
            // Post-conditions: Returns true if the carriage node is the same as the left node
            
            int operator + (Carriage *other_carriage) const;
            // Pre-conditions: Right side of the argument's Carrige object.
            // Post-conditions: return the value as if left side was added to right side value from object
        
            friend Carriage operator + (Carriage left_carriage, Carriage right_carriage); 
            // Pre-conditions: Right side of the argument's object.
            //                 Left side of the argument's object.
            // Post-conditions: return the value as if left side was added to right side value
            
            friend Carriage operator - (Carriage left_carriage, Carriage right_carriage); 
            // Pre-conditions: Right side of the argument's value.
            //                 Left side of the argument's object.
            // Post-conditions: return the value as if left side was subtracted from right side value
        
    private:
        // Member variables
        int carriage_load; // Integer value
        
    };
}

#endif
