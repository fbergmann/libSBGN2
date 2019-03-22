#include <iostream>

#include <sbgn/SbgnTypes.h>
#include <sbml/packages/render/common/RenderExtensionTypes.h>

void printRenderExtension(SbgnMap* map)
{
  if (map == NULL)
  {
    std::cout << " Map was NULL ..." << std::endl;
    return;
  }

  auto* info = map->getRenderInformation();
  if (info == NULL)
  {
    std::cout << " RenderInformation was NULL" << std::endl;
    return;
  }

  std::cout << "RenderInformation" << std::endl;
  if (info->isSetId())
    std::cout << "id: " << info->getId() << std::endl;

  if (info->isSetName())
    std::cout << "name: " << info->getName() << std::endl;

  if (info->isSetProgramName())
    std::cout << "program name: " << info->getProgramName() << std::endl;

  if (info->isSetProgramVersion())
    std::cout << "program version: " << info->getProgramVersion() << std::endl;

  if (info->getNumColorDefinitions() > 0)
    std::cout << "# color definitions: " << info->getNumColorDefinitions() << std::endl;

  if (info->getNumGradientDefinitions() > 0)
    std::cout << "# gradient definitions: " << info->getNumGradientDefinitions() << std::endl;

  if (info->getNumLocalStyles() > 0)
    std::cout << "# style definitions: " << info->getNumLocalStyles() << std::endl;

}

int main(int argc, const char* argv[])
{

  if (argc != 2)
  {
    std::cout << " usage: print_render_extension <filename>" << std::endl;
    return 1;
  }

  auto* doc = readSBGNFromFile(argv[1]);

  printRenderExtension(doc->getMap(0));

  delete doc;

  return 0;
}