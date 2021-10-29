#include "../include/GameObj.h"

std::ostream& operator<<(std::ostream& stream, const GameObj& gameObj)
{
	gameObj.printInfo(stream);
	return stream;
}

GameObj::GameObj(std::string id)
: _ID(id) {}

Character::Character(HP hp, std::string name, std::string id)
: GameObj(id)
, _hp(hp)
, _name(name) {}

HP::HP(unsigned hp)
: _hp(hp) {}

void Character::printInfo(std::ostream& stream) const
{
	stream<<_name<<", ma: "<<hp();
}

Player::Player(HP hp, std::string name, std::string id)
: GameObj(id)
, Character(hp, name, id) {}

void Player::printInfo(std::ostream& stream) const
{
	stream<<"Player "<<static_cast<Character>(*this);
}


Hurting::Hurting(HP hurtHP, std::string id)
: GameObj(id)
, _hurtHP(hurtHP) {}

void Hurting::printInfo(std::ostream& stream) const
{
	stream<<"Jego uderzenie odbiera: "<<hp();
}

Bomb::Bomb(HP hurtHP, std::string id)
: GameObj(id)
, Hurting(hurtHP, id) {}

Boss::Boss(HP hp, std::string name, HP hurtingHP, std::string id)
: GameObj(id)
, Character(hp, name, id)
, Hurting(hurtingHP, id) {}

void Boss::printInfo(std::ostream& stream) const
{
	stream<<"Bad guy: "<<static_cast<Character>(*this)<<"\n";
	stream<<static_cast<Hurting>(*this);
}