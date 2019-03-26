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
  label->setText("RAS");

  bbox = glyph->createBBox();
  bbox->setX(70);
  bbox->setY(70);
  bbox->setWidth(100);
  bbox->setHeight(60);

  auto* glyph_1 = glyph->createGlyph();
  glyph_1->setId("glyph4");
  glyph_1->setClazz("state variable");

  bbox = glyph_1->createBBox();
  bbox->setX(90);
  bbox->setY(110);
  bbox->setWidth(50);
  bbox->setHeight(30);

  state = glyph_1->createState();
  state->setValue("active");

  glyph = map->createGlyph();
  glyph->setId("glyph2");
  glyph->setClazz("submap");

  label = glyph->createLabel();
  label->setText("MAPK&#10;cascade");

  bbox = glyph->createBBox();
  bbox->setX(220);
  bbox->setY(40);
  bbox->setWidth(220);
  bbox->setHeight(120);

  auto* glyph_2 = glyph->createGlyph();
  glyph_2->setId("glyph5");
  glyph_2->setClazz("terminal");
  glyph_2->setOrientation("right");

  label = glyph_2->createLabel();
  label->setText("RAS");

  bbox = glyph_2->createBBox();
  bbox->setX(220);
  bbox->setY(77);
  bbox->setWidth(80);
  bbox->setHeight(45);

  auto* glyph_3 = glyph->createGlyph();
  glyph_3->setId("glyph6");
  glyph_3->setClazz("terminal");
  glyph_3->setOrientation("left");

  label = glyph_3->createLabel();
  label->setText("ERK");

  bbox = glyph_3->createBBox();
  bbox->setX(360);
  bbox->setY(77);
  bbox->setWidth(80);
  bbox->setHeight(45);

  glyph = map->createGlyph();
  glyph->setId("glyph3");
  glyph->setClazz("macromolecule");

  label = glyph->createLabel();
  label->setText("ERK");

  bbox = glyph->createBBox();
  bbox->setX(520);
  bbox->setY(70);
  bbox->setWidth(100);
  bbox->setHeight(60);

  auto* glyph_4 = glyph->createGlyph();
  glyph_4->setId("glyph7");
  glyph_4->setClazz("state variable");

  bbox = glyph_4->createBBox();
  bbox->setX(530);
  bbox->setY(120);
  bbox->setWidth(30);
  bbox->setHeight(20);

  state = glyph_4->createState();
  state->setValue("2P");

  arc = map->createArc();
  arc->setId("a1");
  arc->setClazz("equivalence arc");
  arc->setSource("glyph1");
  arc->setTarget("glyph5");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(170);
  point->setY(100);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(220);
  point->setY(100);

  arc = map->createArc();
  arc->setId("a2");
  arc->setClazz("equivalence arc");
  arc->setSource("glyph3");
  arc->setTarget("glyph6");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(520);
  point->setY(100);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(440);
  point->setY(100);


    std::string outfile = "out.sbgn";
  if (argc > 1)
    outfile = argv[1];
  writeSBGNToFile(doc, outfile.c_str());
                                  
  delete doc;                     
                                  
  return 0;                       
}                                 
