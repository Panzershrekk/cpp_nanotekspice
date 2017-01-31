#ifndef  _PARSER_HPP_
#define  _PARSER_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include "IParser.hpp"

class Parser : public nts::IParser
{
public:
  Parser();
  ~Parser();
  Parser(Parser const & other);
  Parser& operator=(Parser const & other);

  virtual void feed(std::string const& input);
  virtual void parseTree(nts::t_ast_node& root);
  virtual nts::t_ast_node *createTree();
};

#endif
