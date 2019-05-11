/* cairo - a vector graphics library with display and print output
 *
 * cairo-binary.h
 *
 * Copyright © 2005 Emmanuel Pacaud <emmanuel.pacaud@univ-poitiers.fr>
 *
 * This library is free software; you can redistribute it and/or
 * modify it either under the terms of the GNU Lesser General Public
 * License version 2.1 as published by the Free Software Foundation
 * (the "LGPL") or, at your option, under the terms of the Mozilla
 * Public License Version 1.1 (the "MPL"). If you do not alter this
 * notice, a recipient may use your version of this file under either
 * the MPL or the LGPL.
 *
 * You should have received a copy of the LGPL along with this library
 * in the file COPYING-LGPL-2.1; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Suite 500, Boston, MA 02110-1335, USA
 * You should have received a copy of the MPL along with this library
 * in the file COPYING-MPL-1.1
 *
 * The contents of this file are subject to the Mozilla Public License
 * Version 1.1 (the "License"); you may not use this file except in
 * compliance with the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY
 * OF ANY KIND, either express or implied. See the LGPL or the MPL for
 * the specific language governing rights and limitations.
 *
 */

#ifndef CAIRO_BINARY_H
#define CAIRO_BINARY_H

#include "cairo.h"

#if CAIRO_HAS_BINARY_SURFACE

CAIRO_BEGIN_DECLS

/**
 * cairo_binary_version_t:
 * @CAIRO_BINARY_VERSION_1_1: The version 1.1 of the BINARY specification. (Since 1.2)
 * @CAIRO_BINARY_VERSION_1_2: The version 1.2 of the BINARY specification. (Since 1.2)
 *
 * #cairo_binary_version_t is used to describe the version number of the BINARY
 * specification that a generated BINARY file will conform to.
 *
 * Since: 1.2
 **/
typedef enum _cairo_binary_version {
    CAIRO_BINARY_VERSION_1_1,
    CAIRO_BINARY_VERSION_1_2
} cairo_binary_version_t;

/**
 * cairo_binary_unit_t:
 *
 * @CAIRO_BINARY_UNIT_USER: User unit, a value in the current coordinate system.
 *   If used in the root element for the initial coordinate systems it
 *   corresponds to pixels. (Since 1.16)
 * @CAIRO_BINARY_UNIT_EM: The size of the element's font. (Since 1.16)
 * @CAIRO_BINARY_UNIT_EX: The x-height of the element’s font. (Since 1.16)
 * @CAIRO_BINARY_UNIT_PX: Pixels (1px = 1/96th of 1in). (Since 1.16)
 * @CAIRO_BINARY_UNIT_IN: Inches (1in = 2.54cm = 96px). (Since 1.16)
 * @CAIRO_BINARY_UNIT_CM: Centimeters (1cm = 96px/2.54). (Since 1.16)
 * @CAIRO_BINARY_UNIT_MM: Millimeters (1mm = 1/10th of 1cm). (Since 1.16)
 * @CAIRO_BINARY_UNIT_PT: Points (1pt = 1/72th of 1in). (Since 1.16)
 * @CAIRO_BINARY_UNIT_PC: Picas (1pc = 1/6th of 1in). (Since 1.16)
 * @CAIRO_BINARY_UNIT_PERCENT: Percent, a value that is some fraction of another
 *   reference value. (Since 1.16)
 *
 * #cairo_binary_unit_t is used to describe the units valid for coordinates and
 * lengths in the BINARY specification.
 *
 * See also:
 * https://www.w3.org/TR/BINARY/coords.html#Units
 * https://www.w3.org/TR/BINARY/types.html#DataTypeLength
 * https://www.w3.org/TR/css-values-3/#lengths
 *
 * Since: 1.16
 **/
typedef enum _cairo_binary_unit {
    CAIRO_BINARY_UNIT_USER = 0,
    CAIRO_BINARY_UNIT_EM,
    CAIRO_BINARY_UNIT_EX,
    CAIRO_BINARY_UNIT_PX,
    CAIRO_BINARY_UNIT_IN,
    CAIRO_BINARY_UNIT_CM,
    CAIRO_BINARY_UNIT_MM,
    CAIRO_BINARY_UNIT_PT,
    CAIRO_BINARY_UNIT_PC,
    CAIRO_BINARY_UNIT_PERCENT
} cairo_binary_unit_t;

cairo_public cairo_surface_t *
cairo_binary_surface_create (const char   *filename,
			  double	width_in_points,
			  double	height_in_points);

cairo_public cairo_surface_t *
cairo_binary_surface_create_for_stream (cairo_write_func_t	write_func,
				     void	       *closure,
				     double		width_in_points,
				     double		height_in_points);

cairo_public void
cairo_binary_surface_restrict_to_version (cairo_surface_t 		*surface,
				       cairo_binary_version_t  	 version);

cairo_public void
cairo_binary_get_versions (cairo_binary_version_t const	**versions,
                        int                      	 *num_versions);

cairo_public const char *
cairo_binary_version_to_string (cairo_binary_version_t version);

cairo_public void
cairo_binary_surface_set_document_unit (cairo_surface_t	*surface,
				     cairo_binary_unit_t	 unit);

cairo_public cairo_binary_unit_t
cairo_binary_surface_get_document_unit (cairo_surface_t	*surface);

CAIRO_END_DECLS

#else  /* CAIRO_HAS_BINARY_SURFACE */
# error Cairo was not compiled with support for the binary backend
#endif /* CAIRO_HAS_BINARY_SURFACE */

#endif /* CAIRO_BINARY_H */
