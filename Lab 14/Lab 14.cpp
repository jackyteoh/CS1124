/*
Jacky Teoh
CS 1124 : Rec 14 : STL
12.09.2016
rec 14.cpp
*/

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#include <fstream>
#include <map>
#include <set>

using namespace std;

// Task 8
void listIterator(const list<int>& x) {
	for (list<int>::const_iterator it = x.begin(); it != x.end(); it++) {
		cout << *it << ' ';
	}
}

void rangedListIterator(const list<int>& x) {
	auto it = begin(x);
	for (auto& value : x) {
		cout << *it << ' ';
		it++;
	}
}

void autoListIterator(const list<int>& x) {
	auto it = begin(x);
	for (auto& value : x) {
		cout << *it << ' ';
		it++;
	}
}

bool isEven(int n) {
	return n % 2 == 0;
}

list<int>::const_iterator taskEleven(const list<int>& aList, int search) {
	for (list<int>::const_iterator iter = aList.begin(); iter != aList.end(); iter++) {
		if (*iter == search) {
			return iter;
		}
	}

	return aList.end();
}

auto taskTwelve(const list<int>& aList, int search) {
	for (auto iter = aList.begin(); iter != aList.end(); iter++) {
		if (*iter == search) {
			return iter;
		}
	}

	return aList.end();
}

list<int>::iterator ourFind(list<int>::iterator start, list<int>::iterator stop, int target) {
	cout << "find" << endl;
	for (list<int>::iterator p = start; p != stop; p++) {
		if (target == *p) {
			return p;
		}
	}
	return stop;
}

template<typename Searcher, typename Searchee>
Searcher ourFind(Searcher start, Searcher stop, Searchee target) {
	cout << "template find" << endl;
	for (Searcher p = start; p != stop; p++) {
		if (target == *p) {
			return p;
		}
	}
	return stop;
}

int main() {
	// Task 1
	vector<int> v;
	v.push_back(5);
	v.push_back(3);
	v.push_back(7);

	cout << "Task 1 : Contents of vector are: " << endl;
	for (int x : v) {
		cout << x << ' ';
	}

	// Task 2
	cout << endl << "Task 2 : Contents of list are: " << endl;
	list<int> l(v.begin(), v.end());
	for (list<int>::iterator it = l.begin(); it != l.end(); it++) {
		cout << *it << ' ';
	}

	// Task 3
	cout << endl << "Task 3 : Sorted vector is: " << endl;
	sort(v.begin(), v.end());
	for (int x : v) {
		cout << x << ' ';
	}

	// Task 4
	cout << endl << "Task 4 : Every other element in the list: " << endl;
	for (int i = 0; i < v.size(); i += 2) {
		cout << v[i] << ' ';
	}

	// Task 5
	cout << endl << "Task 5 : Sorting list: " << endl;
	l.sort();
	for (list<int>::iterator it = l.begin(); it != l.end(); it++) {
		cout << *it << ' ';
	}

	// Task 6
	//cout << endl << "Task 6 : Iterator for Vector: " << endl;
	//for (vector<int>::iterator it = v.begin(); it != v.end(); it += 2) {
	//	cout << *it << ' ';
	//}

	// Task 7
	cout << endl << "Task 7 : Iterator for List: " << endl;
	for (list<int>::iterator it = l.begin(); it != l.end(); it++) { // doesn't support random access
		cout << *it << ' ';
	}

	// Task 8
	cout << endl << "Task 8 : Function for List Iterator: " << endl;
	listIterator(l);

	// Task 9
	cout << endl << "Task 9 : Ranged For for List Iterator: " << endl;
	rangedListIterator(l);

	// Task 10
	cout << endl << "Task 10 : Auto: " << endl;
	autoListIterator(l);

	// Task 11 
	taskEleven(l, 3);

	// task 12
	taskTwelve(l, 5);

	// task 13
	find(l.begin(), l.end(), 5);

	// task 14
	cout << *find_if(l.begin(), l.end(), isEven) << endl;

	// task 15
	cout << *find_if(l.begin(), l.end(), [](int x) {return x % 2 == 0; }) << endl;



	// task 16
	printTask(16);
	int arr[oneVector.size()];
	copy(oneVector.begin(), oneVector.end(), arr);
	for (size_t x = 0; x < oneVector.size(); x++) {
		cout << arr[x] << ' ';
	}
	cout << *find(arr, arr + oneVector.size(), 1) << endl;
	cout << *find(arr, arr + oneVector.size(), 200) << endl;
	endLine();
	endLine();
	printBreak();

	// task 17
	printTask(17);
	ourFind(twoList.begin(), twoList.end(), 1);
	endLine();
	printBreak();

	// task 18
	printTask(18);
	ourFind(oneVector.begin(), oneVector.end(), 1);
	endLine();
	printBreak();

	// task 19
	printTask(19);
	ifstream ifs;
	ifs.open("lab/14/pooh-nopunc.txt");
	vector<string> taskNineteen;
	string word;
	while (ifs >> word) {
		if (find(taskNineteen.begin(), taskNineteen.end(), word) == taskNineteen.end()) {
			taskNineteen.push_back(word);
		}
	}
	for (string aWord : taskNineteen) {
		cout << aWord << ' ';
	}
	endLine();
	endLine();
	printBreak();

	// task 20
	printTask(20);
	set<string> taskTwenty;
	ifs.clear();
	ifs.seekg(0);
	while (ifs >> word) {
		taskTwenty.insert(word);
	}
	for (string aWord : taskTwenty) {
		cout << aWord << ' ';
	}
	endLine();
	endLine();
	printBreak();

	// task 21
	printTask(21);
	map<string, vector<int>> wordMap;
	ifs.clear();
	ifs.seekg(0);
	while (ifs >> word) {
		wordMap[word].push_back(ifs.tellg());
	}
	for (auto loopVar : wordMap) {
		cout << loopVar.first << ": ";
		for (int x : loopVar.second) {
			cout << x << ' ';
		}
		endLine();
	}
	printBreak();

	system("pause");
}
