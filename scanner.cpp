/*
 * COMP3109 Calculator Exercise
 *
 * Scanner implements the coversion of an
 * input character stream to a token stream.
 *
 */

#include "exception.h"
#include "scanner.h"

using namespace std;

// get next token from input line
enum token scanner::next()
{
 // skip blanks
 while(idx < input.length() && isspace(input[idx]))
  idx++;

 // return end of line
 if(idx >= input.length()) return t_eol;

 // number
 if(isdigit(input[idx])){
  num_value=input[idx++]-'0';
  while(idx < input.length() && isdigit(input[idx])) {
   num_value=num_value*10+input[idx++]-'0';
  }
  return t_number;

 // identifier
 } else if(isalpha(input[idx])) {
  id_value = input[idx++];
  while(isalnum(input[idx])) {
   id_value += input[idx++];
  }
  if (id_value == "let") {
   return t_let;
 } else if(id_value == "if"){
   return t_if;
 }else if(id_value == "while"){
   return t_while;
 }else {
   return t_ident;
  }

 // plus
 } else if(input[idx]=='+') {
  idx ++;
  return t_plus;

 // minus
 } else if(input[idx]=='-') {
  idx ++;
  return t_minus;

 // multiply
 } else if(input[idx]=='*') {
  idx ++;
  return t_multiply;

 // divide
 } else if(input[idx]=='/') {
  idx ++;
  return t_divide;

 // assign
 } else if(input[idx]=='=') {
  idx ++;
  return t_equal;

 // left parenthesis
 } else if(input[idx]=='(') {
  idx ++;
  return t_lparen;

 // right parenthesis
 } else if(input[idx]==')') {
  idx ++;
  return t_rparen;

 // throw exception: illegal character
 } else {
  throw calc_exception();
 };
}
