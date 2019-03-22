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
  glyph->setClazz("macromolecule");

  label = glyph->createLabel();
  label->setText("B");

  bbox = glyph->createBBox();
  bbox->setX(286);
  bbox->setY(140);
  bbox->setWidth(108);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph0");
  glyph->setClazz("macromolecule");

  label = glyph->createLabel();
  label->setText("C");

  bbox = glyph->createBBox();
  bbox->setX(446);
  bbox->setY(90);
  bbox->setWidth(108);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph2");
  glyph->setClazz("macromolecule");

  label = glyph->createLabel();
  label->setText("D");

  bbox = glyph->createBBox();
  bbox->setX(636);
  bbox->setY(90);
  bbox->setWidth(108);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph5");
  glyph->setClazz("simple chemical");

  label = glyph->createLabel();
  label->setText("I");

  bbox = glyph->createBBox();
  bbox->setX(250);
  bbox->setY(490);
  bbox->setWidth(60);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph4");
  glyph->setClazz("simple chemical");

  label = glyph->createLabel();
  label->setText("II");

  bbox = glyph->createBBox();
  bbox->setX(460);
  bbox->setY(490);
  bbox->setWidth(60);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph9");
  glyph->setClazz("process");

  label = glyph->createLabel();

  bbox = glyph->createBBox();
  bbox->setX(368);
  bbox->setY(508);
  bbox->setWidth(24);
  bbox->setHeight(24);

  port = glyph->createPort();
  port->setId("glyph9.1");
  port->setX(356);
  port->setY(520);

  port = glyph->createPort();
  port->setId("glyph9.2");
  port->setX(404);
  port->setY(520);

  glyph = map->createGlyph();
  glyph->setId("glyph3");
  glyph->setClazz("macromolecule");

  label = glyph->createLabel();
  label->setText("A");

  bbox = glyph->createBBox();
  bbox->setX(156);
  bbox->setY(260);
  bbox->setWidth(108);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph6");
  glyph->setClazz("not");

  label = glyph->createLabel();
  label->setText("NOT");

  bbox = glyph->createBBox();
  bbox->setX(319);
  bbox->setY(249);
  bbox->setWidth(42);
  bbox->setHeight(42);

  port = glyph->createPort();
  port->setId("glyph6.1");
  port->setX(340);
  port->setY(228);

  port = glyph->createPort();
  port->setId("glyph6.2");
  port->setX(340);
  port->setY(312);

  glyph = map->createGlyph();
  glyph->setId("glyph7");
  glyph->setClazz("and");

  label = glyph->createLabel();
  label->setText("AND");

  bbox = glyph->createBBox();
  bbox->setX(549);
  bbox->setY(239);
  bbox->setWidth(42);
  bbox->setHeight(42);

  port = glyph->createPort();
  port->setId("glyph7.1");
  port->setX(570);
  port->setY(218);

  port = glyph->createPort();
  port->setId("glyph7.2");
  port->setX(570);
  port->setY(302);

  glyph = map->createGlyph();
  glyph->setId("glyph8");
  glyph->setClazz("or");

  label = glyph->createLabel();
  label->setText("OR");

  bbox = glyph->createBBox();
  bbox->setX(359);
  bbox->setY(419);
  bbox->setWidth(42);
  bbox->setHeight(42);

  port = glyph->createPort();
  port->setId("glyph8.2");
  port->setX(380);
  port->setY(482);

  port = glyph->createPort();
  port->setId("glyph8.1");
  port->setX(380);
  port->setY(398);

  arc = map->createArc();
  arc->setId("arc000000");
  arc->setClazz("logic arc");
  arc->setSource("glyph1");
  arc->setTarget("glyph6.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(340);
  point->setY(200);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(340);
  point->setY(228);

  arc = map->createArc();
  arc->setId("arc000001");
  arc->setClazz("logic arc");
  arc->setSource("glyph0");
  arc->setTarget("glyph7.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(521.429);
  point->setY(150);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(570);
  point->setY(218);

  arc = map->createArc();
  arc->setId("arc000002");
  arc->setClazz("logic arc");
  arc->setSource("glyph2");
  arc->setTarget("glyph7.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(653.265);
  point->setY(150);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(570);
  point->setY(218);

  arc = map->createArc();
  arc->setId("arc000003");
  arc->setClazz("consumption");
  arc->setSource("glyph5");
  arc->setTarget("glyph9.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(310);
  point->setY(520);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(356);
  point->setY(520);

  arc = map->createArc();
  arc->setId("arc000004");
  arc->setClazz("production");
  arc->setSource("glyph9.2");
  arc->setTarget("glyph4");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(404);
  point->setY(520);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(460);
  point->setY(520);

  arc = map->createArc();
  arc->setId("arc000005");
  arc->setClazz("stimulation");
  arc->setSource("glyph8.2");
  arc->setTarget("glyph9");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(380);
  point->setY(482);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(380);
  point->setY(508);

  arc = map->createArc();
  arc->setId("arc000006");
  arc->setClazz("logic arc");
  arc->setSource("glyph3");
  arc->setTarget("glyph8.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(257.222);
  point->setY(320);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(380);
  point->setY(398);

  arc = map->createArc();
  arc->setId("arc000007");
  arc->setClazz("logic arc");
  arc->setSource("glyph6.2");
  arc->setTarget("glyph8.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(340);
  point->setY(312);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(380);
  point->setY(398);

  arc = map->createArc();
  arc->setId("arc000008");
  arc->setClazz("logic arc");
  arc->setSource("glyph7.2");
  arc->setTarget("glyph8.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(570);
  point->setY(302);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(380);
  point->setY(398);


  writeSBGNToFile(doc, "out.sbgn");
                                  
  delete doc;                     
                                  
  return 0;                       
}                                 
