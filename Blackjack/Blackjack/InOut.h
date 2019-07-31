#pragma once
#include <vector>
#include <string>

class InOut
{ //Class for Input and Output functions
private:


public:
	InOut() = default;

	static int InPlayerNum();

	//Input&Output for the Player class
	static std::string InPlayerName(int i);
	static void OutPlayerName(const std::string& n);
	static void OutPlayerScore(int i);
	static void OutFinalScore(const std::string & playerName, int i);

	//Input&Output for Game Phases
	static void CardDrawing(const std::string& playerName, int cardValue);
	static void AnnounceBust(const std::string& playerName);
	static int InPlayerAce();
	static int InPlayerContinue(const std::string& playerName);

	// Logging Outputs
	static void CardsLeftLoop(const std::vector<int>& cardDeck);
};

