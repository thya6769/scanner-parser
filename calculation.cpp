/*
 * COMP3109 Calculator Exercise
 *
 * Abstract Syntax Tree implementation
 *
 */

#include <assert.h>
#include "calculation.h"

/*
 * evaluate number
 */
float calc_number::eval(binding &b) {
  return number;
}

/*
 * evaluate variable
 */
float calc_variable::eval(binding &b) {
  return b[var];
}

/*
 * evaluate a let statement
 */
float calc_let::eval(binding &b) {
  b[var] = term->eval(b);
  return b[var];
}

/*
 * evaluate an operation
 */
float calc_op::eval(binding &b) {
  switch(op){
    case '+':
      return left->eval(b) + right->eval(b);
      break;
    case '-':
      return left->eval(b) - right->eval(b);
      break;
    case '*':
      return left->eval(b) * right->eval(b);
      break;
    case '/':
      return left->eval(b) / right->eval(b);
      break;
    default:
      assert(false && "wrong op code");
  }
}
