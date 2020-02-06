

const char* rootCABuff = \
"-----BEGIN CERTIFICATE-----\n" \
"MIIDeDCCAmCgAwIBAgIJAIAOZwNER/v5MA0GCSqGSIb3DQEBCwUAMFExCzAJBgNV\n" \
"BAYTAlVTMREwDwYDVQQHDAhQb3J0bGFuZDEMMAoGA1UECgwDQURDMQwwCgYDVQQL\n" \
"DANjeXMxEzARBgNVBAMMCmFkYy5uZXQuYXIwHhcNMTkwNzE5MTIxMjUzWhcNMjkw\n" \
"NzE2MTIxMjUzWjBRMQswCQYDVQQGEwJVUzERMA8GA1UEBwwIUG9ydGxhbmQxDDAK\n" \
"BgNVBAoMA0FEQzEMMAoGA1UECwwDY3lzMRMwEQYDVQQDDAphZGMubmV0LmFyMIIB\n" \
"IjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAoL7WUI6LiCl7NJI00ggeLuCW\n" \
"Ad/2vTTuUzjQyr56WutNK/2TQ/ORcrAHc2BVDyd2BoX3Dyn9p+NflKvMneTZgMOu\n" \
"FbnK5YOfvh0xsn421rMycefAiWwJ8XKUSITLXhIMlFA3sb2zs6sGgIn8VTU7uSIv\n" \
"vS5a0zNKPTgJzjOxXLKpSF3YBESC7RcCNMugli+BgOPJZAbEwLMrxNgKK4/AxRAg\n" \
"2Zyo4XcqWdwPbMoGJIus409XFhDXSMdJlfiImmJVbDxZSiuPodYFEngIUvxXHAlV\n" \
"AjRT5gc+04vo3AlBlrKHdF0PDl0eLWSWzUx1o5+GXHpqCPTY4uz2xbAgxtCiJQID\n" \
"AQABo1MwUTAdBgNVHQ4EFgQU6kNejnMamTyEMXAB0Qdi24NKWdcwHwYDVR0jBBgw\n" \
"FoAU6kNejnMamTyEMXAB0Qdi24NKWdcwDwYDVR0TAQH/BAUwAwEB/zANBgkqhkiG\n" \
"9w0BAQsFAAOCAQEAXdNweZS0yVimJQd4ThsrFAzKWu9BQRNTFkZxS4qIhlO27Nza\n" \
"WrTuwlYFnQImcLBRb0GEEerVGszOvcGC++DKKdWAEbnL8Pe3HCSI2VkQDghvAYUj\n" \
"NcdJ102YFlBDlsh8A/IDUTPRL61h4MB6ON1gzK2QCj5/mz/ZkUDKV+aPh4z8ZVbi\n" \
"CJt9/rhKTsy/uFm3zChFQX/4R3vb1t+sSLXFD554p6H+Pn+8L4l8c3FQjFexeRp/\n" \
"INZ+nbBMhnsI9LHvD/PPnmxtvt6mtebyo1IHsm0TP72VKo5iiR3aljX1+Cs7THPo\n" \
"IvlB90MD+fUp3l2KGOs6d3QKFujCxPhkZ48QKQ==\n" \
"-----END CERTIFICATE-----\n";


