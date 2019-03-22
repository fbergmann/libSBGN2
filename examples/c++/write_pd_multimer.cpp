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
  label->setText("Monomer");

  bbox = glyph->createBBox();
  bbox->setX(326);
  bbox->setY(30);
  bbox->setWidth(108);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph2");
  glyph->setClazz("macromolecule multimer");

  label = glyph->createLabel();
  label->setText("Dimer");

  bbox = glyph->createBBox();
  bbox->setX(116);
  bbox->setY(30);
  bbox->setWidth(108);
  bbox->setHeight(60);

  auto* glyph_1 = glyph->createGlyph();
  glyph_1->setId("glyph2a");
  glyph_1->setClazz("unit of information");

  label = glyph_1->createLabel();
  label->setText("N:2");

  bbox = glyph_1->createBBox();
  bbox->setX(130);
  bbox->setY(24);
  bbox->setWidth(32);
  bbox->setHeight(12);

  glyph = map->createGlyph();
  glyph->setId("pn1");
  glyph->setClazz("process");
  glyph->setOrientation("horizontal");

  bbox = glyph->createBBox();
  bbox->setX(268);
  bbox->setY(48);
  bbox->setWidth(24);
  bbox->setHeight(24);

  port = glyph->createPort();
  port->setId("pn1.1");
  port->setX(256);
  port->setY(60);

  port = glyph->createPort();
  port->setId("pn1.2");
  port->setX(304);
  port->setY(60);

  arc = map->createArc();
  arc->setId("a1");
  arc->setClazz("consumption");
  arc->setSource("glyph1");
  arc->setTarget("pn1.2");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(326);
  point->setY(60);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(304);
  point->setY(60);

  arc = map->createArc();
  arc->setId("a2");
  arc->setClazz("production");
  arc->setSource("pn1.1");
  arc->setTarget("glyph2");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(256);
  point->setY(60);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(226);
  point->setY(60);


  writeSBGNToFile(doc, "out.sbgn");
                                  
  delete doc;                     
                                  
  return 0;                       
}                                 
