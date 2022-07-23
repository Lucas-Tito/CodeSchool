<p align="center">
  <img src="https://miro.medium.com/max/1400/1*uMpAuvIGRy9aTqREM3X-0w.jpeg" alt="header" width="50%" height="50%"/>
</p>


 <h1>Descrição</h1>

Este código implementa um algoitimo chamado Binary Search, estes são seus passos básicos:

+ Os elementos devem estar ordenados.
+ Começar com o elemento do meio no array.
+ se o valor buscado for encontrado neste, o programa retorna este índice do array.
+ Se não, caso o valor do elemento do meio seja maior que o valor buscado, o intervalo de busca é alterado para a metade inferior do vetor.
+ Caso o valor do elemento do meio seja menor que o valor buscado, o intervalo de busca é alterado para a metade superior do vetor.


<br> <br>
## Entrada
Na primeira linha será fornecido o número de elementos a serem armazenados e o número de elementos a serem buscados. <br>
Na segunda, espera-se os elementos a serem armazenados separados por espaço em uma única linha.<br>
Já na terceira, serão fornecidos os elementos a serem buscados separados por espaço em uma única linha.

ex: <br>
8 4<br>
2 3 4 8 10 45 54 72<br>
8 9 54 72<br>
1 3 2 5 4 <br>

## Saída
O programa imprime o número de iterações que o álgorítimo precisou para achar cada elemento.