// Fill with your certificate.pem.crt with LINE ENDING
const char* certificateBuff = \
"-----BEGIN CERTIFICATE-----\n" \
"MIIDMDCCAhgCCQCQzhtPiUv/SjANBgkqhkiG9w0BAQsFADBRMQswCQYDVQQGEwJV\n" \
"UzERMA8GA1UEBwwIUG9ydGxhbmQxDDAKBgNVBAoMA0FEQzEMMAoGA1UECwwDY3lz\n" \
"MRMwEQYDVQQDDAphZGMubmV0LmFyMB4XDTE5MDcxOTEyMjMwMVoXDTI5MDcxNjEy\n" \
"MjMwMVowYzELMAkGA1UEBhMCQVIxDTALBgNVBAgMBEJTQVMxDTALBgNVBAcMBENB\n" \
"QkExDDAKBgNVBAoMA1RFTDEMMAoGA1UECwwDY3lzMRowGAYDVQQDDBFsYWJyZWRl\n" \
"cy5kZG5zLm5ldDCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBAKK43gyD\n" \
"5oYjfySUoeKy3q1JlolFWUBgnD9OBfWtz1JU2rpD/auPCjU5qAtoUJ91sdzwKU6R\n" \
"j5nhabhE4mQ3w3ApsvB2JWyuPuHRItP4h5rzI0uDRgxW5qI7F++yF37o+2M4xiCD\n" \
"8PU9IXIpcwqj0xEVuffEpuhu5Dosu1xGQkKZoM07j+3HWUcnwVGaW5Sj5FGwcmoQ\n" \
"PomPQWN0sVvr5B4QHSxdt86SpurMhTr/HUO4sT0HNynAGyOaCihhO5efJam9GuVw\n" \
"/OF/RZcQ/hQJjwN62WDFv4U8X6AvjgURKSCtGU/ya+FOtRvuujvNLkjId/ZDoY6O\n" \
"gHCjd/qIAqkVmccCAwEAATANBgkqhkiG9w0BAQsFAAOCAQEAUHV/IOH0PdxCIQud\n" \
"uZ3v9tVLdSUjTuJBETPJyrmfdD6b5HJhZSpWB3OB0z9PGt54HhYMOzHuw/o3qykd\n" \
"08HJv6ny80MezQauQAAZGQby6dVsm0dLxsUFrf4iEdiVrKQ/D8CmCn/j/1B4JW45\n" \
"cm9cBLgXi++nr63wTDE+wmChksYDPzdd5wHNLeBt7hXQxhS7k4kq8nZpLgxMKpZl\n" \
"c+xZKelXNX91bYrbVwK6X7ob4IRjf7ZflLv7u0M4Xe874t1khDN1SxufJNdjJ4AK\n" \
"IOoaLRXiwdYCyjjP/oGShNgxZmEkV8XLm/+/LzQVzerVB1teWCMYd7kw+LuC8CEU\n" \
"ByNWnQ==\n" \
"-----END CERTIFICATE-----\n";



