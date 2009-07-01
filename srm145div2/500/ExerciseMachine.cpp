
// 24:43 - 24:58

#line 3 "ExerciseMachine.cpp"
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>

using namespace std;
class ExerciseMachine {
    public:
    int ctoi(char c){
        return c - '0';
    }
    
    int parsetime(string & time){
        int ret;
        ret = (ctoi(time[7]) + ctoi(time[6])*10)
            + 60 * (ctoi(time[4])+10*ctoi(time[3])
                    + 60 * (ctoi(time[1]) + 10*ctoi(time[0])));

        return ret;
    }

    int getPercentages(string & time) {
        int secs = parsetime(time);
        int ret = 0;

        for(int i = 1;i < secs;i++){
            int q = (i * 100) / secs;
            if (q * secs == i * 100) ret++;
        }
        
        return ret;
    }


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "00:30:00"; int Arg1 = 99; verify_case(0, Arg1, getPercentages(Arg0)); }
	void test_case_1() { string Arg0 = "00:28:00"; int Arg1 = 19; verify_case(1, Arg1, getPercentages(Arg0)); }
	void test_case_2() { string Arg0 = "23:59:59"; int Arg1 = 0; verify_case(2, Arg1, getPercentages(Arg0)); }
	void test_case_3() { string Arg0 = "00:14:10"; int Arg1 = 49; verify_case(3, Arg1, getPercentages(Arg0)); }
	void test_case_4() { string Arg0 = "00:19:16"; int Arg1 = 3; verify_case(4, Arg1, getPercentages(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
ExerciseMachine ___test;
___test.run_test(-1);
}
// END CUT HERE
