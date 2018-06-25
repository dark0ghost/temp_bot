
#include <ESP8266WiFi.h> 
#include <WiFiClientSecure.h> 
#include <UniversalTelegramBot.h> 
 
char ssid[] = "";
char password[] = "";
String tempard ;
 
#define BOTtoken ""
 
WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);
 
String keyboardJson = "[[\"температура\"]]";
 
void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}
 
void loop() {
  int numNewMessages = bot.getUpdates(
           bot.last_message_received + 1);
  handleNewMessages(numNewMessages);
}
 
void handleNewMessages(int numNewMessages) {
  for (int i = 0; i < numNewMessages; i++) {
    String chat_id = String(bot.messages[i].chat_id);
    String text = bot.messages[i].text;
    if (text == "температура") {
      Serial.println("temp");
      delay (100);
      tempard =  Serial.read();
      bot.sendMessage(chat_id ,"температура ",tempard );
    }
    if (text == "/start") {
     bot.sendMessageWithReplyKeyboard(chat_id, 
          "Choose from one of the following options",
      "", keyboardJson, true);
  }
}
}
  

