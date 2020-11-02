# JSON Package Details

This library is a GSM based IoT library. IoT communication pack is a JSON pack. 


### "IoT" Paketi (P101 Örnek)

```json
{
	"Device": {
		"Type": "P511",
		"ID": "0001767661",
		"Hardware": "01.01.04",
		"Firmware": "01.04.02"
	}
	"Power": {
		"Source": 1,
		"Battery": {
			"Charger": 2,
			"IV": 3.89,
			"T": 25.43,
			"AC": -51.72,
			"SOC": 17.97,
			"FB": 4000,
			"IB": 718,
			"CYC": 32
		}
	},
	"IoT": {
		"GSM": {
			"Firmware": "01.06.01",
			"Module": {
				"Brand": 1,
				"Model": "xxxxxxx",
				"Revision": "xxxx",
				"Firmware": "xxxxxxx",
				"Serial": "0001767646",
				"IMEI": "353613080341053"
			},
			"SIM": {
				"SIM_Type": 1,
				"Iccid": "8990011901130266075"
			},
			"Operator": {
				"Code": 28601,
				"dbm": -81,
				"RSSI": 11,
				"Conn_Time": 22
			}
		},
		"BT": {
			"Firmware": "01.06.01"
		},
		"RF": {
			"Firmware": "01.06.01"
		},
		"Wifi": {
			"Firmware": "01.06.01"
		}
	},
	"Data": {
		"TimeStamp": "2020-10-23  14:18:28",
		"Event": 111,
		"Environment": [
			{
				"Type": "AirTemp",
				"ID": 1,
				"Value": 22.22,
				"Min": 22.21,
				"Max": 22.23,
				"Deviation": 2.2
			},
			{
				"Type": "AirHum",
				"ID": 1,
				"Value": 22.22,
				"Deviation": 2.2
			},
			{
				"Type": "AirPres",
				"ID": 1,
				"Value": 917.22,
			},
			{
				"Type": "SoilTemp",
				"ID": 1,
				"Value": 22.22,
				"Deviation": 2.2
			},
		]
	}
}
```



---

	@ Copyright 2020-2021 Mehmet Günce Akkoyun

[![star this repo](https://githubbadges.com/star.svg?user=akkoyun&repo=GE910&style=default)](https://github.com/akkoyun/GE910) [![fork this repo](https://githubbadges.com/fork.svg?user=akkoyun&repo=GE910&style=default)](https://github.com/akkoyun/GE910/fork)

