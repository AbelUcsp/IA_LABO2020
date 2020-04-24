#include "grafo.hpp"



int elementos = 100;
grafoIA A(elementos);


int nodo_inicial = 70;
int nodo_final = 8070;

float width = 800.f;
float height = 700.f;

void displayGizmo()
{
	float  idc = 7.0f;
	unsigned int i;


	glBegin(GL_POINTS);
	for (i = 0; i < A.root->nodo_cuadricula.size(); ++i) {
		if (A.root->nodo_cuadricula[i]->bloqueado == false) {
			glColor4ub(200.0f, 200.0f, 0, 255.f); /// 0-255
			glVertex2d((float)A.root->nodo_cuadricula[i]->y * idc, (float)A.root->nodo_cuadricula[i]->x * idc);
		}
	}
	//glEnd();
	//glFlush(); ///limpia buffer






	///glBegin(GL_POINTS);
	for (i = 0; i < A.visitados.size(); ++i) {
		glColor4ub(100, 0, 100, 255.f); /// 0-255
		glVertex2d(A.visitados[i]->y * idc, A.visitados[i]->x * idc);
	}
	for (i = 0; i < A.solucionA.size(); ++i) {
		glColor4ub(255, 0, 255, 255.f); /// 0-255
		glVertex2d(A.solucionA[i]->y * idc, A.solucionA[i]->x * idc);
	}





	/**
	///glBegin(GL_POINTS);
	for (i = 0; i < A.solucionAnchura.size(); ++i) {
		if (A.solucionAnchura[i]->bloqueado == false) {
			glColor4ub(0, 100, 100, 255.f); /// 0-255
			glVertex2d(A.solucionAnchura[i]->y * idc, A.solucionAnchura[i]->x * idc);
		}
	}
	for (i = 0; i < A.solucionA.size(); ++i) {
		glColor4ub(0, 255, 255, 255.f); /// 0-255
		glVertex2d(A.solucionA[i]->y * idc, A.solucionA[i]->x * idc);
	}
	*/




	glEnd();
	glFlush(); ///limpia buffer
}


//funcion llamada a cada imagen || funcion de dibujado
void glPaint(void) {
	//El fondo de la escena al color initial
	glClear(GL_COLOR_BUFFER_BIT); //CAMBIO
	glLoadIdentity();
	//glOrtho(-300.0f, 300.0f, -300.0f, 300.0f, -1.0f, 1.0f);
	glOrtho(-100, width, -20, height, 1.0f, -1.0f);


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
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); //(R, G, B, transparencia) en este caso un fondo negro
	glPointSize(3);

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

	default:
		break;
	}
}



int main(int argc, char** argv) {

	A.root->bloquear(500);
	A.ANCHURA(A.root->nodo_cuadricula[nodo_inicial], A.root->nodo_cuadricula[nodo_final]);
	A.A_asterico(A.root->nodo_cuadricula[nodo_inicial], A.root->nodo_cuadricula[nodo_final]);


	cout << "SALIDA " << A.root->nodo_cuadricula.size() << endl;



	glutInit(&argc, argv); //incia GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // modo video dos buffer || modo video RGB
	glutInitWindowSize(width, height); //tama?o de la ventana
	glutInitWindowPosition(0, 0); //posicion de la ventana
	glutCreateWindow("IA_LABO_01"); //titulo de la ventana

	init_GL(); //funcion de inicializacion de OpenGL

	glutDisplayFunc(glPaint);
	glutReshapeFunc(&window_redraw);
	// Callback del teclado
	glutKeyboardFunc(&window_key);
	//glutMouseFunc(&OnMouseClick);
	//glutMotionFunc(&OnMouseMotion);

	//glutIdleFunc(&idle);

	//glFlush(); ///limpia buffer
	//system.("pause");
	glutMainLoop(); //bucle de rendering

	//system("pause");
	return 0;
}
