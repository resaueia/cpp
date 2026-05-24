# Análise dos Evals — C++ Módulos 05 a 09

Cada módulo é avaliado contra o respectivo `42 EvalHub.pdf`. Onde há conflito entre eval e subject, **o subject prevalece**. A legenda de status usada é:

| Símbolo | Significado |
|---------|-------------|
| ✅ | Passa no critério |
| ⚠️ | Ponto de atenção / grey area |
| ❌ | Falha clara no critério do eval |

---

## Histórico de Correções

Problemas identificados em versões anteriores e que **já foram corrigidos**:

| Módulo | Problema | Resolução |
|--------|----------|-----------|
| **05** ex00/ex01 | `CXX = g++` nos Makefiles | Corrigido — ambos já usam `CXX = c++` |
| **05** todos | Pastas nomeadas `00/`…`03/` em vez de `ex00/`…`ex03/` | Corrigido — pastas renomeadas corretamente |
| **06** ex00 | `ScalarConverter` sem construtor privado | Corrigido — `.hpp` já declara construtor `private` |
| **06** ex00 | `CXX = c++ -g` (flag `-g` embutida na variável do compilador) | Corrigido — separado para `CXX = c++`, flag removida |
| **06** ex01 | `serialize` retornava `unsigned long`; `deserialize` declarava `uintptr_t` mas definia `unsigned long` | Corrigido — ambos usam `uintptr_t` consistentemente |
| **06** ex02 | `identify(Base& p)` usava pointer trick; try/catch correto estava comentado | Corrigido — try/catch ativo; pointer trick removido |
| **06** ex02 | `#include <typeinfo>` ausente, causando erro de compilação (`std::bad_cast` não encontrado) | Corrigido — include adicionado |
| **08** ex02 | `MutantStack::operator=` sem `return *this` no caminho de self-assignment (UB) | Corrigido — `return *this` presente |

---

## Módulo 05 — Exceções

**Conceito:** Exceções em C++ (`throw` / `try` / `catch`). O exercício modela a burocracia com hierarquia de classes onde operações inválidas lançam exceções customizadas derivadas de `std::exception`. O eval testa se as exceções são usadas corretamente — sem retornar códigos de erro — e se toda a hierarquia de classes (OCF) está presente.

### Avaliação por Exercício

#### Ex00 — Bureaucrat
**O que faz:** Cria um burocrata com nome `const` e grade entre 1 (mais alto) e 150 (mais baixo). Qualquer operação que force a grade para fora desse intervalo lança uma exceção aninhada (`GradeTooHighException` / `GradeTooLowException`).

| Critério do Eval | Status | Observação |
|---|---|---|
| Makefile compila com `c++` e flags corretas | ✅ | `CXX = c++`, `-Wall -Wextra -Werror -std=c++98` |
| Classe `Bureaucrat` com nome `const` | ✅ | `const std::string _name` |
| Grade 1–150 com exceções no construtor | ✅ | Lança `GradeTooHighException` / `GradeTooLowException` |
| Accessors para os atributos | ✅ | `getName()`, `getGrade()` |
| `incrementGrade()` / `decrementGrade()` com exceções | ✅ | Correto |
| Exceções herdam de `std::exception` | ✅ | Classes aninhadas com `what()` |
| `operator<<` para ostream | ✅ | Presente e funcional |
| Main com testes suficientes | ✅ | Testa criação, incremento, decremento e exceções |

#### Ex01 — Form
**O que faz:** Adiciona a classe `Form` com atributos `const` (nome, grau para assinar, grau para executar). Um burocrata só consegue assinar se tiver grau suficiente; caso contrário, `beSigned()` lança exceção. `Bureaucrat::signForm()` encapsula o try/catch e imprime o resultado.

