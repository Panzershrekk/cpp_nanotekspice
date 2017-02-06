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
  _buffer = other._buffer;
  _Chipset = other._Chipset;
}

FileParse& FileParse::operator=(FileParse const & other)
{
  _buffer = other._buffer;
  _Chipset = other._Chipset;
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
  setBuffer(parser->getBuffer());
  parseForTree();
  DumpChipsetMap();
}

void FileParse::parseForTree()
{
  int i = 2;

  std::size_t found = _buffer.find(".chipsets:");
  if (found!=std::string::npos)
    i -= 1;
  found = _buffer.find(".links:");
  if (found!=std::string::npos)
    i -= 1;
  if (i != 0)
  {
    std::cout << "The configuration file is not valid" << std::endl;
    return;
  }
  _Chipset["chipset"] = "found";
  _Chipset["input"] = "a0";
  _Chipset["input"] = "a1";
}

void FileParse::chipsetMap()
{

}

void FileParse::setBuffer(std::string buffer)
{
  this->_buffer = buffer;
}

void FileParse::DumpBuffer() const
{
  std::cout << "Buffer : " << _buffer << std::endl;
}

void FileParse::DumpChipsetMap() const
{
  for(std::map<std::string, std::string>::const_iterator it = _Chipset.begin();
    it != _Chipset.end(); ++it)
    {
      std::cout << "Index : " << it->first << std::endl;
      std::cout << "Value : " << it->second << std::endl << std::endl;
    }
}

std::map<std::string, std::string> FileParse::getMapChipset()
{
  return (_Chipset);
}

/*std::string buffer = "";
size_t pos = filename.find_last_of(".");
std::ifstream ifs(_filename.data());
_root = NULL;
_parser = new ASTFileParse(in);
if (ifs)
  {
    try {
while (std::getline(ifs, buffer))
  _parser->feed(buffer);
_root = _parser->createTree();
    } catch (nts::NtsError const& e) {
throw e;
    }
    ifs.close();
  }
else
  throw nts::FileParseError("Error: " + filename + " can't be open");
*/
