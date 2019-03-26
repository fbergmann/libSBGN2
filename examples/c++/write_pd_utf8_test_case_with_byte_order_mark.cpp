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
  glyph->setClazz("macromolecule");

  label = glyph->createLabel();
  label->setText("greek letter alpha: α");

  bbox = glyph->createBBox();
  bbox->setX(20);
  bbox->setY(20);
  bbox->setWidth(140);
  bbox->setHeight(60);


    std::string outfile = "out.sbgn";
  if (argc > 1)
    outfile = argv[1];
  writeSBGNToFile(doc, outfile.c_str());
                                  
  delete doc;                     
                                  
  return 0;                       
}                                 
