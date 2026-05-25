import React from 'react';
import { useTranslation } from "../i18n/LanguageContext";

// dictionnaire pour définir les différents texte des bouttons de langue et aussi les code language que chanque boutton doit produire 
const LANGUAGES = [
    { code: 'en-US', label: 'English 🇬🇧' }, // Anglais du royaume Unis
    { code: 'fr-FRA', label: 'Français 🇫🇷' }, // Français de la France
    { code: 'es-ES', label: 'Español 🇪🇸' }, // Espagnol
    { code: 'ja-JP', label: '翻訳 🇯🇵' }, // Japonais
    { code: 'de-DE', label: 'Deutsch 🇩🇪' }, // Allemand
    { code: 'yo-NGA', label: 'Yorùbá 🇳🇬' },       // Yoruba
    { code: 'fon-BEN', label: 'Fon (Fɔngbè) 🇧🇯' }, // Fon
    { code: 'pt-BR', label: 'Português 🇧🇷' }, // Portuguais
    { code: 'it-IT', label: 'Italiano 🇮🇹' }, // Italien
    { code: 'zh-CN', label: '中文 🇨🇳' }, // Chinois
    { code: 'ko-KR', label: '한국어 🇰🇷' }, // Coréen
     { code: 'gej', label: 'Mina (Gɛ̃) 🇹🇬' }, // Mina
];

// Dessinner le Overlay où les différents bouttons de language seront afficher
const LanguageDrawer = ({ isOpen, onClose }) => {
    const { language, setLanguage, t } = useTranslation();

    return (
        <div className={`fixed h-full w-[300px] bg-[#1a1a1a]/95 backdrop-blur-md z-50 border-l-4 border-stone-600 shadow-2xl transition-transform duration-300 ${isOpen ? 'translate-x-0' : 'translate-x-full'}`} style={{ top: 0, right: 0 }}>
            <div className="p-6">
                <h2 className="text-3xl text-yellow-400 mb-6">
                    {t("language")}
                </h2>
                <div className="flex flex-col gap-4">
                    {/* Utiliser la fonction map pour parcourir la map de code-label pour la création des bouton */}
                    {LANGUAGES.map(lang => (
                        <button
                            key={lang.code}
                            // Gérer les évennement affin de avoir si un bouton était cliquer afin de récupérer le code language qu'il laisse
                            onClick={() => {
                                setLanguage(lang.code);
                                onClose();
                            }}
                            className={`p-3 rounded-lg border-2 transition ${
                                language === lang.code
                                    ? 'border-yellow-400 bg-stone-700'
                                    : 'border-stone-600 hover:bg-stone-700'
                            }`}
                        >
                            {lang.label}
                        </button>
                    ))}
                </div>
            </div>
        </div>
    );
};

export default LanguageDrawer;