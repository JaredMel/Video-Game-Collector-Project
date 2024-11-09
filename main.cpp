// Include necessary headers for file handling, data structures, etc.
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <list>
using namespace std;

// Define a function to simulate a game collection over time
    // Parameters: map of video game conditions, number of intervals
void simulateGame(map<string, vector<list<string>>>, vector<string>, int);
void printCollection(map<string, vector<list<string>>>);

// Define main function
int main() {
    // Initializes a map to store video game collection information, each associated with and array of lists for game genres like action, platformer, and open world
    map<string, vector<list<string>>> collection;
    vector<string> games;
    vector<list<string>> genres1;
    vector<list<string>> genres2;
    vector<list<string>> genres3;
    string title;
    ifstream ifs;

    // Open an external file to read initial data about game's condition and populate the map
        // If file does not open, print an error and exit
    list<string> action1 = {"ActionGame"};
    genres1.push_back(action1);
    list<string> platformer1 = {"PlatformGame"};
    genres1.push_back(platformer1);
    list<string> open_world1 = {"OpenWorldGame"};
    genres1.push_back(open_world1);
    list<string> action2 = {"CallofDuty1"};
    genres2.push_back(action2);
    list<string> platformer2 = {"SuperMarioBros"};
    genres2.push_back(platformer2);
    list<string> open_world2 = {"BreathofTheWild"};
    genres2.push_back(open_world2);
    list<string> action3 = {"CallofDuty2"};
    genres3.push_back(action3);
    list<string> platformer3 = {"SuperMarioBros2"};
    genres3.push_back(platformer3);
    list<string> open_world3 = {"TearsofTheKingdom"};
    genres3.push_back(open_world3);
    collection.insert({"New", genres1});
    collection.insert({"Used", genres2});
    collection.insert({"Very Good", genres3});

    ifs.open("games.txt");
    if (ifs)
    {
        for (size_t i = 0; i < 99; i++)
        {
            getline(ifs, title);
            games.push_back(title);
        }
        ifs.close();
    }
    else
    {
        cout << "ERROR: Could not read file" << endl;
        exit(EXIT_FAILURE);
    }

    // Begin a time-based simulation for game collection
        // For 20 time intervals
    simulateGame(collection, games, 20);
    // End of main function
}

void simulateGame(map<string, vector<list<string>>> gameCollection, vector<string> gamesVec, int interval)
{
    int prob;
    int ran;
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
                    ran = rand() % 99;
                    x.second[j].push_back(gamesVec[ran]);
                    cout << "Bought " << x.second[j].back() << " for " << genre[j] << x.first << endl;
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