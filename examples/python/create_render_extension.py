#! /bin/env python
from libsbgn import *
import sys

def createExample():
  doc = SbgnDocument()

  map = doc.createMap()
  map.setMetaId("map1")
  map.setLanguage("process description")

  glyph = map.createGlyph()
  glyph.setId("glyph0")
  glyph.setClazz("macromolecule")

  label = glyph.createLabel()
  label.setText("greek letter alpha: &#945;")

  bbox = glyph.createBBox()
  bbox.setX(20)
  bbox.setY(20)
  bbox.setWidth(140)
  bbox.setHeight(60)

  renderInfo = LocalRenderInformation()
  
  renderInfo.setId("info1")
  renderInfo.setProgramName("libSBGN example")
  renderInfo.setProgramVersion("0.0.1")

  color = renderInfo.createColorDefinition()
  color.setId("orange")
  color.setValue("#fa9e2fff")

  gradient = renderInfo.createLinearGradientDefinition()
  gradient.setId("orangeGradient")
  
  stop = gradient.createGradientStop()
  stop.setOffset("0%")
  stop.setStopColor("#ffffff")
  stop = gradient.createGradientStop()
  stop.setOffset("100%")
  stop.setStopColor("#fa9e2fff")

  style = renderInfo.createLocalStyle()
  style.addId("glyph0")
  
  group = style.createGroup()
  group.setStroke("orange")
  group.setStrokeWidth(2.0)
  group.setFill("orangeGradient")

  map.setRenderInformation(renderInfo)

  writeSBGNToFile(doc, "out.sbgn")

  
if __name__ == "__main__":
  createExample()
