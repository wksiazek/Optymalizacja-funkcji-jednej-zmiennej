#pragma once
#include"stdafx.h"
#include"WriterToFile.h"

WriterToFile::WriterToFile()
{
	theBest.open("najlepsze.txt", ios::out);
	theWorst.open("najgorsze.txt", ios::out);
}

WriterToFile::~WriterToFile()
{
	theWorst.close();
	theBest.close();
}

//funkcje realizujace wybor najlepszego i najgorszego osobnika
Individual WriterToFile::theBestIndyvidual(Population &population)
{
	auto best = (max_element(population.getListOfIndividuals().begin(), population.getListOfIndividuals().end(), [](Individual &a, Individual &b) {return (a.getFitnessValue() < b.getFitnessValue()); }));
	if (Configuration::instance()->getOptimization() == MAXIMUM)
	{
		//cout << "Najlepszy chromosom to: " << najlepszy->getPrzeskalowana_wartosc() << "\tjego wartosc to:" << najlepszy->getWartosc_funkcji_celu() << endl;
		theBest << "x: " << best->getScaledRepresentation10() << " f(x): " << best->getFitnessValue() << endl;
	}
	else
	{
		//cout << "Najlepszy chromosom to: " << najlepszy->przeskalowana_wartosc << "\tjego wartosc to:" << -najlepszy->-wartosc_funkcji_celu << endl;
		theBest << "x: " << best->getScaledRepresentation10() << " f(x): " << -(best->getFitnessValue()) << endl;
	}
	return *best;

}

Individual WriterToFile::theWorstIndyvidual(Population &population)
{
	auto worst = (max_element(population.getListOfIndividuals().begin(), population.getListOfIndividuals().end(), [](Individual &a, Individual &b) {return (a.getFitnessValue() > b.getFitnessValue()); }));
	if (Configuration::instance()->getOptimization() == MAXIMUM)
	{
		theWorst << "x: " << worst->getScaledRepresentation10() << " f(x): " << worst->getFitnessValue() << endl;
	}
	else
	{
		theWorst << "x: " << worst->getScaledRepresentation10() << " f(x): " << -(worst->getFitnessValue()) << endl;
	}
	return *worst;
}
