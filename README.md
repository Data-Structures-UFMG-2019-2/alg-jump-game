
# Jump Game

O jogo do pulo gira em torno de um problema de busca em grafos direcionados sem pesos. A partir desse grafo teremos um vértice de destino v<sub>f</sub> e um conjunto de tamanho k de vértices de origem R =  {r<sub>0</sub>,r<sub>1</sub>...r<sub>k−1</sub>}. O objetivo do algoritmo é, para cada vértice de origem, queremos encontrar o caminho mais rápido ao destino de forma eficiente e em tempo hábil.

## Descrição

O problema se desenrola da seguinte forma: dado um tabuleiro, jogadores e suas posições iniciais, atingir a última casa do tabuleiro (em um tabuleiro de tamanho MxN, essa seria a casa N −1xM −1 ). O tabuleiro pode conter qualquer número de dimensões, dependendo do modo do jogo e da realidade em que está inserido. Neste trabalho iremos abordar o modo bidimensional do jogo. Cada célula do tabuleiro contém um número que informa quantas casas o jogador deve pular partindo dela. Note que é o número exato de casas, e não o máximo partindo dela. O tabuleiro possui números inteiros positivos, e pode conter casas com o número zero (no caso do número da casa ser um zero, o jogador nunca consegue sair dela).

Os personagens movimentam-se apenas em sentidos paralelos aos limites do tabuleiro. No caso de um tabuleiro bidimensional, por exemplo, o personagem só pode andar nas direções x ou y, ou seja, movimentos diagonais não são permitidos. Além disso, o movimento pode se dar em qualquer sentido, desde que seguindo a restrição anterior. Novamente, no caso bidimensional, o personagem pode se movimentar nas direções +x, -x, +y ou -y. 

A ordem de jogadas e a casa inicial dos jogadores é definida no começo do jogo. No nosso caso, essa ordem e as casas iniciais serão dadas como entrada do problema.

Definidas as posições iniciais, vamos começar o jogo. Seguindo a ordem posteriormente sorteada, cada jogador pula o número de casas escrito na sua posição, em qualquer sentido permitido e desejado. A ordem de jogadas nas rodadas seguintes é definida pelo tamanho do pulo anterior. A regra é que tem maior prioridade aquele que pulou a menor quantidade de casas na rodada anterior e, em caso de empate, tem prioridade o jogador que jogou antes na primeira rodada.

O jogo pode terminar de duas maneiras:
* A vitória de algum jogador
* A impossibilidade de vitória

No primeiro caso, o jogo termina quando o primeiro jogador atinge a última casa do tabuleiro. Já no segundo caso, o jogo acaba quando fica definido que nenhum jogador conseguirá vencer nunca o jogo (jogo sem vencedores). Um jogo sem vencedores pode ocorrer quando nenhum jogador consegue chegar na ultima posição do tabuleiro. Isso pode acontecer ao cair em uma casa marcada com o número 0 (e ele não conseguiria sair de lá), ou ao ficar rodando sempre pelas mesmas casas, sem conseguir sair delas.

## Compilação e execução

O makefile preparado para a execução do código tem as seguintes opções:

* make: Compila os arquivos de código fonte e armazena a saída da compilação em
uma pasta “./build/”.
* make run: Executa o arquivo gerado pela compilação.
* make mem: Executa o arquivo gerado pela compilação em modo de depuração de memória, assim podemos nos certificar que não existe nenhum vazamento
acontecendo durante a execução.
* make test: Executa os script de testes.
* make time: Gera um conjunto de entradas aleatórias, executa o algoritmo para cada uma delas e registra o tempo no arquivo ```./output/time_log.csv```
* make clean: Limpa a pasta contendo as saídas da compilação.