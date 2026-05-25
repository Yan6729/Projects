/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** SceneBuilder
*/

#include "../../include/scene/SceneBuilder.hpp"
namespace RayTracer {
    SceneBuilder::SceneBuilder(PluginFactory<IPrimitive>& primitive_factory, PluginFactory<ILight>& light_factory)
        : primitive_factory_(primitive_factory), light_factory_(light_factory) {}

    static Mat4 buildTransformMatrix(const TransformData& data) {
        Mat4 m = RayTracer::identity();
        if (data.has_rotation) {
            m = rotationZ(data.rz * M_PI / 180.0) * m;
            m = vrotationY(data.ry * M_PI / 180.0) * m;
            m = rotationX(data.rx * M_PI / 180.0) * m;
        }
        if (data.has_translation) {
            m = translation(data.tx, data.ty, data.tz) * m;
        }
        return m;
    }

    Scene SceneBuilder::build(const SceneParser& parser) {
        Scene scene;

        buildPrimitives(scene, parser);
        buildLights(scene, parser);
        scene.primitives_presents = parser._typesName;
        return scene;
    }

    void SceneBuilder::buildPrimitives(Scene& scene, const SceneParser& parser) {
        for (const auto& tangle : parser.primitive_.tangleCube) {
            auto primitive = primitive_factory_.create("tangle");
            primitive->configure({
                {"x", (double)tangle.x}, {"y", (double)tangle.y}, {"z", (double)tangle.z}, {"color.r", (double)tangle.color.r},
                {"color.g", (double)tangle.color.g}, {"color.b", (double)tangle.color.b}, {"scale", (double)tangle.scale }
            });
            
            if (tangle.transform.has_translation || tangle.transform.has_rotation) {
                Mat4 m = buildTransformMatrix(tangle.transform);
                auto transformed = std::make_unique<TransformedPrimitive>(std::move(primitive), m);
                scene.addPrimitive("tangle", std::move(transformed));
            } else {
                scene.addPrimitive("tangle", std::move(primitive));
            }
        }
        
        for (const auto& sphere : parser.primitive_.sphere) {
            auto primitive = primitive_factory_.create("sphere");
            primitive->configure({
                {"x", (double)sphere.x}, {"y", (double)sphere.y}, {"z", (double)sphere.z}, {"r", (double)sphere.r},
                {"color.r", (double)sphere.color.r}, {"color.g", (double)sphere.color.g}, {"color.b", (double)sphere.color.b}
            });
            
            if (sphere.transform.has_translation || sphere.transform.has_rotation) {
                Mat4 m = buildTransformMatrix(sphere.transform);
                auto transformed = std::make_unique<TransformedPrimitive>(std::move(primitive), m);
                scene.addPrimitive("sphere", std::move(transformed));
            } else {
                scene.addPrimitive("sphere", std::move(primitive));
            }
        }

        for (const auto& cone : parser.primitive_.cone) {
            auto primitive = primitive_factory_.create("cone");
            primitive->configure({
                {"x", (double)cone.x}, {"y", (double)cone.y}, {"z", (double)cone.z}, {"r", (double)cone.r}, {"height", (double)cone.height},
                {"color.r", (double)cone.color.r}, {"color.g", (double)cone.color.g}, {"color.b", (double)cone.color.b}
            });
            
            if (cone.transform.has_translation || cone.transform.has_rotation) {
                Mat4 m = buildTransformMatrix(cone.transform);
                auto transformed = std::make_unique<TransformedPrimitive>(std::move(primitive), m);
                scene.addPrimitive("cone", std::move(transformed));
            } else {
                scene.addPrimitive("cone", std::move(primitive));
            }
        }

        for (const auto& cylinder : parser.primitive_.cylinder) {
            auto primitive = primitive_factory_.create("cylinder");
            primitive->configure({
                {"x", (double)cylinder.x}, {"y", (double)cylinder.y}, {"z", (double)cylinder.z}, {"r", (double)cylinder.r},
                {"height", (double)cylinder.height}, {"color.r", (double)cylinder.color.r}, {"color.g", (double)cylinder.color.g}, {"color.b", (double)cylinder.color.b}
            });
            
            if (cylinder.transform.has_translation || cylinder.transform.has_rotation) {
                Mat4 m = buildTransformMatrix(cylinder.transform);
                auto transformed = std::make_unique<TransformedPrimitive>(std::move(primitive), m);
                scene.addPrimitive("cylinder", std::move(transformed));
            } else {
                scene.addPrimitive("cylinder", std::move(primitive));
            }
        }

        for (const auto& triangle : parser.primitive_.triangle) {
            auto primitive = primitive_factory_.create("triangle");
            primitive->configure({
                {"x0", triangle.x0}, {"y0", triangle.y0}, {"z0", triangle.z0},
                {"x1", triangle.x1}, {"y1", triangle.y1}, {"z1", triangle.z1},
                {"x2", triangle.x2}, {"y2", triangle.y2}, {"z2", triangle.z2},
                {"color.r", (double)triangle.color.r},
                {"color.g", (double)triangle.color.g},
                {"color.b", (double)triangle.color.b}
            });

            if (triangle.transform.has_translation || triangle.transform.has_rotation) {
            Mat4 m = buildTransformMatrix(triangle.transform);
            auto transformed = std::make_unique<TransformedPrimitive>(std::move(primitive), m);
            scene.addPrimitive("triangle", std::move(transformed));
            } else {
                scene.addPrimitive("triangle", std::move(primitive));
            }
        }
        
        for (const auto& torus : parser.primitive_.torus) {
             auto primitive = primitive_factory_.create("torus");
            primitive->configure({
            {"x", torus.x}, {"y", torus.y}, {"z", torus.z},
            {"R", torus.R},
            {"r", torus.r},
            {"color.r", (double)torus.color.r},
            {"color.g", (double)torus.color.g},
            {"color.b", (double)torus.color.b}
        });

        if (torus.transform.has_translation || torus.transform.has_rotation) {
        Mat4 m = buildTransformMatrix(torus.transform);
        auto transformed = std::make_unique<TransformedPrimitive>(std::move(primitive), m);
        scene.addPrimitive("torus", std::move(transformed));
        } else {
            scene.addPrimitive("torus", std::move(primitive));
        }
        }

        for (const auto& mob : parser.primitive_.mobius) {
            auto primitive = primitive_factory_.create("mobius");
            primitive->configure({{"x", mob.x}, {"y", mob.y}, {"z", mob.z},
                {"R", mob.R}, {"w", mob.W}, {"color.r", mob.color.r},
                {"color.g", mob.color.g}, {"color.b", mob.color.b}
            });
            if (mob.transform.has_translation || mob.transform.has_rotation) {
                Mat4 m = buildTransformMatrix(mob.transform);
                auto transformed = std::make_unique<TransformedPrimitive>(std::move(primitive), m);
                scene.addPrimitive("mobius", std::move(transformed));
            } else {
                scene.addPrimitive("mobius", std::move(primitive));
            }
        }

        for (const auto& plane : parser.primitive_.plane) {
            auto primitive = primitive_factory_.create("plane");
            Vec3 normal = {0, 0, 0};
            Vec3 center = {0, 0, 0};
            if (plane.axis == "X") {
                normal.x = 1;
                center.x = (double)plane.position;
            } else if (plane.axis == "Y") {
                normal.y = 1;
                center.y = (double)plane.position;
            } else if (plane.axis == "Z") {
                normal.z = 1;
                center.z = (double)plane.position;
            }
            primitive->configure({
                {"c.x", center.x}, {"c.y", center.y}, {"c.z", center.z},
                {"n.x", normal.x}, {"n.y", normal.y}, {"n.z", normal.z},
                {"color.r", plane.color.r}, {"color.g", plane.color.g}, {"color.b", plane.color.b}
            });
            
            if (plane.transform.has_translation || plane.transform.has_rotation) {
                Mat4 m = buildTransformMatrix(plane.transform);
                auto transformed = std::make_unique<TransformedPrimitive>(std::move(primitive), m);
                scene.addPrimitive("plane", std::move(transformed));
            } else {
                scene.addPrimitive("plane", std::move(primitive));
            }
        }

        for (const auto& frac : parser.primitive_.fractal) {
            auto primitive = primitive_factory_.create("fractal");
            primitive->configure({
                {"x", frac.x}, {"y", frac.y}, {"z", frac.z},
                {"iterations", (double)frac.iterations}, {"power", frac.power},
                {"color.r", frac.color.r}, {"color.g", frac.color.g}, {"color.b", frac.color.b}
            });
            if (frac.transform.has_translation || frac.transform.has_rotation) {
                Mat4 m = buildTransformMatrix(frac.transform);
                auto transformed = std::make_unique<TransformedPrimitive>(std::move(primitive), m);
                scene.addPrimitive("fractal", std::move(transformed));
            } else {
                scene.addPrimitive("fractal", std::move(primitive));
            }
        }
    }

    void SceneBuilder::buildLights(Scene& scene, const SceneParser& parser) {
        scene.addLight(
            "ambient",
            std::make_unique<AmbientLight>(parser.light_.ambient));

        for (const auto& dir : parser.light_.directional_light) {
            const Vec3 direction(
                static_cast<double>(dir.x),
                static_cast<double>(dir.y),
                static_cast<double>(dir.z));
            auto directonal = make_unique<DirectionalLight>(direction, parser.light_.diffuse);
            directonal->_color = Color::fromRGB255(dir.color.r, dir.color.g, dir.color.b);
            scene.addLight(
                "directional",
                std::move(directonal));
        }
            for (const auto& pt : parser.light_.point_light) {
                const Vec3 direction (
                        static_cast<double>(pt.x),
                        static_cast<double>(pt.y),
                        static_cast<double>(pt.z));
                auto point = make_unique<PointLight>(direction, pt.intensity);
                point->_color = Color::fromRGB255(pt.color.r, pt.color.g, pt.color.b);
                scene.addLight(
                    "point",
                    std::move(point));
            }
    }
}

std::ostream& RayTracer::operator<<(std::ostream& os, const Color& v)
{
    return os << (int)v.r << " " << (int)v.g << " " << (int)v.b << " ";
}
