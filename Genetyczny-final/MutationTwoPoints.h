#pragma once
#include"stdafx.h"
#include"Mutation.h"

class MutationTwoPoints :public Mutation
{
public:
	MutationTwoPoints() :Mutation() {}
	void mutate(Population &population);
	void randomingMutationPoints(set<int>& mutationPoints);
};