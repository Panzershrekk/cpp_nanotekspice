#include "Circuit.hpp"

Circuit::Circuit(int ac, char **av)
{
  int i = 2;

  _filename = av[1];
  while (i < ac)
  {
    _valueCompo[i - 2] = av[i];
    i++;
  }
}

Circuit::~Circuit()
{
}

Circuit::Circuit(Circuit const & other)
{
  (void) other;
}

Circuit& Circuit::operator=(Circuit const & other)
{
  (void) other;
  return *this;
}

void Circuit::Nanotekspice()
{
  FileParse *fileparser = new FileParse();
  fileparser->parseFile(_filename, _valueCompo);
}

void Circuit::DumpValue()
{
  for(std::map<size_t, std::string>::iterator it = _valueCompo.begin();
    it != _valueCompo.end(); ++it)
    {
        std::cout << it->second << std::endl;
    }
}
