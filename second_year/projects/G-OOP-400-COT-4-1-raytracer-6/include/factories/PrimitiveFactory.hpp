/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** PrimitiveFactory
*/

#pragma once

#include "../primitives/IPrimitive.hpp"
#include "../primitives/Sphere.hpp"
#include "../primitives/Plane.hpp"
#include "../primitives/Cylinder.hpp"
#include "../primitives/Cone.hpp"
#include <memory>
#include <string>
#include <unordered_map>
#include <functional>

namespace RayTracer {
    class PrimitiveFactory {
        public:
            using PrimitiveCreator = std::function<std::unique_ptr<IPrimitive>()>;

            static PrimitiveFactory& getInstance() {
                static PrimitiveFactory instance;
                return instance;
            }

            template<typename T>
            void registerPrimitive(const std::string& type) {
                creators_[type] = []() -> std::unique_ptr<IPrimitive> {
                    return std::make_unique<T>();
                };
            }

            std::unique_ptr<IPrimitive> createPrimitive(const std::string& type) {
                auto it = creators_.find(type);
                if (it != creators_.end()) {
                    return it->second();
                }
                return nullptr;
            }

            bool isTypeSupported(const std::string& type) const {
                return creators_.find(type) != creators_.end();
            }

            std::vector<std::string> getSupportedTypes() const {
                std::vector<std::string> types;
                for (const auto& pair : creators_) {
                    types.push_back(pair.first);
                }
                return types;
            }

        private:
            PrimitiveFactory() {
                registerDefaultPrimitives();
            }

            void registerDefaultPrimitives() {
                registerPrimitive<Sphere>("sphere");
                registerPrimitive<Plane>("plane");
                registerPrimitive<Cylinder>("cylinder");
                registerPrimitive<Cone>("cone");
            }

            std::unordered_map<std::string, PrimitiveCreator> creators_;
    };
}
