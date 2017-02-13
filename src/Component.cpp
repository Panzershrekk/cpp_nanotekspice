#include "Input.hpp"
#include "Component.hpp"

Component::Component()
{
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
  nts::IComponent *Comp;
  if (type == "input")
    Comp = createInput(value);
  if (type == "output")
    Comp = createOutput(value);
  if (type == "4081")
    Comp = create4081(value);
  return (Comp);
}

nts::IComponent *Component::createInput(const std::string &value) const
{
  return (new Input(value));
}

nts::IComponent *Component::create4081(const std::string &value) const
{
  (void) value;
  return (new Component4081());
}

nts::IComponent *Component::createOutput(const std::string &value) const
{
  (void) value;
  return (new Output());
}
