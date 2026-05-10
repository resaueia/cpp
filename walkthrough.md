# C++ Modules — Walkthrough

Resumo por lista de exercícios: conceitos abordados, restrições do subject e como cada solução funciona.

---

## Regras Gerais (módulos 05–09)

- Compilar com `c++ -Wall -Wextra -Werror -std=c++98`
- Nomes de classe em UpperCamelCase; arquivos nomeados conforme a classe
- Proibido: `using namespace`, `friend`, `*printf()`, `*alloc()`, `free()`, C++11, Boost
- STL (containers e `<algorithm>`) proibida até o Módulo 08; a partir dele, é **obrigatória**
- Sem implementações de funções em arquivos de cabeçalho (nota 0)
- Todos os headers precisam de include guards
- Sem memory leaks quando se usa `new`
- Todas as classes devem seguir a **Forma Canônica Ortodoxa** (construtor padrão, construtor de cópia, operador de atribuição, destrutor), exceto classes de exceção no Módulo 05

---

## Módulo 05 — Exceções

**Subject:** `05-cpp/en.subject.05.pdf`

**Conceitos abordados:** `throw`, `try`/`catch`, classes de exceção aninhadas herdando `std::exception`, membros `const` em classes com operador de atribuição, interação entre objetos via referências, padrão de fábrica sem cadeias `if/else`.

**Restrições especiais:** classes de exceção não precisam seguir OCF. Todas as outras devem.

### ex00 — Bureaucrat

`Bureaucrat` com `const std::string name` e `int grade` (1–150, onde 1 é o mais alto). O construtor lança `GradeTooHighException` ou `GradeTooLowException` se `grade` estiver fora do intervalo. `incrementGrade()` e `decrementGrade()` também lançam ao atingir os limites. As exceções são classes aninhadas que herdam `std::exception` e sobrescrevem `what()`. O `operator<<` imprime `"<nome>, bureaucrat grade <grau>."`.

### ex01 — Form

Adiciona a classe `Form` com atributos `const` (nome, grauParaAssinar, grauParaExecutar) e `bool isSigned`. `beSigned(const Bureaucrat&)` verifica se o grau numérico do burocrata é ≤ ao grau exigido para assinar; caso contrário lança `GradeTooLowException`. `Bureaucrat::signForm()` envolve `beSigned()` em try/catch e imprime o resultado da tentativa.

### ex02 — AForm

`Form` é renomeada para `AForm` e ganha `virtual void execute(const Bureaucrat& executor) const = 0`, tornando-se abstrata. Adiciona `FormNotSignedException`. Três classes concretas herdam `AForm`:

- `ShrubberyCreationForm` (assinar=145, executar=137): cria arquivo `<alvo>_shrubbery` com árvore ASCII usando `std::ofstream`.
- `RobotomyRequestForm` (assinar=72, executar=45): imprime barulho de broca e usa `std::rand()` para 50% de chance de sucesso.
- `PresidentialPardonForm` (assinar=25, executar=5): imprime mensagem de perdão de Zaphod Beeblebrox.

`Bureaucrat::executeForm()` chama `form.execute(*this)` com tratamento de exceção.

### ex03 — Intern

`Intern` sem nome, grau ou estado relevante. `makeForm(formName, target)` usa dois arrays paralelos — nomes dos formulários e ponteiros para funções construtoras estáticas — em vez de `if/else`. Um loop compara `formName` com cada entrada e chama a função correspondente. Retorna `NULL` e imprime erro para nomes desconhecidos.

---

## Módulo 06 — Casts em C++

**Subject:** `06-cpp/06-en.subject.pdf`

**Conceitos abordados:** os quatro casts do C++ (`static_cast`, `reinterpret_cast`, `dynamic_cast`, `const_cast`), detecção de tipo em tempo de execução via RTTI, serialização de ponteiros.

**Restrições:** toda conversão de tipo deve usar um cast C++ explícito — a escolha é avaliada na defesa. No ex02, o header `<typeinfo>` é explicitamente proibido.

### ex00 — Scalar Type Conversion

