#include "Tank.h"
#include <MaddoLib.h>
using namespace std;
using namespace Maddo;

Tank::Tank(const string name)
{
	_name = name;
}
Tank::Tank(const int number)
{
	_name = "Tank " + MaddoLib::ToString(number);
}

void Tank::OutputStatus() const
{
	MaddoLib::OutputLine("Tank: " + _name);
	OutputStat("Ammo: ", _ammo);
	OutputStat("Fuel: ", _fuel);
	OutputStat("Health: ", _health);
	OutputUpgrades();
	MaddoLib::OutputLine();
}

int Tank::DoMission(Mission mission)
{
	int v = 0;
	if (mission == Mission::Attack)
	{
		v = AttackMission();
	}
	else if (mission == Mission::Patrol)
	{
		v = PatrolMission();

	}
	else if (mission == Mission::Refuel)
	{
		RefuelMission();
		v = -1;
	}
	else if (mission == Mission::ArmorUpgrade)
	{
		
	}

	
	if (v == 0)
	{
		AnnounceDeath();
		return 0;
	}

	return v;
}

bool Tank::IsDead() const
{
	return (_health <= 0 || _ammo <= 0 || _fuel <= 0);
}

void Tank::OutputStat(string label, int value) const
{
	MaddoLib::OutputLine(label + MaddoLib::ToString(value));
}


/**
 * \brief Esegue la missione di patrol
 * \return il valore della missione
 */
int Tank::PatrolMission()
{
	int r = MaddoLib::GetRandomInt(2, 4);
	_health -= r * 2;
	_fuel -= r * 8;
	_ammo -= r * 2;

	return IsDead() ? 0 : 1;
}

int Tank::AttackMission()
{
	int r = MaddoLib::GetRandomInt(2, 4);
	_health -= r * 7;
	_fuel -= r * 3;
	_ammo -= r * 7;

	return IsDead() ? 0 : 2;
}

void Tank::RefuelMission()
{
	int r = MaddoLib::GetRandomInt(2, 4);
	_health += r * 5;
	_fuel += r * 5;
	_ammo += r * 5;
	if (_health > 100) _health = 100;
	if (_fuel > 100) _fuel = 100;
	if (_ammo > 100) _ammo = 100;
}

void Tank::AnnounceDeath() const
{
	MaddoLib::OutputLine("Rip carro " + _name);
}

void Tank::OutputUpgrades() const
{
	MaddoLib::Output("Upgrades: ");
	if (_hasArmorUpgrade) MaddoLib::Output("A");
	if (_hasEngineUpgrade) MaddoLib::OutputLine("E");
	if (_hasShellUpgrade) MaddoLib::OutputLine("S");
	MaddoLib::OutputLine();
}
