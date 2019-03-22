#include <iostream>

#include <sbgn/SbgnTypes.h>

void printArc(SbgnArc* arc)
{
  if (arc == NULL) return;

  std::cout << "Arc" << std::endl;
  if (arc->isSetId())
  std::cout << "  id      : " << arc->getId() << std::endl;
  if (arc->isSetClazz())
  std::cout << "  class   : " << arc->getClazz() << std::endl;
  if (arc->isSetSource())
  std::cout << "  source  : " << arc->getSource() << std::endl;
  if (arc->isSetTarget())
  std::cout << "  target  : " << arc->getTarget() << std::endl;
  if (arc->getNumNexts() > 0)
  std::cout << "  # next: " << arc->getNumNexts() << std::endl;

  if (arc->isSetStart())
  {
    std::cout << "  start   : x: " << arc->getStart()->getX()
      << " y: " << arc->getStart()->getY()
      << std::endl;
  }

  for (unsigned int i = 0; i < arc->getNumNexts(); ++i)
  {
    auto* next = arc->getNext(i);
    std::cout << "  next    : x: " << next->getX()
      << " y: " << next->getY()
      << std::endl;
  }

  if (arc->isSetEnd())
  {
    std::cout << "  end     : x: " << arc->getEnd()->getX()
      << " y: " << arc->getEnd()->getY()
      << std::endl;
  }

}

void printGlyph(SbgnGlyph *glyph)
{
  if (glyph == NULL) return;

  std::cout << "Glyph" << std::endl;
  if (glyph->isSetId())
  std::cout << "  id      : " << glyph->getId() << std::endl;
  if (glyph->isSetClazz())
  std::cout << "  class   : " << glyph->getClazz() << std::endl;
  if (glyph->getNumGlyphs() > 0)
  std::cout << "  # glyphs: " << glyph->getNumGlyphs() << std::endl;
  if (glyph->getNumPorts() > 0)
  std::cout << "  # ports : " << glyph->getNumPorts() << std::endl;

}

void printMap(SbgnMap *map)
{
  if (map == NULL) return;

  std::cout << "Map" << std::endl;
  if (map->isSetId())
  std::cout << "  id      : " << map->getId() << std::endl;
  if (map->isSetLanguage())
  std::cout << "  language: " << map->getLanguageAsString() << std::endl;
  if (map->getNumGlyphs() > 0)
  std::cout << "  # glyphs: " << map->getNumGlyphs() << std::endl;
  if (map->getNumArcs() > 0)
  std::cout << "  # arcs  : " << map->getNumArcs() << std::endl;

  for (unsigned int i = 0; i < map->getNumGlyphs(); ++i)
  {
    printGlyph(map->getGlyph(i));
  }

  for (unsigned int i = 0; i < map->getNumArcs(); ++i)
  {
    printArc(map->getArc(i));
  }
}

int main(int argc, const char* argv[])
{

  if (argc != 2)
  {
    std::cout << " usage: print_sbgn <filename>" << std::endl;
    return 1;
  }

  auto* doc = readSBGNFromFile(argv[1]);

  if (!doc->getNumMaps())
  {
    std::cout << " The file has no map" << std::endl;
  }

  printMap(doc->getMap(0));

  delete doc;

  return 0;
}