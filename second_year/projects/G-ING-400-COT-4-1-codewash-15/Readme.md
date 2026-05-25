Lauch the project:
    Do './start'
    Then go to the "[http/localhost/4173](http://localhost:5173/)" (by default, if this port is already taken just go to the one that the server show you)

Language Localization System
Overview
    The game features a comprehensive multilingual localization system that allows players to experience the game in their preferred language. The system supports 12 languages with full UI translation and intelligent speech recognition fallback for the Reading skill.

Supported Languages
    Language	Code	Flag	Speech Recognition
    English	    en-US	🇬🇧	    Full Support
    French	    fr-FRA	🇫🇷	    Full Support
    Spanish	    es-ES	🇪🇸	    Full Support
    German	    de-DE	🇩🇪	    Full Support
    Italian	    it-IT	🇮🇹	    Full Support
    Portuguese	pt-BR	🇧🇷	    Full Support
    Japanese	ja-JP	🇯🇵	    Full Support
    Korean	    ko-KR	🇰🇷	    Full Support
    Chinese	    zh-CN	🇨🇳	    Full Support
    Yoruba	    yo	    🇳🇬	    Fallback to English
    Fon	        fon	    🇧🇯	    Fallback to English
    Mina (Gen)	gej	    🇹🇬	    Fallback to English
    
