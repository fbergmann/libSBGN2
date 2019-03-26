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
  glyph->setId("g1");
  glyph->setClazz("variable value");

  label = glyph->createLabel();
  label->setText("P");

  bbox = glyph->createBBox();
  bbox->setX(267);
  bbox->setY(50);
  bbox->setWidth(20);
  bbox->setHeight(20);

  glyph = map->createGlyph();
  glyph->setId("g2");
  glyph->setClazz("entity");

  label = glyph->createLabel();
  label->setText("CaMKII");

  bbox = glyph->createBBox();
  bbox->setX(142);
  bbox->setY(210);
  bbox->setWidth(180);
  bbox->setHeight(60);

  auto* glyph_1 = glyph->createGlyph();
  glyph_1->setId("g2_1");
  glyph_1->setClazz("state variable");

  bbox = glyph_1->createBBox();
  bbox->setX(159);
  bbox->setY(202);
  bbox->setWidth(56);
  bbox->setHeight(15);

  state = glyph_1->createState();
  state->setVariable("T286");
  state->setValue("P");

  auto* glyph_2 = glyph->createGlyph();
  glyph_2->setId("g2_2");
  glyph_2->setClazz("state variable");

  bbox = glyph_2->createBBox();
  bbox->setX(258);
  bbox->setY(202);
  bbox->setWidth(38);
  bbox->setHeight(15);

  state = glyph_2->createState();
  state->setVariable("T306");

  auto* glyph_3 = glyph->createGlyph();
  glyph_3->setId("g2_3");
  glyph_3->setClazz("unit of information");

  label = glyph_3->createLabel();
  label->setText("mt:prot");

  bbox = glyph_3->createBBox();
  bbox->setX(209);
  bbox->setY(262);
  bbox->setWidth(47);
  bbox->setHeight(15);

  glyph = map->createGlyph();
  glyph->setId("g3");
  glyph->setClazz("delay");

  bbox = glyph->createBBox();
  bbox->setX(71);
  bbox->setY(194);
  bbox->setWidth(42);
  bbox->setHeight(42);

  port = glyph->createPort();
  port->setId("g3_1");
  port->setX(123);
  port->setY(215);

  port = glyph->createPort();
  port->setId("g3_2");
  port->setX(61);
  port->setY(215);

  arc = map->createArc();
  arc->setId("a1");
  arc->setClazz("assignment");
  arc->setSource("g1");
  arc->setTarget("g2_2");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(277);
  point->setY(70);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(277);
  point->setY(202);

  port = arc->createPort();
  port->setId("g4");
  port->setX(277);
  port->setY(120);

  arc = map->createArc();
  arc->setId("a2");
  arc->setClazz("logic arc");
  arc->setSource("g2");
  arc->setTarget("g3_1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(142);
  point->setY(215);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(123);
  point->setY(215);

  arc = map->createArc();
  arc->setId("a3");
  arc->setClazz("necessary stimulation");
  arc->setSource("g3_2");
  arc->setTarget("g4");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(61);
  point->setY(215);

  point = arc->createNext();
  point->setElementName("next");
  point->setX(50);
  point->setY(215);

  point = arc->createNext();
  point->setElementName("next");
  point->setX(50);
  point->setY(120);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(277);
  point->setY(120);


    std::string outfile = "out.sbgn";
  if (argc > 1)
    outfile = argv[1];
  writeSBGNToFile(doc, outfile.c_str());

  delete doc;

  return 0;
}

