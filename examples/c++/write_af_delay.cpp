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
  label->setText("early&#10;effect");

  bbox = glyph->createBBox();
  bbox->setX(46);
  bbox->setY(180);
  bbox->setWidth(108);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("g2");
  glyph->setClazz("delay");
  glyph->setOrientation("vertical");

  bbox = glyph->createBBox();
  bbox->setX(79);
  bbox->setY(109);
  bbox->setWidth(42);
  bbox->setHeight(42);

  port = glyph->createPort();
  port->setId("g2.1");
  port->setX(100);
  port->setY(172);

  port = glyph->createPort();
  port->setId("g2.2");
  port->setX(100);
  port->setY(88);

  glyph = map->createGlyph();
  glyph->setId("g3");
  glyph->setClazz("biological activity");

  label = glyph->createLabel();
  label->setText("late&#10;effect");

  bbox = glyph->createBBox();
  bbox->setX(46);
  bbox->setY(10);
  bbox->setWidth(108);
  bbox->setHeight(60);

  arc = map->createArc();
  arc->setId("a1");
  arc->setClazz("logic arc");
  arc->setSource("g1");
  arc->setTarget("g2.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(100);
  point->setY(172);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(100);
  point->setY(151);

  arc = map->createArc();
  arc->setId("a2");
  arc->setClazz("positive influence");
  arc->setSource("g2.2");
  arc->setTarget("g3");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(100);
  point->setY(88);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(100);
  point->setY(70);


    std::string outfile = "out.sbgn";
  if (argc > 1)
    outfile = argv[1];
  writeSBGNToFile(doc, outfile.c_str());

  delete doc;

  return 0;
}

