
#include "binary_code.cpp"

void print_result(vector<string> str){
    cout << "{" << str[0] << "," << str[1] << "}" << endl;
}

int main(int argc, char ** argv){

    BinaryCode bc;

    vector<string> tests;
    tests.push_back("123210122");
    tests.push_back("12321012");

    for(int i = 0;i < tests.size();i++){
        print_result(bc.decode(tests[i]));
    }

    return 0;
}
