
// 14:08 - 14:58 (break) 16:35 - 17:26

#line 3 "VendingMachine.cpp"

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

class purch{
public:
    int col;
    int row;
    int time;
    
    purch(string & p){
        
        int comma = p.find(',');
        int colon = p.find(':');
        
        this->row = atoi(p.substr(0, comma - 0).c_str());
        this->col = atoi(p.substr(comma+1, colon-comma-1).c_str());
        this->time = atoi(p.substr(colon+1, p.length()+1-colon).c_str());
    }
};


class VendingMachine {
    public:
    int mindiff(int size, int now, int next){
        // rotate
        int diff1, diff2;
        diff1 = abs(now - next);
        diff2 = size - diff1;
        return (diff1 > diff2 ? diff2 : diff1);
    }

    int motorUse(vector <string> & prices, vector <string> & purchases) {
        int motorrun = 0;
        
        int curcol = 0;
        vector<vector <int>*> p;
        vector<int> colsums;
        for(uint i=0;i<prices.size();i++){
            string price(prices[i]);
            istringstream iss(price);
            vector<int> * pv = new vector<int>();
            p.push_back(pv);
            int row = 0;
            
            while(!iss.eof()){
                if (colsums.size() <= (uint)row)
                    colsums.push_back(0);
                int p;
                iss >> p;
                pv->push_back(p);
                colsums[row] += p;
                row++;
            }
        }

        int max = *max_element(colsums.begin(),colsums.end());
        while(colsums[curcol] != max) curcol++;
        if (curcol > 0) motorrun++;

        int lasttime = 0;
        for(uint i = 0;i < purchases.size();i++){
            purch pur = purch(purchases[i]);
            vector<int> * row = p[pur.row];
            max = *max_element(colsums.begin(),colsums.end());
            int minmaxcol = 0;

            while(max != colsums[minmaxcol]){minmaxcol++;};

            if((*row)[pur.col] == 0){
                return -1;
            }
            
            if (lasttime + 5 <= pur.time){
                // rotate
                motorrun += mindiff(row->size(), curcol, minmaxcol);
                curcol = minmaxcol;
            }

            motorrun += mindiff(row->size(), curcol, pur.col);

            lasttime = pur.time;
            curcol = pur.col;
            colsums[pur.col] -= (*row)[pur.col];
            (*row)[pur.col] = 0;
        }

        int minmaxcol = 0;
        max = *max_element(colsums.begin(), colsums.end());
        while(max != colsums[minmaxcol]){minmaxcol++;};
        motorrun += mindiff(colsums.size(), curcol, minmaxcol);
        return motorrun;
    }


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"100 100 100"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0,0:0", "0,2:5", "0,1:10"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(0, Arg2, motorUse(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"100 200 300 400 500 600"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0,2:0", "0,3:5", "0,1:10", "0,4:15"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 17; verify_case(1, Arg2, motorUse(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"100 200 300 400 500 600"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0,2:0", "0,3:4", "0,1:8", "0,4:12"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 11; verify_case(2, Arg2, motorUse(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"100 100 100"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0,0:10", "0,0:11"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(3, Arg2, motorUse(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"100 200 300",
 "600 500 400"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0,0:0", "1,1:10", "1,2:20",
 "0,1:21", "1,0:22", "0,2:35"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(4, Arg2, motorUse(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
VendingMachine ___test;
___test.run_test(-1);
}
// END CUT HERE
