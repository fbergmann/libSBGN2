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
  glyph->setClazz("compartment");

  label = glyph->createLabel();
  label->setText("extracellular");

  bbox = glyph->createBBox();
  bbox->setX(90);
  bbox->setY(70);
  bbox->setWidth(440);
  bbox->setHeight(140);

  glyph = map->createGlyph();
  glyph->setId("glyph8");
  glyph->setClazz("compartment");

  label = glyph->createLabel();
  label->setText("cytosol");

  bbox = glyph->createBBox();
  bbox->setX(90);
  bbox->setY(230);
  bbox->setWidth(440);
  bbox->setHeight(260);

  glyph = map->createGlyph();
  glyph->setId("glyph2");
  glyph->setClazz("complex");
  glyph->setCompartmentRef("glyph1");

  bbox = glyph->createBBox();
  bbox->setX(360);
  bbox->setY(150);
  bbox->setWidth(140);
  bbox->setHeight(160);

  auto* glyph_1 = glyph->createGlyph();
  glyph_1->setId("glyph3");
  glyph_1->setClazz("macromolecule");

  label = glyph_1->createLabel();
  label->setText("IGF");

  bbox = glyph_1->createBBox();
  bbox->setX(380);
  bbox->setY(171);
  bbox->setWidth(100);
  bbox->setHeight(60);

  auto* glyph_2 = glyph->createGlyph();
  glyph_2->setId("glyph6");
  glyph_2->setClazz("macromolecule");

  label = glyph_2->createLabel();
  label->setText("IGFR");

  bbox = glyph_2->createBBox();
  bbox->setX(380);
  bbox->setY(232);
  bbox->setWidth(100);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph4");
  glyph->setClazz("macromolecule");
  glyph->setCompartmentRef("glyph8");

  label = glyph->createLabel();
  label->setText("IGFR");

  bbox = glyph->createBBox();
  bbox->setX(120);
  bbox->setY(250);
  bbox->setWidth(100);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph5");
  glyph->setClazz("macromolecule");
  glyph->setCompartmentRef("glyph1");

  label = glyph->createLabel();
  label->setText("IGF");

  bbox = glyph->createBBox();
  bbox->setX(170);
  bbox->setY(130);
  bbox->setWidth(100);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("pn1");
  glyph->setClazz("association");

  bbox = glyph->createBBox();
  bbox->setX(280);
  bbox->setY(270);
  bbox->setWidth(20);
  bbox->setHeight(20);

  port = glyph->createPort();
  port->setId("pn1.1");
  port->setX(270);
  port->setY(280);

  port = glyph->createPort();
  port->setId("pn1.2");
  port->setX(310);
  port->setY(280);

  arc = map->createArc();
  arc->setId("a01");
  arc->setClazz("production");
  arc->setSource("pn1.2");
  arc->setTarget("glyph2");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(310);
  point->setY(280);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(360);
  point->setY(280);

  arc = map->createArc();
  arc->setId("a02");
  arc->setClazz("consumption");
  arc->setSource("glyph4");
  arc->setTarget("pn1.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(220);
  point->setY(280);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(270);
  point->setY(280);

  arc = map->createArc();
  arc->setId("a03");
  arc->setClazz("consumption");
  arc->setSource("glyph5");
  arc->setTarget("pn1.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(233);
  point->setY(190);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(270);
  point->setY(280);


    std::string outfile = "out.sbgn";
  if (argc > 1)
    outfile = argv[1];
  writeSBGNToFile(doc, outfile.c_str());
                                  
  delete doc;                     
                                  
  return 0;                       
}                                 
