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
  label->setText("X");

  bbox = glyph->createBBox();
  bbox->setX(42);
  bbox->setY(17);
  bbox->setWidth(60);
  bbox->setHeight(100);

  auto* glyph_1 = glyph->createGlyph();
  glyph_1->setId("glyph1_1");
  glyph_1->setClazz("state variable");

  bbox = glyph_1->createBBox();
  bbox->setX(17);
  bbox->setY(41);
  bbox->setWidth(50);
  bbox->setHeight(25);

  state = glyph_1->createState();
  state->setVariable("122");
  state->setValue("P");

  auto* glyph_2 = glyph->createGlyph();
  glyph_2->setId("glyph1_2");
  glyph_2->setClazz("state variable");

  bbox = glyph_2->createBBox();
  bbox->setX(76);
  bbox->setY(41);
  bbox->setWidth(50);
  bbox->setHeight(25);

  state = glyph_2->createState();
  state->setVariable("257");
  state->setValue("P");

  auto* glyph_3 = glyph->createGlyph();
  glyph_3->setId("glyph1_3");
  glyph_3->setClazz("state variable");

  bbox = glyph_3->createBBox();
  bbox->setX(17);
  bbox->setY(78);
  bbox->setWidth(50);
  bbox->setHeight(25);

  state = glyph_3->createState();
  state->setVariable("312");
  state->setValue("P");

  auto* glyph_4 = glyph->createGlyph();
  glyph_4->setId("glyph1_4");
  glyph_4->setClazz("state variable");

  bbox = glyph_4->createBBox();
  bbox->setX(76);
  bbox->setY(78);
  bbox->setWidth(50);
  bbox->setHeight(25);

  state = glyph_4->createState();
  state->setVariable("438");
  state->setValue("P");


  writeSBGNToFile(doc, "out.sbgn");
                                  
  delete doc;                     
                                  
  return 0;                       
}                                 
