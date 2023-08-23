#pragma once

#include "editor/editor_plugin.h"
#include "editor/import/editor_import_plugin.h"
#include "modules/gltf/gltf_document.h"

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
	virtual bool get_option_visibility(const String &p_path, const String &p_option, const HashMap<StringName, Variant> &p_options) const override;
	virtual void get_import_options(const String &p_path, List<ImportOption> *r_options, int p_preset) const override;

	Error import(const String &p_source_file, const String &p_save_path, const HashMap<StringName, Variant> &p_options, List<String> *r_platform_variants, List<String> *r_gen_files, Variant *r_metadata = nullptr) override;

	GodotSubdivImporter();
};
