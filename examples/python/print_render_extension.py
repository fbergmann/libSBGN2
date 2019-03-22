#! /bin/env python
from libsbgn import *
import sys

def printRenderExtension(map):

  if map is None:
    print(" Map was None ..." )
    return
  

  info = map.getRenderInformation()
  if info is None:
    print(" RenderInformation was None" )
    return
  

  print("RenderInformation" )
  if info.isSetId():
    print("id: %s" % info.getId() )

  if info.isSetName():
    print("name: %s" % info.getName() )

  if info.isSetProgramName():
    print("program name: %s" % info.getProgramName() )

  if info.isSetProgramVersion():
    print("program version: %s" % info.getProgramVersion() )

  if info.getNumColorDefinitions() > 0:
    print("# color definitions: %d" % info.getNumColorDefinitions() )

  if info.getNumGradientDefinitions() > 0:
    print("# gradient definitions: %d" % info.getNumGradientDefinitions() )

  if info.getNumLocalStyles() > 0:
    print("# style definitions: %d" % info.getNumLocalStyles() )


if __name__ == "__main__":
  args = sys.argv
  if len(args) != 2:  
    print(" usage: print_render_extension <filename>" )
    sys.exit(1)
  

  doc = readSBGNFromFile(args[1])
  printRenderExtension(doc.getMap())
