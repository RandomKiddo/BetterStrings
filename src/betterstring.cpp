/*
This file is licensed by the MIT License
Copyright © 2022 RandomKiddo
For more information, visit https://opensource.org/licenses/MIT
*/

#include <stdio.h>
#include <string>

using namespace std;

class BetterString;

int main(int argc, char *argv) {
    return 0;
}

class BetterString { 
    private:
        std::string str;
        unsigned int length; 
    public:
        //Constructors
        BetterString() { str = ""; length = 0; }
        BetterString(std::string def) { str = def; length = def.length(); }
        BetterString(unsigned int init) { 
            length = init;
            str = "";
            for (unsigned int i = 0; i < init; ++i) {
                str += " ";
            }
        }
        BetterString(const BetterString& copy) {
            str = copy.str;
            length = str.size(); 
        }
        //Operators
        char operator[](int index) { 
            if (index >= length) { return '\0'; }
            return str[index]; 
        }
        BetterString operator+(const BetterString& s) {
            return BetterString(str + s.str); 
        }
        void operator+=(const BetterString& s) {
            str += s.str;
            length = str.size(); 
        }
        BetterString operator*(unsigned int times) {
            std::string mult = ""; 
            for (unsigned int i = 0; i < times; ++i) {
                mult += str;
            }
            return BetterString(mult);
        }
        void operator*=(unsigned int times) {
            std::string mult = "";
            for (unsigned int i = 0; i < times; ++i) {
                mult += str;
            }
            str = mult;
            length = str.length();
        }
        bool operator==(const BetterString& s) {
            if (s.length != length) { return false; }
            for (unsigned int i = 0; i < length; ++i) {
                if (s.str[i] != str[i]) { return false; }
            }
            return true;
        }
        bool operator!=(const BetterString& s) {
            if (s.length != length) { return true; }
            for (unsigned int i = 0; i < length; ++i) {
                if (s.str[i] != str[i]) { return true; }
            }
            return false;
        }
        BetterString operator-(const BetterString& s) {
            return BetterString(); //TODO subtract
        }
        void operator-=(const BetterString& s) { 
            return; //TODO subtract equals
        }
        void operator=(const BetterString& s) {
            str = s.str;
            length = str.length();
        }
        //TODO comparisons between strings
        //Getters
        int length(void) { return length; }
        int size(void) { return length; }
        //Methods
        int index(const BetterString& s) {
            return -1; //TODO index
        }
        bool equalsIgnoreCase(const BetterString& s) {
            return false; //TODO equals ignore case
        }
};