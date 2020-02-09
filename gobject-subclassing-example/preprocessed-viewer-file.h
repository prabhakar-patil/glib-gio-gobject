/*
 * #define VIEWER_TYPE_FILE viewer_file_get_type () 
 */
GType viewer_file_get_type (void);

/*
 * G_DECLARE_FINAL_TYPE (ViewerFile, viewer_file, VIEWER, FILE, GObject)
 */

typedef struct _ViewerFile ViewerFile;

typedef struct { 
	GObjectClass parent_class; 
} ViewerFileClass; 

typedef ViewerFile *ViewerFile_autoptr; 

static inline void glib_autoptr_cleanup_ViewerFile (ViewerFile **_ptr) 
{ 
	glib_autoptr_cleanup_GObject ((GObject **) _ptr); 
} 

// this cast function
static inline ViewerFile * VIEWER_FILE (gpointer ptr) 
{ 
return (((ViewerFile*) g_type_check_instance_cast ((GTypeInstance*) (ptr), (viewer_file_get_type ())))); 
} 

// this check function, check whether ptr is instance of ViewerFile* or not
static inline gboolean VIEWER_IS_FILE (gpointer ptr) 
{ 
return ((__extension__ (
        { 
		GTypeInstance *__inst = (GTypeInstance*) (ptr); 
		GType __t = (viewer_file_get_type ()); 
		gboolean __r; 
		if (!__inst) 
			__r = (0); 
		else if (__inst->g_class && __inst->g_class->g_type == __t) 
			__r = (!(0)); 
		else 
			__r = g_type_check_instance_is_a (__inst, __t);
		 __r; 
	}
	))); 
}

ViewerFile *viewer_file_new (void);