| Critério do Eval | Status | Observação |
|---|---|---|
| Makefile compila com `c++` e flags corretas | ✅ | `CXX = c++` |
| Classe `Form` com atributos `private` (não `protected`) | ✅ | Correto |
| Atributos `name`, `gradeToSign`, `gradeToExecute` são `const` | ✅ | Correto |
| `isSigned` começa como `false` | ✅ | Inicializado no construtor |
| Validação de grades com exceções | ✅ | Mesmo padrão do Bureaucrat |
| Accessors e `operator<<` | ✅ | Presentes |
| `Form::beSigned()` | ✅ | Lança se grau do burocrata for insuficiente |
| `Bureaucrat::signForm()` | ✅ | try/catch com mensagem de sucesso/falha |

#### Ex02 — AForm + Formulários Concretos
**O que faz:** `Form` vira `AForm` (abstrata). Três subclasses concretas com comportamentos distintos: `ShrubberyCreationForm` (desenha árvore em arquivo), `RobotomyRequestForm` (robotomiza com 50% de sucesso), `PresidentialPardonForm` (perdoa). `Bureaucrat::executeForm()` chama `execute()` com tratamento de exceção.

| Critério do Eval | Status | Observação |
|---|---|---|
| Makefile com `c++` | ✅ | |
| Formas concretas com graus e nomes corretos | ✅ | Shrubbery(145/137), Robotomy(72/45), Presidential(25/5) |
| Construtores recebem apenas `target` | ✅ | |
| `AForm::execute()` / verificação de grau | ✅ | |
| `Bureaucrat::executeForm()` | ✅ | Presente com tratamento de exceção |
| OCF para todas as classes | ✅ | |
| Main com testes suficientes | ✅ | |

#### Ex03 — Intern
**O que faz:** A classe `Intern` fabrica formulários pelo nome (string) sem if/else encadeado. Usa um array de ponteiros para funções construtoras, indexado por nome de formulário — padrão de despacho limpo que o eval testa explicitamente.

| Critério do Eval | Status | Observação |
|---|---|---|
| Makefile com `c++` | ✅ | |
| Classe `Intern` presente | ✅ | |
| `makeForm()` funciona conforme o subject | ✅ | |
| **Good dispatching**: sem if/else em cascata | ✅ | Array de ponteiros para funções: `AForm* (*constructors[])(const std::string&)` |

---

## Módulo 06 — Casts em C++

**Conceito:** Os quatro tipos de cast explícito do C++: `static_cast` (conversão segura entre tipos relacionados, verificada em compilação), `dynamic_cast` (downcasting seguro em hierarquias polimórficas, verificado em runtime), `reinterpret_cast` (reinterpretação dos bits sem conversão) e `const_cast` (remover/adicionar `const`). O módulo proíbe classes instanciáveis — tudo é `static`.

### Avaliação por Exercício

#### Ex00 — ScalarConverter
**O que faz:** Classe com apenas métodos estáticos (construtor `private` → não instanciável). Recebe uma string e determina o tipo literal (char, int, float, double, especiais como `nan`/`±inf`), converte para um `double` interno e depois exibe todas as quatro representações usando `static_cast`.

| Critério do Eval | Status | Observação |
|---|---|---|
| Classe com construtor privado | ✅ | `.hpp` declara construtor/cópia/atribuição/destrutor como `private` |
| Métodos estáticos | ✅ | `convert()` e `get_type()` são `static` |
| Usa `static_cast` | ✅ | Todas as conversões usam `static_cast` |
| Programa funciona conforme requerido | ✅ | Trata char, int, float, double, nan, ±inf |
| Makefile com `c++` | ✅ | `CXX = c++` (flag `-g` removida) |

#### Ex01 — Serializer
**O que faz:** Converte um ponteiro `Data*` para `uintptr_t` (inteiro sem sinal do tamanho de um ponteiro) usando `reinterpret_cast`, e depois reconstrói o ponteiro original a partir desse inteiro. Demonstra que os bits são preservados — o endereço e os dados permanecem idênticos após o round-trip.

