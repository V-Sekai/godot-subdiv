#ifndef TOPOLOGY_DATA_IMPORTER_H
#define TOPOLOGY_DATA_IMPORTER_H

#include "core/object/object.h"
#include "core/templates/hash_map.h"
#include "scene/3d/importer_mesh_instance_3d.h"
#include "scene/3d/mesh_instance_3d.h"
#include "scene/resources/mesh.h"

#include "../resources/topology_data_mesh.hpp"

class TopologyDataImporter : public RefCounted {
	GDCLASS(TopologyDataImporter, RefCounted);

protected:
	static void _bind_methods();

public:
	enum ImportMode {
		BAKED_SUBDIV_MESH = 0,
		IMPORTER_MESH,
	};

private:
	struct TopologySurfaceData {
		PackedVector3Array vertex_array;
		PackedVector3Array normal_array;
		PackedVector2Array uv_array;
		PackedInt32Array index_array;
		PackedInt32Array bones_array;
		Vector<float> weights_array;
	};

	struct SurfaceVertexArrays { //of imported triangle mesh
		PackedVector3Array vertex_array;
		PackedVector3Array normal_array;
		PackedInt32Array index_array;
		PackedVector2Array uv_array;
		PackedInt32Array bones_array; //could be float or int array after docs
		Vector<float> weights_array;
		SurfaceVertexArrays(const Array &p_mesh_arrays);
		SurfaceVertexArrays(){};
	};

	TopologyDataImporter::TopologySurfaceData _remove_duplicate_vertices(const SurfaceVertexArrays &surface, int32_t format);
	Array _generate_packed_blend_shapes(const Array &tri_blend_shapes,
			const PackedInt32Array &mesh_index_array, const PackedVector3Array &mesh_vertex_array);
	bool _merge_to_quads(PackedInt32Array &index_array, PackedVector2Array &uv_array, int32_t format);
	PackedInt32Array _generate_uv_index_array(PackedVector2Array &uv_array);
	TopologyDataMesh::TopologyType _generate_topology_surface_arrays(const SurfaceVertexArrays &surface, int32_t format, Array &surface_arrays);

	int32_t generate_fake_format(const Array &arrays) const;
	MeshInstance3D *_replace_importer_mesh_instance_with_mesh_instance(ImporterMeshInstance3D * importer_mesh_instance);

public:
	TopologyDataImporter();
	~TopologyDataImporter();

	void convert_importer_meshinstance_to_subdiv(ImporterMeshInstance3D *importer_mesh_instance, ImportMode import_mode, int32_t subdiv_level);
};

VARIANT_ENUM_CAST(TopologyDataImporter::ImportMode);

#endif