let ws = new WebSocket("wss://elecdesign.org.aalto.fi/nr1/ws/eka");

ws.addEventListener("open", () => {
  console.log('[Socket] Connected!');
  ws.send("Test!");
});

ws.addEventListener("message", (event) => {
  console.log(`[Socket] ${event.data}`);
});

ws.addEventListener("close", (event)=> {
  if (event.wasClean) {
    console.log(`[Socket] Connection closed cleanly, code=${event.code} reason=${event.reason}`);
  } else {
    console.log('[Socket] Connection died');
  }
});

ws.addEventListener("error", (error) => {
  console.log(`[Socket] Error: ${error.message}`);
});
