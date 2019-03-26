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
  map->setLanguage("activity flow");

  glyph = map->createGlyph();
  glyph->setId("g1");
  glyph->setClazz("biological activity");

  label = glyph->createLabel();
  label->setText("Grb2");

  bbox = glyph->createBBox();
  bbox->setX(76);
  bbox->setY(20);
  bbox->setWidth(108);
  bbox->setHeight(40);

  glyph = map->createGlyph();
  glyph->setId("g2");
  glyph->setClazz("biological activity");

  label = glyph->createLabel();
  label->setText("Spry");

  bbox = glyph->createBBox();
  bbox->setX(16);
  bbox->setY(126);
  bbox->setWidth(108);
  bbox->setHeight(40);

  auto* glyph_1 = glyph->createGlyph();
  glyph_1->setId("g2a");
  glyph_1->setClazz("unit of information");

  bbox = glyph_1->createBBox();
  bbox->setX(28);
  bbox->setY(157);
  bbox->setWidth(30);
  bbox->setHeight(18);

  entity = glyph_1->createEntity();
  entity->setName("unspecified entity");

  glyph = map->createGlyph();
  glyph->setId("g3");
  glyph->setClazz("biological activity");

  label = glyph->createLabel();
  label->setText("GAB1");

  bbox = glyph->createBBox();
  bbox->setX(186);
  bbox->setY(126);
  bbox->setWidth(108);
  bbox->setHeight(40);

  glyph = map->createGlyph();
  glyph->setId("g4");
  glyph->setClazz("biological activity");

  label = glyph->createLabel();
  label->setText("p85 PI3K");

  bbox = glyph->createBBox();
  bbox->setX(86);
  bbox->setY(230);
  bbox->setWidth(108);
  bbox->setHeight(40);

  arc = map->createArc();
  arc->setId("a1");
  arc->setClazz("positive influence");
  arc->setSource("g1");
  arc->setTarget("g2");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(97);
  point->setY(60);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(69);
  point->setY(126);

  auto* point1 = point->createPoint();
  point1->setElementName("point");
  point1->setX(77);
  point1->setY(75);

  auto* point2 = point->createPoint();
  point2->setElementName("point");
  point2->setX(66);
  point2->setY(100);

  arc = map->createArc();
  arc->setId("a2");
  arc->setClazz("positive influence");
  arc->setSource("g1");
  arc->setTarget("g3");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(152);
  point->setY(60);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(216);
  point->setY(126);

  arc = map->createArc();
  arc->setId("a3");
  arc->setClazz("negative influence");
  arc->setSource("g2");
  arc->setTarget("g1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(80);
  point->setY(126);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(115);
  point->setY(65);

  arc = map->createArc();
  arc->setId("a4");
  arc->setClazz("positive influence");
  arc->setSource("g3");
  arc->setTarget("g4");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(219);
  point->setY(166);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(159);
  point->setY(230);


    std::string outfile = "out.sbgn";
  if (argc > 1)
    outfile = argv[1];
  writeSBGNToFile(doc, outfile.c_str());

  delete doc;

  return 0;
}

