#ifndef SUBDIVISION_SERVER_H
#define SUBDIVISION_SERVER_H

#include "core/object/class_db.h"
#include "core/object/object.h"
#include "core/templates/hash_map.h"

class SubdivisionMesh;
class TopologyDataMesh;

class SubdivisionServer : public Object {
	GDCLASS(SubdivisionServer, Object);
	static SubdivisionServer *singleton;

protected:
	static void _bind_methods();

public:
	static SubdivisionServer *get_singleton();
	Ref<SubdivisionMesh> create_subdivision_mesh(const Ref<TopologyDataMesh> &p_mesh, int32_t p_level);
	Ref<SubdivisionMesh> create_subdivision_mesh_with_rid(const Ref<TopologyDataMesh> &p_mesh, int32_t p_level, RID p_rid);
	SubdivisionServer();
	~SubdivisionServer();
};

#endif