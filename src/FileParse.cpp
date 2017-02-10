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

void  FileParse::parseFile(std::string filename)
{
  std::string buffer = "";
  std::ifstream ifs(filename.data());
  Parser *parser;
  parser = new Parser();
  if (ifs)
    {
      while (std::getline(ifs, buffer))
        parser->feed(buffer);
      ifs.close();
    }
  //parser->DumpParseMap();
  parser->CheckValidity();
  parser->parseTree(*parser->createTree());
}
