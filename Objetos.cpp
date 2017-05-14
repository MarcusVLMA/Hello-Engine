#include "stdafx.h"
#include "Objetos.h"


Objetos::Objetos() {
	numeroDeVertices = 0;
	idTextura = NULL;
	posicao.x = 0;
	posicao.y = 0;
	angulo = 0;
	velocidade.x = 0;
	velocidade.y = 0;
}

Objetos::Objetos(int numerodevertices, char *filename, float posicaoInicialX, float posicaoInicialY, float anguloInicial, float variacaoangulo, float taxadevariacaoX, float taxadevariacaoY) {
	numeroDeVertices = numerodevertices;

	idTextura = SOIL_load_OGL_texture(
		filename,
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID, 
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	for (int i = 0; i< numerodevertices; i++) {

		vetorDeVertices.push_back(Vec3());
		vetorDeCoordenadasDeTexturas.push_back(Vec3());
	}

	posicao.x = posicaoInicialX;
	posicao.y = posicaoInicialY;
	angulo = anguloInicial;
	variacaoAngulo = variacaoangulo;
	velocidade.x = taxadevariacaoX;
	velocidade.y = taxadevariacaoY;
}

void Objetos::desenhaQuadradoNaTela() {
	glLoadIdentity();
	
	glTranslatef(posicao.x, posicao.y, 0);

	glRotatef(angulo, 0, 0, 1);

	glBindTexture(GL_TEXTURE_2D, idTextura);

	glEnable(GL_TEXTURE_2D);

	glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
			glVertexPointer(3, GL_FLOAT, 0, &vetorDeVertices[0].x);
			glTexCoordPointer(3, GL_FLOAT, 0, &vetorDeCoordenadasDeTexturas[0].x);
			glDrawArrays(GL_QUADS, 0, numeroDeVertices);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

	glDisable(GL_TEXTURE_2D);
}

void Objetos::seteMeusVertices(Vec3 *vertices, Vec3 *textura) {
	for(int i = 0; i < numeroDeVertices; i++) {
		vetorDeVertices[i].x = vertices[i].x;
		vetorDeVertices[i].y = vertices[i].y;
		vetorDeVertices[i].z = vertices[i].z;

		vetorDeCoordenadasDeTexturas[i].x = textura[i].x;
		vetorDeCoordenadasDeTexturas[i].y = textura[i].y;
		vetorDeCoordenadasDeTexturas[i].z = textura[i].z;
	}

}


void Objetos::queroQuadrado() {
	vetorDeVertices[0].x = 0.125f;
	vetorDeVertices[0].y = 0.250f;

	vetorDeVertices[1].x = 0.0f;
	vetorDeVertices[1].y = 0.250f;

	vetorDeVertices[2].x = 0.0f;
	vetorDeVertices[2].y = 0.0f;

	vetorDeVertices[3].x = 0.125f;
	vetorDeVertices[3].y = 0.0f;
	//==============Textura=========
	vetorDeCoordenadasDeTexturas[0].x = 1.0;
	vetorDeCoordenadasDeTexturas[0].y = 1.0;

	vetorDeCoordenadasDeTexturas[1].x = 0.0;
	vetorDeCoordenadasDeTexturas[1].y = 1.0;

	vetorDeCoordenadasDeTexturas[2].x = 0.0;
	vetorDeCoordenadasDeTexturas[2].y = 0.0;

	vetorDeCoordenadasDeTexturas[3].x = 1.0;
	vetorDeCoordenadasDeTexturas[3].y = 0.0;
}

void Objetos::queroQuadradoDeFundo() {
	vetorDeVertices[0].x = 1.992f;
	vetorDeVertices[0].y = 1.0f;

	vetorDeVertices[1].x = -1.992f;
	vetorDeVertices[1].y = 1.0f;

	vetorDeVertices[2].x = -1.992f;
	vetorDeVertices[2].y = -1.0f;

	vetorDeVertices[3].x = 1.992f;
	vetorDeVertices[3].y = -1.0f;
	//==============Textura=========
	vetorDeCoordenadasDeTexturas[0].x = 1.0;
	vetorDeCoordenadasDeTexturas[0].y = 1.0;

	vetorDeCoordenadasDeTexturas[1].x = 0.0;
	vetorDeCoordenadasDeTexturas[1].y = 1.0;

	vetorDeCoordenadasDeTexturas[2].x = 0.0;
	vetorDeCoordenadasDeTexturas[2].y = 0.0;

	vetorDeCoordenadasDeTexturas[3].x = 1.0;
	vetorDeCoordenadasDeTexturas[3].y = 0.0;
}

void Objetos::movimentar(unsigned char key, int x, int y) {
	if (key == 27) {
		exit(0);
	}
	
	if (key == 'd' || key == 'D') {
		posicao.x = posicao.x + velocidade.x;
	}

	if (key == 'a' || key == 'A') {
		posicao.x = posicao.x - velocidade.x;
	}

	if (key == 'w' || key == 'W') {
		posicao.y = posicao.y + velocidade.y;
	}

	if (key == 's' || key == 'S') {
		posicao.y = posicao.y - velocidade.y;
	}

	if (key == 'q' || key == 'Q') {
		angulo = angulo + variacaoAngulo;
	}

	if (key == 'e' || key == 'E') {
		angulo = angulo - variacaoAngulo;
	}
}

void Objetos::movimentarInvertido(unsigned char key, int x, int y) {
	if (key == 27) {
		exit(0);
	}
	
	if (key == 'd' || key == 'D') {
		posicao.x = posicao.x - velocidade.x;
	}

	if (key == 'a' || key == 'A') {
		posicao.x = posicao.x + velocidade.x;
	}

	if (key == 'w' || key == 'W') {
		posicao.y = posicao.y - velocidade.y;
	}

	if (key == 's' || key == 'S') {
		posicao.y = posicao.y + velocidade.y;
	}

	if (key == 'q' || key == 'Q') {
		angulo = angulo + variacaoAngulo;
	}

	if (key == 'e' || key == 'E') {
		angulo = angulo - variacaoAngulo;
	}
}
