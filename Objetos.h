#pragma once
#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include "Objetos.h"
#include <vector>
class Objetos {
	int numeroDeVertices;
	GLuint idTextura;
	std::vector<float> vetorDeVertices;
	float posicaoX;
	float posicaoY;
	float angulo;
	float taxaDeVariacaoX;
	float taxaDeVariacaoY;
public:
	Objetos();
	Objetos::Objetos(int numerodevertices, char *filename, float posicaoInicialX, float posicaoInicialY, float anguloInicial, float taxadevariacaoX, float taxadevariacaoY);
	void Objetos::desenhaQuadradoNaTela();
	void Objetos::queroQuadrado();
	void Objetos::movimentar(unsigned char key, int x, int y);
	void Objetos::movimentarInvertido(unsigned char key, int x, int y);
	void Objetos::seteMeusVertices(float *vertices);
	void Objetos::queroQuadradoDeFundo();
};



