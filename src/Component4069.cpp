#include "Component4069.hpp"

Component4069::Component4069(std::string value)
{
  _value = value;
  _nbrPin = 14;
  for (int i = 0; i < 14; i++)
  {
    _linked[i] = NULL;
    _StateMap[i] = nts::Tristate::UNDEFINED;
  }
_pin[1] = 2;
_pin[2] = 1;
_pin[3] = 4;
_pin[4] = 3;
_pin[5] = 6;
_pin[6] = 5;
_pin[8] = 9;
_pin[9] = 8;
_pin[10] = 11;
_pin[11] = 10;
_pin[12] = 13;
_pin[13] = 12;
}

Component4069::~Component4069()
{
}

Component4069::Component4069(Component4069 const & other)
{
  //_StateMap = other._StateMap;
  _nbrPin = other._nbrPin;
  _link = other._link;
  //_linked = other._linked;
}

Component4069& Component4069::operator=(Component4069 const & other)
{
  _nbrPin = other._nbrPin;
  _link = other._link;
  //_linked = other._linked;
  return *this;
}

nts::Tristate Component4069::Compute(size_t pin_num_this)
{
  if (pin_num_this >= 1 && pin_num_this <= _nbrPin)
  {
    if (pin_num_this == 2 ||
        pin_num_this == 4 ||
        pin_num_this == 6 ||
        pin_num_this == 8 ||
        pin_num_this == 10 ||
        pin_num_this == 12)
        {
          nts::Tristate fpin = _linked[_pin[pin_num_this]-1]->Compute(_link[pin_num_this]);
          if (fpin == nts::Tristate::TRUE)
            return (nts::Tristate::FALSE);
          else if (fpin == nts::Tristate::FALSE)
            return (nts::Tristate::TRUE);
        }
    if (pin_num_this == 1 ||
        pin_num_this == 3 ||
        pin_num_this == 5 ||
        pin_num_this == 9 ||
        pin_num_this == 11 ||
        pin_num_this == 13)
        {
          nts::Tristate fpin = _linked[pin_num_this - 1]->Compute(_link[pin_num_this]);
          if (fpin == nts::Tristate::TRUE)
            return (nts::Tristate::TRUE);
          else if (fpin == nts::Tristate::FALSE)
            return (nts::Tristate::FALSE);
        }
  }
  return (nts::Tristate::UNDEFINED);
}

void Component4069::SetLink(size_t pin_num_this,
                        nts::IComponent &component,
                        size_t pin_num_target)
{
  if (pin_num_this >= 1 && pin_num_this <= _nbrPin)
  {
    if (pin_num_this == 7 || pin_num_this == 14)
    {
        std::cout << "Couldn't link this pin : Invalide Pin" << '\n';
        return ;
    }
    _link[pin_num_this] = pin_num_target;
    _linked[pin_num_this - 1] = &component;
  }
  else
    std::cout << "Pin or component does not exist!!!" << std::endl;
}

void Component4069::Dump(void) const
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

std::map<size_t, nts::Tristate> Component4069::getStateMap() const
{
  return (_StateMap);
}
