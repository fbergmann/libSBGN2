using libsbgncs;

public class create_render_extension
{

public static int Main(string[] args)
{
  var doc = new SbgnDocument();

  var map = doc.createMap();
  map.setMetaId("map1");
  map.setLanguage("process description");

  var glyph = map.createGlyph();
  glyph.setId("glyph0");
  glyph.setClazz("macromolecule");

  var label = glyph.createLabel();
  label.setText("greek letter alpha: &#945;");

  var bbox = glyph.createBBox();
  bbox.setX(20);
  bbox.setY(20);
  bbox.setWidth(140);
  bbox.setHeight(60);

  var renderInfo = new LocalRenderInformation();
  
  renderInfo.setId("info1");
  renderInfo.setProgramName("libSBGN example");
  renderInfo.setProgramVersion("0.0.1");

  var color = renderInfo.createColorDefinition();
  color.setId("orange");
  color.setValue("#fa9e2fff");

  var gradient = renderInfo.createLinearGradientDefinition();
  gradient.setId("orangeGradient");
  var stop = gradient.createGradientStop();
  stop.setOffset("0%");
  stop.setStopColor("#ffffff");
  stop = gradient.createGradientStop();
  stop.setOffset("100%");
  stop.setStopColor("#fa9e2fff");

  var style = renderInfo.createLocalStyle();
  style.addId("glyph0");
  var group = style.createGroup();
  group.setStroke("orange");
  group.setStrokeWidth(2.0);
  group.setFill("orangeGradient");

  map.setRenderInformation(renderInfo);

  libsbgn.writeSBGNToFile(doc, "out.sbgn");

  return 0;
}

}