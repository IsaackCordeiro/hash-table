# Tabela Hash
---

#### Conceitos gerais
* Também conhecidas como tabelas de “indexação” ou de
“espalhamento”
* É uma generalização da ideia de “array”
* Utiliza uma função para espalhar os elementos que queremos
armazenar na tabela
* O espalhamento faz com que os elementos fiquem dispersos de
forma não ordenada dentro do “array” que define a tabela
* Função de hashing
* Função que espalha os elementos na tabela

#### Vantagens
* Alta eficiência na operação de busca
* Tempo de busca é praticamente independente do número de
“chaves” armazenadas na tabela
* Implementação simples

#### Desvantagens
* Alto custo para recuperar os elementos da tabela ordenados
pela “chave”. Nesse caso, é preciso ordenar a tabela
* Pior caso é “O(N)”, sendo “N” o tamanho da tabela: alto número
de “colisões”