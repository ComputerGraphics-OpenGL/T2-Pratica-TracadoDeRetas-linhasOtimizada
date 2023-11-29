## Traçado de Curvas em Dispositivos Gráficos Matriciais

* O traçado de primitivas gráficas elementares, como segmentos de reta ou arcos de circunferência, requer a contrução de algoritmos capazes de determinar na matriz de pixels da superfície de exibição quais pixels devem ser alterados de forma a simular-se a aparência do elemento gráfico desejado. Estes algoritmos recebem o nome de Algoritmos de Conversão Matricial, por converterem em representação matricial elementos gráficos expressos em uma representação vetorial.

## Conversão Matricial de segmentos de reta.

Em (a) adotou-se o critério de selecionar-se os dois pixels imediatamente acima e abaixo do ponto de interseção do segmento com cada vertical, a menos quando o segmento passa por um pixel. Restrição: desta forma obtém-se linhas densas, como se o segmento fosse espesso.
em (b) o critério foi selecionar todos os pixels cujas coordenadas são obtidas arredondando-se os valores das coordenadas de um ponto do segmento. Restrição: com segmentos a 45 o critério produz resultados semelhantes ao anterior.

A conversão ilustrada em (c) foi obtida selecionando-se em cada vertical o pixel mais próximo do ponto de interseção do segmento com a reta vertical. Vantagens: aparência leve e continuidade.

Em (d) utilizou-se o mesmo critério, só que para as linhas horizontais. Restrição: descontinuidade.

Características Desejáveis para os Algoritmos de conversão Matricial de Segmentos de Retas.

1. Linearidade: os pixels traçados devem dar a aparência de que estão sobre uma reta. Isso é trivial no caso de segmentos paralelos aos eixos x ou y, ou com inclinação de 45 graus, mas não nos outros casos.

2. Precisão: os segmentos devem iniciar e terminar nos pontos especificados. Caso isso não ocorra, prequenos gaps podem surgir entre o final de um segmento e o início de outro.

3. Espessura (Densidade) uniforme: a densidade da linha é dada pelo número de pixels traçados dividido pelo comprimento da linha. Para manter a densidade constante, os pixels devem ser igualmente espaçados. A imagem do segmento não varia de intensidade ou espessura ao longo de sua extensão.

4. Intensidade independente da inclinação: para segmentos de diferentes inclinações.

5. Continuidade: a imagem não apresenta interrupções indesejáveis.

6. Rapidez no traçado dos segmentos.

Os algoritmos que vamos estudar usam o método incremental, que consiste em executar os cálculos iterativamente, mantendo um registro (ou memória) do progresso da computação a cada passo da iteração. Nesse método, começando por um dos extremos da linha, o próximo ponto é calculado e traçado até que o outro extremo seja atingido e traçado.

O problema da conversão matricial consiste essencialmente em ajustar uma curva, no caso, um segmento de reta, a qual é precisamente definida por coordenadas reais, a uma malha de coordenadas inteiras. Isso pode ser feito calculando as coordenadas reais (x_r, y_r), do próximo ponto na linha, e escolhendo na malha os pixels cujas coordenadas (x, y) mais se aproximam das coordenadas reais, obtidos por arredondamento ou truncamento.

## Critério adotado
Seja o segmento de reta definido por seus extremos (x_1, y_1) e (x_2, y_2).
Pode-se supor que este segmento está no 1º octante. Por quê?
Então as coordenadas respeitam as relações:
0 < x_1 < x_2
0 < y_1 < y_2
y_2 - y_1 < x_2 - x_1

Nestas condições o segmento de reta corta um número maior de linhas verticais do reticulado do que de horizontais e assim:

Critério de conversão: em cada vertical do retilado com abscissa entre x_1 e x_2 apenas o pixel mais próximo da interseção do segmento com a vertical faz parte da sua imagem.

