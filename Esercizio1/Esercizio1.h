#pragma once
#include "Tank.h"
#include <vector>
#include "enums.h"
int main();

void Game();
void InitVector(std::vector<Tank>* const tanksVector, int amount);
void OutputTanks(const std::vector<Tank>* const tanksVector);
Mission SelectMission();
void DoMission(std::vector<Tank>* const tanksVector, const Mission mission, int* valor);
bool IsAnyTankAlive(const std::vector<Tank>* const tanksVector);