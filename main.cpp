// Include necessary headers for file handling, data structures, etc.
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <list>
using namespace std;

// Define a function to simulate a game collection over time
    // Parameters: map of video game conditions, number of intervals
void simulateGame(map<string, vector<list<string>>>, int);
void printCollection(map<string, vector<list<string>>>);

// Define main function
int main() {
    // Initializes a map to store video game collection information, each associated with and array of lists for game genres like action, platformer, and open world
    map<string, vector<list<string>>> collection;
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

void simulateGame(map<string, vector<list<string>>> gameCollection, int interval)
{
    int prob;
    int countGenres = 3;
    string genre[countGenres] = {"Action", "Platformer", "Open-world"}; 
    

    for (size_t i = 0; i < interval; i++)
    {
        cout << "Year #" << i+1 << ":" << endl;
        // Iterate through each genre in the map
        for (auto x : gameCollection)
        {
            for (size_t j = 0; j < countGenres; j++)
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
                    cout << "Sold " << x.second[j].front() << " for " << genre[j] << x.first << endl;
                    x.second[j].pop_front();
                    prob = rand() % 100 + 1;
                }
                // If returning, select a random game from the list to remove only with a different message
                if (prob <= 10)
                {
                    cout << "Returned " << x.second[j].back() << " for " << genre[j] << x.first << endl;
                    x.second[j].pop_back();
                    prob = rand() % 100 + 1;
                }
            }
        }
        printCollection(gameCollection);
                    // Print the changes for this interval, e.g. "Bought {title} for {genre} in {condition}"

                // Simulate more complex collection changes
                // random events impacting collection
                // trends, low on money, etc.

                // Wait or pause briefly to simulate the passage of time between intervals
    }
}

void printCollection(map<string, vector<list<string>>> gameCollection)
{
    int countGenres = 3;
    string genre[countGenres] = {"Action", "Platformer", "Open-world"}; 

    for (auto x : gameCollection)
    {
        cout << "Collection:" << endl;
        cout << "   " << x.first << ":" << endl;
        for (size_t i = 0; i < countGenres; i++)
        {
            cout << "       " << genre[i] << ":" << endl;
            for (string game : x.second[i])
            {
                cout << "           " << game << endl;
            }
        }
    }
    cout << endl;
}
//"New", "Used", "Very Good"