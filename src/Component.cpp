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
  Component *FromDeBite = new Component();
  std::cout << type << std::endl;
  std::cout << value << std::endl;
  return (FromDeBite);
}

nts::Tristate Component::Compute(size_t pin_num_this)
{
  nts::Tristate tete = nts::UNDEFINED;
  (void)pin_num_this;
  return (tete);
}

void Component::SetLink(size_t pin_num_this,
                        nts::IComponent &component,
                        size_t pin_num_target)
{
  (void)pin_num_this;
  (void)component;
  (void)pin_num_target;
}

void Component::Dump(void) const
{
  std::cout << "Huge crap/dump" <<std::endl;
}
