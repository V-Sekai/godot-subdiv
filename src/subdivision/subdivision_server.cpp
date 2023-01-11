#include "subdivision_server.hpp"

#include "core/object/class_db.h"
#include "subdivision_mesh.hpp"

#include "modules/subdiv/src/resources/topology_data_mesh.hpp"

SubdivisionServer *SubdivisionServer::singleton = nullptr;

SubdivisionServer *SubdivisionServer::get_singleton() {
	return singleton;
}

SubdivisionServer::SubdivisionServer() {
	singleton = this;
}

SubdivisionServer::~SubdivisionServer() {
	singleton = nullptr;
}

void SubdivisionServer::_bind_methods() {
	ClassDB::bind_static_method("SubdivisionServer", D_METHOD("get_singleton"), &SubdivisionServer::get_singleton);
	ClassDB::bind_method(D_METHOD("create_subdivision_mesh", "mesh", "level"), &SubdivisionServer::create_subdivision_mesh);
	ClassDB::bind_method(D_METHOD("create_subdivision_mesh_with_rid", "mesh", "level", "rid"), &SubdivisionServer::create_subdivision_mesh_with_rid);
}

Ref<SubdivisionMesh> SubdivisionServer::create_subdivision_mesh(const Ref<TopologyDataMesh> &p_mesh, int32_t p_level) {
	Ref<SubdivisionMesh> subdiv_mesh;
	subdiv_mesh.instantiate();
	subdiv_mesh->update_subdivision(p_mesh, p_level);

	return subdiv_mesh;
}

Ref<SubdivisionMesh> SubdivisionServer::create_subdivision_mesh_with_rid(const Ref<TopologyDataMesh> &p_mesh, int32_t p_level, RID p_rid) {
	Ref<SubdivisionMesh> subdiv_mesh;
	subdiv_mesh.instantiate();
	subdiv_mesh->set_rid(p_rid);
	subdiv_mesh->update_subdivision(p_mesh, p_level);
	return subdiv_mesh;
}

