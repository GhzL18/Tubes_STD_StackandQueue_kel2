#include "Head.h"

//program insert, delete, dan show data
//membuat program jika stack kosong maka return true
bool isEmpty(Stack S){
    if (Top(S) == -1){
        return true;
    }else{
        return false;
    }
}

//membuat program jika stack penuh maka return true
bool isFull(Stack S){
    if (Top(S) == nMax){
        return true;
    } else {
        return false;
    }
}

//membuat sebuah stack baru
void createStack(Stack &S){
    Top(S) = -1;
}

//membuat program input data kedalam stack atau push
void insertData(Stack &S, infotype x){
    if (!isFull(S)){
        Top(S)++;
        info(S)[Top(S)] = x;
    }
}

//membuat program keluarkan data dari dalam stack atau pop
infotype deleteData(Stack &S){
    infotype x;
    if(isFull(S) == false){
        x = Top(S);
        Top(S) --;
    }
    return x;
}

//membuat program menampilkan semua data yang berada di dalam stack
void showAllData(Stack S){
    for (int i = Top(S); i >= 0; i--){
        cout << info(S)[i] << endl;
    }
//    cout << Top(S);
}

//Program mengubah notasi infix to prefix
//membuat program jika stack kosong maka return true
bool isEmpty_Chr(Stack_Chr S){
    if (Top(S) == nil){
        return true;
    }else{
        return false;
    }
}

//membuat program jika stack penuh maka return true
bool isFull_Chr(Stack_Chr S){
    if (Top(S) == nMax){
        return true;
    } else {
        return false;
    }
}

//membuat sebuah stack baru
void createStack_Chr(Stack_Chr &S){
    Top(S) = 0;
}

//membuat program input data kedalam stack atau push
void insertData_Chr(Stack_Chr &S, infotypec x){
    if (isFull_Chr(S) == false){
        Top(S)++;
        info(S)[Top(S)] = x;
    }
}

//membuat program keluarkan data dari dalam stack atau pop
infotypec deleteData_Chr(Stack_Chr &S){
    if(isFull_Chr(S) == false){
        Top(S) --;
    }
}

//membuat program yang membedakan operator dan bilangan string biasa
bool isOperator(char c){
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
        return true;
    }
    else {
        return false;
    }
}

//membuat program agar mengatahui yang mana akan di prioritaskan
int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

//membuat program yang dapat membalikan data
string reverseString(string x){
    string y;
    for(int i = x.length() - 1; i >= 0; i--)
    {
      	y += x[i];
    }
    return y;
}

//membuat sebuah program yang mengubah notasi infix to prefix
string infixToPrefix(Stack_Chr s, string x){
    string prefix;
    x = reverseString(x);

    for (int i = 0; i < x.length(); i++) {
        if (x[i] == '(') {
            x[i] = ')';
        }
        else if (x[i] == ')') {
            x[i] = '(';
        }
    }
    for (int i = 0; i < x.length(); i++) {
        if ((x[i] >= 'a' && x[i] <= 'z') || (x[i] >= 'A' && x[i] <= 'Z')) {
            prefix += x[i];
        }
        else if (x[i] == '(') {
            insertData_Chr(s, x[i]);
        }
        else if (x[i] == ')') {
            while ((info(s)[Top(s)] != '(') && (!isEmpty_Chr(s))) {
                prefix += info(s)[Top(s)];
                deleteData_Chr(s);
            }

            if (info(s)[Top(s)] == '(') {
                deleteData_Chr(s);
            }
        }
        else if (isOperator(x[i])) {
            if (isEmpty_Chr(s)) {
                insertData_Chr(s, x[i]);
            }
            else {
                if (precedence(x[i]) > precedence(info(s)[Top(s)])) {
                    insertData_Chr(s, x[i]);
                }
                else if ((precedence(x[i]) == precedence(info(s)[Top(s)])) && (x[i] == '^')) {
                    while ((precedence(x[i]) == precedence(info(s)[Top(s)])) && (x[i] == '^')) {
                        prefix += info(s)[Top(s)];
                        deleteData_Chr(s);
                    }
                    insertData_Chr(s, x[i]);
                }
                else if (precedence(x[i]) == precedence(info(s)[Top(s)])) {
                    insertData_Chr(s, x[i]);
                }
                else {
                    while ((!isEmpty_Chr(s)) && (precedence(x[i]) < precedence(info(s)[Top(s)]))) {
                        prefix += info(s)[Top(s)];
                        deleteData_Chr(s);
                    }
                   insertData_Chr(s, x[i]);
                }
            }
        }
    }

    while (!isEmpty_Chr(s)) {
        prefix += info(s)[Top(s)];
        deleteData_Chr(s);
    }

    prefix = reverseString(prefix);
    return prefix;
}

//Program yang mengurutkan array dengan stack
//membuat program jika stack kosong maka return true
bool isEmpty_int(Stack_int S){
    if (Top(S) == 0){
        return true;
    }else{
        return false;
    }
}

//membuat program jika stack penuh maka return true
bool isFull_int(Stack_int S){
    if (Top(S) == nMax){
        return true;
    } else {
        return false;
    }
}

//membuat sebuah stack baru
void createStack_int(Stack_int &S){
    Top(S) = 0;
}

//membuat program input data kedalam stack atau push
void insertData_int(Stack_int &S, infotypeck x){
    if (isFull_int(S) == false){
        Top(S)++;
        info(S)[Top(S)] = x;
    }
}

//membuat program keluarkan data dari dalam stack atau pop
infotypec deleteData_int(Stack_int &S){
    if(isFull_int(S) == false){
        Top(S) --;
    }
}

//membuat program menampilkan semua data yang berada di dalam stack
void showAllData_int(Stack_int S){
    for (int i=1; i <= Top(S); i++){
        cout << info(S)[i] << " ";
    }
}

//Membuat sebuah program yang dapat mengurutkan array dalam stack
Stack_int sortArray(Stack_int S){
    Stack_int tmpStack;
    createStack_int(tmpStack);

    while (!isEmpty_int(S))
    {
        // keluarkan elemen pertama stack S
        infotypeck tmp = info(S)[Top(S)];
        deleteData_int(S);

        // selama stack temporary tidak kosong dan
        // info Top stack temporary lebih besar daripada temp
        while (!isEmpty_int(tmpStack) && info(tmpStack)[Top(tmpStack)] > tmp)
        {
            // keluarkan elemen dari stack temporary dan tambahkan
            // ke stack S
            insertData_int(S, info(tmpStack)[Top(tmpStack)]);
            deleteData_int(tmpStack);
        }

        // tambahkan temp ke stack temporary
        insertData_int(tmpStack, tmp);
    }

    return tmpStack;
}


//main Program
//membuat sebuah main menu
int mainMenu(){
    cout << "=============== MENU ===============" << endl;
    cout << "1. Insert Data" << endl;
    cout << "2. Delete Data " << endl;
    cout << "3. Show Data " << endl;
    cout << "4. Change Infix To Prefix " << endl;
    cout << "5. Mengurutkan Data " << endl;
    cout << "0. Exit" << endl;
    cout << "====================================" << endl;
    cout << "Masukkan Pilihan Menu : ";

    int input   = 0;
    cin >> input;

    return input;

}
