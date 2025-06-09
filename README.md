# COVID-19-Social-Distance-Monitoring-and-Contact-Tracing
COVID-19 Social Distance Monitoring and Contact Tracing

The COVID-19 patient can monitor his own condition at any time, though this he can save the life.
Sensor technology is to be used for monitoring the COVID-19 patient condition easily. Temperature: For the temperature we have 2 domains, the cold air and the hot air. The patients are mostly exposed to cold air after exercising. It is advised to avoid temperatures below 18°C. The temperature of 15°C and below is considered risky. The hot air is by itself dangerous. It also helps contain pollen and air pollution. It is advised to avoid temperatures above 27°C. The temperature of 30°C and above is considered also risky for the COVID-19tic patients.
The system uses microcontroller. A SPO2 sensor ,and Temperature sensor are connected to the Microcontroller. The temperature sensor gives the temperature value in degree Celsius. To measure the heart rate, the heart beat/pulse is detected and the number of pulses for one minute is counted to get the beats per minute. Light (using an LED) is passed from one side of the finger and the intensity of light received on the other side is measured (using an LDR).The GPS and Nodemcu modules are interfaced with the microcontroller. The GPS module finds out the latitude and longitude of the patient. The temperature and Spo2 values are measured and compared with a configurable threshold to be classified as “low”, “normal” or “high”. The Nodemcu module is used to send a message to the doctor’s mobile in case of emergencies. The message contains the temperature, Spo2 values and the patient’s latitude and longitude. The doctor can thus take immediate action with the help of this alert system and if in case of changing the position of covid Patient also detect by using GPS value and send alert to the concern persons.
While the symptoms described in the above are typical indicators of COVID-19, not all people suffer in the same way or the same combination of these symptoms. Research shows that some people may have the coughing, wheezing, chest tightness and shortness of breath, while others may have a different combination of the symptoms at different times [10]. Sometimes during an attack, some of the symptoms will be worse than others, and even vary from one episode to another. Some are mild and generally more common, while some are more serious. The life-threatening attacks may be less common, but they also may last longer in length and require emergency medical care

The measurement results are transmitted via a wireless interface to a PC, tablet or smartphone and are recorded in an electronic diary or, for example, can be used to train a neural network. This will allow for the accumulation of data to adapt the program of processing results for a specific patient and more accurately monitor the change in its health. When the measurement results exceed the set limits, an alarm is generated, which is displayed as a message on the screen of the mobile device and can be sent to the email address of the medical center.
The described individual system can be useful for continuous express monitoring of the condition of a person suffering from COVID-19 during the day and warning him about the need to take medicine. In addition, it can be useful in medical institutions for monitoring the condition of a patient in hospital, and monitoring the effects of drugs.

	•	SYSTEM REQUIREMENTS

HARDWARE REQUIREMENTS

 Arduino NANO
 SPO2 Sensor
 Temperature Sensor
  ESP 8266
  Load cell
 Power Supply
 Ultrasonic sensor



SOFTWARE REQUIREMENTS

 Embedded C
 Arduino Suite

Functional Requirements:

System should scan & Detect the COVID-19 patient condition
System should measure the heart beat & temperature.
System should self-monitoring allows the early detection of exacerbations.
System should automatically investigate reasons for poor control.
