#ifndef _CIRCUIT_HPP_
#define _CIRCUIT_HPP_

#include    <map>
#include    "Component.hpp"
#include    "FileParse.hpp"
#include    "Parser.hpp"
#include    "Input.hpp"
#include    "Output.hpp"
#include    "Component4081.hpp"

class Circuit
{
private:
  std::string _filename;
  std::map<size_t, std::string> _valueCompo;
public:
  Circuit(int ac, char **av);
  ~Circuit();
  Circuit(Circuit const & other);
  Circuit& operator=(Circuit const & other);

  void Nanotekspice();
  void DumpValue();
};

#endif
