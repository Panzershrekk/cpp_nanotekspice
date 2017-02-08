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
  nts::IComponent *Comp = new Input();
  std::cout << type << std::endl;
  std::cout << value << std::endl;
  return (Comp);
}

/*nts::IComponent * create4081(const std::string &value) const
{
  (void)value;
}

nts::IComponent * createInput(const std::string &value) const
{
  (void)value
}

nts::IComponent * createOutput(const std::string &value) const
{
  (void)value
}
*/
