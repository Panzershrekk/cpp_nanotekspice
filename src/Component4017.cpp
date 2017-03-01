#include "Component4017.hpp"

Component4017::Component4017(std::string value)
{
  _value = value;
  _nbrPin = 14;
  for (int i = 0; i < 14; i++)
  {
    _linked[i] = NULL;
    _StateMap[i] = nts::Tristate::UNDEFINED;
  }
  _OutLink[3] = std::make_pair(1,2);
  _OutLink[4] = std::make_pair(5,6);
  _OutLink[10] = std::make_pair(8,9);
  _OutLink[11] = std::make_pair(12,13);
}

Component4017::~Component4017()
{
}

Component4017::Component4017(Component4017 const & other)
{
  //_StateMap = other._StateMap;
  _nbrPin = other._nbrPin;
  _link = other._link;
  //_linked = other._linked;
}

Component4017& Component4017::operator=(Component4017 const & other)
{
  _nbrPin = other._nbrPin;
  _link = other._link;
  //_linked = other._linked;
  return *this;
}

nts::Tristate Component4017::Compute(size_t pin_num_this)
{
  if(_nbrPin >= pin_num_this)
  {
    std::map<size_t, nts::Tristate> StateMap = getStateMap();
    if (StateMap[pin_num_this - 1] == nts::Tristate::TRUE)
      return (nts::Tristate::TRUE);
    else if (StateMap[pin_num_this - 1] == nts::Tristate::FALSE)
      return (nts::Tristate::FALSE);
    else
      return (nts::Tristate::UNDEFINED);
  }
  else
    std::cout << "Pin does not exist" << std::endl;
  return (nts::Tristate::UNDEFINED);
}

void Component4017::SetLink(size_t pin_num_this,
                        nts::IComponent &component,
                        size_t pin_num_target)
{
  if (pin_num_this >= 1 && pin_num_this <= _nbrPin)
  {
    /*if (pin_num_this == 7 || pin_num_this == 14)
    {
        std::cout << "Couldn't link this pin : Invalide Pin" << '\n';
        return ;
    }*/
    _link[pin_num_this] = pin_num_target;
    _linked[pin_num_this - 1] = &component;
  }
  else
    std::cout << "Pin or component does not exist!!!" << std::endl;
}

void Component4017::Dump(void) const
{
  std::map<size_t, nts::Tristate> StateMap;
  StateMap = getStateMap();
  for (int i = 0; i < 14; i++)
  {
    std::cout << "Pin number :" << i + 1 << ". State : ";
    if (StateMap[i] == nts::Tristate::TRUE)
      std::cout << "Activated";
    else if (StateMap[i] == nts::Tristate::FALSE)
      std::cout << "Desactivated";
    else
      std::cout << "Undefined";
    std::cout << ". Linked :";
    if (_linked[i])
      std::cout << " YES" << '\n';
    else
      std::cout << " NO" << '\n';
  }
}

std::map<size_t, nts::Tristate> Component4017::getStateMap() const
{
  return (_StateMap);
}
