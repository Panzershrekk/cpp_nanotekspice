#include "Parser.hpp"
#include "Component.hpp"
#include "SpiceExecptions.hpp"

Parser::Parser()
{
  _rootNode = NULL;
  _buffer = "";
  _section = "undefined";
  _line = "";
  _firstName = "";
  _firstPath = 0;
  _compoType[0] = "input";
  _compoType[1] = "output";
  _compoType[2] = "4081";
  _compoType[3] = "4071";
  _compoType[4] = "4069";
  _compoType[5] = "4030";
  _compoType[6] = "4011";
  _compoType[7] = "4001";
  _compoType[8] = "clock";
  _compoType[9] = "true";
  _compoType[10] = "false";
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
    _parseMap.push_back(modifySpace(buffer));
    _buffer += buffer;
  }
}

void Parser::parseTree(nts::t_ast_node& root)
{
  if (root.children != NULL)
  {
    for (std::vector<nts::s_ast_node*>::iterator it = root.children->begin(); it != root.children->end(); ++it)
      parseChildren(it, root.lexeme);
  }
  _firstPath = 1;
}

void Parser::parseChildren(std::vector<nts::s_ast_node*>::iterator it, std::string father)
{
  (void)father;
  Component *compo = new Component();
  if ((int)(*it)->type == 2)
  {
    if ((*it)->lexeme != "output")
    {
      if ((*it)->lexeme == "clock")
      {
        if (_firstPath == 1)
        {
          nts::Tristate test = _allComp[(*it)->value]->Compute(1);
          if (test == nts::Tristate::TRUE)
            _allComp[(*it)->value] = compo->createComponent((*it)->lexeme, "0");
          else if (test == nts::Tristate::FALSE)
            _allComp[(*it)->value] = compo->createComponent((*it)->lexeme, "1");
        }
        else if (_inputComp[(*it)->value] != "")
          _allComp[(*it)->value] = compo->createComponent((*it)->lexeme, _inputComp[(*it)->value]);
        else
          _allComp[(*it)->value] = compo->createComponent((*it)->lexeme, "0");
      }
      else
      {
        if (_inputComp[(*it)->value] != "")
          _allComp[(*it)->value] = compo->createComponent((*it)->lexeme, _inputComp[(*it)->value]);
        else
        _allComp[(*it)->value] = compo->createComponent((*it)->lexeme, "0");
      }
    }
    else
      _allComp[(*it)->value] = compo->createComponent((*it)->lexeme, (*it)->value);
  }
  else if((int)(*it)->type == 3)
  {
    _firstName = (*it)->lexeme;
    _firstPin = atoi((*it)->value.c_str());
  }
  else if((int)(*it)->type == 4)
  {
    _allComp[_firstName]->SetLink(_firstPin , *_allComp[(*it)->lexeme], atoi((*it)->value.c_str()));
    _allComp[(*it)->lexeme]->SetLink(atoi((*it)->value.c_str()) , *_allComp[_firstName], _firstPin);

    //std::cout << _firstPin << "," << (*it)->lexeme << "," << atoi((*it)->value.c_str()) <<'\n';

    _allComp[(*it)->lexeme]->Compute(atoi((*it)->value.c_str()));
    //std::cout << atoi((*it)->value.c_str()) << "," << _firstName << "," <<_firstPin << '\n';
    _allComp[_firstName]->Compute(_firstPin);
  }
  if ((*it)->children != NULL)
  {
    for (std::vector<nts::s_ast_node*>::iterator it2 = (*it)->children->begin(); it2 != (*it)->children->end(); ++it2)
    {
      parseChildren(it2, (*it)->lexeme);
    }
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
    _line = *i;
    if (*i == ".chipsets:")
      _section = "chipsets";
    else if (*i == ".links:")
      _section = "links";
    if (_section == "chipsets")
    {
      if (*i != ".chipsets:")
      {
        if(checkTypeValue(findTypeInFile(*i)) == 1)
          throw SpiceExecptions("Component " + findTypeInFile(*i) + " does not exists");
        firstNode->children->push_back(addNode(findTypeInFile(*i), nts::ASTNodeType::COMPONENT,findNameInFile(*i)));
      }
    }
    else
    {
      if (*i != ".links:")
      {
        firstNode->children->back()->children->push_back(addNode(findFirstLinkName(_line), nts::ASTNodeType::LINK, findFirstLinkPin(_line)));
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
  child->children = children;
  if (type == nts::ASTNodeType::LINK)
  {
    child->children->push_back(addNode(findSecondLinkName(_line), nts::ASTNodeType::LINK_END, findSecondLinkPin(_line)));
  }
  return (child);
}

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
  std::string section = "";
  for (std::vector<std::string>::const_iterator i = _parseMap.begin(); i != _parseMap.end(); ++i)
    {
      if (*i == ".chipsets:")
        val--;
      if (*i == ".links:")
        val--;
    }
  if (val != 0)
    throw SpiceExecptions("A Section is missing");
  for (std::vector<std::string>::const_iterator i = _parseMap.begin(); i != _parseMap.end(); ++i)
  {
    if (section == "link")
    {
      if (!std::regex_match(*i, std::regex("[a-zA-Z0-9]+:[0-9]+[\t]+[a-zA-Z0-9]+:[0-9]+")))
        throw SpiceExecptions("Link section is invalid");
    }
    if (*i == ".links:")
      section = "link";
  }
}

std::string Parser::findTypeInFile(std::string line)
{
  std::string type = "";
  size_t pos = 0;;
  pos = line.find_first_of("\t");
  type = line.substr(0, pos);
  return (type);
}

std::string Parser::findNameInFile(std::string line)
{
  std::string name = "";
  size_t pos = 0;
  pos = line.find_first_of("\t");
  name = line.substr(pos + 1/*2*/, line.size());
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
  size_t pos2 = line.find_first_of("\t");
  pos2 = pos2 - pos;
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

int Parser::checkTypeValue(std::string str)
{
  int i = 0;

  for(std::map<size_t, std::string>::iterator it = _compoType.begin();
    it != _compoType.end(); ++it)
    {
      if (it->second == str)
        i++;
    }
  if (i == 0)
    return (1);
  return(0);
}

void Parser::DumpTree(nts::t_ast_node& root)
{
  std::cout << "Lexeme : " << root.lexeme << std::endl;
  std::cout << "Type : " << (int)root.type << std::endl;
  std::cout << "Value : " << root.value << std::endl;
  if (root.children != NULL)
  {
    for (std::vector<nts::s_ast_node*>::iterator it = root.children->begin(); it != root.children->end(); ++it)
      DumpChildren(it, root.lexeme);
  }
}

void Parser::DumpChildren(std::vector<nts::s_ast_node*>::iterator it, std::string father)
{
  std::cout << "\nThis node is the child of : " << father << std::endl;
  std::cout << "Lexeme : " <<(*it)->lexeme << std::endl;
  std::cout << "Type : " << (int)(*it)->type << std::endl;
  std::cout << "Value : " << (*it)->value << std::endl;
  if ((*it)->children != NULL)
  {
    for (std::vector<nts::s_ast_node*>::iterator it2 = (*it)->children->begin(); it2 != (*it)->children->end(); ++it2)
      DumpChildren(it2, (*it)->lexeme);
  }
}

void Parser::DumpComponent()
{
  for(std::map<std::string, nts::IComponent*>::iterator it = _allComp.begin();
    it != _allComp.end(); ++it)
    {
      it->second->Dump();
    }
}

void Parser::setCompoValue(std::map<size_t, std::string> comp)
{
  _valueCompo = comp;
}

void Parser::setInputValue(std::string line)
{
  size_t pos = 0;

  pos = line.find_first_of("=");
  if ((line.substr(pos + 1, line.size()) < "0") || (line.substr(pos + 1, line.size()) > "1"))
    throw SpiceExecptions("The input value is not valid !");
  _inputComp[line.substr(0, pos)] = line.substr(pos + 1, line.size());
}

void Parser::ParseInputValue()
{
  for(std::map<size_t, std::string>::iterator it = _valueCompo.begin();
    it != _valueCompo.end(); ++it)
    {
      size_t pos = 0;

      pos = it->second.find_first_of("=");
      _inputComp[it->second.substr(0, pos)] = it->second.substr(pos + 1, it->second.size());
    }
}

void Parser::DumpInputComp()
{
  for (std::map<std::string, std::string>::iterator it = _inputComp.begin();
    it != _inputComp.end(); ++it)
    {
      std::cout << it->first << '\n';
      std::cout << it->second << '\n';
    }
}

std::string  Parser::modifySpace(std::string s)
{
  bool space = false;
 auto p = s.begin();
 for (auto ch : s)
   if (std::isspace(ch))
   {
     space = p != s.begin();
   }
   else
   {
     if (space) *p++ = '\t';
     *p++ = ch;
     space = false;
   }
 s.erase(p, s.end());
 return (s);
}
