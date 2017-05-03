// 12.12.2016 C++ Notes - STL pt. 2
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <list>
#include <set>
#include <map>

using namespace std;

int& min(int& a, int& b) {
	if (a < b) {
		return a;
	}
	return b;
}

template<class T, class S>
class Pair { // Tying two heterogeneous data types
public:
	T first;
	S second;
};

int main() {
	map<string, int> testScores; // Keeps in sorted order based on first item.
	testScores.insert(pair<string,int>("Daniel Katz", 100));
	testScores["John Jones"] = 90;
	testScores["Albert Einstein"] = 99;
	for (map<string, int>::iterator i = testScores.begin(); i != testScores.end(); i++) {
		cout << i->first << "= " << i->second << endl;
	}

	srand(time(NULL));
	set<int> s; // Keeps things in sorted order, also doesn't do duplicates.
	multiset<int> m; // Keeps things in sorted order, BUT allows duplicates.
	for (int i = 0; i < 100; i++) {
		s.insert(rand() % 100);
	}
	int counter = 0;
	for (int i : s) {
		cout << i << endl;
		counter++;
	}
	cout << "There are " << counter << " items in this set." << endl;


	pair<string, int> p;
	p.first = "Daniel Katz";
	p.second = 100;

	pair<pair<string, int>, pair<char, float>> confusingThing;
	confusingThing.first.first = "John";
	confusingThing.first.second = 100;
	confusingThing.second.first = 'A';
	confusingThing.second.second = 5.5;

	list<int> l;
	for (int i = 0; i < 100; i++) {
		l.push_front(i * 100);
	}
	for (list<int>::iterator i = l.begin(); i != l.end(); i++) {
		cout << *i << endl;
	}
	list<int>::iterator i = l.end();
	i--;
	cout << "The last element in the list is: " << *i << endl;
	for (int i : l) {
		cout << i << endl;
	}

	int x = 5;
	int y = 10;
	int& z = min(x, y);
	z++;
	cout << x << endl;
	cout << y << endl;
	cout << z << endl;

	// 6, 10, 6

	vector<int> v; // Standard Template Library (STL) 
	for (int i = 0; i < 100; i++) {
		v.push_back(i * 100);
	}
	for (int i : v) { // Ranged for makes a copy, i
		i = i * 2;
	}
	for (int& i : v) { 
		i = i * 2;
	}
	for (int i : v) {
		cout << i << endl;
	}

	system("pause");
}