`ScalarConverter` não instanciável (todos os construtores privados), com único método estático `convert(const std::string&)`. Um parser interno detecta o tipo literal da string (char, int, float, double, ou especiais `nan`/`+inf`/`-inf`). Em seguida usa `static_cast` para produzir os quatro tipos e os imprime, tratando `"impossible"` para overflow e `"Non displayable"` para chars fora do intervalo ASCII imprimível (32–126).

### ex01 — Serialization

`Serializer` não instanciável. `serialize(Data*)` usa `reinterpret_cast<unsigned long>(ptr)` para converter o endereço do ponteiro em um inteiro sem sinal. `deserialize(uintptr_t)` usa `reinterpret_cast<Data*>(raw)` para reverter. Nenhum bit é alterado. O `main` verifica que a ida e volta preserva o ponteiro e os dados do struct.

### ex02 — Identify Real Type

`Base` com destrutor virtual; `A`, `B`, `C` herdam de `Base`. `generate()` instancia aleatoriamente um dos três via `rand() % 3`. `identify(Base*)` tenta `dynamic_cast<A*>`, `dynamic_cast<B*>`, `dynamic_cast<C*>` em sequência — cast com falha em ponteiro retorna `nullptr`. `identify(Base&)` opera via referência, usando dynamic_cast em ponteiros obtidos com `&p`.

---

## Módulo 07 — Templates

**Subject:** `07-cpp/07pt_br.subject.pdf`

**Conceitos abordados:** templates de função, templates de classe, dedução automática de tipo, `operator[]` com exceção de bounds, cópia profunda em classes template, inicialização com `()` em `new T[n]()`.

**Restrições:** implementações de templates de função devem estar no header; templates de classe também (o compilador precisa ver a definição completa no momento da instanciação).

### ex00 — Start with a Few Functions

`whatever.hpp` define três templates de função: `swap<T>` (troca via temporário), `min<T>` (retorna o menor; o segundo em caso de empate), `max<T>` (retorna o maior; o segundo em caso de empate). O `main` usa `::swap`, `::min`, `::max` para garantir chamada dos templates globais em vez dos equivalentes de `std`.

### ex01 — Iter

`iter<T>(T* array, size_t length, void(*func)(T const&))` aplica `func` a cada elemento do array. Valida ponteiro nulo, comprimento zero e função nula antes de iterar. O `main` testa com array de `int` e array de `std::string`.

### ex02 — Array

`Array<T>` template de classe com `T* arr` e `unsigned int _size`. Construtor padrão (`arr=NULL`, `_size=0`); construtor com `unsigned int n` aloca `new T[n]()` (os `()` inicializam os elementos). Cópia profunda: construtor de cópia e operador de atribuição alocam novo array e copiam elemento a elemento. `operator[]` lança `std::out_of_range` se o índice for ≥ `_size` (sobrecargas `const` e não-`const`). `size()` é `const`.

---

## Módulo 08 — Containers, Iteradores e Algoritmos STL

**Subject:** `08-cpp/08pt_br.subject.pdf`

**Conceitos abordados:** containers STL (`std::vector`, `std::list`, `std::stack`), iteradores, algoritmos de `<algorithm>` (`std::find`, `std::sort`, `std::min_element`, `std::max_element`, `std::distance`), adaptador de container `std::stack` e acesso ao seu membro protegido `c`.

**Restrições especiais:** uso de STL é **obrigatório**. Não usá-la resulta em nota baixa. Declarações de template podem ir em `.hpp`; implementações opcionalmente em `.tpp`.

### ex00 — Easy Find

`easyfind<T>(T& container, int value)` usa `std::find(container.begin(), container.end(), value)`. Se o iterador retornado for `end()`, lança `std::runtime_error("Value not found!")`. Funciona com qualquer container sequencial que suporte iteradores bidirecionais (`std::vector`, `std::list`, etc.).

### ex01 — Span

