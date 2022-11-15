#include <iostream>

using namespace std;

struct F1{
  string driversname, driversteam;
  int driversnumber;
  F1 *prev;
  F1 *next;
};

F1 *head, *tail, *cur, *newNode, *afterNode;


void createF1( string name, string team, int number ){
  head = new F1();
  head->driversname = name;
  head->driversteam = team;
  head->driversnumber = number;
  head->prev = head;
  head->next = head;
  tail = head;
}


void addFirst( string name, string team, int number ){
  if( head == NULL ){
    cout << "Linked List Not Exist" << endl;
  }else{
    newNode = new F1();
    newNode->driversname = name;
    newNode->driversteam = team;
    newNode->driversnumber = number;
    newNode->prev = tail;
    newNode->next = head;
    head->prev = newNode;
    tail->next = newNode;
    head = newNode;
  }
}


void addLast( string name, string team, int number ){
  if( head == NULL ){
    cout << "Linked List Not Exist" << endl;
  }else{
    newNode = new F1();
    newNode->driversname = name;
    newNode->driversteam = team;
    newNode->driversnumber = number;
    newNode->prev = tail;
    newNode->next = head;
    head->prev = newNode;
    tail->next = newNode;
    tail = newNode;
  }
}


void addMiddle( string name, string team, int number, int position ){
  if( head == NULL ){
    cout << "Linked List Not Exist" << endl;
  }else{
    if( position == 1 ){
      cout << "First Position Is Not In The Middle" << endl;
    }else if( position < 1 ){
      cout << "Position Out Of Range" << endl;
    }else{
      newNode = new F1();
      newNode->driversname = name;
      newNode->driversteam = team;
      newNode->driversnumber = number;

      cur = head;
      int number = 1;
      while ( number < position - 1 ){
        cur = cur->next;
        number++;
      }
      afterNode = cur->next;
      cur->next = newNode;
      afterNode->prev = newNode;
      newNode->prev = cur;
      newNode->next = afterNode;
    }
  }
}

void printF1()
{
  if( head == NULL ){
    cout << "Linked List Not Exist" << endl;
  }else{
    cout << "F1 Data" << endl;
    cout<<"-----------------"<<endl;
    cur = head;
    while( cur->next != head ){
      
      cout << "Driver's Name : " << cur->driversname << endl;
      cout << "Driver's Team : " << cur->driversteam << endl;
      cout << "Driver's Number : " << cur->driversnumber << endl<< endl;
      
      cur = cur->next;
    }
    
	  cout << "Driver's Name : " << cur->driversname << endl;
      cout << "Driver's Team : " << cur->driversteam << endl;
      cout << "Driver's Number : " << cur->driversnumber << endl<< endl;
  }
}

int main(){
	
  createF1("Max Verstappen", "Red Bull", 1);
  printF1();
  cout<<endl<<endl;

  addFirst("Charles Leclerc", "Scuderia Ferrari", 16);
  printF1();
  cout<<endl<<endl;

  addLast("George Russel", "Mercedes AMG", 63);
  printF1();
  cout<<endl<<endl;

  addMiddle("Lando Norris", "Mclaren", 4 , 3);
  printF1();
  cout<<endl<<endl;
}