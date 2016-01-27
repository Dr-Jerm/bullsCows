#include <iostream>
#include <string>
#include <map>
#include "main.h"

using namespace std;

// Entrypoint
int main() {
	// intro splash
	introduce();

	// Begin main game
	do {
		PlayGame();
	} while (AskToPlayAgain());
	
	return 0;
}

class BullsAndCowsGame {
public:
	string WORD;
	int GUESS_COUNT;
	int WORD_LENGTH;
};

void PlayGame() {
	string WORD = "foo";
	int GUESS_COUNT = WORD.length();
	for (int i = 0; i < GUESS_COUNT; i++) {
		string Guess = getGuess();
		printGuessFeedback(Guess);
	}
}

bool AskToPlayAgain() {
	// Get a guess from the user
	cout << "Play again? (y): ";
	string Response = "";
	getline(cin, Response, '\n');
	if (Response[0] == 'y' || Response[0] == 'Y') {
		return true;
	}
	return false;
}

void introduce() {
	constexpr int WORD_LENGTH = 5;

	// Introduce the Game
	cout << "Welcome to Bulls and Cows!\n";
	cout << "Can you think of the " << WORD_LENGTH << " letter isogram?\n";

	return;
}

string getGuess() {
	// Get a guess from the user
	cout << "Enter your guess: ";
	string Guess = "";
	getline(cin, Guess, '\n');

	int valid = validate(Guess);
	// Repeat the guess back to them

	if (!valid) {
		return getGuess();
	}
	return Guess;
}

void printGuessFeedback(string LastGuess){
	cout << "Your guess was: " << LastGuess << endl;
}

bool validate(string InputString) {

	if (InputString.length() == 0) {
		return false;
	}
	if (InputString.find(' ') != string::npos) {
		cout << "Please only enter a single word\n";
		return false;
	}

	map<char, bool> letterMap;
	for (int i = 0; i < InputString.length(); i++) {
		char letter = InputString.at(i);
		bool exists = letterMap.count(letter) > 0;
		if (exists) {
			cout << "Please only word with no repeated letters\n";
			return false;
		}
		else {
			letterMap[letter] = true;
		}
	}

	return true;
}
