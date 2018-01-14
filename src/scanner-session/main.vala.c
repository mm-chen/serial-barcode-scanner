/* main.vala.c generated by valac 0.34.7, the Vala compiler
 * generated from main.vala, do not modify */

/* Copyright 2013, Sebastian Reichel <sre@ring0.de>
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <glib.h>
#include <glib-object.h>
#include <gio/gio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


#define TYPE_SCANNER_SESSION_IMPLEMENTATION (scanner_session_implementation_get_type ())
#define SCANNER_SESSION_IMPLEMENTATION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_SCANNER_SESSION_IMPLEMENTATION, ScannerSessionImplementation))
#define SCANNER_SESSION_IMPLEMENTATION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_SCANNER_SESSION_IMPLEMENTATION, ScannerSessionImplementationClass))
#define IS_SCANNER_SESSION_IMPLEMENTATION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_SCANNER_SESSION_IMPLEMENTATION))
#define IS_SCANNER_SESSION_IMPLEMENTATION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_SCANNER_SESSION_IMPLEMENTATION))
#define SCANNER_SESSION_IMPLEMENTATION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_SCANNER_SESSION_IMPLEMENTATION, ScannerSessionImplementationClass))

typedef struct _ScannerSessionImplementation ScannerSessionImplementation;
typedef struct _ScannerSessionImplementationClass ScannerSessionImplementationClass;
#define _scanner_session_implementation_unref0(var) ((var == NULL) ? NULL : (var = (scanner_session_implementation_unref (var), NULL)))
#define _g_main_loop_unref0(var) ((var == NULL) ? NULL : (var = (g_main_loop_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))


extern ScannerSessionImplementation* session;
ScannerSessionImplementation* session = NULL;

gpointer scanner_session_implementation_ref (gpointer instance);
void scanner_session_implementation_unref (gpointer instance);
GParamSpec* param_spec_scanner_session_implementation (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void value_set_scanner_session_implementation (GValue* value, gpointer v_object);
void value_take_scanner_session_implementation (GValue* value, gpointer v_object);
gpointer value_get_scanner_session_implementation (const GValue* value);
GType scanner_session_implementation_get_type (void) G_GNUC_CONST;
guint scanner_session_implementation_register_object (void* object, GDBusConnection* connection, const gchar* path, GError** error);
gint _vala_main (gchar** args, int args_length1);
void on_bus_aquired (GDBusConnection* con);
static void _on_bus_aquired_gbus_acquired_callback (GDBusConnection* connection, const gchar* name, gpointer self);
static void __lambda4_ (void);
static void ___lambda4__gbus_name_acquired_callback (GDBusConnection* connection, const gchar* name, gpointer self);
static void __lambda5_ (void);
static void ___lambda5__gbus_name_lost_callback (GDBusConnection* connection, const gchar* name, gpointer self);
ScannerSessionImplementation* scanner_session_implementation_new (void);
ScannerSessionImplementation* scanner_session_implementation_construct (GType object_type);


static void _on_bus_aquired_gbus_acquired_callback (GDBusConnection* connection, const gchar* name, gpointer self) {
	on_bus_aquired (connection);
}


static void __lambda4_ (void) {
}


static void ___lambda4__gbus_name_acquired_callback (GDBusConnection* connection, const gchar* name, gpointer self) {
	__lambda4_ ();
}


static void __lambda5_ (void) {
	FILE* _tmp0_ = NULL;
	_tmp0_ = stderr;
	fprintf (_tmp0_, "Could not aquire name\n");
}


static void ___lambda5__gbus_name_lost_callback (GDBusConnection* connection, const gchar* name, gpointer self) {
	__lambda5_ ();
}


gint _vala_main (gchar** args, int args_length1) {
	gint result = 0;
	ScannerSessionImplementation* _tmp0_ = NULL;
	GMainLoop* _tmp1_ = NULL;
	GMainLoop* _tmp2_ = NULL;
	g_bus_own_name_with_closures (G_BUS_TYPE_SYSTEM, "io.mainframe.shopsystem.ScannerSession", G_BUS_NAME_OWNER_FLAGS_NONE, (GClosure*) ((_on_bus_aquired_gbus_acquired_callback == NULL) ? NULL : g_cclosure_new ((GCallback) _on_bus_aquired_gbus_acquired_callback, NULL, (GClosureNotify) NULL)), (GClosure*) ((___lambda4__gbus_name_acquired_callback == NULL) ? NULL : g_cclosure_new ((GCallback) ___lambda4__gbus_name_acquired_callback, NULL, (GClosureNotify) NULL)), (GClosure*) ((___lambda5__gbus_name_lost_callback == NULL) ? NULL : g_cclosure_new ((GCallback) ___lambda5__gbus_name_lost_callback, NULL, (GClosureNotify) NULL)));
	_tmp0_ = scanner_session_implementation_new ();
	_scanner_session_implementation_unref0 (session);
	session = _tmp0_;
	_tmp1_ = g_main_loop_new (NULL, FALSE);
	_tmp2_ = _tmp1_;
	g_main_loop_run (_tmp2_);
	_g_main_loop_unref0 (_tmp2_);
	result = 0;
	return result;
}


int main (int argc, char ** argv) {
#if !GLIB_CHECK_VERSION (2,35,0)
	g_type_init ();
#endif
	return _vala_main (argv, argc);
}


void on_bus_aquired (GDBusConnection* con) {
	GError * _inner_error_ = NULL;
	g_return_if_fail (con != NULL);
	{
		GDBusConnection* _tmp0_ = NULL;
		ScannerSessionImplementation* _tmp1_ = NULL;
		_tmp0_ = con;
		_tmp1_ = session;
		scanner_session_implementation_register_object (_tmp1_, _tmp0_, "/io/mainframe/shopsystem/scanner_session", &_inner_error_);
		if (G_UNLIKELY (_inner_error_ != NULL)) {
			if (_inner_error_->domain == G_IO_ERROR) {
				goto __catch0_g_io_error;
			}
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return;
		}
	}
	goto __finally0;
	__catch0_g_io_error:
	{
		GError* e = NULL;
		FILE* _tmp2_ = NULL;
		e = _inner_error_;
		_inner_error_ = NULL;
		_tmp2_ = stderr;
		fprintf (_tmp2_, "Could not register service\n");
		_g_error_free0 (e);
	}
	__finally0:
	if (G_UNLIKELY (_inner_error_ != NULL)) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
}


