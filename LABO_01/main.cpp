#include "grafo.hpp"

int puntoB[200];


void displayGizmo()
{
	unsigned int i;
	glBegin(GL_POINTS);
	for (i = 0; i < 144; ++i) {
		glColor3d(0, 255, 0);
		//glVertex2d(hull[i].x, hull[i].y);

		glVertex2d(i, puntoB[i]);

	}
	glEnd();
}




void idle() { // AGREGAR ESTA FUNCION
	glutPostRedisplay();
}

//funcion llamada a cada imagen || funcion de dibujado
void glPaint(void) {
	//El fondo de la escena al color initial
	glClear(GL_COLOR_BUFFER_BIT); //CAMBIO
	glLoadIdentity();
	glOrtho(-300.0f, 300.0f, -300.0f, 300.0f, -1.0f, 1.0f);

	//version 1
	//
	displayGizmo();
	//displayGizmo2();


	//doble buffer, mantener esta instruccion al fin de la funcion
	glutSwapBuffers();
}

//
//inicializacion de OpenGL
//
void init_GL(void) {
	//Color del fondo de la escena

	glPointSize(2);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); //(R, G, B, transparencia) en este caso un fondo negro

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


GLvoid window_key(unsigned char key, int x, int y) {
	switch (key) {
		/*
	case KEY_ESC:
		exit(0);
		break;
		*/
	default:
		break;
	}
}



int main(int argc, char** argv) {


	//vector<Point> a = { {0, 3}, {1, 1}, {2, 2}, {4, 4}, {0, 0}, { 1, 2 }, { 3, 1 }, { 3, 3 } };


	int PUNTOC[200];
	for (int i = 0; i < 10; i++) {

		puntoB[i] = PUNTOC[i];
	}


	grafoIA A(100);

	nodo* tmp = A.root->tmp;
	for (unsigned int i = 4; i < 100; ++i) {///99-99
		nodo* tmp_ = A.root->add100(tmp, 100, i * 100, i);
		tmp = tmp_;
	}

	A.ANCHURA(A.root->child[98]->child[1]->child[1], A.root);
	for (int i = 0; i < 200; i++) {

		PUNTOC[i] = A.caminoX[i];
	}








//Inicializacion de la GLUT
	glutInit(&argc, argv); //incia GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // modo video dos buffer || modo video RGB
	glutInitWindowSize(600, 600); //tama?o de la ventana
	glutInitWindowPosition(150, 150); //posicion de la ventana
	glutCreateWindow("IA_LABO_01"); //titulo de la ventana

	init_GL(); //funcion de inicializacion de OpenGL

	glutDisplayFunc(glPaint);
	glutReshapeFunc(&window_redraw);
	// Callback del teclado
	glutKeyboardFunc(&window_key);
	//glutMouseFunc(&OnMouseClick);
	//glutMotionFunc(&OnMouseMotion);
	glutIdleFunc(&idle);
	//glFlush() limpia buffer

	glutMainLoop(); //bucle de rendering

	return 0;
}


/**
int main() {

	grafoIA A(100);
	//A.root->child[99];			//100 primero hijos, cada hijo tendra 1 hijo con 2 aristas derecha(0) y abajo(1)

	/************+
	nodo* tmp = A.root->add100(A.root, 100, 100, 1);
	nodo* tmp2 = A.root->add100(tmp, 100, 200, 2);
	tmp = A.root->add100(tmp2, 100, 300, 3);
	tmp = A.root->add100(tmp, 100, 400, 4);
********************


	nodo* tmp = A.root->tmp;
	for (unsigned int i = 4; i < 100; ++i) {///99-99
		nodo* tmp_ = A.root->add100(tmp, 100, i * 100, i);
		tmp = tmp_;
	}

	//A.root->eliminar(A.root->child[0]->child[1], A.root);

	A.root->eliminar(A.root->child[1]->child[1], A.root);
	A.ANCHURA(A.root->child[1]->child[1], A.root);

	cout << endl;
	
	return 0;
}


*/