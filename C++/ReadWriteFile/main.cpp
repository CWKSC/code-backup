#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string readFile(const string &filename) {
	ifstream file(filename);
	string result;
	file >> result;
	file.close();
	return result;
}

void writeFile(const string& filename, const string& content) {
	ofstream file(filename);
	file << content;
	file.close();
}

int main() {
	writeFile("file.txt", "Hello World!");
	cout << readFile("file.txt");
	return 0;
}
