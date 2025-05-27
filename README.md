## Algoritmos de Ordenação em C

Este projeto implementa diferentes algoritmos de ordenação em linguagem C, com foco no funcionamento do **Insertion Sort** e do **Merge Sort**, tanto em **ordem crescente** quanto **decrescente**. É possível observar a ordenação passo a passo, útil para fins educacionais.

## 📁 Estrutura do Projeto

<p>AlgoritmosOrdenacao/</p>
<p├── CMakeLists.txt</p>
<p├── main.c</p>
<p├── funcoes/</p>
<p│ ├── insertion_sort/</p>
<p│ │ ├── insertion_sort.c</p>
<p│ │ └── insertion_sort.h</p>
<p│ └── merge_sort/</p>
<p│ ├── merge_sort.c</p>
<p│ └── merge_sort.h</p>

## 🔧 Algoritmos Implementados

- [x] Insertion Sort Crescente
- [x] Insertion Sort Decrescente
- [x] Merge Sort Crescente
- [x] Merge Sort Decrescente

## 🚀 Como executar

### Pré-requisitos
- [CLion](https://www.jetbrains.com/clion/) (recomendado) ou qualquer IDE/CMake que suporte C.
- GCC (caso esteja usando terminal/linha de comando)

### Compilando no CLion

1. Clone o repositório:
   ```bash
   git clone https://github.com/seu-usuario/AlgoritmosOrdenacao.git
Abra o projeto no CLion. O CMake deve reconhecer automaticamente os arquivos. (Caso não reconhecer apaga o cmake.text e o debug, ae pede pra ele criar um novo)

Selecione a opção de build e execute como uma CMake Application.

Caso veja erro de undefined reference, verifique se todos os arquivos .c estão incluídos em CMakeLists.txt.

Executando via terminal
bash

gcc main.c funcoes/insertion_sort/insertion_sort.c funcoes/merge_sort/merge_sort.c -o ordenar
./ordenar

📊 Exemplo de Execução

Qual metodo de ordenacao gostaria de usar ?
0 - Sair do Programa.
1 - Insertion Sort Crescente.
2 - Insertion Sort Decrescente.
3 - Merge Sort Crescente.
4 - Merge Sort Decrescente.
1

Array inicial:
 1 -  342  754  123  908  ...

**Insertion Sort Crescente**

Passo 1: 342 754 ...
Passo 2: 123 342 754 ...

Matriz com linhas ordenadas:
 1 - 123 342 754 ...
