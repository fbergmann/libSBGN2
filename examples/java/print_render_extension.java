import java.io.*;
import org.sbgn.libsbgn.*;

public class print_render_extension
{

static void printRenderExtension(SbgnMap map)
{
  if (map == null)
  {
    System.out.println(" Map was null ..." );
    return;
  }

  LocalRenderInformation info = map.getRenderInformation();
  if (info == null)
  {
    System.out.println(" RenderInformation was null" );
    return;
  }

  System.out.println("RenderInformation" );
  if (info.isSetId())
    System.out.println("id: " + info.getId() );

  if (info.isSetName())
    System.out.println("name: " + info.getName() );

  if (info.isSetProgramName())
    System.out.println("program name: " + info.getProgramName() );

  if (info.isSetProgramVersion())
    System.out.println("program version: " + info.getProgramVersion() );

  if (info.getNumColorDefinitions() > 0)
    System.out.println("# color definitions: " + info.getNumColorDefinitions() );

  if (info.getNumGradientDefinitions() > 0)
    System.out.println("# gradient definitions: " + info.getNumGradientDefinitions() );

  if (info.getNumLocalStyles() > 0)
    System.out.println("# style definitions: " + info.getNumLocalStyles() );

}

public static void main (String[] args)
{

  if (args.length != 1)
  {
    System.out.println(" usage: print_render_extension <filename>" );
    System.exit(1);
  }

  System.loadLibrary("sbgnj");
  
  SbgnDocument doc = libsbgn.readSBGNFromFile(args[0]);

  printRenderExtension(doc.getMap());

}

}
