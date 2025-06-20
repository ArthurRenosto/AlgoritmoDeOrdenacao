## Algoritmos de Ordenação em C

Este projeto implementa diferentes algoritmos de ordenação em linguagem C, com foco no funcionamento do **Insertion Sort** e do **Merge Sort**, tanto em **ordem crescente** quanto **decrescente**. O projeto também explora o uso de **ponteiros**, **alocação dinâmica de memória** e **listas encadeadas** para reforçar conceitos de estruturas dinâmicas em C. É possível observar a ordenação passo a passo, útil para fins educacionais.

## 📁 Estrutura do Projeto

```
AlgoritmosOrdenacao/
├── CMakeLists.txt
├── main.c
├── funcoes/
│   ├── insertion_sort/
│   │   ├── insertion_sort.c
│   │   └── insertion_sort.h
│   ├── merge_sort/
│   │   ├── merge_sort.c
│   │   └── merge_sort.h
│   ├── lista_encadeada.c
│   └── lista_encadeada.h
```

## 🔧 Algoritmos Implementados

- [x] Insertion Sort Crescente
- [x] Insertion Sort Decrescente
- [x] Merge Sort Crescente
- [x] Merge Sort Decrescente
- [x] Insertion Sort Crescente (Lista Encadeada)
- [x] Insertion Sort Decrescente (Lista Encadeada)
- [x] Merge Sort Crescente (Lista Encadeada)
- [x] Merge Sort Decrescente (Lista Encadeada)

## 💡 Funcionalidades Didáticas
- Visualização passo a passo da ordenação
- Uso de ponteiros e alocação dinâmica de memória
- Implementação e manipulação de listas encadeadas
- Menu interativo para escolha do algoritmo e tipo de estrutura

## 🚀 Como executar

### Pré-requisitos
- [CLion](https://www.jetbrains.com/clion/) (recomendado) ou qualquer IDE/CMake que suporte C.
- GCC (caso esteja usando terminal/linha de comando)

### Compilando no CLion

1. Clone o repositório:
   ```bash
   git clone https://github.com/seu-usuario/AlgoritmosOrdenacao.git
   ```
2. Abra o projeto no CLion. O CMake deve reconhecer automaticamente os arquivos. (Caso não reconheça, apague o cmake.cache e a pasta cmake-build-debug, então peça para o CLion gerar novamente)
3. Selecione a opção de build e execute como uma CMake Application.
4. Caso veja erro de undefined reference, verifique se todos os arquivos .c estão incluídos em CMakeLists.txt.

### Executando via terminal

```bash
gcc main.c funcoes/insertion_sort/insertion_sort.c funcoes/merge_sort/merge_sort.c funcoes/lista_encadeada.c -o ordenar
./ordenar
```

## 📊 Exemplo de Execução

```
Qual metodo de ordenacao gostaria de usar ?
0 - Sair do Programa.
1 - Insertion Sort Crescente.
2 - Insertion Sort Decrescente.
3 - Merge Sort Crescente.
4 - Merge Sort Decrescente.
5 - Insertion Sort Crescente (Lista Encadeada).
6 - Insertion Sort Decrescente (Lista Encadeada).
7 - Merge Sort Crescente (Lista Encadeada).
8 - Merge Sort Decrescente (Lista Encadeada).
1

Array inicial:
 1 -  342  754  123  908  ...

**Insertion Sort Crescente**

Passo 1: 342 754 ...
Passo 2: 123 342 754 ...

Matriz com linhas ordenadas:
 1 - 123 342 754 ...
```

---

> Projeto desenvolvido para fins didáticos, reforçando conceitos de manipulação eficiente de dados em C.

