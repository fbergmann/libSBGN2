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
  label->setText("LABEL");

  bbox = glyph->createBBox();
  bbox->setX(0);
  bbox->setY(20);
  bbox->setWidth(210);
  bbox->setHeight(120);

  clone = glyph->createClone();

  label = clone->createLabel();
  label->setText("marker");

  bbox = label->createBBox();
  bbox->setX(0);
  bbox->setY(100);
  bbox->setWidth(210);
  bbox->setHeight(40);

  auto* glyph_1 = glyph->createGlyph();
  glyph_1->setId("glyph10");
  glyph_1->setClazz("unit of information");

  label = glyph_1->createLabel();
  label->setText("INFO");

  bbox = glyph_1->createBBox();
  bbox->setX(20);
  bbox->setY(0);
  bbox->setWidth(60);
  bbox->setHeight(40);

  auto* glyph_2 = glyph->createGlyph();
  glyph_2->setId("glyph11");
  glyph_2->setClazz("state variable");

  bbox = glyph_2->createBBox();
  bbox->setX(100);
  bbox->setY(0);
  bbox->setWidth(60);
  bbox->setHeight(40);

  state = glyph_2->createState();
  state->setVariable("val");
  state->setValue("var");

  glyph = map->createGlyph();
  glyph->setId("glyph2");
  glyph->setClazz("nucleic acid feature");

  label = glyph->createLabel();
  label->setText("LABEL");

  bbox = glyph->createBBox();
  bbox->setX(220);
  bbox->setY(20);
  bbox->setWidth(210);
  bbox->setHeight(120);

  clone = glyph->createClone();

  label = clone->createLabel();
  label->setText("marker");

  bbox = label->createBBox();
  bbox->setX(220);
  bbox->setY(100);
  bbox->setWidth(210);
  bbox->setHeight(40);

  auto* glyph_3 = glyph->createGlyph();
  glyph_3->setId("glyph12");
  glyph_3->setClazz("unit of information");

  label = glyph_3->createLabel();
  label->setText("INFO");

  bbox = glyph_3->createBBox();
  bbox->setX(240);
  bbox->setY(0);
  bbox->setWidth(60);
  bbox->setHeight(40);

  auto* glyph_4 = glyph->createGlyph();
  glyph_4->setId("glyph13");
  glyph_4->setClazz("state variable");

  bbox = glyph_4->createBBox();
  bbox->setX(320);
  bbox->setY(0);
  bbox->setWidth(60);
  bbox->setHeight(40);

  state = glyph_4->createState();
  state->setVariable("val");
  state->setValue("var");

  glyph = map->createGlyph();
  glyph->setId("glyph3");
  glyph->setClazz("macromolecule multimer");

  label = glyph->createLabel();
  label->setText("LABEL");

  bbox = glyph->createBBox();
  bbox->setX(440);
  bbox->setY(20);
  bbox->setWidth(210);
  bbox->setHeight(120);

  clone = glyph->createClone();

  label = clone->createLabel();
  label->setText("marker");

  bbox = label->createBBox();
  bbox->setX(440);
  bbox->setY(100);
  bbox->setWidth(210);
  bbox->setHeight(40);

  auto* glyph_5 = glyph->createGlyph();
  glyph_5->setId("glyph14");
  glyph_5->setClazz("unit of information");

  label = glyph_5->createLabel();
  label->setText("N:5");

  bbox = glyph_5->createBBox();
  bbox->setX(460);
  bbox->setY(0);
  bbox->setWidth(60);
  bbox->setHeight(40);

  auto* glyph_6 = glyph->createGlyph();
  glyph_6->setId("glyph15");
  glyph_6->setClazz("state variable");

  bbox = glyph_6->createBBox();
  bbox->setX(540);
  bbox->setY(0);
  bbox->setWidth(60);
  bbox->setHeight(40);

  state = glyph_6->createState();
  state->setVariable("val");
  state->setValue("var");


  writeSBGNToFile(doc, "out.sbgn");
                                  
  delete doc;                     
                                  
  return 0;                       
}                                 
