#include "Player.h"

void Player::SetName(const std::string& n)
{
	Name = n;
}
 void Player::SetScore(const int i)
 {
	 if (Score != 0) { Score = Score + i; }
	 else { Score = i; }
 }

 std::string Player::GetName() const
 {
	 return Name;
 }

 int Player::GetScore() const
 {
	 return Score;
 }
