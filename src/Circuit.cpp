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
  Output *output = new Output();
  file->parseFile(_filename);

  _Chipset = file->getMapChipset();
  (void)_Chipset;
  input->Dump();
  output->Dump();
  std::cout << "----FOR THE LINKING----" << '\n';
  input->SetLink(1, *output, 1);
  output->SetLink(1, *input, 1);
  input->Dump();
  output->Dump();
  std::cout << "----CHANGING STATE------" << '\n';
  output->Compute();
  output->Dump();
  input->setState(1);
  output->Compute();
  output->Dump();
}