Este critério aplicado a segmentos do 2º octante não produz resultados satisfatórios (tente fazê-lo), pois nesse caso o número de verticais que corta o segmento será menor que o de horizontais. Solução: para segmentos no 2º octante utilizar este critério só que trocando x com y e vertical por horizontal.

## Algoritmo:
Equação da reta: 
y = y_1 + a(x - x_1)
onde a = (y_2 - Y_1) / (x_2 - x_1)

Deta forma, basta que para cada vertical da grade entre x_1 e x_2, determinemos o inteiro mais próximo da ordenada correspondente da reta.

Exercício: 
 Elabore um algoritmo que 
desenhe a reta, de acordo com o 
critério provido anteriormente e 
com a equação da reta fornecida 
com relação ao segundo octante.

```C++
procedure linha(x1, y1, x2, y2, 
cor:integer);
var valor, x,y:integer;   a:real;
begin
       a:=(y2-y1)/(x2-x1);
           for x:=x1 to x2 do
       begin
            y := round( y1 + a * (x - x1) );
            write_pixel(x, y, cor);
       end;
end;

```

## Equação implicita da reta
(A) F(x,y) = ax + by + c = 0
dy = y2 - y1 e dx = x2 - x1
y = (dy/dx) x + B, B = 
1) y = ((y2 - y1) / (x2 - x1))x + B

2) y = y_1 + ((y2-y1)/(x2-x1))(x - x1)
y = y1 - ((y2-y1)/(x2-x1))x1 + ((y2-y1)/(x2-x1))x

B = y1 - ((y2-y1)/(x2-x1))x1

a = dy, b = dx, c = B.dx
(B)F(x, y) = dy . x - dx . y + B.dx = 0


## Algoritmo d "Ponto-Médio"
O algoritmo do ponto médio 
implementa uma versão do algoritmo 
de traçado de retas provido 
anteriormente utilizando-se somente 
operações com números inteiros.

O algoritmo assumos que a inclinação da linha está entre 0 e 1 (outras inclunações podem ser tratadas por simetria). O ponto (x1, y1) é o inferior esquerdo, e (x2, y2) é o superior direito.

Assumindo-se que o pixel que acabou de ser 
selecionado é  P

(x_p, y_p), e o próximo deve ser escolhido entre o pixel à direita (pixel E) e o pixel acima à direita (NE). Seja Q o ponto de interseção entre a reta e a coluna x = x_p + 1 da malha, e M o ponto intermediário entre os pixels E e NE. O que faz é observar de que lado da reta está o ponto M. É fácil verificar que se M está acima da reta, o pixel E está mais próximo da reta; se M está abaixo, NE está mais próximo.

Grade de pixels para o Algoritmo o Ponto Médio (M) e as escolhas E e NE.
Desta forma, o teste do ponto-médio permite a escolha do pixel mais próximo d areta. Além disso, o erro (a distância vertical entre o pixel escolhido e a linha) é sempre <= 1/2.
O que precisamos agora é um método para calcular de que lado da reta está o ponto M. Para isso, considere sua função implícita, F(x, y) = ax + by + c = 0. Se dy = y_2 - y_1, e dx = x_2 - x_1, a equação da reta em termos de sua inclinação pode ser escrita como:

y = (dy/dx)x + B
F(x, y) = dy.x - dx.y + B.dx = 0

Aqui, tem-se a = dy, b = -dx, e c = B.dx

É fácil verificar que F(x, y) = 0 sobre a linha, positiva para pontos abaixo dela, e negativa para pontos acima dela. Para o teste do ponto-médio, basta calcular F(M) = F(x_p + 1, y_p + 1/2) e verificar o seu sinal. Como a decisão será tomada com base no valor da função no ponto (x_p + 1, y_p + 1/2), definimos uma "variável de decisão" d = a(x_p + 1) + b(y_p + 1/2) + c. Se d > 0, escolhemos o pixel NE, se d < 0, escolhemos o pixel E: se d = 0 pode-se escolher qualquer um deles, por exemplo E.

