#include "viewer-file.h"

struct _ViewerFile
{
	GObject parent_instance;	
};

G_DEFINE_TYPE (ViewerFile, viewer_file, G_TYPE_OBJECT)

static void
viewer_file_class_init (ViewerFileClass *klass)
{
	g_print ("viewer_file_class_init\n");
}

static void
viewer_file_init (ViewerFile *self)
{
	g_print ("viewer_file_init\n");
	/* Initialize all public and private members to resonable default values.
	 * They are all automatically initialized to 0 to begin with.
	 */
}

ViewerFile*
viewer_file_new (void)
{
  return g_object_new (VIEWER_TYPE_FILE, NULL);
}

void main(void)
{
	ViewerFile *file = viewer_file_new ();
	
	if (VIEWER_IS_FILE (file))
		g_print ("file is ViewerFile instance\n");		
	else
		g_print ("file is NOT ViewerFile instance\n");	
	
	g_clear_object (&file);
}
