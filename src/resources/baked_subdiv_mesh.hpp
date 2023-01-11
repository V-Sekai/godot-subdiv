#ifndef BAKED_SUBDIV_MESH_H
#define BAKED_SUBDIV_MESH_H

#include "core/io/resource.h"
#include "core/object/class_db.h"
#include "scene/resources/material.h"
#include "scene/resources/mesh.h"

class TopologyDataMesh;

//Uses a TopologyDataMesh in the background to function like a Mesh
class BakedSubdivMesh : public ArrayMesh {
	GDCLASS(BakedSubdivMesh, ArrayMesh);

protected:
	Ref<TopologyDataMesh> data_mesh;
	int subdiv_level = 0;
	void _update_subdiv();
	void _clear();

	bool _set(const StringName &p_name, const Variant &p_value);
	bool _get(const StringName &p_name, Variant &r_ret) const;

	static void _bind_methods();

public:
	void set_data_mesh(Ref<TopologyDataMesh> p_data_mesh);
	Ref<TopologyDataMesh> get_data_mesh() const;
	void set_subdiv_level(int p_level);
	int get_subdiv_level() const;
	BakedSubdivMesh();
	~BakedSubdivMesh();
};

#endif