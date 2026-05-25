/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** rayTracerError
*/

#ifndef RAYTRACERERROR_HPP_
    #define RAYTRACERERROR_HPP_
    #include <iostream>
    #include <exception>
    #include <string>
    #include <cstring>
    using namespace std;


namespace RayTracer {
    class RayTracerError : public exception {
        public:
            RayTracerError();
            RayTracerError(string message);
            virtual const char *what() const noexcept override;
        private:
            string _msg;
    };
}
#endif /* !RAYTRACERERROR_HPP_ */
