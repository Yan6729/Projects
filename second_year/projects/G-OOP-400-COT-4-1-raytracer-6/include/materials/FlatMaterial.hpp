/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Sun, May, 2026                                                     *
 * Title           - G-OOP-400-COT-4-1-raytracer-6                                      *
 * Description     -                                                                    *
 *     FlatMaterial                                                                     *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ *
 *                                                                                      *
 *         ░        ░       ░░        ░        ░        ░░      ░░  ░░░░  ░             *
 *         ▒  ▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒▒▒  ▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒▒▒▒▒▒  ▒▒▒▒  ▒  ▒▒▒▒  ▒             *
 *         ▓      ▓▓▓       ▓▓▓▓▓  ▓▓▓▓▓▓▓  ▓▓▓▓      ▓▓▓  ▓▓▓▓▓▓▓        ▓             *
 *         █  ███████  ██████████  ███████  ████  ███████  ████  █  ████  █             *
 *         █        █  ███████        ████  ████        ██      ██  ████  █             *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ */


#ifndef FLAT_MATERIAL_HPP_
    #define FLAT_MATERIAL_HPP_

    #include "../lights/Color.hpp"

namespace RayTracer {

    class FlatMaterial {
        public:
            FlatMaterial();
            explicit FlatMaterial(const Color& albedo);
            FlatMaterial(int r, int g, int b);

            static FlatMaterial fromRGB255(int r, int g, int b);

            const Color& getAlbedo() const;
            void setAlbedo(const Color& albedo);

        private:
            Color _albedo;
    };

}

#endif /* !FLAT_MATERIAL_HPP_ */
