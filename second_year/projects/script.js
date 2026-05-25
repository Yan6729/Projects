//import { franc } from "https://esm.sh/franc"

// Check for browser compatibility (Note: vendor prefixes might be needed for full compatibility)
window.SpeechRecognition = window.SpeechRecognition || window.webkitSpeechRecognition;
window.SpeechSynthesis = window.SpeechSynthesis || window.webkitSpeechSynthesis;
console.log(window.SpeechRecognition);
const recognition = new SpeechRecognition();
recognition.continuous = false; // Stop after one utterance
recognition.lang = 'en-US';

const inputArea = document.getElementById('input-area');
const outputArea = document.getElementById('output-area');
const listenButton = document.getElementById('listen-button');

listenButton.addEventListener('click', () => {
    recognition.start();
    inputArea.textContent = 'Listening...';
});

recognition.onresult = (event) => {
    const transcript = event.results[0][0].transcript;
    inputArea.textContent = transcript;
    processCommand(transcript);
};

recognition.onerror = (event) => {
    console.error('Speech recognition error:', event.error);
    inputArea.textContent = 'Error listening.';
};

function processCommand(command) {
    let reply = '';
    // Simple command processing logic
    if (command.toLowerCase().includes('hello')) {
        reply = 'Hello there!';
    } else if (command.toLowerCase().includes('what is the time')) {
        reply = `The current time is ${new Date().toLocaleTimeString()}.`;
    } else {
        reply = `I don't understand the command: ${command}`;
    }
    speak(reply);
}

function speak(text) {
    const utterance = new SpeechSynthesisUtterance(text);
    // Optional: customize voice, pitch, rate etc.
    // utterance.voice = voices[0];
    window.speechSynthesis.speak(utterance);
    outputArea.textContent = text;
}

//const test = document.getElementById("test")


//console.log(franc(test.textContent))