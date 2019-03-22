#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include <sbgn/SbgnTypes.h>


void replaceAllSubStringsInPlace(std::string &str, const std::string &from, const std::string &to)
{
  if (from.empty())
    return;

  size_t start_pos = 0;

  while ((start_pos = str.find(from, start_pos)) != std::string::npos)
  {
    str.replace(start_pos, from.length(), to);
    start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
  }
}

void writeStart(std::ostream &os)
{
  os << "#include <iostream>" << std::endl;
  os << std::endl;
  os << "#include <sbgn/SbgnTypes.h>" << std::endl;
  os << std::endl;
  os << "int main(int argc, const char* argv[])" << std::endl;
  os << "{" << std::endl;
  os << "  auto* doc = new SbgnDocument();" << std::endl;
  os << std::endl;
  os << "  SbgnGlyph* glyph = NULL;" << std::endl;
  os << "  SbgnState* state = NULL;" << std::endl;
  os << "  SbgnEntity* entity = NULL;" << std::endl;
  os << "  SbgnCallout* co = NULL;" << std::endl;
  os << "  SbgnGlyph* clone = NULL;" << std::endl;
  os << "  SbgnLabel* label = NULL;" << std::endl;
  os << "  SbgnArc*   arc = NULL;" << std::endl; 
  os << "  SbgnArcGroup* arcGroup = NULL;" << std::endl;
  os << "  SbgnBBox*  bbox = NULL;" << std::endl;
  os << "  SbgnPoint* point = NULL;" << std::endl;
  os << "  SbgnPort*  port= NULL;" << std::endl;
  os << std::endl;
  os << "  auto* map = doc->createMap();" << std::endl;

}

void writeEnd(std::ostream& os)
{
  os << std::endl;
  os << "  writeSBGNToFile(doc, \"out.sbgn\");" << std::endl;
  os << std::endl;
  os << "  delete doc;" << std::endl;
  os << std::endl;
  os << "  return 0;" << std::endl;
  os << "}" << std::endl << std::endl;
}

void writeBBox(std::ostream& os, SbgnBBox* bbox, const std::string& parent)
{
  if (bbox == NULL) return;
  os << std::endl;
  os << "  bbox = " << parent << "->createBBox();" << std::endl;
  if (bbox->isSetX())
  os << "  bbox->setX(" << bbox->getX() << ");" << std::endl;
  if (bbox->isSetY())
  os << "  bbox->setY(" << bbox->getY() << ");" << std::endl;
  if (bbox->isSetWidth())
  os << "  bbox->setWidth(" << bbox->getWidth() << ");" << std::endl;
  if (bbox->isSetHeight())
  os << "  bbox->setHeight(" << bbox->getHeight() << ");" << std::endl;
}

void writeLabel(std::ostream &os, SbgnLabel* label, const std::string& parent)
{
  if (label == NULL)
    return;
  os << std::endl;
  os << "  label = " << parent << "->createLabel();" << std::endl;
  if (label->isSetText())
  {
    std::string text = label->getText();
    replaceAllSubStringsInPlace(text, "\n", "&#10;");
    os << "  label->setText(\"" << text << "\");" << std::endl;
  }
  if (label->isSetBBox())
    writeBBox(os, label->getBBox(), "label");
}

void writePoint(std::ostream& os, SbgnPoint* point, 
  const std::string& parent, const std::string& type, bool isChild = false)
{
  if (point == NULL) return;
  os << std::endl;
  std::string currentName = "point";
  if (isChild)
  {
    static int count = 0; 
    std::stringstream str; str << currentName << ++count;
    currentName = str.str();
    os << "  auto* " << currentName <<  " = " << parent << "->create" << type << "();" << std::endl;
  }
  else
  os << "  point = " << parent << "->create" << type << "();" << std::endl;
  os << "  " << currentName << "->setElementName(\"" << point->getElementName() << "\");" << std::endl;
  if (point->isSetId())
    os << "  " << currentName << "->setId(\"" << point->getId() << "\");" << std::endl;
  if (point->isSetX())
    os << "  " << currentName << "->setX(" << point->getX() << ");" << std::endl;
  if (point->isSetY())
    os << "  " << currentName << "->setY(" << point->getY() << ");" << std::endl;

  for (unsigned int i = 0; i < point->getNumPoints(); ++i)
  {
    writePoint(os, point->getPoint(i), currentName, "Point", true);
  }

}

