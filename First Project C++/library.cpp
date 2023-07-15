#include "library.h"
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

void collect_one_player(ifstream &fin, Stats &s) {
  s.highest = 0;
  s.total =  0;
  getline(fin, s.name, ',');
  getline(fin, s.team, ',');
  fin >> s.jersey;
  fin.ignore();
  for (int i = 0; i < 5; i++) {
    fin >> s.seasonavr[i];
    s.total += s.seasonavr[i];
    fin.ignore();
    if (s.seasonavr[i] > s.highest) {
      s.highest = s.seasonavr[i];
    }
  }
  s.avr = s.total / 5;
   }

void collect_all(Stats arr[], unsigned& d) {
  ifstream input("input.dat");
  // this next line ignores the URL.
  input.ignore(1000, '\n');
  while (!input.eof()) {
    collect_one_player(input, arr[d]);
    d++;
  }
}
void display_one_player(Stats s) {
  cout << left << setw(19) << s.name;
  cout << left << setw(10) << s.team;
  cout << left << setw(7) << s.jersey;
  for (int i = 0; i < 5; i++) {
    cout << left << setw(12) << s.seasonavr[i];
  }
  cout << left << setw(10) << s.avr;
  cout << left << setw(6) << s.highest;
  cout << endl;
}
void display_all(const Stats arr[], unsigned d) {
  cout << left << setw(19) << "Name";
  cout << left << setw(10) << "Team";
  cout << left << setw(7) << "#";
  cout << left << setw(12) << "2017/2018";
  cout << left << setw(12) << "2018/2019";
  cout << left << setw(12) << "2019/2020";
  cout << left << setw(12) << "2020/2021";
  cout << left << setw(12) << "2021/2022";
  cout << left << setw(10) << "AVR";
  cout << left << setw(6) << "Highest" << endl;
  cout << endl;
  
  for (int i = 0; i < d; i++) {
    display_one_player(arr[i]);
  }
}
void sort_by_avg(Stats arr[], unsigned d) {
  for (int j = 1; j < d; j++) {
    for (int i = j; i > 0 && arr[i-1].avr < arr[i].avr; i--) {
      swap(arr[i-1], arr[i]);
    }
  }
}
void sort_by_player(Stats arr[], unsigned d) {
  for (int j = 1; j < d; j++) {
    for (int i = j; i > 0 && arr[i-1].name > arr[i].name; i--) {
      swap(arr[i-1], arr[i]);
    }
  }
}
void sort_by_highest(Stats arr[], unsigned d) {
  for (int j = 1; j < d; j++) {
    for (int i = j; i > 0 && arr[i-1].highest < arr[i].highest; i--) {
      swap(arr[i-1], arr[i]);
    }
  }
}
void sort_by_jersey(Stats arr[], unsigned d) {
  for (int j = 1; j < d; j++) {
    for (int i = j; i > 0 && arr[i-1].jersey > arr[i].jersey; i--) {
      swap(arr[i-1], arr[i]);
    }
  }
}
void sort_by_team(Stats arr[], unsigned d) {
  for (int j = 1; j < d; j++) {
    for (int i = j; i > 0 && arr[i-1].team < arr[i].team; i--) {
      swap(arr[i-1], arr[i]);
    }
  }
}
void remove_a_player(Stats arr[], unsigned& d, string n) {
  int index = 0;
  while (index < d && n != arr[index].name){
    index++;
  }
  if (index != d) {
    for (int i = index; i < d - 1; i++){
      arr[i] = arr[i + 1];
    }
    d--;
  }
}
int lookup_one(Stats arr[], unsigned d, string n){
    int index = 0;
  while (index < d && n != arr[index].name){
    index++;
    }
return index;
}

void display_lookup_one(Stats s) {
  cout << left << setw(19) << "Name";
  cout << left << setw(10) << "Team";
  cout << left << setw(7) << "#";
  cout << left << setw(12) << "2017/2018";
  cout << left << setw(12) << "2018/2019";
  cout << left << setw(12) << "2019/2020";
  cout << left << setw(12) << "2020/2021";
  cout << left << setw(12) << "2021/2022";
  cout << left << setw(10) << "AVR";
  cout << left << setw(6) << "Highest" << endl;
  cout << endl;
  cout << left << setw(19) << s.name;
  cout << left << setw(10) << s.team;
  cout << left << setw(7) << s.jersey;
  for (int i = 0; i < 5; i++) {
    cout << left << setw(12) << s.seasonavr[i];
  }
  cout << left << setw(10) << s.avr;
  cout << left << setw(6) << s.highest;
  cout << endl;
}

void check(Stats arr[], unsigned d, string n, bool& z){
   
    int index = 0;
  while (index < d && n != arr[index].name){
    index++;
  }
  if(index == d){
    z = true;
  
  }
  else{
    z = false;
  }
}
