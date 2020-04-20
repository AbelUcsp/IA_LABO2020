#pragma once
#include <stack>
#include <utility>  
#include <windows.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
#include <fstream>
#include <string>
#include <vector>
#include <GL/glut.h>


using namespace std;

class punto {
	public:
		int x;
		int y;
		bool visitado;
		bool agregado;
		float costo;
		punto() { x = y = 0; visitado = agregado = false; }


		punto operator=(const punto &A) {
			x = A.x;
			y = A.y;
			return *this;
		}

		bool operator== (const punto &B) {
			if (this->x == B.x && this->y == B.y) {
				return true;
			}
			return false;
		}

};

class nodo {
public:
	int dato;
	int x;  //para openGL
	int y;  //para openGL
	nodo** child;
	nodo* tmp;

	nodo() {//para hijos
		dato = x = y = 66;
		child = new  nodo * [2];
		child[0] = nullptr;
		child[1] = nullptr;
	}

	nodo(int cantidad, int validar) {//para hijos
		dato = x = y = 99;
		child = new  nodo * [cantidad];
	}

	nodo(int cantidad) {//para root
		dato = x = y = 1;
		child = new nodo * [cantidad];
		for (std::size_t i = 0; i < cantidad; ++i) {///inicializamos 100 primeros nodos con valor i
			child[i] = new nodo();
			child[i]->setDATA(i);
			child[i]->setXY(0, i);
			if (i > 0) {
				child[i - 1]->child[0] = child[i];
			}
		}
		child[0]->child[1] = new nodo();
		child[0]->child[1]->setDATA(100);
		child[0]->child[1]->setXY(1, 0);
		child[97]->child[1] = new nodo();
		child[97]->child[1]->setDATA(197);
		child[97]->child[1]->setXY(1, 97);
		child[98]->child[1] = new nodo();
		child[98]->child[1]->setDATA(198);
		child[98]->child[1]->setXY(1, 98);
		child[99]->child[1] = new nodo();
		child[99]->child[1]->setDATA(199);
		child[99]->child[1]->setXY(1, 99);

		child[0]->child[1]->child[1] = new nodo();
		child[0]->child[1]->child[1]->setDATA(200);
		child[0]->child[1]->child[1]->setXY(2, 0);
		child[97]->child[1]->child[1] = new nodo();
		child[97]->child[1]->child[1]->setDATA(297);
		child[97]->child[1]->child[1]->setXY(2, 97);
		child[98]->child[1]->child[1] = new nodo();
		child[98]->child[1]->child[1]->setDATA(298);
		child[98]->child[1]->child[1]->setXY(2, 98);
		child[99]->child[1]->child[1] = new nodo();
		child[99]->child[1]->child[1]->setDATA(299);
		child[99]->child[1]->child[1]->setXY(2, 99);

		tmp = new nodo(100, 1);
		child[0]->child[1]->child[1]->child[1] = new nodo();
		child[0]->child[1]->child[1]->child[1]->setDATA(300);
		child[0]->child[1]->child[1]->child[1]->setXY(3, 0);

		//child[0]->child[1]->child[1]->child[1]->child[0] = new nodo();
		//child[0]->child[1]->child[1]->child[1]->child[0]->setDATA(400);
		//child[0]->child[1]->child[1]->child[1]->child[0]->setXY(4,0);

		//tmp->child[0] = child[0]->child[1]->child[1]->child[1]->child[0];
		//nodo *lateral = child[0]->child[1]->child[1]->child[1]->child[0];

		tmp->child[0] = child[0]->child[1]->child[1]->child[1];
		nodo* lateral = child[0]->child[1]->child[1]->child[1];
		nodo* copia = lateral;
		//lateral = new nodo();
		//lateral->setDATA(300+1);
		//lateral->setXY(3,1);


		for (std::size_t i = 1; i < cantidad; ++i) {
			//child[0]->child[1]->child[1]->child[1]->child[0] = new nodo();
			//nodo *lateral = child[0]->child[1]->child[1]->child[1]->child[0];
			lateral = new nodo();
			lateral->setDATA(300 + i);
			lateral->setXY(3, i);


			copia->child[0] = lateral;
			copia = lateral;


			//tmp->child[i-1] = lateral;
			///tmp->child[0] = lateral;
			tmp->child[i] = lateral;
			lateral = tmp->child[i];
		}

		//child[0]->child[1]->child[1]->child[1]
		child[97]->child[1]->child[1]->child[1] = tmp->child[97];

		child[98]->child[1]->child[1]->child[1] = tmp->child[98];

		child[99]->child[1]->child[1]->child[1] = tmp->child[99];

	}

