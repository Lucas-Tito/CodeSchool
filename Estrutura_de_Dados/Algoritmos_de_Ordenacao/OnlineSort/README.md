<h1>Descrição</h1>


Um algoritmo é dito online quando ele recebe um fluxo de dados como entrada e precisa tomar decisões durante o processo sem a necessidade de saber as solicitações futuras. A aluna Larissa não entendeu muito bem esse conceito então o professor Insertionildo propôs o seguinte desafio para Larissa.

O programa precisa processar dois tipos operações:
+ A operação do tipo 1 recebe um novo elemento do vetor.
+ A operação do tipo 2 quer saber qual é o i-ésimo elemento no vetor ordenado formado com elementos já recebidos.<br><br>

Note que o algoritmo precisa atender as operações durante o processo.


<br> <br>
## Entrada
A primeira linha da entrada contém um inteiro representando o número de requisições que o seu programa deve responder. As seguintes N linhas contém um inteiro O indicando a operação a ser realizada. Se Operação = 1, então a linha contém mais um inteiro A representando o número adicionado no vetor. Se Operação = 2, então a linha contém mais um inteiro II indicando qual é a posição desejada no vetor ordenado.

ex: <br>
10<br>
1 2<br>
1 4<br>
1 3<br>
2 0<br>
1 5<br>
2 1<br>
2 0<br>
1 1<br>
1 4<br>
2 3<br>

## Saída
O programa imprime o resultado das operações do tipo 2.
