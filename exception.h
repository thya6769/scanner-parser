#pragma once

/*
 * COMP3109 Calculator Exercise
 *
 * Exception Class
 */

#include <exception>

/*
 * exception for reporting illegal states
 */
class calc_exception: public std::exception
{
public:
 virtual const char* what() const throw()
 {
  return "error";
 }
};