| Critério do Eval | Status | Observação |
|---|---|---|
| Classe com construtor privado | ✅ | Todos os membros especiais são `private` |
| Métodos estáticos | ✅ | `serialize()` e `deserialize()` são `static` |
| `reinterpret_cast` de `Data*` → `uintptr_t` | ✅ | Correto e consistente |
| `reinterpret_cast` de `uintptr_t` → `Data*` | ✅ | Correto e consistente |
| Tipo de retorno de `serialize` é `uintptr_t` | ✅ | Corrigido — header e .cpp usam `uintptr_t` |
| Struct `Data` não-vazio | ✅ | `int number` e `std::string text` |
| Round-trip preserva dados | ✅ | `main` verifica endereço e valores |

#### Ex02 — Identify Real Type
**O que faz:** Dado um `Base*` gerado aleatoriamente como A, B ou C, identifica o tipo real em runtime. `identify(Base* p)` verifica se `dynamic_cast` retornou `NULL` (cast de ponteiro). `identify(Base& p)` usa try/catch de `std::bad_cast` (cast de referência lança exceção em vez de retornar `NULL`). O `#include <typeinfo>` é necessário para `std::bad_cast`.

| Critério do Eval | Status | Observação |
|---|---|---|
| `dynamic_cast` usado para identificar tipo | ✅ | Usado em ambas as sobrecargas |
| `identify(Base* p)` verifica se cast retornou NULL | ✅ | `if (dynamic_cast<A*>(p))` |
| `identify(Base& p)` usa try/catch | ✅ | `catch (std::bad_cast&)` — implementação correta e ativa |
| `#include <typeinfo>` presente | ✅ | Adicionado a `methods.cpp` |

---

## Módulo 07 — Templates

**Conceito:** Templates de função e de classe em C++. Permitem escrever código genérico que funciona para qualquer tipo que satisfaça as operações usadas (duck typing em tempo de compilação). O compilador gera uma instância específica do template para cada tipo usado — zero overhead em runtime.

### Avaliação por Exercício

#### Ex00 — swap / min / max
**O que faz:** Três funções template genéricas: `::swap` (troca os valores de dois objetos), `::min` (retorna o menor, o segundo em empate), `::max` (retorna o maior, o segundo em empate). Funciona com qualquer tipo que tenha `operator<` e `operator>`.

| Critério do Eval | Status | Observação |
|---|---|---|
| Funciona com tipos simples (int) | ✅ | Testado no main |
| Funciona com tipos complexos (string) | ✅ | `std::string` testado no mesmo main |
| Usa `::swap`, `::min`, `::max` | ✅ | Evita ambiguidade com `std::` |
| `min` retorna o segundo argumento em caso de empate | ✅ | `a < b ? a : b` |
| `max` retorna o segundo argumento em caso de empate | ✅ | `a > b ? a : b` |

#### Ex01 — Iter
**O que faz:** Função template `iter(array, length, func)` que aplica uma função a cada elemento de um array de qualquer tipo. O callback também é template, permitindo qualquer função ou functor compatível com o tipo dos elementos.

| Critério do Eval | Status | Observação |
|---|---|---|
| Funciona conforme o subject | ✅ | Itera corretamente aplicando função a cada elemento |
| Makefile com `c++` | ✅ | |
| Suporta callbacks de qualquer tipo | ✅ | Assinatura genérica suficientemente flexível |

#### Ex02 — Array
**O que faz:** Classe template `Array<T>` que encapsula um array alocado com `new[]`. Construtor padrão (tamanho 0), construtor com tamanho (inicializa com `new T[n]()`), `operator[]` com bounds checking que lança `std::out_of_range`, e sobrecarga `const` para acesso em instâncias constantes. Copy constructor e `operator=` fazem deep copy.

