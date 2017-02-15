#include <exception>
#include <iostream>

class SpiceExecptions : public std::exception
{
private:
  std::string _msg;
public:
  SpiceExecptions(std::string msg) throw();
  virtual const char* what() const throw();
  virtual ~SpiceExecptions() throw() {};
};
