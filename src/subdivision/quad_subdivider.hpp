#ifndef QUAD_SUBDIVIDER_H
#define QUAD_SUBDIVIDER_H

#include "core/object/ref_counted.h"

#include "subdivider.hpp"

class QuadSubdivider : public Subdivider {
	GDCLASS(QuadSubdivider, Subdivider);

public:
	QuadSubdivider();
	~QuadSubdivider();

protected:
	static void _bind_methods();
	virtual OpenSubdiv::Sdc::SchemeType _get_refiner_type() const override;
	virtual Array _get_triangle_arrays() const override;
	virtual Vector<int> _get_face_vertex_count() const override;
	virtual int32_t _get_vertices_per_face_count() const override;
	virtual Array _get_direct_triangle_arrays() const override;
};

#endif