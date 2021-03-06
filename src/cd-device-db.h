/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*-
 *
 * Copyright (C) 2011 Richard Hughes <richard@hughsie.com>
 *
 * Licensed under the GNU General Public License Version 2
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef __CD_DEVICE_DB_H
#define __CD_DEVICE_DB_H

#include <glib-object.h>

G_BEGIN_DECLS

#define CD_TYPE_DEVICE_DB (cd_device_db_get_type ())
G_DECLARE_DERIVABLE_TYPE (CdDeviceDb, cd_device_db, CD, DEVICE_DB, GObject)

struct _CdDeviceDbClass
{
	GObjectClass	parent_class;
};

CdDeviceDb	*cd_device_db_new		(void);

gboolean	 cd_device_db_load		(CdDeviceDb	*ddb,
						 const gchar	*filename,
						 GError		**error)
						 G_GNUC_WARN_UNUSED_RESULT;
gboolean	 cd_device_db_empty		(CdDeviceDb	*ddb,
						 GError		**error)
						 G_GNUC_WARN_UNUSED_RESULT;
gboolean	 cd_device_db_add		(CdDeviceDb	*ddb,
						 const gchar	*device_id,
						 GError		**error)
						 G_GNUC_WARN_UNUSED_RESULT;
gboolean	 cd_device_db_set_property	(CdDeviceDb	*ddb,
						 const gchar	*device_id,
						 const gchar	*property,
						 const gchar	*value,
						 GError		**error)
						 G_GNUC_WARN_UNUSED_RESULT;
gchar		*cd_device_db_get_property	(CdDeviceDb	*ddb,
						 const gchar	*device_id,
						 const gchar	*property,
						 GError		**error)
						 G_GNUC_WARN_UNUSED_RESULT;
gboolean	 cd_device_db_remove		(CdDeviceDb	*ddb,
						 const gchar	*device_id,
						 GError		**error)
						 G_GNUC_WARN_UNUSED_RESULT;
GPtrArray	*cd_device_db_get_devices	(CdDeviceDb	*ddb,
						 GError		**error)
						 G_GNUC_WARN_UNUSED_RESULT;
GPtrArray	*cd_device_db_get_properties	(CdDeviceDb	*ddb,
						 const gchar	*device_id,
						 GError		**error)
						 G_GNUC_WARN_UNUSED_RESULT;

G_END_DECLS

#endif /* __CD_DEVICE_DB_H */
