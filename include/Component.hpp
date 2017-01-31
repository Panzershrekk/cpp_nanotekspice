#ifndef _COMPONENT_HPP_
#define _COMPONENT_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include "IComponent.hpp"

class Component : public nts::IComponent
{
public:
  Component();
  ~Component();
  Component(Component const & other);
  Component& operator=(Component const & other);

  IComponent * createComponent(const std::string &type, const std::string &value);
  virtual nts::Tristate Compute(size_t pin_num_this = 1);
  virtual void SetLink(size_t pin_num_this,
    nts::IComponent &component,
    size_t pin_num_target);
  virtual void Dump(void) const;
};

#endif
