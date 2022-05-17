# BikeShapley
Geração de pares estáveis de usuários/bicicletas utilizando o algoritmo de Gale-Shapley e busca BFS em um mapa.

# Sobre o projeto
O programa lida com a situação fictícia de um sistema de aluguel de bicicletas em uma lagoa, assim os usuários desse sistema devem ser alocados às bicicletas de maneira ótima, gerando pares estáveis que respeitem as listas de preferência de cada usuário em conjunto com a distância de cada bicicleta. O projeto foi desenvolvido como forma de avaliação para a disciplina de Algoritmos I do curso de Ciência da Computação na UFMG.

# Passos que o programa deve seguir
- Receber um mapa da lagoa.
- Calcular as distâncias entre visitantes e bicicletas, de acordo com o mapa fornecido.
- Receber uma lista de preferencias de cada visitante indicando, para cada bicicleta disponível, o grau
de preferência do visitante por aquela bicicleta.
- Alocar visitantes a bicicletas, de forma que cada bicicleta esteja associada a exatamente um visitante,
e vice-versa
- Respeitar a seguinte condição de estabilidade: Se uma pessoa p1 foi alocada a uma bicicleta b1,
ambos os seguintes critérios deve ser satisfeitos:
  - Se há uma bicicleta b2 que p1 considere preferível em relaçãoo a b1, então há uma pessoa p2 mais
próxima de b2 para a qual b2 foi alocada.
  -  Se há uma pessoa p2 que está mais próxima de b1 do que p1, então p2 foi alocada para alguma
bicicleta b2 que ela considera preferível a b1.
- Regra de desempate por preferência: Se um visitante possui igual preferência por duas bicicletas,
então é priorizada aquela com o menor ID (Posição sequencial no arquivo de entrada).
- Regra de desempate por distãncia: Se dois visitantes estão equidistantes da mesma bicicleta, então
possui prioridade o visitante com o menor ID (Posição sequencial no arquivo de entrada).

# Arquivo de entrada
O programa lê um arquivo texto de entrada de forma que a primeira linha contém um valor inteiro indicando o número de visitantes e bicicletas, 1 ≤ V ≤ 10. A
segunda linha, por sua vez, contém dois valores inteiros separados por um espaçoo em branco, 1 ≤ N, M ≤ 1000, indicando as dimensões do mapa (N linhas, M colunas).
As próximas N linhas descrevem o mapa da região. Cada linha contém uma string de texto com exatamente M caracteres, podendo conter os seguintes caracteres:
* '*', indicando um trecho atravessável do mapa. Visitantes podem transitar por essa região sem problemas.
* '-', indicando um obstáculo no mapa. Visitantes não podem atravessar essa região, devendo contorná-la de alguma forma.
* Letras minúsculas de ’a’ até ’j’, indicando um visitante, onde o visitante ’a’ possui ID = 0, o visitante ’b’ possui ID = 1 e assim por diante. Suponha que um visitante possa atravessar espaços ocupados por outros visitantes.
* Números, de ’0’ até ’9’, indicando uma bicicleta.

Por fim, as próximas V linhas descrevem as preferências dos V visitantes. A i-ésima linha descreve as preferências do i-ésimo visitante (Lembrando que o visitante ’a’ é o primeiro visitante, ’b’ o segundo e assim por diante). Cada linha i, 1 ≤ i ≤ V , contém V valores pij , indicando que o visitante i atribuiu um
grau de preferência de pij à bicicleta j, 1 ≤ j ≤ V .

O sistema vem com 3 valores de input salvos na pasta input, por padrão é utilizado o input3, mas pode-se alterar a entrada do programa através do Makefile. Na linha 17 do Makefile se encontra o nome do arquivo de entrada:
```Makefile
INPUT = <NOME_ENTRADA.txt>
```
# Saída
O programa escreve na saída padrão os pares de Usuário / Bicicleta gerados. No padrão:

Usuário a Bicicleta relacionada

Usuário b Bicicleta relacionada

Até imprimir o par do último Usuário da entrada.

Na pasta input, juntamente com os arquivos de entrada, estão arquivos numerados "expected_out.txt" que descrevem a saída esperada para cada uma das entradas.

# Exemplo prático de entrada / saída

Tendo a figura a seguir como um exemplo de problema:

![image](https://user-images.githubusercontent.com/73205375/168915533-d9d0618f-6e40-4f70-ab80-19933ae85375.png)

A entrada respectiva para essa figura seria:

![image](https://user-images.githubusercontent.com/73205375/168915591-8141b647-473e-49b9-8a64-63244a48861e.png)

A saída respectiva para essa entrada é:

![image](https://user-images.githubusercontent.com/73205375/168915681-d52387fd-0d16-4d4b-b4b5-f3426e72d9de.png)

# Instruções de compilação e execução
Para executar o programa é necessário ter instalada a função "make" na máquina, além de um compilador C++. A maneira mais fácil para instalar o make em um sistema windows é utilizando o [Chocolatey](https://chocolatey.org/install). Após a instalação do Chocolatey, digite no terminal:
```
choco install make
```
Após a instalação do Make, para compilar o código e gerar o executável do programa digite no diretório do programa: ```make all```. Após compilar o código, para executá-lo digite ```make run```. Se o programa for executado com sucesso, a saída especificada deve ser impressa na saída padrão.

# Considerações finais
Para a análise assintótica das funções e um detalhamento maior da implementação, acesse a [documentação do projeto](https://github.com/JoaoP-Silva/BikeShapley/blob/main/BikeShapley_Documentacao.pdf). A execução deste trabalho foi importante para visualizar na prática a implementação do algoritmo de Gale Shapley e ser criativo para implementar o BFS em uma matriz, além de entender que pequenas mudanças no problema(como o mapa ter posições que não podem ser acessadas) podem mudar completamente a solução adotada. Sobre mudanças no projetom penso que talvez haja alguma maneira mais eficiente de inserir as pessoas encontradas de forma ordenada na lista, além de fazer com que as funções da geração das listas de preferência sejam métodos das respectivas classes, afim de deixar o main um pouco mais enxuto e diminuir a quantidade de arquivos headers.

## Autores

| [<img src="https://avatars.githubusercontent.com/u/73205375?v=4" width=115><br><sub>João Pedro Fernandes Silva</sub>](https://github.com/JoaoP-Silva)
