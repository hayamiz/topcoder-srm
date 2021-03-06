
// 12:46 - 12:50

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
class RectangularGrid {
    public:
    long long countRectangles(int width, int height) {
        long long ret = 0;
        for(int i = 1;i <= width;i++){
            for(int j=1;j <= height;j++){
                if (i==j) continue;
                ret += (width - i + 1) * (height - j + 1);
            }
        }

        return ret;
    }


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 3; long long Arg2 = 22LL; verify_case(0, Arg2, countRectangles(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 2; long long Arg2 = 31LL; verify_case(1, Arg2, countRectangles(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 10; long long Arg2 = 2640LL; verify_case(2, Arg2, countRectangles(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 1; long long Arg2 = 0LL; verify_case(3, Arg2, countRectangles(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 592; int Arg1 = 964; long long Arg2 = 81508708664LL; verify_case(4, Arg2, countRectangles(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
RectangularGrid ___test;
___test.run_test(-1);
}
// END CUT HERE
