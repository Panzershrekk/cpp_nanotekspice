#include <string>
#include <iostream>

#include "Circuit.hpp"
#include "FileParse.hpp"

int main(int ac, char **av)
{
  if (ac >= 2)
  {
    Circuit *Nanotekspice = new Circuit(ac, av);
    Nanotekspice->Nanotekspice();
  }
  else
    std::cerr << "Bad usage" << std::endl;
  return 0;
}
