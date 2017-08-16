# scanner-parser
The task of this tutorial is to implement portions of a scanner, an undecorated recursive descent parser, and a decorated recursive descent parser that constructs an abstract syntax tree. For sake of simplicity we have a grammar for a calculator given below:
 start := [["let" IDENT ’=’ term ] | term] ’\n’;
 term := factor { ’+’| ’-’ factor};
 factor := primitive { ’*’ | ’/’ primitive };
 primitive := IDENT | NUMBER | ’(’ term ’)’;
The symbols on the right-hand side are non-terminals, and concrete symbols in an input line are terminals. Braces are used for zero or more occurrences, brackets for zero or at most one occurrence. For parsing, please refresh your knowledge about context-free languages and recursive descent parser. You find information on wikipedia.
The calculator is implemented as a Read-Evaluate-Print-Loop (REPL). In the following, input/output linesareshownforsimpleinputs,i.e.,101,A = 10,andA * A + 1inconsecutiveorder.
101
result = 101 let A = 10 result = 10 A*A+1 result = 101