// Genetyczny-final.cpp : Defines the entry point for the console application.
//
#pragma once
#include "stdafx.h"
#include"GeneticAlgorithm.h"
#include"ComputingTime.h"

int main()
{
	//ustalenie stalych
	ComputingTime computingTime;
	computingTime.start();
	Configuration::instance()->setParameters(MAXIMUM, 6, 1.0,26 , 100,100, 15, 70, 10, 10, CROSSOVER_SINGLE_POINT,
		MUTATION_SINGLE_POINT,ROULETTE_WHEEL_SELECTION,false, 50, 3, 1, 2, -1.0, 2.0, 0);

	//wybor optimum,dokladnosc, stala, ilosc bitow, poczatkowa populacja, ilosc iteracji,prawdopodobienstwo mutacji,
	//prawdopodobienstwo_krzyzowania,prawdopodobienstwo inwersji,% elitarnych,rodzaj krzyzowania,rodzaj mutacji, 
	//rodzaj selekcji,unikalnosc potomkow, ilosc najlepszych- tylko do selekcji najlepszych,
	//wielkosc turnieju,lewy przedzial, prawy przedzial
	GeneticAlgorithm alg;
	alg.geneticLoop();

	computingTime.stop();
	computingTime.calculateDifference();
	computingTime.displayDifference();
	system("pause");
	return 0;
}

