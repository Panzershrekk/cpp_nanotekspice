#ifndef _CLOCK_HPP_
#define _CLOCK_HPP_

#include    <map>
#include    "IComponent.hpp"

class Clock : public nts::IComponent
{
private:
  nts::Tristate _state;
  unsigned int  _nbrPin;
  std::map<size_t, size_t> _link;
  nts::IComponent *_linked;
public:
  Clock();
  Clock(std::string);
  ~Clock();
  Clock(Clock const & other);
  Clock& operator=(Clock const & other);

  nts::IComponent * createClock(const std::string &value);
  virtual nts::Tristate Compute(size_t pin_num_this = 1);
  virtual void SetLink(size_t pin_num_this,
                       nts::IComponent &component,
                       size_t pin_num_target);
  virtual void Dump(void) const;
  void setState(int);
  nts::Tristate getState() const;
};

#endif
