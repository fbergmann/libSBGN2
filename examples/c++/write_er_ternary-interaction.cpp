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
  bbox->setX(56);
  bbox->setY(30);
  bbox->setWidth(108);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("g2");
  glyph->setClazz("entity");

  label = glyph->createLabel();
  label->setText("B");

  bbox = glyph->createBBox();
  bbox->setX(176);
  bbox->setY(30);
  bbox->setWidth(108);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("g3");
  glyph->setClazz("entity");

  label = glyph->createLabel();
  label->setText("C");

  bbox = glyph->createBBox();
  bbox->setX(296);
  bbox->setY(30);
  bbox->setWidth(108);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("g5");
  glyph->setClazz("phenotype");

  label = glyph->createLabel();
  label->setText("phenotype X");

  bbox = glyph->createBBox();
  bbox->setX(176);
  bbox->setY(250);
  bbox->setWidth(108);
  bbox->setHeight(60);

  arc = map->createArc();
  arc->setId("a1");
  arc->setClazz("stimulation");
  arc->setSource("g4_1");
  arc->setTarget("g5");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(230);
  point->setY(207);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(230);
  point->setY(250);

  arcGroup = map->createArcGroup();
  arcGroup->setClazz("interaction");

  auto* glyph_1 = arcGroup->createGlyph();
  glyph_1->setId("g4");
  glyph_1->setClazz("interaction");

  bbox = glyph_1->createBBox();
  bbox->setX(209);
  bbox->setY(159);
  bbox->setWidth(42);
  bbox->setHeight(42);

  auto* glyph_2 = glyph_1->createGlyph();
  glyph_2->setId("g4_1");
  glyph_2->setClazz("outcome");

  bbox = glyph_2->createBBox();
  bbox->setX(224);
  bbox->setY(195);
  bbox->setWidth(12);
  bbox->setHeight(12);

  arc = arcGroup->createArc();
  arc->setId("a2");
  arc->setClazz("interaction");
  arc->setSource("g4");
  arc->setTarget("g1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(215);
  point->setY(164);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(142);
  point->setY(90);

  arc = arcGroup->createArc();
  arc->setId("a3");
  arc->setClazz("interaction");
  arc->setSource("g4");
  arc->setTarget("g2");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(230);
  point->setY(159);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(230);
  point->setY(90);

  arc = arcGroup->createArc();
  arc->setId("a4");
  arc->setClazz("interaction");
  arc->setSource("g4");
  arc->setTarget("g3");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(245);
  point->setY(164);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(318);
  point->setY(90);


  writeSBGNToFile(doc, "out.sbgn");

  delete doc;

  return 0;
}

