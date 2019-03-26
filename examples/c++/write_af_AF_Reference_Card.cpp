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
  SbgnArcGroup* arcGroup = NULL;
  SbgnBBox*  bbox = NULL;
  SbgnPoint* point = NULL;
  SbgnPort*  port= NULL;

  auto* map = doc->createMap();
  map->setId("map1");
  map->setLanguage("activity flow");

  glyph = map->createGlyph();
  glyph->setId("glyph0");
  glyph->setClazz("compartment");
  glyph->setCompartmentOrder(-39);

  label = glyph->createLabel();
  label->setText("Connecting Arcs");

  bbox = label->createBBox();
  bbox->setX(484);
  bbox->setY(54);
  bbox->setWidth(112);
  bbox->setHeight(18);

  bbox = glyph->createBBox();
  bbox->setX(330);
  bbox->setY(50);
  bbox->setWidth(420);
  bbox->setHeight(600);

  glyph = map->createGlyph();
  glyph->setId("glyph1");
  glyph->setClazz("compartment");
  glyph->setCompartmentOrder(-38);

  label = glyph->createLabel();
  label->setText("Auxiliary Units");

  bbox = label->createBBox();
  bbox->setX(872);
  bbox->setY(54);
  bbox->setWidth(96);
  bbox->setHeight(18);

  bbox = glyph->createBBox();
  bbox->setX(770);
  bbox->setY(50);
  bbox->setWidth(300);
  bbox->setHeight(600);

  glyph = map->createGlyph();
  glyph->setId("glyph2");
  glyph->setClazz("compartment");
  glyph->setCompartmentOrder(-37);

  label = glyph->createLabel();
  label->setText("Reference Nodes");

  bbox = label->createBBox();
  bbox->setX(340.5);
  bbox->setY(674);
  bbox->setWidth(119);
  bbox->setHeight(18);

  bbox = glyph->createBBox();
  bbox->setX(50);
  bbox->setY(670);
  bbox->setWidth(700);
  bbox->setHeight(200);

  glyph = map->createGlyph();
  glyph->setId("glyph3");
  glyph->setClazz("compartment");
  glyph->setCompartmentOrder(-36);

  label = glyph->createLabel();
  label->setText("Activity Nodes (AN)");

  bbox = label->createBBox();
  bbox->setX(115.5);
  bbox->setY(54);
  bbox->setWidth(129);
  bbox->setHeight(18);

  bbox = glyph->createBBox();
  bbox->setX(50);
  bbox->setY(50);
  bbox->setWidth(260);
  bbox->setHeight(360);

  glyph = map->createGlyph();
  glyph->setId("glyph4");
  glyph->setClazz("compartment");
  glyph->setCompartmentOrder(-35);

  label = glyph->createLabel();
  label->setText("Container Node (CN)");

  bbox = label->createBBox();
  bbox->setX(849.5);
  bbox->setY(674);
  bbox->setWidth(141);
  bbox->setHeight(18);

  bbox = glyph->createBBox();
  bbox->setX(770);
  bbox->setY(670);
  bbox->setWidth(300);
  bbox->setHeight(200);

  glyph = map->createGlyph();
  glyph->setId("glyph5");
  glyph->setClazz("compartment");
  glyph->setCompartmentOrder(-34);

  label = glyph->createLabel();
  label->setText("Logical Operators");

  bbox = label->createBBox();
  bbox->setX(119);
  bbox->setY(434);
  bbox->setWidth(122);
  bbox->setHeight(18);

  bbox = glyph->createBBox();
  bbox->setX(50);
  bbox->setY(430);
  bbox->setWidth(260);
  bbox->setHeight(220);

  glyph = map->createGlyph();
  glyph->setId("glyph6");
  glyph->setClazz("compartment");
  glyph->setCompartmentOrder(-33);

  label = glyph->createLabel();
  label->setText("Compartment");

  bbox = label->createBBox();
  bbox->setX(873);
  bbox->setY(738);
  bbox->setWidth(94);
  bbox->setHeight(18);

  bbox = glyph->createBBox();
  bbox->setX(830);
  bbox->setY(730);
  bbox->setWidth(180);
  bbox->setHeight(100);

  auto* glyph_1 = glyph->createGlyph();
  glyph_1->setId("glyph6a");
  glyph_1->setClazz("unit of information");

  label = glyph_1->createLabel();
  label->setText("e:INFO");

  bbox = glyph_1->createBBox();
  bbox->setX(850);
  bbox->setY(721.5);
  bbox->setWidth(50);
  bbox->setHeight(17);

  glyph = map->createGlyph();
  glyph->setId("glyph7");
  glyph->setClazz("submap");

  label = glyph->createLabel();
  label->setText("Submap");

  bbox = glyph->createBBox();
  bbox->setX(245);
  bbox->setY(720);
  bbox->setWidth(160);
  bbox->setHeight(120);

  auto* glyph_2 = glyph->createGlyph();
  glyph_2->setId("glyph36");
  glyph_2->setClazz("terminal");
  glyph_2->setOrientation("left");

  label = glyph_2->createLabel();
  label->setText("C");

  bbox = glyph_2->createBBox();
  bbox->setX(355);
  bbox->setY(795);
  bbox->setWidth(50);
  bbox->setHeight(30);

  auto* glyph_3 = glyph->createGlyph();
  glyph_3->setId("glyph38");
  glyph_3->setClazz("terminal");
  glyph_3->setOrientation("left");

  label = glyph_3->createLabel();
  label->setText("B");

  bbox = glyph_3->createBBox();
  bbox->setX(355);
  bbox->setY(735);
  bbox->setWidth(50);
  bbox->setHeight(30);

  auto* glyph_4 = glyph->createGlyph();
  glyph_4->setId("glyph37");
  glyph_4->setClazz("terminal");
  glyph_4->setOrientation("right");

  label = glyph_4->createLabel();
  label->setText("A");

  bbox = glyph_4->createBBox();
  bbox->setX(245);
  bbox->setY(765);
  bbox->setWidth(50);
  bbox->setHeight(30);

  glyph = map->createGlyph();
  glyph->setId("glyph8");
  glyph->setClazz("biological activity");
  glyph->setCompartmentRef("glyph1");

  label = glyph->createLabel();
  label->setText("AN");

  bbox = glyph->createBBox();
  bbox->setX(820);
  bbox->setY(215);
  bbox->setWidth(200);
  bbox->setHeight(70);

  auto* glyph_5 = glyph->createGlyph();
  glyph_5->setId("glyph8a");
  glyph_5->setClazz("unit of information");

  label = glyph_5->createLabel();
  label->setText("Simple&#10;Chemical");

  bbox = glyph_5->createBBox();
  bbox->setX(843.5);
  bbox->setY(188.5);
  bbox->setWidth(53);
  bbox->setHeight(53);

  entity = glyph_5->createEntity();
  entity->setName("simple chemical");

  glyph = map->createGlyph();
  glyph->setId("glyph9");
  glyph->setClazz("biological activity");
  glyph->setCompartmentRef("glyph1");

  label = glyph->createLabel();
  label->setText("AN");

  bbox = glyph->createBBox();
  bbox->setX(820);
  bbox->setY(105);
  bbox->setWidth(200);
  bbox->setHeight(70);

  auto* glyph_6 = glyph->createGlyph();
  glyph_6->setId("glyph9a");
  glyph_6->setClazz("unit of information");

  label = glyph_6->createLabel();
  label->setText("Macromolecule");

  bbox = glyph_6->createBBox();
  bbox->setX(826.5);
  bbox->setY(96.5);
  bbox->setWidth(87);
  bbox->setHeight(17);

  entity = glyph_6->createEntity();
  entity->setName("macromolecule");

  glyph = map->createGlyph();
  glyph->setId("glyph10");
  glyph->setClazz("biological activity");
  glyph->setCompartmentRef("glyph1");

  label = glyph->createLabel();
  label->setText("AN");

  bbox = glyph->createBBox();
  bbox->setX(820);
  bbox->setY(325);
  bbox->setWidth(200);
  bbox->setHeight(70);

  auto* glyph_7 = glyph->createGlyph();
  glyph_7->setId("glyph10a");
  glyph_7->setClazz("unit of information");

  label = glyph_7->createLabel();
  label->setText("Nucleic Acid&#10;Feature");

  bbox = glyph_7->createBBox();
  bbox->setX(832.5);
  bbox->setY(309.5);
  bbox->setWidth(75);
  bbox->setHeight(31);

  entity = glyph_7->createEntity();
  entity->setName("nucleic acid feature");

  glyph = map->createGlyph();
  glyph->setId("glyph11");
  glyph->setClazz("biological activity");
  glyph->setCompartmentRef("glyph1");

  label = glyph->createLabel();
  label->setText("AN");

  bbox = glyph->createBBox();
  bbox->setX(820);
  bbox->setY(435);
  bbox->setWidth(200);
  bbox->setHeight(70);

  auto* glyph_8 = glyph->createGlyph();
  glyph_8->setId("glyph11a");
  glyph_8->setClazz("unit of information");

  label = glyph_8->createLabel();
  label->setText("Unspecified");

  bbox = glyph_8->createBBox();
  bbox->setX(831);
  bbox->setY(420.5);
  bbox->setWidth(78);
  bbox->setHeight(29);

  entity = glyph_8->createEntity();
  entity->setName("unspecified entity");

  glyph = map->createGlyph();
  glyph->setId("glyph12");
  glyph->setClazz("biological activity");
  glyph->setCompartmentRef("glyph1");

  label = glyph->createLabel();
  label->setText("AN");

  bbox = glyph->createBBox();
  bbox->setX(820);
  bbox->setY(545);
  bbox->setWidth(200);
  bbox->setHeight(70);

  auto* glyph_9 = glyph->createGlyph();
  glyph_9->setId("glyph12a");
  glyph_9->setClazz("unit of information");

  label = glyph_9->createLabel();
  label->setText("Complex");

  bbox = glyph_9->createBBox();
  bbox->setX(842);
  bbox->setY(536.5);
  bbox->setWidth(56);
  bbox->setHeight(17);

  entity = glyph_9->createEntity();
  entity->setName("complex");

  glyph = map->createGlyph();
  glyph->setId("glyph13");
  glyph->setClazz("biological activity");
  glyph->setCompartmentRef("glyph3");

  label = glyph->createLabel();
  label->setText("Biological&#10;Activity");

  bbox = glyph->createBBox();
  bbox->setX(110);
  bbox->setY(105);
  bbox->setWidth(140);
  bbox->setHeight(70);

  glyph = map->createGlyph();
  glyph->setId("glyph14");
  glyph->setClazz("perturbation");
  glyph->setCompartmentRef("glyph3");

  label = glyph->createLabel();
  label->setText("Perturbation");

  bbox = glyph->createBBox();
  bbox->setX(110);
  bbox->setY(305);
  bbox->setWidth(140);
  bbox->setHeight(70);

  glyph = map->createGlyph();
  glyph->setId("glyph15");
  glyph->setClazz("phenotype");
  glyph->setCompartmentRef("glyph3");

  label = glyph->createLabel();
  label->setText("Phenotype");

  bbox = glyph->createBBox();
  bbox->setX(110);
  bbox->setY(205);
  bbox->setWidth(140);
  bbox->setHeight(70);

  glyph = map->createGlyph();
  glyph->setId("glyph26");
  glyph->setClazz("tag");
  glyph->setOrientation("right");

  label = glyph->createLabel();
  label->setText("Tag");

  bbox = glyph->createBBox();
  bbox->setX(591);
  bbox->setY(750);
  bbox->setWidth(108);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph32");
  glyph->setClazz("or");

  bbox = glyph->createBBox();
  bbox->setX(205);
  bbox->setY(485);
  bbox->setWidth(50);
  bbox->setHeight(50);

  glyph = map->createGlyph();
  glyph->setId("glyph33");
  glyph->setClazz("not");

  bbox = glyph->createBBox();
  bbox->setX(105);
  bbox->setY(565);
  bbox->setWidth(50);
  bbox->setHeight(50);

  glyph = map->createGlyph();
  glyph->setId("glyph34");
  glyph->setClazz("and");

  bbox = glyph->createBBox();
  bbox->setX(105);
  bbox->setY(485);
  bbox->setWidth(50);
  bbox->setHeight(50);

  glyph = map->createGlyph();
  glyph->setId("glyph35");
  glyph->setClazz("delay");

  bbox = glyph->createBBox();
  bbox->setX(205);
  bbox->setY(565);
  bbox->setWidth(50);
  bbox->setHeight(50);

  glyph = map->createGlyph();
  glyph->setId("glyph27");
  glyph->setClazz("tag");
  glyph->setOrientation("right");

  label = glyph->createLabel();
  label->setText("LABEL");

  bbox = glyph->createBBox();
  bbox->setX(376);
  bbox->setY(550);
  bbox->setWidth(108);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph24");
  glyph->setClazz("biological activity");
  glyph->setCompartmentRef("glyph0");

  label = glyph->createLabel();
  label->setText("AN&#10;or CN");

  bbox = glyph->createBBox();
  bbox->setX(596);
  bbox->setY(550);
  bbox->setWidth(108);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph17");
  glyph->setClazz("biological activity");
  glyph->setCompartmentRef("glyph0");

  label = glyph->createLabel();
  label->setText("Source&#10;AN");

  bbox = glyph->createBBox();
  bbox->setX(376);
  bbox->setY(460);
  bbox->setWidth(108);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph31");
  glyph->setClazz("and");

  bbox = glyph->createBBox();
  bbox->setX(620);
  bbox->setY(460);
  bbox->setWidth(60);
  bbox->setHeight(60);

  port = glyph->createPort();
  port->setId("glyph31.1");
  port->setX(590);
  port->setY(490);

  glyph = map->createGlyph();
  glyph->setId("glyph21");
  glyph->setClazz("biological activity");
  glyph->setCompartmentRef("glyph0");

  label = glyph->createLabel();
  label->setText("Source&#10;AN");

  bbox = glyph->createBBox();
  bbox->setX(376);
  bbox->setY(280);
  bbox->setWidth(108);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph22");
  glyph->setClazz("biological activity");
  glyph->setCompartmentRef("glyph0");

  label = glyph->createLabel();
  label->setText("Target&#10;AN");

  bbox = glyph->createBBox();
  bbox->setX(596);
  bbox->setY(280);
  bbox->setWidth(108);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph25");
  glyph->setClazz("biological activity");
  glyph->setCompartmentRef("glyph0");

  label = glyph->createLabel();
  label->setText("Source&#10;AN");

  bbox = glyph->createBBox();
  bbox->setX(376);
  bbox->setY(100);
  bbox->setWidth(108);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph16");
  glyph->setClazz("biological activity");
  glyph->setCompartmentRef("glyph0");

  label = glyph->createLabel();
  label->setText("Target&#10;AN");

  bbox = glyph->createBBox();
  bbox->setX(596);
  bbox->setY(100);
  bbox->setWidth(108);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph20");
  glyph->setClazz("biological activity");
  glyph->setCompartmentRef("glyph0");

  label = glyph->createLabel();
  label->setText("Source&#10;AN");

  bbox = glyph->createBBox();
  bbox->setX(376);
  bbox->setY(190);
  bbox->setWidth(108);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph19");
  glyph->setClazz("biological activity");
  glyph->setCompartmentRef("glyph0");

  label = glyph->createLabel();
  label->setText("Target&#10;AN");

  bbox = glyph->createBBox();
  bbox->setX(596);
  bbox->setY(190);
  bbox->setWidth(108);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph23");
  glyph->setClazz("biological activity");
  glyph->setCompartmentRef("glyph0");

  label = glyph->createLabel();
  label->setText("Source&#10;AN");

  bbox = glyph->createBBox();
  bbox->setX(376);
  bbox->setY(370);
  bbox->setWidth(108);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph18");
  glyph->setClazz("biological activity");
  glyph->setCompartmentRef("glyph0");

  label = glyph->createLabel();
  label->setText("Target&#10;AN");

  bbox = glyph->createBBox();
  bbox->setX(596);
  bbox->setY(370);
  bbox->setWidth(108);
  bbox->setHeight(60);

  glyph = map->createGlyph();
  glyph->setId("glyph29");
  glyph->setClazz("biological activity");
  glyph->setCompartmentRef("glyph2");

  label = glyph->createLabel();
  label->setText("AN&#10;or CN");

  bbox = glyph->createBBox();
  bbox->setX(450);
  bbox->setY(790);
  bbox->setWidth(100);
  bbox->setHeight(50);

  glyph = map->createGlyph();
  glyph->setId("glyph30");
  glyph->setClazz("biological activity");
  glyph->setCompartmentRef("glyph2");

  label = glyph->createLabel();
  label->setText("AN&#10;or CN");

  bbox = glyph->createBBox();
  bbox->setX(450);
  bbox->setY(720);
  bbox->setWidth(100);
  bbox->setHeight(50);

  glyph = map->createGlyph();
  glyph->setId("glyph28");
  glyph->setClazz("biological activity");
  glyph->setCompartmentRef("glyph2");

  label = glyph->createLabel();
  label->setText("AN&#10;or CN");

  bbox = glyph->createBBox();
  bbox->setX(105);
  bbox->setY(755);
  bbox->setWidth(100);
  bbox->setHeight(50);

  arc = map->createArc();
  arc->setId("arc0");
  arc->setClazz("equivalence arc");
  arc->setSource("glyph27");
  arc->setTarget("glyph24");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(484);
  point->setY(580);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(596);
  point->setY(580);

  arc = map->createArc();
  arc->setId("arc1");
  arc->setClazz("logic arc");
  arc->setSource("glyph17");
  arc->setTarget("glyph31.1");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(484);
  point->setY(490);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(590);
  point->setY(490);

  arc = map->createArc();
  arc->setId("arc2");
  arc->setClazz("unknown influence");
  arc->setSource("glyph21");
  arc->setTarget("glyph22");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(484);
  point->setY(310);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(596);
  point->setY(310);

  arc = map->createArc();
  arc->setId("arc3");
  arc->setClazz("positive influence");
  arc->setSource("glyph25");
  arc->setTarget("glyph16");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(484);
  point->setY(130);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(596);
  point->setY(130);

  arc = map->createArc();
  arc->setId("arc4");
  arc->setClazz("negative influence");
  arc->setSource("glyph20");
  arc->setTarget("glyph19");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(484);
  point->setY(220);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(596);
  point->setY(220);

  arc = map->createArc();
  arc->setId("arc5");
  arc->setClazz("necessary stimulation");
  arc->setSource("glyph23");
  arc->setTarget("glyph18");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(484);
  point->setY(400);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(596);
  point->setY(400);

  arc = map->createArc();
  arc->setId("arc6");
  arc->setClazz("equivalence arc");
  arc->setSource("glyph36");
  arc->setTarget("glyph29");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(405);
  point->setY(811.042);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(450);
  point->setY(812.917);

  arc = map->createArc();
  arc->setId("arc7");
  arc->setClazz("equivalence arc");
  arc->setSource("glyph38");
  arc->setTarget("glyph30");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(405);
  point->setY(748.958);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(450);
  point->setY(747.083);

  arc = map->createArc();
  arc->setId("arc8");
  arc->setClazz("equivalence arc");
  arc->setSource("glyph28");
  arc->setTarget("glyph37");

  point = arc->createStart();
  point->setElementName("start");
  point->setX(205);
  point->setY(780);

  point = arc->createEnd();
  point->setElementName("end");
  point->setX(245);
  point->setY(780);


    std::string outfile = "out.sbgn";
  if (argc > 1)
    outfile = argv[1];
  writeSBGNToFile(doc, outfile.c_str());

  delete doc;

  return 0;
}

