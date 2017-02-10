#include "Parser.hpp"

Parser::Parser()
{
  _rootNode = NULL;
  _buffer = "";
  _section = "undefined";
}

Parser::~Parser()
{
}

Parser::Parser(Parser const & other)
{
  _rootNode = other._rootNode;
  _buffer = other._buffer;
  _section = other._section;
}

Parser& Parser::operator=(Parser const & other)
{
  _rootNode = other._rootNode;
  _buffer = other._buffer;
  _section = other._section;
  return *this;
}

void Parser::feed(std::string const& input)
{
  std::string buffer = input;
  size_t pos = input.find_first_of("#");
  if (pos != std::string::npos)
    buffer = input.substr(0, pos);
  if (buffer.find_first_not_of("\n") != std::string::npos)
  {
    _parseMap.push_back(buffer);
    _buffer += buffer;
  }
}

void Parser::parseTree(nts::t_ast_node& root)
{
  /*if (root)
    return;*/
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

  firstNode->lexeme = "Chipsets";
  firstNode->type = nts::ASTNodeType::SECTION;
  firstNode->value = "0";
  for (std::vector<std::string>::const_iterator i = _parseMap.begin(); i != _parseMap.end() ; ++i)
  {
    if (*i == ".chipsets:")
      _section = "chipsets";
    else if (*i == ".links:")
      _section = "links";
    if (_section == "chipsets")
    {
      if (*i != ".chipsets:")
      {
        firstNode->children->push_back(addNode(findTypeInFile(*i), nts::ASTNodeType::COMPONENT,findNameInFile(*i)));
      }
    }
    else
    {
      if (*i != ".links:")
      {
        std::cout << findSecondLinkName(*i) << '\n';
        std::cout << findSecondLinkPin(*i) << '\n';
        parseTree(firstNode->children->end());
        //firstNode->children->push_back(createNodeLink(findFirstLinkName(*i), nts::ASTNodeType::SECTION, findSecondFirstPin(*i)));
      }
      else
        firstNode->children->push_back(addNode("links", nts::ASTNodeType::SECTION, "1"));
    }
  }
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

/*nts::t_ast_node *Parser::createNodeLink(std::string line)
{

}*/

std::string Parser::getBuffer() const
{
  return (_buffer);
}

std::vector<std::string> Parser::getParseMap() const
{
  return (_parseMap);
}

void Parser::DumpParseMap() const
{

  for (std::vector<std::string>::const_iterator i = _parseMap.begin(); i != _parseMap.end(); ++i)
    std::cout << *i << '\n';
}

void Parser::CheckValidity()
{
  int val = 2;
  for (std::vector<std::string>::const_iterator i = _parseMap.begin(); i != _parseMap.end(); ++i)
    {
      if (*i == ".chipsets:")
        val--;
      if (*i == ".links:")
        val--;
    }
  if (val != 0)
  {
    std::cout << "Error : This file is not valid" << '\n';
    return ;
  }
}

std::string Parser::findTypeInFile(std::string line)
{
  std::string type = "";
  size_t pos = 0;;
  pos = line.find_first_of("\t");
  type = line.substr(0, pos);
  //std::cout << type << '\n';
  return (type);
}

std::string Parser::findNameInFile(std::string line)
{
  std::string name = "";
  size_t pos = 0;
  pos = line.find_first_of("\t");
  name = line.substr(pos + 2, line.size());
  //std::cout << name << '\n';
  return (name);
}

std::string Parser::findFirstLinkName(std::string line)
{
  std::string name = "";
  size_t pos = line.find_first_of(":");
  name = line.substr(0, pos);
  return (name);
}

std::string Parser::findFirstLinkPin(std::string line)
{
  std::string name = "";
  size_t pos = line.find_first_of(":");
  size_t pos2 = pos;
  while (line[pos2] != '\t' && line[pos2] != ' ')
    pos2++;
  name = line.substr(pos + 1, pos2);
  return (name);
}

std::string Parser::findSecondLinkName(std::string line)
{
  std::string name = "";
  size_t pos = line.find_last_of(":");
  size_t pos2 = pos;
  while (line[pos2] != '\t' && line[pos2] != 32)
    pos2--;
  while (pos2 != pos)
  {
    if (line[pos2]  != '\t'&& line[pos2] != 32)
      name += line[pos2];
    pos2++;
  }
  return (name);
}

std::string Parser::findSecondLinkPin(std::string line)
{
  std::string name = "";
  size_t pos = line.find_last_of(":");
  size_t pos2 = pos;
  while (line[pos])
    pos++;
  name = line.substr(pos2 + 1, pos);
  return (name);
}

void Parser::ComponentIsValid()
{
  /* tableau */
}

/*void Parser::createChipsets()
{
  _section = "chipsets";
  std::string type = "";
  std::string name = "";
  std::string tmp;
  size_t pos = 0;
  for (std::vector<std::string>::const_iterator i = _parseMap.begin(); *i != ".links:"; ++i)
  {
    if (*i != ".chipsets:")
    {
      tmp = *i;
      pos = tmp.find_first_of("\t");
      type = tmp.substr(0, pos);
      name = tmp.substr(pos + 2, tmp.size());
    }
  }
}*/
