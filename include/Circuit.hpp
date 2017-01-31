#ifndef _CIRCUIT_HPP_
#define _CIRCUIT_HPP_

#include    "Component.hpp"

class Circuit
{
public:
  Circuit();
  ~Circuit();
  Circuit(Circuit const & other);
  Circuit& operator=(Circuit const & other);

  void addComponent(Component &);
  void removeComponent(Component &);
  void startSimulation();
};

#endif
