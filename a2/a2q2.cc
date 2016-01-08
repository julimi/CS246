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

// the X number(the defined number of votes)
string ind;

// read the candidate name and votes
void readVotes();
void readVotes() {
    
    // define a string to get in
    string cname;
    // define a int to put the converted int
    int vt;
    
    // a copy for vt
    int cvt;
    
    // the number of votes of a voter
    int column = 0;
    
    // the sum of votes of a voter
    int sum = 0;
    
    /* the int to help determine that
     * there is given X or not */
    int x1 = 0;
    int x2 = -1;
    
    // determine the votes reading starts or not
    int start = 0;
    stringstream iind(ind);
    if (iind >> x1) {
        x2 = x1;
    }
    
    while (true) {
        
        if (noc>=11) break;
        
        getline(cin, cname);
        
        stringstream convert(cname);
        stringstream cconvert(cname);
        
        // start getting the line of voter
        if (convert >> vt) {
            
            // no X here
            if (x2 == -1) {
                x2 = noc;
            }
            
            /* running firstly bu copy to get
             * the number of votes and the sum of votes
             * are right or not */
            while (cconvert >> cvt) {
                ++column;
                sum += cvt;
            } // while
            if (column == noc && sum <= x2) {
                
                int j=0;
                do {
                    votes[j] += vt;
                    ++j;
                } while (convert >> vt);
                ++novr;
                ++vnovr;
                column = 0;
                sum = 0;
            }
            
            else {
                ++novr;
                ++snovr;
                column = 0;
                sum = 0;
            } // exit
            ++start;
            continue;
        }
        
        // the situation that there is blank line
        else if (start > 0) {
            if (cin.eof()) break;
            else {
                ++novr;
                // if no canadidate, the blank line is valid
                if (noc == 0) {
                    ++vnovr;
                } else {
                    ++snovr;
                }
                continue;
            }
        } // exit
        
        if (cin.eof()) break;
        candidates[noc]= cname;
        ++noc;
    } // while
} // ReadVotes

// print the output
void printResults();
void printResults() {
    cout << "Number of voters: " << novr << endl;
    cout << "Number of valid ballots: " << vnovr << endl;
    cout << "Number of spoilt ballots: " << snovr << endl << endl;
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
} // PrintResult

int main(int argc, char *argv[]) {
    // Note that loop starts from index 1
    for (int i = 1; i < argc; ++i) {
        ind = argv[i];
    }
    readVotes();
    printResults();
}
