#include "Player.h"

Player::Player()
{
	elementCharacter = "A";
	pokemonsCaptured, pokeBallsCaptured = 0;
	myPosition = new Vector2D(5, 5);
}
std::set<Vector2D*> Player::CloseArea()
{
	myRadius.clear();

	//PLAYER POS
	myRadius.insert(new Vector2D(myPosition->_x, myPosition->_y));

	//DRETA ESQUERRA ADALT ABAIX
	myRadius.insert(new Vector2D(myPosition->_x + 1, myPosition->_y));
	myRadius.insert(new Vector2D(myPosition->_x - 1, myPosition->_y));
	myRadius.insert(new Vector2D(myPosition->_x, myPosition->_y + 1));
	myRadius.insert(new Vector2D(myPosition->_x, myPosition->_y - 1));

	//DIAGONALS
	myRadius.insert(new Vector2D(myPosition->_x + 1, myPosition->_y + 1));
	myRadius.insert(new Vector2D(myPosition->_x - 1, myPosition->_y + 1));
	myRadius.insert(new Vector2D(myPosition->_x - 1, myPosition->_y - 1));
	myRadius.insert(new Vector2D(myPosition->_x + 1, myPosition->_y - 1));

	return myRadius;
}

void Player::OnPlayerCollision(Player* myPlayer, Vector2D* movement)
{
	return;
}
