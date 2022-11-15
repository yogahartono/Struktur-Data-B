#include <iostream>

using namespace std;


struct F1{
  string driversname, driversteam, driversnumber;
  F1 *next;
};

F1 *head, *tail, *newNode, *cur;

void createCircularSingleLinkedList(string newData[3]){
  head = new F1();
  head->driversname = newData[0];
  head->driversteam = newData[1];
  head->driversnumber = newData[2];
  tail = head;
  tail->next = head;
}

void addFirst( string data[3] ){
  if( head == NULL ){
    cout << "Linked List Not Exist" << endl;
  }else{
    newNode = new F1();
    newNode->driversname = data[0];
    newNode->driversteam = data[1];
    newNode->driversnumber = data[2];
    newNode->next = head;
    tail->next = newNode;
    head = newNode;
  }
}


void addLast( string data[3] ){
  if( head == NULL ){
    cout << "Linked List Not Exist" << endl;
  }else{
    newNode = new F1();
    newNode->driversname = data[0];
    newNode->driversteam = data[1];
    newNode->driversnumber = data[2];
    newNode->next = head;
    tail->next = newNode;
    tail = newNode;
  }
}

void addMiddle(string data[3], int posisi)
{
  if( head == NULL ){
    cout << "Linked List Not Exist" << endl;
  }else{
    if( posisi == 1 ){
      cout << "First Position Is Not In The Middle" << endl;
    }else{
      newNode = new F1();
      newNode->driversname = data[0];
      newNode->driversteam = data[1];
      newNode->driversnumber = data[2];

      
      int nomor = 1;
      cur = head;
      while (nomor < posisi - 1)
      {
        cur = cur->next;
        nomor++;
      }
      newNode->next = cur->next;
      cur->next = newNode;
    }
  }
}

void printCircular()
{
  if( head == NULL ){
    cout << "Linked List Not Exist" << endl;
  }else{
    cout << "F1 Data " << endl;
    cout<<"-----------------"<<endl;
    cur = head;
    while(cur->next != head ){
      
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
  string newData[3] = {"Max Verstappen", "Red Bull", "1"};
  createCircularSingleLinkedList(newData);
  printCircular();
  cout<<endl<<endl;

  string data[3] = {"Charles Leclerc", "Scuderia Ferrari", "16"};
  addFirst(data);
  printCircular();
  cout<<endl<<endl;
  
  string data2[3] = {"George Russel", "Mercedes AMG", "63"};
  addLast(data2);
  printCircular();
  cout<<endl<<endl;
  
  string data3[3] = {"Lando Norris", "Mclaren", "4"};
  addMiddle(data3, 3);
  printCircular();
  cout<<endl<<endl;
}