#include "Circuit.hpp"

Circuit::Circuit(int ac, char **av)
{
  int i = 2;

  _filename = av[1];
  while (i < ac)
  {
    _valueCompo[i - 2] = av[i];
    i++;
  }
}

Circuit::~Circuit()
{
}

Circuit::Circuit(Circuit const & other)
{
  (void) other;
}

Circuit& Circuit::operator=(Circuit const & other)
{
  (void) other;
  return *this;
}

void Circuit::Nanotekspice()
{
  try
   {
     ValidFile(_filename);
   }
   catch(std::exception const& e)
   {
       std::cerr << "ERROR : " << e.what() << std::endl;
       exit(1);
   }
  FileParse *fileparser = new FileParse();
  fileparser->parseFile(_filename, _valueCompo);
}

void Circuit::DumpValue()
{
  for(std::map<size_t, std::string>::iterator it = _valueCompo.begin();
    it != _valueCompo.end(); ++it)
    {
        std::cout << it->second << std::endl;
    }
}

void Circuit::ValidFile(std::string file)
{
  size_t pos = file.find_last_of('.');
  std::string check = "";
  while(file[pos])
  {
    check += file[pos];
    pos++;
  }
  if (check != ".nts")
    throw SpiceExecptions("Bad file format");
}
