#include "InOut.h"
#include <iostream>

void InOut::CardsLeftLoop(const std::vector<int>& cardDeck)
{
	//For Testing:  Loops through the current deck
	for (auto i : cardDeck)
	{
		std::cout << "i = " << i << std::endl;
	}
}

// INPUT & OUTPUT RELATING TO THE PLAYER CLASS

int InOut::InPlayerNum()
{
	int numOfPlayers;
	std::cout << "How many people will be playing?" << std::endl;
	std::cin >> numOfPlayers;
	return numOfPlayers;
}

std::string InOut::InPlayerName(int i)
{
	//Requests user input for the Player Name value
	std::string playerName;
	std::cout << "What is Player " << i << "\'s name?" << std::endl;
	std::cin >> playerName;
	return playerName;
}

void InOut::OutPlayerName(const std::string& n)
{
	//Outputs the previously received Player Name value
	std::cout << "Player Name:  " << n << std::endl;
}

void InOut::OutPlayerScore(const int i)
{
	//Takes a value and outputs it as the Player Score
	std::cout << "This player's score is:  " << i << std::endl;
}

void InOut::OutFinalScore(const std::string& playerName, const int i)
{
	//Takes a value and outputs it as the Player Score
	std::cout << "~~~~~ " << playerName << "'s Final Score is:  " << i << ". ~~~~~" << std::endl;
}

// INPUT & OUTPUT FOR THE GAME PHASES

void InOut::CardDrawing(const std::string& playerName, const int cardValue)
{
	std::cout << playerName << " is drawing a card..." << std::endl;
	std::cout << "The card drawn is a(n):  " << cardValue << std::endl;
}

void InOut::AnnounceBust(const std::string& playerName)
{
	std::cout << "BUSTED!  Sorry " << playerName << "! Your score is over 21!" << std::endl;
}

int InOut::InPlayerAce()
{
	auto choice = 0;

	do {
		std::cout << "You have drawn an Ace card. This card can have a score of either '1' or '11'. Please choose the value that you want." << '\n';
		std::cout << "Type either '1' or '11' to make your selection!" << std::endl;
		std::cin >> choice;
	} while (choice != 1 && choice != 11);

	return choice;
}

int InOut::InPlayerContinue(const std::string& playerName)
{
	auto choice = 0;

	do
	{
		std::cout << '\n';
		std::cout << "###### PLAYER:  " << playerName << " #####" << '\n';
		std::cout << "Please select one of the following actions: " << '\n';
		std::cout << "(1) Draw Card" << '\n';
		std::cout << "(2) Stay at Current Score" << std::endl;
		std::cin >> choice;
		std::cout << std::endl;
	} while (choice != 1 && choice != 2);

	return choice;
}
