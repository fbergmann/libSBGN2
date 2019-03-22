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
  glyph->setClazz("simple chemical multimer");

  bbox = glyph->createBBox();
  bbox->setX(30);
  bbox->setY(20);
  bbox->setWidth(60);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph2");
  glyph->setClazz("macromolecule multimer");

  bbox = glyph->createBBox();
  bbox->setX(136);
  bbox->setY(20);
  bbox->setWidth(108);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph3");
  glyph->setClazz("nucleic acid feature multimer");

  bbox = glyph->createBBox();
  bbox->setX(286);
  bbox->setY(20);
  bbox->setWidth(108);
  bbox->setHeight(60);


  writeSBGNToFile(doc, "out.sbgn");
                                  
  delete doc;                     
                                  
  return 0;                       
}                                 
