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
  map->setMetaId("map2");
  map->setLanguage("process description");

  glyph = map->createGlyph();
  glyph->setId("glyph4");
  glyph->setClazz("tag");
  glyph->setOrientation("left");

  label = glyph->createLabel();
  label->setText("ERK");

  bbox = glyph->createBBox();
  bbox->setX(520);
  bbox->setY(130);
  bbox->setWidth(100);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph1");
  glyph->setClazz("macromolecule");

  label = glyph->createLabel();
  label->setText("RAS");

  bbox = glyph->createBBox();
  bbox->setX(200);
  bbox->setY(20);
  bbox->setWidth(100);
  bbox->setHeight(60);

  auto* glyph_1 = glyph->createGlyph();
  glyph_1->setId("glyph1a");
  glyph_1->setClazz("state variable");

  bbox = glyph_1->createBBox();
  bbox->setX(225);
  bbox->setY(67);
  bbox->setWidth(50);
  bbox->setHeight(26);

  state = glyph_1->createState();
  state->setValue("active");

  glyph = map->createGlyph();
  glyph->setId("glyph3");
  glyph->setClazz("tag");
  glyph->setOrientation("right");

  label = glyph->createLabel();
  label->setText("RAS");

  bbox = glyph->createBBox();
  bbox->setX(30);
  bbox->setY(20);
  bbox->setWidth(100);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph5");
  glyph->setClazz("source and sink");

  bbox = glyph->createBBox();
  bbox->setX(90);
  bbox->setY(130);
  bbox->setWidth(60);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph6");
  glyph->setClazz("omitted process");

  bbox = glyph->createBBox();
  bbox->setX(240);
  bbox->setY(150);
  bbox->setWidth(20);
  bbox->setHeight(20);

  port = glyph->createPort();
  port->setId("glyph6.1");
  port->setX(230);
  port->setY(160);

  port = glyph->createPort();
  port->setId("glyph6.2");
  port->setX(270);
  port->setY(160);

  glyph = map->createGlyph();
  glyph->setId("glyph2");
  glyph->setClazz("macromolecule");

  label = glyph->createLabel();
  label->setText("ERK");

  bbox = glyph->createBBox();
  bbox->setX(350);
  bbox->setY(130);
  bbox->setWidth(100);
  bbox->setHeight(60);

  auto* glyph_2 = glyph->createGlyph();
  glyph_2->setId("glyph2a");
  glyph_2->setClazz("state variable");

  bbox = glyph_2->createBBox();
  bbox->setX(359);
  bbox->setY(179);
  bbox->setWidth(32);
  bbox->setHeight(22);

  state = glyph_2->createState();
  state->setValue("2P");

  arc = map->createArc();
  arc->setId("arc1");
  arc->setClazz("catalysis");
  arc->setSource("glyph1");
  arc->setTarget("glyph6");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(250);
  point->setY(92);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(250);
  point->setY(150);

  arc = map->createArc();
  arc->setId("arc2");
  arc->setClazz("equivalence arc");
  arc->setSource("glyph2");
  arc->setTarget("glyph4");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(450);
  point->setY(160);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(520);
  point->setY(160);

  arc = map->createArc();
  arc->setId("arc3");
  arc->setClazz("equivalence arc");
  arc->setSource("glyph1");
  arc->setTarget("glyph3");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(200);
  point->setY(50);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(130);
  point->setY(50);

  arc = map->createArc();
  arc->setId("arc4");
  arc->setClazz("consumption");
  arc->setSource("glyph5");
  arc->setTarget("glyph6.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(150);
  point->setY(160);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(230);
  point->setY(160);

  arc = map->createArc();
  arc->setId("arc5");
  arc->setClazz("production");
  arc->setSource("glyph6.2");
  arc->setTarget("glyph2");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(270);
  point->setY(160);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(350);
  point->setY(160);


    std::string outfile = "out.sbgn";
  if (argc > 1)
    outfile = argv[1];
  writeSBGNToFile(doc, outfile.c_str());
                                  
  delete doc;                     
                                  
  return 0;                       
}                                 
