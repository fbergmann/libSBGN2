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
  map->setMetaId("map2");
  map->setLanguage("activity flow");

  glyph = map->createGlyph();
  glyph->setId("g01");
  glyph->setClazz("compartment");
  glyph->setCompartmentOrder(1);

  label = glyph->createLabel();
  label->setText("membrane");

  bbox = label->createBBox();
  bbox->setX(244);
  bbox->setY(493);
  bbox->setWidth(72);
  bbox->setHeight(18);

  bbox = glyph->createBBox();
  bbox->setX(35);
  bbox->setY(140);
  bbox->setWidth(490);
  bbox->setHeight(380);

  glyph = map->createGlyph();
  glyph->setId("g02");
  glyph->setClazz("compartment");
  glyph->setCompartmentOrder(2);

  label = glyph->createLabel();
  label->setText("cytosol");

  bbox = label->createBBox();
  bbox->setX(254);
  bbox->setY(452);
  bbox->setWidth(50);
  bbox->setHeight(18);

  bbox = glyph->createBBox();
  bbox->setX(45);
  bbox->setY(160);
  bbox->setWidth(470);
  bbox->setHeight(320);

  glyph = map->createGlyph();
  glyph->setId("g03");
  glyph->setClazz("biological activity");
  glyph->setCompartmentRef("g02");

  label = glyph->createLabel();
  label->setText("GiPCR");

  bbox = glyph->createBBox();
  bbox->setX(206);
  bbox->setY(130);
  bbox->setWidth(108);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("g04");
  glyph->setClazz("biological activity");
  glyph->setCompartmentRef("g02");

  label = glyph->createLabel();
  label->setText("Giα");

  bbox = glyph->createBBox();
  bbox->setX(136);
  bbox->setY(270);
  bbox->setWidth(108);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("g05");
  glyph->setClazz("biological activity");
  glyph->setCompartmentRef("g02");

  label = glyph->createLabel();
  label->setText("Gβγ");

  bbox = glyph->createBBox();
  bbox->setX(296);
  bbox->setY(270);
  bbox->setWidth(108);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("g06");
  glyph->setClazz("biological activity");
  glyph->setCompartmentRef("g02");

  label = glyph->createLabel();
  label->setText("GIRK");

  bbox = glyph->createBBox();
  bbox->setX(436);
  bbox->setY(330);
  bbox->setWidth(108);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("g07");
  glyph->setClazz("biological activity");
  glyph->setCompartmentRef("g02");

  label = glyph->createLabel();
  label->setText("adenylate&#10;cyclase");

  bbox = glyph->createBBox();
  bbox->setX(136);
  bbox->setY(410);
  bbox->setWidth(108);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("g08");
  glyph->setClazz("tag");
  glyph->setOrientation("down");

  label = glyph->createLabel();
  label->setText("1");

  bbox = glyph->createBBox();
  bbox->setX(250);
  bbox->setY(30);
  bbox->setWidth(20);
  bbox->setHeight(40);

  glyph = map->createGlyph();
  glyph->setId("g09");
  glyph->setClazz("tag");
  glyph->setOrientation("up");

  label = glyph->createLabel();
  label->setText("2");

  bbox = glyph->createBBox();
  bbox->setX(180);
  bbox->setY(540);
  bbox->setWidth(20);
  bbox->setHeight(40);

  glyph = map->createGlyph();
  glyph->setId("g010");
  glyph->setClazz("tag");
  glyph->setOrientation("left");

  label = glyph->createLabel();
  label->setText("3");

  bbox = glyph->createBBox();
  bbox->setX(600);
  bbox->setY(350);
  bbox->setWidth(40);
  bbox->setHeight(20);

  glyph = map->createGlyph();
  glyph->setId("g011");
  glyph->setClazz("tag");
  glyph->setOrientation("left");

  label = glyph->createLabel();
  label->setText("4");

  bbox = glyph->createBBox();
  bbox->setX(600);
  bbox->setY(260);
  bbox->setWidth(40);
  bbox->setHeight(20);

  glyph = map->createGlyph();
  glyph->setId("g012");
  glyph->setClazz("tag");
  glyph->setOrientation("left");

  label = glyph->createLabel();
  label->setText("5");

  bbox = glyph->createBBox();
  bbox->setX(600);
  bbox->setY(290);
  bbox->setWidth(40);
  bbox->setHeight(20);

  arc = map->createArc();
  arc->setId("a01");
  arc->setClazz("positive influence");
  arc->setSource("g03");
  arc->setTarget("g04");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(244);
  point->setY(190);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(204);
  point->setY(270);

  arc = map->createArc();
  arc->setId("a02");
  arc->setClazz("positive influence");
  arc->setSource("g03");
  arc->setTarget("g05");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(280);
  point->setY(190);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(332);
  point->setY(270);

  arc = map->createArc();
  arc->setId("a03");
  arc->setClazz("positive influence");
  arc->setSource("g05");
  arc->setTarget("g06");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(350);
  point->setY(330);

  point = arc->createNext();
  point->setElementName("next");
  point->setX(350);
  point->setY(360);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(436);
  point->setY(360);

  arc = map->createArc();
  arc->setId("a04");
  arc->setClazz("negative influence");
  arc->setSource("g04");
  arc->setTarget("g07");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(190);
  point->setY(330);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(190);
  point->setY(405);

  arc = map->createArc();
  arc->setId("a05");
  arc->setClazz("equivalence arc");
  arc->setSource("g03");
  arc->setTarget("g08");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(260);
  point->setY(130);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(260);
  point->setY(70);

  arc = map->createArc();
  arc->setId("a06");
  arc->setClazz("equivalence arc");
  arc->setSource("g07");
  arc->setTarget("g09");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(190);
  point->setY(470);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(190);
  point->setY(540);

  arc = map->createArc();
  arc->setId("a07");
  arc->setClazz("equivalence arc");
  arc->setSource("g06");
  arc->setTarget("g010");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(544);
  point->setY(360);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(600);
  point->setY(360);

  arc = map->createArc();
  arc->setId("a08");
  arc->setClazz("equivalence arc");
  arc->setSource("g02");
  arc->setTarget("g011");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(515);
  point->setY(270);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(600);
  point->setY(270);

  arc = map->createArc();
  arc->setId("a09");
  arc->setClazz("equivalence arc");
  arc->setSource("g01");
  arc->setTarget("g012");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(525);
  point->setY(300);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(600);
  point->setY(300);


  writeSBGNToFile(doc, "out.sbgn");

  delete doc;

  return 0;
}

