import React from 'react';
import { X, Bug } from 'lucide-react';

// Import language utilities
import { useTranslation } from '../i18n/LanguageContext'

const BugReportModal = ({ isOpen, onClose }) => {
    if (!isOpen) return null;
    const { t } = useTranslation();

    return (
        <div className="fixed inset-0 z-50 flex items-center justify-center animate-in fade-in duration-200">
            <div className="absolute inset-0 bg-black/70 backdrop-blur-sm" onClick={onClose}></div>
            
            <div className="relative bg-stone-900 border-4 border-stone-600 rounded-2xl w-full max-w-lg mx-4 shadow-2xl overflow-hidden">
                {/* Header */}
                    <button 
                        onClick={onClose}
                        className="absolute top-4 right-4 text-stone-400 hover:text-white transition-colors"
                        aria-label="Close"
                    >
                        <X size={24} />
                    </button>
                    <div className="bg-gradient-to-b from-red-950/30 to-stone-900 p-8 pt-10 border-b-2 border-stone-800 text-center">
                        <div className="inline-flex p-3 bg-red-500/10 rounded-full mb-4 border border-red-500/20">
                            <Bug size={32} className="text-red-500 animate-pulse" />
                        </div>
                        <h2 className="text-3xl font-black text-stone-100 uppercase tracking-tighter">
                            {t('bug_report_title')}
                        </h2>
                        <p className="text-red-400/80 font-mono text-sm mt-1 uppercase tracking-widest">
                            {t('bug_report_subtitle')}
                        </p>
                    </div>
                    <div className="bg-gradient-to-b from-red-950/30 to-stone-900 p-8 pt-10 border-b-2 border-stone-800 text-center">
                        <label className="text-lg text-white text-left">
                            {t('describe_problem')}
                        </label>
                         <textarea 
                            rows="4"
                            className="w-full border border-stone-600 rounded-lg p-3 text-white focus:outline-none focus:border-blue-500 placeholder-stone-500"
                            placeholder={t('bug_description_placeholder')}>
                        </textarea>
                        <div className="flex flex-col items-start w-full mt-6">
                            <label className="text-lg text-white text-left mb-2">
                                {t('add_file')}
                            </label>
                            <input
                                type="file"
                                className="w-full text-sm text-stone-400
                                bg-stone-800 border border-stone-600 
                                rounded-lg p-2
                                file:mr-4 file:py-2 file:px-4
                                file:rounded-md file:border-0
                                file:text-sm file:font-semibold
                                file:bg-stone-700 file:text-stone-200
                                hover:file:bg-stone-600 file:cursor-pointer cursor-pointer"
                            />
                        </div>
                        <button 
                            type="submit"
                            className="w-full mt-8 bg-red-600 hover:bg-red-950/30 text-white py-3 px-6 rounded-xl active:scale-95 shadow-lg justify-center"
                        >
                            {t('submit_file')}
                        </button>
                    </div>
            </div>
        </div>
    );
};

export default BugReportModal;