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
  glyph->setId("glyph9");
  glyph->setClazz("macromolecule");

  label = glyph->createLabel();
  label->setText("hexokinase");

  bbox = glyph->createBBox();
  bbox->setX(170);
  bbox->setY(40);
  bbox->setWidth(120);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph0");
  glyph->setClazz("simple chemical");

  label = glyph->createLabel();
  label->setText("glucose");

  bbox = glyph->createBBox();
  bbox->setX(90);
  bbox->setY(140);
  bbox->setWidth(60);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph6");
  glyph->setClazz("simple chemical");

  label = glyph->createLabel();
  label->setText("ATP");

  bbox = glyph->createBBox();
  bbox->setX(140);
  bbox->setY(230);
  bbox->setWidth(60);
  bbox->setHeight(60);

  clone = glyph->createClone();

  glyph = map->createGlyph();
  glyph->setId("glyph8");
  glyph->setClazz("process");

  bbox = glyph->createBBox();
  bbox->setX(220);
  bbox->setY(160);
  bbox->setWidth(20);
  bbox->setHeight(20);

  port = glyph->createPort();
  port->setId("glyph8.1");
  port->setX(210);
  port->setY(170);

  port = glyph->createPort();
  port->setId("glyph8.2");
  port->setX(250);
  port->setY(170);

  glyph = map->createGlyph();
  glyph->setId("glyph7");
  glyph->setClazz("simple chemical");

  label = glyph->createLabel();
  label->setText("ADP");

  bbox = glyph->createBBox();
  bbox->setX(270);
  bbox->setY(230);
  bbox->setWidth(60);
  bbox->setHeight(60);

  clone = glyph->createClone();

  glyph = map->createGlyph();
  glyph->setId("glyph12");
  glyph->setClazz("simple chemical");

  label = glyph->createLabel();
  label->setText("ADP");

  bbox = glyph->createBBox();
  bbox->setX(700);
  bbox->setY(230);
  bbox->setWidth(60);
  bbox->setHeight(60);

  clone = glyph->createClone();

  glyph = map->createGlyph();
  glyph->setId("glyph13");
  glyph->setClazz("simple chemical");

  label = glyph->createLabel();
  label->setText("ATP");

  bbox = glyph->createBBox();
  bbox->setX(570);
  bbox->setY(230);
  bbox->setWidth(60);
  bbox->setHeight(60);

  clone = glyph->createClone();

  glyph = map->createGlyph();
  glyph->setId("glyph1");
  glyph->setClazz("simple chemical");

  label = glyph->createLabel();
  label->setText("glucose&#10;6P");

  bbox = glyph->createBBox();
  bbox->setX(320);
  bbox->setY(140);
  bbox->setWidth(60);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph2");
  glyph->setClazz("simple chemical");

  label = glyph->createLabel();
  label->setText("fructose&#10;6P");

  bbox = glyph->createBBox();
  bbox->setX(520);
  bbox->setY(140);
  bbox->setWidth(60);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph15");
  glyph->setClazz("macromolecule");

  label = glyph->createLabel();
  label->setText("triose-P&#10;isomerase");

  bbox = glyph->createBBox();
  bbox->setX(1080);
  bbox->setY(140);
  bbox->setWidth(120);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph3");
  glyph->setClazz("simple chemical");

  label = glyph->createLabel();
  label->setText("fructose&#10;1,6P");

  bbox = glyph->createBBox();
  bbox->setX(730);
  bbox->setY(140);
  bbox->setWidth(60);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph17");
  glyph->setClazz("macromolecule");

  label = glyph->createLabel();
  label->setText("glucose-6P&#10;isomerase");

  bbox = glyph->createBBox();
  bbox->setX(380);
  bbox->setY(40);
  bbox->setWidth(120);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph10");
  glyph->setClazz("process");

  bbox = glyph->createBBox();
  bbox->setX(430);
  bbox->setY(160);
  bbox->setWidth(20);
  bbox->setHeight(20);

  port = glyph->createPort();
  port->setId("glyph10.1");
  port->setX(420);
  port->setY(170);

  port = glyph->createPort();
  port->setId("glyph10.2");
  port->setX(460);
  port->setY(170);

  glyph = map->createGlyph();
  glyph->setId("glyph19");
  glyph->setClazz("macromolecule");

  label = glyph->createLabel();
  label->setText("phospho&#10;fructokinase");

  bbox = glyph->createBBox();
  bbox->setX(600);
  bbox->setY(40);
  bbox->setWidth(120);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph11");
  glyph->setClazz("process");

  bbox = glyph->createBBox();
  bbox->setX(650);
  bbox->setY(160);
  bbox->setWidth(20);
  bbox->setHeight(20);

  port = glyph->createPort();
  port->setId("glyph11.2");
  port->setX(680);
  port->setY(170);

  port = glyph->createPort();
  port->setId("glyph11.1");
  port->setX(640);
  port->setY(170);

  glyph = map->createGlyph();
  glyph->setId("glyph18");
  glyph->setClazz("macromolecule");

  label = glyph->createLabel();
  label->setText("adolase");

  bbox = glyph->createBBox();
  bbox->setX(820);
  bbox->setY(40);
  bbox->setWidth(120);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph16");
  glyph->setClazz("process");

  bbox = glyph->createBBox();
  bbox->setX(870);
  bbox->setY(160);
  bbox->setWidth(20);
  bbox->setHeight(20);

  port = glyph->createPort();
  port->setId("glyph16.1");
  port->setX(860);
  port->setY(170);

  port = glyph->createPort();
  port->setId("glyph16.2");
  port->setX(900);
  port->setY(170);

  glyph = map->createGlyph();
  glyph->setId("glyph22");
  glyph->setClazz("macromolecule");

  label = glyph->createLabel();
  label->setText("GAPDH");

  bbox = glyph->createBBox();
  bbox->setX(1080);
  bbox->setY(350);
  bbox->setWidth(120);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph4");
  glyph->setClazz("simple chemical");

  label = glyph->createLabel();
  label->setText("GA-3P");

  bbox = glyph->createBBox();
  bbox->setX(960);
  bbox->setY(240);
  bbox->setWidth(60);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph23");
  glyph->setClazz("simple chemical");

  label = glyph->createLabel();
  label->setText("Pi");

  bbox = glyph->createBBox();
  bbox->setX(880);
  bbox->setY(280);
  bbox->setWidth(60);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph24");
  glyph->setClazz("simple chemical");

  label = glyph->createLabel();
  label->setText("NAD");

  bbox = glyph->createBBox();
  bbox->setX(1050);
  bbox->setY(280);
  bbox->setWidth(60);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph25");
  glyph->setClazz("simple chemical");

  label = glyph->createLabel();
  label->setText("H+");

  bbox = glyph->createBBox();
  bbox->setX(1050);
  bbox->setY(420);
  bbox->setWidth(60);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph20");
  glyph->setClazz("process");
  glyph->setOrientation("vertical");

  bbox = glyph->createBBox();
  bbox->setX(980);
  bbox->setY(370);
  bbox->setWidth(20);
  bbox->setHeight(20);

  port = glyph->createPort();
  port->setId("glyph20.1");
  port->setX(990);
  port->setY(360);

  port = glyph->createPort();
  port->setId("glyph20.2");
  port->setX(990);
  port->setY(400);

  glyph = map->createGlyph();
  glyph->setId("glyph26");
  glyph->setClazz("simple chemical");

  label = glyph->createLabel();
  label->setText("NADH");

  bbox = glyph->createBBox();
  bbox->setX(1050);
  bbox->setY(490);
  bbox->setWidth(60);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph35");
  glyph->setClazz("macromolecule");

  label = glyph->createLabel();
  label->setText("PGK1");

  bbox = glyph->createBBox();
  bbox->setX(820);
  bbox->setY(540);
  bbox->setWidth(120);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph36");
  glyph->setClazz("macromolecule");

  label = glyph->createLabel();
  label->setText("PG mutase");

  bbox = glyph->createBBox();
  bbox->setX(580);
  bbox->setY(540);
  bbox->setWidth(120);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph37");
  glyph->setClazz("macromolecule");

  label = glyph->createLabel();
  label->setText("enolase");

  bbox = glyph->createBBox();
  bbox->setX(350);
  bbox->setY(540);
  bbox->setWidth(120);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph38");
  glyph->setClazz("macromolecule");

  label = glyph->createLabel();
  label->setText("pyruvate&#10;kinase");

  bbox = glyph->createBBox();
  bbox->setX(100);
  bbox->setY(540);
  bbox->setWidth(120);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph21");
  glyph->setClazz("simple chemical");

  label = glyph->createLabel();
  label->setText("1,3 BPG");

  bbox = glyph->createBBox();
  bbox->setX(960);
  bbox->setY(460);
  bbox->setWidth(60);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph42");
  glyph->setClazz("simple chemical");

  label = glyph->createLabel();
  label->setText("ADP");

  bbox = glyph->createBBox();
  bbox->setX(910);
  bbox->setY(390);
  bbox->setWidth(60);
  bbox->setHeight(60);

  clone = glyph->createClone();

  glyph = map->createGlyph();
  glyph->setId("glyph41");
  glyph->setClazz("simple chemical");

  label = glyph->createLabel();
  label->setText("ATP");

  bbox = glyph->createBBox();
  bbox->setX(780);
  bbox->setY(390);
  bbox->setWidth(60);
  bbox->setHeight(60);

  clone = glyph->createClone();

  glyph = map->createGlyph();
  glyph->setId("glyph31");
  glyph->setClazz("process");

  bbox = glyph->createBBox();
  bbox->setX(870);
  bbox->setY(480);
  bbox->setWidth(20);
  bbox->setHeight(20);

  port = glyph->createPort();
  port->setId("glyph31.2");
  port->setX(900);
  port->setY(490);

  port = glyph->createPort();
  port->setId("glyph31.1");
  port->setX(860);
  port->setY(490);

  glyph = map->createGlyph();
  glyph->setId("glyph27");
  glyph->setClazz("simple chemical");

  label = glyph->createLabel();
  label->setText("3 PG");

  bbox = glyph->createBBox();
  bbox->setX(720);
  bbox->setY(460);
  bbox->setWidth(60);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph32");
  glyph->setClazz("process");

  bbox = glyph->createBBox();
  bbox->setX(630);
  bbox->setY(480);
  bbox->setWidth(20);
  bbox->setHeight(20);

  port = glyph->createPort();
  port->setId("glyph32.2");
  port->setX(660);
  port->setY(490);

  port = glyph->createPort();
  port->setId("glyph32.1");
  port->setX(620);
  port->setY(490);

  glyph = map->createGlyph();
  glyph->setId("glyph28");
  glyph->setClazz("simple chemical");

  label = glyph->createLabel();
  label->setText("2 PG");

  bbox = glyph->createBBox();
  bbox->setX(490);
  bbox->setY(460);
  bbox->setWidth(60);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph43");
  glyph->setClazz("simple chemical");

  label = glyph->createLabel();
  label->setText("H2O");

  bbox = glyph->createBBox();
  bbox->setX(320);
  bbox->setY(390);
  bbox->setWidth(60);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph33");
  glyph->setClazz("process");

  bbox = glyph->createBBox();
  bbox->setX(400);
  bbox->setY(480);
  bbox->setWidth(20);
  bbox->setHeight(20);

  port = glyph->createPort();
  port->setId("glyph33.2");
  port->setX(430);
  port->setY(490);

  port = glyph->createPort();
  port->setId("glyph33.1");
  port->setX(390);
  port->setY(490);

  glyph = map->createGlyph();
  glyph->setId("glyph29");
  glyph->setClazz("simple chemical");

  label = glyph->createLabel();
  label->setText("PEP");

  bbox = glyph->createBBox();
  bbox->setX(270);
  bbox->setY(460);
  bbox->setWidth(60);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph39");
  glyph->setClazz("simple chemical");

  label = glyph->createLabel();
  label->setText("ADP");

  bbox = glyph->createBBox();
  bbox->setX(210);
  bbox->setY(390);
  bbox->setWidth(60);
  bbox->setHeight(60);

  clone = glyph->createClone();

  glyph = map->createGlyph();
  glyph->setId("glyph40");
  glyph->setClazz("simple chemical");

  label = glyph->createLabel();
  label->setText("ATP");

  bbox = glyph->createBBox();
  bbox->setX(60);
  bbox->setY(390);
  bbox->setWidth(60);
  bbox->setHeight(60);

  clone = glyph->createClone();

  glyph = map->createGlyph();
  glyph->setId("glyph34");
  glyph->setClazz("process");

  bbox = glyph->createBBox();
  bbox->setX(150);
  bbox->setY(480);
  bbox->setWidth(20);
  bbox->setHeight(20);

  port = glyph->createPort();
  port->setId("glyph34.2");
  port->setX(180);
  port->setY(490);

  port = glyph->createPort();
  port->setId("glyph34.1");
  port->setX(140);
  port->setY(490);

  glyph = map->createGlyph();
  glyph->setId("glyph30");
  glyph->setClazz("simple chemical");

  label = glyph->createLabel();
  label->setText("pyruvate");

  bbox = glyph->createBBox();
  bbox->setX(30);
  bbox->setY(460);
  bbox->setWidth(60);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph14");
  glyph->setClazz("process");
  glyph->setOrientation("vertical");

  bbox = glyph->createBBox();
  bbox->setX(980);
  bbox->setY(160);
  bbox->setWidth(20);
  bbox->setHeight(20);

  port = glyph->createPort();
  port->setId("glyph14.2");
  port->setX(990);
  port->setY(190);

  port = glyph->createPort();
  port->setId("glyph14.1");
  port->setX(990);
  port->setY(150);

  glyph = map->createGlyph();
  glyph->setId("glyph5");
  glyph->setClazz("simple chemical");

  label = glyph->createLabel();
  label->setText("DHA-P");

  bbox = glyph->createBBox();
  bbox->setX(960);
  bbox->setY(40);
  bbox->setWidth(60);
  bbox->setHeight(60);

  arc = map->createArc();
  arc->setId("a01");
  arc->setClazz("catalysis");
  arc->setSource("glyph9");
  arc->setTarget("glyph8");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(230);
  point->setY(100);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(230);
  point->setY(160);

  arc = map->createArc();
  arc->setId("a02");
  arc->setClazz("consumption");
  arc->setSource("glyph0");
  arc->setTarget("glyph8.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(150);
  point->setY(170);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(210);
  point->setY(170);

  arc = map->createArc();
  arc->setId("a03");
  arc->setClazz("production");
  arc->setSource("glyph8.2");
  arc->setTarget("glyph1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(250);
  point->setY(170);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(320);
  point->setY(170);

  arc = map->createArc();
  arc->setId("a04");
  arc->setClazz("consumption");
  arc->setSource("glyph6");
  arc->setTarget("glyph8.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(182.184);
  point->setY(232.586);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(210);
  point->setY(170);

  arc = map->createArc();
  arc->setId("a05");
  arc->setClazz("production");
  arc->setSource("glyph8.2");
  arc->setTarget("glyph7");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(250);
  point->setY(170);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(281.582);
  point->setY(236.319);

  arc = map->createArc();
  arc->setId("a06");
  arc->setClazz("production");
  arc->setSource("glyph11.2");
  arc->setTarget("glyph12");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(680);
  point->setY(170);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(711.582);
  point->setY(236.319);

  arc = map->createArc();
  arc->setId("a07");
  arc->setClazz("consumption");
  arc->setSource("glyph13");
  arc->setTarget("glyph11.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(612.184);
  point->setY(232.586);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(640);
  point->setY(170);

  arc = map->createArc();
  arc->setId("a08");
  arc->setClazz("consumption");
  arc->setSource("glyph1");
  arc->setTarget("glyph10.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(380);
  point->setY(170);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(420);
  point->setY(170);

  arc = map->createArc();
  arc->setId("a09");
  arc->setClazz("production");
  arc->setSource("glyph10.2");
  arc->setTarget("glyph2");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(460);
  point->setY(170);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(520);
  point->setY(170);

  arc = map->createArc();
  arc->setId("a10");
  arc->setClazz("consumption");
  arc->setSource("glyph2");
  arc->setTarget("glyph11.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(580);
  point->setY(170);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(640);
  point->setY(170);

  arc = map->createArc();
  arc->setId("a11");
  arc->setClazz("production");
  arc->setSource("glyph11.2");
  arc->setTarget("glyph3");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(680);
  point->setY(170);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(730);
  point->setY(170);

  arc = map->createArc();
  arc->setId("a12");
  arc->setClazz("production");
  arc->setSource("glyph14.2");
  arc->setTarget("glyph4");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(990);
  point->setY(190);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(990);
  point->setY(240);

  arc = map->createArc();
  arc->setId("a13");
  arc->setClazz("catalysis");
  arc->setSource("glyph15");
  arc->setTarget("glyph14");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(1080);
  point->setY(170);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(1000);
  point->setY(170);

  arc = map->createArc();
  arc->setId("a14");
  arc->setClazz("consumption");
  arc->setSource("glyph3");
  arc->setTarget("glyph16.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(790);
  point->setY(170);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(860);
  point->setY(170);

  arc = map->createArc();
  arc->setId("a15");
  arc->setClazz("production");
  arc->setSource("glyph16.2");
  arc->setTarget("glyph5");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(900);
  point->setY(170);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(967.802);
  point->setY(90.1802);

  arc = map->createArc();
  arc->setId("a16");
  arc->setClazz("production");
  arc->setSource("glyph16.2");
  arc->setTarget("glyph4");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(900);
  point->setY(170);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(967.802);
  point->setY(249.82);

  arc = map->createArc();
  arc->setId("a17");
  arc->setClazz("catalysis");
  arc->setSource("glyph17");
  arc->setTarget("glyph10");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(440);
  point->setY(100);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(440);
  point->setY(160);

  arc = map->createArc();
  arc->setId("a18");
  arc->setClazz("catalysis");
  arc->setSource("glyph19");
  arc->setTarget("glyph11");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(660);
  point->setY(100);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(660);
  point->setY(160);

  arc = map->createArc();
  arc->setId("a19");
  arc->setClazz("catalysis");
  arc->setSource("glyph18");
  arc->setTarget("glyph16");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(880);
  point->setY(100);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(880);
  point->setY(160);

  arc = map->createArc();
  arc->setId("a20");
  arc->setClazz("catalysis");
  arc->setSource("glyph22");
  arc->setTarget("glyph20");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(1080);
  point->setY(380);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(1000);
  point->setY(380);

  arc = map->createArc();
  arc->setId("a21");
  arc->setClazz("consumption");
  arc->setSource("glyph4");
  arc->setTarget("glyph20.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(990);
  point->setY(300);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(990);
  point->setY(360);

  arc = map->createArc();
  arc->setId("a22");
  arc->setClazz("production");
  arc->setSource("glyph20.2");
  arc->setTarget("glyph21");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(990);
  point->setY(400);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(990);
  point->setY(460);

  arc = map->createArc();
  arc->setId("a23");
  arc->setClazz("consumption");
  arc->setSource("glyph23");
  arc->setTarget("glyph20.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(935.44);
  point->setY(325.9);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(990);
  point->setY(360);

  arc = map->createArc();
  arc->setId("a24");
  arc->setClazz("consumption");
  arc->setSource("glyph24");
  arc->setTarget("glyph20.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(1053.78);
  point->setY(324.569);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(990);
  point->setY(360);

  arc = map->createArc();
  arc->setId("a25");
  arc->setClazz("production");
  arc->setSource("glyph20.2");
  arc->setTarget("glyph25");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(990);
  point->setY(400);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(1056.32);
  point->setY(431.582);

  arc = map->createArc();
  arc->setId("a26");
  arc->setClazz("production");
  arc->setSource("glyph20.2");
  arc->setTarget("glyph26");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(990);
  point->setY(400);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(1063.78);
  point->setY(494.765);

  arc = map->createArc();
  arc->setId("a27");
  arc->setClazz("catalysis");
  arc->setSource("glyph35");
  arc->setTarget("glyph31");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(880);
  point->setY(540);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(880);
  point->setY(500);

  arc = map->createArc();
  arc->setId("a28");
  arc->setClazz("catalysis");
  arc->setSource("glyph36");
  arc->setTarget("glyph32");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(640);
  point->setY(540);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(640);
  point->setY(500);

  arc = map->createArc();
  arc->setId("a29");
  arc->setClazz("catalysis");
  arc->setSource("glyph37");
  arc->setTarget("glyph33");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(410);
  point->setY(540);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(410);
  point->setY(500);

  arc = map->createArc();
  arc->setId("a30");
  arc->setClazz("catalysis");
  arc->setSource("glyph38");
  arc->setTarget("glyph34");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(160);
  point->setY(540);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(160);
  point->setY(500);

  arc = map->createArc();
  arc->setId("a31");
  arc->setClazz("consumption");
  arc->setSource("glyph21");
  arc->setTarget("glyph31.2");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(960);
  point->setY(490);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(900);
  point->setY(490);

  arc = map->createArc();
  arc->setId("a32");
  arc->setClazz("consumption");
  arc->setSource("glyph42");
  arc->setTarget("glyph31.2");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(925.116);
  point->setY(446.047);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(900);
  point->setY(490);

  arc = map->createArc();
  arc->setId("a33");
  arc->setClazz("production");
  arc->setSource("glyph31.1");
  arc->setTarget("glyph41");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(860);
  point->setY(490);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(831.213);
  point->setY(441.213);

  arc = map->createArc();
  arc->setId("a34");
  arc->setClazz("production");
  arc->setSource("glyph31.1");
  arc->setTarget("glyph27");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(860);
  point->setY(490);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(780);
  point->setY(490);

  arc = map->createArc();
  arc->setId("a35");
  arc->setClazz("consumption");
  arc->setSource("glyph27");
  arc->setTarget("glyph32.2");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(720);
  point->setY(490);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(660);
  point->setY(490);

  arc = map->createArc();
  arc->setId("a36");
  arc->setClazz("production");
  arc->setSource("glyph32.1");
  arc->setTarget("glyph28");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(620);
  point->setY(490);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(550);
  point->setY(490);

  arc = map->createArc();
  arc->setId("a37");
  arc->setClazz("consumption");
  arc->setSource("glyph28");
  arc->setTarget("glyph33.2");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(490);
  point->setY(490);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(430);
  point->setY(490);

  arc = map->createArc();
  arc->setId("a38");
  arc->setClazz("production");
  arc->setSource("glyph33.1");
  arc->setTarget("glyph43");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(390);
  point->setY(490);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(369.524);
  point->setY(442.778);

  arc = map->createArc();
  arc->setId("a39");
  arc->setClazz("production");
  arc->setSource("glyph33.1");
  arc->setTarget("glyph29");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(390);
  point->setY(490);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(330);
  point->setY(490);

  arc = map->createArc();
  arc->setId("a40");
  arc->setClazz("consumption");
  arc->setSource("glyph29");
  arc->setTarget("glyph34.2");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(270);
  point->setY(490);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(180);
  point->setY(490);

  arc = map->createArc();
  arc->setId("a41");
  arc->setClazz("consumption");
  arc->setSource("glyph39");
  arc->setTarget("glyph34.2");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(220.476);
  point->setY(442.778);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(180);
  point->setY(490);

  arc = map->createArc();
  arc->setId("a42");
  arc->setClazz("production");
  arc->setSource("glyph34.1");
  arc->setTarget("glyph40");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(140);
  point->setY(490);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(111.213);
  point->setY(441.213);

  arc = map->createArc();
  arc->setId("a43");
  arc->setClazz("production");
  arc->setSource("glyph34.1");
  arc->setTarget("glyph30");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(140);
  point->setY(490);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(90);
  point->setY(490);

  arc = map->createArc();
  arc->setId("a44");
  arc->setClazz("production");
  arc->setSource("glyph14.1");
  arc->setTarget("glyph5");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(990);
  point->setY(150);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(990);
  point->setY(100);


    std::string outfile = "out.sbgn";
  if (argc > 1)
    outfile = argv[1];
  writeSBGNToFile(doc, outfile.c_str());
                                  
  delete doc;                     
                                  
  return 0;                       
}                                 
