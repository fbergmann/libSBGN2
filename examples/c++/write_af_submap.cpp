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
  glyph->setCompartmentOrder(1);

  label = glyph->createLabel();
  label->setText("membrane");

  bbox = label->createBBox();
  bbox->setX(234);
  bbox->setY(542);
  bbox->setWidth(72);
  bbox->setHeight(18);

  bbox = glyph->createBBox();
  bbox->setX(25);
  bbox->setY(190);
  bbox->setWidth(490);
  bbox->setHeight(380);

  glyph = map->createGlyph();
  glyph->setId("g2");
  glyph->setClazz("compartment");
  glyph->setCompartmentOrder(2);

  label = glyph->createLabel();
  label->setText("cytosol");

  bbox = label->createBBox();
  bbox->setX(245);
  bbox->setY(502);
  bbox->setWidth(50);
  bbox->setHeight(18);

  bbox = glyph->createBBox();
  bbox->setX(35);
  bbox->setY(210);
  bbox->setWidth(470);
  bbox->setHeight(320);

  glyph = map->createGlyph();
  glyph->setId("g3");
  glyph->setClazz("submap");

  bbox = glyph->createBBox();
  bbox->setX(140);
  bbox->setY(300);
  bbox->setWidth(220);
  bbox->setHeight(120);

  auto* glyph_1 = glyph->createGlyph();
  glyph_1->setId("g3.1");
  glyph_1->setClazz("terminal");
  glyph_1->setOrientation("down");

  label = glyph_1->createLabel();
  label->setText("1");

  bbox = glyph_1->createBBox();
  bbox->setX(240);
  bbox->setY(300);
  bbox->setWidth(20);
  bbox->setHeight(40);

  auto* glyph_2 = glyph->createGlyph();
  glyph_2->setId("g3.2");
  glyph_2->setClazz("terminal");
  glyph_2->setOrientation("up");

  label = glyph_2->createLabel();
  label->setText("2");

  bbox = glyph_2->createBBox();
  bbox->setX(170);
  bbox->setY(380);
  bbox->setWidth(20);
  bbox->setHeight(40);

  auto* glyph_3 = glyph->createGlyph();
  glyph_3->setId("g3.3");
  glyph_3->setClazz("terminal");
  glyph_3->setOrientation("left");

  label = glyph_3->createLabel();
  label->setText("3");

  bbox = glyph_3->createBBox();
  bbox->setX(320);
  bbox->setY(380);
  bbox->setWidth(40);
  bbox->setHeight(20);

  auto* glyph_4 = glyph->createGlyph();
  glyph_4->setId("g3.4");
  glyph_4->setClazz("terminal");
  glyph_4->setOrientation("left");

  label = glyph_4->createLabel();
  label->setText("4");

  bbox = glyph_4->createBBox();
  bbox->setX(320);
  bbox->setY(310);
  bbox->setWidth(40);
  bbox->setHeight(20);

  auto* glyph_5 = glyph->createGlyph();
  glyph_5->setId("g3.5");
  glyph_5->setClazz("terminal");
  glyph_5->setOrientation("left");

  label = glyph_5->createLabel();
  label->setText("5");

  bbox = glyph_5->createBBox();
  bbox->setX(320);
  bbox->setY(340);
  bbox->setWidth(40);
  bbox->setHeight(20);

  glyph = map->createGlyph();
  glyph->setId("g4");
  glyph->setClazz("biological activity");
  glyph->setCompartmentRef("g2");

  label = glyph->createLabel();
  label->setText("ligand");

  bbox = glyph->createBBox();
  bbox->setX(196);
  bbox->setY(20);
  bbox->setWidth(108);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("g5");
  glyph->setClazz("biological activity");
  glyph->setCompartmentRef("g2");

  label = glyph->createLabel();
  label->setText("GiPCR");

  bbox = glyph->createBBox();
  bbox->setX(196);
  bbox->setY(180);
  bbox->setWidth(108);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("g6");
  glyph->setClazz("biological activity");
  glyph->setCompartmentRef("g2");

  label = glyph->createLabel();
  label->setText("GIRK");

  bbox = glyph->createBBox();
  bbox->setX(426);
  bbox->setY(360);
  bbox->setWidth(108);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("g7");
  glyph->setClazz("biological activity");
  glyph->setCompartmentRef("g2");

  label = glyph->createLabel();
  label->setText("adenylate&#10;cyclase");

  bbox = glyph->createBBox();
  bbox->setX(126);
  bbox->setY(460);
  bbox->setWidth(108);
  bbox->setHeight(60);

  arc = map->createArc();
  arc->setId("a1");
  arc->setClazz("positive influence");
  arc->setSource("g4");
  arc->setTarget("g5");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(250);
  point->setY(80);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(250);
  point->setY(180);

  arc = map->createArc();
  arc->setId("a2");
  arc->setClazz("equivalence arc");
  arc->setSource("g5");
  arc->setTarget("g3.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(250);
  point->setY(240);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(250);
  point->setY(300);

  arc = map->createArc();
  arc->setId("a3");
  arc->setClazz("equivalence arc");
  arc->setSource("g7");
  arc->setTarget("g3.2");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(180);
  point->setY(460);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(180);
  point->setY(420);

  arc = map->createArc();
  arc->setId("a4");
  arc->setClazz("equivalence arc");
  arc->setSource("g6");
  arc->setTarget("g3.3");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(426);
  point->setY(390);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(360);
  point->setY(390);

  arc = map->createArc();
  arc->setId("a5");
  arc->setClazz("equivalence arc");
  arc->setSource("g2");
  arc->setTarget("g3.4");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(505);
  point->setY(320);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(360);
  point->setY(320);

  arc = map->createArc();
  arc->setId("a6");
  arc->setClazz("equivalence arc");
  arc->setSource("g1");
  arc->setTarget("g3.5");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(515);
  point->setY(350);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(360);
  point->setY(350);


  writeSBGNToFile(doc, "out.sbgn");

  delete doc;

  return 0;
}

