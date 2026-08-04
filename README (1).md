<div align="center">

# 🔥 Fire Detection System

### Embedded Fire & Smoke Detection using ATmega32

*A layered-architecture embedded system that continuously monitors temperature and smoke levels, classifies hazard severity, and triggers alarms automatically.*

[![Platform](https://img.shields.io/badge/Platform-ATmega32-orange?style=flat-square)]()
[![Language](https://img.shields.io/badge/Language-Embedded%20C-blue?style=flat-square)]()
[![License](https://img.shields.io/badge/License-MIT-green?style=flat-square)]()
[![Status](https://img.shields.io/badge/Status-Active-brightgreen?style=flat-square)]()

</div>

---

## 👥 Team 7 — *Resistors on Fire*

| Role | Name |
|---|---|
|  Team Leader | **Eng. Hesham Ahmed** |
|  Member | Beshoy Esmat |
|  Member | Yousef Medhat |
|  Member | Ali Mohamed |
|  Member | Rohayem Moataz |
|  Member | Moaz Ahmed |

---

## 📖 Overview

The **Fire Detection System** is an embedded application built on the **ATmega32** microcontroller. It continuously reads room temperature and smoke levels, displays live status on an LCD, and escalates through a series of alarm states — from normal conditions all the way to emergency — using a clean **layered software architecture** (APP / HAL / MCAL / LIB).

---

## 🎯 Objectives

- [x] Continuously monitor environmental conditions
- [x] Detect possible fire hazards
- [x] Classify warning severity
- [x] Trigger alarms automatically
- [x] Display system status
- [x] Allow user acknowledgment
- [x] Log important events
- [x] Support serial diagnostics
- [x] Implement reliable safety logic
- [x] Build a modular embedded software architecture

---

## 🚨 Alarm Levels

| Level | State | Description |
|:---:|---|---|
| 🟢 0 | **Normal** | Environment is safe, system idle-monitoring |
| 🟡 1 | **Warning** | Elevated readings detected, keep watching |
| 🟠 2 | **Fire Detected** | Fire-range temperature/smoke, alarm active |
| 🔴 3 | **Emergency** | Critical levels — full alarm, requires user acknowledgment |

---

## 🗂️ Project Structure

```
Fire_Detection_System/
│
├── APP/
│   ├── main.c
│   ├── Fire_detection/
│   │   ├── Emergency/
│   │   ├── Fire/
│   │   ├── Normal/
│   │   └── Warning/
│   └── Safety_Manager/
│       ├── System/
│       ├── EventLogger/
│       ├── Monitoring/
│       └── Recovery/
│
├── HAL/
│   ├── LCD/
│   ├── LM35/
│   ├── MQ2/
│   ├── LED/
│   ├── Buzzer/
│   └── Button/
│
├── MCAL/
│   ├── ADC/
│   ├── DIO/
│   ├── UART/
│   ├── TIMER/
│   └── EXTI/
│
├── LIB/
│   ├── STD_TYPES.h
│   └── BIT_MATH.h
│
└── README.md
```

> **Architecture layers, bottom-up:**
> **LIB** (shared types/macros) → **MCAL** (microcontroller peripherals) → **HAL** (sensors & actuators) → **APP** (fire-detection logic & safety management)

---

## 🛠️ Tools & Technologies

| Tool | Purpose |
|---|---|
|  VS Code | Writing and editing the code |
|  Git / GitHub | Version control and collaboration |
|  Discord | Team communication |
|  Trello | Task tracking (to-do / doing / done) |
|  Proteus | Full hardware circuit simulation |
|  SimulIDE | Quick component-level testing |
|  Embedded Builder | Building the project & catching bugs |

---

## 📚 Course Information

**Embedded Systems Diploma**

Topics covered throughout this project:

`Embedded C` · `AVR Architecture` · `ADC` · `LCD` · `UART` · `Timers` · `Interrupts` · `State Machine` · `Safety Logic` · `Driver Development`

---

## 📄 License

This project was developed during the **NTI Embedded Systems Training Program**.

Licensed under the **MIT License**.

**Project Organization:** Gestell

---

## 🙏 Acknowledgment

Special thanks to:

- 🏛️ National Telecommunication Institute (NTI)
- 👨‍🏫 Eng. Hesham Ahmed
- 🤝 Gestell Team

for their support and guidance throughout this project.

---

<div align="center">

*Made with 🔥 by Team 7 — Resistors on Fire*

</div>
