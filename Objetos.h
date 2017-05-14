// TODO trocar o #pragma once
#pragma once
#include "stdafx.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <GL/glut.h>
#include <vector>
#include "Vec3.h"
#ifdef WIN32
	#include <SOIL.h>
#else
	#include <SOIL/SOIL.h>
#endif


class Objetos {
	int numeroDeVertices;
	GLuint idTextura;
	std::vector<Vec3> vetorDeVertices;
	std::vector<Vec3> vetorDeCoordenadasDeTexturas;
	Vec3 posicao;
	Vec3 velocidade;
	float angulo;
public:
	Objetos();
	Objetos(int numerodevertices, char *filename, float posicaoInicialX, float posicaoInicialY, float anguloInicial, float taxadevariacaoX, float taxadevariacaoY);
	void desenhaQuadradoNaTela();
	void queroQuadrado();
	void movimentar(unsigned char key, int x, int y);
	void movimentarInvertido(unsigned char key, int x, int y);
	void seteMeusVertices(Vec3 *vertices, Vec3 *textura);
	void queroQuadradoDeFundo();
};



