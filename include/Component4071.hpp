#ifndef _COMPONENT4071_HPP_
#define _COMPONENT4071_HPP_

#include    <map>
#include    <utility>
#include    "IComponent.hpp"

class Component4071 : public nts::IComponent
{
private:
  std::string _value;
  std::map<size_t, nts::Tristate> _StateMap;
  unsigned int  _nbrPin;
  std::map<size_t, size_t> _link;
  nts::IComponent *_linked[14];
  std::map<size_t, std::pair<size_t, size_t> > _OutLink;
public:
  Component4071(std::string);
  ~Component4071();
  Component4071(Component4071 const & other);
  Component4071& operator=(Component4071 const & other);

  nts::IComponent * createComponent4071(const std::string &value);
  virtual nts::Tristate Compute(size_t pin_num_this = 1);
  virtual void SetLink(size_t pin_num_this,
                       nts::IComponent &component,
                       size_t pin_num_target);
  virtual void Dump(void) const;
  std::map<size_t, nts::Tristate> getStateMap() const;
};

#endif
