#ifndef _CIRCUIT_HPP_
#define _CIRCUIT_HPP_

#include    "Component.hpp"
#include    "FileParse.hpp"
#include    "Parser.hpp"
#include    "Input.hpp"
#include    "Output.hpp"

class Circuit
{
private:
  std::string _filename;
  std::map<std::string, std::string> _Chipset;
public:
  Circuit(std::string);
  ~Circuit();
  Circuit(Circuit const & other);
  Circuit& operator=(Circuit const & other);

  void Nanotekspice();
};

#endif
