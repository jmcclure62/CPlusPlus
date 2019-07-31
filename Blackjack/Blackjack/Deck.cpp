#include "Deck.h"
#include <ctime>

void Deck::CreateDeck()
{
	//Create the deck of cards by expanding the CardsLeft array by 52
	for (auto n=0; n<= 52; n = n+1)
	{
		if (n >= 0 && n <= 4) { CardsLeft.push_back(2); }; //Assign the Cards of Twos
		if (n > 4 && n <= 8) { CardsLeft.push_back(3); }; //Assign the Cards of Threes
		if (n > 8 && n <= 12) { CardsLeft.push_back(4); }; //Assign the Cards of Fours
		if (n > 12 && n <= 16) { CardsLeft.push_back(5); }; // Assign the Cards of Fives
		if (n > 16 && n <= 20) { CardsLeft.push_back(6); }; //Assign the Cards of Sixes
		if (n > 20 && n <= 24) { CardsLeft.push_back(7); }; //Assign the Cards of Sevens
		if (n > 24 && n <= 28) { CardsLeft.push_back(8); }; //Assign the Cards of Eights
		if (n > 28 && n <= 32) { CardsLeft.push_back(9); }; //Assign the Cards of Nines
		if (n > 32 && n <= 36) { CardsLeft.push_back(10); }; //Assign the Cards of 10s
		if (n > 36 && n <= 40) { CardsLeft.push_back(10); }; //Assign the Cards of Jacks
		if (n > 40 && n <= 44) { CardsLeft.push_back(10); }; //Assign the Queens
		if (n > 44 && n <= 48) { CardsLeft.push_back(10); }; //Assign the Kings
		if (n > 48 && n <= 52) { CardsLeft.push_back(11); }; //Assign the Aces
	}
	//Remove the initial '0' index of the array
	CardsLeft.erase(CardsLeft.begin());
}

int Deck::DrawCard()
{
	// Create a variable 'r' with a time-based randomized number 
	srand(time(nullptr));

	//Random number within the range of the vector size
	const auto r = (rand() % CardsLeft.size()) + 1;
	const auto cardDrawn = CardsLeft.at(r);

	//Call upon the 'Remove Card' function
	RemoveCard(r);

	return cardDrawn;
}

void Deck::RemoveCard(int i)
{
	// Function to remove the requested 'card' (index) from the 'deck' (array)
	CardsLeft.erase(CardsLeft.begin() + i);
}

int Deck::SizeOfCardsLeft() const
{
	return CardsLeft.size();
}
