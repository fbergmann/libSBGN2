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
  map->setMetaId("map1");
  map->setLanguage("entity relationship");

  glyph = map->createGlyph();
  glyph->setId("g1");
  glyph->setClazz("entity");

  label = glyph->createLabel();
  label->setText("A");

  bbox = glyph->createBBox();
  bbox->setX(16);
  bbox->setY(20);
  bbox->setWidth(108);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("g2");
  glyph->setClazz("entity");

  label = glyph->createLabel();
  label->setText("B");

  bbox = glyph->createBBox();
  bbox->setX(296);
  bbox->setY(20);
  bbox->setWidth(108);
  bbox->setHeight(60);

  arcGroup = map->createArcGroup();
  arcGroup->setClazz("interaction");

  auto* glyph_1 = arcGroup->createGlyph();
  glyph_1->setId("g3");
  glyph_1->setClazz("interaction");

  bbox = glyph_1->createBBox();
  bbox->setX(189);
  bbox->setY(29);
  bbox->setWidth(42);
  bbox->setHeight(42);

  arc = arcGroup->createArc();
  arc->setId("a1");
  arc->setClazz("interaction");
  arc->setSource("g3");
  arc->setTarget("g1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(189);
  point->setY(50);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(124);
  point->setY(50);

  arc = arcGroup->createArc();
  arc->setId("a2");
  arc->setClazz("interaction");
  arc->setSource("g3");
  arc->setTarget("g2");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(231);
  point->setY(50);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(296);
  point->setY(50);


  writeSBGNToFile(doc, "out.sbgn");

  delete doc;

  return 0;
}

