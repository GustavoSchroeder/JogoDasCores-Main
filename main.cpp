#include<Windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

using namespace std; //para dizer que não precisa colocar namespace na frente do objeto criado por ela

void desenhaRetangulo(float x, float y, float weight, float height, float r, float g, float b){
  glColor(r, g, b);
  glVertex2d(x, y); // Linha 1
  glVertex2d(x, y + height); // Linha 2
  glVertex2d(x + weight, y + height);// Linha 3
  glVertex2d(x + weight, y); // Linha 4
}

void drawRect(float x, float y, float weight, float height, float r, float g, float b){
  desenhaRetangulo(x, y, w, h, r, g, b);
}

void mouse(int button, int state, int x, int y){
 //faz alguma coisa dado que algum botão (button) foi pressionado,
 //um estado do botão (state) e a posição de tela (x,y) que foi clicada.
 //Não é coordenada do OpenGL, portanto, devemos converter o
 //clique de tela em coordenada do OpenGL. Dica: y é invertido.
 
 // width é a largura da janela em pixels (ver glViewport)
 float xx = x / (float) width; // normaliza click: xx = [0..1)
 // transformar xx em coordenadas da janela OpenGL:
 // xi é a coordenada inicial da janela e w = xf - xi (largura da janela)
 // Veja as definições de janela no comando glOrtho
 xx = xi + xx * w; // xx está em coordenadas do OpenGL (xx=[xi..xf));
 // para o y temos que considerar que o sistema OpenGL o y cresce para cima
 // e no da tela (que veio o click) o y cresce para baixo. Então, devemos
 // primeiro inverter o y e depois convertê-lo para janela OpenGL
 // height é a altura da janela em pixels (ver glViewport)
 y = height - y;
 float yy = y / (float) height; // normaliza click: yy = [0..1)
 // transformar xx em coordenadas da janela OpenGL:
 // xi é a coordenada inicial da janela e h = yf - yi (altura da janela)
 // Veja as definições de janela no comando glOrtho
 yy = yi + yy * h; // yy está em coordenadas do OpenGL (yy=[yi..yf));
}
void keyboard(unsigned char key, int x, int y){
 //faz alguma coisa dado que alguma tecla (key) foi pressionada,
 //e a posição de tela atual (x,y) do mouse.
 //Não é coordenada do OpenGL, portanto, devemos converter o
 //clique de tela em coordenada do OpenGL. Dica: y é invertido.
}
void reshape(int w, int h) {
 // redefinição da viewport e de proporções da tela, quando o usuário
 // aumenta ou diminui a tela do programa.
 // w e h são as novas dimensões da janela
 glViewport (0, 0, width=w, height=h);
}

/*
float drawText(char *msg, int msgLength, float x, float y, float charWidth){
 for (int i = 0; i < msgLength; i++) {
 glRasterPos2d(x, y);
 // A fonte, neste caso, é uma constante da GLUT. Que pode ser um param
 glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *(msg++)); // inc ponteiro msg
 x += charWidth;
 }
 return x;
}
*/

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


 
