/*
This file is licensed by the MIT License
Copyright © 2022 RandomKiddo
For more information, visit https://opensource.org/licenses/MIT
Repository link: https://github.com/RandomKiddo/BetterStrings
*/

#include <stdio.h>
#include <string>
#include <algorithm>
#include <cctype>
#include <string.h>
#include <ctype.h>
#include <iostream>

using namespace std;

/*
int main(int argc, char **argv) { 
    return 0;
}
*/

namespace betterstrings {
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
                if (times == 0) { return BetterString(str); }
                std::string mult = ""; 
                for (unsigned int i = 0; i < times; ++i) {
                    mult += str;
                }
                return BetterString(mult);
            }
            void operator*=(unsigned int times) {
                if (times == 0) { return; }
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
                if (index(s.str) == -1) { return BetterString(str); }
                int in = index(s.str);
                int tracker = 0;
                std::string removed = ""; 
                while (tracker < str.length()) {
                    if (!(tracker >= in && tracker < in + s.str.length())) {
                        removed += str[tracker];
                    }
                    if (tracker == in + s.str.length() - 1 && index(s.str, in + s.str.length())) {
                        in = index(s.str, in + s.str.length());
                    }
                    ++tracker;
                }
                return BetterString(removed);
            }
            void operator-=(const BetterString& s) { 
                if (index(s.str) == -1) { return; }
                int in = index(s.str);
                int tracker = 0;
                std::string removed = ""; 
                while (tracker < str.length()) {
                    if (!(tracker >= in && tracker < in + s.str.length())) {
                        removed += str[tracker];
                    }
                    if (tracker == in + s.str.length() - 1 && index(s.str, in + s.str.length())) {
                        in = index(s.str, in + s.str.length());
                    }
                    ++tracker;
                }
                str = removed;
                length = removed.length();
                return;
            }
            void operator=(const BetterString& s) {
                str = s.str;
                length = str.length();
            }
            bool operator<(const BetterString& s) { return str < s.str; }
            bool operator>(const BetterString& s) { return str > s.str; }
            bool operator<=(const BetterString& s) { return str <= s.str; }
            bool operator>=(const BetterString& s) { return str >= s.str; }
            BetterString operator()(unsigned int start, unsigned int stop) {
                std::string copy = "";
                if (start >= length || stop > length) { return BetterString(); }
                for (int i = start; i < stop; ++i) {
                    copy += str[i];
                }
                return BetterString(copy);
            }
            BetterString operator()(unsigned int start) {
                std::string copy = "";
                if (start >= length) { return BetterString(); }
                for (int i = start; i < str.length(); ++i) {
                    copy += str[i];
                }
                return BetterString(copy);
            }
            BetterString operator()(unsigned int start, unsigned int stop, unsigned int step) {
                std::string copy = "";
                if (start >= length || stop > length) { return BetterString(); }
                for (int i = start; i < stop; i += step) {
                    copy += str[i];
                }
                return BetterString(copy);
            }
            friend ostream& operator<<(ostream& os, const BetterString& s) { os << s.str; return os; }
            friend std::string operator<<(std::string s1, BetterString& s2) { std::string t = s1 + (s2.str); return t; }
            friend const char* operator<<(const char* s1, const BetterString& s2) { 
                std::string s1s = s1; 
                std::string t = s1s + (s2.str);
                return t.c_str();
            }
            friend istream& operator>>(istream& is, BetterString& in) { is >> in.str; return is; }
            //Getters
            int size(void) { return length; }
            std::string as_str(void) { return str; }
            const char* c_str(void) { return str.c_str(); }
            //Methods
            BetterString subtractFirst(const BetterString& s) {
                if (index(s.str) == -1) { return BetterString(str); }
                int in = index(s.str);
                std::string copy = "";
                for (int i = 0; i < in; ++i) {
                    copy += str[i];
                }
                for (int i = in + s.str.length(); i < str.length(); ++i) {
                    copy += str[i];
                }
                return BetterString(copy); 
            }
            BetterString lower(void) {
                std::string copy = str;
                std::transform(copy.begin(), copy.end(), copy.begin(), 
                [](unsigned char c){ return std::tolower(c); });
                return BetterString(copy);
            }
            BetterString upper(void) {
                std::string copy = str;
                std::transform(copy.begin(), copy.end(), copy.begin(), 
                [](unsigned char c){ return std::toupper(c); });
                return BetterString(copy);
            }
            BetterString title(void) {
                std::string copy = str;
                for (int i = 0; copy[i] != '\0'; ++i) {
                    if (!isalpha(copy[i]) && copy[i] != ' ') { continue; }
                    if (isalpha(copy[i]) && i == 0) {
                        copy[i] = copy[i]-32;
                    } else if (copy[i] == ' ' && isalpha(copy[i+1])) {
                        copy[i+1] = copy[i+1]-32;
                    }
                }
                return BetterString(copy);
            }
            int index(std::string s) {
                if (s.length() == 1) {
                    for (int i = 0; i < str.length(); ++i) {
                        if (s[0] == str[i]) { return i; }
                    }
                } else {
                    for (int i = 0; i <= str.length() - s.length(); ++i) {
                        std::string connected = "";
                        for (int j = i; j < s.length() + i; ++j) {
                            connected += str[j]; 
                        }
                        if (connected == s) { return i; }
                    }
                }
                return -1; 
            }
            int index(std::string s, int start) {
                if (start >= str.size()) { return -1; }
                if (s.length() == 1) {
                    for (int i = start; i < str.length(); ++i) {
                        if (s[0] == str[i]) { return i; }
                    }
                } else {
                    for (int i = start; i <= str.length() - s.length(); ++i) {
                        std::string connected = "";
                        for (int j = i; j < s.length() + i; ++j) {
                            connected += str[j];
                        }
                        if (connected == s) { return i; }
                    }
                }
                return -1; 
            }
            bool equalsIgnoreCase(const BetterString& s) {
                if (s.str.length() != str.length()) { return false; }
                BetterString one = BetterString(str);
                BetterString two = BetterString(s.str);
                one = one.lower();
                two = two.lower();
                for (unsigned int i = 0; i < one.str.length(); ++i) {
                    if (one.str[i] != two.str[i]) { return false; }
                }
                return true;
            }
            //Iterator
            struct iterator {
                using iterator_category = std::random_access_iterator_tag;
                using difference_type = std::ptrdiff_t;
                using value_type = BetterString;
                using pointer = BetterString*;
                using reference = BetterString&;
                private:
                    char ptr;
                    int index;
                    std::string str;
                public:
                    iterator() {}
                    iterator(BetterString s) { 
                        str = s.as_str();
                        ptr = s[0];
                        index = 0;
                    }
                    iterator(BetterString s, int i) {
                        ptr = s[i];
                        str = s.as_str();
                        index = i;
                    }
                    char operator*() const { return ptr; }
                    char operator->() { return ptr; }
                    iterator operator++() { 
                        ++index;
                        ptr = str[index];
                        return iterator(str, index);
                    }
                    iterator operator++(int) { 
                        iterator temp = *this; 
                        ++(*this);
                        return temp;
                    }
                    friend bool operator== (const iterator& a, const iterator& b) {
                        return a.str == b.str && a.ptr == b.ptr && a.index == b.index;
                    }
                    friend bool operator!= (const iterator& a, const iterator& b) {
                        return a.str != b.str || a.ptr != b.ptr || a.index == b.index; 
                    }
            };
            iterator begin() { return iterator(BetterString(str), 0); }
            iterator end() { 
                BetterString s(str);
                return iterator(s, s.size());
            }
    };
};