	//nodo* tmp = tmp2->add100(A.root, 100, 100, 1);
	nodo* add100(nodo*& root, std::size_t cant, unsigned int valor, int x) {
		nodo* return_;
		return_ = new nodo(cant, 1);

		for (std::size_t i = 0; i < cant; ++i) {///inicializamos 100 nodos con valor
			root->child[i]->child[1] = new nodo();
			root->child[i]->child[1]->setDATA(i + valor);
			root->child[i]->child[1]->setXY(x, i);

			if (i > 0) {
				root->child[i - 1]->child[1]->child[0] = root->child[i]->child[1];
			}
			return_->child[i] = root->child[i]->child[1];
			//cout << "FOR " << return_->child[0]->x << " " << return_->child[0]->y << endl;
		}
		return return_;
	}

	/**
	void eliminar(nodo* current, nodo*& root) {///ANCHURA/AMPLITUD
		///cout << "elimnar " <<current->dato <<endl;
		//cout << root->child[1]->dato;
		for (std::size_t i = 2; i < 20; ++i) {
			root->child[i]->child[1] = nullptr;
		}
		root->child[1]->child[0] = nullptr;
	
	}*/

	void setXY(int x, int y) {
		this->x = x;
		this->y = y;
	}
	void setDATA(int data) {
		this->dato = data;
	}
};


class grafoIA {
public:
	nodo* root;
	int camino[200];
	int caminoX[200];
	int caminoY[200];
	int tamanho;

	struct struc_comparar {
		bool operator()(punto *&P, punto *&Q) {
			return P->costo > Q->costo;
		}
	};

	priority_queue<punto *, vector<punto* >, struc_comparar > menor;

	vector<punto *> Path;
	

		//int puntoB[144];
	grafoIA(int cantidad) {
		root = new nodo(cantidad);
		root->setDATA(-1);
		tamanho = 0;

	}


	void ANCHURA(nodo* destino,  nodo*& root) {///ANCHURA/AMPLITUD
		queue<nodo*> cola;
		
		int indice = 0;
		for (std::size_t i = 0; i < 100; ++i) {
			cola.push(root->child[i]);
		}
		while (!cola.empty()) {
			if (cola.front()) {
				cout << cola.front()->dato << " ";
				caminoX[indice] = cola.front()->x;
				caminoY[indice] = cola.front()->y;
				indice++;
		
				cola.push(cola.front()->child[1]);
			}
			cola.pop();
		}
	}



	float euclides(punto P, punto N) {
		return sqrt(pow(abs(N.x - P.x), 2) + pow(abs(N.y - P.y), 2));
	}

	///euclidean

	bool A_asterisco(punto &P, punto &N, nodo *root) {
		float G;
		float H;
		int indice = 0;
		punto *visitado;
		menor.push(&P);
		while (!menor.empty()) {
			camino[indice] = visitado->x;
			camino[indice] = visitado->y;
			indice++;
			visitado = menor.top();
			visitado->visitado = true;
			menor = priority_queue<punto*, vector<punto* >, struc_comparar>();
			if (*visitado == N) {
				return true;
			}
			
			else {
				for (unsigned int i = 0; i < 100; i++) {
					if (root->child[i]->child[1] == false) {
						G = euclides(P, N);
						punto A;
						A.x = root->child[i]->child[1]->x;
						A.x = root->child[i]->child[1]->y;
						H = euclides(A, N);
						root->child[i]->child[1] = root->child[i]->child[1]->child[1];
						visitado->visitado = G + H;
						menor.push(visitado);
					}
				}
			}

			
		}
		return false;
	}


};

