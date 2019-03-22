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
  map->setMetaId("map1");
  map->setLanguage("process description");

  glyph = map->createGlyph();
  glyph->setId("glyph1");
  glyph->setClazz("compartment");

  label = glyph->createLabel();
  label->setText("cytosol");

  bbox = label->createBBox();
  bbox->setX(623.5);
  bbox->setY(195);
  bbox->setWidth(73);
  bbox->setHeight(23);

  bbox = glyph->createBBox();
  bbox->setX(40);
  bbox->setY(180);
  bbox->setWidth(1240);
  bbox->setHeight(1000);

  glyph = map->createGlyph();
  glyph->setId("glyph40");
  glyph->setClazz("compartment");

  label = glyph->createLabel();
  label->setText("extracellular");

  bbox = label->createBBox();
  bbox->setX(601);
  bbox->setY(55);
  bbox->setWidth(118);
  bbox->setHeight(23);

  bbox = glyph->createBBox();
  bbox->setX(40);
  bbox->setY(40);
  bbox->setWidth(1240);
  bbox->setHeight(120);

  glyph = map->createGlyph();
  glyph->setId("glyph2");
  glyph->setClazz("macromolecule");
  glyph->setCompartmentRef("glyph1");

  label = glyph->createLabel();
  label->setText("IGFR");

  bbox = glyph->createBBox();
  bbox->setX(70);
  bbox->setY(200);
  bbox->setWidth(100);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph0");
  glyph->setClazz("macromolecule");
  glyph->setCompartmentRef("glyph40");

  label = glyph->createLabel();
  label->setText("IGF");

  bbox = glyph->createBBox();
  bbox->setX(120);
  bbox->setY(80);
  bbox->setWidth(100);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph6");
  glyph->setClazz("association");

  bbox = glyph->createBBox();
  bbox->setX(230);
  bbox->setY(220);
  bbox->setWidth(20);
  bbox->setHeight(20);

  port = glyph->createPort();
  port->setId("glyph6.1");
  port->setX(220);
  port->setY(230);

  port = glyph->createPort();
  port->setId("glyph6.2");
  port->setX(260);
  port->setY(230);

  glyph = map->createGlyph();
  glyph->setId("glyph5");
  glyph->setClazz("complex");
  glyph->setCompartmentRef("glyph1");

  bbox = glyph->createBBox();
  bbox->setX(310);
  bbox->setY(100);
  bbox->setWidth(140);
  bbox->setHeight(160);

  auto* glyph_1 = glyph->createGlyph();
  glyph_1->setId("glyph3");
  glyph_1->setClazz("macromolecule");

  label = glyph_1->createLabel();
  label->setText("IGF");

  bbox = glyph_1->createBBox();
  bbox->setX(330);
  bbox->setY(121);
  bbox->setWidth(100);
  bbox->setHeight(60);

  auto* glyph_2 = glyph->createGlyph();
  glyph_2->setId("glyph4");
  glyph_2->setClazz("macromolecule");

  label = glyph_2->createLabel();
  label->setText("IGFR");

  bbox = glyph_2->createBBox();
  bbox->setX(330);
  bbox->setY(182);
  bbox->setWidth(100);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph9");
  glyph->setClazz("simple chemical");
  glyph->setCompartmentRef("glyph1");

  label = glyph->createLabel();
  label->setText("ATP");

  bbox = glyph->createBBox();
  bbox->setX(270);
  bbox->setY(290);
  bbox->setWidth(60);
  bbox->setHeight(60);

  clone = glyph->createClone();

  glyph = map->createGlyph();
  glyph->setId("glyph10");
  glyph->setClazz("simple chemical");
  glyph->setCompartmentRef("glyph1");

  label = glyph->createLabel();
  label->setText("ADP");

  bbox = glyph->createBBox();
  bbox->setX(420);
  bbox->setY(290);
  bbox->setWidth(60);
  bbox->setHeight(60);

  clone = glyph->createClone();

  glyph = map->createGlyph();
  glyph->setId("glyph12");
  glyph->setClazz("macromolecule");
  glyph->setCompartmentRef("glyph1");

  label = glyph->createLabel();
  label->setText("Grb2");

  bbox = glyph->createBBox();
  bbox->setX(590);
  bbox->setY(510);
  bbox->setWidth(100);
  bbox->setHeight(60);

  auto* glyph_3 = glyph->createGlyph();
  glyph_3->setId("glyph12a");
  glyph_3->setClazz("state variable");

  bbox = glyph_3->createBBox();
  bbox->setX(610);
  bbox->setY(556);
  bbox->setWidth(60);
  bbox->setHeight(28);

  state = glyph_3->createState();
  state->setValue("inactive");

  glyph = map->createGlyph();
  glyph->setId("glyph13");
  glyph->setClazz("process");

  bbox = glyph->createBBox();
  bbox->setX(510);
  bbox->setY(530);
  bbox->setWidth(20);
  bbox->setHeight(20);

  port = glyph->createPort();
  port->setId("glyph13.2");
  port->setX(540);
  port->setY(540);

  port = glyph->createPort();
  port->setId("glyph13.1");
  port->setX(500);
  port->setY(540);

  glyph = map->createGlyph();
  glyph->setId("glyph20");
  glyph->setClazz("macromolecule");
  glyph->setCompartmentRef("glyph1");

  label = glyph->createLabel();
  label->setText("RAS");

  bbox = glyph->createBBox();
  bbox->setX(100);
  bbox->setY(880);
  bbox->setWidth(100);
  bbox->setHeight(60);

  auto* glyph_4 = glyph->createGlyph();
  glyph_4->setId("glyph20a");
  glyph_4->setClazz("state variable");

  bbox = glyph_4->createBBox();
  bbox->setX(120);
  bbox->setY(926);
  bbox->setWidth(60);
  bbox->setHeight(28);

  state = glyph_4->createState();
  state->setValue("inactive");

  glyph = map->createGlyph();
  glyph->setId("glyph18");
  glyph->setClazz("complex");
  glyph->setCompartmentRef("glyph1");

  bbox = glyph->createBBox();
  bbox->setX(150);
  bbox->setY(710);
  bbox->setWidth(260);
  bbox->setHeight(100);

  auto* glyph_5 = glyph->createGlyph();
  glyph_5->setId("glyph16");
  glyph_5->setClazz("macromolecule");

  label = glyph_5->createLabel();
  label->setText("SOS");

  bbox = glyph_5->createBBox();
  bbox->setX(169);
  bbox->setY(730);
  bbox->setWidth(100);
  bbox->setHeight(60);

  auto* glyph_6 = glyph->createGlyph();
  glyph_6->setId("glyph17");
  glyph_6->setClazz("macromolecule");

  label = glyph_6->createLabel();
  label->setText("Grb2");

  bbox = glyph_6->createBBox();
  bbox->setX(290);
  bbox->setY(730);
  bbox->setWidth(100);
  bbox->setHeight(60);

  auto* glyph_7 = glyph_6->createGlyph();
  glyph_7->setId("glyph17a");
  glyph_7->setClazz("state variable");

  bbox = glyph_7->createBBox();
  bbox->setX(315);
  bbox->setY(777);
  bbox->setWidth(50);
  bbox->setHeight(26);

  state = glyph_7->createState();
  state->setValue("active");

  glyph = map->createGlyph();
  glyph->setId("glyph22");
  glyph->setClazz("simple chemical");
  glyph->setCompartmentRef("glyph1");

  label = glyph->createLabel();
  label->setText("GTP");

  bbox = glyph->createBBox();
  bbox->setX(170);
  bbox->setY(1000);
  bbox->setWidth(60);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph19");
  glyph->setClazz("process");

  bbox = glyph->createBBox();
  bbox->setX(270);
  bbox->setY(900);
  bbox->setWidth(20);
  bbox->setHeight(20);

  port = glyph->createPort();
  port->setId("glyph19.1");
  port->setX(260);
  port->setY(910);

  port = glyph->createPort();
  port->setId("glyph19.2");
  port->setX(300);
  port->setY(910);

  glyph = map->createGlyph();
  glyph->setId("glyph23");
  glyph->setClazz("simple chemical");
  glyph->setCompartmentRef("glyph1");

  label = glyph->createLabel();
  label->setText("GDP");

  bbox = glyph->createBBox();
  bbox->setX(340);
  bbox->setY(1000);
  bbox->setWidth(60);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph29");
  glyph->setClazz("simple chemical");
  glyph->setCompartmentRef("glyph1");

  label = glyph->createLabel();
  label->setText("ADP");

  bbox = glyph->createBBox();
  bbox->setX(940);
  bbox->setY(630);
  bbox->setWidth(60);
  bbox->setHeight(60);

  clone = glyph->createClone();

  glyph = map->createGlyph();
  glyph->setId("glyph28");
  glyph->setClazz("simple chemical");
  glyph->setCompartmentRef("glyph1");

  label = glyph->createLabel();
  label->setText("ATP");

  bbox = glyph->createBBox();
  bbox->setX(800);
  bbox->setY(630);
  bbox->setWidth(60);
  bbox->setHeight(60);

  clone = glyph->createClone();

  glyph = map->createGlyph();
  glyph->setId("glyph33");
  glyph->setClazz("simple chemical");
  glyph->setCompartmentRef("glyph1");

  label = glyph->createLabel();
  label->setText("ADP");

  bbox = glyph->createBBox();
  bbox->setX(1080);
  bbox->setY(860);
  bbox->setWidth(60);
  bbox->setHeight(60);

  clone = glyph->createClone();

  glyph = map->createGlyph();
  glyph->setId("glyph34");
  glyph->setClazz("simple chemical");
  glyph->setCompartmentRef("glyph1");

  label = glyph->createLabel();
  label->setText("ATP");

  bbox = glyph->createBBox();
  bbox->setX(950);
  bbox->setY(860);
  bbox->setWidth(60);
  bbox->setHeight(60);

  clone = glyph->createClone();

  glyph = map->createGlyph();
  glyph->setId("glyph30");
  glyph->setClazz("macromolecule");
  glyph->setCompartmentRef("glyph1");

  label = glyph->createLabel();
  label->setText("RSK");

  bbox = glyph->createBBox();
  bbox->setX(1000);
  bbox->setY(730);
  bbox->setWidth(100);
  bbox->setHeight(60);

  auto* glyph_8 = glyph->createGlyph();
  glyph_8->setId("glyph30a");
  glyph_8->setClazz("state variable");

  bbox = glyph_8->createBBox();
  bbox->setX(1087.5);
  bbox->setY(749);
  bbox->setWidth(25);
  bbox->setHeight(22);

  state = glyph_8->createState();
  state->setValue("P");

  glyph = map->createGlyph();
  glyph->setId("glyph35");
  glyph->setClazz("macromolecule");
  glyph->setCompartmentRef("glyph1");

  label = glyph->createLabel();
  label->setText("c-Fos");

  bbox = glyph->createBBox();
  bbox->setX(1150);
  bbox->setY(960);
  bbox->setWidth(100);
  bbox->setHeight(60);

  auto* glyph_9 = glyph->createGlyph();
  glyph_9->setId("glyph35a");
  glyph_9->setClazz("state variable");

  bbox = glyph_9->createBBox();
  bbox->setX(1237.5);
  bbox->setY(979);
  bbox->setWidth(25);
  bbox->setHeight(22);

  state = glyph_9->createState();
  state->setValue("P");

  glyph = map->createGlyph();
  glyph->setId("glyph36");
  glyph->setClazz("phenotype");

  label = glyph->createLabel();
  label->setText("gene&#10;transcription");

  bbox = glyph->createBBox();
  bbox->setX(1130);
  bbox->setY(1080);
  bbox->setWidth(140);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph7");
  glyph->setClazz("macromolecule");
  glyph->setCompartmentRef("glyph1");

  label = glyph->createLabel();
  label->setText("IRS1-4");

  bbox = glyph->createBBox();
  bbox->setX(470);
  bbox->setY(380);
  bbox->setWidth(100);
  bbox->setHeight(60);

  auto* glyph_10 = glyph->createGlyph();
  glyph_10->setId("glyph7a");
  glyph_10->setClazz("state variable");

  bbox = glyph_10->createBBox();
  bbox->setX(557.5);
  bbox->setY(399);
  bbox->setWidth(25);
  bbox->setHeight(22);

  state = glyph_10->createState();
  state->setValue("P");

  glyph = map->createGlyph();
  glyph->setId("glyph31");
  glyph->setClazz("macromolecule");
  glyph->setCompartmentRef("glyph1");

  label = glyph->createLabel();
  label->setText("ERK");

  bbox = glyph->createBBox();
  bbox->setX(820);
  bbox->setY(880);
  bbox->setWidth(100);
  bbox->setHeight(60);

  auto* glyph_11 = glyph->createGlyph();
  glyph_11->setId("glyph31a");
  glyph_11->setClazz("state variable");

  bbox = glyph_11->createBBox();
  bbox->setX(829);
  bbox->setY(929);
  bbox->setWidth(32);
  bbox->setHeight(22);

  state = glyph_11->createState();
  state->setValue("2P");

  glyph = map->createGlyph();
  glyph->setId("glyph21");
  glyph->setClazz("macromolecule");
  glyph->setCompartmentRef("glyph1");

  label = glyph->createLabel();
  label->setText("RAS");

  bbox = glyph->createBBox();
  bbox->setX(370);
  bbox->setY(880);
  bbox->setWidth(100);
  bbox->setHeight(60);

  auto* glyph_12 = glyph->createGlyph();
  glyph_12->setId("glyph21a");
  glyph_12->setClazz("state variable");

  bbox = glyph_12->createBBox();
  bbox->setX(395);
  bbox->setY(927);
  bbox->setWidth(50);
  bbox->setHeight(26);

  state = glyph_12->createState();
  state->setValue("active");

  glyph = map->createGlyph();
  glyph->setId("glyph24");
  glyph->setClazz("submap");

  label = glyph->createLabel();
  label->setText("MAPK&#10;cascade");

  bbox = glyph->createBBox();
  bbox->setX(520);
  bbox->setY(850);
  bbox->setWidth(220);
  bbox->setHeight(120);

  auto* glyph_13 = glyph->createGlyph();
  glyph_13->setId("glyph41");
  glyph_13->setClazz("terminal");
  glyph_13->setOrientation("right");

  label = glyph_13->createLabel();
  label->setText("RAS");

  bbox = glyph_13->createBBox();
  bbox->setX(520);
  bbox->setY(887);
  bbox->setWidth(80);
  bbox->setHeight(45);

  auto* glyph_14 = glyph->createGlyph();
  glyph_14->setId("glyph42");
  glyph_14->setClazz("terminal");
  glyph_14->setOrientation("left");

  label = glyph_14->createLabel();
  label->setText("ERK");

  bbox = glyph_14->createBBox();
  bbox->setX(660);
  bbox->setY(887);
  bbox->setWidth(80);
  bbox->setHeight(45);

  glyph = map->createGlyph();
  glyph->setId("glyph37");
  glyph->setClazz("macromolecule");
  glyph->setCompartmentRef("glyph1");

  label = glyph->createLabel();
  label->setText("c-Fos");

  bbox = glyph->createBBox();
  bbox->setX(850);
  bbox->setY(960);
  bbox->setWidth(100);
  bbox->setHeight(60);

  auto* glyph_15 = glyph->createGlyph();
  glyph_15->setId("glyph37a");
  glyph_15->setClazz("state variable");

  bbox = glyph_15->createBBox();
  bbox->setX(940);
  bbox->setY(979);
  bbox->setWidth(20);
  bbox->setHeight(22);

  glyph = map->createGlyph();
  glyph->setId("glyph32");
  glyph->setClazz("process");

  bbox = glyph->createBBox();
  bbox->setX(1040);
  bbox->setY(980);
  bbox->setWidth(20);
  bbox->setHeight(20);

  port = glyph->createPort();
  port->setId("glyph32.2");
  port->setX(1070);
  port->setY(990);

  port = glyph->createPort();
  port->setId("glyph32.1");
  port->setX(1030);
  port->setY(990);

  glyph = map->createGlyph();
  glyph->setId("glyph38");
  glyph->setClazz("macromolecule");
  glyph->setCompartmentRef("glyph1");

  label = glyph->createLabel();
  label->setText("IRS1-4");

  bbox = glyph->createBBox();
  bbox->setX(190);
  bbox->setY(380);
  bbox->setWidth(100);
  bbox->setHeight(60);

  auto* glyph_16 = glyph->createGlyph();
  glyph_16->setId("glyph38a");
  glyph_16->setClazz("state variable");

  bbox = glyph_16->createBBox();
  bbox->setX(280);
  bbox->setY(399);
  bbox->setWidth(20);
  bbox->setHeight(22);

  glyph = map->createGlyph();
  glyph->setId("glyph8");
  glyph->setClazz("process");

  bbox = glyph->createBBox();
  bbox->setX(370);
  bbox->setY(400);
  bbox->setWidth(20);
  bbox->setHeight(20);

  port = glyph->createPort();
  port->setId("glyph8.1");
  port->setX(360);
  port->setY(410);

  port = glyph->createPort();
  port->setId("glyph8.2");
  port->setX(400);
  port->setY(410);

  glyph = map->createGlyph();
  glyph->setId("glyph39");
  glyph->setClazz("macromolecule");
  glyph->setCompartmentRef("glyph1");

  label = glyph->createLabel();
  label->setText("RSK");

  bbox = glyph->createBBox();
  bbox->setX(700);
  bbox->setY(730);
  bbox->setWidth(100);
  bbox->setHeight(60);

  auto* glyph_17 = glyph->createGlyph();
  glyph_17->setId("glyph39a");
  glyph_17->setClazz("state variable");

  bbox = glyph_17->createBBox();
  bbox->setX(790);
  bbox->setY(749);
  bbox->setWidth(20);
  bbox->setHeight(22);

  glyph = map->createGlyph();
  glyph->setId("glyph27");
  glyph->setClazz("process");

  bbox = glyph->createBBox();
  bbox->setX(890);
  bbox->setY(750);
  bbox->setWidth(20);
  bbox->setHeight(20);

  port = glyph->createPort();
  port->setId("glyph27.2");
  port->setX(920);
  port->setY(760);

  port = glyph->createPort();
  port->setId("glyph27.1");
  port->setX(880);
  port->setY(760);

  glyph = map->createGlyph();
  glyph->setId("glyph14");
  glyph->setClazz("macromolecule");
  glyph->setCompartmentRef("glyph1");

  label = glyph->createLabel();
  label->setText("SOS");

  bbox = glyph->createBBox();
  bbox->setX(120);
  bbox->setY(510);
  bbox->setWidth(100);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph11");
  glyph->setClazz("macromolecule");
  glyph->setCompartmentRef("glyph1");

  label = glyph->createLabel();
  label->setText("Grb2");

  bbox = glyph->createBBox();
  bbox->setX(340);
  bbox->setY(510);
  bbox->setWidth(100);
  bbox->setHeight(60);

  auto* glyph_18 = glyph->createGlyph();
  glyph_18->setId("glyph11a");
  glyph_18->setClazz("state variable");

  bbox = glyph_18->createBBox();
  bbox->setX(365);
  bbox->setY(557);
  bbox->setWidth(50);
  bbox->setHeight(26);

  state = glyph_18->createState();
  state->setValue("active");

  glyph = map->createGlyph();
  glyph->setId("glyph15");
  glyph->setClazz("association");
  glyph->setOrientation("vertical");

  bbox = glyph->createBBox();
  bbox->setX(270);
  bbox->setY(640);
  bbox->setWidth(20);
  bbox->setHeight(20);

  port = glyph->createPort();
  port->setId("glyph15.2");
  port->setX(280);
  port->setY(670);

  port = glyph->createPort();
  port->setId("glyph15.1");
  port->setX(280);
  port->setY(630);

  arc = map->createArc();
  arc->setId("a01");
  arc->setClazz("consumption");
  arc->setSource("glyph2");
  arc->setTarget("glyph6.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(170);
  point->setY(230);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(220);
  point->setY(230);

  arc = map->createArc();
  arc->setId("a02");
  arc->setClazz("production");
  arc->setSource("glyph6.2");
  arc->setTarget("glyph5");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(260);
  point->setY(230);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(310);
  point->setY(229.6);

  arc = map->createArc();
  arc->setId("a03");
  arc->setClazz("consumption");
  arc->setSource("glyph0");
  arc->setTarget("glyph6.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(182.5);
  point->setY(140);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(220);
  point->setY(230);

  arc = map->createArc();
  arc->setId("a04");
  arc->setClazz("catalysis");
  arc->setSource("glyph5");
  arc->setTarget("glyph8");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(380);
  point->setY(260);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(380);
  point->setY(400);

  arc = map->createArc();
  arc->setId("a05");
  arc->setClazz("consumption");
  arc->setSource("glyph9");
  arc->setTarget("glyph8.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(316.641);
  point->setY(344.962);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(360);
  point->setY(410);

  arc = map->createArc();
  arc->setId("a06");
  arc->setClazz("production");
  arc->setSource("glyph8.2");
  arc->setTarget("glyph10");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(400);
  point->setY(410);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(431.582);
  point->setY(343.681);

  arc = map->createArc();
  arc->setId("a07");
  arc->setClazz("stimulation");
  arc->setSource("glyph7");
  arc->setTarget("glyph13");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(520);
  point->setY(440);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(520);
  point->setY(530);

  arc = map->createArc();
  arc->setId("a08");
  arc->setClazz("consumption");
  arc->setSource("glyph12");
  arc->setTarget("glyph13.2");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(590);
  point->setY(540);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(540);
  point->setY(540);

  arc = map->createArc();
  arc->setId("a09");
  arc->setClazz("production");
  arc->setSource("glyph13.1");
  arc->setTarget("glyph11");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(500);
  point->setY(540);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(440);
  point->setY(540);

  arc = map->createArc();
  arc->setId("a10");
  arc->setClazz("production");
  arc->setSource("glyph15.2");
  arc->setTarget("glyph18");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(280);
  point->setY(670);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(280);
  point->setY(710);

  arc = map->createArc();
  arc->setId("a11");
  arc->setClazz("consumption");
  arc->setSource("glyph20");
  arc->setTarget("glyph19.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(200);
  point->setY(910);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(260);
  point->setY(910);

  arc = map->createArc();
  arc->setId("a12");
  arc->setClazz("production");
  arc->setSource("glyph19.2");
  arc->setTarget("glyph21");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(300);
  point->setY(910);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(370);
  point->setY(910);

  arc = map->createArc();
  arc->setId("a13");
  arc->setClazz("stimulation");
  arc->setSource("glyph18");
  arc->setTarget("glyph19");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(280);
  point->setY(810);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(280);
  point->setY(900);

  arc = map->createArc();
  arc->setId("a14");
  arc->setClazz("consumption");
  arc->setSource("glyph22");
  arc->setTarget("glyph19.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(213.416);
  point->setY(1003.17);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(260);
  point->setY(910);

  arc = map->createArc();
  arc->setId("a15");
  arc->setClazz("production");
  arc->setSource("glyph19.2");
  arc->setTarget("glyph23");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(300);
  point->setY(910);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(352);
  point->setY(1006);

  arc = map->createArc();
  arc->setId("a16");
  arc->setClazz("production");
  arc->setSource("glyph27.2");
  arc->setTarget("glyph30");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(920);
  point->setY(760);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(1000);
  point->setY(760);

  arc = map->createArc();
  arc->setId("a17");
  arc->setClazz("production");
  arc->setSource("glyph27.2");
  arc->setTarget("glyph29");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(920);
  point->setY(760);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(952.796);
  point->setY(684.577);

  arc = map->createArc();
  arc->setId("a18");
  arc->setClazz("consumption");
  arc->setSource("glyph28");
  arc->setTarget("glyph27.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(843.416);
  point->setY(686.833);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(880);
  point->setY(760);

  arc = map->createArc();
  arc->setId("a19");
  arc->setClazz("catalysis");
  arc->setSource("glyph31");
  arc->setTarget("glyph27");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(876);
  point->setY(880);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(898);
  point->setY(770);

  arc = map->createArc();
  arc->setId("a20");
  arc->setClazz("production");
  arc->setSource("glyph32.2");
  arc->setTarget("glyph35");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(1070);
  point->setY(990);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(1150);
  point->setY(990);

  arc = map->createArc();
  arc->setId("a21");
  arc->setClazz("production");
  arc->setSource("glyph32.2");
  arc->setTarget("glyph33");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(1070);
  point->setY(990);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(1094.57);
  point->setY(915.725);

  arc = map->createArc();
  arc->setId("a22");
  arc->setClazz("consumption");
  arc->setSource("glyph34");
  arc->setTarget("glyph32.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(993.416);
  point->setY(916.833);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(1030);
  point->setY(990);

  arc = map->createArc();
  arc->setId("a23");
  arc->setClazz("catalysis");
  arc->setSource("glyph30");
  arc->setTarget("glyph32");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(1050);
  point->setY(790);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(1050);
  point->setY(980);

  arc = map->createArc();
  arc->setId("a24");
  arc->setClazz("stimulation");
  arc->setSource("glyph35");
  arc->setTarget("glyph36");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(1200);
  point->setY(1020);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(1200);
  point->setY(1080);

  arc = map->createArc();
  arc->setId("a25");
  arc->setClazz("production");
  arc->setSource("glyph8.2");
  arc->setTarget("glyph7");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(400);
  point->setY(410);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(470);
  point->setY(410);

  arc = map->createArc();
  arc->setId("a26");
  arc->setClazz("equivalence arc");
  arc->setSource("glyph31");
  arc->setTarget("glyph42");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(820);
  point->setY(910);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(740);
  point->setY(910);

  arc = map->createArc();
  arc->setId("a27");
  arc->setClazz("equivalence arc");
  arc->setSource("glyph21");
  arc->setTarget("glyph41");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(470);
  point->setY(910);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(520);
  point->setY(910);

  arc = map->createArc();
  arc->setId("a28");
  arc->setClazz("consumption");
  arc->setSource("glyph37");
  arc->setTarget("glyph32.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(957);
  point->setY(990);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(1030);
  point->setY(990);

  arc = map->createArc();
  arc->setId("a29");
  arc->setClazz("consumption");
  arc->setSource("glyph38");
  arc->setTarget("glyph8.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(297);
  point->setY(410);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(360);
  point->setY(410);

  arc = map->createArc();
  arc->setId("a30");
  arc->setClazz("consumption");
  arc->setSource("glyph39");
  arc->setTarget("glyph27.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(807);
  point->setY(760);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(880);
  point->setY(760);

  arc = map->createArc();
  arc->setId("a31");
  arc->setClazz("consumption");
  arc->setSource("glyph14");
  arc->setTarget("glyph15.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(206.667);
  point->setY(570);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(280);
  point->setY(630);

  arc = map->createArc();
  arc->setId("a32");
  arc->setClazz("consumption");
  arc->setSource("glyph11");
  arc->setTarget("glyph15.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(353.333);
  point->setY(570);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(280);
  point->setY(630);


  writeSBGNToFile(doc, "out.sbgn");
                                  
  delete doc;                     
                                  
  return 0;                       
}                                 
