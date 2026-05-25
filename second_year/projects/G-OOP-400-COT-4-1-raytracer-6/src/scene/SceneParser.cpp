/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** SceneParser
*/


#include "../../include/scene/SceneParser.hpp"
#include "../../include/rayTracerError.hpp"
#include <filesystem>

using namespace RayTracer;

TransformData SceneParser::parse_transform(const Setting& setting)
{
    TransformData data;

    if (setting.exists("translation")) {
        const Setting& t = setting["translation"];
        data.has_translation = true;
        data.tx = (double)t["x"];
        data.ty = (double)t["y"];
        data.tz = (double)t["z"];
    }

    if (setting.exists("rotation")) {
        const Setting& r = setting["rotation"];
        data.has_rotation = true;
        data.rx = (double)r["x"];
        data.ry = (double)r["y"];
        data.rz = (double)r["z"];
    }

    return data;
}

std::vector<ConeData> SceneParser::parse_cone(const Setting& cone)
{
    std::vector<ConeData> cone_data;

    for (int i = 0; i < cone.getLength(); i++) {
        ConeData data;
        const Setting& c = cone[i];
        int r, g, b;
        c.lookupValue("x", data.x);
        c.lookupValue("y", data.y);
        c.lookupValue("z", data.z);
        c.lookupValue("r", data.r);
        c.lookupValue("height", data.height);
        const Setting& color = c["color"];
        color.lookupValue("r", r);
        color.lookupValue("g", g);
        color.lookupValue("b", b);
        data.color.r = r;
        data.color.g = g;
        data.color.b = b;
        data.transform = parse_transform(c);
        cone_data.push_back(data);
    }
    return cone_data;
}

std::vector<CylinderData> SceneParser::parse_cylinder(const Setting& cylinder)
{
    std::vector<CylinderData> cylinder_data;

    for (int i = 0; i < cylinder.getLength(); i++) {
        CylinderData data;
        const Setting& cy = cylinder[i];
        int r, g, b;
        cy.lookupValue("x", data.x);
        cy.lookupValue("y", data.y);
        cy.lookupValue("z", data.z);
        cy.lookupValue("r", data.r);
        cy.lookupValue("height", data.height);
        const Setting& color = cy["color"];
        color.lookupValue("r", r);
        color.lookupValue("g", g);
        color.lookupValue("b", b);
        data.color.r = r;
        data.color.g = g;
        data.color.b = b;
        data.transform = parse_transform(cy);
        cylinder_data.push_back(data);
    }
    return cylinder_data;
}

std::vector<PlaneData> SceneParser::parse_plane(const Setting& plane)
{
    std::vector<PlaneData> plane_data;

    for(int i = 0; i < plane.getLength(); i++) {
        PlaneData date;
        const Setting &p = plane[i];
        int r, g, b;
        p.lookupValue("position", date.position);
        p.lookupValue("axis", date.axis);
        const Setting& col = p["color"];
        col.lookupValue("r", r);
        col.lookupValue("g", g);
        col.lookupValue("b", b);
        date.color.r = r;
        date.color.g = g;
        date.color.b = b;
        date.transform = parse_transform(p);
        plane_data.push_back(date);
    }
    return plane_data;
}

std::vector<MobiusData> SceneParser::parse_mobius(const Setting& mobius) {
    std::vector<MobiusData> mobi_data;

    for (int i = 0; i < mobius.getLength(); i++) {
        MobiusData data;
        const Setting& m = mobius[i];

        m.lookupValue("x", data.x);
        m.lookupValue("y", data.y);
        m.lookupValue("z", data.z);
        m.lookupValue("R", data.R);
        m.lookupValue("w", data.W);
        const Setting& color = m["color"];
        int r, g, b;
        color.lookupValue("r", r);
        color.lookupValue("g", g);
        color.lookupValue("b", b);
        data.color.r = (double)r;
        data.color.g = (double)g;
        data.color.b = (double)b;
        data.transform = parse_transform(m);
        mobi_data.push_back(data);
    }
    return mobi_data;
}

