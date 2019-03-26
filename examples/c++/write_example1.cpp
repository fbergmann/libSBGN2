#include <iostream>

#include <sbgn/SbgnTypes.h>

int main(int argc, const char* argv[])
{
  auto* doc = new SbgnDocument();

  auto* map = doc->createMap();
  map->setId("map1");
  map->setLanguage(SBGNML_LANGUAGE_PROCESS_DESCRIPTION);

  auto* glyph = map->createGlyph();
  glyph->setId("glyph0");
  glyph->setClazz("macromolecule");
  auto* bounds = glyph->createBBox();
  bounds->setX(20);
  bounds->setY(20);
  bounds->setWidth(140);
  bounds->setHeight(60);

  auto* label = glyph->createLabel();
  label->setText("greek letter alpha: &#x3b1;");

    std::string outfile = "out.sbgn";
  if (argc > 1)
    outfile = argv[1];
  writeSBGNToFile(doc, outfile.c_str());

  delete doc;

  return 0;
}