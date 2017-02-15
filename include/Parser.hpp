#ifndef  _PARSER_HPP_
#define  _PARSER_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
//#include "SpiceExecptions.hpp"
#include "IParser.hpp"
#include "IComponent.hpp"

class Parser : public nts::IParser
{
private:
  nts::t_ast_node *_rootNode;
  std::string _buffer;
  std::vector<std::string> _parseMap;
  std::string _section;
  std::string _line;
  std::string _firstName;
  size_t _firstPin;
  std::map<std::string, nts::IComponent *> _allComp;
  std::map<size_t, std::string> _valueCompo;
  std::map<std::string, std::string> _inputComp;
  int _firstPath;

public:
  Parser();
  ~Parser();
  Parser(Parser const & other);
  Parser& operator=(Parser const & other);

  nts::t_ast_node *addNode(std::string, nts::ASTNodeType, std::string);
  nts::t_ast_node *createNodeLink(std::string, std::vector<struct nts::s_ast_node*>);

  void parseFile(std::string filename);
  void parseChildren(std::vector<nts::s_ast_node*>::iterator, std::string);

  void DumpTree(nts::t_ast_node& root);
  void DumpChildren(std::vector<nts::s_ast_node*>::iterator, std::string father);

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
  void DumpComponent();

  void setCompoValue(std::map<size_t, std::string>);
  void ParseInputValue();
  void DumpInputComp();
  void setInputValue(std::string);

  virtual void feed(std::string const& input);
  virtual void parseTree(nts::t_ast_node& root);
  virtual nts::t_ast_node *createTree();
};

#endif
