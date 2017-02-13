#pragma once
#include"stdafx.h"
#include"Individual.h"

class Population
{
public:
	//funkcja do utworzenia populacji
	void createPopulation();

	//funkcje wykonujace obliczenia na populacji
	void calculateRepresentation10();
	void scaleRepresentation10();
	void calculateFitness();
	void scaleFitness();
	void calculateProbability();
	void calculateForPopulation();

	//funkcje wyswietlace populacje
	void displayBinary();
	void displayRepresentation10();
	void displayScale10();
	void displayFitness();
	void displayProbability();

	vector<Individual>& getListOfIndividuals() { return listOfIndividuals; }

private:
	vector<Individual>listOfIndividuals;
};