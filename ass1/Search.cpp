#include "CardCatalog.h"
#include "Media.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

void getFilter(){

  // allow user to interact and provide a filter criterion
  cout << "Enter 1 to search records using call_number" << endl;
  cout << "Enter 2 to search records using title" << endl;
  cout << "Enter 3 to search records using subject" << endl;
  cout << "Enter 4 to search records using other" << endl;
  cout << "Enter 0 to leave program" << endl;

}




int main(){

  int filter = -1;
  vector<Media *> resultList;
  CardCatalog cc; // all data is read here in constructor
  //cc.showRecords();  
  getFilter();
  cin >> filter;

  while( filter != 0 ){
    if(filter == 1){

        string user_call_number;
        cout << "Please enter the call_number you wish to look up";
        cin.ignore();
        getline(cin,user_call_number);
        resultList = cc.searchByCallNumber(user_call_number);
        cc.display(resultList);
    }
    else if(filter == 2){

      string user_title;
      cout << "Please enter the title you wish to look up";
      cin.ignore();
      getline(cin,user_title);
      cout << user_title << endl;
      resultList = cc.searchByTitle(user_title);
      cc.display(resultList);

    }
    else if(filter == 3){

      string user_subject;
      cout << "Please enter the subject you wish to look up";
      cin.ignore();
      getline(cin,user_subject);
      resultList = cc.searchBySubjects(user_subject);
      cc.display(resultList);

    }
    else if(filter == 4){

      string user_other;
      cout << "Please enter the other value you wish to look up";
      cin.ignore();
      getline(cin,user_other);
      resultList = cc.searchByOthers(user_other);
      cc.display(resultList);

    }
    else{
      cout << "Please select appropriate filter number" << endl;
    }

    // keep reading filter from user till he quits with 0 as input
    cout << endl;
    getFilter();
    cin >> filter;

  }

  return 0;
}
