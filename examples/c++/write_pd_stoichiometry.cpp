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
  label->setText("lactose");

  bbox = glyph->createBBox();
  bbox->setX(50);
  bbox->setY(50);
  bbox->setWidth(60);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph2");
  glyph->setClazz("simple chemical");

  label = glyph->createLabel();
  label->setText("galactose");

  bbox = glyph->createBBox();
  bbox->setX(250);
  bbox->setY(50);
  bbox->setWidth(60);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("pn1");
  glyph->setClazz("process");
  glyph->setOrientation("horizontal");

  bbox = glyph->createBBox();
  bbox->setX(170);
  bbox->setY(70);
  bbox->setWidth(20);
  bbox->setHeight(20);

  port = glyph->createPort();
  port->setId("pn1.1");
  port->setX(160);
  port->setY(80);

  port = glyph->createPort();
  port->setId("pn1.2");
  port->setX(200);
  port->setY(80);

  arc = map->createArc();
  arc->setId("a1");
  arc->setClazz("consumption");
  arc->setSource("glyph1");
  arc->setTarget("pn1.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(110);
  point->setY(80);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(160);
  point->setY(80);

  auto* glyph_1 = arc->createGlyph();
  glyph_1->setId("glyph10");
  glyph_1->setClazz("cardinality");

  label = glyph_1->createLabel();
  label->setText("2");

  bbox = glyph_1->createBBox();
  bbox->setX(140);
  bbox->setY(60);
  bbox->setWidth(20);
  bbox->setHeight(16);

  arc = map->createArc();
  arc->setId("a2");
  arc->setClazz("production");
  arc->setSource("pn1.2");
  arc->setTarget("glyph2");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(200);
  point->setY(80);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(250);
  point->setY(80);

  auto* glyph_2 = arc->createGlyph();
  glyph_2->setId("glyph11");
  glyph_2->setClazz("cardinality");

  label = glyph_2->createLabel();
  label->setText("1");

  bbox = glyph_2->createBBox();
  bbox->setX(200);
  bbox->setY(60);
  bbox->setWidth(20);
  bbox->setHeight(16);


    std::string outfile = "out.sbgn";
  if (argc > 1)
    outfile = argv[1];
  writeSBGNToFile(doc, outfile.c_str());
                                  
  delete doc;                     
                                  
  return 0;                       
}                                 
