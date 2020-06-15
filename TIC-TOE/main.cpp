#include "Minimax.hpp"


int width = 300.0f;
int height = 300.0f;
int global_X;
int global_Y;

int deepGlobal = 0;
bool GANO = false;

coodernadas mapa[3][3];
int turnojuego = 3; ///0=pc-red,	1=persona-blue


void displayGizmo()
{

	glBegin(GL_LINES);
	glColor4ub(255, 200.0f, 0, 255.f); /// 0-255
	glVertex2d(100, 0);
	glVertex2d(100, 300);

	glVertex2d(200, 0);
	glVertex2d(200, 300);

	glVertex2d(0, 100);
	glVertex2d(300, 100);

	glVertex2d(0, 200);
	glVertex2d(300, 200);
	glEnd(); ///end tic toe


	glBegin(GL_POINTS);
	for (size_t i = 0; i < 3; ++i) {///TABLERO
		for (size_t j = 0; j < 3; ++j) {
			
			//glPointSize(10.0f);
			if (tablero[i][j] == 1) {
				glColor4ub(0.0f, 0.0f, 255, 255.f); /// 0-255
				//glVertex2d(coordenadas[i].first, coordenadas[j].second);
				glVertex2d(mapa[i][j].x , mapa[i][j].y );
			}
			else if (tablero[i][j] == 0) {
				glColor4ub(255, 0.0f, 0.0f, 255.f); /// 0-255
				glVertex2d(mapa[i][j].x, mapa[i][j].y );
			}
		
		}	
		
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
	glOrtho(0, width, 0, height, 1.0f, -1.0f);

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
	glPointSize(15);

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

void jugador(){
	
	if ( (global_X > 0 && global_X < 100) && (global_Y > 0 && global_Y < 100)) {
		if (turnojuego == 2 && tablero[0][0] == -1) {
			tablero[0][0] = 1;
			turnojuego = 1;
		}
	}
	else if ((global_X > 100 && global_X < 200) && (global_Y > 0 && global_Y < 100)) {
		if (turnojuego == 2 && tablero[0][1] == -1){
			tablero[0][1] = 1;
			turnojuego = 1;
		}
	}
	else if ((global_X > 200 && global_X < 300) && (global_Y > 0 && global_Y < 100)) {

		if (turnojuego == 2 && tablero[0][2] == -1){
			tablero[0][2] = 1;
			turnojuego = 1;
		}
	}
	else if ((global_X > 0 && global_X < 100) && (global_Y > 100 && global_Y < 200)) {

		if (turnojuego == 2 && tablero[1][0] == -1){
			tablero[1][0] = 1;
			turnojuego = 1;
		}
	}
	else if ((global_X > 100 && global_X < 200) && (global_Y > 100 && global_Y < 200)) {

		if (turnojuego == 2 && tablero[1][1] == -1){
			tablero[1][1] = 1;
			turnojuego = 1;
		}
	}
	else if ((global_X > 200 && global_X < 300) && (global_Y > 100 && global_Y < 200)) {

		if (turnojuego == 2 && tablero[1][2] == -1){
			tablero[1][2] = 1;
			turnojuego = 1;
		}
	}
	else if ((global_X > 0 && global_X < 100) && (global_Y > 200 && global_Y < 300)) {

		if (turnojuego == 2 && tablero[2][0] == -1){
			tablero[2][0] = 1;
			turnojuego = 1;
		}
	}
	else if ((global_X > 100 && global_X < 200) && (global_Y > 200 && global_Y < 300)) {

		if (turnojuego == 2 && tablero[2][1] == -1){
			tablero[2][1] = 1;
			turnojuego = 1;
		}
		
	}
	else if ((global_X > 200 && global_X < 300) && (global_Y > 200 && global_Y < 300)) {

		if (turnojuego == 2 && tablero[2][2] == -1){
			tablero[2][2] = 1;
			turnojuego = 1;
		}
		
	}
}

void OnMouseClick(int button, int state, int x, int y)
{
	global_X = x;
	global_Y = y;


	if (turnojuego == 1 && !GANO ) {
		///cout << "buscando mejor jugada....  " << endl;
		MejorJugada(deepGlobal);
		turnojuego = 2;
		glPaint();
		if (AlguienGano() == 0) {
			GANO = true;
			cout << " IA WINS " << GANO << endl;
		}
		
	}
	else if(turnojuego == 2 && !GANO ){
		///cout << "escoge la posicion [][]" << endl;
		//int x__,y__; cin >> x__>> y__;
		//tablero[x__][y__] = 1;
		jugador();
		//turnojuego = 1;
		glPaint();
		if (AlguienGano() == 1) {
			GANO = true;
			cout << " HUMAN WINS " << GANO << endl;
		}
	}


	if (GANO == true) {
		system("pause");
	}
	
	cout << endl;
}


GLvoid window_key(unsigned char key, int x, int y) {
	switch (key) {

	default:
		break;
	}
}



int main(int argc, char** argv) {

	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			tablero[i][j] = -1;

	mapa[0][0] = coodernadas(50, 250);
	mapa[0][1] = coodernadas(150, 250);
	mapa[0][2] = coodernadas(250, 250);
	mapa[1][0] = coodernadas(50, 150);
	mapa[1][1] = coodernadas(150, 150);
	mapa[1][2] = coodernadas(250, 150);
	mapa[2][0] = coodernadas(50, 50);
	mapa[2][1] = coodernadas(150, 50);
	mapa[2][2] = coodernadas(250, 50);

	cout << "Profundidad Arbol: "; cin >> deepGlobal;
	cout << "Quien inicia: IA(1) HUMAN(2)"; cin >> turnojuego;
	//deepGlobal = 0;
	//turnojuego = 1;


	glutInit(&argc, argv); //incia GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // modo video dos buffer || modo video RGB
	glutInitWindowSize(width, height); //tama?o de la ventana
	glutInitWindowPosition(0, 0); //posicion de la ventana
	glutCreateWindow("IA_LABO_02"); //titulo de la ventana

	init_GL(); //funcion de inicializacion de OpenGL
	glPaint();
///	glutDisplayFunc(glPaint);
	glutMouseFunc(&OnMouseClick);
	glutMainLoop(); //bucle de rendering

	return 0;
}
