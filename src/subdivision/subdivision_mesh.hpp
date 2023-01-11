#ifndef SUBDIVISION_MESH_H
#define SUBDIVISION_MESH_H

#include "scene/resources/mesh.h"
#include "scene/3d/mesh_instance_3d.h"

#include "core/templates/hash_map.h"

#include "modules/subdiv/src/resources/topology_data_mesh.hpp"

//SubdivisionMesh is only for subdividing ImporterQuadMeshes
class SubdivisionMesh : public RefCounted {
	GDCLASS(SubdivisionMesh, RefCounted);
	RID source_mesh; //ImporterQuadMesh
	RID subdiv_mesh; //generated triangle mesh

	int current_level = -1;

protected:
	static void _bind_methods();
	Array _get_subdivided_arrays(const Array &p_arrays, int p_level, int32_t p_format, bool calculate_normals, TopologyDataMesh::TopologyType topology_type);

	Vector<int64_t> subdiv_vertex_count; //variables used for compatibility with mesh
	Vector<int64_t> subdiv_index_count;

public:
	SubdivisionMesh();
	~SubdivisionMesh();

	RID get_rid() const;
	void set_rid(RID p_rid);
	void update_subdivision(Ref<TopologyDataMesh> p_mesh, int p_level);
	void _update_subdivision(Ref<TopologyDataMesh> p_mesh, int p_level, const Vector<Array> &cached_data_arrays);
	void update_subdivision_vertices(int p_surface, const PackedVector3Array &new_vertex_array,
			const PackedInt32Array &index_array, TopologyDataMesh::TopologyType topology_type);
	void clear();

	int64_t surface_get_vertex_array_size(int p_surface) const;
	int64_t surface_get_index_array_size(int p_surface) const;
};

#endif