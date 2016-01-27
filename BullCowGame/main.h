#pragma once
#include <string>

using namespace std;

void introduce();
bool AskToPlayAgain();
string getGuess();
void printGuessFeedback(string LastGuess);
bool validate(string InputString);
void PlayGame();
