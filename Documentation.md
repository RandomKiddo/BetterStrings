### BetterStrings in C++

[![License](https://img.shields.io/github/license/RandomKiddo/BetterStrings)](https://opensource.org/licenses/MIT)
[![Version](https://img.shields.io/badge/version-1.2r-blueviolet)](https://github.com/RandomKiddo/BetterStrings/releases/tag/v1.2r)

___

### Table of Contents

1. [Constructors](#constructors)
2. [Operators](#operators)
3. [Getters](#getters)
4. [Descriptive Methods](#descriptive-methods)
5. [Iterator](#iterator)

___

### Constructors

<br>

`BetterString(void)`
<sub>Constructs an empty better string equivalent to an empty string</sub>
```cpp
BetterString str(); //str = ""
```

<br>

`BetterString(std::string def)`
<sub>Constructs a better string set to the standard string passed in</sub>
```cpp
std::string def = "hey";
BetterString str(def); //str = "hey"
```

<br>

`BetterString(unsigned int init)`
<sub>Constructs a better string of only spaces of size <i>init</i></sub>
```cpp
unsigned int init = 5;
BetterString str(init); //str = "     "
```

<br>

`BetterString(const BetterString& copy)`
<sub>Constructs a better string equivalent to the one passed in</sub>
```cpp
BetterString copy("hello");
BetterString str(copy); //str = "hello"
```

[Back](#table-of-contents)

___

### Operators

<br>

`char operator[](int index)`
<sub>Returns the char at the given string index, -1 if index out-of-range</sub>
```cpp
BetterString str("hello");
str[0]; //"h"
```

<br>

`BetterString operator+(const BetterString& s)`
<sub>Adds the two better strings together, and returns a new better string</sub>
```cpp
BetterString one("one");
BetterString two("two");
BetterString three = one + two; //three = "onetwo"
```

<br>

`void operator+=(const BetterString& s)`
<sub>Adds this better stirng to the one passed in, and sets this better string to the new one</sub>
```cpp
BetterString one("one");
BetterString two("two");
two += one; //two = "onetwo"
```

<br>

`BetterString operator*(unsigned int times)`
<sub>Multiplies this string the amount of times given, and returns a new better string</sub>
```cpp
BetterString one("one");
BetterString two = one*3; //three = "oneoneone"
```

<br>

`void operator*=(unsigned int times)`
<sub>Multiplies this string the amount of times given and set this better string to the new one</sub>
```cpp
BetterString one("one");
one *= 3; //one = "oneoneone"
```

<br>

`bool operator==(const BetterString& s)`
<sub>Returns true if this better string is equivalent to the one passed in, false otherwise</sub>
```cpp
BetterString one("one");
BetterString two("two");
one == two; //false
```

<br>

`bool operator!=(const BetterString& s)`
<sub>Returns true if this better string is not equivalent to the one passed in, false otherwise</sub>
```cpp
BetterString one("one");
BetterString two("two");
one != two; //true
```

<br>

`BetterString operator-(const BetterString &s)`
<sub>Removes every instance of s in this better string, and returns a new better string</sub>
```cpp
BetterString test("hello");
BetterString rem("l");
BetterString sub = test - rem; //sub = "heo"
```

<br>

`void operator-=(const BetterString &s)`
<sub>Removed every instance of s in this better string and sets this better string to the value</sub>
```cpp
BetterString test("hello");
BetterString rem("l");
test -= rem; //test = "heo"
```

<br>

`void operator=(const BetterString& s)`
<sub>Sets this string to the better string passed in</sub>
```cpp
BetterString one("two");
BetterString two = one; //two = "two"
```

<br>

`bool operator<(const BetterString& s)`
<sub>Returns true if this better string is less than the one passed in</sub>
```cpp
BetterString one("one");
BetterString two("two");
one < two; //true
```

<br>

`bool operator<=(const BetterString& s)`
<sub>Returns true if this better string is less than or equal to the one passed in</sub>
```cpp
BetterString one("one");
BetterString two("two");
one <= two; //true
```

<br>

`bool operator>(const BetterString& s)`
<sub>Returns true if this better string is greater than the one passed in</sub>
```cpp
BetterString one("one");
BetterString two("two");
one > two; //false
```

<br>

`bool operator>=(const BetterString& s)`
<sub>Returns true if this better string is greater than or equal to the one passed in</sub>
```cpp
BetterString one("one");
BetterString two("two");
one >= two; //false
```

<br>

`BetterString operator()(unsigned int start)`
<sub>Get a substring of this better string starting at the int passed in</sub>
```cpp
BetterString test("hello");
test(1); //"ello"
```

<br>

`BetterString operator()(unsigned int start, unsigned int stop)`
<sub>Get a substring of this better string starting and stopping at the ints passed in</sub>
```cpp
BetterString test("hello");
test(1, 3); //"el"
```

<br>

`BetterString operator()(unsigned int start, unsigned int stop, unsigned int step)`
<sub>Get a substring of this better string starting and stopping at the ints passed in, skipping every step chars</sub>
```cpp
BetterString test("hello world");
test(0, 11, 2); //"hlowrd"
```

<br>

`friend ostream& operator<<(ostream& os, const BetterString& s)`
<sub>Merges this better string with the output stream specified</sub>
```cpp
BetterString test("test");
std::cout << test; //prints "test"
```

<br>

`friend std::string operator<<(std::string s1, BetterString& s2)`
<sub>Merges this better string with the string specified</sub>
```cpp
BetterString test("test");
std::string merge = "merge";
merge << test; //"mergetest"
```

<br>

`friend const char* operator<<(const char* s1, const BetterString& s2)`
<sub>Merges this better string with the C-string specified</sub>
```cpp
BetterString test("test");
"merge" << test; //"mergetest"
```

<br>

`friend istream& operator>>(istream& is, BetterString& in)`
<sub>Sets the better string specified with the input string passed in</sub>
```cpp
BetterString test;
std::cin >> test; //input test
```

[Back](#table-of-contents)

___

### Getters

<br>

`int size(void)`
<sub>Returns the size of the better string instance</sub>
```cpp
BetterString str("hey");
str.size(); //3
```

<br>

`std::string as_str(void)`
<sub>Returns this better string as a standard string</sub>
```cpp
BetterString str("hey");
str.as_str(); //"hey"
```

<br>

`const char* c_str(void)`
<sub>Returns this better string as a legacy C-string</sub>
```cpp
BetterString str("hi");
str.c_str(); //"hi" as C-string
```

<br>

`std::vector<char> as_vector(void)`
<sub>Returns this better string as a vector of chars</sub>
```cpp
BetterString str("hi");
str.as_vector(); //vector <'h', 'i'>
```

[Back](#table-of-contents)

___

### Descriptive Methods

<br>

`BetterString subtractFirst(const BetterString& s)`
<sub>Subtracts the first instance of the string specified in this better string, and returns a new better string</sub>
```cpp
BetterString test("banana");
BetterString rem("a");
BetterString sub = test.subtractFirst(rem); //sub = "bnana";
```

<br>

`BetterString lower(void)`
<sub>Returns a new better string in all lowercase</sub>
```cpp
BetterString test("HeY TherE");
test.lower(); //"hey there"
```

<br>

`BetterString upper(void)`
<sub>Returns a new better string in all uppercase</sub>
```cpp
BetterString test("HeY TherE");
test.upper(); //"HEY THERE";
```

<br>

`BetterString title(void)`
<sub>Returns a new better string in title case</sub>
```cpp
BetterString test("HeY TherE");
test.title(); //"Hey There";
```

<br>

`int index(std::string s)`
<sub>Returns the index of the string specified in this better string, -1 if not found</sub>
```cpp
BetterString test("test");
std::string find = "e";
test.index(find); //1
```

<br>

`int index(std::string s, int start)`
<sub>Returns the index of the string specified in this better string, starting at start, -1 if not found</sub>
```cpp
BetterString test("test");
std::string find = "t";
test.index(find, 1); //3
```

<br>

`bool equalsIgnoreCase(const BetterString& s)`
<sub>Checks if this better string is equal to the one specified, disregarding capitalization</sub>
```cpp
BetterString one("one");
BetterString two("ONE");
one.equalsIgnoreCase(two); //true
```

[Back](#table-of-contents)

___

### Iterator

<br>

`iterator begin(void)`
<sub>Returns the beginning of this better string's iterator</sub>
```cpp
BetterString test("test");
BetterString::iterator it = test.begin();
```

<br>

`iterator end(void)`
<sub>Returns the end of this better string's iterator</sub>
```cpp
BetterString test("test");
BetterString::iterator it = test.end();
```

<br>

`iterator operator++(void)`
`iterator operator++(int)`
<sub>Increments this iterator</sub>
```cpp
BetterString test("test");
BetterString::iterator it = test.begin();
it++; ++it;
```

<br>

`char operator*(void) const`
<sub>Returns the char associated with this iterator</sub>
```cpp
BetterString test("test");
BetterString::iterator it = test.begin();
*it; //'t'
```

[Back](#table-of-contents)

___

[Back to Top](#betterstrings-in-c)

<sub>This page was last edited on 10.27.2022</sub>
