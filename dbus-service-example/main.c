#include "myapp-generated.h"
#include <gio/gio.h>

gboolean handle_hello_world (MyAppNetCorpMyAppFrobber *object, 
			     GDBusMethodInvocation *invocation,
			     const gchar *arg_greeting);

void
on_bus_acquired (GDBusConnection *connection,
                 const gchar *name,
                 gpointer user_data)
{
	g_print ("on_bus_acquired: %s\n", name);
}

void
on_name_acquired (GDBusConnection *connection,
               	  const gchar *name,
                  gpointer user_data)
{
	g_print ("on_name_acquired: %s\n", name);

	MyAppNetCorpMyAppFrobber *interface = my_app_net_corp_my_app_frobber_skeleton_new ();
	my_app_net_corp_my_app_frobber_set_verbose (interface, TRUE);

	g_signal_connect (interface,
                    	  "handle-hello-world",
                    	  G_CALLBACK (handle_hello_world),
                    	  user_data);

	GError *error = NULL;
	gboolean b = 
	b = g_dbus_interface_skeleton_export (G_DBUS_INTERFACE_SKELETON (interface),
	                		      connection,
					      "/net/Corp/MyApp",
					      &error);
	if (!b)
	{
		g_print ("%s\n", error->message);
		g_clear_error (&error);
	}
}

void
on_name_lost (GDBusConnection *connection,
              const gchar *name,
              gpointer user_data)
{
	g_print ("on_name_lost: %s\n", name);
}

gboolean
handle_hello_world (MyAppNetCorpMyAppFrobber *object, 
		    GDBusMethodInvocation *invocation,
		    const gchar *arg_greeting)
{
	g_print ("handle_hello_world: %s\n", arg_greeting);
	my_app_net_corp_my_app_frobber_complete_hello_world (object,
							     invocation,
							     arg_greeting);
	return TRUE;
}

void main (void)
{
	GMainContext *context = NULL; // default context
	GMainLoop *loop = g_main_loop_new (context, FALSE);

	guint owner_id;
	owner_id = g_bus_own_name (G_BUS_TYPE_SESSION,
				     "net.Corp.MyApp",
				     G_BUS_NAME_OWNER_FLAGS_NONE,
				     on_bus_acquired,
				     on_name_acquired,
				     on_name_lost,
				     NULL,
				     NULL);
	g_main_loop_run (loop);
	g_print ("out of main loop\n");
	g_bus_unown_name(owner_id);
}