`Span` armazena até N inteiros em `std::vector<int>` privado. `addNumber()` lança `std::runtime_error` se o vetor já atingiu `_maxSize`. `shortestSpan()` copia o vetor para um temporário, aplica `std::sort` e itera pares adjacentes para encontrar a diferença mínima — lança se houver menos de 2 elementos. `longestSpan()` usa `std::max_element` e `std::min_element` diretamente no vetor original. O template `addRange<Iterator>` usa `std::distance` para verificar capacidade e `numbers.insert(end, begin, end)` para inserir uma faixa em uma única chamada.

### ex02 — MutantStack

`MutantStack<T>` herda publicamente de `std::stack<T>`. Expõe iteradores acessando `this->c` (o membro protegido da stack, por padrão um `std::deque`). Define os typedefs `iterator`, `const_iterator`, `reverse_iterator`, `const_reverse_iterator` e implementa `begin()`, `end()`, `rbegin()`, `rend()` com suas versões `const`, tornando a pilha iterável como qualquer container sequencial.

---

## Módulo 09 — STL (uso real)

**Subject:** `09-cpp/09pt_br.subject.pdf`

**Conceitos abordados:** `std::map` com `lower_bound` para busca por proximidade, `std::stack` como avaliador de expressões pós-fixas, algoritmo Ford-Johnson (merge-insert sort), medição de tempo de execução com dois containers diferentes.

**Restrição crítica:** cada exercício deve usar ao menos um container STL, e um container usado em um exercício **não pode ser reutilizado** em exercícios posteriores do módulo. O ex02 requer ao menos dois containers diferentes (e não pode usar `std::map` nem `std::stack`).

### ex00 — Bitcoin Exchange

`BitcoinExchange` carrega `data.csv` em `std::map<std::string, double>` — as chaves em formato ISO (`YYYY-MM-DD`) se ordenam lexicograficamente, o que equivale à ordem cronológica. `rateForDateOrPrev()` usa `lower_bound(date)` para encontrar a primeira chave ≥ à data solicitada; se não for exata, recua um passo para obter a taxa da data mais próxima anterior. Valida formato de data (incluindo anos bissextos), valores no intervalo [0, 1000] e imprime `data => valor = resultado` ou mensagem de erro.

### ex01 — Reverse Polish Notation

`RPN` usa `std::stack<int>`. `evaluate(expr)` tokeniza a expressão com `std::istringstream`: tokens de dígito único são empilhados como inteiros; operadores (`+`, `-`, `*`, `/`) desempilham dois valores (`b` depois `a`), calculam com `applyOperator()` e empilham o resultado. Lança `std::runtime_error("Error")` para token inválido, divisão por zero, ou stack com número errado de elementos ao final.

### ex02 — PmergeMe

`PmergeMe` ordena uma sequência de inteiros positivos recebidos como argumentos usando o algoritmo **Ford-Johnson (merge-insert sort)**, executado independentemente em dois containers: `std::vector<int>` e `std::deque<int>` (proibidos `std::map` e `std::stack`, usados nos exercícios anteriores).

**Algoritmo Ford-Johnson** (aplicado recursivamente em cada nível):
1. Se o número de elementos for ímpar, salva o *straggler* à parte.
2. Forma pares adjacentes, garantindo que o maior fique primeiro.
3. Extrai os maiores e os ordena **recursivamente** com o mesmo algoritmo.
4. Reassocia cada maior ordenado ao seu menor parceiro (usando marcação booleana para lidar com duplicatas).
5. Monta a cadeia principal: `[b_1, a_1, a_2, …, a_m]` (b_1 já está em posição correta pois b_1 ≤ a_1).
6. Insere `b_2..b_m` na cadeia em **ordem de Jacobsthal** (J(n) = J(n-1) + 2·J(n-2): grupos 3→2, 5→4, 11→6, 21→12…). A busca binária de cada `b_k` é limitada à posição de `a_k`, pois `b_k ≤ a_k` — isso minimiza o total de comparações.
7. Reinsere o straggler com busca binária na cadeia completa.

O tempo de cada sort é medido com `gettimeofday()` e exibido em microssegundos. Entradas inválidas (negativos, zero, não-inteiros) produzem mensagem de erro em `stderr`.

---
