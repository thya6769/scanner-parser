#pragma once

/*
 * COMP3109 Calculator Exercise
 *
 * Scanner: converts the stream of input characters
 *          to a stream of tokens.
 */

#include <ctype.h>
#include <string>
#include <iostream>
#include <exception>

/*
 * We have following tokens for the calculator grammar
 *
 *  '\n' -> t_eol
 *  let -> t_let
 *  identifier/sequence of alphanumerical letters -> t_ident
 *  '=' -> t_equal
 *  '+' -> t_plus
 *  '-' -> t_minus
 *  '*' -> t_multiply
 *  '/' -> t_divide
 *  '(' -> t_lparen
 *  ')' -> t_rparen
 *  number/sequence of digits -> t_number
 *
 */

/*
 * token declaration
 */
enum token {
 t_number,    // number,i.e., [0-9]+
 t_ident,     // identifier, i.e., [a-zA-Z][a-zA-Z0-9]*
 t_let,       // let keyword
 t_if,        // if keyword
 t_while,     // while keyword
 t_lessThan,  // less than, i.e. '<'
 t_lparen,    // left parenthesis, i.e., '('
 t_rparen,    // right parenthesis, i.e., ')'
 t_plus,      // plus, i.e., '+'
 t_minus,     // minus, i.e., '-'
 t_multiply,  // multiply, i.e., '*'
 t_divide,    // divide, i.e., '/'
 t_equal,     // equal, i.e., '='
 t_eol        // end of line
};

/*
 * Scanner class
 */
class scanner {
private:
 std::string input;    // input line that is tokenized
 int idx;         // current position in string

 float num_value; // value of number token
 std::string id_value; // value of identifier token

public:
 scanner(const std::string &input) :
  input(input),
  idx(0),
  num_value(0.0),
  id_value("") {
 };

 // retrieve number of a number token
 float get_number() {
  return num_value;
 }

 // retrieve string of an identifier token
 const std::string &get_identifier() {
  return id_value;
 }

 // get next token from input line
 enum token next();
};
