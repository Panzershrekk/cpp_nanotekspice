#ifndef _COMPONENT4081_HPP_
#define _COMPONENT4081_HPP_

#include    <map>
#include    <utility>
#include    "IComponent.hpp"

class Component4081 : public nts::IComponent
{
private:
  std::map<size_t, nts::Tristate> _StateMap;
  unsigned int  _nbrPin;
  std::map<size_t, size_t> _link;
  nts::IComponent *_linked[14];
  std::map<size_t, std::pair<size_t, size_t> > _OutLink;
public:
  Component4081();
  ~Component4081();
  Component4081(Component4081 const & other);
  Component4081& operator=(Component4081 const & other);

  nts::IComponent * createComponent4081(const std::string &value);
  virtual nts::Tristate Compute(size_t pin_num_this = 1);
  virtual void SetLink(size_t pin_num_this,
                       nts::IComponent &component,
                       size_t pin_num_target);
  virtual void Dump(void) const;
  std::map<size_t, nts::Tristate> getStateMap() const;
};

#endif
