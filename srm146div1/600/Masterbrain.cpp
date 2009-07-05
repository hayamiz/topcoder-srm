


#include <algorithm>
#include <complex>
#include <exception>
#include <list>
#include <stack>
#include <bitset>
#include <csetjmp>
#include <fstream>
#include <locale>
#include <stdexcept>
#include <cassert>
#include <csignal>
#include <functional>
#include <map>
#include <cctype>
#include <cstdarg>
#include <iomanip>
#include <memory>
#include <streambuf>
#include <cerrno>
#include <cstddef>
#include <ios>
#include <new>
#include <string>
#include <cfloat>
#include <cstdio>
#include <iosfwd>
#include <numeric>
#include <typeinfo>
#include <ciso646>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <utility>
#include <climits>
#include <cstring>
#include <istream>
#include <queue>
#include <valarray>
#include <clocale>
#include <ctime>
#include <iterator>
#include <set>
#include <vector>
#include <cmath>
#include <deque>
#include <limits>
#include <sstream>

typedef long long ll;
typedef unsigned int ui;

#define veceach(v) for(uint i = 0;i < (v).size();i++)
#define veceach2(v,i) for(uint i = 0;i < (v).size();i++)

using namespace std;

class Masterbrain {
    public:

    bool check_guess(string & cand, string & g, string & result){
        int b, w;
        string cand_sec(cand);
        string guess(g);
        b = result[0] - '0'; w = result[3] - '0';

        int ab = 0, aw = 0;

        // check black
        for(int i = 0;i < (int)guess.length();i++){
            if (cand_sec[i] == guess[i]){
                cand_sec[i] = '_';
                guess[i] = 'x';
                ab++;
            }
        }

        // ckeck white
        for(int i = 0;i < (int)guess.length();i++){
            int idx = cand_sec.find(guess[i]);
            if (idx < 0) continue;
            if (idx != i){
                aw++;
                cand_sec[idx] = '_';
            }
        }

        return ab == b && aw == w;
    }

    bool test(string & cand_sec, uint lieidx, vector <string>& guesses, vector <string>& results){
        veceach(guesses){
            string guess (guesses[i]);
            string result (results[i]);
            bool right = check_guess(cand_sec, guess, result);

            if(lieidx == i){
                if (right){
                    return false;
                }
            } else {
                if (!right){
                    return false;
                }
            }
        }

        return true;
    }

    int possibleSecrets(vector <string>& guesses, vector <string>& results) {
        set<int> ret;
        
        for(uint m = 0;m < guesses.size();m++){
            vector<int> cands;
            for(int i = 1;i <= 7;i++){
                for(int j = 1;j <= 7;j++){
                    for(int k = 1;k <= 7;k++){
                        for(int l = 1;l <= 7;l++){
                            ostringstream oss;
                            oss << i<<j<<k<<l;
                            string cand_sec = oss.str();
//                        cout << cand_sec<<endl;

                            if (test(cand_sec, m, guesses, results)){
                                cands.push_back(atoi(cand_sec.c_str()));
                            }
                        }
                    }
                }
            }

            for(uint i = 0;i < cands.size();i++){
                ret.insert(cands[i]);
//                cout << cands[i] <<",";
            }
//            cout << endl;
        }

        return ret.size();
    }


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1575"} ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"4b 0w"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2400; verify_case(0, Arg2, possibleSecrets(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"1234"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0b 4w"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2392; verify_case(1, Arg2, possibleSecrets(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"6172","6162","3617"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"3b 0w","2b 1w","0b 3w"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 14; verify_case(2, Arg2, possibleSecrets(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"1513","5654","4564","1377","1671","1342"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1b 0w","0b 1w","1b 0w","1b 0w","0b 1w","0b 1w"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(3, Arg2, possibleSecrets(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"2611", "1371", "7417", "2647", "3735", "4272", "2442", "3443", "1252", "3353"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0b 2w","0b 2w","0b 1w","0b 2w","1b 0w","1b 0w","1b 0w","0b 1w","1b 1w","0b 1w"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(4, Arg2, possibleSecrets(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
Masterbrain ___test;
___test.run_test(-1);
}
// END CUT HERE
