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
  glyph->setClazz("biological activity");

  label = glyph->createLabel();
  label->setText("membrane&#10;potential&#10;activity");

  bbox = glyph->createBBox();
  bbox->setX(30);
  bbox->setY(30);
  bbox->setWidth(120);
  bbox->setHeight(100);

  auto* glyph_1 = glyph->createGlyph();
  glyph_1->setId("g1a");
  glyph_1->setClazz("unit of information");

  label = glyph_1->createLabel();
  label->setText("increase in&#10;membrane&#10;potential");

  bbox = glyph_1->createBBox();
  bbox->setX(0);
  bbox->setY(0);
  bbox->setWidth(120);
  bbox->setHeight(60);

  entity = glyph_1->createEntity();
  entity->setName("perturbation");

  glyph = map->createGlyph();
  glyph->setId("g2");
  glyph->setClazz("biological activity");

  label = glyph->createLabel();
  label->setText("sodium&#10;channel&#10;activity");

  bbox = glyph->createBBox();
  bbox->setX(36);
  bbox->setY(232);
  bbox->setWidth(108);
  bbox->setHeight(75);

  auto* glyph_2 = glyph->createGlyph();
  glyph_2->setId("g2.1");
  glyph_2->setClazz("unit of information");

  label = glyph_2->createLabel();
  label->setText("sodium&#10;channel");

  bbox = glyph_2->createBBox();
  bbox->setX(39);
  bbox->setY(219);
  bbox->setWidth(46);
  bbox->setHeight(26);

  entity = glyph_2->createEntity();
  entity->setName("macromolecule");

  glyph = map->createGlyph();
  glyph->setId("g3");
  glyph->setClazz("phenotype");

  label = glyph->createLabel();
  label->setText("depolarization");

  bbox = glyph->createBBox();
  bbox->setX(30);
  bbox->setY(450);
  bbox->setWidth(120);
  bbox->setHeight(60);

  arc = map->createArc();
  arc->setId("a1");
  arc->setClazz("positive influence");
  arc->setSource("g1");
  arc->setTarget("g2");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(90);
  point->setY(90);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(90);
  point->setY(232);

  arc = map->createArc();
  arc->setId("a2");
  arc->setClazz("necessary stimulation");
  arc->setSource("g2");
  arc->setTarget("g3");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(90);
  point->setY(307);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(90);
  point->setY(450);


  writeSBGNToFile(doc, "out.sbgn");

  delete doc;

  return 0;
}

