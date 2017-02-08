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
  Input *input = new Input("1");
  Input *input2 = new Input("1");
  Output *output = new Output();
  Component4081 *C4081 = new Component4081();
  file->parseFile(_filename);

  _Chipset = file->getMapChipset();
  (void)_Chipset;
  input->Dump();
  output->Dump();
  std::cout << "----COMPONENT 4081------" << '\n';
  input->SetLink(1, *C4081, 1);
  input2->SetLink(1, *C4081, 2);
  output->SetLink(1, *C4081, 3);
  C4081->SetLink(1, *input2, 1);
  C4081->SetLink(2, *input, 1);
  C4081->SetLink(3, *output, 1);


  C4081->Compute(1);
  C4081->Compute(2);
  C4081->Compute(3);
  C4081->Compute(6);
  C4081->Dump();

  std::cout << "----------INPUT---------" << '\n';
  input->Dump();
  input2->Dump();
  std::cout << "---------OUTPUT---------" << '\n';
  output->Dump();
  output->Compute(1);
  output->Dump();
  (void)C4081;
}
