// POO.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <GL/glut.h>
#include "Objetos.h"
#include <SOIL.h>

Objetos sonic;
Objetos fundo1;
Objetos fundo2;

void Desenho() {
	fundo2.desenhaQuadradoNaTela();
	fundo1.desenhaQuadradoNaTela();
	sonic.desenhaQuadradoNaTela();
	glutSwapBuffers();
	glutPostRedisplay();
}

void Teclado(unsigned char key, int x, int y) {
	fundo2.movimentar(key, x, y);
	fundo1.movimentar(key, x, y);
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
	sonic = Objetos(4, "sonic.png", 0, 0, 0, 0, 0);
	sonic.queroQuadrado();
	fundo1 = Objetos(4, "bga.png", 0, 0, 0,/* 0.0125, 0.00625*/0,0);
	fundo1.queroQuadradoDeFundo();
	fundo2 = Objetos(4, "bgb.png", 0, 0, 0,/* 0.0625, 0.0315*/0,0);
	fundo2.queroQuadradoDeFundo(); 
	glutDisplayFunc(Desenho);
	glutKeyboardFunc(Teclado);
	glutMainLoop();
	return 0;
}