| Critério do Eval | Status | Observação |
|---|---|---|
| Construtor vazio (`Array()`) | ✅ | `_size=0`, `arr=NULL` |
| Construtor com tamanho (`Array(unsigned int n)`) | ✅ | `new T[n]()` — inicializa elementos |
| Usa `new[]` para alocação | ✅ | Explicitamente verificado pelo eval |
| `operator[]` lança `std::exception` fora dos limites | ✅ | Lança `std::out_of_range` |
| Acesso de leitura em instância `const` | ✅ | Sobrecarga `const` de `operator[]` presente |
| Funciona com tipos simples e complexos | ✅ | Testado com `int` e `std::string` |

---

## Módulo 08 — Containers, Iteradores e Algoritmos STL

**Conceito:** Uso correto da STL: containers (`vector`, `list`, `stack`, `deque`), iteradores (abstraem o acesso uniforme aos elementos) e algoritmos (`std::find`, `std::sort`, `std::min_element`). O módulo força o uso de algoritmos STL em vez de loops manuais sempre que possível.

### Avaliação por Exercício

#### Ex00 — easyfind
**O que faz:** Função template `easyfind(container, value)` que busca um inteiro em qualquer container de inteiros usando `std::find`. Retorna o iterador encontrado ou lança exceção se o valor não estiver presente.

| Critério do Eval | Status | Observação |
|---|---|---|
| Função template `easyfind(T, int)` | ✅ | |
| **Obrigatório usar algoritmos STL** (`std::find`) | ✅ | Usa `std::find` explicitamente |
| Main com testes suficientes | ✅ | Testa vector, list, caso não-encontrado |

#### Ex01 — Span
**O que faz:** Classe `Span` que armazena até N inteiros num `std::vector`. `shortestSpan()` ordena uma cópia e itera sobre pares adjacentes para encontrar a menor diferença. `longestSpan()` usa `std::max_element - std::min_element`. `addRange<Iterator>()` permite inserir múltiplos valores de uma vez.

| Critério do Eval | Status | Observação |
|---|---|---|
| Classe conforme as restrições do subject | ✅ | |
| Usa algoritmos STL | ✅ | `std::sort`, `std::min_element`, `std::max_element` |
| `shortestSpan` não usa apenas subtração dos dois menores | ✅ | Ordena cópia e itera pares adjacentes |
| Forma prática de adicionar múltiplos números | ✅ | `addRange<Iterator>` template com `insert` |

#### Ex02 — MutantStack
**O que faz:** `std::stack` não expõe iteradores — só permite acesso ao topo. `MutantStack` herda de `std::stack` e expõe os iteradores do container subjacente (`this->c`, um `std::deque` por padrão). Assim é possível tanto usar a interface LIFO do stack quanto iterar sobre todos os elementos.

| Critério do Eval | Status | Observação |
|---|---|---|
| Herda de `std::stack` e expõe todas as funções | ✅ | |
| Tem iterador; operações do subject funcionam | ✅ | `begin()`, `end()`, `rbegin()`, `rend()` |
| `operator=` correto (sem UB) | ✅ | `return *this` presente em ambos os caminhos |
| "Better tests" — main vai além dos exemplos do subject | ✅ | Inclui iteração reversa |

---

## Módulo 09 — STL (uso real)

**Conceito:** Aplicação prática de containers STL escolhidos de forma justificada para problemas reais. O eval exige que o estudante saiba explicar por que escolheu cada container e demonstre conhecimento das trocas de performance (cache-friendliness, complexidade de inserção/busca).

### Avaliação por Exercício

#### Ex00 — Bitcoin Exchange
**O que faz:** Lê uma base de taxas de câmbio Bitcoin (`data.csv`) e um arquivo de entrada com datas e valores. Para cada linha, encontra a taxa da data mais próxima (inferior ou igual) e calcula o valor. Usa `std::map<std::string, double>` — chaves ordenadas lexicograficamente (datas em formato YYYY-MM-DD ficam ordenadas cronologicamente) e `lower_bound()` para busca em O(log n).

