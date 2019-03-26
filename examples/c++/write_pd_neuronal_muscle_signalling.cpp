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
  glyph->setId("glyph1");
  glyph->setClazz("compartment");
  glyph->setCompartmentOrder(1);

  label = glyph->createLabel();
  label->setText("synaptic cleft");

  bbox = label->createBBox();
  bbox->setX(487);
  bbox->setY(478.5);
  bbox->setWidth(126);
  bbox->setHeight(23);

  bbox = glyph->createBBox();
  bbox->setX(50);
  bbox->setY(320);
  bbox->setWidth(1000);
  bbox->setHeight(340);

  glyph = map->createGlyph();
  glyph->setId("glyph0");
  glyph->setClazz("compartment");
  glyph->setCompartmentOrder(2);

  label = glyph->createLabel();
  label->setText("synaptic button");

  bbox = label->createBBox();
  bbox->setX(478);
  bbox->setY(58);
  bbox->setWidth(144);
  bbox->setHeight(23);

  bbox = glyph->createBBox();
  bbox->setX(90);
  bbox->setY(50);
  bbox->setWidth(920);
  bbox->setHeight(320);

  glyph = map->createGlyph();
  glyph->setId("glyph2");
  glyph->setClazz("compartment");
  glyph->setCompartmentOrder(2);

  label = glyph->createLabel();
  label->setText("muscle cytosol");

  bbox = label->createBBox();
  bbox->setX(479);
  bbox->setY(1299);
  bbox->setWidth(142);
  bbox->setHeight(23);

  bbox = glyph->createBBox();
  bbox->setX(90);
  bbox->setY(610);
  bbox->setWidth(920);
  bbox->setHeight(720);

  glyph = map->createGlyph();
  glyph->setId("glyph14");
  glyph->setClazz("compartment");
  glyph->setCompartmentOrder(3);

  label = glyph->createLabel();
  label->setText("synaptic vesicle");

  bbox = label->createBBox();
  bbox->setX(674.5);
  bbox->setY(188);
  bbox->setWidth(151);
  bbox->setHeight(23);

  bbox = glyph->createBBox();
  bbox->setX(650);
  bbox->setY(180);
  bbox->setWidth(200);
  bbox->setHeight(120);

  glyph = map->createGlyph();
  glyph->setId("glyph34");
  glyph->setClazz("compartment");
  glyph->setCompartmentOrder(3);

  label = glyph->createLabel();
  label->setText("ER");

  bbox = label->createBBox();
  bbox->setX(923);
  bbox->setY(628);
  bbox->setWidth(34);
  bbox->setHeight(23);

  bbox = glyph->createBBox();
  bbox->setX(840);
  bbox->setY(620);
  bbox->setWidth(200);
  bbox->setHeight(120);

  glyph = map->createGlyph();
  glyph->setId("glyph8");
  glyph->setClazz("macromolecule");
  glyph->setCompartmentRef("glyph0");

  label = glyph->createLabel();
  label->setText("CHT1");

  bbox = glyph->createBBox();
  bbox->setX(120);
  bbox->setY(290);
  bbox->setWidth(120);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph13");
  glyph->setClazz("simple chemical");
  glyph->setCompartmentRef("glyph0");

  label = glyph->createLabel();
  label->setText("Ach");

  bbox = glyph->createBBox();
  bbox->setX(490);
  bbox->setY(220);
  bbox->setWidth(60);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph4");
  glyph->setClazz("macromolecule");
  glyph->setCompartmentRef("glyph0");

  label = glyph->createLabel();
  label->setText("vAChT");

  bbox = glyph->createBBox();
  bbox->setX(540);
  bbox->setY(100);
  bbox->setWidth(120);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph18");
  glyph->setClazz("process");

  bbox = glyph->createBBox();
  bbox->setX(590);
  bbox->setY(240);
  bbox->setWidth(20);
  bbox->setHeight(20);

  port = glyph->createPort();
  port->setId("glyph18.1");
  port->setX(580);
  port->setY(250);

  port = glyph->createPort();
  port->setId("glyph18.2");
  port->setX(620);
  port->setY(250);

  glyph = map->createGlyph();
  glyph->setId("glyph3");
  glyph->setClazz("macromolecule");
  glyph->setCompartmentRef("glyph0");

  label = glyph->createLabel();
  label->setText("ChAT");

  bbox = glyph->createBBox();
  bbox->setX(380);
  bbox->setY(100);
  bbox->setWidth(120);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph10");
  glyph->setClazz("macromolecule");
  glyph->setCompartmentRef("glyph1");

  label = glyph->createLabel();
  label->setText("AChE");

  bbox = glyph->createBBox();
  bbox->setX(390);
  bbox->setY(395);
  bbox->setWidth(120);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph19");
  glyph->setClazz("process");

  bbox = glyph->createBBox();
  bbox->setX(440);
  bbox->setY(530);
  bbox->setWidth(20);
  bbox->setHeight(20);

  port = glyph->createPort();
  port->setId("glyph19.2");
  port->setX(470);
  port->setY(540);

  port = glyph->createPort();
  port->setId("glyph19.1");
  port->setX(430);
  port->setY(540);

  glyph = map->createGlyph();
  glyph->setId("glyph11");
  glyph->setClazz("simple chemical");
  glyph->setCompartmentRef("glyph1");

  label = glyph->createLabel();
  label->setText("acetate");

  bbox = glyph->createBBox();
  bbox->setX(310);
  bbox->setY(405);
  bbox->setWidth(60);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph9");
  glyph->setClazz("macromolecule");
  glyph->setCompartmentRef("glyph0");

  label = glyph->createLabel();
  label->setText("SNARE");

  bbox = glyph->createBBox();
  bbox->setX(860);
  bbox->setY(290);
  bbox->setWidth(120);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph6");
  glyph->setClazz("simple chemical");
  glyph->setCompartmentRef("glyph14");

  label = glyph->createLabel();
  label->setText("ACh");

  bbox = glyph->createBBox();
  bbox->setX(690);
  bbox->setY(220);
  bbox->setWidth(60);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph17");
  glyph->setClazz("process");
  glyph->setOrientation("vertical");

  bbox = glyph->createBBox();
  bbox->setX(660);
  bbox->setY(440);
  bbox->setWidth(20);
  bbox->setHeight(20);

  port = glyph->createPort();
  port->setId("glyph17.1");
  port->setX(670);
  port->setY(430);

  port = glyph->createPort();
  port->setId("glyph17.2");
  port->setX(670);
  port->setY(470);

  glyph = map->createGlyph();
  glyph->setId("glyph7");
  glyph->setClazz("simple chemical");
  glyph->setCompartmentRef("glyph1");

  label = glyph->createLabel();
  label->setText("ACh");

  bbox = glyph->createBBox();
  bbox->setX(590);
  bbox->setY(510);
  bbox->setWidth(60);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph20");
  glyph->setClazz("macromolecule");
  glyph->setCompartmentRef("glyph2");

  label = glyph->createLabel();
  label->setText("nAChR");

  bbox = glyph->createBBox();
  bbox->setX(350);
  bbox->setY(670);
  bbox->setWidth(120);
  bbox->setHeight(60);

  auto* glyph_1 = glyph->createGlyph();
  glyph_1->setId("glyph20a");
  glyph_1->setClazz("state variable");

  bbox = glyph_1->createBBox();
  bbox->setX(380);
  bbox->setY(715);
  bbox->setWidth(60);
  bbox->setHeight(30);

  state = glyph_1->createState();
  state->setValue("closed");

  glyph = map->createGlyph();
  glyph->setId("glyph24");
  glyph->setClazz("process");

  bbox = glyph->createBBox();
  bbox->setX(610);
  bbox->setY(690);
  bbox->setWidth(20);
  bbox->setHeight(20);

  port = glyph->createPort();
  port->setId("glyph24.1");
  port->setX(600);
  port->setY(700);

  port = glyph->createPort();
  port->setId("glyph24.2");
  port->setX(640);
  port->setY(700);

  glyph = map->createGlyph();
  glyph->setId("glyph22");
  glyph->setClazz("simple chemical");
  glyph->setCompartmentRef("glyph2");

  label = glyph->createLabel();
  label->setText("Ca2+");

  bbox = glyph->createBBox();
  bbox->setX(860);
  bbox->setY(860);
  bbox->setWidth(60);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph42");
  glyph->setClazz("association");
  glyph->setOrientation("vertical");

  bbox = glyph->createBBox();
  bbox->setX(750);
  bbox->setY(1010);
  bbox->setWidth(20);
  bbox->setHeight(20);

  port = glyph->createPort();
  port->setId("glyph42.1");
  port->setX(760);
  port->setY(1000);

  port = glyph->createPort();
  port->setId("glyph42.2");
  port->setX(760);
  port->setY(1040);

  glyph = map->createGlyph();
  glyph->setId("glyph38");
  glyph->setClazz("complex");
  glyph->setCompartmentRef("glyph2");

  bbox = glyph->createBBox();
  bbox->setX(630);
  bbox->setY(1080);
  bbox->setWidth(260);
  bbox->setHeight(160);

  auto* glyph_2 = glyph->createGlyph();
  glyph_2->setId("glyph38a");
  glyph_2->setClazz("state variable");

  bbox = glyph_2->createBBox();
  bbox->setX(726.5);
  bbox->setY(1225);
  bbox->setWidth(67);
  bbox->setHeight(30);

  state = glyph_2->createState();
  state->setValue("relaxed");

  auto* glyph_3 = glyph->createGlyph();
  glyph_3->setId("glyph29");
  glyph_3->setClazz("macromolecule");

  label = glyph_3->createLabel();
  label->setText("myosin");

  bbox = glyph_3->createBBox();
  bbox->setX(760);
  bbox->setY(1100);
  bbox->setWidth(120);
  bbox->setHeight(60);

  auto* glyph_4 = glyph->createGlyph();
  glyph_4->setId("glyph30");
  glyph_4->setClazz("macromolecule");

  label = glyph_4->createLabel();
  label->setText("actin");

  bbox = glyph_4->createBBox();
  bbox->setX(640);
  bbox->setY(1100);
  bbox->setWidth(120);
  bbox->setHeight(60);

  auto* glyph_5 = glyph->createGlyph();
  glyph_5->setId("glyph46");
  glyph_5->setClazz("simple chemical");

  label = glyph_5->createLabel();
  label->setText("ATP");

  bbox = glyph_5->createBBox();
  bbox->setX(790);
  bbox->setY(1160);
  bbox->setWidth(60);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph33");
  glyph->setClazz("simple chemical");
  glyph->setCompartmentRef("glyph2");

  label = glyph->createLabel();
  label->setText("Pi");

  bbox = glyph->createBBox();
  bbox->setX(520);
  bbox->setY(1010);
  bbox->setWidth(60);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph43");
  glyph->setClazz("process");

  bbox = glyph->createBBox();
  bbox->setX(540);
  bbox->setY(1160);
  bbox->setWidth(20);
  bbox->setHeight(20);

  port = glyph->createPort();
  port->setId("glyph43.2");
  port->setX(570);
  port->setY(1170);

  port = glyph->createPort();
  port->setId("glyph43.1");
  port->setX(530);
  port->setY(1170);

  glyph = map->createGlyph();
  glyph->setId("glyph40");
  glyph->setClazz("simple chemical");
  glyph->setCompartmentRef("glyph2");

  label = glyph->createLabel();
  label->setText("ADP");

  bbox = glyph->createBBox();
  bbox->setX(450);
  bbox->setY(1010);
  bbox->setWidth(60);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph44");
  glyph->setClazz("dissociation");
  glyph->setOrientation("vertical");

  bbox = glyph->createBBox();
  bbox->setX(290);
  bbox->setY(980);
  bbox->setWidth(20);
  bbox->setHeight(20);

  port = glyph->createPort();
  port->setId("glyph44.2");
  port->setX(300);
  port->setY(1010);

  port = glyph->createPort();
  port->setId("glyph44.1");
  port->setX(300);
  port->setY(970);

  glyph = map->createGlyph();
  glyph->setId("glyph26");
  glyph->setClazz("macromolecule");
  glyph->setCompartmentRef("glyph2");

  label = glyph->createLabel();
  label->setText("actin");

  bbox = glyph->createBBox();
  bbox->setX(470);
  bbox->setY(910);
  bbox->setWidth(120);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph25");
  glyph->setClazz("simple chemical");
  glyph->setCompartmentRef("glyph2");

  label = glyph->createLabel();
  label->setText("ATP");

  bbox = glyph->createBBox();
  bbox->setX(440);
  bbox->setY(750);
  bbox->setWidth(60);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph27");
  glyph->setClazz("macromolecule");
  glyph->setCompartmentRef("glyph2");

  label = glyph->createLabel();
  label->setText("myosin");

  bbox = glyph->createBBox();
  bbox->setX(290);
  bbox->setY(830);
  bbox->setWidth(120);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph45");
  glyph->setClazz("association");

  bbox = glyph->createBBox();
  bbox->setX(540);
  bbox->setY(850);
  bbox->setWidth(20);
  bbox->setHeight(20);

  port = glyph->createPort();
  port->setId("glyph45.1");
  port->setX(530);
  port->setY(860);

  port = glyph->createPort();
  port->setId("glyph45.2");
  port->setX(570);
  port->setY(860);

  glyph = map->createGlyph();
  glyph->setId("glyph36");
  glyph->setClazz("complex");
  glyph->setCompartmentRef("glyph2");

  bbox = glyph->createBBox();
  bbox->setX(690);
  bbox->setY(830);
  bbox->setWidth(140);
  bbox->setHeight(140);

  auto* glyph_6 = glyph->createGlyph();
  glyph_6->setId("glyph28");
  glyph_6->setClazz("macromolecule");

  label = glyph_6->createLabel();
  label->setText("myosin");

  bbox = glyph_6->createBBox();
  bbox->setX(700);
  bbox->setY(840);
  bbox->setWidth(120);
  bbox->setHeight(60);

  auto* glyph_7 = glyph->createGlyph();
  glyph_7->setId("glyph35");
  glyph_7->setClazz("simple chemical");

  label = glyph_7->createLabel();
  label->setText("ATP");

  bbox = glyph_7->createBBox();
  bbox->setX(730);
  bbox->setY(900);
  bbox->setWidth(60);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph21");
  glyph->setClazz("macromolecule");
  glyph->setCompartmentRef("glyph2");

  label = glyph->createLabel();
  label->setText("nAChR");

  bbox = glyph->createBBox();
  bbox->setX(680);
  bbox->setY(670);
  bbox->setWidth(120);
  bbox->setHeight(60);

  auto* glyph_8 = glyph->createGlyph();
  glyph_8->setId("glyph21a");
  glyph_8->setClazz("state variable");

  bbox = glyph_8->createBBox();
  bbox->setX(714.5);
  bbox->setY(716);
  bbox->setWidth(51);
  bbox->setHeight(28);

  state = glyph_8->createState();
  state->setValue("open");

  glyph = map->createGlyph();
  glyph->setId("glyph5");
  glyph->setClazz("simple chemical");
  glyph->setCompartmentRef("glyph2");

  label = glyph->createLabel();
  label->setText("choline");

  bbox = glyph->createBBox();
  bbox->setX(260);
  bbox->setY(510);
  bbox->setWidth(60);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph15");
  glyph->setClazz("process");
  glyph->setOrientation("vertical");

  bbox = glyph->createBBox();
  bbox->setX(280);
  bbox->setY(310);
  bbox->setWidth(20);
  bbox->setHeight(20);

  port = glyph->createPort();
  port->setId("glyph15.2");
  port->setX(290);
  port->setY(340);

  port = glyph->createPort();
  port->setId("glyph15.1");
  port->setX(290);
  port->setY(300);

  glyph = map->createGlyph();
  glyph->setId("glyph12");
  glyph->setClazz("simple chemical");
  glyph->setCompartmentRef("glyph2");

  label = glyph->createLabel();
  label->setText("choline");

  bbox = glyph->createBBox();
  bbox->setX(260);
  bbox->setY(220);
  bbox->setWidth(60);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph47");
  glyph->setClazz("simple chemical");
  glyph->setCompartmentRef("glyph2");

  label = glyph->createLabel();
  label->setText("acetyl&#10;CoA");

  bbox = glyph->createBBox();
  bbox->setX(260);
  bbox->setY(140);
  bbox->setWidth(60);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph16");
  glyph->setClazz("process");

  bbox = glyph->createBBox();
  bbox->setX(430);
  bbox->setY(240);
  bbox->setWidth(20);
  bbox->setHeight(20);

  port = glyph->createPort();
  port->setId("glyph16.1");
  port->setX(420);
  port->setY(250);

  port = glyph->createPort();
  port->setId("glyph16.2");
  port->setX(460);
  port->setY(250);

  glyph = map->createGlyph();
  glyph->setId("glyph23");
  glyph->setClazz("simple chemical");
  glyph->setCompartmentRef("glyph34");

  label = glyph->createLabel();
  label->setText("Ca2+");

  bbox = glyph->createBBox();
  bbox->setX(860);
  bbox->setY(660);
  bbox->setWidth(60);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph41");
  glyph->setClazz("process");
  glyph->setOrientation("vertical");

  bbox = glyph->createBBox();
  bbox->setX(880);
  bbox->setY(780);
  bbox->setWidth(20);
  bbox->setHeight(20);

  port = glyph->createPort();
  port->setId("glyph41.2");
  port->setX(890);
  port->setY(810);

  port = glyph->createPort();
  port->setId("glyph41.1");
  port->setX(890);
  port->setY(770);

  glyph = map->createGlyph();
  glyph->setId("glyph37");
  glyph->setClazz("complex");
  glyph->setCompartmentRef("glyph2");

  bbox = glyph->createBBox();
  bbox->setX(170);
  bbox->setY(1080);
  bbox->setWidth(260);
  bbox->setHeight(120);

  auto* glyph_9 = glyph->createGlyph();
  glyph_9->setId("glyph37a");
  glyph_9->setClazz("state variable");

  bbox = glyph_9->createBBox();
  bbox->setX(273);
  bbox->setY(1186);
  bbox->setWidth(54);
  bbox->setHeight(28);

  state = glyph_9->createState();
  state->setValue("tense");

  auto* glyph_10 = glyph->createGlyph();
  glyph_10->setId("glyph31");
  glyph_10->setClazz("macromolecule");

  label = glyph_10->createLabel();
  label->setText("actin");

  bbox = glyph_10->createBBox();
  bbox->setX(180);
  bbox->setY(1100);
  bbox->setWidth(120);
  bbox->setHeight(60);

  auto* glyph_11 = glyph->createGlyph();
  glyph_11->setId("glyph39");
  glyph_11->setClazz("macromolecule");

  label = glyph_11->createLabel();
  label->setText("myosin");

  bbox = glyph_11->createBBox();
  bbox->setX(300);
  bbox->setY(1100);
  bbox->setWidth(120);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph32");
  glyph->setClazz("phenotype");

  label = glyph->createLabel();
  label->setText("muscle&#10;contraction");

  bbox = glyph->createBBox();
  bbox->setX(150);
  bbox->setY(1250);
  bbox->setWidth(160);
  bbox->setHeight(60);

  arc = map->createArc();
  arc->setId("a1");
  arc->setClazz("necessary stimulation");
  arc->setSource("glyph8");
  arc->setTarget("glyph15");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(240);
  point->setY(320);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(280);
  point->setY(320);

  arc = map->createArc();
  arc->setId("a2");
  arc->setClazz("consumption");
  arc->setSource("glyph12");
  arc->setTarget("glyph16.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(320);
  point->setY(250);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(420);
  point->setY(250);

  arc = map->createArc();
  arc->setId("a3");
  arc->setClazz("production");
  arc->setSource("glyph16.2");
  arc->setTarget("glyph13");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(460);
  point->setY(250);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(490);
  point->setY(250);

  arc = map->createArc();
  arc->setId("a4");
  arc->setClazz("consumption");
  arc->setSource("glyph13");
  arc->setTarget("glyph18.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(550);
  point->setY(250);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(580);
  point->setY(250);

  arc = map->createArc();
  arc->setId("a5");
  arc->setClazz("production");
  arc->setSource("glyph18.2");
  arc->setTarget("glyph6");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(620);
  point->setY(250);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(690);
  point->setY(250);

  arc = map->createArc();
  arc->setId("a6");
  arc->setClazz("necessary stimulation");
  arc->setSource("glyph4");
  arc->setTarget("glyph18");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(600);
  point->setY(160);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(600);
  point->setY(240);

  arc = map->createArc();
  arc->setId("a7");
  arc->setClazz("catalysis");
  arc->setSource("glyph3");
  arc->setTarget("glyph16");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(440);
  point->setY(160);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(440);
  point->setY(240);

  arc = map->createArc();
  arc->setId("a8");
  arc->setClazz("catalysis");
  arc->setSource("glyph10");
  arc->setTarget("glyph19");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(450);
  point->setY(455);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(450);
  point->setY(530);

  arc = map->createArc();
  arc->setId("a9");
  arc->setClazz("consumption");
  arc->setSource("glyph7");
  arc->setTarget("glyph19.2");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(590);
  point->setY(540);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(470);
  point->setY(540);

  arc = map->createArc();
  arc->setId("a10");
  arc->setClazz("production");
  arc->setSource("glyph19.1");
  arc->setTarget("glyph5");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(430);
  point->setY(540);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(320);
  point->setY(540);

  arc = map->createArc();
  arc->setId("a11");
  arc->setClazz("production");
  arc->setSource("glyph19.1");
  arc->setTarget("glyph11");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(430);
  point->setY(540);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(361.701);
  point->setY(455.714);

  arc = map->createArc();
  arc->setId("a12");
  arc->setClazz("necessary stimulation");
  arc->setSource("glyph9");
  arc->setTarget("glyph17");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(906.154);
  point->setY(350);

  point = arc->createNext();
  point->setElementName("next");
  point->setX(860);
  point->setY(450);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(680);
  point->setY(450);

  arc = map->createArc();
  arc->setId("a13");
  arc->setClazz("consumption");
  arc->setSource("glyph6");
  arc->setTarget("glyph17.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(711.971);
  point->setY(278.906);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(670);
  point->setY(430);

  arc = map->createArc();
  arc->setId("a14");
  arc->setClazz("production");
  arc->setSource("glyph17.2");
  arc->setTarget("glyph7");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(670);
  point->setY(470);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(634.569);
  point->setY(513.775);

  arc = map->createArc();
  arc->setId("a15");
  arc->setClazz("necessary stimulation");
  arc->setSource("glyph7");
  arc->setTarget("glyph24");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(620);
  point->setY(570);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(620);
  point->setY(690);

  arc = map->createArc();
  arc->setId("a16");
  arc->setClazz("consumption");
  arc->setSource("glyph20");
  arc->setTarget("glyph24.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(470);
  point->setY(700);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(600);
  point->setY(700);

  arc = map->createArc();
  arc->setId("a17");
  arc->setClazz("production");
  arc->setSource("glyph24.2");
  arc->setTarget("glyph21");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(640);
  point->setY(700);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(680);
  point->setY(700);

  arc = map->createArc();
  arc->setId("a18");
  arc->setClazz("production");
  arc->setSource("glyph41.2");
  arc->setTarget("glyph22");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(890);
  point->setY(810);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(890);
  point->setY(860);

  arc = map->createArc();
  arc->setId("a19");
  arc->setClazz("stimulation");
  arc->setSource("glyph22");
  arc->setTarget("glyph42");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(890);
  point->setY(920);

  point = arc->createNext();
  point->setElementName("next");
  point->setX(890);
  point->setY(1020);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(770);
  point->setY(1020);

  arc = map->createArc();
  arc->setId("a20");
  arc->setClazz("consumption");
  arc->setSource("glyph36");
  arc->setTarget("glyph42.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(760);
  point->setY(970);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(760);
  point->setY(1000);

  arc = map->createArc();
  arc->setId("a21");
  arc->setClazz("consumption");
  arc->setSource("glyph26");
  arc->setTarget("glyph42.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(590);
  point->setY(955.652);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(760);
  point->setY(1000);

  arc = map->createArc();
  arc->setId("a22");
  arc->setClazz("production");
  arc->setSource("glyph42.2");
  arc->setTarget("glyph38");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(760);
  point->setY(1040);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(760);
  point->setY(1080);

  arc = map->createArc();
  arc->setId("a23");
  arc->setClazz("consumption");
  arc->setSource("glyph38");
  arc->setTarget("glyph43.2");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(630);
  point->setY(1166.84);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(570);
  point->setY(1170);

  arc = map->createArc();
  arc->setId("a24");
  arc->setClazz("production");
  arc->setSource("glyph43.1");
  arc->setTarget("glyph37");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(530);
  point->setY(1170);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(430);
  point->setY(1155.6);

  arc = map->createArc();
  arc->setId("a25");
  arc->setClazz("production");
  arc->setSource("glyph43.1");
  arc->setTarget("glyph33");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(530);
  point->setY(1170);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(550);
  point->setY(1070);

  arc = map->createArc();
  arc->setId("a26");
  arc->setClazz("production");
  arc->setSource("glyph43.1");
  arc->setTarget("glyph40");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(530);
  point->setY(1170);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(494.223);
  point->setY(1066.41);

  arc = map->createArc();
  arc->setId("a27");
  arc->setClazz("consumption");
  arc->setSource("glyph37");
  arc->setTarget("glyph44.2");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(300);
  point->setY(1080);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(300);
  point->setY(1010);

  arc = map->createArc();
  arc->setId("a28");
  arc->setClazz("production");
  arc->setSource("glyph44.1");
  arc->setTarget("glyph27");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(300);
  point->setY(970);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(338.462);
  point->setY(890);

  arc = map->createArc();
  arc->setId("a29");
  arc->setClazz("production");
  arc->setSource("glyph44.1");
  arc->setTarget("glyph26");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(300);
  point->setY(970);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(470);
  point->setY(953.043);

  arc = map->createArc();
  arc->setId("a30");
  arc->setClazz("consumption");
  arc->setSource("glyph25");
  arc->setTarget("glyph45.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(488);
  point->setY(804);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(530);
  point->setY(860);

  arc = map->createArc();
  arc->setId("a31");
  arc->setClazz("consumption");
  arc->setSource("glyph27");
  arc->setTarget("glyph45.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(410);
  point->setY(860);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(530);
  point->setY(860);

  arc = map->createArc();
  arc->setId("a32");
  arc->setClazz("production");
  arc->setSource("glyph45.2");
  arc->setTarget("glyph36");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(570);
  point->setY(860);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(690);
  point->setY(886.667);

  arc = map->createArc();
  arc->setId("a33");
  arc->setClazz("necessary stimulation");
  arc->setSource("glyph21");
  arc->setTarget("glyph41");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(740);
  point->setY(742);

  point = arc->createNext();
  point->setElementName("next");
  point->setX(740);
  point->setY(790);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(880);
  point->setY(790);

  arc = map->createArc();
  arc->setId("a34");
  arc->setClazz("consumption");
  arc->setSource("glyph5");
  arc->setTarget("glyph15.2");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(290);
  point->setY(510);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(290);
  point->setY(340);

  arc = map->createArc();
  arc->setId("a35");
  arc->setClazz("production");
  arc->setSource("glyph15.1");
  arc->setTarget("glyph12");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(290);
  point->setY(300);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(290);
  point->setY(280);

  arc = map->createArc();
  arc->setId("a36");
  arc->setClazz("consumption");
  arc->setSource("glyph47");
  arc->setTarget("glyph16.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(315.55);
  point->setY(185.723);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(420);
  point->setY(250);

  arc = map->createArc();
  arc->setId("a37");
  arc->setClazz("consumption");
  arc->setSource("glyph23");
  arc->setTarget("glyph41.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(890);
  point->setY(720);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(890);
  point->setY(770);

  arc = map->createArc();
  arc->setId("a38");
  arc->setClazz("stimulation");
  arc->setSource("glyph37");
  arc->setTarget("glyph32");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(235);
  point->setY(1200);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(245);
  point->setY(1250);


    std::string outfile = "out.sbgn";
  if (argc > 1)
    outfile = argv[1];
  writeSBGNToFile(doc, outfile.c_str());
                                  
  delete doc;                     
                                  
  return 0;                       
}                                 