std::vector<TriangleData> SceneParser::parse_triangle(const Setting& triangle)
{
    std::vector<TriangleData> triangle_data;

    for (int i = 0; i < triangle.getLength(); i++) {
        TriangleData data;
        const Setting& t = triangle[i];
        int r, g, b;

        const Setting& v0 = t["v0"];
        v0.lookupValue("x", data.x0);
        v0.lookupValue("y", data.y0);
        v0.lookupValue("z", data.z0);

        const Setting& v1 = t["v1"];
        v1.lookupValue("x", data.x1);
        v1.lookupValue("y", data.y1);
        v1.lookupValue("z", data.z1);

        const Setting& v2 = t["v2"];
        v2.lookupValue("x", data.x2);
        v2.lookupValue("y", data.y2);
        v2.lookupValue("z", data.z2);

        const Setting& color = t["color"];
        color.lookupValue("r", r);
        color.lookupValue("g", g);
        color.lookupValue("b", b);
        data.color.r = r;
        data.color.g = g;
        data.color.b = b;
        data.transform = parse_transform(t);
        triangle_data.push_back(data);
    }
    return triangle_data;
}

std::vector<TorusData> SceneParser::parse_torus(const Setting& torus)
{
    std::vector<TorusData> torus_data;

    for (int i = 0; i < torus.getLength(); i++) {
        TorusData data;
        const Setting& t = torus[i];
        int r, g, b, R, _r;

        t.lookupValue("x", data.x);
        t.lookupValue("y", data.y);
        t.lookupValue("z", data.z);
        t.lookupValue("R", R);
        t.lookupValue("r", _r);

        data.R = R;
        data.r = _r;
        const Setting& color = t["color"];
        color.lookupValue("r", r);
        color.lookupValue("g", g);
        color.lookupValue("b", b);
        data.color.r = r;
        data.color.g = g;
        data.color.b = b;
        data.transform = parse_transform(t);
        torus_data.push_back(data);
    }
    return torus_data;
}

std::vector<FractalData> SceneParser::parse_fractal(const Setting& fractal)
{
    std::vector<FractalData> fractal_data;

    for (int i = 0; i < fractal.getLength(); i++) {
        FractalData data;
        const Setting& f = fractal[i];
        int r, g, b;

        f.lookupValue("x", data.x);
        f.lookupValue("y", data.y);
        f.lookupValue("z", data.z);
        f.lookupValue("iterations", data.iterations);
        f.lookupValue("power", data.power);

        const Setting& color = f["color"];
        color.lookupValue("r", r);
        color.lookupValue("g", g);
        color.lookupValue("b", b);
        data.color.r = r;
        data.color.g = g;
        data.color.b = b;
        data.transform = parse_transform(f);
        fractal_data.push_back(data);
    }
    return fractal_data;
}

std::vector<SphereData> SceneParser::parse_sphere(const Setting& sphere)
{
    std::vector<SphereData> sphere_data;

    for (int i = 0; i < sphere.getLength(); ++i) {
        SphereData data;
        const Setting& s = sphere[i];
        int r, g, b;
        s.lookupValue("x", data.x);
        s.lookupValue("y", data.y);
        s.lookupValue("z", data.z);
        s.lookupValue("r", data.r);
        const Setting& col = s["color"];
        col.lookupValue("r", r);
        col.lookupValue("g", g);
        col.lookupValue("b", b);
        data.color.r = r;
        data.color.g = g;
        data.color.b = b;
        data.transform = parse_transform(s);
        sphere_data.push_back(data);
    }
    return sphere_data;
}

void SceneParser::parse_camera(const std::string& filepath) {
    Config cfg;
    cfg.readFile(filepath.c_str());
    const Setting &cam = cfg.lookup("camera");

    const Setting& res = cam["resolution"];
    res.lookupValue("width", camera_.width);
    res.lookupValue("height", camera_.height);
    const Setting& pos = cam["position"];
    pos.lookupValue("x", camera_.xp);
    pos.lookupValue("y", camera_.yp);
    pos.lookupValue("z", camera_.zp);
    const Setting& rot = cam["rotation"];
    rot.lookupValue("x", camera_.xr);
    rot.lookupValue("y", camera_.yr);
    rot.lookupValue("z", camera_.zr);
    cam.lookupValue("fieldOfView", camera_.field_of_view);  
}

