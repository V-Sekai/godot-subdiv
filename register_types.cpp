#include "register_types.h"

#include "core/object/class_db.h"

#include "modules/subdiv/src/import/topology_data_importer.hpp"
#include "modules/subdiv/src/resources/baked_subdiv_mesh.hpp"
#include "modules/subdiv/src/subdivision/subdivision_baker.hpp"
#include "modules/subdiv/src/subdivision/subdivision_mesh.hpp"
#include "modules/subdiv/src/subdivision/subdivision_server.hpp"
#include "src/resources/topology_data_mesh.hpp"

#include "modules/subdiv/src/subdivision/quad_subdivider.hpp"
#include "modules/subdiv/src/subdivision/subdivider.hpp"
#include "modules/subdiv/src/subdivision/triangle_subdivider.hpp"

#ifdef TESTS_ENABLED
#include "subdiv_test.hpp"
#endif

static SubdivisionServer *_subdivision_server;

void initialize_subdiv_module(ModuleInitializationLevel p_level) {
	if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE) {
		ClassDB::register_class<Subdivider>();
		ClassDB::register_class<QuadSubdivider>();
		ClassDB::register_class<TriangleSubdivider>();

		ClassDB::register_class<SubdivisionServer>();
		ClassDB::register_class<SubdivisionMesh>();
		ClassDB::register_class<SubdivisionBaker>();

		ClassDB::register_class<TopologyDataImporter>();

		ClassDB::register_class<TopologyDataMesh>();
		ClassDB::register_class<BakedSubdivMesh>();

		_subdivision_server = memnew(SubdivisionServer);
		Engine::get_singleton()->add_singleton(Engine::Singleton("SubdivisionServer", _subdivision_server));
	}
}

void uninitialize_subdiv_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		if (Engine::get_singleton()->has_singleton("SubdivisionServer") && Engine::get_singleton()->get_singleton_object("SubdivisionServer") == _subdivision_server) {
			Engine::get_singleton()->remove_singleton("SubdivisionServer");
			memdelete(_subdivision_server);
		}
	}
}
