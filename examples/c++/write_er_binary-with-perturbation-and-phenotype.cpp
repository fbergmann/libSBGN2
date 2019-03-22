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
  bbox->setX(26);
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
  bbox->setY(100);
  bbox->setWidth(108);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("g3");
  glyph->setClazz("perturbing agent");

  label = glyph->createLabel();
  label->setText("Heat");

  bbox = glyph->createBBox();
  bbox->setX(186);
  bbox->setY(10);
  bbox->setWidth(108);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("g4");
  glyph->setClazz("phenotype");

  label = glyph->createLabel();
  label->setText("Phenotype X");

  bbox = glyph->createBBox();
  bbox->setX(126);
  bbox->setY(190);
  bbox->setWidth(108);
  bbox->setHeight(60);

  arc = map->createArc();
  arc->setId("a1");
  arc->setClazz("interaction");
  arc->setSource("g1");
  arc->setTarget("g2");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(134);
  point->setY(130);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(296);
  point->setY(130);

  port = arc->createPort();
  port->setId("g6");
  port->setX(240);
  port->setY(130);

  auto* glyph_1 = arc->createGlyph();
  glyph_1->setId("g5");
  glyph_1->setClazz("outcome");

  bbox = glyph_1->createBBox();
  bbox->setX(174);
  bbox->setY(124);
  bbox->setWidth(12);
  bbox->setHeight(12);

  arc = map->createArc();
  arc->setId("a2");
  arc->setClazz("absolute inhibition");
  arc->setSource("g3");
  arc->setTarget("g6");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(240);
  point->setY(70);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(240);
  point->setY(125);

  arc = map->createArc();
  arc->setId("a3");
  arc->setClazz("stimulation");
  arc->setSource("g5");
  arc->setTarget("g4");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(180);
  point->setY(136);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(180);
  point->setY(190);


  writeSBGNToFile(doc, "out.sbgn");

  delete doc;

  return 0;
}

