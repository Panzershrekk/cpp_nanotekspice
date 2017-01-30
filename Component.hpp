#ifndef _COMPONENT_HPP_
#define _COMPONENT_HPP_

class Component
{
private:
  bool      states;
  Component *input;
  Component *output;
public:
  Component();
  ~Component();
  Component(Component const & other);
  Component& operator=(Component const & other);
};

#endif
