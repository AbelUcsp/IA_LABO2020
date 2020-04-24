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
#include <list>
#include <GL/glut.h>

using namespace std;

#define infinito 10000.0f


class nodo {
public:
    int dato;
    int x;  ///para openGL
    int y;  ///para openGL

    bool bloqueado;
    bool visitado;	///para A*
    float local;
    float global;
    vector<nodo*> vecinos;
    nodo* parent;	///reconstruir camino
    nodo* nodes;    ///contendra la matrix
    list<nodo*> nodos; ///ordenados
    vector<nodo*> nodo_cuadricula; ///ordenados

    nodo() {//para hijos
        dato = x = y = -1;
        bloqueado = false;
        visitado = false;	///para A*
        local = infinito;
        global = infinito;
        nodes = nullptr;
        parent = nullptr;	/// reconstruir camino
    }

    nodo(int cantidad) {//para root
        dato = x = y = -1;
        bloqueado = false;
        visitado = false;	///para A*
        local = infinito;
        global = infinito;
        nodes = nullptr;
        parent = nullptr;	/// reconstruir camino

    }

    void inicializacion(int x__, int y__) {
        nodes = new nodo[x__ * y__];
        nodo_cuadricula.reserve(10000);
        int valor_ = 0;
        for (int x = 0; x < x__; x++)
            for (int y = 0; y < x__; y++)
            {
                nodes[y * x__ + x].dato = valor_;
                nodes[y * x__ + x].x = x;
                nodes[y * x__ + x].y = y;
                nodes[y * x__ + x].bloqueado = false;
                nodes[y * x__ + x].parent = nullptr;
                nodes[y * x__ + x].visitado = false;
                nodes[y * x__ + x].local = infinito;
                nodes[y * x__ + x].global = infinito;
                valor_++;
            }


        for (int x = 0; x < x__; x++)
            for (int y = 0; y < y__; y++)
            {
                if (y > 0)
                    nodes[y * x__ + x].vecinos.push_back(&nodes[(y - 1) * x__ + (x + 0)]);
                if (y < x__ - 1)
                    nodes[y * x__ + x].vecinos.push_back(&nodes[(y + 1) * x__ + (x + 0)]);
                if (x > 0)
                    nodes[y * x__ + x].vecinos.push_back(&nodes[(y + 0) * x__ + (x - 1)]);
                if (x < x__ - 1)
                    nodes[y * x__ + x].vecinos.push_back(&nodes[(y + 0) * x__ + (x + 1)]);

            }

        for (int i = 0; i < x__ * x__; ++i) {
            nodos.push_back(&nodes[i]);
        }
        nodos.sort([](const nodo* lhs, const nodo* rhs) {return lhs->dato < rhs->dato; });
        while (!nodos.empty()) {
            nodo_cuadricula.push_back(nodos.front());
            nodos.pop_front();
        }

    }

