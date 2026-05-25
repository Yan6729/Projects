import React, { useState } from 'react';

// Import language utilities
import { useTranslation } from '../i18n/LanguageContext';

const ShifoumiCard = ({ challenge, onSuccess, onFail, difficulty }) => {
    const [playerChoice, setPlayerChoice] = useState(null);
    const [aiChoice, setAiChoice] = useState(null);
    const [result, setResult] = useState(null);
    const [aiHistory, setAiHistory] = useState([]);
    const [isThinking, setIsThinking] = useState(false);
    const { t } = useTranslation();

    const getAvailableMoves = () => {
        if (challenge && challenge.moves) return challenge.moves;
        if (difficulty >= 6) return ['rock', 'paper', 'scissors', 'lizard', 'spock'];
        if (difficulty >= 4) return ['rock', 'paper', 'scissors', 'lizard'];
        return ['rock', 'paper', 'scissors'];
    };

    const getMoveIcon = (move) => {
        const icons = {
            rock: '✊',
            paper: '✋',
            scissors: '✌️',
            lizard: '🦎',
            spock: '🖖'
        };
        return icons[move] || '❓';
    };

    const determineWinner = (player, ai) => {
        if (player === ai) return 'tie';
        const rules = {
            rock: ['scissors', 'lizard'],
            paper: ['rock', 'spock'],
            scissors: ['paper', 'lizard'],
            lizard: ['paper', 'spock'],
            spock: ['rock', 'scissors']
        };
        return rules[player]?.includes(ai) ? 'player' : 'ai';
    };

    const getAiMove = (moves) => {
        const aiMemory = Math.min(4, Math.floor(difficulty / 2) + 1);
        
        if (aiHistory.length >= aiMemory) {
            const recentPattern = aiHistory.slice(-aiMemory);
            for (let i = 0; i < aiHistory.length - aiMemory - 1; i++) {
                const pattern = aiHistory.slice(i, i + aiMemory);
                if (JSON.stringify(pattern) === JSON.stringify(recentPattern)) {
                    const predictedMove = aiHistory[i + aiMemory];
                    const rules = {
                        rock: ['paper', 'spock'],
                        paper: ['scissors', 'lizard'],
                        scissors: ['rock', 'spock'],
                        lizard: ['rock', 'scissors'],
                        spock: ['paper', 'lizard']
                    };
                    const counterMoves = rules[predictedMove] || moves;
                    const validCounters = counterMoves.filter(m => moves.includes(m));
                    if (validCounters.length > 0) {
                        return validCounters[Math.floor(Math.random() * validCounters.length)];
                    }
                }
            }
        }
        
        const random = Math.random();
        if (difficulty >= 5 && random < 0.3 && aiHistory.length > 0) {
            const lastPlayerMove = aiHistory[aiHistory.length - 1];
            const rules = {
                rock: ['paper', 'spock'],
                paper: ['scissors', 'lizard'],
                scissors: ['rock', 'spock'],
                lizard: ['rock', 'scissors'],
                spock: ['paper', 'lizard']
            };
            const counterMoves = rules[lastPlayerMove] || moves;
            const validCounters = counterMoves.filter(m => moves.includes(m));
            if (validCounters.length > 0) {
                return validCounters[Math.floor(Math.random() * validCounters.length)];
            }
        }
        
        return moves[Math.floor(Math.random() * moves.length)];
    };

    const handleMove = (move) => {
        if (isThinking || playerChoice) return;
        
        setIsThinking(true);
        setPlayerChoice(move);
        setAiHistory(prev => [...prev, move]);
        
        setTimeout(() => {
            const moves = getAvailableMoves();
            const aiMove = getAiMove(moves);
            setAiChoice(aiMove);
            
            const winner = determineWinner(move, aiMove);
            setResult(winner);
            
            if (winner === 'player') {
                setTimeout(() => onSuccess(), 500);
            } else if (winner === 'ai') {
                setTimeout(() => onFail(), 500);
            } else {
                setTimeout(() => {
                    setPlayerChoice(null);
                    setAiChoice(null);
                    setResult(null);
                    setIsThinking(false);
                }, 1000);
                return;
            }
            
            setTimeout(() => {
                setPlayerChoice(null);
                setAiChoice(null);
                setResult(null);
                setIsThinking(false);
            }, 1500);
        }, 500);
    };

    const moves = getAvailableMoves();

    return (
        <div className="flex flex-col items-center gap-2 p-2">
            {/* Compact Title */}
            <div className="text-center">
                <h3 className="text-lg font-bold text-yellow-400">⚔️ {t('shifoumi')} ⚔️</h3>
                <p className="text-xs text-stone-300">Choose your move!</p>
            </div>
            
            {/* Compact VS Display */}
            <div className="flex justify-center items-center gap-4">
                <div className="text-center">
                    <div className="w-16 h-16 bg-stone-700 rounded-xl border-2 border-yellow-400 flex items-center justify-center">
                        {playerChoice ? (
                            <div className="text-center">
                                <span className="text-3xl">{getMoveIcon(playerChoice)}</span>
                                <p className="text-[10px] mt-0.5 capitalize">{t(playerChoice)}</p>
                            </div>
                        ) : (
                            <span className="text-2xl">🤔</span>
                        )}
                    </div>
                    <p className="text-[10px] text-stone-300">You</p>
                </div>
                
                <div className="text-xl font-bold text-red-500 animate-pulse">VS</div>
                
                <div className="text-center">
                    <div className="w-16 h-16 bg-stone-700 rounded-xl border-2 border-red-500 flex items-center justify-center">
                        {aiChoice ? (
                            <div className="text-center">
                                <span className="text-3xl">{getMoveIcon(aiChoice)}</span>
                                <p className="text-[10px] mt-0.5 capitalize">{t(aiChoice)}</p>
                            </div>
                        ) : (
                            <span className="text-2xl">👾</span>
                        )}
                    </div>
                    <p className="text-[10px] text-stone-300">Enemy</p>
                </div>
            </div>
            
            {/* Compact Result */}
            {result && (
                <div className={`text-sm font-bold ${
                    result === 'player' ? 'text-green-400' : 
                    result === 'ai' ? 'text-red-400' : 
                    'text-yellow-400'
                }`}>
                    {result === 'player' ? t('victory') : 
                     result === 'ai' ? t('defeat') : 
                     t('tie')}
                </div>
            )}
            
            {/* Compact Move Buttons */}
            <div className="flex flex-wrap justify-center gap-2 mt-1">
                {moves.map(move => (
                    <button
                        key={move}
                        onClick={() => handleMove(move)}
                        disabled={isThinking || playerChoice !== null}
                        className="px-2 py-1.5 bg-gradient-to-r from-stone-700 to-stone-800 
                                   rounded-lg border border-stone-500 
                                   hover:border-yellow-400 hover:from-stone-600 
                                   transition-all duration-200 disabled:opacity-50 
                                   disabled:cursor-not-allowed flex flex-col items-center
                                   min-w-[60px]"
                    >
                        <span className="text-2xl">{getMoveIcon(move)}</span>
                        <span className="capitalize text-[10px] font-medium">{t(move)}</span>
                    </button>
                ))}
            </div>
            
            {/* Compact Tip */}
            {difficulty >= 4 && (
                <p className="text-[9px] text-stone-400 text-center mt-1">
                    Enemy learns patterns!
                </p>
            )}
        </div>
    );
};

export default ShifoumiCard;