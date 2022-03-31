# Eliminação de Gauss com pivoteamento parcial
  Eliminação de Gauss com pivoteamento parcial é um método direto para resolver o sistema de equações lineares.
  Neste método, usamos o pivoteamento parcial, ou seja, é escolhido o elemento pivô que é o valor mais alto na coluna após isso é realizado a troca de linhas para posicionar o maior valor na diagonal principal
Após isso da para usar o método normal de Eliminação de Gauss para transformar a Matriz Aumentada na matriz triangular superior.

### Vantagem em relação a eliminação normal
  O método de eliminação gaussiana é suscetível a propagação dos erros de arredondamento, em particular, quando os pivôs são números próximos de zero pois pivôs pequenos geram multiplicadores grandes, que
aumentam os erros de arredondamento e também pode ocorrer uma indeterminação caso o pivo seja 0. Isto pode ser mitigado com o chamado pivotamento parcial 
### Exemplo 1
4     5     2     2     
3     1     5     5     
9     2     4     6  


##### como o elemento de maior modulo da primeira coluna é 9 e está na linha 3 é necessário realizar a troca da linha 1 pela linha 3

9     2     4     6     
3     1     5     5     
4     5     2     2 

##### Após isso pode ser realizada o escalonamento normalmente 
9     2     4     6     
0     0.333333     3.66667     3     
0     4.11111     0.222222     -0.666667 

##### como o elemento de maior modulo da segunda coluna é 4.11111 e está na linha 3 é necessário realizar a troca da linha 2 pela linha 3

9     2     4     6     
0     4.11111     0.222222     -0.666667     
0     0.333333     3.66667     3  

##### Após isso pode ser realizada o escalonamento normalmente

9     2     4     6     
0     4.11111     0.222222     -0.666667     
0     0     3.64865     3.05405     

 x1º = 0.340741
 
 x2º = -0.207407
 
 x3º = 0.837037

### Exemplo 2
0     1     4     1     
1     0     5     4     
7     4     0     2

##### como o elemento de maior modulo da primeira coluna é 7 e está na linha 3 é necessário realizar a troca da linha 1 pela linha 3

7     4     0     2 
1     0     5     4
0     1     4     1     

##### Após isso pode ser realizada o escalonamento normalmente

7     4     0     2     
0     -0.571429     5     3.71429     
0     1     4     1     
##### como o elemento de maior modulo da segunda coluna é 1 e está na linha 3 é necessário realizar a troca da linha 2 pela linha 3

7     4     0     2     
0     1     4     1     
0     -0.571429     5     3.71429  

##### Após isso pode ser realizada o escalonamento normalmente
7     4     0     2     
0     1     4     1     
0     0     7.28571     4.28571   

 x1º = 1.05882
 
 x2º = -1.35294
 
 x3º = 0.588235

