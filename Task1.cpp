#include <iostream>
#include <string>
using namespace std;
void addCandidates(string candidates[], int& numCandidates);
void castVote(const string candidates[], int numCandidates, int votes[]);
void displayResults(const string candidates[], const int votes[], int numCandidates);
int main() {
    const int MAX_CANDIDATES = 10;
    string candidates[MAX_CANDIDATES];
    int votes[MAX_CANDIDATES] = {0};
    int numCandidates = 0;
    int choice;
    while (true) {
        cout << "Voting System Menu:" << endl;
        cout << "1. Add candidates" << endl;
        cout << "2. Cast a vote" << endl;
        cout << "3. Display results" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  
        if (choice == 1) {
            addCandidates(candidates, numCandidates);
        } else if (choice == 2) {
            castVote(candidates, numCandidates, votes);
        } else if (choice == 3) {
            displayResults(candidates, votes, numCandidates);
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}
void addCandidates(string candidates[], int& numCandidates) {
    cout << "Enter the number of candidates (max 10): ";
    cin >> numCandidates;
    cin.ignore();  
    if (numCandidates > 10) {
        numCandidates = 10;
        cout << "Maximum number of candidates is 10. Setting to 10." << endl;
    }
    for (int i = 0; i < numCandidates; ++i) {
        cout << "Enter the name of candidate " << i + 1 << ": ";
        getline(cin, candidates[i]);
    }
}
void castVote(const string candidates[], int numCandidates, int votes[]) {
    if (numCandidates == 0) {
        cout << "No candidates available. Please add candidates first." << endl;
        return;
    }
    cout << "Enter the name of the candidate you want to vote for: ";
    string vote;
    getline(cin, vote);
    bool validVote = false;
    for (int i = 0; i < numCandidates; ++i) {
        if (candidates[i] == vote) {
            votes[i]++;
            validVote = true;
            cout << "Vote casted for " << candidates[i] << "." << endl;
            break;
        }
    }
    if (!validVote) {
        cout << "Invalid candidate name. Please try again." << endl;
    }
}
void displayResults(const string candidates[], const int votes[], int numCandidates) {
    if (numCandidates == 0) {
        cout << "No results to display. Please add candidates and cast votes first." << endl;
        return;
    }
    cout << "Election Results:" << endl;
    for (int i = 0; i < numCandidates; ++i) {
        cout << candidates[i] << ": " << votes[i] << " votes" << endl;
    }
}