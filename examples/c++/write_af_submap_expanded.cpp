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
  glyph->setId("g1");
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
  glyph->setId("g2");
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
  glyph->setId("g3");
  glyph->setClazz("biological activity");
  glyph->setCompartmentRef("g2");

  label = glyph->createLabel();
  label->setText("GiPCR");

  bbox = glyph->createBBox();
  bbox->setX(206);
  bbox->setY(130);
  bbox->setWidth(108);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("g4");
  glyph->setClazz("biological activity");
  glyph->setCompartmentRef("g2");

  label = glyph->createLabel();
  label->setText("Giα");

  bbox = glyph->createBBox();
  bbox->setX(136);
  bbox->setY(270);
  bbox->setWidth(108);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("g5");
  glyph->setClazz("biological activity");
  glyph->setCompartmentRef("g2");

  label = glyph->createLabel();
  label->setText("Gβγ");

  bbox = glyph->createBBox();
  bbox->setX(296);
  bbox->setY(270);
  bbox->setWidth(108);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("g6");
  glyph->setClazz("biological activity");
  glyph->setCompartmentRef("g2");

  label = glyph->createLabel();
  label->setText("GIRK");

  bbox = glyph->createBBox();
  bbox->setX(436);
  bbox->setY(330);
  bbox->setWidth(108);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("g7");
  glyph->setClazz("biological activity");
  glyph->setCompartmentRef("g2");

  label = glyph->createLabel();
  label->setText("adenylate&#10;cyclase");

  bbox = glyph->createBBox();
  bbox->setX(136);
  bbox->setY(410);
  bbox->setWidth(108);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("g8");
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
  glyph->setId("g9");
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
  glyph->setId("g10");
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
  glyph->setId("g11");
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
  glyph->setId("g12");
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
  arc->setId("a1");
  arc->setClazz("positive influence");
  arc->setSource("g3");
  arc->setTarget("g4");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(244);
  point->setY(190);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(204);
  point->setY(270);

  arc = map->createArc();
  arc->setId("a2");
  arc->setClazz("positive influence");
  arc->setSource("g3");
  arc->setTarget("g5");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(280);
  point->setY(190);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(332);
  point->setY(270);

  arc = map->createArc();
  arc->setId("a3");
  arc->setClazz("positive influence");
  arc->setSource("g5");
  arc->setTarget("g6");

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
  arc->setId("a4");
  arc->setClazz("negative influence");
  arc->setSource("g4");
  arc->setTarget("g7");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(190);
  point->setY(330);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(190);
  point->setY(405);

  arc = map->createArc();
  arc->setId("a5");
  arc->setClazz("equivalence arc");
  arc->setSource("g3");
  arc->setTarget("g8");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(260);
  point->setY(130);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(260);
  point->setY(70);

  arc = map->createArc();
  arc->setId("a6");
  arc->setClazz("equivalence arc");
  arc->setSource("g7");
  arc->setTarget("g9");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(190);
  point->setY(470);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(190);
  point->setY(540);

  arc = map->createArc();
  arc->setId("a7");
  arc->setClazz("equivalence arc");
  arc->setSource("g6");
  arc->setTarget("g10");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(544);
  point->setY(360);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(600);
  point->setY(360);

  arc = map->createArc();
  arc->setId("a8");
  arc->setClazz("equivalence arc");
  arc->setSource("g2");
  arc->setTarget("g11");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(515);
  point->setY(270);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(600);
  point->setY(270);

  arc = map->createArc();
  arc->setId("a9");
  arc->setClazz("equivalence arc");
  arc->setSource("g1");
  arc->setTarget("g12");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(525);
  point->setY(300);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(600);
  point->setY(300);


    std::string outfile = "out.sbgn";
  if (argc > 1)
    outfile = argv[1];
  writeSBGNToFile(doc, outfile.c_str());

  delete doc;

  return 0;
}

