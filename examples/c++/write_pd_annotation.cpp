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
  glyph->setId("g1");
  glyph->setClazz("macromolecule");

  label = glyph->createLabel();
  label->setText("LABEL");

  bbox = glyph->createBBox();
  bbox->setX(90);
  bbox->setY(160);
  bbox->setWidth(380);
  bbox->setHeight(210);

  glyph = map->createGlyph();
  glyph->setId("g2");
  glyph->setClazz("annotation");

  bbox = glyph->createBBox();
  bbox->setX(5);
  bbox->setY(5);
  bbox->setWidth(220);
  bbox->setHeight(125);

  co = glyph->createCallout();
  co->setTarget("g1");

  point = co->createPoint();
  point->setElementName("point");
  point->setX(160);
  point->setY(200);


    std::string outfile = "out.sbgn";
  if (argc > 1)
    outfile = argv[1];
  writeSBGNToFile(doc, outfile.c_str());
                                  
  delete doc;                     
                                  
  return 0;                       
}                                 
