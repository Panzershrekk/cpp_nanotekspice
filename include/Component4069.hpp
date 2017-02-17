#ifndef _COMPONENT4069_HPP_
#define _COMPONENT4069_HPP_

#include    <map>
#include    <utility>
#include    "IComponent.hpp"

class Component4069 : public nts::IComponent
{
private:
  std::string _value;
  std::map<size_t, nts::Tristate> _StateMap;
  unsigned int  _nbrPin;
  std::map<size_t, size_t> _link;
  std::map<size_t, size_t> _pin;
  nts::IComponent *_linked[14];
public:
  Component4069(std::string);
  ~Component4069();
  Component4069(Component4069 const & other);
  Component4069& operator=(Component4069 const & other);

  nts::IComponent * createComponent4069(const std::string &value);
  virtual nts::Tristate Compute(size_t pin_num_this = 1);
  virtual void SetLink(size_t pin_num_this,
                       nts::IComponent &component,
                       size_t pin_num_target);
  virtual void Dump(void) const;
  std::map<size_t, nts::Tristate> getStateMap() const;
};

#endif
