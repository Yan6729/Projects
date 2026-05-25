import React, { useState, useRef } from 'react';
import { Music, RotateCcw } from 'lucide-react';

// Import language utilities
import { useTranslation } from '../i18n/LanguageContext';

const RhythmCard = ({ challenge, onSuccess, onFail, difficulty }) => {
    const [pattern, setPattern] = useState([]);
    const [userIndex, setUserIndex] = useState(0);
    const [status, setStatus] = useState('idle'); // idle, playing, waiting, finished
    const [feedback, setFeedback] = useState('');
    const audioCtx = useRef(null);
    const roundResultSent = useRef(false);
    const { t } = useTranslation();

    const getPatternLength = () => {
        if (difficulty <= 1) return 3;
        if (difficulty <= 2) return 4;
        if (difficulty <= 3) return 5;
        if (difficulty <= 4) return 6;
        if (difficulty <= 5) return 7;
        if (difficulty <= 6) return 8;
        return 10;
    };

    const getFeedBack = (feedback) => {
        const feedbacks = {
            'Your turn!': t('rhythm_your_turn'),
            'Perfect!': t('rhythm_perfect'),
            'Wrong!': t('rhythm_wrong'),
            'Listen...': t('rhythm_listen'),
        }
        return feedbacks[feedback] || feedback;
    }

    const generatePattern = () => {
        const length = getPatternLength();
        return Array.from({ length }, () => Math.random() > 0.5 ? 'tap' : 'hold');
    };

    const playSound = (type) => {
        if (!audioCtx.current) {
            audioCtx.current = new (window.AudioContext || window.webkitAudioContext)();
        }
        const osc = audioCtx.current.createOscillator();
        const gain = audioCtx.current.createGain();
        osc.connect(gain);
        gain.connect(audioCtx.current.destination);
        osc.type = 'sine';
        osc.frequency.value = type === 'tap' ? 880 : 440;
        gain.gain.value = 0.3;
        osc.start();
        const duration = type === 'tap' ? 200 : 500;
        setTimeout(() => osc.stop(), duration);
    };

    const playPattern = async (pat) => {
        setStatus('playing');
        setFeedback('Listen...');
        for (let beat of pat) {
            await new Promise(resolve => {
                playSound(beat);
                setTimeout(resolve, 400);
            });
        }
        setStatus('waiting');
        setFeedback('Your turn!');
        setUserIndex(0);
        roundResultSent.current = false;
    };

    const startGame = () => {
        const newPattern = generatePattern();
        setPattern(newPattern);
        playPattern(newPattern);
    };

    const handleInput = async (input) => {
        if (status !== 'waiting') return;

        // Resume AudioContext if needed
        if (audioCtx.current && audioCtx.current.state === 'suspended') {
            await audioCtx.current.resume();
        }

        // Play a sound for the button press
        playSound(input);

        if (input === pattern[userIndex]) {
            setUserIndex(prev => prev + 1);
            if (userIndex + 1 === pattern.length) {
                if (!roundResultSent.current) {
                    roundResultSent.current = true;
                    setStatus('finished');
                    setFeedback('Perfect!');
                    onSuccess();
                }
            } else {
                setFeedback('✓');
                setTimeout(() => setFeedback(''), 300);
            }
        } else {
            if (!roundResultSent.current) {
                roundResultSent.current = true;
                setStatus('finished');
                setFeedback('Wrong!');
                onFail();
            }
        }
    };

    const nextRound = () => {
        // generate new pattern and start fresh
        const newPattern = generatePattern();
        setPattern(newPattern);
        playPattern(newPattern);
    };

    return (
        <div className="flex flex-col items-center gap-2 p-2">
            <div className="text-center">
                <h3 className="text-lg font-bold text-yellow-400">{t('rhythm_duel')}</h3>
                <p className="text-xs text-stone-300">{t('rhythm_subtitle')}</p>
            </div>

            {feedback && (
                <div className={`text-sm font-bold ${
                    feedback === 'Perfect!' ? 'text-green-400' :
                    feedback === 'Wrong!' ? 'text-red-400' :
                    feedback === 'Your turn!' ? 'text-blue-400' :
                    'text-yellow-400'
                }`}>
                    {getFeedBack(feedback)}
                </div>
            )}

            {pattern.length > 0 && (status === 'waiting' || status === 'finished') && (
                <div className="flex gap-1 justify-center">
                    {pattern.map((_, idx) => (
                        <div
                            key={idx}
                            className={`w-3 h-3 rounded-full ${
                                idx < userIndex ? 'bg-green-500' :
                                idx === userIndex && status === 'waiting' ? 'bg-yellow-400 animate-pulse' :
                                'bg-stone-600'
                            }`}
                        />
                    ))}
                </div>
            )}

            {status === 'idle' && (
                <button
                    onClick={startGame}
                    className="px-4 py-1.5 bg-purple-600 hover:bg-purple-500 rounded-lg border border-purple-400 text-sm font-bold"
                >
                    {t('rhythm_start')}
                </button>
            )}

            {status === 'playing' && (
                <div className="animate-pulse flex flex-col items-center">
                    <Music size={32} className="text-yellow-400" />
                    <span className="text-xs mt-1">{t('rhythm_playing')}</span>
                </div>
            )}

            {status === 'waiting' && (
                <div className="flex gap-4 mt-2">
                    <button
                        onClick={() => handleInput('tap')}
                        className="px-5 py-2 bg-blue-600 hover:bg-blue-500 rounded-lg border border-blue-400 font-bold text-base"
                    >
                        {t('rhythm_tap')}
                    </button>
                    <button
                        onClick={() => handleInput('hold')}
                        className="px-5 py-2 bg-orange-600 hover:bg-orange-500 rounded-lg border border-orange-400 font-bold text-base"
                    >
                        {t('rhythm_hold')}
                    </button>
                </div>
            )}

            {status === 'finished' && (
                <button
                    onClick={nextRound}
                    className="px-4 py-1.5 bg-blue-600 hover:bg-blue-500 rounded-lg border border-blue-400 text-sm font-bold flex items-center gap-1"
                >
                    <RotateCcw size={14} /> {t('rhythm_continue')}
                </button>
            )}
        </div>
    );
};

export default RhythmCard;