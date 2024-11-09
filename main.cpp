// Include necessary headers for file handling, data structures, etc.
#include <iostream>
#include <fstream>
#include <map>
#include <list>
using namespace std;

// Define a function to simulate a game collection over time
    // Parameters: map of video game conditions, number of intervals
void simulateGame(map<string, list<string>, list<string>, list<string>>, int);

// Define main function
int main() {
    // Initializes a map to store video game collection information, each associated with and array of lists for game genres like action, platformer, and open world
    map<string, list<string>, list<string>, list<string>> collection;
    ifstream ifs;

    // Open an external file to read initial data about game's condition and populate the map
        // If file does not open, print an error and exit
    ifs.open("data.txt");
    if (ifs)
    {
        // Read data from file and populate map
        // For each line, extract game condition, and game genre
        // Insert game into the appropriate list in the array for their genre

        // Close the file
    }
    else
    {
        cout << "ERROR: Could not read file" << endl;
        exit(EXIT_FAILURE);
    }

    // Begin a time-based simulation for game collection
        // For 20 time intervals
    simulateGame(collection, 20);
    // End of main function
}

void simulateGame(map<string, list<string>, list<string>, list<string>> gameCollection, int interval)
{
    int prob;
    string conditions[3] = {"New", "Used", "Very Good"};
    

    for (size_t i = 0; i < interval; i++)
    {
        // Iterate through each genre in the map
        for (auto x : gameCollection)
        {
            // For each genre, simulate changes
            // Randomly decide if a game will be bought, sold, or returned from each genre (action, platformer, open world)
            prob = rand() % 100 + 1;
            
            // If adding, generate or select a new game title to add to the list
            if (prob <= 50)
            {
                prob = rand() % 100 + 1;
            }
            // If selling, select a random game from the list to remove
            if (prob <= 20)
            {
                x.second.pop_front();
                prob = rand() % 100 + 1;
            }
            // If returning, select a random game from the list to remove only with a different message
            if (prob <= 10)
            {
                cout << "Returned " << x.second.back() << " for " << x.second
                x.second.pop_back();
                prob = rand() % 100 + 1;
            }
        }
                    // Print the changes for this interval, e.g. "Bought {title} for {genre} in {condition}"

                // Simulate more complex collection changes
                // random events impacting collection
                // trends, low on money, etc.

                // Wait or pause briefly to simulate the passage of time between intervals
    }
}