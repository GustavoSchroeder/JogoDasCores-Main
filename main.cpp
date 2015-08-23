#include<Windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <cstdio>
using namespace std; //para dizer que não precisa colocar namespace na frente do objeto criado por ela

int colors[32][32];
char chave;
int botao;
int estadoBotao;
int posicaoX;
int posicaoY;

void retangulo(boolean visibilidade, int x, int y) {
	boolean visivel = visibilidade;
	int posX = x;
	int posY = y;
}

void drawRect(float x, float y, float weight, float height, float r, float g, float b, boolean visib, int xPos, int yPos) {
	glColor3f(r, g, b);
	printf("Drawing...");
	glBegin(GL_QUADS);
	glVertex2f(x, y);
	glVertex2f(x, y + height);
	glVertex2f(x + weight, y + height);
	glVertex2f(x + weight, y);
	retangulo(visib, xPos, yPos);
	glEnd();
	glutSwapBuffers();
}

void mouse(int button, int state, int x, int y) {
	botao = button;
	estadoBotao = state;
	posicaoX = x;
	posicaoY = -y;
}

void keyboard(unsigned char key, int x, int y) {
	chave = key;
	//e a posição de tela atual (x,y) do mouse.
	//Não é coordenada do OpenGL, portanto, devemos converter o
	//clique de tela em coordenada do OpenGL. Dica: y é invertido.
	
	// width é a largura  janela em pixels (ver glViewport)
	float xx = x / (float)500; // normaliza click: xx = [0..1)
								 // transformar xx em coordenadas da janela OpenGL:
								 // xi é a coordenada inicial da janela e w = xf - xi (largura da janela)
								 // Veja as definições de janela no comando glOrtho
	xx = xix + xx * 500; // xx está em coordenadas do OpenGL (xx=[xi..xf));

}
void reshape(int w, int h) {
	glViewport(0, 0, w, h);
}



void display(void) {
	float xx = 0;  //x inicial da tela
	float yy = 0; // y inicial da tela
	srand(time(NULL));
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	for (int i = 0; i < 32; i++) {
		for (int j = 0; j < 32; j++) {
		drawRect(-i, j, i + 0.10, j - 0.15, (rand() % 256), (rand() % 256), (rand() % 256), true, 1, 1);
		}
	}
}
void init(void) {
	glClearColor(0.00, 0.0, 30.0, 0.0);

	/*  initialize viewing values  */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(1.00, 1.00, 1.00, 1.00, 00.0, 00.0);
	glViewport(350, 350, 500, 500); // define pos e tamanho janela 
}

int main(int argc, char** argv)
{
	// inicialização da GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Jogo das Cores");
	init();
	// funções de call-back para a GLUT. Devemos passar o nome da função que
	// criamos para a GLUT. Os parâmetros estar no padrão (veja slides)
	glutDisplayFunc(display); // função de desenho
	glutReshapeFunc(reshape); // tratamento de redimensionamento da janela
	glutKeyboardFunc(keyboard); // tratamento de teclado
	glutMouseFunc(mouse); // tratamento de mouse
						  // inicializações do programa
	init();
	// Inicia loop do programa, o main loop
	glutMainLoop();
	return 0;
}
