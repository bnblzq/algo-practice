

#include "iostream"
#include "string"

using namespace std;

int main(){
    string str;
    getline(cin, str);

    for(string::iterator it = str.end(); it != str.begin(); --it){
        if(*it == ' ') str.erase(it);
    }

    puts(str.c_str());

    return 0;
}

