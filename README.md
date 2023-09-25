# Criação de Processos no Linux

Os processos são as unidades fundamentais de execução de programas nos sistemas computacionais. Eles consistem em códigos e dados, carregados na memória principal e vinculados com uma estrutura de dados chamada de bloco de controle de processos ou bloco descrito de processos. É através desta estrutura que o sistema operacional consegue realizar todas as funções de gerenciamento que são necessárias para a execução eficiente de um determinado programa ou aplicação. 

Os processos são criados a partir de outros processos, estabelecendo uma relação de “processo pai” e “processo filho”, que fundamenta uma árvore de processos mantida pelo sistema. A criação de processos é uma prerrogativa dos sistemas operacionais. Eles os fazem através de chamadas de sistema, cuja especificação depende do tipo de interface de programação de aplicações (API) condizente com o sistema. Por exemplo, no caso do Linux, e de outros sistemas operacionais que têm uma derivação do Unix, a API usada é a POSIX.

A chamada de sistema POSIX para a criação de um processo filho é a fork(). Esta função cria uma imagem do processo pai em outro espaço de endereçamento da memória, e com outro descritor de processo. Logo, tratam-se de dois processos diferentes. 

O valor retornado pela função fork() tem valores diferentes para os processos criador e criado. Para o processo pai, a função retorna o identificador do processo filho. Para o processo filho, a função retorna o valor zero. Isto permite elaborar um código que, por meio de estruturas de decisão (if-else, por exemplo), decida que quem execute seja processo pai ou processo filho. 

Por fim, por razões de sincronização, o processo pai deve executar a chamada de sistema wait(), que é uma função que irá bloquear o processo pai até que o processo filho encerre sua execução.

## Problema a ser resolvido

Considerando os códigos-fontes, mais expecificamente os arquivos “estrutura fundamental (criação de processos)” e “Série de Fibonacci (arquivo fonte)”, foi elaborado um programa, em linguagem C/C++, para sistemas Linux, em que um processo recebe um número inteiro positivo (total de termos da série de Fibonacci), cria um processo filho e se bloqueis através da função wait(). O processo filho criado deve, então, a partir do total de termos da série de Fibonacci, gerar e exibir estes termos, finalizando, assim, sua execução.

## Execução

![image](https://github.com/quelita2/creating-linux-processes/assets/61879771/4d134b16-5272-4960-8bc2-7aeffd98822e)


---
<div align="center">
  Sistema Operacional (DCA0108)

  Departamento de Engenharia de Computação e Automação (DCA)
  
  Universidade Federal do Rio Grande do Norte (UFRN)
</div>
