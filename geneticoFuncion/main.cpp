#include <iostream>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>       
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <cmath>
#include <random>

#include<GL/glut.h>

using namespace std;
int CUANTOSELEMENTOS = 1800;

int width = CUANTOSELEMENTOS + 100;
int height = 600.0f;

int global_X;
int global_Y;

int repeticiones;

int random(int number){
	int i;
	i = (rand() % number) + 1;
	return i;
}



/// F(x,y) = x^2 -2xy + y^2
/// x = 0,127   y = 0,255
/****
*   START
*   Generate the initial population
*   Compute fitness
*   REPEAT
*      Selection
*      Crossover
*      Mutation
*      Compute fitness
*   UNTIL population has converged
*   STOP
****/

class coor {
public:
	int x;
	int y;
	coor(int x_,int y_): x(x_), y(y_){}
};

vector< pair<float, float> > promedio;
vector< pair<float, float> > mejor;

/// F(x,y) = x^2 -2xy + y^2
inline int F(int x, int y) { return 	(x * x) - (2 * x * y) + (y * y); }

coor mejor_( vector< pair<float, float> > A) {
	coor dato(0, 0);
	for (auto i : A) {
		if ( F(dato.x, dato.y) < F(i.first, i.second)){
			dato.x = i.first;
			dato.y = i.second;
		}
	}
	return dato;
}

int cruce(int P1, int P2, int puntocruce) {
	int indice = pow(2, puntocruce);
	int resto = P1 % indice;
	P1 ^= resto;

	P2 %= indice;
	return P1 + P2;
}
	
///						mutacion(0b1011101, 5,1); 1000011
float mutacion_(int elemento, int punto1, int punto2) {
	int ind1 = pow(2, punto1);
	int ind2 = pow(2, punto2);
	int resta = pow(2, punto1)-1;

	int c1 = elemento % ind1; //intervalo
	int c2 = elemento % ind2; //
	elemento >>= punto1;
	elemento <<= punto1;

	int otro = resta-c1;
	otro >>= punto2;
	otro <<= punto2;
	float  return_ = elemento + otro + c2;
	if (return_ > 256)
		return_ = 255;
	return return_;
}

int algoritmos_gen(int iteraciones, int idividuos) {
	vector< pair<coor, float> > todo;
	vector< pair<coor, float> > seleccion;
	vector< pair<coor, float> > cruzamiento;
	vector< pair<float, float> > mutacion;
	vector< pair<float, float> > tmpmutacion;
	tmpmutacion.reserve(1000);
	todo.reserve(1000);
	seleccion.reserve(1000);
	cruzamiento.reserve(1000);
	mutacion.reserve(1000);
	tmpmutacion.reserve(1000);



	float S = 0.0f;
	float media = 0.0f; 
	vector< pair<float, float> > tmpS;
	tmpS.reserve(idividuos);
	int x, y;
	for (int i = 0; i < idividuos; i++) {
		x = random(1000) % 36;
		y = random(1000) % 51;
		S += F(x, y);
		tmpS.push_back( make_pair(x,y));
	}
	
	media = S/ idividuos;
	for (int i = 0; i < idividuos; i++) 
		todo.push_back(make_pair(coor(tmpS[i].first, tmpS[i].second), F(tmpS[i].first, tmpS[i].second ) / media));
	

	int tmpX; int tmpY;
	coor mejor__(0,0);
	promedio.clear();
	mejor.clear();
	while (iteraciones > 0) {

		//Seleccion
		seleccion.clear();
		mutacion.clear();
	
		for (auto i : todo) {
			if (i.second >= 0.51f)
				seleccion.push_back(i);
				mutacion.push_back(make_pair(i.first.x, i.first.y));
		}
		tmpX =0; tmpY =0;
		for (auto i : mutacion) {
			tmpX += i.first;
			tmpY += i.second;
		}
		promedio.push_back(make_pair(tmpX/ mutacion.size(), tmpY/ mutacion.size()));
		mejor__ = mejor_(mutacion);
		mejor.push_back(make_pair(mejor__.x, mejor__.y));
		iteraciones--;




	
		//cruzamiento
		cruzamiento.clear();
		mutacion.clear();
		for (auto i : seleccion) {
			//int aptitud = ceil(i.second);
			int aptitud = round(i.second);
			if (i.second >= 0.51f)
				while (aptitud > 0) {
					cruzamiento.push_back(i);
					aptitud--;
				}
		}
		tmpX = 0; int tmpY = 0;
		for (auto i : cruzamiento) {
			int x_tmp = cruce(i.first.x, seleccion[random(seleccion.size())].first.x, random(cruzamiento.size()))%128;
			int y_tmp = cruce(i.first.y, seleccion[random(seleccion.size())].first.y, random(cruzamiento.size()))%256;

			tmpX += x_tmp;
			tmpY += y_tmp;
			mutacion.push_back(make_pair(x_tmp, y_tmp));
		}
		promedio.push_back(make_pair(tmpX / cruzamiento.size(), tmpY / cruzamiento.size()));
		mejor__ = mejor_(mutacion);
		mejor.push_back(make_pair(mejor__.x, mejor__.y));
		iteraciones--;



		//mutacion
		todo.clear();
		tmpmutacion.clear();
		tmpX = 0;
		tmpY = 0;
		S = 0.0f;
		for (auto i : mutacion) 
			tmpmutacion.push_back(make_pair(mutacion_(i.first, random(5), random(4)), mutacion_(i.second, random(6), random(4))));
			
		for (auto j : tmpmutacion) {
			S += F(j.first, j.second);
			tmpX += j.first;
			tmpY += j.second;
		}
		media = S / tmpmutacion.size();
		for (auto i : tmpmutacion)
			todo.push_back(make_pair(coor(i.first, i.second), F(i.first, i.second) / media));
		
		promedio.push_back(make_pair(tmpX / tmpmutacion.size(), tmpY / tmpmutacion.size()));
		mejor__ = mejor_(tmpmutacion);
		mejor.push_back(make_pair(mejor__.x, mejor__.y));
		iteraciones--;
	}
	return 1;
}


