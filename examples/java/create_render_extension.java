import java.io.*;
import org.sbgn.libsbgn.*;

public class create_render_extension
{

public static void main (String[] args)
{
  System.loadLibrary("sbgnj");
  

  SbgnDocument doc = new SbgnDocument();

  SbgnMap map = doc.createMap();
  map.setMetaId("map1");
  map.setLanguage("process description");

  SbgnGlyph glyph = map.createGlyph();
  glyph.setId("glyph0");
  glyph.setClazz("macromolecule");

  SbgnLabel label = glyph.createLabel();
  label.setText("greek letter alpha: &#945;");

  SbgnBBox bbox = glyph.createBBox();
  bbox.setX(20);
  bbox.setY(20);
  bbox.setWidth(140);
  bbox.setHeight(60);

  LocalRenderInformation renderInfo = new LocalRenderInformation();
  
  renderInfo.setId("info1");
  renderInfo.setProgramName("libSBGN example");
  renderInfo.setProgramVersion("0.0.1");

  ColorDefinition color = renderInfo.createColorDefinition();
  color.setId("orange");
  color.setValue("#fa9e2fff");

  LinearGradient gradient = renderInfo.createLinearGradientDefinition();
  gradient.setId("orangeGradient");
  GradientStop stop = gradient.createGradientStop();
  stop.setOffset("0%");
  stop.setStopColor("#ffffff");
  stop = gradient.createGradientStop();
  stop.setOffset("100%");
  stop.setStopColor("#fa9e2fff");

  LocalStyle style = renderInfo.createLocalStyle();
  style.addId("glyph0");
  RenderGroup group = style.createGroup();
  group.setStroke("orange");
  group.setStrokeWidth(2.0);
  group.setFill("orangeGradient");

  map.setRenderInformation(renderInfo);

  libsbgn.writeSBGNToFile(doc, "out.sbgn");

}

}