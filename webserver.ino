#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// WiFi credentials
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

ESP8266WebServer server(80);

// HTML template with Lorem Ipsum content (DECLARE BEFORE USE)
String htmlContent = "<!DOCTYPE html>"
                     "<html>"
                     "<head>"
                     "    <title>Your Website Title</title>"
                     "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">"
                     "    <style>"
                     "        body {"
                     "            font-family: sans-serif;"
                     "            margin: 0;"
                     "            padding: 0;"
                     "            background-color: #f0f8f0;"
                     "            color: #333;"
                     "            line-height: 1.6;"
                     "        }"
                     "        .container {"
                     "            max-width: 800px;"
                     "            margin: 20px auto;"
                     "            padding: 20px;"
                     "            background-color: #fff;"
                     "            border-radius: 8px;"
                     "            box-shadow: 0 2px 4px rgba(0, 0, 0, 0.1);"
                     "        }"
                     "        h1, h2 {"
                     "            color: #2e7d32;"
                     "            text-align: center;"
                     "        }"
                     "        p {"
                     "            margin-bottom: 15px;"
                     "        }"
                     "        .highlight {"
                     "            background-color: #e8f5e9;"
                     "            padding: 10px;"
                     "            border-radius: 5px;"
                     "            margin-bottom: 15px;"
                     "        }"
                     "        .footer {"
                     "            text-align: center;"
                     "            margin-top: 30px;"
                     "            color: #555;"
                     "        }"
                     "        /* Responsive Styles */"
                     "        @media screen and (max-width: 600px) {"
                     "            .container {"
                     "                width: 95%;"
                     "                margin: 10px auto;"
                     "                padding: 10px;"
                     "            }"
                     "            h1 {"
                     "                font-size: 1.5em;"
                     "            }"
                     "            h2 {"
                     "                font-size: 1.2em;"
                     "            }"
                     "        }"
                     "    </style>"
                     "</head>"
                     "<body>"
                     "    <div class=\"container\">"
                     "        <h1>Your Main Heading</h1>"
                     "        <p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.</p>"
                     "        <h2>A Sub Heading</h2>"
                     "        <p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.</p>"
                     "        <div class=\"highlight\">"
                     "            <p><strong>Highlighted Information:</strong></p>"
                     "            <ul>"
                     "                <li>List item 1</li>"
                     "                <li>List item 2</li>"
                     "                <li>List item 3</li>"
                     "            </ul>"
                     "        </div>"
                     "        <h2>Another Sub Heading</h2>"
                     "        <p>Lorem ipsum dolor sit amet, consectetur adipiscing elit.  Sed ut perspiciatis unde omnis iste natus error sit voluptatem accusantium doloremque laudantium, totam rem aperiam, eaque ipsa quae ab illo inventore veritatis et quasi architecto beatae vitae dicta sunt explicabo.</p>"
                     "    </div>"
                     "    <div class=\"footer\">"
                     "        <p>&copy; 2025 Your Website Name</p>"
                     "    </div>"
                     "</body>"
                     "</html>";

void handleRoot() {
  server.send(200, "text/html", htmlContent);
}

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  // Connect to WiFi
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("Connected to WiFi");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("Failed to connect to WiFi");
  }

  server.on("/", handleRoot);

  server.begin();
  Serial.println("Web server started");
}

void loop() {
  server.handleClient();
}