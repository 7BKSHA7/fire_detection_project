#ifndef LED_PRIVATE_H
#define LED_PRIVATE_H

#define LED_STATE_NORMAL        0   //this state for green led , normal state (no fire ,no smoke )
#define LED_STATE_WARNING       1   //this state for yellow led, Activated when:(Temperature approaches threshold , Slight smoke detected)
#define LED_STATE_NOTICE_FIRE   2   //this state for red led (Temperature exceeds limit , Heavy smoke detected, Flame detected)
#define LED_STATE_EMERGENCY     3   //this state for red led but blinking (Critical state requiring immediate action)

#endif
