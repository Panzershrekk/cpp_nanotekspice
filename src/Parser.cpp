#include "Parser.hpp"

Parser::Parser()
{
  _rootNode = NULL;
  _buffer = "";
}

Parser::~Parser()
{
}

Parser::Parser(Parser const & other)
{
  _rootNode = other._rootNode;
  _buffer = other._buffer;
}

Parser& Parser::operator=(Parser const & other)
{
  _rootNode = other._rootNode;
  _buffer = other._buffer;
  return *this;
}

void Parser::feed(std::string const& input)
{
  std::string buffer = input;
  size_t pos = input.find_first_of("#");
  if (pos != std::string::npos)
    buffer = input.substr(0, pos);
  _buffer += buffer;
  _buffer += "\n";
}

void Parser::parseTree(nts::t_ast_node& root)
{
  /*if (root)
    return;*/
  std::cout << root.lexeme << std::endl;
  std::cout << (int)root.type << std::endl;
  std::cout << root.value << std::endl;
  if (root.children != NULL)
  {
    for (std::vector<nts::s_ast_node*>::iterator it = root.children->begin(); it != root.children->end(); ++it)
      parseChildren(it, root.lexeme);
  }
}

void Parser::parseChildren(std::vector<nts::s_ast_node*>::iterator it, std::string father)
{
  std::cout << "\nThis node is the child of : " << father << std::endl;
  std::cout << "Lexeme : " <<(*it)->lexeme << std::endl;
  std::cout << "Type : " << (int)(*it)->type << std::endl;
  std::cout << "Value : " << (*it)->value << std::endl;
  if ((*it)->children != NULL)
  {
    for (std::vector<nts::s_ast_node*>::iterator it2 = (*it)->children->begin(); it2 != (*it)->children->end(); ++it2)
      parseChildren(it2, (*it)->lexeme);
  }
}

nts::t_ast_node *Parser::createTree()
{
  std::vector<struct nts::s_ast_node*> *children = new std::vector<struct nts::s_ast_node*>();
  nts::t_ast_node *firstNode = new nts::t_ast_node(children);

  firstNode->lexeme = "VeryFirstNode";
  firstNode->type = nts::ASTNodeType::NEWLINE;
  firstNode->value = "0";
  firstNode->children->push_back(addNode("ChildrenNode", nts::ASTNodeType::DEFAULT, "1"));
  firstNode->children->push_back(addNode("ChildrenNode2", nts::ASTNodeType::COMPONENT, "45678"));
  return (firstNode) ;
}

nts::t_ast_node *Parser::addNode(std::string lexeme, nts::ASTNodeType type, std::string value)
{
  std::vector<struct nts::s_ast_node*> *children = new std::vector<struct nts::s_ast_node*>();
  nts::t_ast_node *child = new nts::t_ast_node(children);

  child->lexeme = lexeme;
  child->type = type;
  child->value = value;
  child->children = NULL;
  return (child);
}

/*nts::t_ast_node *Parser::addNode2(std::string lexeme, nts::ASTNodeType type, std::string value)
{
  std::vector<struct nts::s_ast_node*> *children = new std::vector<struct nts::s_ast_node*>();
  nts::t_ast_node *child = new nts::t_ast_node(children);

  child->lexeme = lexeme;
  child->type = type;
  child->value = value;
  child->children = NULL;
  return (child);
}*/

std::string Parser::getBuffer() const
{
  return (_buffer);
}
