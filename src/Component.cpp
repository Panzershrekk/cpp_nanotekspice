#include "Input.hpp"
#include "Component.hpp"

Component::Component()
{
  _compFunc["input"] = std::bind(&Component::createInput, this, std::placeholders::_1);
  _compFunc["output"] = std::bind(&Component::createOutput, this, std::placeholders::_1);
  _compFunc["4081"] = std::bind(&Component::create4081, this, std::placeholders::_1);
  _compFunc["4071"] = std::bind(&Component::create4071, this, std::placeholders::_1);

}

Component::~Component()
{
}

Component::Component(Component const & other)
{
  (void) other;
}

Component& Component::operator=(Component const & other)
{
  (void) other;
  return *this;
}

nts::IComponent *Component::createComponent(const std::string &type, const std::string &value)
{
  return (_compFunc[type](value));
}

nts::IComponent *Component::createInput(const std::string &value) const
{
  return (new Input(value));
}

nts::IComponent *Component::create4081(const std::string &value) const
{
  return (new Component4081(value));
}

nts::IComponent *Component::create4071(const std::string &value) const
{
  (void) value;
  return (new Component4071(value));
}

nts::IComponent *Component::createOutput(const std::string &value) const
{
  return (new Output(value));
}
