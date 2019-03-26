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
  glyph->setId("d28f4");
  glyph->setClazz("compartment");
  glyph->setCompartmentOrder(65538);

  label = glyph->createLabel();
  label->setText("on top");

  bbox = glyph->createBBox();
  bbox->setX(21.5);
  bbox->setY(30);
  bbox->setWidth(118);
  bbox->setHeight(71);

  glyph = map->createGlyph();
  glyph->setId("e7e5f");
  glyph->setClazz("compartment");
  glyph->setCompartmentOrder(65537);

  label = glyph->createLabel();
  label->setText("in between");

  bbox = glyph->createBBox();
  bbox->setX(57.5);
  bbox->setY(80);
  bbox->setWidth(118);
  bbox->setHeight(71);

  glyph = map->createGlyph();
  glyph->setId("be96d");
  glyph->setClazz("compartment");
  glyph->setCompartmentOrder(65536);

  label = glyph->createLabel();
  label->setText("at the bottom");

  bbox = glyph->createBBox();
  bbox->setX(89);
  bbox->setY(130);
  bbox->setWidth(118);
  bbox->setHeight(71);


    std::string outfile = "out.sbgn";
  if (argc > 1)
    outfile = argv[1];
  writeSBGNToFile(doc, outfile.c_str());
                                  
  delete doc;                     
                                  
  return 0;                       
}                                 
