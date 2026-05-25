##
## EPITECH PROJECT, 2026
## snd_year_projects
## File description:
## Makefile
##

CPP	=	g++

CPPFLAGS	=	-I./include

LIBFLAGS	=	-Wall -Wextra -Werror -std=c++20 $(CPPFLAGS) -fPIC -fno-gnu-unique -shared
LIB_DIR	=	plugins

FLAGS	= -Wall -Wextra -std=c++20 $(CPPFLAGS)

SRC =	src/main.cpp							\
		src/rayTracerError.cpp					\
		src/reSf/ModifiedWindow.cpp				\
		src/reSf/Button.cpp						\
		src/math/Mat4.cpp						\
		src/math/Mat4Factories.cpp				\
		src/math/Mat4Transform.cpp				\
		src/math/Ray.cpp						\
		src/math/Vec3.cpp						\
		src/renderer/LoadFiles.cpp				\
		src/math/Vec3Operators.cpp				\
		src/math/Vec3Utils.cpp					\
		src/scene/SceneBuilder.cpp				\
		src/scene/SceneParser.cpp				\
		src/scene/Scene.cpp						\
		src/primitives/HitRecord.cpp			\
		src/primitives/TransformedPrimitives.cpp\
		src/renderer/Renderer.cpp				\
		src/renderer/OutputFactorie.cpp			\
		src/camera/Camera.cpp					\
		src/camera/Rectangle3D.cpp				\
		src/renderer/PpmOutput.cpp				\
		src/renderer/SfmlOutput.cpp				\
		src/plugins/PluginLoader.cpp			\
		src/renderer/FrameBuffer.cpp			\
		src/lights/Color.cpp					\
		src/lights/AmbientLight.cpp				\
		src/lights/DirectionalLight.cpp			\
		src/lights/Lighting.cpp					\
		src/lights/PointLight.cpp				\
		src/materials/FlatMaterial.cpp			\
		src/primitives/AbstractPrimitive.cpp	\

MATH	=	src/math/Vec3.cpp \
			src/math/Vec3Operators.cpp \
			src/math/Vec3Utils.cpp \
			src/math/Ray.cpp

SPHERE_SRC		=	src/primitives/AbstractPrimitive.cpp	\
					src/primitives/HitRecord.cpp			\
					src/primitives/sphere.cpp				\
					src/rayTracerError.cpp					\
					src/materials/FlatMaterial.cpp			\
					src/lights/Color.cpp					\
					$(MATH)

TANGLE_SRC		=	src/primitives/AbstractPrimitive.cpp	\
					src/primitives/HitRecord.cpp			\
					src/primitives/TangleCube.cpp			\
					src/rayTracerError.cpp					\
					src/materials/FlatMaterial.cpp			\
					src/lights/Color.cpp					\
					$(MATH)

PLANE_SRC		=	src/primitives/AbstractPrimitive.cpp	\
					src/primitives/HitRecord.cpp			\
					src/rayTracerError.cpp					\
					src/primitives/plane.cpp				\
					src/lights/Color.cpp					\
					src/materials/FlatMaterial.cpp			\
					$(MATH)

CONE_SRC		=	src/primitives/AbstractPrimitive.cpp	\
					src/primitives/HitRecord.cpp			\
					src/primitives/cone.cpp					\
					src/rayTracerError.cpp					\
					src/lights/Color.cpp					\
					src/materials/FlatMaterial.cpp			\
					$(MATH)

TRIANGLE_SRC	=	src/primitives/AbstractPrimitive.cpp	\
					src/primitives/HitRecord.cpp			\
					src/primitives/Triangle.cpp				\
					src/rayTracerError.cpp					\
					src/lights/Color.cpp					\
					src/materials/FlatMaterial.cpp			\
					$(MATH)

