#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

const int maxCandidates = 10;

// array to store the candidate name
string candidates[maxCandidates];
// array to store the candidate's votes
int votes[maxCandidates];

// some additional global values:
int noc = 0;   // number of candidate
int novr = 0;  // number of voters
int vnovr = 0; // number of valid votes
int snovr = 0; // number of spoilt votes

// read in the candidate's name and votes
void readVotes();
void readVotes() {
    
    // define the string for get the input
    string cname;
    // define the int to store each vote
    int vt;
    
    while (true) {
        
        if (noc>=11) break;
        
        getline(cin, cname);
        
        stringstream convert(cname);
        
        // start getting the first line of votes
        if (convert >> vt) {
            do {
                ++novr;
                if (vt>0 && vt<=noc) {
                    ++vnovr;
                    votes[vt-1]++;
                } else {
                    ++snovr;
                }
            } while (convert >> vt); // while
            break;
        } // exit
        if (cin.eof()) break;
        candidates[noc]= cname;
        ++noc;
    } // while
    
    // getting the rest line of votes
    if (vt) {
        while (cin >> vt) {
            ++novr;
            if (vt>0 && vt<=noc) {
                ++vnovr;
                votes[vt-1]++;
            } else {
                ++snovr;
            } // exit
        } // while
    } // exit
} // ReadVotes

// print the output
void printResults();
void printResults() {
    cout << "Number of voters: " << novr << endl;
    cout << "Number of valid votes: " << vnovr << endl;
    cout << "Number of spoilt votes: " << snovr << endl << endl;
    cout << "Candidate      Score" << endl << endl;
    for (int i = 0; i < noc; ++i) {
        cout << candidates[i];
        unsigned short nspace = (15 - candidates[i].length());
        for (int j = 1; j <= nspace; ++j) {
            cout << " ";
        }
        if (votes[i]<10) {
            cout << "  " << votes[i] << endl;
        } else if (votes[i]<100) {
            cout << " " << votes[i] << endl;
        } else {
            cout << votes[i] << endl;
        }
    } // for
} // PrintResults

int main() {
    readVotes();
    printResults();
}
