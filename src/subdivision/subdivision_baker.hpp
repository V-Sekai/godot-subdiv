/**************************************************************************/
/*  subdivision_baker.hpp                                                 */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             GODOT ENGINE                               */
/*                        https://godotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

#pragma once

#include "core/object/ref_counted.h"
#include "scene/resources/3d/importer_mesh.h"

#include "../resources/topology_data_mesh.hpp"

class SubdivisionBaker : public RefCounted {
	GDCLASS(SubdivisionBaker, RefCounted);

protected:
	static void _bind_methods();

public:
	Ref<ImporterMesh> get_importer_mesh(const Ref<ImporterMesh> &p_base, const Ref<TopologyDataMesh> &p_topology_data_mesh, int32_t p_level, bool bake_blendshapes = false);
	Array get_baked_arrays(const Array &topology_arrays, int32_t p_level, int64_t p_format, int topology_type);
	TypedArray<Array> get_baked_blend_shape_arrays(const Array &base_arrays, const Array &relative_topology_blend_shape_arrays,
			int32_t p_level, int64_t p_format, int topology_type);

	SubdivisionBaker();
	~SubdivisionBaker();
};
