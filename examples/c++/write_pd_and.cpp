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
  glyph->setId("glyph0");
  glyph->setClazz("nucleic acid feature");

  label = glyph->createLabel();
  label->setText("IRF1");

  bbox = glyph->createBBox();
  bbox->setX(440);
  bbox->setY(330);
  bbox->setWidth(120);
  bbox->setHeight(60);

  auto* glyph_1 = glyph->createGlyph();
  glyph_1->setId("glyph0a");
  glyph_1->setClazz("unit of information");

  label = glyph_1->createLabel();
  label->setText("ct:mRNA");

  bbox = glyph_1->createBBox();
  bbox->setX(468);
  bbox->setY(321);
  bbox->setWidth(63);
  bbox->setHeight(18);

  glyph = map->createGlyph();
  glyph->setId("glyph1");
  glyph->setClazz("and");
  glyph->setOrientation("vertical");

  bbox = glyph->createBBox();
  bbox->setX(350);
  bbox->setY(230);
  bbox->setWidth(40);
  bbox->setHeight(40);

  port = glyph->createPort();
  port->setId("glyph1.1");
  port->setX(370);
  port->setY(210);

  port = glyph->createPort();
  port->setId("glyph1.2");
  port->setX(370);
  port->setY(290);

  glyph = map->createGlyph();
  glyph->setId("glyph2");
  glyph->setClazz("process");
  glyph->setOrientation("vertical");

  bbox = glyph->createBBox();
  bbox->setX(360);
  bbox->setY(350);
  bbox->setWidth(20);
  bbox->setHeight(20);

  port = glyph->createPort();
  port->setId("glyph2.1");
  port->setX(350);
  port->setY(360);

  port = glyph->createPort();
  port->setId("glyph2.2");
  port->setX(390);
  port->setY(360);

  glyph = map->createGlyph();
  glyph->setId("glyph3");
  glyph->setClazz("source and sink");

  bbox = glyph->createBBox();
  bbox->setX(250);
  bbox->setY(330);
  bbox->setWidth(60);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph7");
  glyph->setClazz("complex");

  bbox = glyph->createBBox();
  bbox->setX(40);
  bbox->setY(30);
  bbox->setWidth(220);
  bbox->setHeight(270);

  auto* glyph_2 = glyph->createGlyph();
  glyph_2->setId("glyph5");
  glyph_2->setClazz("complex");

  bbox = glyph_2->createBBox();
  bbox->setX(60);
  bbox->setY(55);
  bbox->setWidth(180);
  bbox->setHeight(140);

  auto* glyph_3 = glyph_2->createGlyph();
  glyph_3->setId("glyph4");
  glyph_3->setClazz("macromolecule");

  label = glyph_3->createLabel();
  label->setText("STAT1α");

  bbox = glyph_3->createBBox();
  bbox->setX(80);
  bbox->setY(95);
  bbox->setWidth(140);
  bbox->setHeight(60);

  auto* glyph_4 = glyph_3->createGlyph();
  glyph_4->setId("glyph4a");
  glyph_4->setClazz("unit of information");

  label = glyph_4->createLabel();
  label->setText("mt:prot");

  bbox = glyph_4->createBBox();
  bbox->setX(123);
  bbox->setY(86);
  bbox->setWidth(53);
  bbox->setHeight(18);

  auto* glyph_5 = glyph_3->createGlyph();
  glyph_5->setId("glyph4b");
  glyph_5->setClazz("state variable");

  bbox = glyph_5->createBBox();
  bbox->setX(80);
  bbox->setY(141);
  bbox->setWidth(69);
  bbox->setHeight(28);

  state = glyph_5->createState();
  state->setVariable("Y701");
  state->setValue("P");

  auto* glyph_6 = glyph_3->createGlyph();
  glyph_6->setId("glyph4c");
  glyph_6->setClazz("state variable");

  bbox = glyph_6->createBBox();
  bbox->setX(150);
  bbox->setY(141);
  bbox->setWidth(69);
  bbox->setHeight(28);

  state = glyph_6->createState();
  state->setVariable("Y727");
  state->setValue("P");

  auto* glyph_7 = glyph->createGlyph();
  glyph_7->setId("glyph6");
  glyph_7->setClazz("nucleic acid feature");

  label = glyph_7->createLabel();
  label->setText("IRF1-GAS");

  bbox = glyph_7->createBBox();
  bbox->setX(90);
  bbox->setY(220);
  bbox->setWidth(120);
  bbox->setHeight(60);

  auto* glyph_8 = glyph_7->createGlyph();
  glyph_8->setId("glyph6a");
  glyph_8->setClazz("unit of information");

  label = glyph_8->createLabel();
  label->setText("ct:grr");

  bbox = glyph_8->createBBox();
  bbox->setX(129);
  bbox->setY(211);
  bbox->setWidth(42);
  bbox->setHeight(18);

  glyph = map->createGlyph();
  glyph->setId("glyph8");
  glyph->setClazz("nucleic acid feature");

  label = glyph->createLabel();
  label->setText("IRF1");

  bbox = glyph->createBBox();
  bbox->setX(430);
  bbox->setY(140);
  bbox->setWidth(120);
  bbox->setHeight(60);

  auto* glyph_9 = glyph->createGlyph();
  glyph_9->setId("glyph8a");
  glyph_9->setClazz("unit of information");

  label = glyph_9->createLabel();
  label->setText("ct:gene");

  bbox = glyph_9->createBBox();
  bbox->setX(462);
  bbox->setY(131);
  bbox->setWidth(55);
  bbox->setHeight(18);

  arc = map->createArc();
  arc->setId("a01");
  arc->setClazz("necessary stimulation");
  arc->setSource("glyph1.2");
  arc->setTarget("glyph2");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(370);
  point->setY(290);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(370);
  point->setY(350);

  arc = map->createArc();
  arc->setId("a02");
  arc->setClazz("consumption");
  arc->setSource("glyph3");
  arc->setTarget("glyph2.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(310);
  point->setY(360);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(350);
  point->setY(360);

  arc = map->createArc();
  arc->setId("a03");
  arc->setClazz("production");
  arc->setSource("glyph2.2");
  arc->setTarget("glyph0");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(390);
  point->setY(360);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(440);
  point->setY(360);

  arc = map->createArc();
  arc->setId("a04");
  arc->setClazz("logic arc");
  arc->setSource("glyph8");
  arc->setTarget("glyph1.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(430);
  point->setY(189);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(370);
  point->setY(210);

  arc = map->createArc();
  arc->setId("a05");
  arc->setClazz("logic arc");
  arc->setSource("glyph7");
  arc->setTarget("glyph1.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(260);
  point->setY(188);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(370);
  point->setY(210);


    std::string outfile = "out.sbgn";
  if (argc > 1)
    outfile = argv[1];
  writeSBGNToFile(doc, outfile.c_str());
                                  
  delete doc;                     
                                  
  return 0;                       
}                                 
