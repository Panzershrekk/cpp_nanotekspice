#ifndef  _FILEPARSE_HPP_
#define  _FILEPARSE_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

class FileParse
{
private:
  std::string _buffer;
  std::vector<std::string> _file;
public:
  FileParse();
  ~FileParse();
  FileParse(FileParse const & other);
  FileParse& operator=(FileParse const & other);

  void parseFile(std::string filename);
  void parseForTree();
};

#endif
