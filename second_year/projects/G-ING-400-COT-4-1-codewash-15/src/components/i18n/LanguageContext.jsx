// src/i18n/LanguageContext.jsx
import React, { createContext, useContext, useState, useEffect } from 'react';

const LanguageContext = createContext();

// Dictionnaire complet des traductions importer
import { TRANSLATION  } from '../../utils/languageDictionary';

export const LanguageProvider = ({ children }) => {
    const [language, setLanguage] = useState(() => {
        return localStorage.getItem("lang") || "en-US";
    });

    useEffect(() => {
        localStorage.setItem("lang", language);
    }, [language]);

    const t = (key) => {
        const langDict = TRANSLATION[language];
        if (langDict && langDict[key] !== undefined) {
            return langDict[key];
        }
        // Fallback en anglais
        if (TRANSLATION['en-US'][key] !== undefined) {
            return TRANSLATION['en-US'][key];
        }
        return key;
    };

    return (
        <LanguageContext.Provider value={{ language, setLanguage, t }}>
            {children}
        </LanguageContext.Provider>
    );
};

export const useTranslation = () => {
    const context = useContext(LanguageContext);
    if (!context) {
        throw new Error('useTranslation must be used within LanguageProvider');
    }
    return context;
};