TORUS_SRC		=	src/primitives/AbstractPrimitive.cpp	\
					src/primitives/HitRecord.cpp			\
					src/primitives/Torus.cpp				\
					src/rayTracerError.cpp					\
					src/lights/Color.cpp					\
					src/materials/FlatMaterial.cpp			\
					$(MATH)

CYLINDER_SRC	=	src/primitives/AbstractPrimitive.cpp	\
					src/primitives/HitRecord.cpp			\
					src/primitives/cylinder.cpp				\
					src/rayTracerError.cpp					\
					src/lights/Color.cpp					\
					src/materials/FlatMaterial.cpp			\
					$(MATH)

MOBIUS_SRC	=	src/primitives/AbstractPrimitive.cpp	\
				src/primitives/HitRecord.cpp			\
				src/primitives/mobius.cpp				\
				src/rayTracerError.cpp					\
				src/lights/Color.cpp					\
				src/materials/FlatMaterial.cpp			\
				$(MATH)

FRACTAL_SRC	=	src/primitives/AbstractPrimitive.cpp	\
				src/primitives/HitRecord.cpp			\
				src/primitives/fractal.cpp				\
				src/rayTracerError.cpp					\
				src/lights/Color.cpp					\
				src/materials/FlatMaterial.cpp			\
				$(MATH)

SPHERE_LIB		=	$(LIB_DIR)/raytracer_libsphere.so
PLANE_LIB		=	$(LIB_DIR)/raytracer_libplane.so
CONE_LIB		=	$(LIB_DIR)/raytracer_libcone.so
CYLINDER_LIB	=	$(LIB_DIR)/raytracer_libcylinder.so
TRIANGLE_LIB	=	$(LIB_DIR)/raytracer_libtriangle.so
MOBIUS_LIB		=	$(LIB_DIR)/raytracer_libmobius.so
TORUS_LIB		=	$(LIB_DIR)/raytracer_libtorus.so
FRACTAL_LIB		=	$(LIB_DIR)/raytracer_libfractal.so
TANGLE_LIB		=	$(LIB_DIR)/raytracer_libtangle.so

BIN	=	raytracer

SFML_FLAGS	=	-lsfml-graphics -lsfml-window -lsfml-system	-lsfml-audio -lconfig++

all: $(BIN) primitives

$(BIN):
	$(CPP) $(FLAGS) -o $(BIN) $(SRC) $(SFML_FLAGS) -g3

primitives: $(SPHERE_LIB) $(PLANE_LIB) $(CONE_LIB) $(CYLINDER_LIB) $(TRIANGLE_LIB) $(MOBIUS_LIB) $(TORUS_LIB) $(FRACTAL_LIB) $(TANGLE_LIB)

$(SPHERE_LIB): $(SPHERE_SRC)
	mkdir $(LIB_DIR)
	$(CPP) $(LIBFLAGS) -o $@ $^

$(PLANE_LIB): $(PLANE_SRC)
	$(CPP) $(LIBFLAGS) -o $@ $^

$(CONE_LIB): $(CONE_SRC)
	$(CPP) $(LIBFLAGS) -o $@ $^

$(CYLINDER_LIB): $(CYLINDER_SRC)
	$(CPP) $(LIBFLAGS) -o $@ $^

$(TRIANGLE_LIB): $(TRIANGLE_SRC)
	$(CPP) $(LIBFLAGS) -o $@ $^

$(MOBIUS_LIB): $(MOBIUS_SRC)
	$(CPP) $(LIBFLAGS) -o $@ $^

$(TORUS_LIB): $(TORUS_SRC)
	$(CPP) $(LIBFLAGS) -o $@ $^

$(FRACTAL_LIB): $(FRACTAL_SRC)
	$(CPP) $(LIBFLAGS) -o $@ $^

$(TANGLE_LIB): $(TANGLE_SRC)
	$(CPP) $(LIBFLAGS) -o $@ $^

clean:
	rm -f *~
	rm -f *#

fclean:	clean
	rm -f $(BIN)
	rm -rf $(LIB_DIR)

re:	fclean all