Features
    Smart Speech Recognition
        The Reading skill uses voice recognition with intelligent fallback:
        Fully supported languages: Native speech recognition in the player's language
        Limited support languages: Automatically falls back to English voice input while keeping UI in native language
        User receives a friendly notification when fallback is activated
        Technical Implementation

    Architecture of the src
        src
    ├── App.jsx
    ├── assets
    │   └── react.svg
    ├── components
    │   ├── drawers
    │   │   ├── CosmeticsDrawer.jsx
    │   │   ├── LanguageDrawer.jsx
    │   │   ├── MenuDrawer.jsx
    │   │   ├── MenuDrawer_old.jsx
    │   │   └── SettingsDrawer.jsx
    │   ├── i18n
    │   │   └── LanguageContext.jsx
    │   ├── modals
    │   │   ├── BugReportModal.jsx
    │   │   └── ResetModal.jsx
    │   ├── PhantomEvent.jsx
    │   ├── profile
    │   │   └── ProfileCard.jsx
    │   ├── skills
    │   │   ├── RhythmCard.jsx
    │   │   ├── ShifoumiCard.jsx
    │   │   └── SkillCard.jsx
    │   └── ui
    │       ├── AchievementToast.jsx
    │       ├── GlobalStyles.jsx
    │       ├── LanguageIcon.jsx
    │       ├── MobWithAura.jsx
    │       ├── ParentalVerificationModal.jsx
    │       ├── PixelHeart.jsx
    │       └── SafeImage.jsx
    ├── constants
    │   ├── achievements.js
    │   ├── assets.js
    │   └── gameData.jsx
    ├── index.css
    ├── main.jsx
    └── utils
            ├── achievementUtils.js
            ├── gameUtils.js
            ├── languageDictionary.js
            ├── mobDisplayUtils.js
            └── soundManager.js
    
    

    Key Components
        LanguageProvider
        Wraps the entire application and provides translation capabilities to all child components.
        jsx
        <LanguageProvider>
            <App />
        </LanguageProvider>
        useTranslation Hook
        Custom hook for accessing translation functions in any component:

        jsx
        const { t, language, setLanguage } = useTranslation();

        // Usage
        <p>{t("start_battle")}</p>
        Translation Dictionary Structure
        javascript
        translations = {
            'en-US': {
                player: "Player",
                start_battle: "Start Battle",
                // ... more keys
            },
            'fr-FRA': {
                player: "Joueur",
                start_battle: "Commencer le combat",
                // ... more keys
            }
        }
        Adding New Languages
        Step 1: Add Language to Translation Dictionary
        Add a new entry in LanguageContext.jsx:

        javascript
        'new-lang': {
            player: "Translation",
            language: "Translation",
            // ... all required keys
        }
        Step 2: Add to Language Selection Menu
        Update LanguageDrawer.jsx:

        javascript
        const LANGUAGES = [
            // ... existing languages
            { code: 'new-lang', label: 'Language Name 🇺🇳' },
        ];
        Step 3: Configure Speech Recognition Support
        Add language to the speech recognition mapping:

        javascript
        const getSpeechLang = (langCode) => {
            const langMap = {
                // ... existing
                'new-lang': 'new-lang-code',
            };
            return langMap[langCode] || 'en-US';
        };
        Speech Recognition Fallback Logic
        javascript
        const isSpeechSupported = (langCode) => {
            const supported = ['en-US', 'fr-FRA', 'es-ES', 'de-DE', 'it-IT', 'pt-BR', 'ja-JP', 'ko-KR', 'zh-CN'];
            return supported.includes(langCode);
        };

        const toggleMicListener = (targetId) => {
            let currentLang = localStorage.getItem("lang") || "en-US";
        
            if (!isSpeechSupported(currentLang)) {
                // Show fallback message
                setSpokenText(t("speech_fallback_english"));
                currentLang = "en-US"; // Fallback to English for voice
        }
        
        // Start recognition with appropriate language
            startVoiceListener(targetId, currentLang);
        };
        Key Translation Keys
        UI Elements
        Key	Description
        player	Player name label
        language	Language selection label
        settings	Settings menu title
        achievements	Achievements section title
        skills	Skills section title
        stats	Statistics section title
        Gameplay
        Key	Description
        start_battle	Battle start button
        end_battle	Battle end button
        correct	Correct answer feedback
        wrong	Wrong answer feedback
        you_died	Death screen message
        level_restored	Level restoration message
        Skill Names
        Key	Description
        reading	Reading skill
        math	Mathematics skill
        writing	Writing skill
        memory	Memory skill
        patterns	Patterns skill
        cleaning	Cleaning skill
        Voice Recognition
        Key	Description
        mic_off	Microphone off status
        listening	Listening status
        speech_fallback_english	Fallback notification
        speech_not_supported	Unsupported language error
        User Experience
        Language Selection
        Click the language icon in the top-left corner
        Select desired language from the drawer
        UI instantly updates without page reload
        Preference is saved to localStorage for future sessions
        Voice Input for Reading Skill
        Supported languages: Works natively with accurate recognition
        Limited languages: Shows notification and uses English for voice input
        All other UI elements remain in the selected language

    Performance Considerations
        Translations are loaded once at startup
        No runtime network requests for translations
        localStorage persistence for user preferences

        Efficient re-rendering with React Context

    Browser Compatibility
        Feature	Chrome	Firefox	Safari	Edge
        UI Translation	                ✅   ✅  ✅   ✅
        Speech Recognition (Supported)	✅	⚠️	✅	✅
        Speech Recognition (Fallback)	✅	⚠️	✅	✅
        Future Enhancements
        Right-to-left (RTL) language support
        Regional dialects (e.g., Canadian French, Latin American Spanish)
        Community translation contributions
        Language-specific cultural adaptations
        Voice recognition training for better accuracy
        Troubleshooting
        Language Not Showing
        Clear browser cache and localStorage
        Verify language code matches the translations object
        Voice Recognition Not Working
        Check microphone permissions
        Verify internet connection (for Chrome's speech recognition)
        Ensure you're using a supported browser
        Try the fallback English mode if your language isn't fully supported
        Translations Missing
        Fallback to English will occur automatically
        Check if the translation key exists in all language objects

    Contributing
        To contribute new translations:
        Fork the repository
        Add your language to the translations object (you'll find the dictionnary in the 'src/utils/languageDictionay.js' file)
        Test all UI elements
        Submit a pull request
        For questions or suggestions, please open an issue on GitHub.

