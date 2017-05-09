#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include "Objetos.h"
#include <vector>
#include <SOIL.h>

Objetos::Objetos() {
	numeroDeVertices = 0;
	idTextura = NULL;
	posicaoX = 0;
	posicaoY = 0;
	angulo = 0;
	taxaDeVariacaoX = 0;
	taxaDeVariacaoY = 0;
}

Objetos::Objetos(int numerodevertices, char *filename, float posicaoInicialX, float posicaoInicialY, float anguloInicial, float taxadevariacaoX, float taxadevariacaoY) {
	numeroDeVertices = numerodevertices;

	idTextura = SOIL_load_OGL_texture(
		filename,
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID, 
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	for (int i = 0; i<(2 * numerodevertices); i++) {
		vetorDeVertices.push_back(0);
	}

	posicaoX = posicaoInicialX;
	posicaoY = posicaoInicialY;
	angulo = 0;
	taxaDeVariacaoX = taxadevariacaoX;
	taxaDeVariacaoY = taxadevariacaoY;
}

void Objetos::desenhaQuadradoNaTela() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

	gluPerspective(75, (1368 / 768), 0.5, 100);
	gluLookAt(0, 0, 1, 0, 0, 0, 0, 1, 0);

	glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	
	glTranslatef(posicaoX, posicaoY, 0);

	glRotatef(angulo, 0, 0, 1);

	glBindTexture(GL_TEXTURE_2D, idTextura);

	glEnable(GL_TEXTURE_2D);

	glBegin(GL_QUADS);

	//Primeiro vértice no canto superior direito e segue o sentido anti-horário
	glTexCoord2f(1.0f, 1.0f);
	glVertex2f(vetorDeVertices[0], vetorDeVertices[1]);

	glTexCoord2f(0.0f, 1.0f);
	glVertex2f(vetorDeVertices[2], vetorDeVertices[3]);

	glTexCoord2f(0.0f, 0.0f);
	glVertex2f(vetorDeVertices[4], vetorDeVertices[5]);

	glTexCoord2f(1.0f, 0.0f);
	glVertex2f(vetorDeVertices[6], vetorDeVertices[7]);
	glEnd();

	glDisable(GL_TEXTURE_2D);

	glutSwapBuffers();
	glutPostRedisplay();
}

void Objetos::seteMeusVertices(float *vertices) {
	for(int i = 0; i < (2*numeroDeVertices); i++) {
		vetorDeVertices[i] = vertices[i];
	}
}


void Objetos::queroQuadrado() {
	vetorDeVertices[0] = 0.125;
	vetorDeVertices[1] = 0.250;
	vetorDeVertices[2] = 0.0;
	vetorDeVertices[3] = 0.250;
	vetorDeVertices[4] = 0.0;
	vetorDeVertices[5] = 0.0;
	vetorDeVertices[6] = 0.125;
	vetorDeVertices[7] = 0.0;
}

void Objetos::queroQuadradoDeFundo() {
	vetorDeVertices[0] = 1.992;
	vetorDeVertices[1] = 1.0;
	vetorDeVertices[2] = -1.992;
	vetorDeVertices[3] = 1.0;
	vetorDeVertices[4] = -1.992;
	vetorDeVertices[5] = -1.0;
	vetorDeVertices[6] = 1.992;
	vetorDeVertices[7] = -1.0;
}

void Objetos::movimentar(unsigned char key, int x, int y) {
	if (key == 27) {
		exit(0);
	}
	
	if (key == 'd' || key == 'D') {
		posicaoX = posicaoX + taxaDeVariacaoX;
	}

	if (key == 'a' || key == 'A') {
		posicaoX = posicaoX - taxaDeVariacaoX;
	}

	if (key == 'w' || key == 'W') {
		posicaoY = posicaoY + taxaDeVariacaoY;
	}

	if (key == 's' || key == 'S') {
		posicaoY = posicaoY - taxaDeVariacaoY;
	}

	if (key == 'q' || key == 'Q') {
		angulo = angulo + 15;
	}

	if (key == 'e' || key == 'E') {
		angulo = angulo - 15;
	}
}

void Objetos::movimentarInvertido(unsigned char key, int x, int y) {
	if (key == 27) {
		exit(0);
	}
	
	if (key == 'd' || key == 'D') {
		posicaoX = posicaoX - 0.0125;
	}

	if (key == 'a' || key == 'A') {
		posicaoX = posicaoX + 0.0125;
	}

	if (key == 'w' || key == 'W') {
		posicaoY = posicaoY - 0.0125;
	}

	if (key == 's' || key == 'S') {
		posicaoY = posicaoY + 0.0125;
	}

	if (key == 'q' || key == 'Q') {
		angulo = angulo + 15;
	}

	if (key == 'e' || key == 'E') {
		angulo = angulo - 15;
	}
}