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
  bbox->setY(150);
  bbox->setWidth(108);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("g2");
  glyph->setClazz("entity");

  label = glyph->createLabel();
  label->setText("B");

  bbox = glyph->createBBox();
  bbox->setX(296);
  bbox->setY(150);
  bbox->setWidth(108);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("g4");
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
  arc->setSource("g3_1");
  arc->setTarget("g4");

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
  glyph_1->setId("g3");
  glyph_1->setClazz("interaction");

  bbox = glyph_1->createBBox();
  bbox->setX(209);
  bbox->setY(159);
  bbox->setWidth(42);
  bbox->setHeight(42);

  auto* glyph_2 = glyph_1->createGlyph();
  glyph_2->setId("g3_1");
  glyph_2->setClazz("outcome");

  bbox = glyph_2->createBBox();
  bbox->setX(224);
  bbox->setY(195);
  bbox->setWidth(12);
  bbox->setHeight(12);

  arc = arcGroup->createArc();
  arc->setId("a2");
  arc->setClazz("interaction");
  arc->setSource("g3");
  arc->setTarget("g1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(209);
  point->setY(180);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(124);
  point->setY(180);

  auto* glyph_3 = arc->createGlyph();
  glyph_3->setId("g5");
  glyph_3->setClazz("cardinality");

  label = glyph_3->createLabel();
  label->setText("2");

  bbox = glyph_3->createBBox();
  bbox->setX(162);
  bbox->setY(172);
  bbox->setWidth(20);
  bbox->setHeight(15);

  arc = arcGroup->createArc();
  arc->setId("a3");
  arc->setClazz("interaction");
  arc->setSource("g3");
  arc->setTarget("g2");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(251);
  point->setY(180);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(296);
  point->setY(180);


  writeSBGNToFile(doc, "out.sbgn");

  delete doc;

  return 0;
}

