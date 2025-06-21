const chatArea = document.getElementById('talk-area');
const userInput = document.getElementById('user-input');

function sendMessage() {
  const message = userInput.value.trim();
  if (message === "") return;

  appendMessage('user', message);
  userInput.value = '';

  setTimeout(() => {
    generateBotReply(message);
  }, 600);
}

function appendMessage(sender, text) {
  const messageDiv = document.createElement('div');
  messageDiv.classList.add('message', sender);
  messageDiv.textContent = text;
  chatArea.appendChild(messageDiv);
  chatArea.scrollTop = chatArea.scrollHeight;
}

function generateBotReply(userText) {
  const reply = `You said: "${userText}"`; // Replace with real logic or API call
  appendMessage('bot', reply);
}
