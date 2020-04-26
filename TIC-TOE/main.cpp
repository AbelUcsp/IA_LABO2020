#include "Minimax.hpp"




int width = 300.0f;
int height = 300.0f;
int global_X;
int global_Y;
int global = 0;

int deepGlobal = 0;
vector<int > plano;
vector< pair<int, int> >coordenadas;

int player; ///0 pc,		1 persona,		-1 free
bool turno; ///false pc-red,	true persona-blue

int getGoodMove(MiniMax* minimaxtree)
{
	if (minimaxtree->sons.size() <= 0)
	{
		//cout << "to push: " << minimaxtree->RValue << endl;
		return minimaxtree->RValue;
	}
	else
	{
		vector<int> values;
		for (size_t i = 0; i < minimaxtree->sons.size(); i++)
		{
			values.push_back(getGoodMove(minimaxtree->sons[i]));
		}
		if (minimaxtree->isMax == true and minimaxtree->isMin == false)
		{
			int bruh = *std::max_element(values.begin(), values.end());
			minimaxtree->MinimaxVal = bruh;
			///printVector(values);
			//cout << "Max DSFDSFDSFDSF: " << bruh << endl;
			return bruh;
		}
		if (minimaxtree->isMax == false and minimaxtree->isMin == true)
		{
			int bruh = *std::min_element(values.begin(), values.end());
			minimaxtree->MinimaxVal = bruh;
			///printVector(values);
			//cout << "Min answ: " << bruh << endl;
			return bruh;
		}
	}
}


void startBoard()
{
	for (size_t i = 0; i < 9; i++)
	{
		board.push_back('C');
	}
}



void displayGizmo()
{
	float  idc = 7.0f;
	unsigned int i;


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



	for (size_t i = 0; i < 9; ++i) {///TABLERO
		glBegin(GL_POINTS);
		//glPointSize(10.0f);

		if (plano[i] == 1) {
			glColor4ub(0.0f, 0.0f, 255, 255.f); /// 0-255
			glVertex2d(coordenadas[i].first, coordenadas[i].second);
		}
		else if (plano[i] == 0) {
			glColor4ub(255, 0.0f, 0.0f, 255.f); /// 0-255
			glVertex2d(coordenadas[i].first, coordenadas[i].second);
		}
		glEnd();
	}


	/*
	for (size_t i = 0; i < 9; ++i)
		cout << plano[i] << " ";
	*/
	//cout << global << " global ";
	//cout << endl;


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

void OnMouseClick(int button, int state, int x, int y)
{
	global_X = x;
	global_Y = y;
	//global++;
	int player_id = -1;


	int GM_;
	int TheChosenOne;
	cout << "IA move now : " << endl;
	MiniMax* SKYNET;
	SKYNET = new MiniMax(deepGlobal, true, false, board, 'B');
	cout << "mimimax tree done..." << endl;
	GM_ = getGoodMove(SKYNET);
	cout << "GM: " << GM_ << endl;
	for (size_t i = 0; i < SKYNET->sons.size(); i++)
	{
		if (SKYNET->sons[i]->MinimaxVal == GM_)
		{
			TheChosenOne = i;
		}
	}
	std::size_t indice;
	for (indice = 0; indice < 9; ++indice) {
		if (board[indice] != SKYNET->sons[TheChosenOne]->internalBoard[indice]) {
			//cout << "I " << SKYNET->sons[TheChosenOne]->internalBoard[indice] << endl;
			break;
		}
	}

	board = SKYNET->sons[TheChosenOne]->internalBoard;
	plano[indice] = 0;
	cout << " ---------Gameplay--------- " << indice << endl;
	//printboardchar(board);


	cout << "Write pos of move [0-8]" << endl;
	int val; cin >> val;
	board[val] = 'A';
	plano[val] = 1;
	//printboardchar(board);

	

	


	///END
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//cout << "x: " << x << endl;
		//cout << "y: " << y << endl;

	}
	
	/**
	if (player == 1) {
		player_id = 1;
		turno = true;
	}
	else if (player == 0) {
		player_id = 0;
		turno = false;
	}
	*/


	///INICIO CUADRICULA
	if ( (x > 0 && x < 100) && (y > 0 && y < 100)) {
		if (turno==true && plano[0] == -1) {
			plano[0] = 1;
			turno = !turno;
		}
		else if (turno==false && plano[0] == -1 ){
			plano[0] = 0;
		turno = !turno;
		}
		cout << "bool " << turno << endl;
	}
	else if ((x > 100 && x < 200) && (y > 0 && y < 100)) {
		if (turno == true  && plano[1] == -1){
			plano[1] = 1;
			turno = !turno;
		}
		else if (turno==false && plano[1] == -1){
			plano[1] = 0;
			turno = !turno;
		}
		cout << "bool " << turno << endl;
	}
	else if ((global_X > 200 && global_X < 300) && (global_Y > 0 && global_Y < 100)) {

		if (turno == true && plano[2] == -1){
			plano[2] = 1;
			turno = !turno;
		}
		else if (turno==false  && plano[2] == -1){
			plano[2] = 0;
			turno = !turno;
		}
		cout << "bool " << turno << endl;
	}

	else if ((global_X > 0 && global_X < 100) && (global_Y > 100 && global_Y < 200)) {

		if (turno == true && plano[3] == -1){
			plano[3] = 1;
			turno = !turno;
		}
		else if ( turno==false && plano[3] == -1){
			plano[3] = 0;
			turno = !turno;
		}
		cout << "bool " << turno << endl;
	}
	else if ((global_X > 100 && global_X < 200) && (global_Y > 100 && global_Y < 200)) {

		if (turno && plano[4] == -1){
			plano[4] = 1;
			turno = !turno;
		}
		else if (!turno && plano[4] == -1){
			plano[4] = 0;
			turno = !turno;
		}
		cout << "bool " << turno << endl;
	}
	else if ((global_X > 200 && global_X < 300) && (global_Y > 100 && global_Y < 200)) {

		if (turno && plano[5] == -1){
			plano[5] = 1;
			turno = !turno;
		}
		else if (!turno && plano[5] == -1){
			plano[5] = 0;
			turno = !turno;
		}
		cout << "bool " << turno << endl;
	}
	else if ((global_X > 0 && global_X < 100) && (global_Y > 200 && global_Y < 300)) {

		if (turno && plano[6] == -1){
			plano[6] = 1;
			turno = !turno;
		}
		else if (!turno && plano[6] == -1){
			plano[6] = 0;
			turno = !turno;
		}
		cout << "bool " << turno << endl;
	}
	else if ((global_X > 100 && global_X < 200) && (global_Y > 200 && global_Y < 300)) {

		if (turno && plano[7] == -1){
			plano[7] = 1;
			turno = !turno;
		}
		else if (!turno && plano[7] == -1){
			plano[7] = 0;
		turno = !turno;
		}
		cout << "bool " << endl;
	}
	else if ((global_X > 200 && global_X < 300) && (global_Y > 200 && global_Y < 300)) {

		if (turno && plano[8] == -1){
			plano[8] = 1;
			turno = !turno;
		}
		else if (!turno && plano[8] == -1){
			plano[8] = 0;
			turno = !turno;
	}
		cout << "bool " << endl;
	}
	///END CUADRICULA

	/**
	for (auto i : coordenadas)
		cout << i.first << " " << i.second << endl;
	*/

	cout << endl;
}

