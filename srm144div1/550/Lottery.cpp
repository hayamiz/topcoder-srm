
// 9:20 - 11:03

#line 3 "Lottery.cpp"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cctype>
#include <cstdlib>

using namespace std;

typedef enum {
    t_name = 0,
    t_choices = 1,
    t_blanks = 2,
    t_sorted = 3,
    t_unique = 4,
} token_t;

struct lot {
    string name;
    int choices;
    int blanks;
    bool unique;
    bool sorted;
    unsigned long long total_case;

    map<int, map<int,unsigned long long>* > notuniq_mem;
    map<int, map<int,unsigned long long>* > uniq_mem;

    unsigned long long total_sorted_notunique(int n, int m){
        unsigned long long ret = 0;
        if (m == 1){
            return n;
        } else {
            map<int,unsigned long long>* mem = NULL;
            if (notuniq_mem.find(n) != notuniq_mem.end()){
                mem = notuniq_mem[n];
                if (mem->find(m) != mem->end()){
                    return (*mem)[m];
                }
            } else {
                notuniq_mem[n] = mem = new map<int,unsigned long long>();
            }
            
            for (int k = 0;k < n;k++){
                ret += total_sorted_notunique(n - k, m - 1);
            }
            (*mem)[m] = ret;
        }
        return ret;
    }

    unsigned long long total_sorted_unique(int n, int m){
        unsigned long long ret = 0;
        if (m == 1){
            return n;
        } else {
            map<int,unsigned long long>* mem = NULL;
            if (uniq_mem.find(n) != uniq_mem.end()){
                mem = uniq_mem[n];
                if (mem->find(m) != mem->end()){
                    return (*mem)[m];
                }
            } else {
                uniq_mem[n] = mem = new map<int, unsigned long long>();
            }

            for (int k = 1;k < n;k++){
                ret += total_sorted_unique(n - k, m - 1);
            }
            (*mem)[m] = ret;
        }
        return ret;
    }

    unsigned long long total_notsorted_notunique(int n, int m){
        unsigned long long ret = 1;
        for (int i = 0;i<m;i++){
            ret *= n;
        }

        return ret;
    }
    
    unsigned long long total_notsorted_unique(int n, int m){
        unsigned long long ret = 1;
        for (int i = 0;i<m;i++){
            ret *= n;
            n--;
        }

        return ret;
    }

    unsigned long long total(){
        unsigned long long ret;

        if (this->sorted && !this->unique){
            ret = total_sorted_notunique(this->choices, this->blanks);
        } else if (this->sorted && this->unique) {
            ret = total_sorted_unique(this->choices, this->blanks);
        } else if (!this->sorted && !this->unique) {
            ret = total_notsorted_notunique(this->choices, this->blanks);
        } else if (!this->sorted && this->unique) {
            ret = total_notsorted_unique(this->choices, this->blanks);
        } else {
            cerr << "error" <<endl;
            exit(1);
        }

        return ret;
    }

    static lot * parse(string & str){
        lot * ret = new lot();
        ostringstream oss;
        token_t cur_tok = t_name;
        for (unsigned int i = 0;i < str.length();i++){
            char c = str[i];

            switch (cur_tok){
            case t_name:
                if (c != ':'){
                    oss << c;
                } else {
                    i++;
                    cur_tok = t_choices;
                    ret->name = oss.str();
                    oss.str("");
                }
                break;
            case t_choices:
                if (isdigit(c)){
                    oss << c;
                } else {
                    ret->choices = atoi(oss.str().c_str());
                    oss.str("");
                    cur_tok = t_blanks;
                }
                break;
            case t_blanks:
                if (isdigit(c)){
                    oss << c;
                } else {
                    ret->blanks = atoi(oss.str().c_str());
                    oss.str("");
                    cur_tok = t_sorted;
                }
                break;
            case t_sorted:
                if (c == 'T') ret->sorted = true;
                else if (c == 'F') ret->sorted = false;
                else {
                    oss.str("");
                    cur_tok = t_unique;
                }
                break;
            case t_unique:
                if (c == 'T') ret->unique = true;
                else if (c == 'F') ret->unique = false;
                break;
            }
        }

        ret->total_case = ret->total();
        return ret;
    }
};

bool compare_lot(lot * a, lot * b){
    if (a->total_case != b->total_case)
        return (a->total_case < b->total_case);
    else {
        return a->name < b->name;
    }
    
    return true;
}

void inspect(lot * l){
    cerr << "{ name: \"" <<l->name<<"\", "
         << "choices: " << l->choices << ", "
         << "blanks : " << l->blanks << ", "
         << "sorted : " << l->sorted << ", "
         << "unique : " << l->unique << ", "
         << "total  : " << l->total_case << "}"
         << endl;
}

class Lottery {
    public:
    vector <string> sortByOdds(vector<string> rules) {
        vector<string> ret;
        vector<lot*> lots;

        if (rules.size() == 0) return ret;

        for(unsigned int i=0;i < rules.size();i++){
            lots.push_back(lot::parse(rules[i]));
            //inspect(lots.back());
        }

        sort(lots.begin(), lots.end(), compare_lot);

        for(unsigned int i=0;i < rules.size();i++){
            ret.push_back(lots[i]->name);
        }

        return ret;
    }
    

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"PICK ANY TWO: 10 2 F F"
,"PICK TWO IN ORDER: 10 2 T F"
,"PICK TWO DIFFERENT: 10 2 F T"
,"PICK TWO LIMITED: 10 2 T T"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "PICK TWO LIMITED",  "PICK TWO IN ORDER",  "PICK TWO DIFFERENT",  "PICK ANY TWO" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, sortByOdds(Arg0)); }
	void test_case_1() { string Arr0[] = {"INDIGO: 93 8 T F",
 "ORANGE: 29 8 F T",
 "VIOLET: 76 6 F F",
 "BLUE: 100 8 T T",
 "RED: 99 8 T T",
 "GREEN: 78 6 F T",
 "YELLOW: 75 6 F F"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "RED",  "ORANGE",  "YELLOW",  "GREEN",  "BLUE",  "INDIGO",  "VIOLET" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, sortByOdds(Arg0)); }
	void test_case_2() { string Arr0[] = {}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, sortByOdds(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
Lottery ___test;
___test.run_test(-1);
}
// END CUT HERE
