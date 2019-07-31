#include "Deck.h"
#include "InOut.h"
#include "Player.h"

int main()
{
	// Request the number of players
	const auto numOfPlayers = InOut::InPlayerNum();

	//Create Player objects equal to the numOfPlayers
	std::vector<Player> player;
	player.reserve(numOfPlayers+1);
	for (auto i=1; i<=numOfPlayers+1;i++)
	{
		player.emplace_back();
	}

	//Request the Player names
	for (auto i=1;i<=numOfPlayers;i++)
	{ 
		player[i].SetName(InOut::InPlayerName(i));
	}

	//Set Player Scores to '0' as starting value
	for (auto i=1;i<=numOfPlayers;i++)
	{
		player[i].SetScore(0);
	}

	//Create the deck
	Deck deck;
	deck.CreateDeck();

	// PLAY THE GAME
	for (auto i=1;i<=numOfPlayers;i++)
	{
		const auto testInt = i;
		while (player[i].GetScore() <= 21 && testInt==i)
		{
			const auto playerContinue = InOut::InPlayerContinue(player[i].GetName());

			//The player has made the choice to draw a card.
			if (playerContinue == 1)
			{
				auto cardValue = deck.DrawCard();
				InOut::CardDrawing(player[i].GetName(), cardValue);
					//When an 'Ace' is drawn. Allow player to choose either '1' or '11'
					if(cardValue == 11)
					{
						cardValue = InOut::InPlayerAce();
						player[i].SetScore(cardValue);
						InOut::OutPlayerScore(player[i].GetScore());
					}
					//Any other card will be automatically added to the player score.
					else
					{
						player[i].SetScore(cardValue);
						InOut::OutPlayerScore(player[i].GetScore());
					}
			}
			//The player has made the choice to keep their current score.
			if(playerContinue == 2)
			{
				InOut::OutFinalScore(player[i].GetName(), player[i].GetScore());
				break;
			}
		}
		if (player[i].GetScore() > 21)
		{
			InOut::AnnounceBust(player[i].GetName());
		}
	}

	return 0;
}