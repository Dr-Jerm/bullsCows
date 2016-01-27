#include <iostream>
#include <string>
#include "main.h"

using namespace std;

void introduce();
void getGuessAndPrint();
bool validate(string InputString);

// Entrypoint
int main() {



	// intro splash
	introduce();

	// Begin main game

	PlayGame();
	

	return 0;
}

void PlayGame()
{
	string WORD = "foo";
	int GUESS_COUNT = WORD.length();
	for (int i = 0; i < GUESS_COUNT; i++) {
		getGuessAndPrint();
	}
}

void introduce() {
	constexpr int WORD_LENGTH = 5;

	// Introduce the Game
	cout << "Welcome to Bulls and Cows!\n";
	cout << "Can you think of the " << WORD_LENGTH << " letter isogram?\n";

	return;
}

void getGuessAndPrint() {
	// Get a guess from the user
	cout << "Enter your guess: ";
	string Guess = "";
	getline(cin, Guess, '\n');

	int valid = validate(Guess);
	// Repeat the guess back to them

	if (valid) {
		cout << "Your guess was: " << Guess << endl;
	}
	else {
		getGuessAndPrint();
	}
	return;
}

bool validate(string InputString) {

	if (InputString.length() == 0) {
		return false;
	}

	if (InputString.find(' ') != string::npos) {
		cout << "Please only enter a single word\n";
		return false;
	}

	return true;
}
