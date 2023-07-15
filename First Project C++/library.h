#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
struct Stats{
string url; 
string name; 
string team; 
int jersey;
double seasonavr[5]; 
double total; 
double avr;
double highest; 
};

void collect_one_player(ifstream& fin, Stats& s );
void collect_all(Stats arr[], unsigned& d);
void display_one_player(Stats s);
void display_all(const Stats arr[], unsigned d);
void sort_by_avg(Stats arr[], unsigned d);
void sort_by_player(Stats arr[], unsigned d);
void sort_by_highest(Stats arr[], unsigned d);
void sort_by_jersey(Stats arr[], unsigned d);
void sort_by_team(Stats arr[], unsigned d);
void remove_a_player(Stats arr[], unsigned& d, string name);
int lookup_one(Stats arr[], unsigned d, string n);
void display_lookup_one(Stats s);
void check(Stats arr[], unsigned d, string n, bool& z);