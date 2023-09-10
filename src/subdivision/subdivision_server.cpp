/**************************************************************************/
/*  subdivision_server.cpp                                                */
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

#include "subdivision_server.hpp"

#include "core/object/class_db.h"
#include "subdivision_mesh.hpp"

#include "../resources/topology_data_mesh.hpp"

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
	ClassDB::bind_static_method("SubdivisionServer", D_METHOD("create_subdivision_mesh", "mesh", "level"), &SubdivisionServer::create_subdivision_mesh);
	ClassDB::bind_static_method("SubdivisionServer", D_METHOD("create_subdivision_mesh_with_rid", "mesh", "level", "rid"), &SubdivisionServer::create_subdivision_mesh_with_rid);
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
