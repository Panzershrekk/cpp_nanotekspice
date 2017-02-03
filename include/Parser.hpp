#ifndef  _PARSER_HPP_
#define  _PARSER_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include "IParser.hpp"

class Parser : public nts::IParser
{
public:
  nts::t_ast_node *rootNode;
public:
  Parser();
  ~Parser();
  Parser(Parser const & other);
  Parser& operator=(Parser const & other);

  nts::t_ast_node *addNode();
  void parseChildren(nts::t_ast_node, std::string);
  virtual void feed(std::string const& input);
  virtual void parseTree(nts::t_ast_node& root);
  virtual nts::t_ast_node *createTree();
};

#endif
