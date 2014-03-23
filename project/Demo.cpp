//
//  Demo.cpp
//  Assignment 2
//
//  Created by Adrian Brown
//  Student c3145942
//  SENG1120 10 / 10 / 2011
//

#include "Train.h"
#include "Queue.h"

using Assignment2::Carriage;
using Assignment2::Node;
using Assignment2::LinkedList;
using Assignment2::Queue;
using Assignment2::Train;
using namespace std;

int main()
{
    /////////////////////////////////////////////////////////////////////////////////////////////
    // Declare
        // Creates an array of five queues
        Queue<Carriage>* queues[] = 
        {
            new Queue<Carriage>(), 
            new Queue<Carriage>(), 
            new Queue<Carriage>(), 
            new Queue<Carriage>(), 
            new Queue<Carriage>()
        };
    
        // Creates an array of four trains
        Train<Carriage>* trains[] = 
        {
            new Train<Carriage>(), 
            new Train<Carriage>(), 
            new Train<Carriage>(), 
            new Train<Carriage>()
        };
    
        // Random Number Generator
        srand(time(NULL)); // Random number based on the time
        // srand(1234567890); // Random number based on a seed of 1,234,567,890  
    
    /////////////////////////////////////////////////////////////////////////////////////////////
    // Tasks
    
        /////////////////////////////////////////////////////////////////////////////////////////////
        // Table Header
        cout << endl
             << "                A = Average length of Queue | M = Maximum Length of Queue                   " << endl
             << " ------------------------------------------------------------------------------------------ " << endl
             << "|          |                             Number of queues - q                              |" << endl
             << "|----------|-------------------------------------------------------------------------------|" << endl
             << "|    Oc    |         2         |         3         |        4          |         5         |";
    
    
        /////////////////////////////////////////////////////////////////////////////////////////////
        // Process and output simulation body
        for (int Oc = 50000; Oc <= 350000; Oc += 50000) // Test overload capacities from 50,000 to 350,000
        {
            
            cout << endl << "|----------|-------------------|-------------------|-------------------|-------------------|" << endl;
            
            // Output 'Oc' (capacity)
            if (Oc < 100000)
            {
                cout << "|    " << Oc << " | "; // Table format
            }
            else
            {
                cout << "|   " << Oc << " | "; // Table format
            }
            
            /////////////////////////////////////////////////////////////////////////////////////////////
            // Queue columns
            for (int q = 2; q <= 5; q++) // Columns loop
            {
                /////////////////////////////////////////////////////////////////////////////////////////////
                // Row entry - PROCESS
                
                // Declare counters
                int maximum = 0; // Holds the highest amount of carriages held in any queue
                int dailyQueueLength[30]; // Used to calculate the average length of queues
            
                // Month loop
                for (int dayCounter = 0; dayCounter < 30; dayCounter++)
                {
                    // Train arriving in morning
                    int carriageCount[] = {0,0,0,0}; // Will store the count of carriages for each train
                    for (int i = 0; i < 4; i++)// Trains arriving with the coal
                    {
                        // Gives the train between 10 and 20 carraiges
                        carriageCount[i] = rand() % 10 + 10; // RANDOM FROM 10 - 20
                        // carriageCount[i] = 10; // LOWEST RESULT TEST
                        // carriageCount[i] = 20; // HIGHEST RESULT TEST
                    
                        // Fills each of those trains carriages between 4000 and 5000KG
                        for (int j = 0; j < carriageCount[i]; j++)
                        {
                            trains[i] -> addLoad(rand() % 1000 + 4000, j + 1); // RANDOM FROM 4000 - 5000
                            // trains[i] -> addLoad(5000, j + 1); // LOWEST RESULT TEST
                            // trains[i] -> addLoad(4000, j + 1); // HIGHEST RESULT TEST
                        }
                    }
                
                    // Add train's carriages to most empty queue
                    for (int i = 0; i < 4; i++) // Loop for all four trains
                    {
                        // Search for queue with the least carriages
                        int smallest_queue = 0; // Start at first position
                        for (int j = 0; j < q; j++)
                        {
                            if (queues[smallest_queue] -> size() > queues[j] -> size())
                            {
                                smallest_queue = j;
                            }
                        }
                    
                        // Add each carriage of the train to the smallest queue
                        for (Node<Carriage>* pointer = trains[i] -> getFront(); pointer != NULL; 
                             pointer = pointer -> link() ) // Cycle through all train carriages
                        {
                            queues[smallest_queue] -> Enqueue(pointer -> getData()); // Add to end of queue
                        }
                    }
                
                    // Record largest queue length
                    for (int i = 0; i < q; i++)
                    {
                        if (queues[i] -> size() > maximum) // Queue size greater than current recorded maximum
                        {
                            maximum = queues[i] -> size(); // Set as maximum
                        }
                    }
                
                    // Record day's average queue queue length to later calculate the average queue size for the month
                    dailyQueueLength[dayCounter] = (
                                                    queues[0] -> size() + 
                                                    queues[1] -> size() + 
                                                    queues[2] -> size() + 
                                                    queues[3] -> size() + 
                                                    queues[4] -> size() 
                                                   )
                                                   / q; // BODMAS (BRACKETS, OVER, DIVISION, MULTIPLICATION, ADDITION, SUBTRACTION)
                    
                    // Empty Queues until Oc limit is reached
                    int coalRemoved = 0; // Counter for amount of coal removed
                    for (int i = 0; coalRemoved < Oc; i++) 
                    {
                        if (queues[0] -> size() == 0 && 
                            queues[1] -> size() == 0 && 
                            queues[2] -> size() == 0 && 
                            queues[3] -> size() == 0 && 
                            queues[4] -> size() == 0 ) 
                        {
                            coalRemoved = Oc; // No carriages to Dequeue, exit loop
                        }
                        else
                        {
                            if (i == q) // Then it is out of array bounds
                            {
                                i = 0; // Reset back to first queue position
                            }
                            if (queues[i] -> size() != 0) // Queue is not empty
                            {
                                coalRemoved += queues[i] -> getFront() -> getData(); // Add data to counter
                                queues[i] -> Dequeue(); // Remove front carriage
                            }
                        }
                    }
                    
                    // Memory Management
                    for (int i = 0; i < 4; i++)
                    {
                        delete trains[i]; // Delete all trains objects
                        trains[i] = new Train<Carriage>(); // Re-instansiate
                    }
                }
            
                // Average lenth of queue
                double average_length = 0.0; // Stores the average length over 30 days
                for (int i = 0; i < 30; i++)
                {
                    average_length += dailyQueueLength[i]; // Total of all days
                }
                average_length /= 30; // Dividing by 30 (days) for average queue length
            
                
                /////////////////////////////////////////////////////////////////////////////////////////////
                // Row entry - OUTPUT
                
                // Average
                if (average_length < 10)
                {
                    cout << "A: " << fixed << setprecision(2) << average_length << "   ";
                }
                else if (average_length < 100)
                {
                    cout << "A: " << fixed << setprecision(2) << average_length << "  ";
                }
                else if (average_length < 1000) // Largest possible average is 525.50
                {
                    cout << "A: " << fixed << setprecision(2) << average_length << " ";
                }
                else // Over 1000
                {
                    cout << "A: " << fixed << setprecision(2) << average_length;
                }
            
                // Maximum
                if (maximum < 10)
                {
                    cout << "M: " << maximum << "    | "; // Table format
                }
                else if (maximum < 100)
                {
                    cout << "M: " << maximum << "   | "; // Table format
                }
                else if (maximum < 1000)
                {
                    cout << "M: " << maximum << "  | "; // Table format
                }
                else // Over 1000, largest maximum is 1017
                {
                    cout << "M: " << maximum << " | "; // Table format
                }
                
                // Memory Management
                for (int i = 0; i < 5; i++)
                {
                    delete queues[i]; // Delete all queues objects
                    queues[i] = new Queue<Carriage>(); // Re-instantiate
                }
            }
        }
    
    /////////////////////////////////////////////////////////////////////////////////////////////
    // Table footer
    cout << endl 
         << " ------------------------------------------------------------------------------------------ " 
         << endl 
         << endl;
    
    return 0;
}
