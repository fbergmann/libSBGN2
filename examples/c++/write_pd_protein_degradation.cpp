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
  glyph->setClazz("source and sink");

  bbox = glyph->createBBox();
  bbox->setX(270);
  bbox->setY(50);
  bbox->setWidth(60);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph2");
  glyph->setClazz("omitted process");
  glyph->setOrientation("horizontal");

  bbox = glyph->createBBox();
  bbox->setX(188);
  bbox->setY(68);
  bbox->setWidth(24);
  bbox->setHeight(24);

  port = glyph->createPort();
  port->setId("glyph2.1");
  port->setX(176);
  port->setY(80);

  port = glyph->createPort();
  port->setId("glyph2.2");
  port->setX(224);
  port->setY(80);

  glyph = map->createGlyph();
  glyph->setId("glyph3");
  glyph->setClazz("macromolecule");

  label = glyph->createLabel();
  label->setText("Protein");

  bbox = glyph->createBBox();
  bbox->setX(16);
  bbox->setY(50);
  bbox->setWidth(108);
  bbox->setHeight(60);

  arc = map->createArc();
  arc->setId("a1");
  arc->setClazz("production");
  arc->setSource("glyph2.2");
  arc->setTarget("glyph1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(224);
  point->setY(80);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(270);
  point->setY(80);

  arc = map->createArc();
  arc->setId("a2");
  arc->setClazz("consumption");
  arc->setSource("glyph3");
  arc->setTarget("glyph2.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(124);
  point->setY(80);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(176);
  point->setY(80);


  writeSBGNToFile(doc, "out.sbgn");
                                  
  delete doc;                     
                                  
  return 0;                       
}                                 
