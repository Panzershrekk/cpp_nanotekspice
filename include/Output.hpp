#ifndef _OUTPUT_HPP_
#define _OUTPUT_HPP_

#include    <map>
#include    "Component.hpp"

class Output : public Component
{
private:
  nts::Tristate _state;
  unsigned int  _nbrPin;
  std::map<size_t, size_t> _link;
  nts::IComponent *_linked;
public:
  Output();
  ~Output();
  Output(Output const & other);
  Output& operator=(Output const & other);

  nts::IComponent * createOutput(const std::string &value);
  virtual nts::Tristate Compute(size_t pin_num_this = 1);
  virtual void SetLink(size_t pin_num_this,
                       nts::IComponent &component,
                       size_t pin_num_target);
  virtual void Dump(void) const;
  void setState(int);
  nts::Tristate getState() const;
};

#endif
