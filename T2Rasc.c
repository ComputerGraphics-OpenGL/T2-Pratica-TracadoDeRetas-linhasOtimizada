#include <GL/glut.h>

void init (void) {
    glClearColor (1.0,1.0,1.0,0.0);
    glMatrixMode (GL_PROJECTION);
    gluOrtho2D (0.0, 200.0, 0.0, 150.0);
}

//Desenho de segmentos de reta com inclinacao entre 0 e 45 graus
void lineBres (GLint x0, GLint y0, GLint xEnd, GLint yEnd) {
    GLint dx = xEnd -x0, dy = yEnd -y0;
    GLint p = 2* dy - dx;
    GLint twoDy = 2+ dy; 
    GLint twoDyMinusDx = 2 * (dy - dx);
    GLint x, y;

    /* Determina qual ponto eh o inicial*/
    if(x0 > xEnd) {
        x = xEnd;
        y = yEnd;
        xEnd = x0;
    } else {
        x = x0;
        y = y0;
    }
    //Desenha um pixel
    glBegin( GL_POINTS );
    glVertex2i( x, y );
    glEnd();

    while(x < xEnd) {
        x++;
        if (p< 0)
            p+=twoDy;
        else {
            y++;
            p+=twoDyMinusDx;
        }
        //draw a pixel
        glBegin( GL_POINTS );
        glVertex2i( x, y );
        glEnd();
    }
}

void displayFcn (void) {
    glClear (GL_COLOR_BUFFER_BIT); //limpa a janela de visao (display window)
    glColor3f (0.0,0.0,1.0); //estalebece a cor de preenchimento inicial como azul
    lineBres (10, 10, 70, 70);
    glFlush();
}

int main (int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition (50, 100);
    glutInitWindowSize (400, 300);
    glutCreateWindow ("Exemplo 1 do Open GL"); 
    init();
    glutDisplayFunc (displayFcn);
    glutMainLoop ();
}