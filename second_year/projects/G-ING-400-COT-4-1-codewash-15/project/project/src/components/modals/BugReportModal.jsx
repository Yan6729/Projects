import React from 'react';
import {X} from 'lucide-react';

const BugReportModal = ({ isOpen, onClose }) => {
    if (!isOpen) return null;

    return (
        <div className="fixed inset-0 z-50 flex items-center justify-center">
            <div className="absolute inset-0 bg-black/70 backdrop-blur-sm" onClick={onClose}></div>
                 <div className="relative bg-stone-900 border-4 border-stone-600 rounded-2xl p-8 w-full max-w-lg mx-4 shadow-2xl">
                <div className="flex flex-col items-center text-center">
                    <h2 className="text-3xl font-bold text-slate-300 uppercase tracking-wider mb-4">Signalement de bug</h2>
                    <label className="text-lg text-white text-left ">Description du problème</label>
                    <textarea 
                    rows="4"
                    className="w-full border border-stone-600 rounded-lg p-3 text-white focus:border-blue-500 placeholder-stone-500"
                    placeholder="Tu peux faire ta description du bug ici...">
                    </textarea>
                    <label className="text-lg text-white text-left mt-6">Ajout d'un fichier</label>
                    <input
                    type="file"
                    className="w-full text-sm text-stone-400
                    file:mr-4 file:py-2 file:px-4
                    file:rounded-lg file:border-0
                    file:text-sm file:font-semibold
                    file:bg-stone-700 file:text-stone-200
                    hover:file:bg-stone-600 file:cursor-pointer cursor-pointer
                    bg-stone-800 border border-stone-600 rounded-lg p-2"
                    />
                    <button
                    onClick={onClose}
                    className='absolute top-4 right-4 text-stone-400 hover:text-white transition-colors disabled:opacity-50" aria-label="Close'>  <X size={24}/>  </button>
                </div>
             </div>
         </div>
    );
};

export default BugReportModal;
