# 2 "viewer-file.c" 2

static void viewer_file_init (ViewerFile *self);
static void viewer_file_class_init (ViewerFileClass *klass);

# 3 "viewer-file.c" 3 4
static gpointer viewer_file_parent_class = ((void *)0); 

static gint ViewerFile_private_offset;

static void
viewer_file_class_intern_init (gpointer klass) 
{ 
	viewer_file_parent_class = g_type_class_peek_parent (klass);
	if (ViewerFile_private_offset != 0) 
		g_type_class_adjust_private_offset (klass, &ViewerFile_private_offset); 
	
	viewer_file_class_init ((ViewerFileClass*) klass);
} __attribute__((__unused__)) 

static inline gpointer 
viewer_file_get_instance_private (ViewerFile *self) 
{ 
	return (((gpointer) ((guint8*) (self) + (glong) (ViewerFile_private_offset))));
} 

GType 
viewer_file_get_type (void) 
{ 
static volatile gsize g_define_type_id__volatile = 0; 
if ((__extension__ (
{ 
	typedef char 
	GStaticAssertCompileTimeAssertion_1[
		(sizeof *(&g_define_type_id__volatile) == sizeof (gpointer)) ? 1 : -1
		] __attribute__((__unused__));
	(void) (0 ? (gpointer) *(&g_define_type_id__volatile) : 0); 
	(!(__extension__ (
	{ 
	typedef char 
	_GStaticAssertCompileTimeAssertion_2[
		(sizeof *(&g_define_type_id__volatile) == sizeof (gpointer)) ? 1 : -1
		] __attribute__((__unused__));
	
	(gpointer) __atomic_load_8 ((&g_define_type_id__volatile), 5); 
	})) && g_once_init_enter (&g_define_type_id__volatile)); 
}))) 
	
	{ 
	GType g_define_type_id = 
		g_type_register_static_simple (((GType) ((20) << (2))), 
		g_intern_static_string ("ViewerFile"), 
		sizeof (ViewerFileClass), 
		(GClassInitFunc) viewer_file_class_intern_init, 
		sizeof (ViewerFile), 
		(GInstanceInitFunc) viewer_file_init, 
		(GTypeFlags) 0); 

	{ 
		{
			{ 
				ViewerFile_private_offset = 
				g_type_add_instance_private (g_define_type_id, sizeof (ViewerFilePrivate));
			};
		} 
	} (__extension__ (
		{ 
		typedef char
		 _GStaticAssertCompileTimeAssertion_3[
			(sizeof *(&g_define_type_id__volatile) == sizeof (gpointer)) ? 1 : -1
			] __attribute__((__unused__)); 
		(void) (0 ? *(&g_define_type_id__volatile) = (g_define_type_id) : 0); 
		g_once_init_leave ((&g_define_type_id__volatile), (gsize) (g_define_type_id)); 
		})); 
	} 
	return g_define_type_id__volatile; 
}


static void
viewer_file_class_init (ViewerFileClass *klass)
{
}

static void
viewer_file_init (ViewerFile *self)
{
 ViewerFilePrivate *priv = viewer_file_get_instanace_private (self);




}
