#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

struct F1Race{
	string name;
	int position;
	float number[3];
};

int main(){
	F1Race winner[20] = {
		{"Max Verstappen", 1, {1}},
        {"Charles Leclerc", 2, {16}},
        {"Lewis Hamilton", 3, {44}},
        {"Sergio Perez", 4, {11}},
        {"George Russel", 5, {15}},
        {"Lando Norris", 6, {4}},
        {"Mick Schumacher", 7, {27}},
        {"Fernando Alonso", 8, {10}},
        {"Kevin Magnussen", 9, {17}},
        {"Esteban Ocon", 10, {56}},
        {"Daniel Ricciardo", 11, {3}},
        {"Carlos Sainz", 12, {55}},
        {"Sebastian Vettel", 13, {5}},
        {"Pierre Gasly", 14, {12}},
        {"Yuki Tsunoda", 15, {17}},
        {"Nicholas Latifi", 16, {90}},
        {"Nikita Mazepin", 17, {69}},
        {"Nico Hulkenberg", 18, {78}},
        {"Rio Haryanto", 19, {87}},
        {"Nyck De Vries", 20, {36}},
	};
	
	for (int i = 0; i < 20; i++){
		cout << "Name : " << winner[i].name << endl;
        cout << "Position : " << winner[i].position << endl;
        
        for (int j = 0; j < 1; j++){
        	cout << "Racing Number :" << winner[i].number[j] << endl;
		}
	}
	return 0;
}
