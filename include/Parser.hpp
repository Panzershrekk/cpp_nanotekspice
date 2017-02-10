#ifndef  _PARSER_HPP_
#define  _PARSER_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
#include "IParser.hpp"
#include "IComponent.hpp"

class Parser : public nts::IParser
{
private:
  nts::t_ast_node *_rootNode;
  std::string _buffer;
  std::vector<std::string> _parseMap;
  std::string _section;
public:
  Parser();
  ~Parser();
  Parser(Parser const & other);
  Parser& operator=(Parser const & other);

  nts::t_ast_node *addNode(std::string, nts::ASTNodeType, std::string);
  //nts::t_ast node *createNodeLink(std::string);
  //nts::t_ast_node *addNode2(std::string, nts::ASTNodeType, std::string);

  void parseFile(std::string filename);
  void parseChildren(std::vector<nts::s_ast_node*>::iterator, std::string);

  std::string  getBuffer() const;
  std::vector<std::string>getParseMap() const;

  void DumpParseMap() const;
  void CheckValidity();
  std::string findTypeInFile(std::string);
  std::string findNameInFile(std::string);

  std::string findFirstLinkName(std::string);
  std::string findFirstLinkPin(std::string);

  std::string findSecondLinkName(std::string);
  std::string findSecondLinkPin(std::string);

  void ComponentIsValid();

  virtual void feed(std::string const& input);
  virtual void parseTree(nts::t_ast_node& root);
  virtual nts::t_ast_node *createTree();
};

#endif
