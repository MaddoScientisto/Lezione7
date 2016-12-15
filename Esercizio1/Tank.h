#pragma once
#include <String>
#include "Enums.h"
class Tank
{
public:
	Tank::Tank(const std::string name);
	Tank::Tank(const int number);
	
	void OutputStatus() const;

	int DoMission(Mission mission);

	bool IsDead() const;

private:
	std::string	_name;
	int _health = 100;
	int _fuel = 100;
	int _ammo = 100;
	void Tank::OutputStat(std::string label, int value) const;
	int PatrolMission();
	int AttackMission();
	void RefuelMission();
	void AnnounceDeath();
};

