#pragma once

#include "core/error/error_list.h"
#include "editor/editor_plugin.h"
#include "editor/import/editor_import_plugin.h"
#include "modules/gltf/extensions/gltf_document_extension.h"
#include "modules/gltf/gltf_document.h"

#include "scene/3d/importer_mesh_instance_3d.h"
#include "subdiv_converter.h"

class GodotSubdivImporter;

class SubdivEditorPlugin : public EditorPlugin {
	GDCLASS(SubdivEditorPlugin, EditorPlugin);

protected:
	Ref<GodotSubdivImporter> resource_import_plugin;

public:
	SubdivEditorPlugin() {
		resource_import_plugin.instantiate();
		add_import_plugin(resource_import_plugin);
	}
};

class GodotSubdivImporter : public EditorImportPlugin {
	GDCLASS(GodotSubdivImporter, EditorImportPlugin);

protected:
	static void _bind_methods();

public:
	String get_importer_name() const override;
	String get_visible_name() const override;
	virtual void get_recognized_extensions(List<String> *p_extensions) const override;

	String get_save_extension() const override;
	String get_resource_type() const override;
	int get_preset_count() const override;
	String get_preset_name(int preset) const override;
	float get_priority() const override;
	int get_import_order() const override;
	virtual bool get_option_visibility(const String &p_path, const String &p_option, const HashMap<StringName, Variant> &p_options) const;
	virtual void get_import_options(const String &p_path, List<ImportOption> *r_options, int p_preset) const override;

	Error import(const String &p_source_file, const String &p_save_path, const HashMap<StringName, Variant> &p_options, List<String> *r_platform_variants, List<String> *r_gen_files, Variant *r_metadata = nullptr) override;

	GodotSubdivImporter();
};

class GLTFDocumentExtensionSubdiv : public GLTFDocumentExtension {
public:
	virtual Error import_node(Ref<GLTFState> p_state, Ref<GLTFNode> p_gltf_node, Dictionary &r_json, Node *p_node) {
		Ref<SubdivConverter> subdiv_converter = Ref<SubdivConverter>(memnew(SubdivConverter(TopologyDataImporter::ImportMode::IMPORTER_MESH, 1)));
		if (Object::cast_to<ImporterMeshInstance3D>(p_node)) {
			subdiv_converter->convert_importer_mesh_instances_recursively(p_node);
			return OK;
		}
		return OK;
	}
};