
// 19:02 - 20:19 -- Ahhhhh! Forgot to submit

#line 3 "ImageDithering.cpp"
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

class ImageDithering {
    public:
    map<char,bool> dith_chars;

    void make_dith_chars(string & dithered){
        this->dith_chars.clear();
        
        for(unsigned int i = 0;i < dithered.length();i++){
            // cerr << "added char: " << dithered[i] << endl;
            this->dith_chars[dithered[i]] = true;
        }
    }

    bool d(char c){
        if (this->dith_chars.find(c) != this->dith_chars.end()){
            // cerr << "matched char: " << c << endl;
            return true;
        }
        return false;
    }

    char cmap(vector<string> screen, int i, int j ){
        if (i < 0 || i >= screen.size() || j <= 0
            || j >= screen[0].length()){
            return '\0';
        }
        return screen[i][j];
    }

    bool da(char c, char a){
        // cerr << "adj check: " << c << "," << a << endl;
        return d(a) && d(c);
    }
    
    int count(string dithered, vector<string> screen) {
        int ret = 0;
        int row = screen.size();
        int col = screen[0].length();

        make_dith_chars(dithered);
        
        for(int i = 0;i < row;i++){
            for(int j = 0;j < col;j++){
                char c = screen[i][j];
                if (!d(c)) continue;

                if (   cmap(screen, i, j-1)
                    || cmap(screen, i, j+1)
                    || cmap(screen, i-1, j)
                    || cmap(screen, i+1, j)
                    || cmap(screen, i-1, j-1)
                    || cmap(screen, i+1, j-1)
                    || cmap(screen, i-1, j+1)
                       || cmap(screen, i+1, j+1)){
                    ret++;
                    continue;
                }
            }
        }

        return ret;
    }


// BEGIN CUT HERE
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arg0 = "BW"; string Arr1[] = {"AAAAAAAA",
 "ABWBWBWA",
 "AWBWBWBA",
 "ABWBWBWA",
 "AWBWBWBA",
 "AAAAAAAA"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 24; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "BW"; string Arr1[] = {"BBBBBBBB",
 "BBWBWBWB",
 "BWBWBWBB",
 "BBWBWBWB",
 "BWBWBWBB",
 "BBBBBBBB"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 48; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "ACEGIKMOQSUWY"; string Arr1[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
 "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
 "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
 "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
 "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
 "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 150; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "CA"; string Arr1[] = {"BBBBBBB",
 "BBBBBBB",
 "BBBBBBB"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(3, Arg2, count(Arg0, Arg1)); }
    void test_case_4() { string Arg0 = "DCBA"; string Arr1[] = {"ACBD"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(4, Arg2, count(Arg0, Arg1));}
        void test_case_5() { string Arg0 = "JSPQKYRME"; string Arr1[] = {"OT", "QF", "KD", "HR", "VV", "XB"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(5, Arg2, count(Arg0, Arg1));}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
ImageDithering ___test;
___test.run_test(-1);
}
// END CUT HERE
