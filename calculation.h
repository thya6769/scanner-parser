#pragma once

/*
 * COMP3109 Calculator Exercise 
 *
 * calculator class represents the
 * abstract syntax tree with operation
 * to evaluate expressions.
 */

#include <ctype.h>
#include <string>
#include <iostream>
#include <exception>
#include <map>


/*
 * variable binding 
 */ 
typedef std::map<std::string, float> binding; 

/*
 * abstract class for an abstract syntax node
 */
class calculation {
public:
 virtual ~calculation() { }

 // method for computing a value 
 virtual float eval(binding &b) = 0;
};

/*
 * abstract syntax tree node for representing number
 */
class calc_number : public calculation { 
protected:
 float number; // number 
public:
 calc_number(float n) : number(n) { }
 float eval(binding &b);
};

/*
 * abstract syntax tree node for representing variables
 */
class calc_variable : public calculation {
protected:
 std::string var; // name of variable
public:
 calc_variable(const std::string &var) : var(var) { }
 float eval(binding &b);
};

class calc_let : public calculation{ 
protected: 
 std::string var;  // variable name
 std::unique_ptr<calculation> term; 
public: 
 calc_let(const std::string &var, std::unique_ptr<calculation> term) : var(var), term(std::move(term)) { } 
 float eval(binding &b);
};
 
class calc_op : public calculation { 
protected: 
 char op;  // operation 
 std::unique_ptr<calculation> left, 
                              right; 
public: 
 calc_op(char op, std::unique_ptr<calculation> left, std::unique_ptr<calculation> right): 
  op(op), left(std::move(left)), right(std::move(right)) { } 
 float eval(binding &b);
}; 
