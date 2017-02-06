#ifndef  _FILEPARSE_HPP_
#define  _FILEPARSE_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include <map>

class FileParse
{
private:
  std::string _buffer;
  std::map<std::string, std::string> _Chipset;
public:
  FileParse();
  ~FileParse();
  FileParse(FileParse const & other);
  FileParse& operator=(FileParse const & other);

  void chipsetMap();
  void parseFile(std::string filename);
  void parseForTree();

  void setBuffer(std::string buffer);

  void DumpBuffer() const;
  void DumpChipsetMap() const;

  std::map<std::string, std::string> getMapChipset();
};

#endif
