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
  glyph->setId("glyph8");
  glyph->setClazz("source and sink");

  bbox = glyph->createBBox();
  bbox->setX(310);
  bbox->setY(600);
  bbox->setWidth(60);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph6");
  glyph->setClazz("process");

  bbox = glyph->createBBox();
  bbox->setX(420);
  bbox->setY(620);
  bbox->setWidth(20);
  bbox->setHeight(20);

  port = glyph->createPort();
  port->setId("glyph6.1");
  port->setX(410);
  port->setY(630);

  port = glyph->createPort();
  port->setId("glyph6.2");
  port->setX(450);
  port->setY(630);

  glyph = map->createGlyph();
  glyph->setId("glyph3");
  glyph->setClazz("nucleic acid feature");

  label = glyph->createLabel();
  label->setText("IRF1");

  bbox = glyph->createBBox();
  bbox->setX(500);
  bbox->setY(600);
  bbox->setWidth(120);
  bbox->setHeight(60);

  auto* glyph_1 = glyph->createGlyph();
  glyph_1->setId("glyph3a");
  glyph_1->setClazz("unit of information");

  label = glyph_1->createLabel();
  label->setText("ct:mRNA");

  bbox = glyph_1->createBBox();
  bbox->setX(528.5);
  bbox->setY(591);
  bbox->setWidth(63);
  bbox->setHeight(18);

  glyph = map->createGlyph();
  glyph->setId("glyph7");
  glyph->setClazz("source and sink");

  bbox = glyph->createBBox();
  bbox->setX(440);
  bbox->setY(720);
  bbox->setWidth(60);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph5");
  glyph->setClazz("process");

  bbox = glyph->createBBox();
  bbox->setX(550);
  bbox->setY(740);
  bbox->setWidth(20);
  bbox->setHeight(20);

  port = glyph->createPort();
  port->setId("glyph5.1");
  port->setX(540);
  port->setY(750);

  port = glyph->createPort();
  port->setId("glyph5.2");
  port->setX(580);
  port->setY(750);

  glyph = map->createGlyph();
  glyph->setId("glyph15");
  glyph->setClazz("macromolecule");

  label = glyph->createLabel();
  label->setText("IRF1");

  bbox = glyph->createBBox();
  bbox->setX(620);
  bbox->setY(720);
  bbox->setWidth(120);
  bbox->setHeight(60);

  auto* glyph_2 = glyph->createGlyph();
  glyph_2->setId("glyph15a");
  glyph_2->setClazz("unit of information");

  label = glyph_2->createLabel();
  label->setText("mt:prot");

  bbox = glyph_2->createBBox();
  bbox->setX(653.5);
  bbox->setY(711);
  bbox->setWidth(53);
  bbox->setHeight(18);

  glyph = map->createGlyph();
  glyph->setId("glyph14");
  glyph->setClazz("nucleic acid feature");

  label = glyph->createLabel();
  label->setText("IRF1");

  bbox = glyph->createBBox();
  bbox->setX(490);
  bbox->setY(410);
  bbox->setWidth(120);
  bbox->setHeight(60);

  auto* glyph_3 = glyph->createGlyph();
  glyph_3->setId("glyph14a");
  glyph_3->setClazz("unit of information");

  label = glyph_3->createLabel();
  label->setText("ct:gene");

  bbox = glyph_3->createBBox();
  bbox->setX(522.5);
  bbox->setY(401);
  bbox->setWidth(55);
  bbox->setHeight(18);

  glyph = map->createGlyph();
  glyph->setId("glyph13");
  glyph->setClazz("complex");

  bbox = glyph->createBBox();
  bbox->setX(100);
  bbox->setY(300);
  bbox->setWidth(220);
  bbox->setHeight(270);

  auto* glyph_4 = glyph->createGlyph();
  glyph_4->setId("glyph11");
  glyph_4->setClazz("complex");

  bbox = glyph_4->createBBox();
  bbox->setX(120);
  bbox->setY(325);
  bbox->setWidth(180);
  bbox->setHeight(140);

  auto* glyph_5 = glyph_4->createGlyph();
  glyph_5->setId("glyph10");
  glyph_5->setClazz("macromolecule");

  label = glyph_5->createLabel();
  label->setText("STAT1α");

  bbox = glyph_5->createBBox();
  bbox->setX(140);
  bbox->setY(365);
  bbox->setWidth(140);
  bbox->setHeight(60);

  auto* glyph_6 = glyph_5->createGlyph();
  glyph_6->setId("glyph10a");
  glyph_6->setClazz("unit of information");

  label = glyph_6->createLabel();
  label->setText("mt:prot");

  bbox = glyph_6->createBBox();
  bbox->setX(183.5);
  bbox->setY(356);
  bbox->setWidth(53);
  bbox->setHeight(18);

  auto* glyph_7 = glyph_5->createGlyph();
  glyph_7->setId("glyph10b");
  glyph_7->setClazz("state variable");

  bbox = glyph_7->createBBox();
  bbox->setX(140.5);
  bbox->setY(411);
  bbox->setWidth(69);
  bbox->setHeight(28);

  state = glyph_7->createState();
  state->setVariable("Y701");
  state->setValue("P");

  auto* glyph_8 = glyph_5->createGlyph();
  glyph_8->setId("glyph10c");
  glyph_8->setClazz("state variable");

  bbox = glyph_8->createBBox();
  bbox->setX(210.5);
  bbox->setY(411);
  bbox->setWidth(69);
  bbox->setHeight(28);

  state = glyph_8->createState();
  state->setVariable("Y727");
  state->setValue("P");

  auto* glyph_9 = glyph->createGlyph();
  glyph_9->setId("glyph12");
  glyph_9->setClazz("nucleic acid feature");

  label = glyph_9->createLabel();
  label->setText("IRF1-GAS");

  bbox = glyph_9->createBBox();
  bbox->setX(150);
  bbox->setY(490);
  bbox->setWidth(120);
  bbox->setHeight(60);

  auto* glyph_10 = glyph_9->createGlyph();
  glyph_10->setId("glyph12a");
  glyph_10->setClazz("unit of information");

  label = glyph_10->createLabel();
  label->setText("ct:grr");

  bbox = glyph_10->createBBox();
  bbox->setX(189);
  bbox->setY(481);
  bbox->setWidth(42);
  bbox->setHeight(18);

  glyph = map->createGlyph();
  glyph->setId("glyph4");
  glyph->setClazz("and");
  glyph->setOrientation("vertical");

  bbox = glyph->createBBox();
  bbox->setX(410);
  bbox->setY(500);
  bbox->setWidth(40);
  bbox->setHeight(40);

  port = glyph->createPort();
  port->setId("glyph4.2");
  port->setX(430);
  port->setY(560);

  port = glyph->createPort();
  port->setId("glyph4.1");
  port->setX(430);
  port->setY(480);

  glyph = map->createGlyph();
  glyph->setId("glyph0");
  glyph->setClazz("complex");

  bbox = glyph->createBBox();
  bbox->setX(40);
  bbox->setY(40);
  bbox->setWidth(180);
  bbox->setHeight(140);

  auto* glyph_11 = glyph->createGlyph();
  glyph_11->setId("glyph1");
  glyph_11->setClazz("macromolecule");

  label = glyph_11->createLabel();
  label->setText("STAT1α");

  bbox = glyph_11->createBBox();
  bbox->setX(60);
  bbox->setY(80);
  bbox->setWidth(140);
  bbox->setHeight(60);

  auto* glyph_12 = glyph_11->createGlyph();
  glyph_12->setId("glyph1a");
  glyph_12->setClazz("unit of information");

  label = glyph_12->createLabel();
  label->setText("mt:prot");

  bbox = glyph_12->createBBox();
  bbox->setX(68.5);
  bbox->setY(71);
  bbox->setWidth(53);
  bbox->setHeight(18);

  auto* glyph_13 = glyph_11->createGlyph();
  glyph_13->setId("glyph1b");
  glyph_13->setClazz("state variable");

  bbox = glyph_13->createBBox();
  bbox->setX(60.5);
  bbox->setY(126);
  bbox->setWidth(69);
  bbox->setHeight(28);

  state = glyph_13->createState();
  state->setVariable("Y701");
  state->setValue("P");

  auto* glyph_14 = glyph_11->createGlyph();
  glyph_14->setId("glyph1c");
  glyph_14->setClazz("state variable");

  bbox = glyph_14->createBBox();
  bbox->setX(130.5);
  bbox->setY(126);
  bbox->setWidth(69);
  bbox->setHeight(28);

  state = glyph_14->createState();
  state->setVariable("Y727");
  state->setValue("P");

  glyph = map->createGlyph();
  glyph->setId("glyph2");
  glyph->setClazz("nucleic acid feature");

  label = glyph->createLabel();
  label->setText("IRF1-GAS");

  bbox = glyph->createBBox();
  bbox->setX(270);
  bbox->setY(80);
  bbox->setWidth(120);
  bbox->setHeight(60);

  auto* glyph_15 = glyph->createGlyph();
  glyph_15->setId("glyph2a");
  glyph_15->setClazz("unit of information");

  label = glyph_15->createLabel();
  label->setText("ct:grr");

  bbox = glyph_15->createBBox();
  bbox->setX(279);
  bbox->setY(71);
  bbox->setWidth(42);
  bbox->setHeight(18);

  glyph = map->createGlyph();
  glyph->setId("glyph9");
  glyph->setClazz("association");
  glyph->setOrientation("vertical");

  bbox = glyph->createBBox();
  bbox->setX(200);
  bbox->setY(220);
  bbox->setWidth(20);
  bbox->setHeight(20);

  port = glyph->createPort();
  port->setId("glyph9.2");
  port->setX(210);
  port->setY(250);

  port = glyph->createPort();
  port->setId("glyph9.1");
  port->setX(210);
  port->setY(210);

  arc = map->createArc();
  arc->setId("a01");
  arc->setClazz("necessary stimulation");
  arc->setSource("glyph4.2");
  arc->setTarget("glyph6");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(430);
  point->setY(560);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(430);
  point->setY(620);

  arc = map->createArc();
  arc->setId("a02");
  arc->setClazz("necessary stimulation");
  arc->setSource("glyph3");
  arc->setTarget("glyph5");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(560);
  point->setY(660);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(560);
  point->setY(740);

  arc = map->createArc();
  arc->setId("a03");
  arc->setClazz("consumption");
  arc->setSource("glyph8");
  arc->setTarget("glyph6.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(370);
  point->setY(630);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(410);
  point->setY(630);

  arc = map->createArc();
  arc->setId("a04");
  arc->setClazz("production");
  arc->setSource("glyph6.2");
  arc->setTarget("glyph3");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(450);
  point->setY(630);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(500);
  point->setY(630);

  arc = map->createArc();
  arc->setId("a05");
  arc->setClazz("consumption");
  arc->setSource("glyph7");
  arc->setTarget("glyph5.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(500);
  point->setY(750);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(540);
  point->setY(750);

  arc = map->createArc();
  arc->setId("a06");
  arc->setClazz("production");
  arc->setSource("glyph5.2");
  arc->setTarget("glyph15");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(580);
  point->setY(750);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(620);
  point->setY(750);

  arc = map->createArc();
  arc->setId("a07");
  arc->setClazz("production");
  arc->setSource("glyph9.2");
  arc->setTarget("glyph13");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(210);
  point->setY(250);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(210);
  point->setY(300);

  arc = map->createArc();
  arc->setId("a08");
  arc->setClazz("logic arc");
  arc->setSource("glyph14");
  arc->setTarget("glyph4.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(490);
  point->setY(460);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(430);
  point->setY(480);

  arc = map->createArc();
  arc->setId("a09");
  arc->setClazz("logic arc");
  arc->setSource("glyph13");
  arc->setTarget("glyph4.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(320);
  point->setY(457.5);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(430);
  point->setY(480);

  arc = map->createArc();
  arc->setId("a10");
  arc->setClazz("consumption");
  arc->setSource("glyph0");
  arc->setTarget("glyph9.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(186);
  point->setY(180);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(210);
  point->setY(210);

  arc = map->createArc();
  arc->setId("a11");
  arc->setClazz("consumption");
  arc->setSource("glyph2");
  arc->setTarget("glyph9.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(294);
  point->setY(140);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(210);
  point->setY(210);


  writeSBGNToFile(doc, "out.sbgn");
                                  
  delete doc;                     
                                  
  return 0;                       
}                                 
