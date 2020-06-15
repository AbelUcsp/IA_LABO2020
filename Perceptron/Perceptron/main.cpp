
#include <iostream>
#include <vector>

#include "neuron.h"

int main() {

	Neuron neuron0;
	Neuron neuron1;
	Neuron neuron2;

	//pattern 1
	double p11[5] = { 0,0,1,0,0 };
	double p12[5] = { 0,1,1,0,0 };
	double p13[5] = { 1,0,1,0,0 };
	double p14[5] = { 0,0,1,0,0 };
	double p15[5] = { 0,0,1,0,0 };
	double p16[5] = { 0,0,1,0,0 };
	double p17[5] = { 1,1,1,1,1 };
	//pattern 2
	double p21[5] = { 0,0,1,0,0 };
	double p22[5] = { 0,1,1,0,0 };
	double p23[5] = { 1,0,1,0,0 };
	double p24[5] = { 0,0,1,0,0 };
	double p25[5] = { 0,0,1,0,0 };
	double p26[5] = { 0,0,1,0,0 };
	double p27[5] = { 0,0,1,0,0 };
	//pattern 3
	double p31[5] = { 0,0,1,0,0 };
	double p32[5] = { 0,0,1,0,0 };
	double p33[5] = { 0,0,1,0,0 };
	double p34[5] = { 0,0,1,0,0 };
	double p35[5] = { 0,0,1,0,0 };
	double p36[5] = { 0,0,1,0,0 };
	double p37[5] = { 0,0,1,0,0 };
	//pattern 4
	double p41[5] = { 0,0,0,0,1 };
	double p42[5] = { 0,0,0,0,1 };
	double p43[5] = { 0,0,0,0,1 };
	double p44[5] = { 0,0,0,0,1 };
	double p45[5] = { 0,0,0,0,1 };
	double p46[5] = { 0,0,0,0,1 };
	double p47[5] = { 0,0,0,0,1 };
	//pattern 5
	double p51[5] = { 1,1,1,1,1 };
	double p52[5] = { 1,0,0,0,1 };
	double p53[5] = { 1,0,0,0,1 };
	double p54[5] = { 1,0,0,0,1 };
	double p55[5] = { 1,0,0,0,1 };
	double p56[5] = { 1,0,0,0,1 };
	double p57[5] = { 1,1,1,1,1 };
	//pattern 6
	double p61[5] = { 0,1,1,1,0 };
	double p62[5] = { 1,0,0,0,1 };
	double p63[5] = { 1,0,0,0,1 };
	double p64[5] = { 1,0,0,0,1 };
	double p65[5] = { 1,0,0,0,1 };
	double p66[5] = { 1,0,0,0,1 };
	double p67[5] = { 0,1,1,1,0 };
	//pattern 7
	double p71[5] = { 0,0,0,0,0 };
	double p72[5] = { 0,1,1,1,0 };
	double p73[5] = { 0,1,0,1,0 };
	double p74[5] = { 0,1,0,1,0 };
	double p75[5] = { 0,1,0,1,0 };
	double p76[5] = { 0,1,1,1,0 };
	double p77[5] = { 0,0,0,0,0 };
	//pattern 8
	double p81[5] = { 0,1,1,1,0 };
	double p82[5] = { 0,1,0,1,0 };
	double p83[5] = { 0,1,0,1,0 };
	double p84[5] = { 0,1,0,1,0 };
	double p85[5] = { 0,1,0,1,0 };
	double p86[5] = { 0,1,0,1,0 };
	double p87[5] = { 0,1,1,1,0 };
	//pattern 9
	double p91[5] = { 0,0,1,0,0 };
	double p92[5] = { 0,1,0,1,0 };
	double p93[5] = { 1,0,0,0,1 };
	double p94[5] = { 0,0,0,1,0 };
	double p95[5] = { 0,0,1,0,0 };
	double p96[5] = { 0,1,0,0,0 };
	double p97[5] = { 1,1,1,1,1 };
	//pattern 10
	double p101[5] = { 0,0,0,0,0 };
	double p102[5] = { 0,1,1,1,0 };
	double p103[5] = { 1,0,0,0,1 };
	double p104[5] = { 0,0,0,1,0 };
	double p105[5] = { 0,0,1,0,0 };
	double p106[5] = { 0,1,0,0,0 };
	double p107[5] = { 1,1,1,1,1 };
	//pattern 11
	double p111[5] = { 0,0,1,0,0 };
	double p112[5] = { 0,1,0,1,0 };
	double p113[5] = { 0,0,0,1,0 };
	double p114[5] = { 0,0,1,0,0 };
	double p115[5] = { 0,1,0,0,0 };
	double p116[5] = { 0,1,1,1,0 };
	double p117[5] = { 0,0,0,0,0 };
	//pattern 12
	double p121[5] = { 0,0,1,1,0 };
	double p122[5] = { 0,1,0,0,1 };
	double p123[5] = { 0,0,0,1,0 };
	double p124[5] = { 0,0,1,0,0 };
	double p125[5] = { 0,1,1,1,1 };
	double p126[5] = { 0,0,0,0,0 };
	double p127[5] = { 0,0,0,0,0 };
	
	Pattern m_1p(p11, p12, p13, p14, p15, p16, p17);
	std::vector<Pattern> m_patrones_aprendidos1;
	std::vector<Pattern> m_patrones_aprendidos2;
	std::vector<Pattern> m_patrones_aprendidos3;
	m_patrones_aprendidos1.push_back(m_1p);

	neuron1.train(0.02, 1, m_patrones_aprendidos1);

	Pattern m_2p(p21, p22, p23, p24, p25, p26, p27);
	m_patrones_aprendidos1.push_back(m_2p);
	neuron1.train(0.02, 1, m_patrones_aprendidos1);

	Pattern m_3p(p31, p32, p33, p34, p35, p36, p37);
	m_patrones_aprendidos1.push_back(m_3p);
	neuron1.train(0.02, 1, m_patrones_aprendidos1);

	Pattern m_4p(p41, p42, p43, p44, p45, p46, p47);
	m_patrones_aprendidos1.push_back(m_4p);
	neuron1.train(0.02, 1, m_patrones_aprendidos1);

	Pattern m_5p(p51, p52, p53, p54, p55, p56, p57);
	m_patrones_aprendidos2.push_back(m_5p);
	neuron0.train(0.02, 1, m_patrones_aprendidos2);

	Pattern m_6p(p61, p62, p63, p64, p65, p66, p67);
	m_patrones_aprendidos2.push_back(m_6p);
	neuron0.train(0.02, 1, m_patrones_aprendidos2);

	Pattern m_7p(p71, p72, p73, p74, p75, p76, p77);
	m_patrones_aprendidos2.push_back(m_7p);
	neuron0.train(0.02, 1, m_patrones_aprendidos2);

	Pattern m_8p(p81, p82, p83, p84, p85, p86, p87);
	m_patrones_aprendidos2.push_back(m_8p);
	neuron0.train(0.02, 1, m_patrones_aprendidos2);

	Pattern m_9p(p91, p92, p93, p94, p95, p96, p97);
	m_patrones_aprendidos3.push_back(m_9p);
	neuron2.train(0.02, 1, m_patrones_aprendidos3);

	Pattern m_10p(p101, p102, p103, p104, p105, p106, p107);
	m_patrones_aprendidos3.push_back(m_10p);
	neuron2.train(0.02, 1, m_patrones_aprendidos3);

	Pattern m_11p(p111, p112, p113, p114, p115, p116, p117);
	m_patrones_aprendidos3.push_back(m_11p);
	neuron2.train(0.02, 1, m_patrones_aprendidos3);

	Pattern m_12p(p121, p122, p123, p124, p125, p126, p127);
	m_patrones_aprendidos3.push_back(m_12p);
	neuron2.train(0.02, 1, m_patrones_aprendidos3);

	std::cout << "-------------------------" << std::endl;
	std::cout << "Test ceros -> 0" << std::endl;
	std::cout << "Test unos -> 1" << std::endl;
	std::cout << "Test dos -> 2" << std::endl;
	std::cout << "-------------------------" << std::endl;
	int option;
	std::cin >> option;

	std::cout << "Ingrese el patron: " << std::endl;
	Pattern m_patron;
	m_patron.update();
	std::cout << std::endl;
	m_patron.print();
	std::cout << "-------------------------" << std::endl;

	if (option == 0) {

		if (neuron0.test(m_patron)) {
			std::cout << "Es un 0" << std::endl;
		}
		else {
			std::cout << "No es un 0" << std::endl;
		}
	}
	else if (option == 1) {

		if (neuron1.test(m_patron)) {
			std::cout << "Es un 1" << std::endl;
		}
		else {
			std::cout << "No es un 1" << std::endl;
		}
	}
	else if (option == 2) {

		if (neuron2.test(m_patron)) {
			std::cout << "Es un 2" << std::endl;
		}
		else {
			std::cout << "No es un 2" << std::endl;
		}
	}
	else {
		std::cout << "No aprendido" << std::endl;
	}

	return 0;
}

