// Esercizio1.cpp : Defines the entry point for the console application.

#include "Esercizio1.h"

#include "MaddoLib.h"
#include <vector>
#include "Tank.h"
#include <time.h>
#include "enums.h"
using namespace std;
using namespace Maddo;



int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	while (true)
	{
		MaddoLib::ClearScreen();
		Game();
		if (MaddoLib::AskYesNo("Uscire dal gioco?"))
		{
			break;
		}
	}
	return 0;
}

void Game()
{
	vector<Tank> tanks;
	Mission m;
	int valor = 0;

	InitVector(&tanks, 3);
	MaddoLib::ClearScreen();
	MaddoLib::OutputLine("Benvenuto, il tuo obbiettivo � comandare questi carri armati attraverso una serie di missioni.\nLa tua abilit� sar� valutata tramite un punteggio di \"valore\".\nRiuscirai ad essere promosso generale?\nRaggiungi un livello di valore pari o superiore a 100.");
	MaddoLib::Pause();
	while (true)
	{
		MaddoLib::ClearScreen();
		OutputTanks(&tanks);
		MaddoLib::OutputLine("Valore: " + MaddoLib::ToString(valor));
		m = SelectMission();
		MaddoLib::OutputLine("Missione in corso...");
		DoMission(&tanks, m, &valor);
		MaddoLib::Pause();
		if (!IsAnyTankAlive(&tanks))
		{
			// game over man, game over
			break;
		}
		MaddoLib::OutputLine("Valore: " + MaddoLib::ToString(valor));
		MaddoLib::Pause();


		if (valor >= 100)
		{
			MaddoLib::OutputLine("Complimenti, sei stato promosso a generale.\nGAME OVER");
			return;
		}

		if (valor < 0)
		{
			valor = 0;
		}
	}

	MaddoLib::OutputLine("Game over. Valore finale: " + MaddoLib::ToString(valor));

}

void InitVector(vector<Tank>* const tanksVector, int amount)
{
	tanksVector->clear();
	//Tank t1;

	for (int i = 0; i < amount; i++)
	{
		tanksVector->push_back(Tank(i + 1));
	}
}

void OutputTanks(const std::vector<Tank>* const tanksVector)
{
	int i = 1;
	for (auto const &tank : *tanksVector)
	{
		if (!tank.IsDead())
			tank.OutputStatus();
	}
}

Mission SelectMission()
{
	int m;
	MaddoLib::OutputLine("[1] Pattugliamento");
	MaddoLib::OutputLine("[2] Attacco postazione nemica");
	MaddoLib::OutputLine("[3]  Rifornimento e riparazione ");
	MaddoLib::OutputLine("[4] Engine Upgrade (10 valor)");
	MaddoLib::OutputLine("[5] Armor Upgrade (20 valor)");
	MaddoLib::OutputLine("[6] Shell Upgrade (30 valor)");
	m = MaddoLib::InputInt("Selezionare la missione: ", "Valore non corretto", 1, 6);
	return static_cast<Mission>(m - 1);
}

void DoMission(std::vector<Tank>* const tanksVector, const Mission mission, int* valor)
{

	//controllare qui se il valore � sufficiente
	

	for (auto & tank : *tanksVector)
	{
		if (!tank.IsDead())
		{
			*valor += tank.DoMission(mission);
		}
	}
	
	
}

bool IsAnyTankAlive(const std::vector<Tank>* const tanksVector)
{
	for (auto tank : *tanksVector)
	{
		if (!tank.IsDead())
		{
			return true;
		}
	}
	return false;
}