// Fill with your private.pem.key with LINE ENDING
const char* privateKeyBuff = \
"-----BEGIN RSA PRIVATE KEY-----\n" \
"MIIEowIBAAKCAQEAorjeDIPmhiN/JJSh4rLerUmWiUVZQGCcP04F9a3PUlTaukP9\n" \
"q48KNTmoC2hQn3Wx3PApTpGPmeFpuETiZDfDcCmy8HYlbK4+4dEi0/iHmvMjS4NG\n" \
"DFbmojsX77IXfuj7YzjGIIPw9T0hcilzCqPTERW598Sm6G7kOiy7XEZCQpmgzTuP\n" \
"7cdZRyfBUZpblKPkUbByahA+iY9BY3SxW+vkHhAdLF23zpKm6syFOv8dQ7ixPQc3\n" \
"KcAbI5oKKGE7l58lqb0a5XD84X9FlxD+FAmPA3rZYMW/hTxfoC+OBREpIK0ZT/Jr\n" \
"4U61G+66O80uSMh39kOhjo6AcKN3+ogCqRWZxwIDAQABAoIBAHPOH3FGudvDDWxK\n" \
"Pz/oTqOC2JiO+yre1rQS4hjrfr24WAXx92mOHhStGNQthBtIFrIHVU5uN4WrL6MN\n" \
"mxT5vqRneMq7On0zMNtjDGdQ26lB2l+WaFbFzdOtPKbA1wnh427E6/QeEnFl9RSb\n" \
"PR1YZBEnpjcYBDUtHk3sodbUxblBG27TGugkpQQqUtId/3qsNZkOJjrKQZyfHP+E\n" \
"dRR3iW6+oKB8pQvy16oEDmYBWVSEjH5zqMo9RkeetQpYPOiLoeJPMhh2mIgLpHq2\n" \
"uYsgjsss9dsYcrrWlF8SOD9l4GhLADDw1D7UsQ89qQn+rd1CIX1NIPqfwo3dN/Bi\n" \
"4J1Sb0ECgYEA2Mg9+V6P/K0fKATk1bcjnQ3ig0RXHHvijjmxGG6ZFSKPY2K4Ntu1\n" \
"O6lEy00FTH7S/gaKP/msJkoJxIaCf/acSCmk29crLM7zVXmyAb2N2XIrm0Via6zq\n" \
"cjb1DCR1Igg5Jq9rp5h0IhC969zhF+7URW12tMBJkGuQYGJR8X1FW+ECgYEAwCj1\n" \
"9dN1y5GGMS0LqlFWRvCH39nAPoTGsOuXNlKG3qVOtHJO6+eFM2A/JYDAXltyybHX\n" \
"Udy7Ly9H+1S/D8GGArsTgd85mErcLisbtBGIgQDkL0gXkUdgmmVYQo+7eUbWAb5M\n" \
"Fe5tYdOc/54axQ7foIPmsW4TP0HaQeX+OB476qcCgYBd9f0WtywFwyv79pMRJv4i\n" \
"tr/1UYvIZtH9/3eJNXbYuFAaLdHWxUg6gdW1oL6pN1dQj5kgvaEmP3UYX4z01flL\n" \
"NfGk8BBgrZq+8656HqT7GQdZl6tfLGW596QjDTJP++x5nhM1Y1kC4urO7sAJ1ZTg\n" \
"Ot/23FmGZXkArd0CpN+JQQKBgQC6/mEzgj6sBYYfjqU+bX5W9DRU+pJghFbRzcDN\n" \
"ZQvH1/e6E06HtDnj3/IzLZKFf9o5Oi29hN5GsW0Lv9FZpMojGCeIh1CFybtv1hVU\n" \
"aod6egKTnEUK4/m25Y4436PhBbS155gk82tP+lxaR2Hnh2zIx/KTkPl74jphTE3S\n" \
"EGHgGwKBgCYlVJ9lNr/Dz5Kax6YRzU5W2zgd67FHrnZKgtD20x7neAuRlCNiAbW/\n" \
"SpHGTY9U4ETvEjWSIiRcEuyB78ex3g3Evt8+KNmtDQA0Y1i+i/eyCQsjmi8Q6RCf\n" \
"AbUUj/N5qoIkkAVHQHl4vxUyWtXGQGXIxm9doeWTwaRu+dM0hUJi\n" \
"-----END RSA PRIVATE KEY-----\n";




//------------------------------------------------------------------

void setup_pubSub(WiFiData &d) 
{
pubSubClient.setServer(d.mqtt_server, atoi(d.mqtt_port));
pubSubClient.setCallback(fn_ReceivedCallback);

/* set SSL/TLS certificate */
espClient.setCACert(rootCABuff);
espClient.setCertificate(certificateBuff);
espClient.setPrivateKey(privateKeyBuff);
}

//------------------------------------------------------------------

void fn_ReceivedCallback(char* topic, byte* payload, unsigned int length) 
{
Serial.print("Message received: ");
Serial.println(topic);

Serial.print("payload: ");
for (int i = 0; i < length; i++) 
  Serial.print((char)payload[i]);
Serial.println();

/* we got '1' -> on */
// some actions can be taken here...
// if ((char)payload[0] == '1') 
//  digitalWrite(relePin, HIGH); 
// else   /* we got '0' -> on */
//  digitalWrite(relePin, LOW);
}

//------------------------------------------------------------------


void fn_MQTTconnect(WiFiData &d) 
{
int     counter = 0;  
char    action_tag[MAX_TEXT_LEN];

// there is a default channel (estation_name.control) 
// to subscribe for possible actions (reset, OTA, etc)
 
strcpy(action_tag, d.station_name);
strcat(action_tag, ".control");

while (!pubSubClient.connected() && counter++ < 10) 
  {
  Serial.print("MQTT connecting ...");

  if (pubSubClient.connect(d.station_name)) 
    {
    Serial.println("connected");
    pubSubClient.subscribe(action_tag);
    } 
  else 
    {
    Serial.print("Error, status code =");
    Serial.print(pubSubClient.state());
    Serial.println(" Probar de nuevo en 5 segundos");
   
    delay(2000);   // Wait 2 seconds before retrying 
    }
  }
}

//------------------------------------------------------------------
