#include "Output.hpp"

Output::Output()
{
  _state = nts::Tristate::UNDEFINED;
  _nbrPin = 1;
  _linked = NULL;
}

Output::Output(std::string value)
{
  _state = nts::Tristate::UNDEFINED;
  _nbrPin = 1;
  _linked = NULL;
  _value = value;
}

Output::~Output()
{
}

Output::Output(Output const & other)
{
  _state = other._state;
  _nbrPin = other._nbrPin;
  _link = other._link;
  _linked = other._linked;
}

Output& Output::operator=(Output const & other)
{
  _state = other._state;
  _nbrPin = other._nbrPin;
  _link = other._link;
  _linked = other._linked;
  return *this;
}

nts::Tristate Output::Compute(size_t pin_num_this)
{
  if(_nbrPin == pin_num_this)
  {
    if (_linked)
    {
      if (_linked->Compute(_link[pin_num_this]) == nts::Tristate::TRUE)
        _state = nts::Tristate::TRUE;
      else if (_linked->Compute(_link[pin_num_this]) == nts::Tristate::FALSE)
        _state = nts::Tristate::FALSE;
      else
        _state = nts::Tristate::UNDEFINED;
      std::cout << _value << "=" << (int)_state << '\n';
    }
    else
      std::cout << "Pin is not linked" << std::endl;
  }
  else
    std::cout << "Pin does not exist" << std::endl;
  return (nts::Tristate::UNDEFINED);
}

void Output::SetLink(size_t pin_num_this,
                        nts::IComponent &component,
                        size_t pin_num_target)
{
  if(_nbrPin == pin_num_this)
  {
    _link[pin_num_this] = pin_num_target;
    _linked = &component;
  }
  else
    std::cout << "Pin does not exist" << std::endl;
}

void Output::Dump(void) const
{
  std::cout << "This Output is ";
  if (getState() == nts::Tristate::FALSE)
    std::cout << "desactivated" << std::endl;
  else if (getState() == nts::Tristate::TRUE)
    std::cout << "activated" << std::endl;
  else
    std::cout << "undefined" << std::endl;
  if (_linked)
    std::cout << "Pin 1 is linked" << '\n';
  else
    std::cout << "Pin 1 is not linked" << '\n';
}

nts::Tristate Output::getState() const
{
  return(_state);
}
