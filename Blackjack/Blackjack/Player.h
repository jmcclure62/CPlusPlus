#pragma once
#include <string>

class Player
{ //Class to house player variables & functions for the game
private:
	std::string Name;
	int Score;

public:
	Player() = default;

	void SetName(const std::string& n);
	void SetScore(int i);
	std::string GetName() const;
	int GetScore() const;
};

