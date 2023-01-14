#include <iostream>
  #include "Head.h"
  using namespace std;

  int main()
  {
      Stack S;
      createStack(S);
      Stack_Chr s;
      Stack_int SS, sorted;
      infotype x;
      infotypeck z;
      int k, i;
      string lanjut, t;
      createStack_Chr(s);
      int Select = 0;
      Select = mainMenu();

      while (Select != 0){
          switch(Select){
          case 1:
              cout << "Jumlah data yang ingin di input: "; cin >> k;
  //            menambahInputan(S, k);
              for (i = 0; i < k; i++){
                  cout << "Input data: ";
                  cin >> x;
                  insertData(S,x);
              }
              break;

          case 2:
              cout << "Berapa Data yang ingin di hapus: "; cin >> k;
              for (i = 0; i < k ; i++){
                  deleteData(S);
              }
              cout << endl;
              showAllData(S);
              break;

          case 3:
              showAllData(S);
              break;

          case 4:
              cout << "Masukan Data yang ingin diubah notasinya: ";cin >> t;
              cout << "Infix: " << t << endl << "Prefix: " << infixToPrefix(s, t) << endl;
              break;

          case 5:
              cout << "Jumlah data yang ingin di input: "; cin >> k;
  //            menambahInputan(S, k);
              for (i = 0; i < k; i++){
                  cout << "Input data: "; cin >> z;
                  insertData_int(SS,z);
              }
              cout << endl << "Before: ";
              showAllData_int(SS);
              cout << endl << "After: ";
              sorted = sortArray(SS);
              showAllData_int(sorted);
              cout << endl;
              break;

          }
          cout << endl;
          cout << "Ingin Kembali? (y/n): ";cin >> lanjut;
          cout << endl;
          if(lanjut == "y" || lanjut == "Y"){
              Select = mainMenu();
          }else{
              Select = 0;
          }
      }
      cout << endl << "Good Bye :D" << endl;






          /*

      cout << endl << infixToPrefix(s, x);

          cout << endl;
          cout << "Coba lagi? <Y/N>: "; cin >> lanjut;
          if(lanjut == "Y") {
              pilihan = pilihanMenu_1301213378();
          }else{
              pilihan = 0;
          }
      }
      cout << "Selamat jalan!" << endl;
      *
      Stack S;
      Stack_Chr s;
      infotype x;

      x = "(A+B)-C*D";
      createStack(S);
      insertData(S, x);
      showAllData(S);
      createStack_Chr(s);

      cout << endl << infixToPrefix(s, x) << endl;

      Stack_int SS;
      Stack_int sorted;
      infotypeck y;
      createStack_int(SS);

  //    for (int i = 0; i < 5; i++){
  //        cin >> y;
  //        insertData_int(SS, y);
  //    }

      y = 1;
      insertData_int(SS, y);
      y = 8;
      insertData_int(SS, y);
      y = 4;
      insertData_int(SS, y);
      y = 6;
      insertData_int(SS, y);
      y = 2;
      insertData_int(SS, y);

      showAllData_int(SS);
      sorted = sortArray(SS);
      cout << endl;
      showAllData_int(sorted);
      */

      return 0;
  }