| Critério do Eval | Status | Observação |
|---|---|---|
| Makefile com regras padrão | ✅ | |
| Usa pelo menos um container | ✅ | `std::map<std::string, double>` |
| Pode justificar a escolha do container | ✅ | Map mantém datas ordenadas; `lower_bound` dá busca O(log n) |
| Trata arquivo vazio ou com erros | ✅ | Imprime mensagens de erro por linha sem parar |
| Data inválida | ✅ | `isValidDate()` com validação de calendário |
| Valor > 1000 ou < 0 | ✅ | Validado antes do cálculo |
| Usa data inferior mais próxima quando exata não existe | ✅ | `lower_bound` + step-back |

#### Ex01 — Reverse Polish Notation
**O que faz:** Avalia expressões matemáticas em notação polonesa reversa (RPN). Usa `std::stack<int>` — a estrutura LIFO natural para RPN: cada número é empilhado, cada operador desempilha dois operandos, opera e empilha o resultado. Suporta `+ - * /`.

| Critério do Eval | Status | Observação |
|---|---|---|
| Makefile com regras padrão | ✅ | |
| Usa pelo menos um container **diferente do ex00** | ✅ | `std::stack<int>` (ex00 usou `std::map`) |
| Pode justificar a escolha | ✅ | Stack LIFO é a estrutura natural para RPN |
| Funciona com fórmulas diversas | ✅ | |
| **Teste avançado 1:** `8 9 * 9 - 9 - 9 - 4 - 1 +` → 42 | ✅ | Verificado |
| **Teste avançado 2:** `9 8 * 4 * 4 / 2 + 9 - 8 - 8 - 1 - 6 -` → 42 | ✅ | Verificado |
| **Teste avançado 3:** `1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /` → 15 | ✅ | Verificado |

#### Ex02 — PmergeMe
**O que faz:** Ordena uma sequência de inteiros positivos usando o algoritmo Ford-Johnson (merge-insertion sort) em dois containers diferentes (`std::vector` e `std::deque`) e compara o tempo de cada. O algoritmo minimiza o número de comparações: pareamento de elementos, recursão no maior de cada par, inserção da cadeia pendente na ordem de Jacobsthal com binary search limitado.

| Critério do Eval | Status | Observação |
|---|---|---|
| Makefile com regras padrão | ✅ | |
| Usa pelo menos **dois** containers **diferentes dos anteriores** | ✅ | `std::vector<int>` e `std::deque<int>` |
| Pode justificar a escolha de ambos | ✅ | vector: contíguo em memória, cache-friendly; deque: inserções nas extremidades eficientes |
| Algoritmo Ford-Johnson presente e usado em cada container | ✅ | `fordJohnsonVec` e `fordJohnsonDeq` com ordem de Jacobsthal |
| Pode explicar o algoritmo brevemente | ✅ | Pareamento → recursão → cadeia principal → inserção por Jacobsthal + binary search |
| OCF para a classe `PmergeMe` | ✅ | Todos os 4 membros canônicos presentes |
| Funciona com 5–10 inteiros | ✅ | Testado |
| Funciona com 3000 inteiros | ✅ | Testado; saída verificada como ordenada |
| Diferença de tempo visível entre os dois containers | ✅ | Deque consistentemente mais lento que vector |

---

## Resumo Geral — Estado Atual

Todos os exercícios compilam limpos com `c++ -Wall -Wextra -Werror -std=c++98` e passam nos critérios do eval. Nenhum problema crítico pendente.

| Módulo | Status |
|--------|--------|
| **05** — Exceções | ✅ Todos os exercícios ok |
| **06** — Casts | ✅ Todos os exercícios ok (3 correções aplicadas nesta sessão) |
| **07** — Templates | ✅ Todos os exercícios ok |
| **08** — STL containers | ✅ Todos os exercícios ok |
| **09** — STL aplicado | ✅ Todos os exercícios ok |
