#include "Parser.hpp"

Parser::Parser()
{
}

Parser::~Parser()
{
}

Parser::Parser(Parser const & other)
{
  (void) other;
}

Parser& Parser::operator=(Parser const & other)
{
  (void) other;
  return *this;
}

/*void Parse::ParseFile(std::string file)
{
}*/

void Parser::feed(std::string const& input)
{
  (void)input;
}

void Parser::parseTree(nts::t_ast_node& root)
{
  (void)root;
}

nts::t_ast_node *Parser::createTree()
{
  nts::t_ast_node *poil = NULL;
  return (poil) ;
}
