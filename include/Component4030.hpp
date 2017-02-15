#ifndef _COMPONENT4030_HPP_
#define _COMPONENT4030_HPP_

#include    <map>
#include    <utility>
#include    "IComponent.hpp"

class Component4030 : public nts::IComponent
{
private:
  std::string _value;
  std::map<size_t, nts::Tristate> _StateMap;
  unsigned int  _nbrPin;
  std::map<size_t, size_t> _link;
  nts::IComponent *_linked[14];
  std::map<size_t, std::pair<size_t, size_t> > _OutLink;
public:
  Component4030(std::string);
  ~Component4030();
  Component4030(Component4030 const & other);
  Component4030& operator=(Component4030 const & other);

  nts::IComponent * createComponent4030(const std::string &value);
  virtual nts::Tristate Compute(size_t pin_num_this = 1);
  virtual void SetLink(size_t pin_num_this,
                       nts::IComponent &component,
                       size_t pin_num_target);
  virtual void Dump(void) const;
  std::map<size_t, nts::Tristate> getStateMap() const;
};

#endif
