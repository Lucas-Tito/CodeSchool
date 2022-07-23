<h1 align="center">Descrição</h1>

<p align="center">
Dado um vetor A de n inteiros. Compute o valor prox_maior(X) definido da seguinte maneira:

prox_maior(i) : j é o menor índice j tal que i < j < n e A[j] > A[i].

Você precisa calcular o prox_maior para cada índice i do vetor A para 0 <= i < n. Se tal número não existe, atribua o valor -1.

Por exemplo, considere o vetor A = [3,7,1,7,8,4,5,2], temos os seguintes valores:
</p>

<br> <br>
## Entrada
A primeira linha da entrada contém um inteiro N denotando o tamanho do vetor A. Cada uma das N linhas seguintes contém um inteiro onde o inteiro na i-ésima linha denota A[i].

ex: <br>
8 <br>
3 <br>
7 <br>
1 <br>
7 <br>
8 <br>
4 <br>
5 <br>
2 <br>

## Saída
O programa imprime N números separados por espaço em uma única linha, onde o i-ésimo inteiro denota o prox_maior(i).
