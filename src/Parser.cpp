#include "Parser.hpp"

Parser::Parser()
{
  rootNode = NULL;
}

Parser::~Parser()
{
}

Parser::Parser(Parser const & other)
{
  rootNode = other.rootNode;
}

Parser& Parser::operator=(Parser const & other)
{
  rootNode = other.rootNode;
  return *this;
}

void Parser::feed(std::string const& input)
{
  (void)input;
}

void Parser::parseTree(nts::t_ast_node& root)
{
  /*if (root)
    return;*/
  std::cout << root.lexeme << std::endl;
  std::cout << (int)root.type << std::endl;
  std::cout << root.value << std::endl;
  if (root.children != NULL)
    parseChildren(root.children, root.lexeme);
}

void Parser::parseChildren(nts::t_ast_node child, std::string father)
{
  std::cout << "This node is the child of : " << father << std::endl;
  std::vector<nts::s_ast_node*>::iterator it = child.begin();
  std::cout << (*it)->lexeme << '\n';
  std::cout << (*it)->lexeme << '\n';
  std::cout << (*it)->lexeme << '\n';
}

nts::t_ast_node *Parser::createTree()
{
  std::vector<struct nts::s_ast_node*> *children = new std::vector<struct nts::s_ast_node*>();
  nts::t_ast_node *firstNode = new nts::t_ast_node(children);

  firstNode->lexeme = "VeryFirstNode";
  firstNode->type = nts::ASTNodeType::NEWLINE;
  firstNode->value = "0";
  firstNode->children->push_back(addNode());
  return (firstNode) ;
}

nts::t_ast_node *Parser::addNode()
{
  std::vector<struct nts::s_ast_node*> *children = new std::vector<struct nts::s_ast_node*>();
  nts::t_ast_node *child = new nts::t_ast_node(children);
  child->lexeme = "ChildrenNode";
  child->type = nts::ASTNodeType::DEFAULT;
  child->value = "1";
  child->children = NULL;
  return (child) ;
}
