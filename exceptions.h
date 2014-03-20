#ifndef __EXCEPTIONS_H
#define __EXCEPTIONS_H

#include <stdexcept>

/// exception thrown in case a bounding error is discovered
/**
   Inherits from std::runtime_error.
   Construct an object by passing a string or cstring as message. Use
   the what function to access the message passed at construction.
*/
class BoundingError : public std::runtime_error {
 public:
  /// constructs an error object by passing a message
 explicit BoundingError(const std::string & msg) : 
  runtime_error(msg) {};

  /// constructs an error object by passing a message
 explicit BoundingError(const char * msg) :
  runtime_error(msg) {};
};
#endif