GLvoid window_key(unsigned char key, int x, int y) {
	switch (key) {

	default:
		break;
	}
}



int main(int argc, char** argv) {

	//int player = -1;
	//cout << "Quien Inicia Jugador o IA (?";
	//cin >> player; //0-1

	turno = (bool)player;
	for (size_t i = 0; i < 9; ++i)
		plano.push_back(-1);


	coordenadas.push_back(make_pair(50, 250));
	coordenadas.push_back(make_pair(150, 250));
	coordenadas.push_back(make_pair(250, 250));

	coordenadas.push_back(make_pair(50, 150));
	coordenadas.push_back(make_pair(150, 150));
	coordenadas.push_back(make_pair(250, 150));

	coordenadas.push_back(make_pair(50, 50));
	coordenadas.push_back(make_pair(150, 50));
	coordenadas.push_back(make_pair(250, 50));


	for (size_t i = 0; i < 9; ++i)
		cout << coordenadas[i].first << " " << coordenadas[i].second << endl;
	cout << endl;



	vector<int > plano;
	for (size_t i = 0; i < 9; ++i)
		plano.push_back(-1);

	cout << "Insert deep tree: "; cin >> deepGlobal;
	bool winval = false;
	string test;
	startBoard();
	printboardchar(board);


	/*
	while (winval != true)
	{
		cout << "Write: AI if AI move or HUM if Human move" << endl;
		cin >> test;
		//cout << "Quien Inicia Jugador o IA (?";
		//cin >> player; //0-1

		int GM_;
		int TheChosenOne;
		
		cout << "IA move now : " << endl;
		MiniMax* SKYNET;
		SKYNET = new MiniMax(deepGlobal, true, false, board, 'B');
		cout << "mimimax tree done..." << endl;
		GM_ = getGoodMove(SKYNET);
		cout << "GM: " << GM_ << endl;
		for (size_t i = 0; i < SKYNET->sons.size(); i++)
		{
			if (SKYNET->sons[i]->MinimaxVal == GM_)
			{
				TheChosenOne = i;
			}
		}
		std::size_t indice;
		for (indice = 0; indice < 9; ++indice) {
			if (board[indice] != SKYNET->sons[TheChosenOne]->internalBoard[indice]) {
				//cout << "I " << SKYNET->sons[TheChosenOne]->internalBoard[indice] << endl;
				break;
			}
		}

		board = SKYNET->sons[TheChosenOne]->internalBoard;
		plano[indice] = 0;
		cout << " ---------Gameplay--------- " << indice << endl;
		printboardchar(board);
		

		cout << "Write pos of move [0-8]" << endl;
		int val; cin >> val;
		board[val] = 'A';
		plano[val] = 1;
		printboardchar(board);

		for (auto i : plano)
			cout << i << " ";
		cout << endl;
		
	}
	*/






	//cout << tic_toe.root->hijos[0]->hijos[0]->hoja  << endl;


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
	glutMouseFunc(&OnMouseClick);

	//glutMotionFunc(&OnMouseMotion);
	glutMainLoop(); //bucle de rendering

	//system("pause");
	return 0;
}
