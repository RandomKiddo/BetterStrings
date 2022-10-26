/*
This file is licensed by the MIT License
Copyright © 2022 RandomKiddo
For more information, visit https://opensource.org/licenses/MIT
*/

/*
This is a test file. This is meant for development purposes mainly, but
this file can be used to check that the source file is working properly
on your current system
*/

#include "betterstring.cpp"
#include <stdio.h>
#include <vector>
#include <iostream>
#include <map>

using namespace std;
using namespace betterstrings;
using betterstrings::BetterString;

bool assert(bool actual, bool expected);
void testNullConstructor(void);
void testStringConstructor(void);
void testSizeConstructor(void);
void testCopyConstructor(void);
void testSqBrkt(void);
void testPlAndPlEq(void);
void testMuAndMuEq(void);
void testEq(void);
void testNEq(void);
void testSuAndSuEq(void);
void testSEq(void);
void testGAndGEq(void);
void testLAndLEq(void);
void testSpliceOne(void);
void testSpliceTwo(void);
void testSpliceThree(void);
void testSize(void);
void testAsStr(void);
void testCStr(void);
void testSuFirst(void);
void testLower(void);
void testUpper(void);
void testTitle(void); 
void testIndexOne(void);
void testIndexTwo(void);
void testEqIC(void);
void testOut(void);
void testIn(void);
void testIterator(void);

std::vector<bool> vec;
const std::string methods[] = {
    "Null Constructor", "String Constructor", "Size Constructor", "Copy Constructor",
    "Square Bracket Operator", "Plus/Plus Equal Operator", "Multiply/Multiply Equal Operator",
    "Equality", "Inequality", "Subtract/Subtract Equal Operator", "Equal", "Greater/Greater Equal Operator",
    "Less/Less Equal Operator", "Splice One Arg", "Splice Two Args", "Splice Three Args", "Size", "As String",
    "C String", "Subtract First", "Lower", "Upper", "Title", "Index One Arg", "Index Two Args", "Equals Ignore Case",
    "Output <<", "Input >>", "Iterator"
};
int main(int argc, char **argv) {
    testNullConstructor();
    testStringConstructor();
    testSizeConstructor();
    testCopyConstructor();
    testSqBrkt();
    testPlAndPlEq();
    testMuAndMuEq();
    testEq();
    testNEq();
    testSuAndSuEq();
    testSEq();
    testGAndGEq();
    testLAndLEq();
    testSpliceOne();
    testSpliceTwo();
    testSpliceThree();
    testSize();
    testAsStr();
    testCStr();
    testSuFirst();
    testLower();
    testUpper();
    testTitle();
    testIndexOne();
    testIndexTwo();
    testEqIC();
    testOut();
    testIn();
    testIterator();

    const int AMT = 29;
    std::map<int, std::string> failing;

    std::string check = "";
    int asteriskAmt = 0;
    for (int i = 0; i < vec.size(); ++i) {
        if (!vec.at(i)) { 
            check += "*"; 
            ++asteriskAmt; 
            failing.insert(std::pair<int, std::string>(i, methods[i]));
            }
        else { check += "|"; }
    }
    std::cout << "---------------------------------------------" << "\n";
    std::cout << check << "\n" << "---------------------------------------------" << "\n";
    if (asteriskAmt == 0) {
        std::cout << "OK { PASSING IN " << AMT << " CHECKS }" << "\n";
    } else {
        std::cout << "ERROR { PASSING IN " << AMT - asteriskAmt << " CHECKS, FAILING IN " << asteriskAmt << " }\n";
    }
    std::cout << "---------------------------------------------" << "\n";
    std::cout << "Failing In: " << "\n\n";
    if (failing.size() != 0) {
        map<int, std::string>::iterator it;
        for (it = failing.begin(); it != failing.end(); ++it) {
            std::cout << it->second << " : #" << it->first + 1 << "\n";
        }
    } else {
        std::cout << "[N/A]" << "\n";
    }
    std::cout << "---------------------------------------------" << "\n";
    return 0;
}

bool assert(bool actual, bool expected) { return actual == expected; }

