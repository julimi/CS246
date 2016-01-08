#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

// very big original index for the number of series
int oindex = 1000000;

// structure contains various information of credit card:
string *chname = new string[oindex];     // the array to store the name of card holder:
string *cn = new string[oindex];         // the array to store the card numbers
int *em = new int[oindex];               // the array to store month of expiry date
int *ey = new int[oindex];               // the array to store year of expiry date
string *tn = new string[oindex];         // the array to store transition number
int *td = new int[oindex];               // the array to store the day of transition date
int *tm = new int[oindex];               // the array to store the month of transition date
int *ty = new int[oindex];               // the array to store the year of transition date
string *tt = new string[oindex];         // the array to store the time of transition date
string *amount = new string[oindex];     // the array to store the amount of money

// the array to store the status of cards:
string *cstatus = new string[oindex];

// the number of transition
int ntran = 0;

// the function to store all information
void storeinfo();
void storeinfo() {
    string cardin;
    int ncardin;
    while (true) {
        
        // get the holder's name
        getline(cin, cardin);
        chname[ntran] = cardin;
        
        getline(cin, cardin);
        cn[ntran] = cardin;
        
        cin >> ncardin;
        em[ntran] = ncardin;
        
        cin >> ncardin;
        ey[ntran] = ncardin;
        
        cin >> cardin;
        tn[ntran] = cardin;
        
        cin >> ncardin;
        td[ntran] = ncardin;
        
        cin >> ncardin;
        tm[ntran] = ncardin;
        
        cin >> ncardin;
        ty[ntran] = ncardin;
        
        cin >> cardin;
        tt[ntran] = cardin;
        
        cin >> cardin;
        amount[ntran] = cardin;
        
        if (cin.eof()) break;
        else ntran++;
        
        cin.ignore();
        cin.clear();
    } // exit
}

// the function to determine the card whether valid or not
void dvalidon();
void dvalidon() {
    int ntest,sum;
    string stest;
    unsigned long length;
    if (ntran > 0) {
        for (int i = 0; i<ntran; ++i) {
            length = cn[i].length();
            sum = 0;
            
            if (length != 13 && length != 16) {
                cstatus[i] = "invalid";
                continue;
            }
            
            if (cn[i][0] != '4') {
                cstatus[i] = "invalid";
                continue;
            }
            
            if (length == 13) {
                for (int j = 0; j < length; ++j) {
                    stest = cn[i][j];
                    stringstream cton(stest);
                    cton >> ntest;
                    if ((j%2)==0) {
                        sum += ntest;
                    } else {
                        ntest *= 2;
                        if (ntest > 9) ntest = ntest/10 + ntest%10;
                        sum += ntest;
                    }
                }
            } else {
                for (int j = 0; j < length; ++j) {
                    stest = cn[i][j];
                    stringstream cton(stest);
                    cton >> ntest;
                    if ((j%2)!=0) {
                        sum += ntest;
                    } else {
                        ntest = 2 * ntest;
                        if (ntest > 9) ntest = ntest/10 + ntest%10;
                        sum += ntest;
                    }
                }
            }
            if ((sum%10) == 0) {
                cstatus[i] = "valid";
            } else {
                cstatus[i] = "invalid";
            }
        }
    }
}

// print the results
void PrintResult();
void PrintResult() {
    if (ntran > 0) {
        for (int i = 0; i<ntran; ++i) {
            
            if (tn[i].length()==5) cout << tn[i] << " ";
            else if (tn[i].length()==4) cout << "0" << tn[i] << " ";
            else if (tn[i].length()==3) cout << "00" << tn[i] << " ";
            else if (tn[i].length()==2) cout << "000" << tn[i] << " ";
            else cout << "0000" << tn[i] << " ";
            
            if (td[i]<10) cout << "0" << td[i] << "/";
            else cout << td[i] << "/";
            
            if (tm[i]<10) cout << "0" << tm[i] << "/";
            else cout << tm[i] << "/";
            
            cout << ty[i] << " ";
            cout << tt[i][0] << tt[i][1] << ":" << tt[i][2] << tt[i][3] << " ";
            cout << "$" << amount[i] << " ";
            cout << "(" << cn[i] << ", ";
            cout << chname[i] << ", ";
            
            if (em[i]<10) cout << "0" << em[i] << "/";
            else cout << em[i] << "/";
            
            if (ey[i]<10) cout << "0" << ey[i] << ") ";
            else cout << ey[i] << ") ";
            
            cout << cstatus[i] << endl;
        }
    }
}

int main() {
    storeinfo();
    dvalidon();
    PrintResult();
    delete [] chname;
    delete [] cn;
    delete [] em;
    delete [] ey;
    delete [] tn;
    delete [] td;
    delete [] tm;
    delete [] ty;
    delete [] tt;
    delete [] amount;
    delete [] cstatus;
    return 0;
}
