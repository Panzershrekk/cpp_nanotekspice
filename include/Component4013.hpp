#ifndef _CIRCUIT_HPP_
#define _CIRCUIT_HPP_

#include    "Component.hpp"

class Component2716
{
public:
  Component2716();
  ~Component2716();
  Component2716(Component2716 const & other);
  Compo2716& operator=(Component2716 const & other);

  nts::IComponent * createComponent(const std::string &type, const std::string &value);
  virtual nts::Tristate Compute(size_t pin_num_this = 1);
  virtual void SetLink(size_t pin_num_this,
    nts::IComponent &component,
    size_t pin_num_target);
  virtual void Dump(void) const;
};

#endif
