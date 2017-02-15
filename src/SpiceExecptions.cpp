#include "SpiceExecptions.hpp"

SpiceExecptions::SpiceExecptions(std::string msg) throw() : _msg(msg)
{
}

const char *SpiceExecptions::what() const throw()
{
  return (_msg.c_str());
}
