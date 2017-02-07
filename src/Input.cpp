#include "Input.hpp"

Input::Input()
{
  _state = nts::Tristate::UNDEFINED;
  _nbrPin = 1;
}

Input::Input(std::string basestate)
{
  if (basestate == "0")
    _state = nts::Tristate::FALSE;
  else if (basestate == "1")
    _state = nts::Tristate::TRUE;
  else
    _state = nts::Tristate::UNDEFINED;
  _nbrPin = 1;
}

Input::~Input()
{
}

Input::Input(Input const & other) :  Component(other)
{
  _state = other._state;
  _nbrPin = other._nbrPin;
}

Input& Input::operator=(Input const & other)
{
  _state = other._state;
  _nbrPin = other._nbrPin;
  return *this;
}

nts::Tristate Input::Compute(size_t pin_num_this)
{
  if(_nbrPin == pin_num_this)
  {
    if (getState() == 1)
      return (nts::Tristate::TRUE);
    else if (getState() == 0)
      return (nts::Tristate::FALSE);
    else
      return (nts::Tristate::UNDEFINED);
  }
  else
    std::cout << "Pin does not exist" << std::endl;
  return (nts::Tristate::UNDEFINED);
}

void Input::SetLink(size_t pin_num_this,
                        nts::IComponent &component,
                        size_t pin_num_target)
{
  (void)pin_num_this;
  (void)component;
  (void)pin_num_target;
}

void Input::Dump(void) const
{
  std::cout << "This input is ";
  if (getState() == nts::Tristate::FALSE)
    std::cout << "desactivated" << std::endl;
  else if (getState() == nts::Tristate::TRUE)
    std::cout << "activated" << std::endl;
  else
    std::cout << "undefined" << std::endl;
}

void Input::setState(int s)
{
  if (s == 0)
    _state = nts::Tristate::FALSE;
  else if (s == 1)
    _state = nts::Tristate::TRUE;
  else
    _state = nts::Tristate::UNDEFINED;
}

nts::Tristate Input::getState() const
{
  return(_state);
}
