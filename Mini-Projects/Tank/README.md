# Tank

## Install Paho
```bash
$ git clone https://github.com/eclipse/paho.mqtt.c.git 
$ cd paho.mqtt.c
$ mkdir build && cd build
$ cmake .. && make
$ sudo make install
$ sudo ldconfig
```

## Install mosquitto
```bash
sudo apt-get update
sudo apt-get install mosquitto
sudo apt-get install mosquitto-clients
```

## Monitoring topics

In this tank it is possible to monitor
"/tank/level"
"/tank/pump"
"/tank/sink"
"/tank/sensors"

```bash
$ mosquitto_sub -h localhost -t /tank/pump
```

## Sending commands to the Tank
There are two actuators a sink and a pump it is possible to control them send messages
/tank/control/sink
/tank/control/pump

```bash
mosquitto_pub -h localhost -t /tank/control/sink -m "0"
```