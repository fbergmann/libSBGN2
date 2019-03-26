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
  glyph->setClazz("macromolecule");

  label = glyph->createLabel();
  label->setText("Enzym1");

  bbox = glyph->createBBox();
  bbox->setX(56);
  bbox->setY(50);
  bbox->setWidth(108);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph2");
  glyph->setClazz("macromolecule");

  label = glyph->createLabel();
  label->setText("Enzym2");

  bbox = glyph->createBBox();
  bbox->setX(216);
  bbox->setY(50);
  bbox->setWidth(108);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph3");
  glyph->setClazz("or");
  glyph->setOrientation("vertical");

  bbox = glyph->createBBox();
  bbox->setX(169);
  bbox->setY(189);
  bbox->setWidth(42);
  bbox->setHeight(42);

  port = glyph->createPort();
  port->setId("port3.1");
  port->setX(190);
  port->setY(168);

  port = glyph->createPort();
  port->setId("port3.2");
  port->setX(190);
  port->setY(252);

  glyph = map->createGlyph();
  glyph->setId("glyph4");
  glyph->setClazz("process");
  glyph->setOrientation("horizontal");

  bbox = glyph->createBBox();
  bbox->setX(178);
  bbox->setY(278);
  bbox->setWidth(24);
  bbox->setHeight(24);

  port = glyph->createPort();
  port->setId("port4.1");
  port->setX(166);
  port->setY(290);

  port = glyph->createPort();
  port->setId("port4.2");
  port->setX(214);
  port->setY(290);

  glyph = map->createGlyph();
  glyph->setId("glyph5");
  glyph->setClazz("simple chemical");

  label = glyph->createLabel();
  label->setText("Subst");

  bbox = glyph->createBBox();
  bbox->setX(70);
  bbox->setY(260);
  bbox->setWidth(60);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph6");
  glyph->setClazz("simple chemical");

  label = glyph->createLabel();
  label->setText("Prod");

  bbox = glyph->createBBox();
  bbox->setX(260);
  bbox->setY(260);
  bbox->setWidth(60);
  bbox->setHeight(60);

  arc = map->createArc();
  arc->setId("a1");
  arc->setClazz("logic arc");
  arc->setSource("glyph1");
  arc->setTarget("port3.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(139);
  point->setY(110);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(190);
  point->setY(168);

  arc = map->createArc();
  arc->setId("a2");
  arc->setClazz("logic arc");
  arc->setSource("glyph2");
  arc->setTarget("port3.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(241);
  point->setY(110);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(190);
  point->setY(168);

  arc = map->createArc();
  arc->setId("a3");
  arc->setClazz("catalysis");
  arc->setSource("port3.2");
  arc->setTarget("glyph4");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(190);
  point->setY(252);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(190);
  point->setY(278);

  arc = map->createArc();
  arc->setId("a4");
  arc->setClazz("consumption");
  arc->setSource("glyph5");
  arc->setTarget("port4.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(130);
  point->setY(290);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(166);
  point->setY(290);

  arc = map->createArc();
  arc->setId("a5");
  arc->setClazz("production");
  arc->setSource("port4.2");
  arc->setTarget("glyph6");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(214);
  point->setY(290);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(260);
  point->setY(290);


    std::string outfile = "out.sbgn";
  if (argc > 1)
    outfile = argv[1];
  writeSBGNToFile(doc, outfile.c_str());
                                  
  delete doc;                     
                                  
  return 0;                       
}                                 
