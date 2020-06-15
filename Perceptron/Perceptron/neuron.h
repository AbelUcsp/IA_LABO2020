#pragma once

#include <vector>

#include "pattern.h"

class Neuron
{
public:
	Pattern pattern;
	double pbayas;
	double iState;

	Neuron();
	void calculateState(double bayas, Pattern _pattern);
	void calculateNewWeights(double n, double bayas, Pattern _pattern, double wanted);
	double funcionActivacion(double value);
	void train(double n, double wanted, std::vector<Pattern> patterns);
	double test(Pattern _pattern);
};

