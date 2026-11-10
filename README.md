Explicação do código
Visão geral

O programa é um menu em C que resolve quatro problemas de análise combinatória: Triângulo de Pascal, Arranjo, Permutação Simples e Combinação. O usuário escolhe uma opção, digita os valores pedidos, vê o resultado e volta ao menu, até digitar 0 para sair.

Estrutura do programa

O código está dividido em duas partes: as funções, que fazem os cálculos, e a main, que cuida do menu e da interação com o usuário.

As funções

fatorial(int n)
Calcula n! multiplicando todos os números de 2 até n. Começa com r = 1 e, a cada volta do for, multiplica r por i. Serve para a Permutação Simples, onde P(n) = n!. Com int, só funciona até n = 12, porque 13! ultrapassa o maior valor que um int guarda.

arranjo(int n, int p)
Calcula A(n, p) = n! / (n − p)!. Em vez de calcular dois fatoriais, o código multiplica só os p primeiros termos: n × (n−1) × ... × (n−p+1). O resultado é o mesmo e a conta é menor, o que também evita estouro desnecessário.

combinacao(int n, int p)
Calcula C(n, p) = n! / (p! × (n−p)!). Dois detalhes importantes:

Se p > n - p, troca p por n - p, pois C(n, p) = C(n, n−p). Isso diminui o número de voltas do laço.
Dentro do laço, multiplica antes de dividir (r * (n - p + i) / i). Fazendo nessa ordem, a divisão sempre dá um número inteiro exato, sem perder casas decimais.

trianguloPascal(int linhas)
Imprime o triângulo linha por linha. Cada elemento da linha i, coluna j, vale C(i, j), então a função apenas reutiliza combinacao. Os dois for internos fazem o seguinte:

o primeiro imprime espaços para centralizar o triângulo;
o segundo imprime os números da linha, usando %4d para que cada um ocupe 4 posições e fiquem alinhados.
A função main

Menu com do...while
O menu fica dentro de um do { ... } while (opcao != 0);. Isso garante que ele apareça pelo menos uma vez e se repita até o usuário escolher 0.

Escolha com switch
O valor de opcao decide qual case executar:

Caso 1: pede o número de linhas e chama trianguloPascal.
Caso 2: pede n e p e mostra A(n, p).
Caso 3: pede n e mostra n!.
Caso 4: pede n e p e mostra C(n, p).
Caso 0: mostra “Saindo...” e o laço termina.
default: qualquer outro número mostra “Opcao invalida!”.

O break no fim de cada caso impede que o programa continue executando o caso seguinte.

Validações

Antes de calcular, o programa verifica se os valores fazem sentido:

Para arranjo e combinação, n e p não podem ser negativos e p não pode ser maior que n.
Para o triângulo, o número de linhas precisa ser pelo menos 1.
Para a permutação, n deve estar entre 0 e 12 (limite do int).

Se algum valor for inválido, o programa avisa e volta ao menu.

Limitação

Como o programa usa int, resultados muito grandes estouram e aparecem errados. Para trabalhar com valores maiores, bastaria trocar int por long long (e %d por %lld).


NOME DO ALUNO: PEDRO ZOCAL
RA : 122547
