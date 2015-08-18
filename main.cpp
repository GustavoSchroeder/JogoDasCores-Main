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


 
