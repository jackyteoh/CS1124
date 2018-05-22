/*
Jacky Teoh - jt2908
CS 1124 - Homework #5 - Extra Credit : Problem 8
hw 05.cpp
*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

// Forward declaration
class Artist;

// Painting class
class Painting {
public:
	// Painting constructor, taking in a string title and artist*, and setting paintingTitle to title and artist to artist.
	Painting(const string& title, Artist* artist) : paintingTitle(title), artist(artist) {}
	// Getter function for the title of the painting
	string getTitle() const {
		return paintingTitle;
	}
	// Setter function for the name of the painting
	void setTitle(string& newTitle) {
		paintingTitle = newTitle;
	}
private:
	string paintingTitle;
	Artist* artist;
};

// Artist class
class Artist {
public:
	// Artist constructor, taking in a string newName and setting artistName to newName.
	Artist(string& newName) : artistName(newName) {}
	// Getter function for the name of the artist
	string getName() const {
		return artistName;
	}
	// Setter name for the name of the artist.
	void setName(string& newName) {
		artistName = newName;
	}
	// createPainting function
	Painting* createPainting(const string& newPainting);
	// Iterates over the vector of Painting within the artist, prints out the title, and then prints out painted by his/her name.
	void display() const;
	// Clears the vector of Paintings
	void destroy() {
		vectorOfPaintings.clear();
	}
private:
	string artistName;
	// Each artist has a vector of his paintings
	vector<Painting> vectorOfPaintings;
};

// createPainting function, which takes in a string(newPainting) and makes a painting on the heap, passing in string + Artist
// Then pushes back the dereference of the painting created into vectorOfPaintings.
Painting* Artist::createPainting(const string& newPainting) {
	Painting* painting = new Painting(newPainting, this);
	vectorOfPaintings.push_back(*painting);
	return painting;
}
// Iterates over the vector of Painting within the artist, prints out the title, and then prints out painted by his/her name.
void Artist::display() const {
	for (size_t i = 0; i < vectorOfPaintings.size(); i++) {
		cout << vectorOfPaintings[i].getTitle() << " painted by " << this->getName() << endl;
	}
}

// searchVector function, taking in a vector of artists and a string name
Artist* searchVector(vector<Artist>& vArtist, const string& name) {
	for (size_t i = 0; i < vArtist.size(); i++) {
		// Iterates over the vector of artists, and checks if the name of the artist = the name passed in.
		// If it is, returns the Artist*
		if (vArtist[i].getName() == name) {
			Artist* temp = &vArtist[i];
			return temp;
		}
	}
}

int main() {
	string ifs1test;
	string ifs2test;

	cout << "What is the Artist filename?" << endl;
	cin >> ifs1test;

	cout << "What is the Painting filename?" << endl;
	cin >> ifs2test;

	// Checks to see if the first file opened successfully.
	ifstream ifs(ifs1test);
	if (ifs.is_open()) {
		cout << "Your file has successfully opened!" << endl;
	}
	else {
		cout << "There was an error in opening your file." << endl;
	}

	// Checks to see if the second file opened successfully
	ifstream ifs2(ifs2test);
	if (ifs2.is_open()) {
		cout << "Your file has successfully opened!" << endl;
	}
	else {
		cout << "There was an error in opening your file." << endl;
	}

	// ifs
	vector<Artist> vecArtists;
	string artistName;

	// Since file "A" is a file with artist names, gets artistName from ifs, and creates an artist with the name
	// Then pushes the artist back into the vector of Artists
	while (ifs >> artistName) {
		Artist a(artistName);
		vecArtists.push_back(a);
	}

	// ifs2
	string paintingArtist;
	string line;

	// Gets paintingArtist from ifs2, then gets the rest of the line after the artist and stores it in line.
	// Then calls the search vector function on the vector of artists, if his name matches with the paintingArtist passed in, 
	// calls the createPainting function, passing in the title of the painting as a string.
	while (ifs2 >> paintingArtist) {
		getline(ifs2, line);
		Artist* a = searchVector(vecArtists, paintingArtist);
		a->createPainting(line);
	}

	// Iterates over the vector of artists, and calls display function for each.
	for (size_t a = 0; a < vecArtists.size(); a++) {
		vecArtists[a].display();
	}

	// Deleting the vector of paintings within the artist just in case
	for (size_t i = 0; i < vecArtists.size(); i++) {
		vecArtists[i].destroy();
	}

	// clears the vector of artists.
	vecArtists.clear();

	// Closing the files used to test.
	ifs.close();
	ifs2.close();

	system("pause");
}