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
  label->setText("GluR");

  bbox = glyph->createBBox();
  bbox->setX(36);
  bbox->setY(170);
  bbox->setWidth(108);
  bbox->setHeight(60);

  auto* glyph_1 = glyph->createGlyph();
  glyph_1->setId("glyph1a");
  glyph_1->setClazz("unit of information");

  label = glyph_1->createLabel();
  label->setText("mt:prot");

  bbox = glyph_1->createBBox();
  bbox->setX(67);
  bbox->setY(222);
  bbox->setWidth(46);
  bbox->setHeight(15);

  auto* glyph_2 = glyph->createGlyph();
  glyph_2->setId("glyph1b");
  glyph_2->setClazz("location");

  bbox = glyph_2->createBBox();
  bbox->setX(52);
  bbox->setY(160);
  bbox->setWidth(20);
  bbox->setHeight(20);

  auto* glyph_3 = glyph->createGlyph();
  glyph_3->setId("glyph1c");
  glyph_3->setClazz("state variable");

  bbox = glyph_3->createBBox();
  bbox->setX(99);
  bbox->setY(162);
  bbox->setWidth(36);
  bbox->setHeight(15);

  state = glyph_3->createState();
  state->setVariable("T306");

  glyph = map->createGlyph();
  glyph->setId("glyph2");
  glyph->setClazz("variable value");

  label = glyph->createLabel();
  label->setText("PSD");

  bbox = glyph->createBBox();
  bbox->setX(45);
  bbox->setY(30);
  bbox->setWidth(36);
  bbox->setHeight(20);

  glyph = map->createGlyph();
  glyph->setId("glyph3");
  glyph->setClazz("variable value");

  label = glyph->createLabel();
  label->setText("T");

  bbox = glyph->createBBox();
  bbox->setX(107);
  bbox->setY(30);
  bbox->setWidth(20);
  bbox->setHeight(20);

  arc = map->createArc();
  arc->setId("a1");
  arc->setClazz("assignment");
  arc->setSource("glyph2");
  arc->setTarget("glyph1b");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(63);
  point->setY(50);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(63);
  point->setY(160);

  port = arc->createPort();
  port->setId("glyph5");
  port->setX(63);
  port->setY(80);

  arc = map->createArc();
  arc->setId("a2");
  arc->setClazz("assignment");
  arc->setSource("glyph3");
  arc->setTarget("glyph1c");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(117);
  point->setY(50);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(117);
  point->setY(162);

  auto* glyph_4 = arc->createGlyph();
  glyph_4->setId("glyph4");
  glyph_4->setClazz("outcome");

  bbox = glyph_4->createBBox();
  bbox->setX(111);
  bbox->setY(74);
  bbox->setWidth(12);
  bbox->setHeight(12);

  arc = map->createArc();
  arc->setId("a3");
  arc->setClazz("stimulation");
  arc->setSource("glyph4");
  arc->setTarget("glyph5");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(111);
  point->setY(80);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(63);
  point->setY(80);


    std::string outfile = "out.sbgn";
  if (argc > 1)
    outfile = argv[1];
  writeSBGNToFile(doc, outfile.c_str());

  delete doc;

  return 0;
}

