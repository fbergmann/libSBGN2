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
  map->setLanguage("entity relationship");

  glyph = map->createGlyph();
  glyph->setId("glyph2");
  glyph->setClazz("entity");

  label = glyph->createLabel();
  label->setText("Entity with&#10;State Location");

  bbox = glyph->createBBox();
  bbox->setX(390);
  bbox->setY(405);
  bbox->setWidth(140);
  bbox->setHeight(70);

  auto* glyph_1 = glyph->createGlyph();
  glyph_1->setId("glyph2a");
  glyph_1->setClazz("location");

  bbox = glyph_1->createBBox();
  bbox->setX(414);
  bbox->setY(389);
  bbox->setWidth(22);
  bbox->setHeight(32);

  glyph = map->createGlyph();
  glyph->setId("glyph3");
  glyph->setClazz("entity");

  label = glyph->createLabel();
  label->setText("Entity with&#10;State Variable");

  bbox = glyph->createBBox();
  bbox->setX(390);
  bbox->setY(205);
  bbox->setWidth(140);
  bbox->setHeight(70);

  auto* glyph_2 = glyph->createGlyph();
  glyph_2->setId("glyph3a");
  glyph_2->setClazz("state variable");

  bbox = glyph_2->createBBox();
  bbox->setX(397);
  bbox->setY(196.5);
  bbox->setWidth(56);
  bbox->setHeight(17);

  state = glyph_2->createState();
  state->setVariable("var");
  state->setValue("val");

  glyph = map->createGlyph();
  glyph->setId("glyph4");
  glyph->setClazz("entity");

  label = glyph->createLabel();
  label->setText("Entity with&#10;Unit of Information");

  bbox = glyph->createBBox();
  bbox->setX(390);
  bbox->setY(105);
  bbox->setWidth(140);
  bbox->setHeight(70);

  auto* glyph_3 = glyph->createGlyph();
  glyph_3->setId("glyph4a");
  glyph_3->setClazz("unit of information");

  label = glyph_3->createLabel();
  label->setText("pre:label");

  bbox = glyph_3->createBBox();
  bbox->setX(397);
  bbox->setY(96.5);
  bbox->setWidth(56);
  bbox->setHeight(17);

  glyph = map->createGlyph();
  glyph->setId("glyph5");
  glyph->setClazz("entity");

  label = glyph->createLabel();
  label->setText("Entity with&#10;State Existence");

  bbox = glyph->createBBox();
  bbox->setX(390);
  bbox->setY(305);
  bbox->setWidth(140);
  bbox->setHeight(70);

  auto* glyph_4 = glyph->createGlyph();
  glyph_4->setId("glyph5a");
  glyph_4->setClazz("existence");

  bbox = glyph_4->createBBox();
  bbox->setX(414);
  bbox->setY(292.5);
  bbox->setWidth(22);
  bbox->setHeight(25);

  glyph = map->createGlyph();
  glyph->setId("glyph6");
  glyph->setClazz("annotation");

  label = glyph->createLabel();
  label->setText("Annotation");

  bbox = glyph->createBBox();
  bbox->setX(390);
  bbox->setY(575);
  bbox->setWidth(140);
  bbox->setHeight(70);

  glyph = map->createGlyph();
  glyph->setId("glyph7");
  glyph->setClazz("perturbing agent");

  label = glyph->createLabel();
  label->setText("Perturbing&#10;Agent");

  bbox = glyph->createBBox();
  bbox->setX(110);
  bbox->setY(405);
  bbox->setWidth(140);
  bbox->setHeight(70);

  glyph = map->createGlyph();
  glyph->setId("glyph8");
  glyph->setClazz("phenotype");

  label = glyph->createLabel();
  label->setText("Phenotype");

  bbox = glyph->createBBox();
  bbox->setX(705);
  bbox->setY(445);
  bbox->setWidth(140);
  bbox->setHeight(70);

  glyph = map->createGlyph();
  glyph->setId("glyph23");
  glyph->setClazz("variable value");

  label = glyph->createLabel();
  label->setText("Variable Value");

  bbox = glyph->createBBox();
  bbox->setX(715);
  bbox->setY(615);
  bbox->setWidth(120);
  bbox->setHeight(30);

  glyph = map->createGlyph();
  glyph->setId("glyph27");
  glyph->setClazz("and");

  bbox = glyph->createBBox();
  bbox->setX(105);
  bbox->setY(515);
  bbox->setWidth(50);
  bbox->setHeight(50);

  glyph = map->createGlyph();
  glyph->setId("glyph28");
  glyph->setClazz("not");

  bbox = glyph->createBBox();
  bbox->setX(105);
  bbox->setY(610);
  bbox->setWidth(50);
  bbox->setHeight(50);

  glyph = map->createGlyph();
  glyph->setId("glyph29");
  glyph->setClazz("delay");

  bbox = glyph->createBBox();
  bbox->setX(205);
  bbox->setY(610);
  bbox->setWidth(50);
  bbox->setHeight(50);

  glyph = map->createGlyph();
  glyph->setId("glyph31");
  glyph->setClazz("or");

  bbox = glyph->createBBox();
  bbox->setX(205);
  bbox->setY(515);
  bbox->setWidth(50);
  bbox->setHeight(50);

  glyph = map->createGlyph();
  glyph->setId("glyph1");
  glyph->setClazz("entity");

  label = glyph->createLabel();
  label->setText("Entity");

  bbox = glyph->createBBox();
  bbox->setX(110);
  bbox->setY(105);
  bbox->setWidth(140);
  bbox->setHeight(70);

  glyph = map->createGlyph();
  glyph->setId("glyph0");
  glyph->setClazz("entity");

  label = glyph->createLabel();
  label->setText("Entity");

  bbox = glyph->createBBox();
  bbox->setX(110);
  bbox->setY(305);
  bbox->setWidth(140);
  bbox->setHeight(70);

  glyph = map->createGlyph();
  glyph->setId("glyph14");
  glyph->setClazz("entity");

  label = glyph->createLabel();
  label->setText("Source&#10;Entity");

  bbox = glyph->createBBox();
  bbox->setX(1000);
  bbox->setY(587.5);
  bbox->setWidth(100);
  bbox->setHeight(55);

  glyph = map->createGlyph();
  glyph->setId("glyph30");
  glyph->setClazz("and");

  bbox = glyph->createBBox();
  bbox->setX(1225);
  bbox->setY(590);
  bbox->setWidth(50);
  bbox->setHeight(50);

  port = glyph->createPort();
  port->setId("glyph30.1");
  port->setX(1200);
  port->setY(615);

  glyph = map->createGlyph();
  glyph->setId("glyph33");
  glyph->setClazz("variable value");

  label = glyph->createLabel();
  label->setText("val");

  bbox = glyph->createBBox();
  bbox->setX(729);
  bbox->setY(92);
  bbox->setWidth(40);
  bbox->setHeight(16);

  glyph = map->createGlyph();
  glyph->setId("glyph22");
  glyph->setClazz("entity");

  label = glyph->createLabel();
  label->setText("Entity");

  bbox = glyph->createBBox();
  bbox->setX(725);
  bbox->setY(170);
  bbox->setWidth(100);
  bbox->setHeight(50);

  auto* glyph_5 = glyph->createGlyph();
  glyph_5->setId("glyph22a");
  glyph_5->setClazz("state variable");

  bbox = glyph_5->createBBox();
  bbox->setX(722);
  bbox->setY(161.5);
  bbox->setWidth(56);
  bbox->setHeight(17);

  state = glyph_5->createState();
  state->setVariable("var");
  state->setValue("val");

  glyph = map->createGlyph();
  glyph->setId("glyph25");
  glyph->setClazz("entity");

  label = glyph->createLabel();
  label->setText("Entity");

  bbox = glyph->createBBox();
  bbox->setX(830);
  bbox->setY(240);
  bbox->setWidth(80);
  bbox->setHeight(40);

  glyph = map->createGlyph();
  glyph->setId("glyph26");
  glyph->setClazz("entity");

  label = glyph->createLabel();
  label->setText("Entity");

  bbox = glyph->createBBox();
  bbox->setX(830);
  bbox->setY(380);
  bbox->setWidth(80);
  bbox->setHeight(40);

  glyph = map->createGlyph();
  glyph->setId("glyph24");
  glyph->setClazz("entity");

  label = glyph->createLabel();
  label->setText("Entity");

  bbox = glyph->createBBox();
  bbox->setX(640);
  bbox->setY(310);
  bbox->setWidth(80);
  bbox->setHeight(40);

  glyph = map->createGlyph();
  glyph->setId("glyph9");
  glyph->setClazz("entity");

  label = glyph->createLabel();
  label->setText("Source&#10;Entity");

  bbox = glyph->createBBox();
  bbox->setX(1000);
  bbox->setY(187.5);
  bbox->setWidth(100);
  bbox->setHeight(55);

  glyph = map->createGlyph();
  glyph->setId("glyph18");
  glyph->setClazz("phenotype");

  label = glyph->createLabel();
  label->setText("Target");

  bbox = glyph->createBBox();
  bbox->setX(1200);
  bbox->setY(187.5);
  bbox->setWidth(100);
  bbox->setHeight(55);

  glyph = map->createGlyph();
  glyph->setId("glyph10");
  glyph->setClazz("entity");

  label = glyph->createLabel();
  label->setText("Source&#10;Entity");

  bbox = glyph->createBBox();
  bbox->setX(1000);
  bbox->setY(267.5);
  bbox->setWidth(100);
  bbox->setHeight(55);

  glyph = map->createGlyph();
  glyph->setId("glyph17");
  glyph->setClazz("phenotype");

  label = glyph->createLabel();
  label->setText("Target");

  bbox = glyph->createBBox();
  bbox->setX(1200);
  bbox->setY(267.5);
  bbox->setWidth(100);
  bbox->setHeight(55);

  glyph = map->createGlyph();
  glyph->setId("glyph12");
  glyph->setClazz("entity");

  label = glyph->createLabel();
  label->setText("Source&#10;Entity");

  bbox = glyph->createBBox();
  bbox->setX(1000);
  bbox->setY(347.5);
  bbox->setWidth(100);
  bbox->setHeight(55);

  glyph = map->createGlyph();
  glyph->setId("glyph21");
  glyph->setClazz("phenotype");

  label = glyph->createLabel();
  label->setText("Target");

  bbox = glyph->createBBox();
  bbox->setX(1200);
  bbox->setY(347.5);
  bbox->setWidth(100);
  bbox->setHeight(55);

  glyph = map->createGlyph();
  glyph->setId("glyph13");
  glyph->setClazz("entity");

  label = glyph->createLabel();
  label->setText("Source&#10;Entity");

  bbox = glyph->createBBox();
  bbox->setX(1000);
  bbox->setY(507.5);
  bbox->setWidth(100);
  bbox->setHeight(55);

  glyph = map->createGlyph();
  glyph->setId("glyph20");
  glyph->setClazz("phenotype");

  label = glyph->createLabel();
  label->setText("Target");

  bbox = glyph->createBBox();
  bbox->setX(1200);
  bbox->setY(507.5);
  bbox->setWidth(100);
  bbox->setHeight(55);

  glyph = map->createGlyph();
  glyph->setId("glyph11");
  glyph->setClazz("entity");

  label = glyph->createLabel();
  label->setText("Source&#10;Entity");

  bbox = glyph->createBBox();
  bbox->setX(1000);
  bbox->setY(427.5);
  bbox->setWidth(100);
  bbox->setHeight(55);

  glyph = map->createGlyph();
  glyph->setId("glyph16");
  glyph->setClazz("phenotype");

  label = glyph->createLabel();
  label->setText("Target");

  bbox = glyph->createBBox();
  bbox->setX(1200);
  bbox->setY(427.5);
  bbox->setWidth(100);
  bbox->setHeight(55);

  glyph = map->createGlyph();
  glyph->setId("glyph15");
  glyph->setClazz("entity");

  label = glyph->createLabel();
  label->setText("Source&#10;Entity");

  bbox = glyph->createBBox();
  bbox->setX(1000);
  bbox->setY(107.5);
  bbox->setWidth(100);
  bbox->setHeight(55);

  glyph = map->createGlyph();
  glyph->setId("glyph19");
  glyph->setClazz("phenotype");

  label = glyph->createLabel();
  label->setText("Target");

  bbox = glyph->createBBox();
  bbox->setX(1200);
  bbox->setY(107.5);
  bbox->setWidth(100);
  bbox->setHeight(55);

  arc = map->createArc();
  arc->setId("arc0");
  arc->setClazz("interaction");
  arc->setSource("glyph1");
  arc->setTarget("glyph0");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(180);
  point->setY(175);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(180);
  point->setY(305);

  auto* glyph_6 = arc->createGlyph();
  glyph_6->setId("arc0.0");
  glyph_6->setClazz("outcome");

  bbox = glyph_6->createBBox();
  bbox->setX(170);
  bbox->setY(230);
  bbox->setWidth(20);
  bbox->setHeight(20);

  arc = map->createArc();
  arc->setId("arc1");
  arc->setClazz("logic arc");
  arc->setSource("glyph14");
  arc->setTarget("glyph30.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(1100);
  point->setY(615);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(1200);
  point->setY(615);

  arc = map->createArc();
  arc->setId("arc2");
  arc->setClazz("assignment");
  arc->setSource("glyph33");
  arc->setTarget("glyph22");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(751.189);
  point->setY(108);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(750);
  point->setY(165);

  arc = map->createArc();
  arc->setId("arc6");
  arc->setClazz("stimulation");
  arc->setSource("glyph9");
  arc->setTarget("glyph18");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(1100);
  point->setY(215);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(1200);
  point->setY(215);

  arc = map->createArc();
  arc->setId("arc7");
  arc->setClazz("necessary stimulation");
  arc->setSource("glyph10");
  arc->setTarget("glyph17");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(1100);
  point->setY(295);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(1200);
  point->setY(295);

  arc = map->createArc();
  arc->setId("arc8");
  arc->setClazz("absolute stimulation");
  arc->setSource("glyph12");
  arc->setTarget("glyph21");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(1100);
  point->setY(375);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(1200);
  point->setY(375);

  arc = map->createArc();
  arc->setId("arc9");
  arc->setClazz("absolute inhibition");
  arc->setSource("glyph13");
  arc->setTarget("glyph20");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(1100);
  point->setY(535);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(1200);
  point->setY(535);

  arc = map->createArc();
  arc->setId("arc10");
  arc->setClazz("inhibition");
  arc->setSource("glyph11");
  arc->setTarget("glyph16");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(1100);
  point->setY(455);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(1200);
  point->setY(455);

  arc = map->createArc();
  arc->setId("arc11");
  arc->setClazz("modulation");
  arc->setSource("glyph15");
  arc->setTarget("glyph19");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(1100);
  point->setY(135);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(1200);
  point->setY(135);

  arcGroup = map->createArcGroup();
  arcGroup->setClazz("interaction");

  auto* glyph_7 = arcGroup->createGlyph();
  glyph_7->setId("glyph32");
  glyph_7->setClazz("interaction");

  bbox = glyph_7->createBBox();
  bbox->setX(792.5);
  bbox->setY(312.5);
  bbox->setWidth(35);
  bbox->setHeight(35);

  arc = arcGroup->createArc();
  arc->setId("arc3");
  arc->setClazz("interaction");
  arc->setSource("glyph25");
  arc->setTarget("glyph32");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(852.857);
  point->setY(280);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(825);
  point->setY(312.5);

  arc = arcGroup->createArc();
  arc->setId("arc4");
  arc->setClazz("interaction");
  arc->setSource("glyph26");
  arc->setTarget("glyph32");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(852.857);
  point->setY(380);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(825);
  point->setY(347.5);

  arc = arcGroup->createArc();
  arc->setId("arc5");
  arc->setClazz("interaction");
  arc->setSource("glyph32");
  arc->setTarget("glyph24");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(792.5);
  point->setY(330);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(720);
  point->setY(330);

  auto* glyph_8 = arc->createGlyph();
  glyph_8->setId("glyph38");
  glyph_8->setClazz("cardinality");

  label = glyph_8->createLabel();
  label->setText("N");

  bbox = glyph_8->createBBox();
  bbox->setX(751);
  bbox->setY(319);
  bbox->setWidth(22.5);
  bbox->setHeight(17.5);


  writeSBGNToFile(doc, "out.sbgn");

  delete doc;

  return 0;
}

