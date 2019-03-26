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
  map->setLanguage("entity relationship");

  glyph = map->createGlyph();
  glyph->setId("g1");
  glyph->setClazz("entity");

  label = glyph->createLabel();
  label->setText("A");

  bbox = glyph->createBBox();
  bbox->setX(16);
  bbox->setY(100);
  bbox->setWidth(108);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("g2");
  glyph->setClazz("entity");

  label = glyph->createLabel();
  label->setText("B");

  bbox = glyph->createBBox();
  bbox->setX(296);
  bbox->setY(50);
  bbox->setWidth(108);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("g3");
  glyph->setClazz("entity");

  label = glyph->createLabel();
  label->setText("C");

  bbox = glyph->createBBox();
  bbox->setX(296);
  bbox->setY(150);
  bbox->setWidth(108);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("g5");
  glyph->setClazz("perturbing agent");

  label = glyph->createLabel();
  label->setText("Heat");

  bbox = glyph->createBBox();
  bbox->setX(156);
  bbox->setY(10);
  bbox->setWidth(108);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("g6");
  glyph->setClazz("phenotype");

  label = glyph->createLabel();
  label->setText("phenotype X");

  bbox = glyph->createBBox();
  bbox->setX(156);
  bbox->setY(200);
  bbox->setWidth(108);
  bbox->setHeight(60);

  arc = map->createArc();
  arc->setId("a1");
  arc->setClazz("absolute inhibition");
  arc->setSource("g5");
  arc->setTarget("g4_2");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(210);
  point->setY(70);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(210);
  point->setY(104);

  arc = map->createArc();
  arc->setId("a2");
  arc->setClazz("stimulation");
  arc->setSource("g4_1");
  arc->setTarget("g6");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(210);
  point->setY(157);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(210);
  point->setY(200);

  arcGroup = map->createArcGroup();
  arcGroup->setClazz("interaction");

  auto* glyph_1 = arcGroup->createGlyph();
  glyph_1->setId("g4");
  glyph_1->setClazz("interaction");

  bbox = glyph_1->createBBox();
  bbox->setX(189);
  bbox->setY(109);
  bbox->setWidth(42);
  bbox->setHeight(42);

  port = glyph_1->createPort();
  port->setId("g4_2");
  port->setX(210);
  port->setY(109);

  auto* glyph_2 = glyph_1->createGlyph();
  glyph_2->setId("g4_1");
  glyph_2->setClazz("outcome");

  bbox = glyph_2->createBBox();
  bbox->setX(204);
  bbox->setY(145);
  bbox->setWidth(12);
  bbox->setHeight(12);

  arc = arcGroup->createArc();
  arc->setId("a3");
  arc->setClazz("interaction");
  arc->setSource("g4");
  arc->setTarget("g3");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(230);
  point->setY(137);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(296);
  point->setY(161);

  arc = arcGroup->createArc();
  arc->setId("a4");
  arc->setClazz("interaction");
  arc->setSource("g4");
  arc->setTarget("g1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(189);
  point->setY(130);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(124);
  point->setY(130);

  arc = arcGroup->createArc();
  arc->setId("a5");
  arc->setClazz("interaction");
  arc->setSource("g4");
  arc->setTarget("g2");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(230);
  point->setY(123);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(296);
  point->setY(99);


    std::string outfile = "out.sbgn";
  if (argc > 1)
    outfile = argv[1];
  writeSBGNToFile(doc, outfile.c_str());

  delete doc;

  return 0;
}