std::vector<TangleCudeData> SceneParser::parse_tangleCube(const Setting& tangle)
{
    std::vector<TangleCudeData> tangle_data;

    for (int i = 0; i < tangle.getLength(); i++) {
        TangleCudeData data;
        const Setting& t = tangle[i];
        int r, g, b;
        t.lookupValue("x", data.x);
        t.lookupValue("y", data.y);
        t.lookupValue("z", data.z);
        t.lookupValue("scale", data.scale);
        const Setting& color = t["color"];
        color.lookupValue("r", r);
        color.lookupValue("g", g);
        color.lookupValue("b", b);
        data.color.r = r;
        data.color.g = g;
        data.color.b = b;
        data.transform = parse_transform(t);
        tangle_data.push_back(data);
    }
    return tangle_data;
}

void SceneParser::parse_primitive(const std::string& filepath) {
    Config cfg;
    cfg.readFile(filepath.c_str());
    const Setting &prim = cfg.lookup("primitives");

    std::vector<SphereData> sphere_data;
    if (prim.exists("spheres")) {
        _typesName.push_back("sphere");
        const Setting& sphere = prim["spheres"];
        sphere_data = parse_sphere(sphere);
    }
    std::vector<PlaneData> plane_data;
    if (prim.exists("planes")) {
        _typesName.push_back("plane");
        const Setting& plane = prim["planes"];
        plane_data = parse_plane(plane);
    }
    std::vector<ConeData> cone_data;
    if (prim.exists("cones")) {
        _typesName.push_back("cone");
        const Setting& cone = prim["cones"];
        cone_data = parse_cone(cone);
    }
    std::vector<CylinderData> cylinder_data;
    if (prim.exists("cylinders")) {
        _typesName.push_back("cylinder");
        const Setting& cylinder = prim["cylinders"];
        cylinder_data = parse_cylinder(cylinder);
    }
    std::vector<TriangleData> triangle_data;
    if (prim.exists("triangles")) {
        _typesName.push_back("triangle");
        const Setting& triangle = prim["triangles"];
        triangle_data = parse_triangle(triangle);
    }
    std::vector<MobiusData> mobius_data;
    if (prim.exists("mobius")) {
        _typesName.push_back("mobius");
        const Setting& mobi = prim["mobius"];
        mobius_data = parse_mobius(mobi);
    }

    std::vector<TorusData> torus_data;
    if (prim.exists("toruses")) {
        _typesName.push_back("torus");
        const Setting& torus = prim["toruses"];
        torus_data = parse_torus(torus);
    }

    std::vector<TangleCudeData> tangle_data;
    if (prim.exists("tanglecubes")) {
        _typesName.push_back("tangle");
        const Setting& tangle = prim["tanglecubes"];
        tangle_data = parse_tangleCube(tangle);
    }

    std::vector<FractalData> fractal_data;
    if (prim.exists("fractals")) {
        _typesName.push_back("fractal");
        const Setting& fractal = prim["fractals"];
        fractal_data = parse_fractal(fractal);
    }

    if (prim.exists("imports")) {
        const Setting& imports = prim["imports"];
        namespace fs = std::filesystem;
        fs::path base = fs::path(filepath).parent_path();
        for (int i = 0; i < imports.getLength(); i++) {
            std::string sub = imports[i].c_str();
            fs::path subPath = base / sub;
            merge_scene(subPath.string());
        }
    }
    for (auto& s : sphere_data) primitive_.sphere.push_back(s);
    for (auto& p : plane_data) primitive_.plane.push_back(p);
    for (auto& c : cylinder_data) primitive_.cylinder.push_back(c);
    for (auto& c : cone_data) primitive_.cone.push_back(c);
    for (auto& t : triangle_data) primitive_.triangle.push_back(t);
    for (auto& m : mobius_data) primitive_.mobius.push_back(m);
    for (auto& t : torus_data) primitive_.torus.push_back(t);
    for (auto& f : fractal_data) primitive_.fractal.push_back(f);
    for (auto& f : tangle_data) primitive_.tangleCube.push_back(f);
}

