#include <Adafruit_CC3000.h>
#include <ccspi.h>
#include <SPI.h>
#include <string.h>


#define ADAFRUIT_CC3000_IRQ     3
#define ADAFRUIT_CC3000_VBAT    5
#define ADAFRUIT_CC3000_CS      10
#define WLAN_SSID               "wifi_SSID"
#define WLAN_PASS               "wifi_password"
#define WLAN_SECURITY           WLAN_SEC_WPA2


Adafruit_CC3000 cc3000 = Adafruit_CC3000( ADAFRUIT_CC3000_CS,
    ADAFRUIT_CC3000_IRQ, ADAFRUIT_CC3000_VBAT, SPI_CLOCK_DIVIDER );


char *ssid = WLAN_SSID;

if ( !cc3000.connectToAP( WLAN_SSID, WLAN_PASS, WLAN_SECURITY ) ) {
    Serial.println( F( "Failed!" ) );
    while( 1 );
}
