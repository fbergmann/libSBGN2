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
  glyph->setId("glyph1");
  glyph->setClazz("entity");

  label = glyph->createLabel();
  label->setText("Sense");

  bbox = glyph->createBBox();
  bbox->setX(36);
  bbox->setY(40);
  bbox->setWidth(108);
  bbox->setHeight(60);

  auto* glyph_1 = glyph->createGlyph();
  glyph_1->setId("glyph1a");
  glyph_1->setClazz("unit of information");

  label = glyph_1->createLabel();
  label->setText("mt:DNA");

  bbox = glyph_1->createBBox();
  bbox->setX(66);
  bbox->setY(32);
  bbox->setWidth(45);
  bbox->setHeight(15);

  auto* glyph_2 = glyph->createGlyph();
  glyph_2->setId("glyph1b");
  glyph_2->setClazz("existence");

  bbox = glyph_2->createBBox();
  bbox->setX(80);
  bbox->setY(90);
  bbox->setWidth(20);
  bbox->setHeight(20);

  glyph = map->createGlyph();
  glyph->setId("glyph2");
  glyph->setClazz("variable value");

  label = glyph->createLabel();
  label->setText("T");

  bbox = glyph->createBBox();
  bbox->setX(80);
  bbox->setY(170);
  bbox->setWidth(20);
  bbox->setHeight(20);

  arc = map->createArc();
  arc->setId("a1");
  arc->setClazz("assignment");
  arc->setSource("glyph2");
  arc->setTarget("glyph1b");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(90);
  point->setY(170);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(90);
  point->setY(110);


  writeSBGNToFile(doc, "out.sbgn");

  delete doc;

  return 0;
}

