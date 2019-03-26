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
  label->setText("CaMKII");

  bbox = glyph->createBBox();
  bbox->setX(30);
  bbox->setY(30);
  bbox->setWidth(240);
  bbox->setHeight(60);

  auto* glyph_1 = glyph->createGlyph();
  glyph_1->setId("id2");
  glyph_1->setClazz("unit of information");

  label = glyph_1->createLabel();
  label->setText("mt:prot");

  bbox = glyph_1->createBBox();
  bbox->setX(125);
  bbox->setY(80);
  bbox->setWidth(47);
  bbox->setHeight(15);

  arc = map->createArc();
  arc->setId("a1");
  arc->setClazz("interaction");
  arc->setSource("id1");
  arc->setTarget("id1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(88);
  point->setY(90);

  point = arc->createNext();
  point->setElementName("next");
  point->setX(88);
  point->setY(168);

  point = arc->createNext();
  point->setElementName("next");
  point->setX(208);
  point->setY(168);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(208);
  point->setY(90);

  auto* glyph_2 = arc->createGlyph();
  glyph_2->setId("id3");
  glyph_2->setClazz("outcome");

  bbox = glyph_2->createBBox();
  bbox->setX(202);
  bbox->setY(132);
  bbox->setWidth(16);
  bbox->setHeight(16);

  auto* glyph_3 = arc->createGlyph();
  glyph_3->setId("id4");
  glyph_3->setClazz("cardinality");

  label = glyph_3->createLabel();
  label->setText("cis");

  bbox = glyph_3->createBBox();
  bbox->setX(114);
  bbox->setY(160);
  bbox->setWidth(30);
  bbox->setHeight(18);


    std::string outfile = "out.sbgn";
  if (argc > 1)
    outfile = argv[1];
  writeSBGNToFile(doc, outfile.c_str());

  delete doc;

  return 0;
}

