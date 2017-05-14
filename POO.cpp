// POO.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Objetos.h"


Objetos sonic;
Objetos fundo1;

void Desenho() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(75, (1368 / 768), 0.5, 100);
	gluLookAt(0, 0, 1, 0, 0, 0, 0, 1, 0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	fundo1.desenhaQuadradoNaTela();
	sonic.desenhaQuadradoNaTela();

	glutSwapBuffers();
	glutPostRedisplay();
}

void Teclado(unsigned char key, int x, int y) {
	fundo1.movimentarInvertido(key, x, y);
	sonic.movimentar(key, x, y);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1366, 768);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);
	glutCreateWindow("Com POO: =) // Sem POO: =(");
	//glutFullScreen();
	sonic = Objetos(4, "sonic.png", 0, 0, 0, 15, 0, 0);
	sonic.queroQuadrado();
	fundo1 = Objetos(4, "background.png", 0, 0, 0, 0, 0.0125f, 0.00625f);
	fundo1.queroQuadradoDeFundo();
	glutDisplayFunc(Desenho);
	glutKeyboardFunc(Teclado);
	glutMainLoop();
	return 0;
}
