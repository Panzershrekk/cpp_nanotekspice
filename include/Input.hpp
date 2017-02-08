#ifndef _INPUT_HPP_
#define _INPUT_HPP_

#include    <map>
#include    "IComponent.hpp"

class Input : public nts::IComponent
{
private:
  nts::Tristate _state;
  unsigned int  _nbrPin;
  std::map<size_t, size_t> _link;
  nts::IComponent *_linked;
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
