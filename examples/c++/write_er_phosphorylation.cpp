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
  glyph->setId("glyph1");
  glyph->setClazz("entity");

  label = glyph->createLabel();
  label->setText("CaMKII");

  bbox = glyph->createBBox();
  bbox->setX(60);
  bbox->setY(130);
  bbox->setWidth(120);
  bbox->setHeight(60);

  auto* glyph_1 = glyph->createGlyph();
  glyph_1->setId("glyph1a");
  glyph_1->setClazz("unit of information");

  label = glyph_1->createLabel();
  label->setText("mt:prot");

  bbox = glyph_1->createBBox();
  bbox->setX(97);
  bbox->setY(182);
  bbox->setWidth(46);
  bbox->setHeight(15);

  auto* glyph_2 = glyph->createGlyph();
  glyph_2->setId("glyph1b");
  glyph_2->setClazz("state variable");

  bbox = glyph_2->createBBox();
  bbox->setX(62);
  bbox->setY(122);
  bbox->setWidth(54);
  bbox->setHeight(15);

  state = glyph_2->createState();
  state->setVariable("T286");
  state->setValue("P");

  auto* glyph_3 = glyph->createGlyph();
  glyph_3->setId("glyph1c");
  glyph_3->setClazz("state variable");

  bbox = glyph_3->createBBox();
  bbox->setX(132);
  bbox->setY(122);
  bbox->setWidth(36);
  bbox->setHeight(15);

  state = glyph_3->createState();
  state->setVariable("T306");

  glyph = map->createGlyph();
  glyph->setId("glyph2");
  glyph->setClazz("variable value");

  label = glyph->createLabel();
  label->setText("T");

  bbox = glyph->createBBox();
  bbox->setX(60);
  bbox->setY(40);
  bbox->setWidth(20);
  bbox->setHeight(20);

  glyph = map->createGlyph();
  glyph->setId("glyph3");
  glyph->setClazz("variable value");

  label = glyph->createLabel();
  label->setText("F");

  bbox = glyph->createBBox();
  bbox->setX(100);
  bbox->setY(40);
  bbox->setWidth(20);
  bbox->setHeight(20);

  glyph = map->createGlyph();
  glyph->setId("glyph4");
  glyph->setClazz("variable value");

  label = glyph->createLabel();
  label->setText("P");

  bbox = glyph->createBBox();
  bbox->setX(140);
  bbox->setY(40);
  bbox->setWidth(20);
  bbox->setHeight(20);

  glyph = map->createGlyph();
  glyph->setId("glyph5");
  glyph->setClazz("implicit xor");

  bbox = glyph->createBBox();
  bbox->setX(90);
  bbox->setY(90);
  bbox->setWidth(0);
  bbox->setHeight(0);

  arc = map->createArc();
  arc->setId("a1");
  arc->setClazz("assignment");
  arc->setSource("glyph2");
  arc->setTarget("glyph5");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(75);
  point->setY(59);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(90);
  point->setY(90);

  arc = map->createArc();
  arc->setId("a2");
  arc->setClazz("assignment");
  arc->setSource("glyph3");
  arc->setTarget("glyph5");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(105);
  point->setY(59);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(90);
  point->setY(90);

  arc = map->createArc();
  arc->setId("a3");
  arc->setClazz("assignment");
  arc->setSource("glyph5");
  arc->setTarget("glyph1b");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(90);
  point->setY(90);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(90);
  point->setY(122);

  arc = map->createArc();
  arc->setId("a4");
  arc->setClazz("assignment");
  arc->setSource("glyph4");
  arc->setTarget("glyph1c");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(150);
  point->setY(60);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(150);
  point->setY(122);


    std::string outfile = "out.sbgn";
  if (argc > 1)
    outfile = argv[1];
  writeSBGNToFile(doc, outfile.c_str());

  delete doc;

  return 0;
}

