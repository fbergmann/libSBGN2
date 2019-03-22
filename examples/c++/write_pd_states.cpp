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
  glyph->setClazz("tag");
  glyph->setOrientation("right");

  label = glyph->createLabel();
  label->setText("RAS");

  bbox = glyph->createBBox();
  bbox->setX(100);
  bbox->setY(20);
  bbox->setWidth(100);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph2");
  glyph->setClazz("macromolecule");

  label = glyph->createLabel();
  label->setText("RAS");

  bbox = glyph->createBBox();
  bbox->setX(270);
  bbox->setY(20);
  bbox->setWidth(100);
  bbox->setHeight(60);

  auto* glyph_1 = glyph->createGlyph();
  glyph_1->setId("glyph2a");
  glyph_1->setClazz("state variable");

  bbox = glyph_1->createBBox();
  bbox->setX(304);
  bbox->setY(74);
  bbox->setWidth(32);
  bbox->setHeight(12);

  state = glyph_1->createState();
  state->setValue("active");

  glyph = map->createGlyph();
  glyph->setId("glyph3");
  glyph->setClazz("macromolecule");

  label = glyph->createLabel();
  label->setText("RAF");

  bbox = glyph->createBBox();
  bbox->setX(120);
  bbox->setY(150);
  bbox->setWidth(100);
  bbox->setHeight(60);

  auto* glyph_2 = glyph->createGlyph();
  glyph_2->setId("glyph3a");
  glyph_2->setClazz("state variable");

  bbox = glyph_2->createBBox();
  bbox->setX(164);
  bbox->setY(204);
  bbox->setWidth(12);
  bbox->setHeight(12);

  glyph = map->createGlyph();
  glyph->setId("glyph4");
  glyph->setClazz("macromolecule");

  label = glyph->createLabel();
  label->setText("RAF");

  bbox = glyph->createBBox();
  bbox->setX(400);
  bbox->setY(150);
  bbox->setWidth(100);
  bbox->setHeight(60);

  auto* glyph_3 = glyph->createGlyph();
  glyph_3->setId("glyph4a");
  glyph_3->setClazz("state variable");

  bbox = glyph_3->createBBox();
  bbox->setX(444);
  bbox->setY(204);
  bbox->setWidth(12);
  bbox->setHeight(12);

  state = glyph_3->createState();
  state->setValue("P");

  glyph = map->createGlyph();
  glyph->setId("glyph5");
  glyph->setClazz("process");

  bbox = glyph->createBBox();
  bbox->setX(308);
  bbox->setY(168);
  bbox->setWidth(24);
  bbox->setHeight(24);

  port = glyph->createPort();
  port->setId("glyph5a");
  port->setX(296);
  port->setY(180);

  port = glyph->createPort();
  port->setId("glyph5b");
  port->setX(344);
  port->setY(180);

  arc = map->createArc();
  arc->setId("a1");
  arc->setClazz("equivalence arc");
  arc->setSource("glyph2");
  arc->setTarget("glyph1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(270);
  point->setY(50);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(200);
  point->setY(50);

  arc = map->createArc();
  arc->setId("a2");
  arc->setClazz("catalysis");
  arc->setSource("glyph2");
  arc->setTarget("glyph5");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(320);
  point->setY(86);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(320);
  point->setY(168);

  arc = map->createArc();
  arc->setId("a3");
  arc->setClazz("consumption");
  arc->setSource("glyph3");
  arc->setTarget("glyph5a");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(220);
  point->setY(180);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(296);
  point->setY(180);

  arc = map->createArc();
  arc->setId("a4");
  arc->setClazz("production");
  arc->setSource("glyph5b");
  arc->setTarget("glyph4");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(344);
  point->setY(180);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(400);
  point->setY(180);


  writeSBGNToFile(doc, "out.sbgn");
                                  
  delete doc;                     
                                  
  return 0;                       
}                                 
