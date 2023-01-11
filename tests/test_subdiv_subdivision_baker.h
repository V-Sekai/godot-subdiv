#pragma once

#include "core/io/resource_loader.h"
#include "modules/subdiv/src/subdivision/subdivision_baker.hpp"
#include "tests/test_macros.h"

//just checks for non empty usable data
TEST_CASE("Simple bake") {
	Ref<SubdivisionBaker> baker;
	baker.instantiate();
	Ref<TopologyDataMesh> source_mesh = core_bind::ResourceLoader::get_singleton()->load("res://test/skinning_test.tres");
	Ref<ImporterMesh> importer_mesh;
	importer_mesh.instantiate();
	importer_mesh = baker->get_importer_mesh(importer_mesh, source_mesh, 2);

	Array result_arrays = importer_mesh->get_surface_arrays(0);
	CHECK(!result_arrays.is_empty());
	const PackedVector3Array &vertex_array = result_arrays[Mesh::ARRAY_VERTEX];
	int32_t vertex_amount = vertex_array.size();

	const PackedInt32Array &bones_array = result_arrays[Mesh::ARRAY_BONES];
	CHECK_EQ(bones_array.size(), vertex_amount * 4);
	const Vector<real_t> &weights_array = result_arrays[Mesh::ARRAY_WEIGHTS];
	CHECK_EQ(bones_array.size(), weights_array.size());
}