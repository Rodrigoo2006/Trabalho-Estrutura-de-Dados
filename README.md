# Sistema de Backup de Arquivos

Projeto academico desenvolvido para a disciplina de Estrutura de Dados do curso de Analise e Desenvolvimento de Sistemas (ADS) da UniRuy Wyden.

## Aluno

- Nome: Rodrigo Santos Araujo
- Matricula: 202503356751
- Curso: Analise e Desenvolvimento de Sistemas (ADS)
- Instituicao: UniRuy Wyden
- Local: Salvador - BA
- Ano: 2026

## Situacao-Problema

Em ambientes de desenvolvimento de software e edicao continua de documentos, um mesmo arquivo sofre diversas alteracoes ao longo do dia. Sistemas simples de copia acabam sobrescrevendo o arquivo antigo sem manter um historico organizado, fazendo com que versoes anteriores sejam perdidas em caso de erro ou corrupcao.

## Solucao Proposta

Foi desenvolvido um prototipo funcional de Sistema de Backup de Arquivos em linguagem C utilizando Estruturas de Dados Lineares para cadastrar arquivos, organizar alteracoes pendentes em fila, salvar versoes de backup, consultar o historico e restaurar o ultimo estado salvo. Alem do codigo principal em C, o repositorio inclui um prototipo visual simplificado em HTML/JavaScript focado na demonstracao da Pilha (LIFO) no navegador.

## Estruturas de Dados Utilizadas

### 1. Pilha (Stack - LIFO) - Estrutura Principal
Opera no principio LIFO (Last In, First Out - o ultimo a entrar e o primeiro a sair). Armazena o historico de versoes de backup, mantendo a versao mais recente sempre no topo para restauracao imediata.

- Operacoes: empilhar nova versao (`criarBackup` / Push), restaurar a ultima versao (`restaurarBackup` / Pop) e exibir historico (`consultarHistorico`).
- Vantagens: insercao e remocao em tempo constante `O(1)`, implementacao simples e ordem cronologica reversa natural.
- Limitacoes: acesso restrito ao topo, nao sendo pratica para acessar diretamente versoes antigas no meio da pilha.
- Impacto na solucao: garante rapidez na reversao de alteracoes incorretas.

### 2. Fila (Queue - FIFO)
Opera no principio FIFO (First In, First Out - o primeiro a entrar e o primeiro a sair). Organiza os arquivos cadastrados ou modificados que aguardam processamento em lote antes de serem gravados na pilha de historico.

- Operacoes: enfileirar solicitacao (`enfileirarBackup` / Enqueue) e processar fila (`processarFila` / Dequeue).
- Vantagens: respeita a ordem de chegada das alteracoes com custo `O(1)` na insercao e remocao.
- Limitacoes: nao permite acesso direto a versao mais recente, sendo inadequada como historico de restauracao.
- Impacto na solucao: separa o registro da modificacao do processamento dos backups pendentes.

### 3. Lista Encadeada
Formada por nos conectados dinamicamente por ponteiros. Gerencia o catalogo geral de arquivos monitorados pelo sistema, armazenando nome, ultima alteracao e numero de revisoes.

- Operacoes: cadastrar ou atualizar arquivo (`cadastrarArquivo`), busca sequencial por nome e listagem (`listarArquivos`).
- Vantagens: alocacao dinamica de memoria sem tamanho fixo e insercao em `O(1)` no inicio.
- Limitacoes: busca sequencial com custo `O(n)` e uso extra de memoria para ponteiros.
- Impacto na solucao: permite gerenciar varios arquivos de forma flexivel junto com a fila e a pilha.

## Comparacao entre as Estruturas

| Criterio | Pilha (Stack) | Fila (Queue) | Lista Encadeada |
| :--- | :--- | :--- | :--- |
| Politica de Acesso | LIFO (Ultimo a entrar, primeiro a sair) | FIFO (Primeiro a entrar, primeiro a sair) | Acesso sequencial por ponteiros |
| Insercao | O(1) no topo | O(1) no final | O(1) no inicio ou O(n) no fim |
| Remocao | O(1) no topo | O(1) no inicio | O(n) para busca + O(1) remocao |
| Busca e Acesso | O(1) no topo; O(n) nos internos | O(1) no inicio; O(n) nos internos | O(n) busca sequencial por chave |
| Custo / Desempenho | Alto desempenho para empilhar e reverter | Alto desempenho para ordem de chegada | Moderado; depende do tamanho nas buscas |
| Facilidade de Implementacao | Alta (um ponteiro de topo) | Alta (ponteiros de inicio e fim) | Moderada (busca e controle de ligacoes) |
| Organizacao de Dados | Ordem cronologica reversa | Ordem de chegada | Flexivel para insercoes dinamicas |
| Adequacao ao Versionamento | Perfeita (Historico de versoes) | Inadequada para historico linear | Moderada (Bom para catalogo geral) |

## Justificativa Tecnica da Escolha da Pilha

A Pilha foi escolhida como estrutura principal porque, quando ocorre uma falha ou alteracao indesejada, o operador precisa recuperar primeiro a versao mais recente salva. Uma Fila devolveria a versao mais antiga, enquanto uma Lista Encadeada exigiria buscas sequenciais em `O(n)`. Com a Pilha, tanto o salvamento quanto a restauracao ocorrem em `O(1)` com implementacao direta.

## Como Executar

### Codigo principal em C (Pilha, Fila e Lista Encadeada)

Compile com GCC:

```bash
gcc sistema_backup.c -o backup
