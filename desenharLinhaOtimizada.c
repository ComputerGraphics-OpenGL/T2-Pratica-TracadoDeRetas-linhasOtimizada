#include <GL/glut.h>
#include <stdlib.h>

// Função que desenha uma linha usando o algoritmo do ponto médio
void linhaPontoMedio(int xInicial, int yInicial, int xFinal, int yFinal, int R_RGB, int G_RGB, int B_RGB) {
    int diferencaX, diferencaY, a, b, c, decisao, x, y;

    diferencaX = abs(xFinal - xInicial); // Calcula a diferença entre as coordenadas x
    diferencaY = abs(yFinal - yInicial); // Calcula a diferença entre as coordenadas y
    a = diferencaY; // Coeficiente a da função implícita da reta: F(x, y) = a*x + b*y + c = 0
    b = -diferencaX; // Coeficiente b da função implícita da reta: F(x, y) = a*x + b*y + c = 0
    c = -yInicial * diferencaX + xInicial * diferencaY; // Coeficiente c da função implícita da reta: F(x, y) = a*x + b*y + c = 0
    decisao = 2 * a + b; // Valor inicial da variável de decisão: d = F(x + 1, y + 1/2)
    // A variável de decisão é usada para escolher entre E e NE, baseada na função implícita da reta
    // Ela é calculada no ponto médio entre E e NE, e atualizada a cada passo do algoritmo
    // Para mais detalhes, consulte o texto fornecido pelo usuário

    x = xInicial; // Coordenada x inicial
    y = yInicial; // Coordenada y inicial

    glColor3f(R_RGB, G_RGB, B_RGB); // Define a cor da linha
    glBegin(GL_POINTS); // Inicia o modo de desenho de pontos
    glVertex2i(x, y); // Desenha o primeiro ponto

    while (x < xFinal) { // Enquanto x não atinge o final da linha
        if (decisao < 0) {
            // Escolhe E
            decisao = decisao + 2 * a; // Atualiza a variável de decisão: d = d + deltaE = d + a
            x++; // Incrementa x
        } else {
            // Escolhe NE
            decisao = decisao + 2 * (a + b); // Atualiza a variável de decisão: d = d + deltaNE = d + a + b
            x++; // Incrementa x
            y++; // Incrementa y
        } 
        glVertex2i(x, y); // Desenha o próximo ponto
    } 
    glEnd(); // Finaliza o modo de desenho de pontos
}

// Função que desenha uma cena simples com uma linha
void desenhar(void) {
    glClear(GL_COLOR_BUFFER_BIT); // Limpa o buffer de cor
    linhaPontoMedio(50, 50, 200, 150, 1,1,1); // Desenha uma linha branca

    linhaPontoMedio(50, 5, 175, 125, 0,0,1); // Desenha uma linha azul

    linhaPontoMedio(55, 50, 150, 300, 0,1,0); // Desenha uma linha verde
    glFlush(); // Força o desenho dos comandos
}

// Função que inicializa alguns parâmetros do OpenGL
void inicializar(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0); // Define a cor de fundo como preta
    glMatrixMode(GL_PROJECTION); // Define o modo de projeção
    gluOrtho2D(0.0, 250.0, 0.0, 250.0); // Define o sistema de coordenadas
}

// Função principal que cria a janela e entra no loop de eventos
int main(int argc, char** argv) {
    glutInit(&argc, argv); // Inicializa o GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Define o modo de display
    glutInitWindowSize(250, 250); // Define o tamanho da janela
    glutInitWindowPosition(100, 100); // Define a posição da janela
    glutCreateWindow("Linha otimizada"); // Cria a janela com um título
    inicializar(); // Chama a função de inicialização
    glutDisplayFunc(desenhar); // Define a função de desenho
    glutMainLoop(); // Entra no loop de eventos
    return 0;
}