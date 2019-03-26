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
  label->setText("tumor&#10;antigen");

  bbox = glyph->createBBox();
  bbox->setX(26);
  bbox->setY(30);
  bbox->setWidth(108);
  bbox->setHeight(60);

  auto* glyph_1 = glyph->createGlyph();
  glyph_1->setId("g1.1");
  glyph_1->setClazz("unit of information");

  label = glyph_1->createLabel();
  label->setText("TP53");

  bbox = glyph_1->createBBox();
  bbox->setX(32);
  bbox->setY(22);
  bbox->setWidth(40);
  bbox->setHeight(15);

  entity = glyph_1->createEntity();
  entity->setName("macromolecule");

  glyph = map->createGlyph();
  glyph->setId("g2");
  glyph->setClazz("biological activity");

  label = glyph->createLabel();

  bbox = glyph->createBBox();
  bbox->setX(166);
  bbox->setY(30);
  bbox->setWidth(108);
  bbox->setHeight(60);

  auto* glyph_2 = glyph->createGlyph();
  glyph_2->setId("g2.1");
  glyph_2->setClazz("unit of information");

  label = glyph_2->createLabel();
  label->setText("tp53");

  bbox = glyph_2->createBBox();
  bbox->setX(175);
  bbox->setY(22);
  bbox->setWidth(35);
  bbox->setHeight(15);

  entity = glyph_2->createEntity();
  entity->setName("nucleic acid feature");

  glyph = map->createGlyph();
  glyph->setId("g3");
  glyph->setClazz("biological activity");

  bbox = glyph->createBBox();
  bbox->setX(26);
  bbox->setY(120);
  bbox->setWidth(108);
  bbox->setHeight(60);

  auto* glyph_3 = glyph->createGlyph();
  glyph_3->setId("g3.1");
  glyph_3->setClazz("unit of information");

  label = glyph_3->createLabel();
  label->setText("lactose");

  bbox = glyph_3->createBBox();
  bbox->setX(32);
  bbox->setY(99);
  bbox->setWidth(41);
  bbox->setHeight(41);

  entity = glyph_3->createEntity();
  entity->setName("simple chemical");

  glyph = map->createGlyph();
  glyph->setId("g4");
  glyph->setClazz("biological activity");

  bbox = glyph->createBBox();
  bbox->setX(166);
  bbox->setY(120);
  bbox->setWidth(108);
  bbox->setHeight(60);

  auto* glyph_4 = glyph->createGlyph();
  glyph_4->setId("g4.1");
  glyph_4->setClazz("unit of information");

  bbox = glyph_4->createBBox();
  bbox->setX(177);
  bbox->setY(110);
  bbox->setWidth(30);
  bbox->setHeight(19);

  entity = glyph_4->createEntity();
  entity->setName("unspecified entity");

  glyph = map->createGlyph();
  glyph->setId("g5");
  glyph->setClazz("biological activity");

  label = glyph->createLabel();
  label->setText("ribosome&#10;activity");

  bbox = glyph->createBBox();
  bbox->setX(26);
  bbox->setY(210);
  bbox->setWidth(108);
  bbox->setHeight(60);

  auto* glyph_5 = glyph->createGlyph();
  glyph_5->setId("g5.1");
  glyph_5->setClazz("unit of information");

  label = glyph_5->createLabel();
  label->setText("Ribosome");

  bbox = glyph_5->createBBox();
  bbox->setX(22);
  bbox->setY(202);
  bbox->setWidth(61);
  bbox->setHeight(15);

  entity = glyph_5->createEntity();
  entity->setName("complex");

  glyph = map->createGlyph();
  glyph->setId("g6");
  glyph->setClazz("biological activity");

  bbox = glyph->createBBox();
  bbox->setX(166);
  bbox->setY(210);
  bbox->setWidth(108);
  bbox->setHeight(60);

  auto* glyph_6 = glyph->createGlyph();
  glyph_6->setId("g6.1");
  glyph_6->setClazz("unit of information");

  bbox = glyph_6->createBBox();
  bbox->setX(167);
  bbox->setY(200);
  bbox->setWidth(32);
  bbox->setHeight(20);

  entity = glyph_6->createEntity();
  entity->setName("perturbation");


    std::string outfile = "out.sbgn";
  if (argc > 1)
    outfile = argv[1];
  writeSBGNToFile(doc, outfile.c_str());

  delete doc;

  return 0;
}

