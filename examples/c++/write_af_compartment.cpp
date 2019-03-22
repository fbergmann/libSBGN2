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
  map->setLanguage("activity flow");

  glyph = map->createGlyph();
  glyph->setId("g1");
  glyph->setClazz("compartment");

  label = glyph->createLabel();
  label->setText("nucleus");

  bbox = label->createBBox();
  bbox->setX(185);
  bbox->setY(285);
  bbox->setWidth(50);
  bbox->setHeight(15);

  bbox = glyph->createBBox();
  bbox->setX(25);
  bbox->setY(30);
  bbox->setWidth(370);
  bbox->setHeight(280);

  glyph = map->createGlyph();
  glyph->setId("g2");
  glyph->setClazz("biological activity");
  glyph->setCompartmentRef("g1");

  label = glyph->createLabel();
  label->setText("co-repressor");

  bbox = glyph->createBBox();
  bbox->setX(66);
  bbox->setY(60);
  bbox->setWidth(108);
  bbox->setHeight(40);

  glyph = map->createGlyph();
  glyph->setId("g3");
  glyph->setClazz("biological activity");
  glyph->setCompartmentRef("g1");

  label = glyph->createLabel();
  label->setText("co-activator");

  bbox = glyph->createBBox();
  bbox->setX(246);
  bbox->setY(60);
  bbox->setWidth(108);
  bbox->setHeight(40);

  glyph = map->createGlyph();
  glyph->setId("g4");
  glyph->setClazz("and");
  glyph->setOrientation("vertical");

  bbox = glyph->createBBox();
  bbox->setX(189);
  bbox->setY(119);
  bbox->setWidth(42);
  bbox->setHeight(42);

  port = glyph->createPort();
  port->setId("g4.1");
  port->setX(210);
  port->setY(98);

  port = glyph->createPort();
  port->setId("g4.2");
  port->setX(210);
  port->setY(182);

  glyph = map->createGlyph();
  glyph->setId("g5");
  glyph->setClazz("phenotype");

  label = glyph->createLabel();
  label->setText("Gene&#10;transcription");

  bbox = glyph->createBBox();
  bbox->setX(156);
  bbox->setY(210);
  bbox->setWidth(108);
  bbox->setHeight(60);

  arc = map->createArc();
  arc->setId("a1");
  arc->setClazz("logic arc");
  arc->setSource("g2");
  arc->setTarget("g4.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(174);
  point->setY(90);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(210);
  point->setY(98);

  arc = map->createArc();
  arc->setId("a2");
  arc->setClazz("logic arc");
  arc->setSource("g3");
  arc->setTarget("g4.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(246);
  point->setY(90);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(210);
  point->setY(98);

  arc = map->createArc();
  arc->setId("a3");
  arc->setClazz("necessary stimulation");
  arc->setSource("g4.2");
  arc->setTarget("g5");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(210);
  point->setY(182);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(210);
  point->setY(210);


  writeSBGNToFile(doc, "out.sbgn");

  delete doc;

  return 0;
}

