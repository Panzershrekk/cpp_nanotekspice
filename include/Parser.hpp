#ifndef  _PARSER_HPP_
#define  _PARSER_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include "IParser.hpp"

class Parser : public nts::IParser
{
private:
  nts::t_ast_node *_rootNode;
  std::string _buffer;
public:
  Parser();
  ~Parser();
  Parser(Parser const & other);
  Parser& operator=(Parser const & other);

  nts::t_ast_node *addNode(std::string, nts::ASTNodeType, std::string);
  //nts::t_ast_node *addNode2(std::string, nts::ASTNodeType, std::string);

  void parseFile(std::string filename);
  void parseChildren(std::vector<nts::s_ast_node*>::iterator, std::string);

  std::string  getBuffer() const;

  virtual void feed(std::string const& input);
  virtual void parseTree(nts::t_ast_node& root);
  virtual nts::t_ast_node *createTree();
};

#endif
