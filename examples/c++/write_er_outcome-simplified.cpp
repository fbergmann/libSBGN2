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
  glyph->setId("id1");
  glyph->setClazz("entity");

  label = glyph->createLabel();
  label->setText("Sense");

  bbox = glyph->createBBox();
  bbox->setX(66);
  bbox->setY(40);
  bbox->setWidth(108);
  bbox->setHeight(60);

  auto* glyph_1 = glyph->createGlyph();
  glyph_1->setId("id1_1");
  glyph_1->setClazz("unit of information");

  label = glyph_1->createLabel();
  label->setText("mt:dna");

  bbox = glyph_1->createBBox();
  bbox->setX(96);
  bbox->setY(32);
  bbox->setWidth(48);
  bbox->setHeight(15);

  glyph = map->createGlyph();
  glyph->setId("id2");
  glyph->setClazz("entity");

  label = glyph->createLabel();
  label->setText("3' primer");

  bbox = glyph->createBBox();
  bbox->setX(66);
  bbox->setY(220);
  bbox->setWidth(108);
  bbox->setHeight(60);

  auto* glyph_2 = glyph->createGlyph();
  glyph_2->setId("id2_1");
  glyph_2->setClazz("unit of information");

  label = glyph_2->createLabel();
  label->setText("mt:dna");

  bbox = glyph_2->createBBox();
  bbox->setX(96);
  bbox->setY(272);
  bbox->setWidth(48);
  bbox->setHeight(15);

  glyph = map->createGlyph();
  glyph->setId("id3");
  glyph->setClazz("phenotype");

  label = glyph->createLabel();
  label->setText("Phenotype X");

  bbox = glyph->createBBox();
  bbox->setX(176);
  bbox->setY(130);
  bbox->setWidth(108);
  bbox->setHeight(60);

  arc = map->createArc();
  arc->setId("a1");
  arc->setClazz("interaction");
  arc->setSource("id1");
  arc->setTarget("id2");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(120);
  point->setY(100);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(120);
  point->setY(220);

  auto* glyph_3 = arc->createGlyph();
  glyph_3->setId("id4");
  glyph_3->setClazz("outcome");

  bbox = glyph_3->createBBox();
  bbox->setX(114);
  bbox->setY(154);
  bbox->setWidth(12);
  bbox->setHeight(12);

  arc = map->createArc();
  arc->setId("a2");
  arc->setClazz("stimulation");
  arc->setSource("id4");
  arc->setTarget("id3");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(126);
  point->setY(160);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(176);
  point->setY(160);


    std::string outfile = "out.sbgn";
  if (argc > 1)
    outfile = argv[1];
  writeSBGNToFile(doc, outfile.c_str());

  delete doc;

  return 0;
}

