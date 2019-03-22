#include <iostream>

#include <sbgn/SbgnTypes.h>

int main(int argc, const char* argv[])
{
  if (argc != 3)
  {
    std::cout << " usage: echo_sbgn <input-file> <output-file>" << std::endl;
    return 1;
  }

  auto* doc = readSBGNFromFile(argv[1]);
  writeSBGNToFile(doc, argv[2]);
  delete doc;
  
  return 0;
}