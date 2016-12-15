// 2016-11-24.cpp : definisce il punto di ingresso dell'applicazione console.


#include "MaddoLib.h"
#include <iostream>
using namespace std;
using namespace Maddo;

class Critter
{
public:
	int Hunger;
	Critter(int hunger = 0);
	void Greet();


};

Critter::Critter(int hunger)
{
	MaddoLib::OutputLine("Ayy lmao nuovo critter");
	Hunger = hunger;
}
void Critter::Greet()
{

	MaddoLib::OutputLine("Critter fame: " + MaddoLib::ToString(Hunger));

}



int main()
{

	Critter crit1(9);
	Critter crit2(19);

	crit1.Greet();

	crit2.Greet();

	MaddoLib::OutputLine("ayy" + MaddoLib::ToString(57));

	return 0;

	// puntatori
	// una variabile che contiene un indirizzo di memoria

	int* pAPointer; // declare a pointer
	int* pScore = 0; // declare and initialize a pointer
	int score = 1000;
	pScore = &score; // assign pointer pscore address of a variable score

	MaddoLib::OutputLine("Assigning &score to pScore");
	cout << "&score is: " << &score << "\n";
	cout << "pScore is: " << pScore << "\n";
	cout << "score is: " << score << "\n";
	cout << "*pScore is: " << *pScore << "\n";

	pScore += 10;
	cout << "pScore is: " << pScore << "\n";
	cout << "pScore is: " << *pScore << "\n";

	*pScore += 10;

	cout << "pScore is: " << *pScore << "\n";

	//cout << "size: " << (*pScore).size << "\n";

	int BONUS;

	const int* const pBONUS = &BONUS;

	int i;
	int* const p = &i; // puntatore constante, l'indirizzo non si modifica

	const int* p2; // puntatore a constante

	const int* const p3 = &i; // puntatore constante a constante

	// Il nome dell'arrai è un puntatore constante al primo elemento dell'array
	// poiché gli elementi di un array sono memorizzati in blocchi di memoria contigui è possibile utilizzare il nome per un accesso random agli elementi.


	MaddoLib::OutputLine("Ayy lmao");
	return 0;
}

