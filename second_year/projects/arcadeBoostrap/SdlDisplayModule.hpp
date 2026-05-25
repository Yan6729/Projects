/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** SdlDisplayModule
*/

#ifndef SDLDISPLAYMODULE_HPP_
    #define SDLDISPLAYMODULE_HPP_
    #include "IDisplayModule.hpp"

class SDLDisplayModule : public IDisplayModule {
    public:
        SDLDisplayModule();
        ~SDLDisplayModule();
        void init(void);
        void stop(void);
        const string& getName() const;


    protected:
    private:
        string _name;
};

#endif /* !SDLDISPLAYMODULE_HPP_ */
