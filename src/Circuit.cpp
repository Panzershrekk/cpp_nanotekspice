#include "Circuit.hpp"

Circuit::Circuit()
{
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

void Circuit::addComponent(Component &compo)
{
  (void)compo;
}

void Circuit::removeComponent(Component &compo)
{
  (void)compo;
}

void Circuit::startSimulation()
{

}