void SceneParser::parse_light(const std::string& filepath) {
    Config cfg;
    cfg.readFile(filepath.c_str());
    const Setting& light = cfg.lookup("lights");

    light.lookupValue("ambient", light_.ambient);
    light.lookupValue("diffuse", light_.diffuse);
    
    if (light.exists("point")) {
        std::vector<PointLightData> point_data;
        const Setting& p = light["point"];
        for (int i = 0; i < p.getLength(); i++) {
            PointLightData pt;
            const Setting& pt_s = p[i];
            pt_s.lookupValue("x", pt.x);
            pt_s.lookupValue("y", pt.y);
            pt_s.lookupValue("z", pt.z);
            pt_s.lookupValue("intensity", pt.intensity);
            if (pt_s.exists("color")) {
                int r, g, b;
                const Setting& col = pt_s["color"];
                col.lookupValue("r", r);
                col.lookupValue("g", g);
                col.lookupValue("b", b);
                pt.color.r = (double)r;
                pt.color.g = (double)g;
                pt.color.b = (double)b;
            } else {
                pt.color.r = 255;
                pt.color.g = 255;
                pt.color.b = 255;
            }
            point_data.push_back(pt);
        }
        light_.point_light = point_data;
    }
    
    if (light.exists("directional")) {
        std::vector<DirectionalLightData> directional_data;
        const Setting& d = light["directional"];
        for(int i = 0; i < d.getLength(); i++) {
            DirectionalLightData dl;
            const Setting& dl_s = d[i];
            dl_s.lookupValue("x", dl.x);
            dl_s.lookupValue("y", dl.y);
            dl_s.lookupValue("z", dl.z);
            if (dl_s.exists("color")) {
                int r, g, b;
                const Setting& col = dl_s["color"];
                col.lookupValue("r", r);
                col.lookupValue("g", g);
                col.lookupValue("b", b);
                dl.color.r = (double)r;
                dl.color.g = (double)g;
                dl.color.b = (double)b;
            } else {
                dl.color.r = 255;
                dl.color.g = 255;
                dl.color.b = 255;
            }
            directional_data.push_back(dl);
        }
        light_.directional_light = directional_data;
    }
}

void SceneParser::parse_all(const std::string& filepath) {
    Config cfg;
    cfg.readFile(filepath.c_str());

    if (cfg.exists("camera"))
        this->parse_camera(filepath);
    if (cfg.exists("lights"))
        this->parse_light(filepath);
    this->parse_primitive(filepath);
}

void SceneParser::merge_scene(const std::string& filepath)
{
    namespace fs = std::filesystem;
    if (!fs::exists(filepath))
        throw RayTracerError("Import scene introuvable : " + filepath);

    SceneParser sub;
    sub.parse_primitive(filepath);

    for (auto& s : sub.primitive_.sphere)   primitive_.sphere.push_back(s);
    for (auto& p : sub.primitive_.plane)    primitive_.plane.push_back(p);
    for (auto& c : sub.primitive_.cone)     primitive_.cone.push_back(c);
    for (auto& c : sub.primitive_.cylinder) primitive_.cylinder.push_back(c);
    for (auto& m : sub.primitive_.mobius)   primitive_.mobius.push_back(m);
    for (auto& f : sub.primitive_.fractal)  primitive_.fractal.push_back(f);
    for (auto& t : sub.primitive_.torus)    primitive_.torus.push_back(t);
    for (auto& t : sub.primitive_.triangle) primitive_.triangle.push_back(t);
    for (auto& t : sub.primitive_.tangleCube) primitive_.tangleCube.push_back(t);

    for (auto& type : sub._typesName)
        if (std::find(_typesName.begin(), _typesName.end(), type) == _typesName.end())
            _typesName.push_back(type);
}
