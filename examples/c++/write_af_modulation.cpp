#include <iostream>

#include <sbgn/SbgnTypes.h>

int main(int argc, const char* argv[])
{
  auto* doc = new SbgnDocument();

  SbgnGlyph* glyph = NULL;
  SbgnState* state = NULL;
  SbgnEntity* entity = NULL;
  SbgnCallout* co = NULL;
  SbgnGlyph* clone = NULL;
  SbgnLabel* label = NULL;
  SbgnArc*   arc = NULL;
  SbgnArcGroup* arcGroup = NULL;
  SbgnBBox*  bbox = NULL;
  SbgnPoint* point = NULL;
  SbgnPort*  port= NULL;

  auto* map = doc->createMap();
  map->setId("map1");
  map->setLanguage("activity flow");

  glyph = map->createGlyph();
  glyph->setId("g1");
  glyph->setClazz("biological activity");

  label = glyph->createLabel();
  label->setText("A");

  bbox = glyph->createBBox();
  bbox->setX(16);
  bbox->setY(20);
  bbox->setWidth(108);
  bbox->setHeight(40);

  glyph = map->createGlyph();
  glyph->setId("g2");
  glyph->setClazz("biological activity");

  label = glyph->createLabel();
  label->setText("B");

  bbox = glyph->createBBox();
  bbox->setX(16);
  bbox->setY(130);
  bbox->setWidth(108);
  bbox->setHeight(40);

  arc = map->createArc();
  arc->setId("a1");
  arc->setClazz("unknown influence");
  arc->setSource("g1");
  arc->setTarget("g2");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(70);
  point->setY(60);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(70);
  point->setY(130);


    std::string outfile = "out.sbgn";
  if (argc > 1)
    outfile = argv[1];
  writeSBGNToFile(doc, outfile.c_str());

  delete doc;

  return 0;
}

