


//--------------------------------------------------------

void printLocalTime()
{
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    Serial.println("Failed to obtain time");
    return;
  }
  Serial.println(&timeinfo, "%Y:%b:%d:%H:%M:%S");
}

//--------------------------------------------------------

char *getMyLocaltime(char * buf)
{
  time_t rawtime;
  struct tm timeinfo;

  if (!buf) return(NULL);
  
  if(!getLocalTime(&timeinfo))
    {
     Serial.println("Failed to obtain time");
     buf[0] = 0;
    }
//  strftime(buf, sizeof(buf), "%A, %B %d %Y %H:%M:%S", &timeinfo);
  strftime(buf, 100, "%Y:%m:%d:%H:%M:%S", &timeinfo);
  return(buf);
}

//--------------------------------------------------------

int sendTopicLife(WiFiData &wfd)
{
static int        counter=1; 
char              topic[MAX_TEXT_LEN];
char              msg[MAX_TEXT_LEN];

snprintf (topic, 100, "%s/life", wfd.station_name);
snprintf (msg, 100, "%d", counter);
pubSubClient.publish(topic, msg);

if (counter++ > 100) 
  counter = 1;

return(1);
}

//--------------------------------------------------------

int sendTopicTime(WiFiData &wfd)
{
char      topic[MAX_TEXT_LEN];
char      msg[MAX_TEXT_LEN]; 
char      buffer[MAX_TEXT_LEN]; 

getMyLocaltime(buffer);

snprintf (topic, 100, "%s/time", wfd.station_name);
snprintf (msg, 100, "%s", buffer);
pubSubClient.publish(topic, msg);    

return(1);
}

//--------------------------------------------------------

int sendTopicFloat(WiFiData &wfd, char *topicName, float value, int precision, int _verbose) {

char      topic[MAX_TEXT_LEN];
char      msg[MAX_TEXT_LEN];

snprintf (topic, 100, "%s/%s", wfd.station_name, topicName);
snprintf (msg, 100, "%.*f", precision, value);

if (_verbose)  {
  Serial.print("Topic: ");
  Serial.print(topic);
  Serial.print(" value: ");
  Serial.println(msg);  
}
pubSubClient.publish(topic, msg);
return(1); 
}

//--------------------------------------------------------

int sendMeassurementTopics()  {

float value=0.0;

value=0.0;
if (readUV(&value))
  sendTopicFloat(wfd, "uv", value, 1, 1);  
delay (1000);

value=0.0;
if (readTempPrec(&value))
  sendTopicFloat(wfd, "tempPrec", value, 1, 1); 
delay (1000);

value=0.0;
if (readHumidity(&value))
  sendTopicFloat(wfd, "humidity", value, 1, 1); 
delay (1000);

value=0.0;
if (readPressure(&value))
  sendTopicFloat(wfd, "pressure", value, 1, 1); 
delay (1000);

value=0.0;
if (readTemp(&value))
  sendTopicFloat(wfd, "tempStd", value, 1, 1); 
delay (1000);
}

//--------------------------------------------------------

int sendErrorTopics()  {

sendTopicFloat(wfd, "ERRTot", totalErrors, 0, 1); delay (1000);
sendTopicFloat(wfd, "ERRwifi", WIFIErrors, 0, 1); delay (1000);
sendTopicFloat(wfd, "ERRntp", NTPErrors, 0, 1); delay (1000);
sendTopicFloat(wfd, "ERRmqtt", MQTTErrors, 0, 1); delay (1000);
sendTopicFloat(wfd, "ERRbme", BMEErrors, 0, 1); delay (1000);
sendTopicFloat(wfd, "ERRmpce", MCPErrors, 0, 1); delay (1000);
sendTopicFloat(wfd, "ERRveml", VEMLErrors, 0, 1); delay (1000);
}

//--------------------------------------------------------