    void bloquear(int cantidad) {
        //for (auto i : nodo_cuadricula) {
        for (std::size_t i = 0; i < cantidad; ++i) {
            int rand_ = (rand() % (99 * 99)) + 1;
            //cout << (rand() % (99*99) ) + 1 << endl;
            nodo_cuadricula[rand_]->bloqueado = true;
        }
        for (std::size_t i = 0; i < 40; ++i) {
            nodo_cuadricula[5520 + i]->bloqueado = true;
        }
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
    int tamanho;
    int cantidad;
    vector<nodo*> solucionA;
    vector<nodo*> visitados;
    vector<nodo*> solucionAnchura;

    //vector<nodo*> copia;

    grafoIA(int cantidad) {
        root = new nodo(cantidad);
        root->setDATA(-1);
        tamanho = 0;
        this->cantidad = cantidad;
        root->inicializacion(cantidad, cantidad);
        ///solucionAnchura.reserve(10000);
    }


    void ANCHURA(nodo* inicio, nodo* destino) {///ANCHURA/AMPLITUD
        queue<nodo*> cola;
        vector<nodo*> copia(root->nodo_cuadricula);
        int i = 0;
        while (inicio->dato != root->nodo_cuadricula[i]->dato) {
            copia.erase(copia.begin());
            i++;
        }
        while (destino->dato != root->nodo_cuadricula[i]->dato) {
            i++;
        }

        int cc = (inicio->dato) % cantidad;
        int i_ = (inicio->dato) / cantidad;
        int k = 0;

        for (int ii = i_; ii < cantidad; ++ii) {
            for (int j = cc; j < cantidad; ++j) {
                if (copia[k]->bloqueado == false && destino->dato > copia[k]->dato && copia[k]->bloqueado == false) {
                    cola.push(copia[k]);
                    //solucionAnchura.push_back(copia[k]);
                }
                i_++;
                k++;
            }
            //i = 0;
        }

        while (root->nodo_cuadricula[i] != nullptr) {
            //if (root->nodo_cuadricula[i]->bloqueado == false) {
            copia.pop_back();
            i++;
            //} 
        }

        copia.swap(solucionAnchura);
        /**
        for (std::size_t indice = 0; indice < solucionAnchura.size(); ++indice) {
            if (copia[i]->bloqueado == false) {
                solucionAnchura.push_back(copia[i]);
            }
        }
        ****/

    }


    ///float euclides(nodo *A, nodo *B) {
    float euclides(nodo* A, nodo* B)
    {
        return static_cast<float>(sqrt(pow(abs(B->x - A->x), 2) + pow(abs(B->y - A->y), 2)));
    }

    float manhattan(nodo* A, nodo* B)
        ///float euclides(nodo* A, nodo* B)
    {
        return static_cast<float>((abs(B->x - A->x) + abs(B->y - A->y)));
    }

    float octagonal(nodo* A, nodo* B)
        //float euclides(nodo *A, nodo *B)
    {
        return static_cast<float>((abs(B->x - A->x) + abs(B->y - A->y)) + (-6) * min(abs(B->x - A->x), abs(B->y - A->y)));
    }

    bool A_asterico(nodo* inicio, nodo* final_) {
        nodo* actual = inicio;	///explorando actual
        inicio->local = 0.0f;
        inicio->global = euclides(inicio, final_);
        list<nodo*> lista_noProbados; ///para probar todos posibles nodo hasta final
        lista_noProbados.push_back(inicio);

        while (!lista_noProbados.empty() && actual != final_) {
            lista_noProbados.sort([](const nodo* lhs, const nodo* rhs) {return lhs->global < rhs->global; });
            while (!lista_noProbados.empty() && lista_noProbados.front()->visitado) {
                lista_noProbados.pop_front();
            }
            if (lista_noProbados.empty())
                break;

            actual = lista_noProbados.front();
            actual->visitado = true;
            for (auto nodoVecino : actual->vecinos) {   ///revisar vecinos
                //if (!nodoVecino->visitado && nodoVecino != nullptr) {//si ya visitado o es obstaculo
                if (!nodoVecino->visitado && nodoVecino->bloqueado == false) {//si ya visitado o es obstaculo
                    lista_noProbados.push_back(nodoVecino);
                    visitados.push_back(nodoVecino);///BORRAR
                }
                float PosibleMenor = actual->local + euclides(actual, nodoVecino);
                if (PosibleMenor < nodoVecino->local) {
                    nodoVecino->parent = actual;
                    nodoVecino->local = PosibleMenor;

                    nodoVecino->global = nodoVecino->local + euclides(nodoVecino, final_);
                }
            }
        }
        /**
        for(auto i : lista_noProbados )
            visitados.push_back(i);
        cout << "tamanho " << visitados.size() << endl;
        */
        nodo* temp = final_->parent;
        solucionA.push_back(final_);
        while (temp->parent != nullptr) {
            solucionA.push_back(temp);
            temp = temp->parent;
        }
        solucionA.push_back(inicio);
        return true;
    }
};