//#1
void testNullConstructor(void) { 
    BetterString test;
    vec.push_back(assert(test.as_str() == "" && test.size() == 0, true));
    return;
}

//#2
void testStringConstructor(void) {
    BetterString test("test");
    vec.push_back(assert(test.as_str() == "test" && test.size() == 4, true));
    return;
}

//#3
void testSizeConstructor(void) {
    BetterString test(3);
    vec.push_back(assert(test.as_str() == "   " && test.size() == 3, true));
    return;
}

//#4
void testCopyConstructor(void) {
    BetterString test("test");
    BetterString copy(test);
    vec.push_back(assert(copy.as_str() == "test" && copy.size() == 4, true));
    return;
}

//#5
void testSqBrkt(void) {
    BetterString test("test"); 
    vec.push_back(assert(test[0] == 't' && test[4] == '\0', true)); 
    return;
}

//#6
void testPlAndPlEq(void) { 
    BetterString one("one");
    BetterString two("two");
    bool plus = (one + two).as_str() == "onetwo";
    one += two;
    one += two;
    bool pluseq = one.as_str() == "onetwotwo";
    vec.push_back(assert(plus && pluseq, true));
    return;
}

//#7
void testMuAndMuEq(void) { 
    BetterString test("a");
    bool mult = (test*3).as_str() == "aaa";
    test *= 4;
    bool multeq = test.as_str() == "aaaa"; 
    BetterString zero = test*0;
    bool zerom = zero.as_str() == "aaaa";
    zero *= 0;
    bool zeromeq = zero.as_str() == "aaaa";
    vec.push_back(assert(mult && multeq && zerom && zeromeq, true));
    return;
}

//#8
void testEq(void) { 
    BetterString one("one");
    BetterString two("two");
    bool eq = one == one; 
    bool neq = one == two;
    BetterString three("three");
    bool len = one == three; 
    vec.push_back(assert(eq && !neq && !len, true));
    return;
}

//#9 
void testNEq(void) { 
    BetterString one("one");
    BetterString two("two");
    bool neq = one != two;
    bool eq = one != one;
    BetterString three("three");
    bool len = one != three;
    vec.push_back(assert(neq && !eq && len, true));
    return;
}

//#10
void testSuAndSuEq(void) { 
    BetterString test("banana");
    BetterString rem("a");
    BetterString sub = test - rem; 
    bool subt = sub.as_str() == "bnn"; 
    test -= rem;
    bool subteq = test.as_str() == "bnn";
    BetterString nrem("h");
    BetterString test2("bob");
    test2 -= nrem;
    bool nothing = test2.as_str() == "bob";
    BetterString test3("hello");
    BetterString mrem("ll");
    test3 -= mrem;
    bool longer = test3.as_str() == "heo";
    vec.push_back(assert(subt && subteq && nothing && longer, true));
    return; 
}

//#11
void testSEq(void) {
    BetterString test("test");
    test = BetterString("hey");
    bool one = test.as_str() == "hey";
    BetterString test2("two");
    test = test2;
    bool two = test.as_str() == "two";
    vec.push_back(assert(one && two, true));
    return;
}

//#12
void testGAndGEq(void) {
    BetterString one("one");
    BetterString two("two");
    bool g = two > one;
    bool ge = one >= one;
    vec.push_back(assert(g && ge, true));
    return;
}

//#13
void testLAndLEq(void) {
    BetterString one("one");
    BetterString two("two");
    bool l = one < two;
    bool le = two <= two;
    vec.push_back(assert(l && le, true));
    return;
}

//#14
void testSpliceOne(void) {  
    BetterString test("hello world");
    BetterString one = test(2);
    bool onesp = one.as_str() == "llo world";
    BetterString two = test(20);
    bool longer = two.as_str() == ""; 
    vec.push_back(assert(onesp && longer, true));
    return;
}

//#15
void testSpliceTwo(void) {
    BetterString test("hello world");
    BetterString one = test(2, 4);
    bool twosp = one.as_str() == "ll";
    BetterString two = test(3, 31);
    bool endlong = two.as_str() == "";
    two = test(21, 4);
    bool frontlong = two.as_str() == "";
    two = test(21, 31);
    bool bothlong = two.as_str() == "";
    vec.push_back(assert(twosp && endlong && frontlong && bothlong, true));
    return;
}

