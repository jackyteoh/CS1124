// 12.07.2016 C++ Notes - STL
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void swap(char& a, char& b) {
	char temp = a;
	a = b;
	b = temp;
}

// Templated function
template <class T>
void swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

int main() {

}

/*


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
}
*/