/*
 * COMP3109 Calculator Exercise
 * 
 * Main program
 */

#include <ctype.h>
#include <string>
#include <iostream>
#include <exception>

#include "exception.h"
#include "scanner.h"
#include "parser.h"
#include "calculation.h"

/*
 * test driver for scanner
 */
int main(int argc, char **argv)
{
 binding b;
 //
 // read-evaluate-print-loop (REPL)
 //
 while(!cin.eof()) {
  try {
   // read line from stdin
   string line;
   getline(cin,line);

   // tokenize input line
   scanner s(line);

   // parser  
   parser p(s);

   // generate calculation
   unique_ptr<calculation> c = p.parse();

   // compute calculation
   if (c.get() != nullptr) { 
     cout << "result = " << c->eval(b) << "\n";  
   }
  } catch (calc_exception &e) {
   cerr << e.what() << "\n";
  }
 }
}
