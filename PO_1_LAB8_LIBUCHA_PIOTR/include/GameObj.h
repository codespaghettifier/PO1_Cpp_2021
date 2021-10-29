#pragma once

#include <string>
#include <sstream>

/*
Player
Character
Hurting
Bomb
Boss
GameObj
HP
*/

/*
Hierarchia klas - uzasadnienie:
	- GameObj jest klasą bazową dla wszystkich elementów gry
	- Character reprezentuje postacie, jest elementem gry, więc dziedziczy po GameObj
	- Hurting jest rodzajem elementów gry, więc dziedziczy po GameObj
	- Player jest postacią, więc dziedziczy po Character
	- Boss jest postacią, jak i zadaje obrażenia, więc dziedziczy po Hurting i Character
*/

/// Bazowa do wszystkiego
class GameObj
{
public:
	GameObj(std::string id);

	virtual void printInfo(std::ostream& stream) const = 0;
	inline std::string id() const;
	
	virtual ~GameObj() = default;
protected:
	std::string _ID;
};

std::ostream& operator<<(std::ostream& stream, const GameObj& gameObj);

inline std::string GameObj::id() const
{
	return _ID;
}

class HP
{
public:
	HP(unsigned hp);

	inline unsigned getHP() const;
	inline void setHP(unsigned hp);

private:
	unsigned _hp;
};

inline unsigned HP::getHP() const
{
	return _hp;
}

inline void HP::setHP(unsigned hp)
{
	_hp = hp;
}


class Character : public virtual GameObj
{
public:
	Character(HP hp, std::string name, std::string id);

	virtual void printInfo(std::ostream& stream) const override;
	inline std::string hp() const;

protected:
	HP _hp;
	std::string _name;
};

inline std::string Character::hp() const
{
	return "[" + std::to_string(_hp.getHP()) + " HP]";
}

class Hurting : public virtual GameObj
{
public:
	Hurting(HP hurtHP, std::string id);

	virtual void printInfo(std::ostream& stream) const override;
	inline std::string hp() const;

protected:
	HP _hurtHP;
};

inline std::string Hurting::hp() const
{
	return "[" + std::to_string(_hurtHP.getHP()) + " HP]";
}

class Player : public Character
{
public:
	Player(HP hp, std::string name, std::string id);

	virtual void printInfo(std::ostream& stream) const override;
};

class Bomb : public Hurting
{
public:
	Bomb(HP hurtHP, std::string id);
};

class Boss : public Character, public Hurting
{
public:
	Boss(HP hp, std::string name, HP hurtingHP, std::string id);

	virtual void printInfo(std::ostream& stream) const override;
};