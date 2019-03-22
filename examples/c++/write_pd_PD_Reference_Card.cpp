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
  glyph->setId("glyph0");
  glyph->setClazz("compartment");
  glyph->setCompartmentOrder(-62);

  label = glyph->createLabel();
  label->setText("Connecting Arcs");

  bbox = label->createBBox();
  bbox->setX(1219);
  bbox->setY(54);
  bbox->setWidth(112);
  bbox->setHeight(18);

  bbox = glyph->createBBox();
  bbox->setX(1080);
  bbox->setY(50);
  bbox->setWidth(390);
  bbox->setHeight(850);

  glyph = map->createGlyph();
  glyph->setId("glyph1");
  glyph->setClazz("compartment");
  glyph->setCompartmentOrder(-61);

  label = glyph->createLabel();
  label->setText("Entity Pool Nodes (EPN)");

  bbox = label->createBBox();
  bbox->setX(144.5);
  bbox->setY(54);
  bbox->setWidth(161);
  bbox->setHeight(18);

  bbox = glyph->createBBox();
  bbox->setX(50);
  bbox->setY(50);
  bbox->setWidth(350);
  bbox->setHeight(850);

  glyph = map->createGlyph();
  glyph->setId("glyph2");
  glyph->setClazz("compartment");
  glyph->setCompartmentOrder(-60);

  label = glyph->createLabel();
  label->setText("Auxiliary Units");

  bbox = label->createBBox();
  bbox->setX(527);
  bbox->setY(54);
  bbox->setWidth(96);
  bbox->setHeight(18);

  bbox = glyph->createBBox();
  bbox->setX(420);
  bbox->setY(50);
  bbox->setWidth(310);
  bbox->setHeight(430);

  glyph = map->createGlyph();
  glyph->setId("glyph3");
  glyph->setClazz("compartment");
  glyph->setCompartmentOrder(-59);

  label = glyph->createLabel();
  label->setText("Process Nodes");

  bbox = label->createBBox();
  bbox->setX(853);
  bbox->setY(54);
  bbox->setWidth(104);
  bbox->setHeight(18);

  bbox = glyph->createBBox();
  bbox->setX(750);
  bbox->setY(50);
  bbox->setWidth(310);
  bbox->setHeight(430);

  glyph = map->createGlyph();
  glyph->setId("glyph4");
  glyph->setClazz("compartment");
  glyph->setCompartmentOrder(-58);

  label = glyph->createLabel();
  label->setText("Reference Nodes");

  bbox = label->createBBox();
  bbox->setX(680.5);
  bbox->setY(704);
  bbox->setWidth(119);
  bbox->setHeight(18);

  bbox = glyph->createBBox();
  bbox->setX(420);
  bbox->setY(700);
  bbox->setWidth(640);
  bbox->setHeight(200);

  glyph = map->createGlyph();
  glyph->setId("glyph5");
  glyph->setClazz("complex");
  glyph->setCompartmentRef("glyph1");

  label = glyph->createLabel();
  label->setText("Complex");

  bbox = label->createBBox();
  bbox->setX(193.5);
  bbox->setY(622);
  bbox->setWidth(63);
  bbox->setHeight(18);

  bbox = glyph->createBBox();
  bbox->setX(70);
  bbox->setY(620);
  bbox->setWidth(310);
  bbox->setHeight(240);

  auto* glyph_1 = glyph->createGlyph();
  glyph_1->setId("glyph5a");
  glyph_1->setClazz("unit of information");

  label = glyph_1->createLabel();
  label->setText("INFO");

  bbox = glyph_1->createBBox();
  bbox->setX(128);
  bbox->setY(852);
  bbox->setWidth(39);
  bbox->setHeight(16);

  auto* glyph_2 = glyph->createGlyph();
  glyph_2->setId("glyph5b");
  glyph_2->setClazz("state variable");

  bbox = glyph_2->createBBox();
  bbox->setX(205);
  bbox->setY(849);
  bbox->setWidth(40);
  bbox->setHeight(22);

  state = glyph_2->createState();
  state->setValue("varY");

  auto* glyph_3 = glyph->createGlyph();
  glyph_3->setId("glyph8");
  glyph_3->setClazz("complex");

  bbox = glyph_3->createBBox();
  bbox->setX(220);
  bbox->setY(650);
  bbox->setWidth(150);
  bbox->setHeight(180);

  auto* glyph_4 = glyph_3->createGlyph();
  glyph_4->setId("glyph8a");
  glyph_4->setClazz("state variable");

  bbox = glyph_4->createBBox();
  bbox->setX(275);
  bbox->setY(819);
  bbox->setWidth(40);
  bbox->setHeight(22);

  state = glyph_4->createState();
  state->setValue("varX");

  auto* glyph_5 = glyph_3->createGlyph();
  glyph_5->setId("glyph43");
  glyph_5->setClazz("simple chemical");

  label = glyph_5->createLabel();
  label->setText("LABEL");

  bbox = glyph_5->createBBox();
  bbox->setX(285);
  bbox->setY(745);
  bbox->setWidth(60);
  bbox->setHeight(60);

  auto* glyph_6 = glyph_3->createGlyph();
  glyph_6->setId("glyph33");
  glyph_6->setClazz("macromolecule");

  label = glyph_6->createLabel();
  label->setText("LABEL");

  bbox = glyph_6->createBBox();
  bbox->setX(241);
  bbox->setY(670);
  bbox->setWidth(108);
  bbox->setHeight(60);

  auto* glyph_7 = glyph_6->createGlyph();
  glyph_7->setId("glyph33a");
  glyph_7->setClazz("unit of information");

  label = glyph_7->createLabel();
  label->setText("INFO");

  bbox = glyph_7->createBBox();
  bbox->setX(248.5);
  bbox->setY(662);
  bbox->setWidth(39);
  bbox->setHeight(16);

  auto* glyph_8 = glyph_6->createGlyph();
  glyph_8->setId("glyph33b");
  glyph_8->setClazz("state variable");

  bbox = glyph_8->createBBox();
  bbox->setX(301);
  bbox->setY(659);
  bbox->setWidth(42);
  bbox->setHeight(22);

  state = glyph_8->createState();
  state->setValue("varW");

  auto* glyph_9 = glyph->createGlyph();
  glyph_9->setId("glyph30");
  glyph_9->setClazz("macromolecule");

  label = glyph_9->createLabel();
  label->setText("LABEL");

  bbox = glyph_9->createBBox();
  bbox->setX(91);
  bbox->setY(710);
  bbox->setWidth(108);
  bbox->setHeight(60);

  auto* glyph_10 = glyph_9->createGlyph();
  glyph_10->setId("glyph30a");
  glyph_10->setClazz("unit of information");

  label = glyph_10->createLabel();
  label->setText("INFO");

  bbox = glyph_10->createBBox();
  bbox->setX(98.5);
  bbox->setY(702);
  bbox->setWidth(39);
  bbox->setHeight(16);

  auto* glyph_11 = glyph_9->createGlyph();
  glyph_11->setId("glyph30b");
  glyph_11->setClazz("state variable");

  bbox = glyph_11->createBBox();
  bbox->setX(153.5);
  bbox->setY(699);
  bbox->setWidth(37);
  bbox->setHeight(22);

  state = glyph_11->createState();
  state->setValue("varZ");

  glyph = map->createGlyph();
  glyph->setId("glyph6");
  glyph->setClazz("compartment");
  glyph->setCompartmentOrder(-57);

  label = glyph->createLabel();
  label->setText("Logical Operators");

  bbox = label->createBBox();
  bbox->setX(844);
  bbox->setY(504);
  bbox->setWidth(122);
  bbox->setHeight(18);

  bbox = glyph->createBBox();
  bbox->setX(750);
  bbox->setY(500);
  bbox->setWidth(310);
  bbox->setHeight(180);

  glyph = map->createGlyph();
  glyph->setId("glyph7");
  glyph->setClazz("compartment");
  glyph->setCompartmentOrder(-56);

  label = glyph->createLabel();
  label->setText("Container Nodes (CN)");

  bbox = label->createBBox();
  bbox->setX(501);
  bbox->setY(504);
  bbox->setWidth(148);
  bbox->setHeight(18);

  bbox = glyph->createBBox();
  bbox->setX(420);
  bbox->setY(500);
  bbox->setWidth(310);
  bbox->setHeight(180);

  glyph = map->createGlyph();
  glyph->setId("glyph9");
  glyph->setClazz("compartment");
  glyph->setCompartmentOrder(-55);

  label = glyph->createLabel();
  label->setText("Compartment");

  bbox = label->createBBox();
  bbox->setX(528);
  bbox->setY(558);
  bbox->setWidth(94);
  bbox->setHeight(18);

  bbox = glyph->createBBox();
  bbox->setX(485);
  bbox->setY(550);
  bbox->setWidth(180);
  bbox->setHeight(100);

  auto* glyph_12 = glyph->createGlyph();
  glyph_12->setId("glyph9a");
  glyph_12->setClazz("unit of information");

  label = glyph_12->createLabel();
  label->setText("e:INFO");

  bbox = glyph_12->createBBox();
  bbox->setX(505);
  bbox->setY(541.5);
  bbox->setWidth(50);
  bbox->setHeight(17);

  glyph = map->createGlyph();
  glyph->setId("glyph10");
  glyph->setClazz("submap");

  label = glyph->createLabel();
  label->setText("Submap");

  bbox = glyph->createBBox();
  bbox->setX(585);
  bbox->setY(750);
  bbox->setWidth(160);
  bbox->setHeight(120);

  auto* glyph_13 = glyph->createGlyph();
  glyph_13->setId("glyph48");
  glyph_13->setClazz("terminal");
  glyph_13->setOrientation("right");

  label = glyph_13->createLabel();
  label->setText("A");

  bbox = glyph_13->createBBox();
  bbox->setX(585);
  bbox->setY(795);
  bbox->setWidth(50);
  bbox->setHeight(30);

  auto* glyph_14 = glyph->createGlyph();
  glyph_14->setId("glyph47");
  glyph_14->setClazz("terminal");
  glyph_14->setOrientation("left");

  label = glyph_14->createLabel();
  label->setText("B");

  bbox = glyph_14->createBBox();
  bbox->setX(695);
  bbox->setY(765);
  bbox->setWidth(50);
  bbox->setHeight(30);

  auto* glyph_15 = glyph->createGlyph();
  glyph_15->setId("glyph49");
  glyph_15->setClazz("terminal");
  glyph_15->setOrientation("left");

  label = glyph_15->createLabel();
  label->setText("C");

  bbox = glyph_15->createBBox();
  bbox->setX(695);
  bbox->setY(825);
  bbox->setWidth(50);
  bbox->setHeight(30);

  glyph = map->createGlyph();
  glyph->setId("glyph11");
  glyph->setClazz("macromolecule multimer");
  glyph->setCompartmentRef("glyph1");

  label = glyph->createLabel();
  label->setText("Multimer&#10;Macromolecule");

  bbox = glyph->createBBox();
  bbox->setX(82);
  bbox->setY(505);
  bbox->setWidth(126);
  bbox->setHeight(70);

  auto* glyph_16 = glyph->createGlyph();
  glyph_16->setId("glyph11a");
  glyph_16->setClazz("unit of information");

  label = glyph_16->createLabel();
  label->setText("N:5");

  bbox = glyph_16->createBBox();
  bbox->setX(98);
  bbox->setY(497);
  bbox->setWidth(31);
  bbox->setHeight(16);

  glyph = map->createGlyph();
  glyph->setId("glyph12");
  glyph->setClazz("nucleic acid feature multimer");
  glyph->setCompartmentRef("glyph1");

  label = glyph->createLabel();
  label->setText("Multimer&#10;Nucleic Acid&#10;Feature");

  bbox = glyph->createBBox();
  bbox->setX(242);
  bbox->setY(505);
  bbox->setWidth(126);
  bbox->setHeight(70);

  auto* glyph_17 = glyph->createGlyph();
  glyph_17->setId("glyph12a");
  glyph_17->setClazz("unit of information");

  label = glyph_17->createLabel();
  label->setText("N:2");

  bbox = glyph_17->createBBox();
  bbox->setX(258);
  bbox->setY(497);
  bbox->setWidth(31);
  bbox->setHeight(16);

  glyph = map->createGlyph();
  glyph->setId("glyph13");
  glyph->setClazz("complex multimer");
  glyph->setCompartmentRef("glyph1");

  label = glyph->createLabel();
  label->setText("Multimer&#10;Complex");

  bbox = label->createBBox();
  bbox->setX(113.5);
  bbox->setY(412.5);
  bbox->setWidth(63);
  bbox->setHeight(35);

  bbox = glyph->createBBox();
  bbox->setX(82);
  bbox->setY(395);
  bbox->setWidth(126);
  bbox->setHeight(70);

  auto* glyph_18 = glyph->createGlyph();
  glyph_18->setId("glyph13a");
  glyph_18->setClazz("unit of information");

  label = glyph_18->createLabel();
  label->setText("N:5");

  bbox = glyph_18->createBBox();
  bbox->setX(98);
  bbox->setY(387);
  bbox->setWidth(31);
  bbox->setHeight(16);

  glyph = map->createGlyph();
  glyph->setId("glyph14");
  glyph->setClazz("macromolecule");
  glyph->setCompartmentRef("glyph2");

  label = glyph->createLabel();
  label->setText("EPN with&#10;Clone Marker");

  bbox = glyph->createBBox();
  bbox->setX(512);
  bbox->setY(275);
  bbox->setWidth(126);
  bbox->setHeight(80);

  clone = glyph->createClone();

  glyph = map->createGlyph();
  glyph->setId("glyph15");
  glyph->setClazz("macromolecule");
  glyph->setCompartmentRef("glyph2");

  label = glyph->createLabel();
  label->setText("EPN with&#10;Clone Marker");

  bbox = glyph->createBBox();
  bbox->setX(512);
  bbox->setY(375);
  bbox->setWidth(126);
  bbox->setHeight(80);

  clone = glyph->createClone();

  label = clone->createLabel();
  label->setText("Clone Label");

  bbox = label->createBBox();
  bbox->setX(541.5);
  bbox->setY(439);
  bbox->setWidth(67);
  bbox->setHeight(14);

  glyph = map->createGlyph();
  glyph->setId("glyph16");
  glyph->setClazz("unspecified entity");
  glyph->setCompartmentRef("glyph1");

  label = glyph->createLabel();
  label->setText("Unspecified&#10;Entity");

  bbox = glyph->createBBox();
  bbox->setX(82);
  bbox->setY(95);
  bbox->setWidth(126);
  bbox->setHeight(70);

  glyph = map->createGlyph();
  glyph->setId("glyph17");
  glyph->setClazz("macromolecule");
  glyph->setCompartmentRef("glyph1");

  label = glyph->createLabel();
  label->setText("Macromolecule");

  bbox = glyph->createBBox();
  bbox->setX(82);
  bbox->setY(185);
  bbox->setWidth(126);
  bbox->setHeight(70);

  glyph = map->createGlyph();
  glyph->setId("glyph18");
  glyph->setClazz("nucleic acid feature");
  glyph->setCompartmentRef("glyph1");

  label = glyph->createLabel();
  label->setText("Nucleic Acid&#10;Feature");

  bbox = glyph->createBBox();
  bbox->setX(242);
  bbox->setY(185);
  bbox->setWidth(126);
  bbox->setHeight(70);

  glyph = map->createGlyph();
  glyph->setId("glyph19");
  glyph->setClazz("perturbing agent");
  glyph->setCompartmentRef("glyph1");

  label = glyph->createLabel();
  label->setText("Perturbing&#10;Agent");

  bbox = glyph->createBBox();
  bbox->setX(242);
  bbox->setY(275);
  bbox->setWidth(126);
  bbox->setHeight(70);

  glyph = map->createGlyph();
  glyph->setId("glyph20");
  glyph->setClazz("macromolecule");
  glyph->setCompartmentRef("glyph2");

  label = glyph->createLabel();
  label->setText("EPN with&#10;Unit of Information");

  bbox = glyph->createBBox();
  bbox->setX(515);
  bbox->setY(95);
  bbox->setWidth(120);
  bbox->setHeight(70);

  auto* glyph_19 = glyph->createGlyph();
  glyph_19->setId("glyph20a");
  glyph_19->setClazz("unit of information");

  label = glyph_19->createLabel();
  label->setText("pre:label");

  bbox = glyph_19->createBBox();
  bbox->setX(516.5);
  bbox->setY(87);
  bbox->setWidth(57);
  bbox->setHeight(16);

  glyph = map->createGlyph();
  glyph->setId("glyph26");
  glyph->setClazz("macromolecule");
  glyph->setCompartmentRef("glyph2");

  label = glyph->createLabel();
  label->setText("EPN with&#10;State Variable");

  bbox = glyph->createBBox();
  bbox->setX(515);
  bbox->setY(185);
  bbox->setWidth(120);
  bbox->setHeight(70);

  auto* glyph_20 = glyph->createGlyph();
  glyph_20->setId("glyph26a");
  glyph_20->setClazz("state variable");

  bbox = glyph_20->createBBox();
  bbox->setX(516.5);
  bbox->setY(173);
  bbox->setWidth(57);
  bbox->setHeight(24);

  state = glyph_20->createState();
  state->setVariable("var");
  state->setValue("val");

  glyph = map->createGlyph();
  glyph->setId("glyph27");
  glyph->setClazz("simple chemical multimer");
  glyph->setCompartmentRef("glyph1");

  label = glyph->createLabel();
  label->setText("Multimer&#10;Simple&#10;Chemical");

  bbox = glyph->createBBox();
  bbox->setX(270);
  bbox->setY(395);
  bbox->setWidth(70);
  bbox->setHeight(70);

  auto* glyph_21 = glyph->createGlyph();
  glyph_21->setId("glyph27a");
  glyph_21->setClazz("unit of information");

  label = glyph_21->createLabel();
  label->setText("N:2");

  bbox = glyph_21->createBBox();
  bbox->setX(272);
  bbox->setY(387);
  bbox->setWidth(31);
  bbox->setHeight(16);

  glyph = map->createGlyph();
  glyph->setId("glyph35");
  glyph->setClazz("phenotype");

  label = glyph->createLabel();
  label->setText("Phenotype");

  bbox = glyph->createBBox();
  bbox->setX(851);
  bbox->setY(360);
  bbox->setWidth(108);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph36");
  glyph->setClazz("tag");
  glyph->setOrientation("right");

  label = glyph->createLabel();
  label->setText("Tag");

  bbox = glyph->createBBox();
  bbox->setX(931);
  bbox->setY(780);
  bbox->setWidth(108);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph41");
  glyph->setClazz("source and sink");
  glyph->setCompartmentRef("glyph1");

  bbox = glyph->createBBox();
  bbox->setX(110);
  bbox->setY(275);
  bbox->setWidth(70);
  bbox->setHeight(70);

  glyph = map->createGlyph();
  glyph->setId("glyph42");
  glyph->setClazz("simple chemical");
  glyph->setCompartmentRef("glyph1");

  label = glyph->createLabel();
  label->setText("Simple&#10;Chemical");

  bbox = glyph->createBBox();
  bbox->setX(270);
  bbox->setY(95);
  bbox->setWidth(70);
  bbox->setHeight(70);

  glyph = map->createGlyph();
  glyph->setId("glyph44");
  glyph->setClazz("or");

  bbox = glyph->createBBox();
  bbox->setX(884);
  bbox->setY(569);
  bbox->setWidth(42);
  bbox->setHeight(42);

  glyph = map->createGlyph();
  glyph->setId("glyph45");
  glyph->setClazz("not");

  bbox = glyph->createBBox();
  bbox->setX(954);
  bbox->setY(569);
  bbox->setWidth(42);
  bbox->setHeight(42);

  glyph = map->createGlyph();
  glyph->setId("glyph46");
  glyph->setClazz("and");

  bbox = glyph->createBBox();
  bbox->setX(814);
  bbox->setY(569);
  bbox->setWidth(42);
  bbox->setHeight(42);

  glyph = map->createGlyph();
  glyph->setId("glyph54");
  glyph->setClazz("association");

  bbox = glyph->createBBox();
  bbox->setX(893);
  bbox->setY(268);
  bbox->setWidth(24);
  bbox->setHeight(24);

  glyph = map->createGlyph();
  glyph->setId("glyph55");
  glyph->setClazz("uncertain process");

  bbox = glyph->createBBox();
  bbox->setX(893);
  bbox->setY(218);
  bbox->setWidth(24);
  bbox->setHeight(24);

  glyph = map->createGlyph();
  glyph->setId("glyph56");
  glyph->setClazz("dissociation");

  bbox = glyph->createBBox();
  bbox->setX(893);
  bbox->setY(318);
  bbox->setWidth(24);
  bbox->setHeight(24);

  glyph = map->createGlyph();
  glyph->setId("glyph58");
  glyph->setClazz("process");

  bbox = glyph->createBBox();
  bbox->setX(893);
  bbox->setY(118);
  bbox->setWidth(24);
  bbox->setHeight(24);

  glyph = map->createGlyph();
  glyph->setId("glyph60");
  glyph->setClazz("omitted process");

  bbox = glyph->createBBox();
  bbox->setX(893);
  bbox->setY(168);
  bbox->setWidth(24);
  bbox->setHeight(24);

  glyph = map->createGlyph();
  glyph->setId("glyph40");
  glyph->setClazz("unspecified entity");
  glyph->setCompartmentRef("glyph4");

  label = glyph->createLabel();
  label->setText("EPN&#10;or CN");

  bbox = glyph->createBBox();
  bbox->setX(445);
  bbox->setY(785);
  bbox->setWidth(100);
  bbox->setHeight(50);

  glyph = map->createGlyph();
  glyph->setId("glyph38");
  glyph->setClazz("unspecified entity");
  glyph->setCompartmentRef("glyph4");

  label = glyph->createLabel();
  label->setText("EPN&#10;or CN");

  bbox = glyph->createBBox();
  bbox->setX(785);
  bbox->setY(750);
  bbox->setWidth(100);
  bbox->setHeight(50);

  glyph = map->createGlyph();
  glyph->setId("glyph39");
  glyph->setClazz("unspecified entity");
  glyph->setCompartmentRef("glyph4");

  label = glyph->createLabel();
  label->setText("EPN&#10;or CN");

  bbox = glyph->createBBox();
  bbox->setX(785);
  bbox->setY(820);
  bbox->setWidth(100);
  bbox->setHeight(50);

  glyph = map->createGlyph();
  glyph->setId("glyph37");
  glyph->setClazz("tag");
  glyph->setOrientation("right");

  label = glyph->createLabel();
  label->setText("LABEL");

  bbox = glyph->createBBox();
  bbox->setX(1121);
  bbox->setY(790);
  bbox->setWidth(108);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph29");
  glyph->setClazz("unspecified entity");
  glyph->setCompartmentRef("glyph0");

  label = glyph->createLabel();
  label->setText("EPN");

  bbox = glyph->createBBox();
  bbox->setX(1321);
  bbox->setY(790);
  bbox->setWidth(108);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph28");
  glyph->setClazz("unspecified entity");
  glyph->setCompartmentRef("glyph0");

  label = glyph->createLabel();
  label->setText("Source&#10;EPN");

  bbox = glyph->createBBox();
  bbox->setX(1121);
  bbox->setY(710);
  bbox->setWidth(108);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph32");
  glyph->setClazz("unspecified entity");
  glyph->setCompartmentRef("glyph0");

  label = glyph->createLabel();
  label->setText("Target&#10;Logical&#10;Operator");

  bbox = glyph->createBBox();
  bbox->setX(1321);
  bbox->setY(710);
  bbox->setWidth(108);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph22");
  glyph->setClazz("unspecified entity");
  glyph->setCompartmentRef("glyph0");

  label = glyph->createLabel();
  label->setText("Source&#10;EPN or&#10;Logical Operator");

  bbox = glyph->createBBox();
  bbox->setX(1115);
  bbox->setY(255);
  bbox->setWidth(120);
  bbox->setHeight(70);

  glyph = map->createGlyph();
  glyph->setId("glyph61");
  glyph->setClazz("process");

  bbox = glyph->createBBox();
  bbox->setX(1363);
  bbox->setY(278);
  bbox->setWidth(24);
  bbox->setHeight(24);

  glyph = map->createGlyph();
  glyph->setId("glyph21");
  glyph->setClazz("unspecified entity");
  glyph->setCompartmentRef("glyph0");

  label = glyph->createLabel();
  label->setText("Source&#10;EPN or&#10;Logical Operator");

  bbox = glyph->createBBox();
  bbox->setX(1115);
  bbox->setY(345);
  bbox->setWidth(120);
  bbox->setHeight(70);

  glyph = map->createGlyph();
  glyph->setId("glyph57");
  glyph->setClazz("process");

  bbox = glyph->createBBox();
  bbox->setX(1363);
  bbox->setY(368);
  bbox->setWidth(24);
  bbox->setHeight(24);

  glyph = map->createGlyph();
  glyph->setId("glyph23");
  glyph->setClazz("unspecified entity");
  glyph->setCompartmentRef("glyph0");

  label = glyph->createLabel();
  label->setText("Source&#10;EPN or&#10;Logical Operator");

  bbox = glyph->createBBox();
  bbox->setX(1115);
  bbox->setY(435);
  bbox->setWidth(120);
  bbox->setHeight(70);

  glyph = map->createGlyph();
  glyph->setId("glyph53");
  glyph->setClazz("process");

  bbox = glyph->createBBox();
  bbox->setX(1363);
  bbox->setY(458);
  bbox->setWidth(24);
  bbox->setHeight(24);

  glyph = map->createGlyph();
  glyph->setId("glyph25");
  glyph->setClazz("unspecified entity");
  glyph->setCompartmentRef("glyph0");

  label = glyph->createLabel();
  label->setText("Source&#10;EPN or&#10;Logical Operator");

  bbox = glyph->createBBox();
  bbox->setX(1115);
  bbox->setY(525);
  bbox->setWidth(120);
  bbox->setHeight(70);

  glyph = map->createGlyph();
  glyph->setId("glyph50");
  glyph->setClazz("process");

  bbox = glyph->createBBox();
  bbox->setX(1363);
  bbox->setY(548);
  bbox->setWidth(24);
  bbox->setHeight(24);

  glyph = map->createGlyph();
  glyph->setId("glyph24");
  glyph->setClazz("unspecified entity");
  glyph->setCompartmentRef("glyph0");

  label = glyph->createLabel();
  label->setText("Source&#10;EPN or&#10;Logical Operator");

  bbox = glyph->createBBox();
  bbox->setX(1115);
  bbox->setY(615);
  bbox->setWidth(120);
  bbox->setHeight(70);

  glyph = map->createGlyph();
  glyph->setId("glyph59");
  glyph->setClazz("process");

  bbox = glyph->createBBox();
  bbox->setX(1363);
  bbox->setY(638);
  bbox->setWidth(24);
  bbox->setHeight(24);

  glyph = map->createGlyph();
  glyph->setId("glyph51");
  glyph->setClazz("process");

  bbox = glyph->createBBox();
  bbox->setX(1163);
  bbox->setY(188);
  bbox->setWidth(24);
  bbox->setHeight(24);

  port = glyph->createPort();
  port->setId("glyph51.2");
  port->setX(1199);
  port->setY(200);

  glyph = map->createGlyph();
  glyph->setId("glyph31");
  glyph->setClazz("unspecified entity");
  glyph->setCompartmentRef("glyph0");

  label = glyph->createLabel();
  label->setText("Target&#10;EPN");

  bbox = glyph->createBBox();
  bbox->setX(1321);
  bbox->setY(170);
  bbox->setWidth(108);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph34");
  glyph->setClazz("unspecified entity");
  glyph->setCompartmentRef("glyph0");

  label = glyph->createLabel();
  label->setText("Source&#10;EPN");

  bbox = glyph->createBBox();
  bbox->setX(1121);
  bbox->setY(90);
  bbox->setWidth(108);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph52");
  glyph->setClazz("process");

  bbox = glyph->createBBox();
  bbox->setX(1363);
  bbox->setY(108);
  bbox->setWidth(24);
  bbox->setHeight(24);

  port = glyph->createPort();
  port->setId("glyph52.1");
  port->setX(1351);
  port->setY(120);

  arc = map->createArc();
  arc->setId("arc0");
  arc->setClazz("equivalence arc");
  arc->setSource("glyph40");
  arc->setTarget("glyph48");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(545);
  point->setY(810);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(585);
  point->setY(810);

  arc = map->createArc();
  arc->setId("arc1");
  arc->setClazz("equivalence arc");
  arc->setSource("glyph47");
  arc->setTarget("glyph38");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(745);
  point->setY(778.913);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(785);
  point->setY(777.174);

  arc = map->createArc();
  arc->setId("arc2");
  arc->setClazz("equivalence arc");
  arc->setSource("glyph49");
  arc->setTarget("glyph39");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(745);
  point->setY(841.087);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(785);
  point->setY(842.826);

  arc = map->createArc();
  arc->setId("arc3");
  arc->setClazz("equivalence arc");
  arc->setSource("glyph37");
  arc->setTarget("glyph29");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(1229);
  point->setY(820);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(1321);
  point->setY(820);

  arc = map->createArc();
  arc->setId("arc4");
  arc->setClazz("logic arc");
  arc->setSource("glyph28");
  arc->setTarget("glyph32");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(1229);
  point->setY(740);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(1321);
  point->setY(740);

  arc = map->createArc();
  arc->setId("arc5");
  arc->setClazz("modulation");
  arc->setSource("glyph22");
  arc->setTarget("glyph61");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(1235);
  point->setY(290);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(1363);
  point->setY(290);

  arc = map->createArc();
  arc->setId("arc6");
  arc->setClazz("stimulation");
  arc->setSource("glyph21");
  arc->setTarget("glyph57");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(1235);
  point->setY(380);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(1363);
  point->setY(380);

  arc = map->createArc();
  arc->setId("arc7");
  arc->setClazz("catalysis");
  arc->setSource("glyph23");
  arc->setTarget("glyph53");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(1235);
  point->setY(470);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(1363);
  point->setY(470);

  arc = map->createArc();
  arc->setId("arc8");
  arc->setClazz("inhibition");
  arc->setSource("glyph25");
  arc->setTarget("glyph50");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(1235);
  point->setY(560);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(1363);
  point->setY(560);

  arc = map->createArc();
  arc->setId("arc9");
  arc->setClazz("necessary stimulation");
  arc->setSource("glyph24");
  arc->setTarget("glyph59");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(1235);
  point->setY(650);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(1363);
  point->setY(650);

  arc = map->createArc();
  arc->setId("arc10");
  arc->setClazz("production");
  arc->setSource("glyph51.2");
  arc->setTarget("glyph31");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(1199);
  point->setY(200);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(1321);
  point->setY(200);

  auto* glyph_22 = arc->createGlyph();
  glyph_22->setId("glyph72");
  glyph_22->setClazz("cardinality");

  label = glyph_22->createLabel();
  label->setText("N");

  bbox = glyph_22->createBBox();
  bbox->setX(1251);
  bbox->setY(180);
  bbox->setWidth(24.5);
  bbox->setHeight(18.5);

  arc = map->createArc();
  arc->setId("arc11");
  arc->setClazz("consumption");
  arc->setSource("glyph34");
  arc->setTarget("glyph52.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(1229);
  point->setY(120);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(1351);
  point->setY(120);

  auto* glyph_23 = arc->createGlyph();
  glyph_23->setId("glyph73");
  glyph_23->setClazz("cardinality");

  label = glyph_23->createLabel();
  label->setText("N");

  bbox = glyph_23->createBBox();
  bbox->setX(1259);
  bbox->setY(101);
  bbox->setWidth(24.5);
  bbox->setHeight(18.5);


  writeSBGNToFile(doc, "out.sbgn");
                                  
  delete doc;                     
                                  
  return 0;                       
}                                 
