#ifndef _INPUT_HPP_
#define _INPUT_HPP_

#include    <map>
#include    "Component.hpp"

class Input : public Component
{
private:
  nts::Tristate _state;
  unsigned int  _nbrPin;
public:
  Input();
  Input(std::string);
  ~Input();
  Input(Input const & other);
  Input& operator=(Input const & other);

  nts::IComponent * createInput(const std::string &value);
  virtual nts::Tristate Compute(size_t pin_num_this = 1);
  virtual void SetLink(size_t pin_num_this,
                       nts::IComponent &component,
                       size_t pin_num_target);
  virtual void Dump(void) const;
  void setState(int);
  nts::Tristate getState() const;
};

#endif
