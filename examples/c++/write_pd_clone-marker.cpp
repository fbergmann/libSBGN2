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
  glyph->setClazz("simple chemical");

  label = glyph->createLabel();
  label->setText("Glucose");

  bbox = glyph->createBBox();
  bbox->setX(20);
  bbox->setY(110);
  bbox->setWidth(60);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph2");
  glyph->setClazz("simple chemical");

  label = glyph->createLabel();
  label->setText("ATP");

  bbox = glyph->createBBox();
  bbox->setX(70);
  bbox->setY(200);
  bbox->setWidth(60);
  bbox->setHeight(60);

  clone = glyph->createClone();

  glyph = map->createGlyph();
  glyph->setId("glyph3");
  glyph->setClazz("simple chemical");

  label = glyph->createLabel();
  label->setText("ADP");

  bbox = glyph->createBBox();
  bbox->setX(200);
  bbox->setY(200);
  bbox->setWidth(60);
  bbox->setHeight(60);

  clone = glyph->createClone();

  glyph = map->createGlyph();
  glyph->setId("glyph4");
  glyph->setClazz("simple chemical");

  label = glyph->createLabel();
  label->setText("Glucose&#10;6P");

  bbox = glyph->createBBox();
  bbox->setX(250);
  bbox->setY(110);
  bbox->setWidth(60);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph5");
  glyph->setClazz("simple chemical");

  label = glyph->createLabel();
  label->setText("Fructose&#10;6P");

  bbox = glyph->createBBox();
  bbox->setX(450);
  bbox->setY(110);
  bbox->setWidth(60);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph6");
  glyph->setClazz("simple chemical");

  label = glyph->createLabel();
  label->setText("ATP");

  bbox = glyph->createBBox();
  bbox->setX(500);
  bbox->setY(200);
  bbox->setWidth(60);
  bbox->setHeight(60);

  clone = glyph->createClone();

  glyph = map->createGlyph();
  glyph->setId("glyph7");
  glyph->setClazz("simple chemical");

  label = glyph->createLabel();
  label->setText("ADP");

  bbox = glyph->createBBox();
  bbox->setX(630);
  bbox->setY(200);
  bbox->setWidth(60);
  bbox->setHeight(60);

  clone = glyph->createClone();

  glyph = map->createGlyph();
  glyph->setId("glyph8");
  glyph->setClazz("simple chemical");

  label = glyph->createLabel();
  label->setText("Fructose&#10;1,6P");

  bbox = glyph->createBBox();
  bbox->setX(660);
  bbox->setY(110);
  bbox->setWidth(60);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph9");
  glyph->setClazz("process");
  glyph->setOrientation("horizontal");

  bbox = glyph->createBBox();
  bbox->setX(150);
  bbox->setY(130);
  bbox->setWidth(20);
  bbox->setHeight(20);

  port = glyph->createPort();
  port->setId("glyph9a");
  port->setX(140);
  port->setY(140);

  port = glyph->createPort();
  port->setId("glyph9b");
  port->setX(180);
  port->setY(140);

  glyph = map->createGlyph();
  glyph->setId("glyph10");
  glyph->setClazz("process");
  glyph->setOrientation("horizontal");

  bbox = glyph->createBBox();
  bbox->setX(360);
  bbox->setY(130);
  bbox->setWidth(20);
  bbox->setHeight(20);

  port = glyph->createPort();
  port->setId("glyph10a");
  port->setX(350);
  port->setY(140);

  port = glyph->createPort();
  port->setId("glyph10b");
  port->setX(390);
  port->setY(140);

  glyph = map->createGlyph();
  glyph->setId("glyph11");
  glyph->setClazz("process");
  glyph->setOrientation("horizontal");

  bbox = glyph->createBBox();
  bbox->setX(580);
  bbox->setY(130);
  bbox->setWidth(20);
  bbox->setHeight(20);

  port = glyph->createPort();
  port->setId("glyph11a");
  port->setX(570);
  port->setY(140);

  port = glyph->createPort();
  port->setId("glyph11b");
  port->setX(610);
  port->setY(140);

  arc = map->createArc();
  arc->setId("a01");
  arc->setClazz("consumption");
  arc->setSource("glyph1");
  arc->setTarget("glyph9a");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(80);
  point->setY(140);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(140);
  point->setY(140);

  arc = map->createArc();
  arc->setId("a02");
  arc->setClazz("consumption");
  arc->setSource("glyph2");
  arc->setTarget("glyph9a");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(110);
  point->setY(201);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(140);
  point->setY(140);

  arc = map->createArc();
  arc->setId("a03");
  arc->setClazz("consumption");
  arc->setSource("glyph4");
  arc->setTarget("glyph10a");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(310);
  point->setY(140);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(350);
  point->setY(140);

  arc = map->createArc();
  arc->setId("a04");
  arc->setClazz("consumption");
  arc->setSource("glyph5");
  arc->setTarget("glyph11a");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(510);
  point->setY(140);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(570);
  point->setY(140);

  arc = map->createArc();
  arc->setId("a05");
  arc->setClazz("consumption");
  arc->setSource("glyph6");
  arc->setTarget("glyph11a");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(540);
  point->setY(201);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(570);
  point->setY(140);

  arc = map->createArc();
  arc->setId("a06");
  arc->setClazz("production");
  arc->setSource("glyph9b");
  arc->setTarget("glyph3");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(180);
  point->setY(140);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(214);
  point->setY(203);

  arc = map->createArc();
  arc->setId("a07");
  arc->setClazz("production");
  arc->setSource("glyph9b");
  arc->setTarget("glyph4");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(180);
  point->setY(140);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(250);
  point->setY(140);

  arc = map->createArc();
  arc->setId("a08");
  arc->setClazz("production");
  arc->setSource("glyph10b");
  arc->setTarget("glyph5");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(390);
  point->setY(140);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(450);
  point->setY(140);

  arc = map->createArc();
  arc->setId("a09");
  arc->setClazz("production");
  arc->setSource("glyph11b");
  arc->setTarget("glyph7");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(610);
  point->setY(140);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(644);
  point->setY(203);

  arc = map->createArc();
  arc->setId("a10");
  arc->setClazz("production");
  arc->setSource("glyph11b");
  arc->setTarget("glyph8");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(610);
  point->setY(140);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(660);
  point->setY(140);


  writeSBGNToFile(doc, "out.sbgn");
                                  
  delete doc;                     
                                  
  return 0;                       
}                                 
