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
  SbgnBBox*  bbox = NULL;                  
  SbgnPoint* point = NULL;                 
  SbgnPort*  port= NULL;                   
                                           
  auto* map = doc->createMap();            
  map->setId("map1");
  map->setLanguage("process description");

  glyph = map->createGlyph();
  glyph->setId("glyph4");
  glyph->setClazz("simple chemical");

  label = glyph->createLabel();
  label->setText("ATP");

  bbox = glyph->createBBox();
  bbox->setX(270);
  bbox->setY(260);
  bbox->setWidth(60);
  bbox->setHeight(60);

  clone = glyph->createClone();

  glyph = map->createGlyph();
  glyph->setId("glyph5");
  glyph->setClazz("simple chemical");

  label = glyph->createLabel();
  label->setText("ADP");

  bbox = glyph->createBBox();
  bbox->setX(430);
  bbox->setY(260);
  bbox->setWidth(60);
  bbox->setHeight(60);

  clone = glyph->createClone();

  glyph = map->createGlyph();
  glyph->setId("glyph7");
  glyph->setClazz("simple chemical");

  label = glyph->createLabel();
  label->setText("ATP");

  bbox = glyph->createBBox();
  bbox->setX(120);
  bbox->setY(500);
  bbox->setWidth(60);
  bbox->setHeight(60);

  clone = glyph->createClone();

  glyph = map->createGlyph();
  glyph->setId("glyph6");
  glyph->setClazz("simple chemical");

  label = glyph->createLabel();
  label->setText("ADP");

  bbox = glyph->createBBox();
  bbox->setX(280);
  bbox->setY(500);
  bbox->setWidth(60);
  bbox->setHeight(60);

  clone = glyph->createClone();

  glyph = map->createGlyph();
  glyph->setId("glyph10");
  glyph->setClazz("simple chemical");

  label = glyph->createLabel();
  label->setText("ATP");

  bbox = glyph->createBBox();
  bbox->setX(440);
  bbox->setY(500);
  bbox->setWidth(60);
  bbox->setHeight(60);

  clone = glyph->createClone();

  glyph = map->createGlyph();
  glyph->setId("glyph9");
  glyph->setClazz("simple chemical");

  label = glyph->createLabel();
  label->setText("ADP");

  bbox = glyph->createBBox();
  bbox->setX(600);
  bbox->setY(500);
  bbox->setWidth(60);
  bbox->setHeight(60);

  clone = glyph->createClone();

  glyph = map->createGlyph();
  glyph->setId("glyph2");
  glyph->setClazz("macromolecule");

  label = glyph->createLabel();
  label->setText("RAF");

  bbox = glyph->createBBox();
  bbox->setX(480);
  bbox->setY(140);
  bbox->setWidth(100);
  bbox->setHeight(60);

  auto* glyph_1 = glyph->createGlyph();
  glyph_1->setId("glyph2a");
  glyph_1->setClazz("state variable");

  bbox = glyph_1->createBBox();
  bbox->setX(517.5);
  bbox->setY(189);
  bbox->setWidth(25);
  bbox->setHeight(22);

  state = glyph_1->createState();
  state->setValue("P");

  glyph = map->createGlyph();
  glyph->setId("glyph18");
  glyph->setClazz("simple chemical");

  label = glyph->createLabel();
  label->setText("ADP");

  bbox = glyph->createBBox();
  bbox->setX(560);
  bbox->setY(750);
  bbox->setWidth(60);
  bbox->setHeight(60);

  clone = glyph->createClone();

  glyph = map->createGlyph();
  glyph->setId("glyph16");
  glyph->setClazz("simple chemical");

  label = glyph->createLabel();
  label->setText("ADP");

  bbox = glyph->createBBox();
  bbox->setX(280);
  bbox->setY(750);
  bbox->setWidth(60);
  bbox->setHeight(60);

  clone = glyph->createClone();

  glyph = map->createGlyph();
  glyph->setId("glyph15");
  glyph->setClazz("simple chemical");

  label = glyph->createLabel();
  label->setText("ATP");

  bbox = glyph->createBBox();
  bbox->setX(120);
  bbox->setY(750);
  bbox->setWidth(60);
  bbox->setHeight(60);

  clone = glyph->createClone();

  glyph = map->createGlyph();
  glyph->setId("glyph17");
  glyph->setClazz("simple chemical");

  label = glyph->createLabel();
  label->setText("ATP");

  bbox = glyph->createBBox();
  bbox->setX(400);
  bbox->setY(750);
  bbox->setWidth(60);
  bbox->setHeight(60);

  clone = glyph->createClone();

  glyph = map->createGlyph();
  glyph->setId("glyph12");
  glyph->setClazz("macromolecule");

  label = glyph->createLabel();
  label->setText("MEK");

  bbox = glyph->createBBox();
  bbox->setX(650);
  bbox->setY(380);
  bbox->setWidth(100);
  bbox->setHeight(60);

  auto* glyph_2 = glyph->createGlyph();
  glyph_2->setId("glyph12a");
  glyph_2->setClazz("state variable");

  bbox = glyph_2->createBBox();
  bbox->setX(684);
  bbox->setY(429);
  bbox->setWidth(32);
  bbox->setHeight(22);

  state = glyph_2->createState();
  state->setValue("2P");

  glyph = map->createGlyph();
  glyph->setId("glyph19");
  glyph->setClazz("macromolecule");

  label = glyph->createLabel();
  label->setText("ERK");

  bbox = glyph->createBBox();
  bbox->setX(590);
  bbox->setY(630);
  bbox->setWidth(100);
  bbox->setHeight(60);

  auto* glyph_3 = glyph->createGlyph();
  glyph_3->setId("glyph19a");
  glyph_3->setClazz("state variable");

  bbox = glyph_3->createBBox();
  bbox->setX(599);
  bbox->setY(679);
  bbox->setWidth(32);
  bbox->setHeight(22);

  state = glyph_3->createState();
  state->setValue("2P");

  glyph = map->createGlyph();
  glyph->setId("glyph20");
  glyph->setClazz("tag");
  glyph->setOrientation("left");

  label = glyph->createLabel();
  label->setText("ERK");

  bbox = glyph->createBBox();
  bbox->setX(760);
  bbox->setY(630);
  bbox->setWidth(100);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph1");
  glyph->setClazz("macromolecule");

  label = glyph->createLabel();
  label->setText("RAS");

  bbox = glyph->createBBox();
  bbox->setX(330);
  bbox->setY(30);
  bbox->setWidth(100);
  bbox->setHeight(60);

  auto* glyph_4 = glyph->createGlyph();
  glyph_4->setId("glyph1a");
  glyph_4->setClazz("state variable");

  bbox = glyph_4->createBBox();
  bbox->setX(355);
  bbox->setY(77);
  bbox->setWidth(50);
  bbox->setHeight(26);

  state = glyph_4->createState();
  state->setValue("active");

  glyph = map->createGlyph();
  glyph->setId("glyph0");
  glyph->setClazz("tag");
  glyph->setOrientation("right");

  label = glyph->createLabel();
  label->setText("RAS");

  bbox = glyph->createBBox();
  bbox->setX(160);
  bbox->setY(30);
  bbox->setWidth(100);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph24");
  glyph->setClazz("macromolecule");

  label = glyph->createLabel();
  label->setText("MEK");

  bbox = glyph->createBBox();
  bbox->setX(310);
  bbox->setY(380);
  bbox->setWidth(100);
  bbox->setHeight(60);

  auto* glyph_5 = glyph->createGlyph();
  glyph_5->setId("glyph24a");
  glyph_5->setClazz("state variable");

  bbox = glyph_5->createBBox();
  bbox->setX(322.5);
  bbox->setY(429);
  bbox->setWidth(25);
  bbox->setHeight(22);

  state = glyph_5->createState();
  state->setValue("P");

  glyph = map->createGlyph();
  glyph->setId("glyph11");
  glyph->setClazz("process");

  bbox = glyph->createBBox();
  bbox->setX(540);
  bbox->setY(400);
  bbox->setWidth(20);
  bbox->setHeight(20);

  port = glyph->createPort();
  port->setId("glyph11.1");
  port->setX(530);
  port->setY(410);

  port = glyph->createPort();
  port->setId("glyph11.2");
  port->setX(570);
  port->setY(410);

  glyph = map->createGlyph();
  glyph->setId("glyph25");
  glyph->setClazz("macromolecule");

  label = glyph->createLabel();
  label->setText("RAF");

  bbox = glyph->createBBox();
  bbox->setX(180);
  bbox->setY(140);
  bbox->setWidth(100);
  bbox->setHeight(60);

  auto* glyph_6 = glyph->createGlyph();
  glyph_6->setId("glyph25a");
  glyph_6->setClazz("state variable");

  bbox = glyph_6->createBBox();
  bbox->setX(220);
  bbox->setY(189);
  bbox->setWidth(20);
  bbox->setHeight(22);

  glyph = map->createGlyph();
  glyph->setId("glyph3");
  glyph->setClazz("process");

  bbox = glyph->createBBox();
  bbox->setX(370);
  bbox->setY(160);
  bbox->setWidth(20);
  bbox->setHeight(20);

  port = glyph->createPort();
  port->setId("glyph3.2");
  port->setX(400);
  port->setY(170);

  port = glyph->createPort();
  port->setId("glyph3.1");
  port->setX(360);
  port->setY(170);

  glyph = map->createGlyph();
  glyph->setId("glyph23");
  glyph->setClazz("macromolecule");

  label = glyph->createLabel();
  label->setText("MEK");

  bbox = glyph->createBBox();
  bbox->setX(30);
  bbox->setY(380);
  bbox->setWidth(100);
  bbox->setHeight(60);

  auto* glyph_7 = glyph->createGlyph();
  glyph_7->setId("glyph23a");
  glyph_7->setClazz("state variable");

  bbox = glyph_7->createBBox();
  bbox->setX(45);
  bbox->setY(429);
  bbox->setWidth(20);
  bbox->setHeight(22);

  glyph = map->createGlyph();
  glyph->setId("glyph8");
  glyph->setClazz("process");

  bbox = glyph->createBBox();
  bbox->setX(220);
  bbox->setY(400);
  bbox->setWidth(20);
  bbox->setHeight(20);

  port = glyph->createPort();
  port->setId("glyph8.1");
  port->setX(210);
  port->setY(410);

  port = glyph->createPort();
  port->setId("glyph8.2");
  port->setX(250);
  port->setY(410);

  glyph = map->createGlyph();
  glyph->setId("glyph22");
  glyph->setClazz("macromolecule");

  label = glyph->createLabel();
  label->setText("ERK");

  bbox = glyph->createBBox();
  bbox->setX(30);
  bbox->setY(630);
  bbox->setWidth(100);
  bbox->setHeight(60);

  auto* glyph_8 = glyph->createGlyph();
  glyph_8->setId("glyph22a");
  glyph_8->setClazz("state variable");

  bbox = glyph_8->createBBox();
  bbox->setX(45);
  bbox->setY(679);
  bbox->setWidth(20);
  bbox->setHeight(22);

  glyph = map->createGlyph();
  glyph->setId("glyph13");
  glyph->setClazz("process");

  bbox = glyph->createBBox();
  bbox->setX(500);
  bbox->setY(650);
  bbox->setWidth(20);
  bbox->setHeight(20);

  port = glyph->createPort();
  port->setId("glyph13.2");
  port->setX(530);
  port->setY(660);

  port = glyph->createPort();
  port->setId("glyph13.1");
  port->setX(490);
  port->setY(660);

  glyph = map->createGlyph();
  glyph->setId("glyph14");
  glyph->setClazz("process");

  bbox = glyph->createBBox();
  bbox->setX(220);
  bbox->setY(650);
  bbox->setWidth(20);
  bbox->setHeight(20);

  port = glyph->createPort();
  port->setId("glyph14.2");
  port->setX(250);
  port->setY(660);

  port = glyph->createPort();
  port->setId("glyph14.1");
  port->setX(210);
  port->setY(660);

  glyph = map->createGlyph();
  glyph->setId("glyph21");
  glyph->setClazz("macromolecule");

  label = glyph->createLabel();
  label->setText("ERK");

  bbox = glyph->createBBox();
  bbox->setX(310);
  bbox->setY(630);
  bbox->setWidth(100);
  bbox->setHeight(60);

  auto* glyph_9 = glyph->createGlyph();
  glyph_9->setId("glyph21a");
  glyph_9->setClazz("state variable");

  bbox = glyph_9->createBBox();
  bbox->setX(322.5);
  bbox->setY(679);
  bbox->setWidth(25);
  bbox->setHeight(22);

  state = glyph_9->createState();
  state->setValue("P");

  arc = map->createArc();
  arc->setId("a01");
  arc->setClazz("production");
  arc->setSource("glyph3.2");
  arc->setTarget("glyph2");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(400);
  point->setY(170);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(480);
  point->setY(170);

  arc = map->createArc();
  arc->setId("a02");
  arc->setClazz("consumption");
  arc->setSource("glyph4");
  arc->setTarget("glyph3.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(313.416);
  point->setY(263.167);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(360);
  point->setY(170);

  arc = map->createArc();
  arc->setId("a03");
  arc->setClazz("production");
  arc->setSource("glyph3.2");
  arc->setTarget("glyph5");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(400);
  point->setY(170);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(443.359);
  point->setY(265.038);

  arc = map->createArc();
  arc->setId("a04");
  arc->setClazz("catalysis");
  arc->setSource("glyph1");
  arc->setTarget("glyph3");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(380);
  point->setY(102);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(380);
  point->setY(160);

  arc = map->createArc();
  arc->setId("a05");
  arc->setClazz("consumption");
  arc->setSource("glyph7");
  arc->setTarget("glyph8.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(163.416);
  point->setY(503.167);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(210);
  point->setY(410);

  arc = map->createArc();
  arc->setId("a06");
  arc->setClazz("production");
  arc->setSource("glyph8.2");
  arc->setTarget("glyph6");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(250);
  point->setY(410);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(293.359);
  point->setY(505.038);

  arc = map->createArc();
  arc->setId("a07");
  arc->setClazz("consumption");
  arc->setSource("glyph10");
  arc->setTarget("glyph11.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(483.416);
  point->setY(503.167);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(530);
  point->setY(410);

  arc = map->createArc();
  arc->setId("a08");
  arc->setClazz("production");
  arc->setSource("glyph11.2");
  arc->setTarget("glyph12");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(570);
  point->setY(410);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(650);
  point->setY(410);

  arc = map->createArc();
  arc->setId("a09");
  arc->setClazz("production");
  arc->setSource("glyph11.2");
  arc->setTarget("glyph9");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(570);
  point->setY(410);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(613.359);
  point->setY(505.038);

  arc = map->createArc();
  arc->setId("a10");
  arc->setClazz("catalysis");
  arc->setSource("glyph2");
  arc->setTarget("glyph11");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(550);
  point->setY(200);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(549.167);
  point->setY(400);

  arc = map->createArc();
  arc->setId("a11");
  arc->setClazz("catalysis");
  arc->setSource("glyph2");
  arc->setTarget("glyph8");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(510);
  point->setY(200);

  point = arc->createNext();
  point->setElementName("next");
  point->setX(510);
  point->setY(360);

  point = arc->createNext();
  point->setElementName("next");
  point->setX(230);
  point->setY(360);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(230);
  point->setY(400);

  arc = map->createArc();
  arc->setId("a12");
  arc->setClazz("production");
  arc->setSource("glyph13.2");
  arc->setTarget("glyph19");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(530);
  point->setY(660);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(590);
  point->setY(660);

  arc = map->createArc();
  arc->setId("a13");
  arc->setClazz("production");
  arc->setSource("glyph13.2");
  arc->setTarget("glyph18");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(530);
  point->setY(660);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(573.359);
  point->setY(755.038);

  arc = map->createArc();
  arc->setId("a14");
  arc->setClazz("production");
  arc->setSource("glyph14.2");
  arc->setTarget("glyph16");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(250);
  point->setY(660);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(293.359);
  point->setY(755.038);

  arc = map->createArc();
  arc->setId("a15");
  arc->setClazz("consumption");
  arc->setSource("glyph15");
  arc->setTarget("glyph14.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(163.416);
  point->setY(753.167);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(210);
  point->setY(660);

  arc = map->createArc();
  arc->setId("a16");
  arc->setClazz("consumption");
  arc->setSource("glyph17");
  arc->setTarget("glyph13.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(443.416);
  point->setY(753.167);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(490);
  point->setY(660);

  arc = map->createArc();
  arc->setId("a17");
  arc->setClazz("catalysis");
  arc->setSource("glyph12");
  arc->setTarget("glyph13");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(720);
  point->setY(440);

  point = arc->createNext();
  point->setElementName("next");
  point->setX(720);
  point->setY(610);

  point = arc->createNext();
  point->setElementName("next");
  point->setX(510);
  point->setY(610);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(510);
  point->setY(650);

  arc = map->createArc();
  arc->setId("a18");
  arc->setClazz("catalysis");
  arc->setSource("glyph12");
  arc->setTarget("glyph14");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(680);
  point->setY(440);

  point = arc->createNext();
  point->setElementName("next");
  point->setX(680);
  point->setY(590);

  point = arc->createNext();
  point->setElementName("next");
  point->setX(230);
  point->setY(590);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(230);
  point->setY(650);

  arc = map->createArc();
  arc->setId("a19");
  arc->setClazz("equivalence arc");
  arc->setSource("glyph19");
  arc->setTarget("glyph20");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(690);
  point->setY(660);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(760);
  point->setY(660);

  arc = map->createArc();
  arc->setId("a20");
  arc->setClazz("equivalence arc");
  arc->setSource("glyph1");
  arc->setTarget("glyph0");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(330);
  point->setY(60);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(260);
  point->setY(60);

  arc = map->createArc();
  arc->setId("a21");
  arc->setClazz("production");
  arc->setSource("glyph8.2");
  arc->setTarget("glyph24");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(250);
  point->setY(410);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(310);
  point->setY(410);

  arc = map->createArc();
  arc->setId("a22");
  arc->setClazz("consumption");
  arc->setSource("glyph24");
  arc->setTarget("glyph11.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(410);
  point->setY(410);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(530);
  point->setY(410);

  arc = map->createArc();
  arc->setId("a23");
  arc->setClazz("consumption");
  arc->setSource("glyph25");
  arc->setTarget("glyph3.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(280);
  point->setY(170);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(360);
  point->setY(170);

  arc = map->createArc();
  arc->setId("a24");
  arc->setClazz("consumption");
  arc->setSource("glyph23");
  arc->setTarget("glyph8.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(130);
  point->setY(410);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(210);
  point->setY(410);

  arc = map->createArc();
  arc->setId("a25");
  arc->setClazz("consumption");
  arc->setSource("glyph22");
  arc->setTarget("glyph14.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(130);
  point->setY(660);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(210);
  point->setY(660);

  arc = map->createArc();
  arc->setId("a26");
  arc->setClazz("consumption");
  arc->setSource("glyph21");
  arc->setTarget("glyph13.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(410);
  point->setY(660);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(490);
  point->setY(660);

  arc = map->createArc();
  arc->setId("a27");
  arc->setClazz("production");
  arc->setSource("glyph14.2");
  arc->setTarget("glyph21");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(250);
  point->setY(660);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(310);
  point->setY(660);


    std::string outfile = "out.sbgn";
  if (argc > 1)
    outfile = argv[1];
  writeSBGNToFile(doc, outfile.c_str());
                                  
  delete doc;                     
                                  
  return 0;                       
}                                 
