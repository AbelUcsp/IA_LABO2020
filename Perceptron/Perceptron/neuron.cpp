
#include "neuron.h"

Neuron::Neuron() {
	pattern = Pattern();
	pbayas = 0;
	iState = 0;
}

void Neuron::calculateState(double bayas, Pattern _pattern) {
	iState = pbayas * bayas;
	for (int i = 0; i < 5; i++) {
		iState += this->pattern.row1[i] * _pattern.row1[i];
		iState += this->pattern.row2[i] * _pattern.row2[i];
		iState += this->pattern.row3[i] * _pattern.row3[i];
		iState += this->pattern.row4[i] * _pattern.row4[i];
		iState += this->pattern.row5[i] * _pattern.row5[i];
		iState += this->pattern.row6[i] * _pattern.row6[i];
		iState += this->pattern.row7[i] * _pattern.row7[i];
	}
}

void Neuron::calculateNewWeights(double n, double bayas, Pattern _pattern, double wanted) {
	pbayas = pbayas + n * bayas * (wanted - iState);
	for (int i = 0; i < 5; i++) {		
		this->pattern.row1[i] = this->pattern.row1[i] + n * _pattern.row1[i] * (wanted - iState);
		this->pattern.row2[i] = this->pattern.row2[i] + n * _pattern.row2[i] * (wanted - iState);
		this->pattern.row3[i] = this->pattern.row3[i] + n * _pattern.row3[i] * (wanted - iState);
		this->pattern.row4[i] = this->pattern.row4[i] + n * _pattern.row4[i] * (wanted - iState);
		this->pattern.row5[i] = this->pattern.row5[i] + n * _pattern.row5[i] * (wanted - iState);
		this->pattern.row6[i] = this->pattern.row6[i] + n * _pattern.row6[i] * (wanted - iState);
		this->pattern.row7[i] = this->pattern.row7[i] + n * _pattern.row7[i] * (wanted - iState);
	}
}

double Neuron::funcionActivacion(double value) {
	if (value > 0)
		return 1;
	else
		return 0;
}

void Neuron::train(double n, double wanted, std::vector<Pattern> patterns) {
	//entrena con 1
	if (patterns.size() == 1) {
		bool pasa = false, pasa1 = false;
		while (!pasa) {
			if (!pasa1) {
				calculateState(patterns[0].bayas, patterns[0]);
				iState = funcionActivacion(this->iState);
				if (this->iState != wanted) {
					calculateNewWeights(n, patterns[0].bayas, patterns[0], wanted);
				}
				else {
					pasa1 = true;
				}
			}
			if (pasa1)
				pasa = true;
			else {
				pasa1 = false;
				pasa = false;
			}
		}
	}
	//entrena con 2
	else if (patterns.size() == 2) {
		bool pasa = false;
		bool pasa1 = false, pasa2 = false;
		while (!pasa) {
			if (!pasa1) {
				calculateState(patterns[0].bayas, patterns[0]);
				this->iState = funcionActivacion(this->iState);
				if (this->iState != wanted) {
					calculateNewWeights(n, patterns[0].bayas, patterns[0], wanted);
				}
				else {
					pasa1 = true;
				}
			}
			if (!pasa2) {
				calculateState(patterns[1].bayas, patterns[1]);
				this->iState = funcionActivacion(this->iState);
				if (this->iState != wanted) {
					calculateNewWeights(n, patterns[1].bayas, patterns[1], wanted);
				}
				else {
					pasa2 = true;
				}
			}
			if (pasa1 && pasa2) {
				pasa = true;
			}
			else {
				pasa1 = false;
				pasa2 = false;
				pasa = false;
			}
		}
	}
	//entrena con 3
	else if (patterns.size() == 3) {
		bool pasa = false;
		bool pasa1 = false, pasa2 = false, pasa3 = false;
		while (!pasa) {
			if (!pasa1) {
				calculateState(patterns[0].bayas, patterns[0]);
				this->iState = funcionActivacion(this->iState);
				if (this->iState != wanted) {
					calculateNewWeights(n, patterns[0].bayas, patterns[0], wanted);
				}
				else {
					pasa1 = true;
				}
			}
			if (!pasa2) {
				calculateState(patterns[1].bayas, patterns[1]);
				this->iState = funcionActivacion(this->iState);
				if (this->iState != wanted) {
					calculateNewWeights(n, patterns[1].bayas, patterns[1], wanted);
				}
				else {
					pasa2 = true;
				}
			}
			if (!pasa3) {
				calculateState(patterns[2].bayas, patterns[2]);
				this->iState = funcionActivacion(this->iState);
				if (this->iState != wanted) {
					calculateNewWeights(n, patterns[2].bayas, patterns[2], wanted);
				}
				else {
					pasa3 = true;
				}
			}
			if (pasa1 && pasa2 && pasa3) {
				pasa = true;
			}
			else {
				pasa1 = false;
				pasa2 = false;
				pasa3 = false;
				pasa = false;
			}
		}
	}
	//entrena con 4
	else if (patterns.size() == 4) {
		bool pasa = false;
		bool pasa1 = false, pasa2 = false, pasa3 = false, pasa4 = false;
		while (!pasa) {
			if (!pasa1) {
				calculateState(patterns[0].bayas, patterns[0]);
				this->iState = funcionActivacion(this->iState);
				if (this->iState != wanted) {
					calculateNewWeights(n, patterns[0].bayas, patterns[0], wanted);
				}
				else {
					pasa1 = true;
				}
			}
			if (!pasa2) {
				calculateState(patterns[1].bayas, patterns[1]);
				this->iState = funcionActivacion(this->iState);
				if (this->iState != wanted) {
					calculateNewWeights(n, patterns[1].bayas, patterns[1], wanted);
				}
				else {
					pasa2 = true;
				}
			}
			if (!pasa3) {
				calculateState(patterns[2].bayas, patterns[2]);
				this->iState = funcionActivacion(this->iState);
				if (this->iState != wanted) {
					calculateNewWeights(n, patterns[2].bayas, patterns[2], wanted);
				}
				else {
					pasa3 = true;
				}
			}
			if (!pasa4) {
				calculateState(patterns[3].bayas, patterns[3]);
				this->iState = funcionActivacion(this->iState);
				if (this->iState != wanted) {
					calculateNewWeights(n, patterns[3].bayas, patterns[3], wanted);
				}
				else {
					pasa4 = true;
				}
			}
			if (pasa1 && pasa2 && pasa3 && pasa4) {
				pasa = true;
			}
			else {
				pasa1 = false;
				pasa2 = false;
				pasa3 = false;
				pasa4 = false;
				pasa = false;
			}
		}
	}
}

double Neuron::test(Pattern _pattern) {
	double retorno = 0;
	for (int i = 0; i < 5; i++) {
		retorno += this->pattern.row1[i] * _pattern.row1[i];
		retorno += this->pattern.row2[i] * _pattern.row2[i];
		retorno += this->pattern.row3[i] * _pattern.row3[i];
		retorno += this->pattern.row4[i] * _pattern.row4[i];
		retorno += this->pattern.row5[i] * _pattern.row5[i];
		retorno += this->pattern.row6[i] * _pattern.row6[i];
		retorno += this->pattern.row7[i] * _pattern.row7[i];
	}
	return funcionActivacion(retorno);
}
