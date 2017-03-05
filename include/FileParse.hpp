#ifndef  _FILEPARSE_HPP_
#define  _FILEPARSE_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#include <csignal>

class FileParse
{
private:
  std::string _buffer;
  std::vector<std::string> _file;
public:
  static int _loop;
  FileParse();
  ~FileParse();
  FileParse(FileParse const & other);
  FileParse& operator=(FileParse const & other);

  void parseFile(std::string filename, std::map<size_t, std::string>);
  void parseForTree();
  int checkInput(std::string);
};

void my_handler(int param);
void signal_loop(int param);

#endif
