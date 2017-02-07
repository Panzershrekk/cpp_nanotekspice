#include "Circuit.hpp"

Circuit::Circuit(std::string filename)
{
  _filename = filename;
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
  FileParse *file = new FileParse();
  Input *input = new Input("0");
  file->parseFile(_filename);

  _Chipset = file->getMapChipset();
  (void)_Chipset;
  input->Dump();
  input->Compute(2);
}