void displayGizmo()
{
	glBegin(GL_LINES);
	glColor4ub(255.0f, 255.0f, 0.0f, 255.f); /// 0-255
	glVertex2d(0, 0);
	glVertex2d(0, 510);

	glVertex2d(0, 0);
	glVertex2d(CUANTOSELEMENTOS, 0);

	for (auto i = 120; i < CUANTOSELEMENTOS; i+=120) {
		glVertex2d(i, 0);
		glVertex2d(i, 10);
	}

	glEnd(); ///end 2D

	/*
	cout << mejor[0].first << " " << mejor[0].second << endl;
	cout << mejor[CUANTOSELEMENTOS-1].first << " " << mejor[CUANTOSELEMENTOS-1].second << endl;
	cout << promedio[0].first << " " << promedio[0].second << endl;
	cout << promedio[CUANTOSELEMENTOS-1].first << " " << promedio[CUANTOSELEMENTOS-1].second << endl;
	*/
	
	glBegin(GL_POINTS);
	int j = 0;
	for (auto i : promedio) {
		glColor4ub(255, 0.0f, 0, 255.f); /// 0-255
		glVertex2d(j, i.second * 2);
		j++;
	}
	
	glBegin(GL_POINTS);
	j = 0;
	for (auto i : mejor) {
		glColor4ub(0.0f, 0.0f, 255, 255.f); /// 0-255
		glVertex2d(j ,  i.second*2);
		j++;
	}



	glEnd();
	glFlush(); ///limpia buffer
}


//funcion llamada a cada imagen || funcion de dibujado
void glPaint(void) {
	//El fondo de la escena al color initial
	glClear(GL_COLOR_BUFFER_BIT); //CAMBIO
	glLoadIdentity();
	//glOrtho(0, 3.0f, 0, 3.0f, -1.0f, 1.0f);
	glOrtho(-100, width, -100, height, 1.0f, -1.0f);

	displayGizmo();

	//doble buffer, mantener esta instruccion al fin de la funcion
	glutSwapBuffers();
}

//
//inicializacion de OpenGL
//
void init_GL(void) {
	//Color del fondo de la escena
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); //(R, G, B, transparencia) en este caso un fondo negro
	glPointSize(2);

	//modo projeccion
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}



//en el caso que la ventana cambie de tama?o
GLvoid window_redraw(GLsizei width, GLsizei height) {
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}



void OnMouseClick(int button, int state, int x, int y)
{
	global_X = x;
	global_Y = y;

	cout << endl;
}


GLvoid window_key(unsigned char key, int x, int y) {
	switch (key) {

	default:
		break;
	}
}



int main(int argc, char** argv) {

	promedio.reserve(1000);
	mejor.reserve(1000);

	algoritmos_gen(CUANTOSELEMENTOS, 10);
	///cout <<endl << "mutacion_ " << mutacion_(0b11011101, 6,3);	///0b11 100 101





	glutInit(&argc, argv); //incia GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // modo video dos buffer || modo video RGB
	glutInitWindowSize(width, height); //tama?o de la ventana
	glutInitWindowPosition(0, 0); //posicion de la ventana
	glutCreateWindow("IA_GA"); //titulo de la ventana

	init_GL(); //funcion de inicializacion de OpenGL
	glPaint();
	glutMouseFunc(&OnMouseClick);
	glutMainLoop(); //bucle de rendering

	return 0;
}
