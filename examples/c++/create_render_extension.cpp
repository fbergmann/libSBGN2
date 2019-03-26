#include <iostream>

#include <sbgn/SbgnTypes.h>
#include <sbml/packages/render/common/RenderExtensionTypes.h>


int main(int argc, const char* argv[])
{
  auto* doc = new SbgnDocument();

  auto* map = doc->createMap();
  map->setId("map1");
  map->setLanguage("process description");

  auto* glyph = map->createGlyph();
  glyph->setId("glyph0");
  glyph->setClazz("macromolecule");

  auto* label = glyph->createLabel();
  label->setText("greek letter alpha: &#945;");

  auto* bbox = glyph->createBBox();
  bbox->setX(20);
  bbox->setY(20);
  bbox->setWidth(140);
  bbox->setHeight(60);

  auto* renderInfo = new LIBSBML_CPP_NAMESPACE LocalRenderInformation();
  
  renderInfo->setId("info1");
  renderInfo->setProgramName("libSBGN example");
  renderInfo->setProgramVersion("0.0.1");

  auto* color = renderInfo->createColorDefinition();
  color->setId("orange");
  color->setValue("#fa9e2fff");

  auto* gradient = renderInfo->createLinearGradientDefinition();
  gradient->setId("orangeGradient");
  auto* stop = gradient->createGradientStop();
  stop->setOffset("0%");
  stop->setStopColor("#ffffff");
  stop = gradient->createGradientStop();
  stop->setOffset("100%");
  stop->setStopColor("#fa9e2fff");

  auto* style = renderInfo->createLocalStyle();
  style->setIdList({"glyph0"});
  auto* group = style->createGroup();
  group->setStroke("orange");
  group->setStrokeWidth(2.0);
  group->setFill("orangeGradient");

  map->setRenderInformation(renderInfo);
  delete renderInfo;

    std::string outfile = "out.sbgn";
  if (argc > 1)
    outfile = argv[1];
  writeSBGNToFile(doc, outfile.c_str());

  delete doc;

  return 0;
}
