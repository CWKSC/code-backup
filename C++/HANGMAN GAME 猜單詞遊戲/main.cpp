#include <iostream>
#include <string>

using namespace std;

int main() {
	string correctAns = "water";
	size_t ansLength = correctAns.length();
	string repeatCheck = "";
	string display = " ";
	for (size_t i = 0; i < ansLength; i++) {
		display += "_  ";
	}
	string input;
	int getCorrectCount = 0;
	int getWrongCount = 0;

	cout << "\n                ☯️ HANGMAN GAME ☯️ \n" << endl;

	cout << "Let Guess the word↓↓\n" << display << 
		"\nInput one letter only\nYour Answer: " << endl;

	while (getCorrectCount != ansLength && getWrongCount != 5) {
		cin >> input;
		if (input.length() > 1) {
			cout << "Please input only one letter!!" << endl;
			continue;
		}
		char word = input[0];
		size_t index = correctAns.find(word);
		if (index != std::string::npos) {
			if (repeatCheck.find(word) != std::string::npos) {
				cout << "Please don't repeat answer, try to guess other letter" << endl;
				continue;
			}
			repeatCheck += word;
			display[1 + index * 3] = word;
			getCorrectCount++;
			cout << "YES, you got the " << index + 1 << "th letter!!" << endl;
			cout << display << endl;
			continue;
		}
		cout << "sorry, you got the wrong letter!!" << endl;
		cout << "Your Chance: " << ++getWrongCount << "/5 \n \t " << endl;
	}

	if (getCorrectCount == ansLength) {
		cout << "You Win" << endl;
		return 0;
	}
	cout << "You Lose \nThe correct answer is 【 " << correctAns << " 】" << endl;

	return 0;
}
