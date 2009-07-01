
// start 19:20 - 8:08

#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class BinaryCode {
public:
    int atoi(string & str, unsigned int idx){
        if (idx >= str.length()) return 0;
        return int(str[idx] - '0');
    };

    string encode(string str){
        ostringstream oss;
        for (unsigned int i = 0;i < str.length();i++){
            oss << this->atoi(str, i - 1) + this->atoi(str, i)
                + this->atoi(str, i + 1);
        }
        return oss.str();
    }

    string decode_one(int p0, string & str){
        int p, s, t;
        ostringstream oss;
        s = p0; t = 0;
        oss << p0;
        for(unsigned int i = 1; i < str.length();i++){
            p = this->atoi(str, i - 1) - s - t;
            if (p == 0 || p == 1){
                oss << p;
            } else{
                return "NONE";
            }
            t = s; s = p;
        }

        if (this->encode(oss.str()) == str){
            return oss.str();
        } else {
            return "NONE";
        }
    }

    vector<string> decode(string str){
        vector<string> ret;

        ret.push_back(this->decode_one(0, str));
        ret.push_back(this->decode_one(1, str));

        return ret;
    };
};

