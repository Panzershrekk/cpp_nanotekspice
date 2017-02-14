#include "Parser.hpp"
#include "FileParse.hpp"

FileParse::FileParse()
{
  _buffer = "";
}

FileParse::~FileParse()
{
}

FileParse::FileParse(FileParse const & other)
{
  _file = other._file;
}

FileParse& FileParse::operator=(FileParse const & other)
{
  _file = other._file;
  return *this;
}

void  FileParse::parseFile(std::string filename, std::map<size_t, std::string> valueCompo)
{
  std::string buffer = "";
  std::ifstream ifs(filename.data());
  Parser *parser;
  parser = new Parser();
  nts::t_ast_node *root;
  if (ifs)
    {
      while (std::getline(ifs, buffer))
        parser->feed(buffer);
      ifs.close();
    }
  parser->CheckValidity();
  parser->setCompoValue(valueCompo);
  parser->ParseInputValue();
  //parser->DumpInputComp();
  root = parser->createTree();
  parser->parseTree(*root);
  //parser->DumpTree(*root);
  std::cout << "> ";
  for (std::string line; std::getline(std::cin, line);)
  {
    if (line == "display")
      std::cout << "alah" << '\n';
    if (line == "exit")
      exit(0);
    if (line == "dump")
      parser->DumpComponent();
    if (line == "simulate")
      parser->parseTree(*root);
    if (checkInput(line) == 1)
    {
      parser->setInputValue(line);
    }
    std::cout << "> ";
  }
}

int  FileParse::checkInput(std::string line)
{
  size_t pos = 0;

  pos = line.find_first_of("=");
  if ((int)pos == -1)
    return (0);
  return (1);
}
