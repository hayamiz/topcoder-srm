
// 2:28 - 3:02

#line 3 "Bonuses.cpp"
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

class Employee {
public:
    int point;
    int id;
    Employee(int i, int p): point(p), id(i){};
};

bool operator<(const Employee &e1, const Employee &e2){
        return e1.point < e2.point || (e1.point == e2.point && e1.id > e2.id);
}

class Bonuses {

    priority_queue<Employee, vector<Employee> > emp;
    
    public:
    vector <int> getDivision(vector <int> points) {
        vector<int> ret;
        while(!emp.empty()) emp.pop();

        int total = 0;
        int remain = 100;
        for (unsigned int i = 0; i < points.size();i++){
            total += points[i];
        }
        for (unsigned int i = 0; i < points.size();i++){
            int give = points[i] * 100 / total;
            remain -= give;
            ret.push_back(give);
            emp.push(Employee(i, points[i]));
        }
        while (remain > 0){
            remain --;
            Employee e = emp.top();
            ret[e.id] += 1;
            emp.pop();
        }

        return ret;
    }


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3,4,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 6,  13,  20,  27,  34 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getDivision(Arg0)); }
	void test_case_1() { int Arr0[] = {5,5,5,5,5,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 17,  17,  17,  17,  16,  16 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getDivision(Arg0)); }
	void test_case_2() { int Arr0[] = {485, 324, 263, 143, 470, 292, 304, 188, 100, 254, 296,
 255, 360, 231, 311, 275,  93, 463, 115, 366, 197, 470}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 8,  6,  4,  2,  8,  5,  5,  3,  1,  4,  5,  4,  6,  3,  5,  4,  1,  8,  1,  6,  3,  8 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getDivision(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
Bonuses ___test;
___test.run_test(-1);
}
// END CUT HERE
