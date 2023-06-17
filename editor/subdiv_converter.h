#pragma once

#include "core/object/ref_counted.h"

#include "scene/3d/importer_mesh_instance_3d.h"
#include "src/import/topology_data_importer.hpp"

class SubdivConverter : public RefCounted {
	GDCLASS(SubdivConverter, RefCounted);

	Ref<TopologyDataImporter> importer;
	TopologyDataImporter::ImportMode import_mode;
	int subdiv_level = 0;

protected:
	static void _bind_methods();

public:
	SubdivConverter(const TopologyDataImporter::ImportMode p_import_mode, int p_subdiv_level) {
		importer.instantiate();
		import_mode = p_import_mode;
		subdiv_level = p_subdiv_level;
	}
	void convert_importer_mesh_instances_recursively(Node *node);

	SubdivConverter();
};
