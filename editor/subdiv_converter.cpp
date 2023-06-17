#include "subdiv_converter.h"

void SubdivConverter::_bind_methods() {
    ClassDB::bind_method(D_METHOD("convert_importer_mesh_instances_recursively", "node"), &SubdivConverter::convert_importer_mesh_instances_recursively);
}

void SubdivConverter::convert_importer_mesh_instances_recursively(Node *node) {
    for (int i = 0; i < node->get_child_count(); ++i) {
        Node *child = node->get_child(i);
        convert_importer_mesh_instances_recursively(child);

        if (Object::cast_to<ImporterMeshInstance3D>(child)) {
            importer->convert_importer_meshinstance_to_subdiv(Object::cast_to<ImporterMeshInstance3D>(child),  TopologyDataImporter::ImportMode(import_mode), subdiv_level);
        }
    }
}

SubdivConverter::SubdivConverter() {
}
