using System;
using libsbgncs;

public class print_render_extension
{

static void printRenderExtension(SbgnMap map)
{
  if (map == null)
  {
    Console.WriteLine(" Map was null ..." );
    return;
  }

  var info = map.getRenderInformation();
  if (info == null)
  {
    Console.WriteLine(" RenderInformation was null" );
    return;
  }

  Console.WriteLine("RenderInformation" );
  if (info.isSetId())
    Console.WriteLine("id: {0}", info.getId() );

  if (info.isSetName())
    Console.WriteLine("name: {0}", info.getName() );

  if (info.isSetProgramName())
    Console.WriteLine("program name: {0}", info.getProgramName() );

  if (info.isSetProgramVersion())
    Console.WriteLine("program version: {0}", info.getProgramVersion() );

  if (info.getNumColorDefinitions() > 0)
    Console.WriteLine("# color definitions: {0}", info.getNumColorDefinitions() );

  if (info.getNumGradientDefinitions() > 0)
    Console.WriteLine("# gradient definitions: {0}", info.getNumGradientDefinitions() );

  if (info.getNumLocalStyles() > 0)
    Console.WriteLine("# style definitions: {0}", info.getNumLocalStyles() );

}

public static int Main(string[] args)
{

  if (args.Length != 1)
  {
    Console.WriteLine(" usage: print_render_extension <filename>" );
    return 1;
  }

  var doc = libsbgn.readSBGNFromFile(args[0]);

  printRenderExtension(doc.getMap());


  return 0;
}

}