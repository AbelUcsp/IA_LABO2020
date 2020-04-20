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

	void eliminar(nodo* current, nodo*& root) {///ANCHURA/AMPLITUD
		///cout << "elimnar " <<current->dato <<endl;
		//cout << root->child[1]->dato;
		for (std::size_t i = 2; i < 20; ++i) {
			root->child[i]->child[1] = nullptr;



		}
		root->child[1]->child[0] = nullptr;
		/*
			queue<nodo *> cola;
			for (std::size_t i = 0; i < 100; ++i){
				cola.push(root->child[i]);
			}
			while(!cola.empty()){
				if(cola.front()){
					if(current->dato == cola.front()->dato){

					   // for (std::size_t i = 0; i < 20; ++i){
							//if( current != nullptr  ){
								//cout << "si "<<cola.front()->dato << " ";
								current->child[0] = nullptr;
								current->child[1] = nullptr;
							//}
						   // break;
					   // }

					}

					cola.push(cola.front()->child[1]);
					//cola.push(cola.front()->nodes[1]);
				}
				cola.pop();
			}
			*/

			//stack<nodo* >
	}

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

	grafoIA(int cantidad) {
		root = new nodo(cantidad);
		root->setDATA(-1);

	}

	void ANCHURA(nodo* current, nodo*& root) {///ANCHURA/AMPLITUD
		///cout << "elimnar " <<current->dato <<endl;
		queue<nodo*> cola;
		for (std::size_t i = 0; i < 100; ++i) {
			cola.push(root->child[i]);
		}
		while (!cola.empty()) {
			if (cola.front()) {
				cout << cola.front()->dato << " ";
				/*
			if(current->dato == cola.front()->dato){

			   // if( current != nullptr  ){

					current->child[0] = nullptr;
					current->child[1] = nullptr;
				//}
			}
			*/
				cola.push(cola.front()->child[1]);
				//cola.push(cola.front()->nodes[1]);

			}
			cola.pop();
		}

		//stack<nodo* >
	}

};
