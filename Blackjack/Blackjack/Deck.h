#pragma once
#include <vector>

class Deck
{ //Class for housing the 'deck of card' variables and functions
private:


public:
	Deck() = default;
	std::vector<int> CardsLeft;
	std::vector<int> CardsUsed;

	int SizeOfCardsLeft() const;

	void CreateDeck();
	int DrawCard();
	void RemoveCard(int i);
};

