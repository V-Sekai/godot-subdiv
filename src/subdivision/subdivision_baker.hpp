#ifndef SUBDIVISION_BAKER_H
#define SUBDIVISION_BAKER_H

#include "scene/resources/importer_mesh.h"
#include "core/object/ref_counted.h"

#include "modules/subdiv/src/resources/topology_data_mesh.hpp"

class SubdivisionBaker : public RefCounted {
	GDCLASS(SubdivisionBaker, RefCounted);

protected:
	static void _bind_methods();

public:
	Ref<ArrayMesh> get_array_mesh(const Ref<ArrayMesh> &p_base, const Ref<TopologyDataMesh> &p_topology_data_mesh, int32_t p_level, bool generate_lods, bool bake_blendshapes = false);
	Ref<ImporterMesh> get_importer_mesh(const Ref<ImporterMesh> &p_base, const Ref<TopologyDataMesh> &p_topology_data_mesh, int32_t p_level, bool bake_blendshapes = false);
	Array get_baked_arrays(const Array &topology_arrays, int32_t p_level, int64_t p_format, TopologyDataMesh::TopologyType topology_type);
	TypedArray<Array> get_baked_blend_shape_arrays(const Array &base_arrays, const Array &relative_topology_blend_shape_arrays,
			int32_t p_level, int64_t p_format, TopologyDataMesh::TopologyType topology_type);

	SubdivisionBaker();
	~SubdivisionBaker();
};

#endif
