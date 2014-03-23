//
//  Carriage.cpp
//  Assignment 2
//
//  Created by Adrian Brown
//  Student c3145942
//  SENG1120 10 / 10 / 2011
//
#include "Carriage.h"
#include <iostream>

namespace Assignment2
{
    /////////////////////////////////////////////////////////////////////////////////////////////
    // Constructors
    Carriage::Carriage(int initial_data)
    {
        carriage_load = initial_data; // Sets data as the provided parameter or it's default
    }
        
    Carriage::~Carriage()
    {
        // Nothing to delete, stack has automatic garbage collection
    }
    
    /////////////////////////////////////////////////////////////////////////////////////////////
    // Mutate functions
    void Carriage::addCoal(int amount)
    {
        carriage_load += amount; // Add amount to coal count
    }
    
    void Carriage::removeCoal(int amount)
    {
        carriage_load -= amount; // Subtract amount from coal count
    }
    
    void Carriage::emptyCarriage()
    {
        carriage_load = 0; // Set objects integer value to 0
    }
    
    void operator += (int &left_value, Carriage right_carriage)
    {
        left_value += right_carriage.getLoad(); // Add right carriage's load left integer values
    }
    
    void Carriage::operator += (int other_carriage)
    {
        carriage_load += other_carriage; // Add left integer value to right carriages load
    }
    
    void Carriage::operator = (Carriage *other_carriage)
    {
        carriage_load = other_carriage -> getLoad(); // Makes this classes load equal the parameter's load
    }
    
    void Carriage::operator = (int other_carriage)
    {
        carriage_load = other_carriage; // Makes this classes load equal the parameter's integer
    }
    
    int Carriage::operator + (Carriage *other_carriage) const
    {
        return carriage_load + other_carriage -> getLoad();  // Return this load + parameter's load
    }
    
    int operator + (Carriage left_carriage, int right_value)
    {
        return left_carriage.getLoad() + right_value; // Return left carriage + right integer
    }
    
    /////////////////////////////////////////////////////////////////////////////////////////////
    // Query functions
    Carriage operator + (Carriage left_carriage, Carriage right_carriage)
    {
        // Create a Carriage to return
        Carriage *cTemp = new Carriage(left_carriage.getLoad() + right_carriage.getLoad()); // Add the parameters together as the parameter for the constructor
        return *cTemp; // Return the value
    }
    
    bool Carriage::operator < (int right_value)
    {
        return (carriage_load < right_value); // True or False if carriage_load is less than the integer parameter
    }
    
    int Carriage::getLoad() const
    {
        return carriage_load; // Return carriage_load integer value
    }
}
