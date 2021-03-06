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
  glyph->setClazz("simple chemical");

  label = glyph->createLabel();
  label->setText("Ethanol");

  bbox = glyph->createBBox();
  bbox->setX(90);
  bbox->setY(240);
  bbox->setWidth(60);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph2");
  glyph->setClazz("simple chemical");

  label = glyph->createLabel();
  label->setText("NADH");

  bbox = glyph->createBBox();
  bbox->setX(290);
  bbox->setY(150);
  bbox->setWidth(60);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph3");
  glyph->setClazz("macromolecule");

  label = glyph->createLabel();
  label->setText("ADH1");

  bbox = glyph->createBBox();
  bbox->setX(196);
  bbox->setY(80);
  bbox->setWidth(108);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("pn1");
  glyph->setClazz("process");
  glyph->setOrientation("horizontal");

  bbox = glyph->createBBox();
  bbox->setX(148);
  bbox->setY(168);
  bbox->setWidth(24);
  bbox->setHeight(24);

  port = glyph->createPort();
  port->setId("pn1.1");
  port->setX(136);
  port->setY(180);

  port = glyph->createPort();
  port->setId("pn1.2");
  port->setX(184);
  port->setY(180);

  arc = map->createArc();
  arc->setId("a01");
  arc->setClazz("consumption");
  arc->setSource("glyph1");
  arc->setTarget("pn1.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(90);
  point->setY(270);

  point = arc->createNext();
  point->setElementName("next");
  point->setX(70);
  point->setY(270);

  point = arc->createNext();
  point->setElementName("next");
  point->setX(70);
  point->setY(180);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(136);
  point->setY(180);

  arc = map->createArc();
  arc->setId("a02");
  arc->setClazz("catalysis");
  arc->setSource("glyph3");
  arc->setTarget("pn1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(250);
  point->setY(80);

  point = arc->createNext();
  point->setElementName("next");
  point->setX(250);
  point->setY(50);

  point = arc->createNext();
  point->setElementName("next");
  point->setX(160);
  point->setY(50);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(160);
  point->setY(168);

  arc = map->createArc();
  arc->setId("a03");
  arc->setClazz("production");
  arc->setSource("pn1.2");
  arc->setTarget("glyph2");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(184);
  point->setY(180);

  point = arc->createNext();
  point->setElementName("next");
  point->setX(190);
  point->setY(180);

  point = arc->createNext();
  point->setElementName("next");
  point->setX(190);
  point->setY(240);

  point = arc->createNext();
  point->setElementName("next");
  point->setX(240);
  point->setY(240);

  point = arc->createNext();
  point->setElementName("next");
  point->setX(240);
  point->setY(180);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(290);
  point->setY(180);


    std::string outfile = "out.sbgn";
  if (argc > 1)
    outfile = argv[1];
  writeSBGNToFile(doc, outfile.c_str());
                                  
  delete doc;                     
                                  
  return 0;                       
}                                 