void writeCallout(std::ostream& os, SbgnCallout* co, const std::string& parent)
{
  if (co == NULL) return;
  os << std::endl;
  os << "  co = " << parent << "->createCallout();" << std::endl;
  if (co->isSetId())
    os << "  co->setId(\"" << co->getId() << "\");" << std::endl;
  if (co->isSetTarget())
    os << "  co->setTarget(\"" << co->getTarget() << "\");" << std::endl;
  if (co->isSetPoint())
    writePoint(os, co->getPoint(), "co", "Point");
}

void writeClone(std::ostream& os, SbgnGlyph* clone, const std::string& parent)
{
  if (clone == NULL) return;
  os << std::endl;
  os << "  clone = " << parent << "->createClone();" << std::endl;
  if (clone->isSetId())
    os << "  clone->setId(\"" << clone->getId() << "\");" << std::endl;
  if (clone->isSetLabel())
    writeLabel(os, clone->getLabel(), "clone");
}

void writeState(std::ostream& os, SbgnState* state, const std::string& parent)
{
  if (state == NULL) return;
  os << std::endl;
  os << "  state = " << parent << "->createState();" << std::endl;
  if (state->isSetId())
    os << "  state->setId(\"" << state->getId() << "\");" << std::endl;
  if (state->isSetVariable())
    os << "  state->setVariable(\"" << state->getVariable() << "\");" << std::endl;
  if (state->isSetValue())
    os << "  state->setValue(\"" << state->getValue() << "\");" << std::endl;
}

void writeEntity(std::ostream& os, SbgnEntity* entity, const std::string& parent)
{
  if (entity == NULL) return;
  os << std::endl;
  os << "  entity = " << parent << "->createEntity();" << std::endl;
  if (entity->isSetId())
    os << "  entity->setId(\"" << entity->getId() << "\");" << std::endl;
  if (entity->isSetName())
    os << "  entity->setName(\"" << entity->getName() << "\");" << std::endl;
}


void writePort(std::ostream& os, SbgnPort* port, const std::string& parent)
{
  if (port == NULL) return;
  os << std::endl;
  os << "  port = " << parent << "->createPort();" << std::endl;
  if (port->isSetId())
    os << "  port->setId(\"" << port->getId() << "\");" << std::endl;
  if (port->isSetX())
    os << "  port->setX(" << port->getX() << ");" << std::endl;
  if (port->isSetY())
    os << "  port->setY(" << port->getY() << ");" << std::endl;

}

void writeGlyph(std::ostream& os, SbgnGlyph* glyph, const std::string& parent, bool isSubGlyph = false)
{
  if (glyph == NULL) return;
  os << std::endl;
  std::string currentName = "glyph";
  
  if (isSubGlyph)
  {
    static int count = 0;
    std::stringstream str; str << currentName << "_" << ++count;
    currentName = str.str();
  }

  os << "  " << (isSubGlyph ? "auto* " : "")
     << currentName << " = " << parent << "->createGlyph();" << std::endl;
  if (glyph->isSetId())
  os << "  " << currentName << "->setId(\"" << glyph->getId() << "\");" << std::endl;
  if (glyph->isSetClazz())
  os << "  " << currentName << "->setClazz(\"" << glyph->getClazz() << "\");" << std::endl;
  if (glyph->isSetCompartmentOrder())
    os << "  " << currentName << "->setCompartmentOrder(" << glyph->getCompartmentOrder() << ");" << std::endl;
  if (glyph->isSetCompartmentRef())
    os << "  " << currentName << "->setCompartmentRef(\"" << glyph->getCompartmentRef() << "\");" << std::endl;
  if (glyph->isSetOrientation())
    os << "  " << currentName << "->setOrientation(\"" << glyph->getOrientationAsString () << "\");" << std::endl;
  if (glyph->isSetLabel())
    writeLabel(os, glyph->getLabel(), currentName);
  if (glyph->isSetBBox())
    writeBBox(os, glyph->getBBox(), currentName);
  if (glyph->isSetCallout())
    writeCallout(os, glyph->getCallout(), currentName);
  if (glyph->isSetState())
    writeState(os, glyph->getState(), currentName);
  if (glyph->isSetEntity())
    writeEntity(os, glyph->getEntity(), currentName);
  if (glyph->isSetClone())
    writeClone(os, glyph->getClone(), currentName);

  for (unsigned int i = 0; i < glyph->getNumPorts(); ++i)
  {
    writePort(os, glyph->getPort(i), currentName);
  }

  for (unsigned int i = 0; i < glyph->getNumGlyphs(); ++i)
  {
    writeGlyph(os, glyph->getGlyph(i), currentName, true);
  }

}

