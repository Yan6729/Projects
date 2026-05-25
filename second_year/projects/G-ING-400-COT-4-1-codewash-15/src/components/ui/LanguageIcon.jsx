import React from "react";

// Créer l'icône a afficher sur le boutton grâce à forwardRef
const LanguageIcon = React.forwardRef(({ size = 24, ...props }, ref) => {
    return (
        <svg
            ref={ref}
            xmlns="http://www.w3.org/2000/svg"
            width={size}
            height={size}
            viewBox="0 0 24 24"
            fill="none"
            stroke="currentColor"
            strokeWidth="2"
            strokeLinecap="round"
            strokeLinejoin="round"
            {...props}
        >
            {/* Globe */}
            <circle cx="12" cy="12" r="10" />
            <path d="M2 12h20" />
            <path d="M12 2a15 15 0 0 1 0 20" />
            <path d="M12 2a15 15 0 0 0 0 20" />
        </svg>
    );
});

LanguageIcon.displayName = "LanguageIcon";

// Exporter l'icône crée
export default LanguageIcon;