É interessante verificar o que acontece com a localização de M e o valor de d no próximo ponto da reta. Ambos dependem, obviamente, da escolha de E ou NE. Se E for escolhido, M é incrementado de 1 na direção x. Assim,

d_new = F(x_p + 2, y_p + 1/2) = a(x_p + 2) + b(y_p + 1/2) + c

d_old = a(x_p + 1) + b(y_p + 1/2) + c


Subtraindo d_old de d_new para obter a diferença incremental, tem-se d_new = d_old + a.

Denominando DeltaE o incremento a ser adicionado depis da escolha de E; e deltaE = a = dy. Em outras palabras, pode-se derivar o valor da variável de decisão no próximo passo incrementalmente, a partir do seu valor atual, sem necessidade de calcular F(M) diretamente.

Se NE é escolhido, M é incrementado de 1 em ambas as direções, x e y. Portanto, substraindo d_old de d_new, tem-se d_new = d_old + a + b. Denominamos deltaNE o incremento a ser adicionado depois da escolha de NE; e deltaNE = a + b = dy - dx.

Resumindo a técnica incremental do ponto-médio.

A cada passo, o algoritmo escolhe entre 2 pixels, com base no sinal da variável de decisão calculada na iteração anterior; a seguir a variável de decisão é atualizada adicionando-se deltaE ou deltaNE ao valor anterior, dependendo do pixel escolhido.

Como o primeiro pixel corresponde ao ponto (x_1, y_1), pode-se calcular diretamente o valor inicial de d para escolher entre E e NE. O primeiro ponto-médio está em (x_1 + 1, y_1 + 1/2), e

F(x_1 + 1, y_1 + 1/2) = a(x_1 + 1) + b(y_1 + 1/2) + c = ax_1 + by_1 + c + a + b/2 = F(x_1, y_1) + a + b/2.

Como (x_1, y_1) é um ponto da reta, F(x_1, y_1) é 0; consequentemente d_start é dado por a + b/2 = dy - dx/2.
Usando d_start, escolhe-se o segundo pixel, e assim por diante. Para eliminar a fração em d_start, F é multiplicada por 2. Isto é:

F(x, y) = 2(ax + by + c). Isto multiplica cada constante e a variável de decisão por 2, mas não afeta o sinal da variável, que é o que interessa para o teste do ponto-médio.
A aritmética necessária para calcular d_new a cada passo é adição simples - nenhuma multiplicação é necessária (veja o algoritmo abaixo). Note que esta versão doa algoritmo funciona apenas para linhas com inclinação entre 0 e 1, mas a generalização não é difícil. A figura 3.7 mostra a reta que vai do ponto (5,8) ao ponto (9,11), traçada por este algoritmo. Os valores sucessivos de d são 2, 0, 6 e 4, resultantes da escolha de NE, E, NE e NE, respectivamente.

```c++
void inc_line(int x1, int y1, int x2, int y2, int color) {
    int dx, dy, inc E, incNE, d, x, y;

    dx = x2 - x1;
    dy = y2 - y1;
    d = 2 * dy - dx; /* Valor inicial de d */
    incE = 2 * dy; /* Incremento de E */
    incNE = 2 * (dy - dx); /* Incremento de NE */
    x = x1;
    y = y1;

    write_pixel(x, y, color);

    while (x < x2>) {
        if (d <= 0) {
            /* Escolhe E */
            d = d + incE;
            x++;
        } else {
            /* Escolher NE */
            d = d + incNE;
            x++;
            y++;
        } /* end if */
        write_pixel(x, y, color);
    } /* end while */
}/* end inc_line */
```


## Compilação

```shell
gcc -c transformacoes2D.c -lGL -lGLU -lglut -lm
gcc -o transformacoes2D transformacoes2D.c -lGL -lGLU -lglut -lm
./transformacoes2D
```

