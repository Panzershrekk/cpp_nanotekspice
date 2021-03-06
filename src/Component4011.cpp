#include "Component4011.hpp"
#include "SpiceExecptions.hpp"

Component4011::Component4011(std::string value)
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

Component4011::~Component4011()
{
}

Component4011::Component4011(Component4011 const & other)
{
  //_StateMap = other._StateMap;
  _nbrPin = other._nbrPin;
  _link = other._link;
  //_linked = other._linked;
}

Component4011& Component4011::operator=(Component4011 const & other)
{
  _nbrPin = other._nbrPin;
  _link = other._link;
  //_linked = other._linked;
  return *this;
}

nts::Tristate Component4011::Compute(size_t pin_num_this)
{
  if(pin_num_this >= 1 && pin_num_this <= _nbrPin /*&& _linked[pin_num_this] != NULL*/)
  {
    if (pin_num_this == 7 || pin_num_this == 14)
    {
      throw SpiceExecptions("The pin number cannot be computed");
      return nts::Tristate::UNDEFINED;
    }
    if (pin_num_this == 3 || pin_num_this == 4 || pin_num_this == 10 || pin_num_this == 11)
    {
      if (_linked[_OutLink[pin_num_this].first -1] && _linked[_OutLink[pin_num_this].second -1])
      {
        if ((_linked[_OutLink[pin_num_this].first -1])->Compute(_link[pin_num_this]) == nts::Tristate::TRUE
            && _linked[_OutLink[pin_num_this].second -1]->Compute(_link[pin_num_this]) == nts::Tristate::TRUE)
          return (_StateMap[pin_num_this - 1] = nts::Tristate::FALSE);
        else if ((_linked[_OutLink[pin_num_this].first -1])->Compute(_link[pin_num_this]) == nts::Tristate::UNDEFINED
            && _linked[_OutLink[pin_num_this].second -1]->Compute(_link[pin_num_this]) == nts::Tristate::UNDEFINED)
          return (_StateMap[pin_num_this] = nts::Tristate::UNDEFINED);
        else
        return (_StateMap[pin_num_this - 1] = nts::Tristate::TRUE);
      }
      else
        return (_StateMap[pin_num_this] = nts::Tristate::UNDEFINED);
    }
    else if (_linked[pin_num_this -1])
    {
      if (_linked[pin_num_this -1]->Compute(_link[pin_num_this]) == nts::Tristate::TRUE)
        return (_StateMap[pin_num_this - 1] = nts::Tristate::TRUE);
      else if (_linked[pin_num_this - 1]->Compute(_link[pin_num_this]) == nts::Tristate::FALSE)
        return (_StateMap[pin_num_this - 1] = nts::Tristate::FALSE);
      else
        return (_StateMap[pin_num_this -1] = nts::Tristate::UNDEFINED);
    }
  }
  return (nts::Tristate::UNDEFINED);
}

void Component4011::SetLink(size_t pin_num_this,
                        nts::IComponent &component,
                        size_t pin_num_target)
{
  if (pin_num_this >= 1 && pin_num_this <= _nbrPin)
  {
    if (pin_num_this == 7 || pin_num_this == 14)
    {
      throw SpiceExecptions("Couldn't link this pin : Invalide Pin");
      return ;
    }
    _link[pin_num_this] = pin_num_target;
    _linked[pin_num_this - 1] = &component;
  }
  else
    throw SpiceExecptions("Pin or component does not exist!!!");
}

void Component4011::Dump(void) const
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

std::map<size_t, nts::Tristate> Component4011::getStateMap() const
{
  return (_StateMap);
}
