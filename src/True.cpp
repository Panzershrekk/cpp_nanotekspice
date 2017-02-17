#include "True.hpp"

True::True()
{
  _state = nts::Tristate::UNDEFINED;
  _nbrPin = 1;
  _linked = NULL;
}

True::True(std::string basestate)
{
  (void) basestate;
  _state = nts::Tristate::TRUE;
  _nbrPin = 1;
  _linked = NULL;
}

True::~True()
{
}

True::True(True const & other)
{
  _state = other._state;
  _nbrPin = other._nbrPin;
  _link = other._link;
  _linked = other._linked;
}

True& True::operator=(True const & other)
{
  _state = other._state;
  _nbrPin = other._nbrPin;
  _link = other._link;
  _linked = other._linked;
  return *this;
}

nts::Tristate True::Compute(size_t pin_num_this)
{
  if(_nbrPin == pin_num_this)
    return (nts::Tristate::TRUE);
  else
    std::cout << "Pin does not exist" << std::endl;
  return (nts::Tristate::UNDEFINED);
}

void True::SetLink(size_t pin_num_this,
                        nts::IComponent &component,
                        size_t pin_num_target)
{
  if(_nbrPin == pin_num_this)
  {
    _link[pin_num_this] = pin_num_target;
    _linked = &component;
  }
  else
    std::cout << "Pin or component does not exist" << std::endl;
}

void True::Dump(void) const
{
  std::cout << "This true is ";
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

void True::setState(int s)
{
  if (s == 0)
    _state = nts::Tristate::FALSE;
  else if (s == 1)
    _state = nts::Tristate::TRUE;
  else
    _state = nts::Tristate::UNDEFINED;
}

nts::Tristate True::getState() const
{
  return(_state);
}
