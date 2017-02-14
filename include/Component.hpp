#ifndef _COMPONENT_HPP_
#define _COMPONENT_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <functional>
#include "IComponent.hpp"
#include "Input.hpp"
#include "Component4081.hpp"
#include "Output.hpp"

class Component
{
private:
  std::map<std::string, std::function<nts::IComponent*(const std::string &value)>> _compFunc;
public:
  Component();
  ~Component();
  Component(Component const & other);
  Component& operator=(Component const & other);

  nts::IComponent * createComponent(const std::string &type, const std::string &value);
  nts::IComponent * create4081(const std::string &value) const;
  nts::IComponent * createInput(const std::string &value) const;
  nts::IComponent * createOutput(const std::string &value) const;
};

#endif
