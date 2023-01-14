#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

#include <iostream>

#define nil NULL
#define info(S) ((S).info)
#define Top(S) ((S).Top)

using namespace std;
const int nMax = 50;

typedef string infotype;
struct Stack{
    infotype info[nMax];
    int Top;
};

typedef char infotypec;
struct Stack_Chr {
    infotypec info[nMax];
    int Top;
};

typedef int infotypeck;
struct Stack_int {
    infotypeck info[nMax];
    int Top;
};

//program insert,delete dan show data
bool isEmpty(Stack S);
bool isFull(Stack S);
void createStack(Stack &S);
void insertData(Stack &S, infotype x);
infotype deleteData(Stack &S);

//Program yang mengubah notasi infix to prefix
bool isEmpty_Chr(Stack_Chr S);
bool isFull_Chr(Stack_Chr S);
void createStack_Chr(Stack_Chr &S);
void insertData_Chr(Stack_Chr &S, infotypec x);
infotypec deleteData_Chr(Stack_Chr &S);
string reverseString(string x);
bool isOperator(char c);
int precedence(char c);
string infixToPrefix(Stack_Chr s, string x);

//program yang mengurutkan array dengan stack
bool isEmpty_int(Stack_int S);
bool isFull_int(Stack_int S);
void createStack_int(Stack_int &S);
void insertData_int(Stack_int &S, infotypeck x);
infotypec deleteData_int(Stack_int &S);
Stack_int sortArray(Stack_int S);
void showAllData_int(Stack_int S);

//main program
void showAllData(Stack S);
int mainMenu();

#endif // HEAD_H_INCLUDED
