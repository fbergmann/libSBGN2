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

  bbox = map->createBBox();
  bbox->setX(0);
  bbox->setY(0);
  bbox->setWidth(363);
  bbox->setHeight(253);

  glyph = map->createGlyph();
  glyph->setId("glyph1");
  glyph->setClazz("simple chemical");

  label = glyph->createLabel();
  label->setText("Ethanol");

  bbox = glyph->createBBox();
  bbox->setX(40);
  bbox->setY(120);
  bbox->setWidth(60);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph_ethanal");
  glyph->setClazz("simple chemical");

  label = glyph->createLabel();
  label->setText("Ethanal");

  bbox = glyph->createBBox();
  bbox->setX(220);
  bbox->setY(110);
  bbox->setWidth(60);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph_adh1");
  glyph->setClazz("macromolecule");

  label = glyph->createLabel();
  label->setText("ADH1");

  bbox = glyph->createBBox();
  bbox->setX(106);
  bbox->setY(20);
  bbox->setWidth(108);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph_h");
  glyph->setClazz("simple chemical");

  label = glyph->createLabel();
  label->setText("H+");

  bbox = glyph->createBBox();
  bbox->setX(220);
  bbox->setY(190);
  bbox->setWidth(60);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph_nad");
  glyph->setClazz("simple chemical");

  label = glyph->createLabel();
  label->setText("NAD+");

  bbox = glyph->createBBox();
  bbox->setX(40);
  bbox->setY(190);
  bbox->setWidth(60);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph_nadh");
  glyph->setClazz("simple chemical");

  label = glyph->createLabel();
  label->setText("NADH");

  bbox = glyph->createBBox();
  bbox->setX(300);
  bbox->setY(150);
  bbox->setWidth(60);
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
  point->setX(98);
  point->setY(160);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(136);
  point->setY(180);

  arc = map->createArc();
  arc->setId("a02");
  arc->setClazz("production");
  arc->setSource("pn1.2");
  arc->setTarget("glyph_nadh");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(184);
  point->setY(180);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(300);
  point->setY(180);

  arc = map->createArc();
  arc->setId("a03");
  arc->setClazz("catalysis");
  arc->setSource("glyph_adh1");
  arc->setTarget("pn1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(160);
  point->setY(80);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(160);
  point->setY(168);

  arc = map->createArc();
  arc->setId("a04");
  arc->setClazz("production");
  arc->setSource("pn1.2");
  arc->setTarget("glyph_h");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(184);
  point->setY(180);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(224);
  point->setY(202);

  arc = map->createArc();
  arc->setId("a05");
  arc->setClazz("production");
  arc->setSource("pn1.2");
  arc->setTarget("glyph_ethanal");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(184);
  point->setY(180);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(224);
  point->setY(154);

  arc = map->createArc();
  arc->setId("a06");
  arc->setClazz("consumption");
  arc->setSource("glyph_nad");
  arc->setTarget("pn1.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(95);
  point->setY(202);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(136);
  point->setY(180);


    std::string outfile = "out.sbgn";
  if (argc > 1)
    outfile = argv[1];
  writeSBGNToFile(doc, outfile.c_str());
                                  
  delete doc;                     
                                  
  return 0;                       
}                                 
