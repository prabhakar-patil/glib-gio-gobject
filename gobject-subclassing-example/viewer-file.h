#ifndef __VIEWER_FILE_H__
#define __VIEWER_FILE_H__

#include <glib-object.h>

G_BEGIN_DECLS

/*
 * Type declaration
 */

#define VIEWER_TYPE_FILE viewer_file_get_type ()

G_DECLARE_FINAL_TYPE (ViewerFile, viewer_file, VIEWER, FILE, GObject)

/*
 * Mehtod definations
 */

ViewerFile *viewer_file_new (void);

G_END_DECLS

#endif /*__VIEWER_FILE_H__*/