void writeArc(std::ostream& os, SbgnArc* arc, const std::string& parent)
{
  if (arc == NULL) return;
  os << std::endl;
  os << "  arc = " << parent << "->createArc();" << std::endl;
  if (arc->isSetId())
    os << "  arc->setId(\"" << arc->getId() << "\");" << std::endl;
  if (arc->isSetClazz())
    os << "  arc->setClazz(\"" << arc->getClazz() << "\");" << std::endl;
  if (arc->isSetSource())
    os << "  arc->setSource(\"" << arc->getSource() << "\");" << std::endl;
  if (arc->isSetTarget())
    os << "  arc->setTarget(\"" << arc->getTarget() << "\");" << std::endl;
  if (arc->isSetStart())
    writePoint(os, arc->getStart(), "arc", "Start");

  for (unsigned int i = 0; i < arc->getNumNexts(); ++i)
    writePoint(os, arc->getNext(i), "arc", "Next");

  if (arc->isSetEnd())
    writePoint(os, arc->getEnd(), "arc", "End");

  for (unsigned int i = 0; i < arc->getNumPorts(); ++i)
  {
    writePort(os, arc->getPort(i), "arc");
  }

  for (unsigned int i = 0; i < arc->getNumGlyphs(); ++i)
  {
    writeGlyph(os, arc->getGlyph(i), "arc", true);
  }
}

void writeArcGroup(std::ostream& os, SbgnArcGroup* arcGroup, const std::string& parent)
{
  if (arcGroup == NULL) return;
  os << std::endl;
  os << "  arcGroup = " << parent << "->createArcGroup();" << std::endl;
  if (arcGroup->isSetId())
    os << "  arcGroup->setId(\"" << arcGroup->getId() << "\");" << std::endl;
  if (arcGroup->isSetClazz())
    os << "  arcGroup->setClazz(\"" << arcGroup->getClazz() << "\");" << std::endl;

  for (unsigned int i = 0; i < arcGroup->getNumGlyphs(); ++i)
    writeGlyph(os, arcGroup->getGlyph(i), "arcGroup", true);

  for (unsigned int i = 0; i < arcGroup->getNumArcs(); ++i)
  {
    writeArc(os, arcGroup->getArc(i), "arcGroup");
  }
}

void writeMap(std::ostream& os, SbgnMap* map)
{
  if (map == NULL) return;

  if (map->isSetId())
    os << "  map->setMetaId(\"" << map->getId() << "\");" << std::endl;
  if (map->isSetLanguage())
    os << "  map->setLanguage(\"" << map->getLanguageAsString() << "\");" << std::endl;

  if (map->isSetBBox())
    writeBBox(os, map->getBBox(), "map");

  for (unsigned int i = 0; i < map->getNumGlyphs(); ++i)
  {
    writeGlyph(os, map->getGlyph(i), "map");
  }

  for (unsigned int i = 0; i < map->getNumArcs(); ++i)
  {
    writeArc(os, map->getArc(i), "map");
  }

  for (unsigned int i = 0; i < map->getNumArcGroups(); ++i)
  {
    writeArcGroup(os, map->getArcGroup (i), "map");
  }

  os << std::endl;
}

int main(int argc, const char* argv[])
{

  if (argc != 3)
  {
    std::cout << " usage: create_cpp_example <input-sbgn> <output-cpp>"
      << std::endl;
    return 1;
  }

  std::ofstream os;
  os.open(argv[2]);

  if (os.fail() || os.bad())
  {
    os.close();
    std::cerr << "couldn't open output stream" << std::endl;
    return 1;
  }

  auto* doc = readSBGNFromFile(argv[1]);

  writeStart(os);

  writeMap(os, doc->getMap(0));

  writeEnd(os);

  os.close();

  delete doc;

  return 0;
}

