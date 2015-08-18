#include<Windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

using namespace std; //para dizer que não precisa colocar namespace na frente do objeto criado por ela

void keyboard(unsigned char key, int x, int y) {
		if (key == 'q') {
			exit(0);
		}
		var = key;
	}
	
void drawRect(float x, float y, float weight, float height, float r, float g, float b){
  glColor(r, g, b);
  glVertex2d(x, y); // Linha 1
  glVertex2d(x, y + height); // Linha 2
  glVertex2d(x + weight, y + height);// Linha 3
  glVertex2d(x + weight, y); // Linha 4
}

void display(void){
	glClear(GL_COLOR_BUFFER_BIT);
 	//... outras definições
 	float xx;
 	float yy = yi; // y inicial da tela
 	glBegin(GL_QUADS);
 	for (int y=0; y < rows; y++) {
 	xx = xi; // x inicial da tela
 	for (int x = 0; x < cols; x++) {
 	// definir qual é cor (r,g,b)...
 	drawRect(xx, yy, w, h, r,g,b); // w e h são as dimensões do retângulo
 	xx += w; // xx de base para o primeiro vértice do próximo retângulo
 	}
 	yy += h; // yy de base para o primeiro vértice do próximo retângulo
	 }
    glEnd();
    glFlush(); // ou glutSwapBuffers();
 }

	void init(void){
		glClearColor(0.00, 0.0, 30.0, 0.0);

		/*  initialize viewing values  */
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0.5, 0.5, 0.5, 00.0, 00.0, 20.0);
		glViewport(350,350,500,500); // define pos e tamanho janela 
	}

int main(int argc, char** argv)
	{
		glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
		glutInitWindowSize(800, 400);
		glutInitWindowPosition(100, 100);
    glutCreateWindow ("Jogo das Cores");
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

}


 
