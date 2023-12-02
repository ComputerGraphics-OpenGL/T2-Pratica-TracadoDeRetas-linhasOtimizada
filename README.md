# Grupo 1 - CG
#### Universidade Federal de Goiás - Instituto de Informática
#### Disciplina: Computação Gráfica
#### Prof.ª: DELLER JAMES FERREIRA
#### Alunos: 	Matheus Lázaro Honório da Silva - 201801523
#### Gabriel Crispim de Siqueira - 201801496
#### Guilherme Araújo França - 202003569
#### Thais Gonçalves da Silva - 202003617
________________________________________________________________________________________


## Linha otimizada
Este é um programa em C que usa a biblioteca OpenGL para desenhar uma linha otimizada em uma janela. O programa usa o algoritmo do ponto médio, que é uma forma de traçar segmentos de reta em uma grade de pixels, usando apenas operações com números inteiros. Esse algoritmo evita o uso de divisões e multiplicações, que são mais custosas do que somas e subtrações, e reduz o erro de arredondamento. O algoritmo do ponto médio funciona para qualquer inclinação da reta, mas requer algumas adaptações dependendo do caso.

## Problema
O problema que o programa resolve é o de desenhar uma linha em uma janela usando OpenGL, de forma eficiente e precisa. O programa recebe como entrada as coordenadas dos pontos inicial e final da linha, e a cor da linha. O programa deve desenhar a linha na janela, usando o menor número possível de operações e minimizando o erro de arredondamento.

## Funções
### O programa usa as seguintes funções:

```linhaPontoMedio(int xInicial, int yInicial, int xFinal, int yFinal, int cor)```: Esta é a função que implementa o algoritmo do ponto médio para desenhar uma linha. Ela recebe como parâmetros as coordenadas dos pontos inicial e final da linha, e a cor da linha. Ela calcula a diferença entre as coordenadas x e y, os coeficientes da função implícita da reta, e o valor inicial da variável de decisão. Em seguida, ela entra em um loop que escolhe entre dois pixels candidatos a cada passo, com base no sinal da variável de decisão, e atualiza essa variável de acordo com a escolha feita. A cada passo, ela desenha um pixel na janela, usando a cor especificada.

```desenhar(void)```: Esta é a função que desenha uma cena simples com uma linha. Ela limpa o buffer de cor, chama a função linhaPontoMedio com alguns valores de exemplo, e força o desenho dos comandos.

```inicializar(void)```: Esta é a função que inicializa alguns parâmetros do OpenGL. Ela define a cor de fundo como preta, o modo de projeção como ortogonal, e o sistema de coordenadas como um quadrado de 250 x 250 pixels.

```main(int argc, char** argv)```: Esta é a função principal que cria a janela e entra no loop de eventos. Ela inicializa o GLUT, define o modo de display como simples e RGB, define o tamanho e a posição da janela, cria a janela com um título, chama a função de inicialização, define a função de desenho, e entra no loop de eventos.


## Compilação

```shell
gcc -c desenharLinhaOtimizada.c -lGL -lGLU -lglut -lm
gcc -o desenharLinhaOtimizada desenharLinhaOtimizada.c -lGL -lGLU -lglut -lm
./desenharLinhaOtimizada
```