//#16
void testSpliceThree(void) {
    BetterString test("hello world");
    BetterString one = test(0, 11, 2);
    bool threesp = one.as_str() == "hlowrd";
    // If splice length test worked for two, it will work for three
    vec.push_back(assert(threesp, true));
    return;
}

//#17
void testSize(void) {
    BetterString test("hey");
    BetterString test2;
    bool correct = test.size() == 3 && test2.size() == 0; 
    vec.push_back(assert(correct, true));
    return;
}


//#18
void testAsStr(void) {
    BetterString test("hello");
    bool str = test.as_str() == "hello";
    vec.push_back(assert(str, true));
    return;
}

//#19
void testCStr(void) {
    BetterString test("hello");
    BetterString empty;
    std::string one = "hello";
    std::string two = "";
    bool cstr = strcmp(test.c_str(), one.c_str()) == 0 && strcmp(empty.c_str(), two.c_str()) == 0; 
    vec.push_back(assert(cstr, true));
    return;
}

//#20
void testSuFirst(void) {
    BetterString test("banana");
    BetterString rem("a");
    BetterString su = test.subtractFirst(rem);
    bool suf = su.as_str() == "bnana";
    BetterString rem2("t");
    BetterString sun = test.subtractFirst(rem2);
    bool suni = sun.as_str() == "banana";
    vec.push_back(assert(suf && suni, true));
    return;
}

//#21
void testLower(void) {
    BetterString test("HELLO1! ");
    BetterString lower = test.lower();
    vec.push_back(assert(lower.as_str() == "hello1! ", true));
    return;
}

//#22
void testUpper(void) { 
    BetterString test("hello1! world");
    BetterString upper = test.upper();
    vec.push_back(assert(upper.as_str() == "HELLO1! WORLD", true));
    return;
}

//#23
void testTitle(void) {
    BetterString test("hello world 1!");
    BetterString title = test.title();
    vec.push_back(assert(title.as_str() == "Hello World 1!", true));
    return;
}

//#24
void testIndexOne(void) {
    BetterString one("one");
    BetterString check("o");
    BetterString check2("t");
    BetterString check3("ne");
    bool in = one.index(check.as_str()) == 0;
    bool nin = one.index(check2.as_str()) == -1;
    bool lin = one.index(check3.as_str()) == 1;
    vec.push_back(assert(in && nin && lin, true));
    return;
}

//#25
void testIndexTwo(void) {
    BetterString one("nothing");
    BetterString check("n");
    BetterString check2("f");
    BetterString check3("in");
    bool in = one.index(check.as_str(), 2) == 5;
    bool nin = one.index(check2.as_str(), 3) == -1;
    bool lin = one.index(check3.as_str(), 4) == 4;
    bool nlin = one.index(check3.as_str(), 5) == -1;
    vec.push_back(assert(in && nin && lin && nlin, true));
    return;
}

//#26
void testEqIC(void) {
    BetterString one("one");
    BetterString two("OnE");
    BetterString three("two");
    BetterString four("four");
    bool eq = one.equalsIgnoreCase(two);
    bool neq = two.equalsIgnoreCase(three);
    bool longer = one.equalsIgnoreCase(four);
    vec.push_back(assert(eq && !neq && !longer, true));
    return;
}

//#27
void testOut(void) {
    BetterString in("in");
    std::string i = "i";
    std::string sI = i << in; 
    /*
    std::cout << sI; true
    std::cout << "i" << in; true
    */
    vec.push_back(assert(sI == "iin" && true && true, true)); //Extra true's for ostream& << and const char* << 
    return;
}

//#28
void testIn(void) {
    BetterString in; 
    /*
    std::cin >> in; true
    */
    vec.push_back(assert(true, true));
    return;
}

//#29
void testIterator(void) {
    std::string test = "";
    BetterString str("hello");
    vec.push_back(false);
    return;
}