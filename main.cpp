#include <string>
#include <iostream>
#include "IComponent.hpp"
#include "Component.hpp"
#include "Parser.hpp"
#include "Circuit.hpp"
#include "FileParse.hpp"

int main(int ac, char **av)
{
  if (ac >= 2)
  {
    Circuit *Nanotekspice = new Circuit(av[1]);
    Nanotekspice->Nanotekspice();
  }
  else
    std::cout << "Bad usage" << std::endl;
  return 0;
}
