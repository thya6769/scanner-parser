/*
 * COMP3109 Calculator Exercise
 */

#include "exception.h"
#include "scanner.h"
#include "parser.h"

using namespace std;

/*
 * parse non-terminal term
 */
unique_ptr<calculation> parser::term()
{
 // parse a factor
 unique_ptr<calculation> result = factor();
 // continue if there is a plus/minus token
 while (t == t_plus || t == t_minus) {
  char op = ((t == t_plus)?'+':'-');
  // get next token
  t = s.next();
  // parse a factor
  result = unique_ptr<calculation>(new calc_op(op, move(result), factor()));
 }
 return move(result);
}

/*
 * parse non-terminal factor
 */
unique_ptr<calculation> parser::factor()
{
 // parse a primitive
 unique_ptr<calculation> result = primitive();
 while (t == t_multiply || t == t_divide) {
  char op = ((t == t_multiply)?'*':'/');
  // get next token
  t = s.next();
  // parse a primitive
  result = unique_ptr<calculation>(new calc_op(op, move(result), primitive()));
 }
 return move(result);
}

/*
 * parse non-terminal primitive
 */
unique_ptr<calculation> parser::primitive()
{
 unique_ptr<calculation> result;
 if (t == t_ident) {
  result = unique_ptr<calculation>(new calc_variable(s.get_identifier()));
  t = s.next();
 } else if (t == t_number) {
  result = unique_ptr<calculation>(new calc_number(s.get_number()));
  t = s.next();
 } else if (t == t_lparen) {
  t = s.next();
  result = term();
  if (t != t_rparen) throw calc_exception();
  t = s.next();
 } else {
  throw calc_exception();
 }
 return move(result);
}

/*
 * parse input
 */
unique_ptr<calculation> parser::parse()
{
 unique_ptr<calculation> result;

 // read first token from input stream
 t = s.next();

 if (t==t_eol) return move(result);

 // check whether it is keyword "let"
 if (t == t_let) {
   t = s.next();

   // check whether next token is identifier
   if (t != t_ident) throw calc_exception();
   string ident = s.get_identifier();
   t = s.next();

   // check whether next token is an equality symbol
   if (t != t_equal) throw calc_exception();
   t = s.next();

   // parse term
   result = unique_ptr<calculation>(new calc_let(ident,term()));
 } else if(t == t_if){
   t = s.next();
   if (t == l_paren) {
     t = s.next();
     if(t == t_ident || t == t_number){
       t = s.next();
     }
   }
 } else {
   // parse term
   result = term();
 }

 // throw an exception if still tokens remain in stream
 if (t != t_eol) throw calc_exception();

 return move(result);
}
