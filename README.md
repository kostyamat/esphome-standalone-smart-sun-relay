# [🇺🇦 Українська версія](#esphome-standalone-smart-sun-relay-1)

# ESPHome Standalone Smart Sun Relay

[](https://www.google.com/search?q=https://github.com/kostyamat/esphome-standalone-smart-sun-relay/actions/workflows/ci.yaml)
[](https://www.google.com/search?q=https://github.com/kostyamat/esphome-standalone-smart-sun-relay/releases/latest)
[](https://www.google.com/search?q=./LICENSE)

An advanced controller for managing lighting (or any other load) based on ESP8266 and ESPHome. The device can operate completely standalone or be integrated with Home Assistant. The core logic is based on calculating sunrise and sunset for the current geolocation, but its flexible settings allow it to be used as a multi-functional timer.
<p align="center">
  <img src="/docs/webinterface.jpg" width="30%" />
  <img src="/docs/webinterface-.jpg" width="30%" />
  <img src="/docs/webinterface--.jpg" width="30%" />
</p>

<div style="text-align: center;">
  <span style="display: inline-block; vertical-align: top; width: 30%;">
    <img src="/docs/ha-interface.png" style="width: 100%;">
  </span>
  <span style="display: inline-block; vertical-align: top; width: 30%;">
    <img src="/docs/ha-interface-.png" style="width: 100%;">
  </span>
</div>

## 🚀 Key Features

  * **Fully Standalone:** Does not require a central server (like Home Assistant) to operate. Management is done through a built-in web interface.
  * **Three Flexible Operation Modes:**
    1.  `Sun Relay Only`: Fully automatic control based on sunrise/sunset.
    2.  `Sun Relay with Timer`: A hybrid mode where the timer can be activated at night.
    3.  `Timer only`: A manual mode where the timer can be activated at any time of day.
  * **Astronomical Calculation:** Automatically determines sunrise and sunset times based on the specified coordinates (latitude and longitude).
  * **RTC Backup Time Source:** Supports the DS1307 RTC module, allowing the device to maintain accurate time even without an internet connection.
  * **Advanced Web Interface:** Allows configuring all parameters on the fly, including:
      * Geographic coordinates and time zone (UTC).
      * Offsets for sunrise/sunset times.
      * Timer duration.
      * Wi-Fi settings.
  * **Home Assistant Integration:** Provides a service to remotely trigger and restart the timer, enabling complex automations.
  * **Robust Failure Protection:** The system detects a "stuck" physical button and enters an alarm mode. The alarm is deactivated **instantly** upon resolving the issue.
  * **OTA Updates:** Supports over-the-air firmware updates via ESPHome or the web interface.

-----

## ⚙️ Operation Modes

The device supports three modes, which can be switched via the web interface.

### 1\. Sun Relay Only

This is the basic, fully automatic mode.

  * The relay **turns ON** at sunset (considering the offset).
  * The relay **turns OFF** at sunrise (considering the offset).
  * The physical button and timer are inactive in this mode.

### 2\. Sun Relay with Timer

A hybrid mode, ideal for passageways (corridors, stairs) during the night.

  * **During the day:** The relay is always off.
  * **At night:** The relay is off by default. The light can be turned on for a specified duration (e.g., 60 seconds) by pressing the physical button or calling the Home Assistant service. The light will automatically turn off after the countdown finishes.

### 3\. Timer only

A fully manual mode that ignores sunrise and sunset times.

  * The relay is always off by default.
  * The light can be turned on for a specified duration **at any time of day** by pressing the physical button or calling the Home Assistant service.

-----

## 🔌 Home Assistant Integration

After adding the device to Home Assistant, a special service for controlling the timer becomes available.

**Service:** `esphome.<device_name>_button_press`

**Capabilities:**

  * **Start Timer:** Activates the timer just like the physical button.
  * **Restart Timer:** If the timer is already running, calling this service will **restart** the countdown from the beginning.

**Service Logic:**

  * In `Sun Relay with Timer` mode: Will only work **at night**.
  * In `Timer only` mode: Will work **at any time of day**.
  * In `Sun Relay Only` mode: The service call will be ignored.

**Example Automation in Home Assistant (automation.yaml):**

```yaml
- alias: "Activate corridor light when motion detected at night"
  trigger:
    - platform: state
      entity_id: binary_sensor.motion_detector
      to: 'on'
  action:
    - service: esphome.sun_lights_controller_button_press
```

-----

## 🖥️ Web Interface Controls

### Time & Sources

  * **Current Time:** The device's current time, considering the UTC offset.
  * **Time Source:** The source of time (SNTP, RTC, Manual).
  * **Next Sunrise/Sunset:** The calculated time for the next sunrise/sunset.
  * **Set Local Time:** A field for manually setting the date and time.

### Location & Offset

  * **Latitude / Longitude:** Geographic coordinates for sun calculations.
  * **UTC Offset Hours:** The offset of your time zone from UTC.
  * **Sunrise/Sunset Offset Hours:** An additional offset in hours to fine-tune the relay's ON/OFF times.

### Control

  * **Operation Mode:** Select one of the three operation modes.
  * **Auto Mode:** A master switch for all automations.
  * **Relay:** Manual control of the relay state.
  * **Light On Duration:** Sets the timer duration in seconds.
  * **💡Control Status:** An informational sensor showing the current system status (e.g., "🌙 Night: Light is ON" or "Countdown: 45s ⏱️").

### WiFi control

  * **New Wi-Fi SSID / Password:** Fields for changing the Wi-Fi network without re-flashing the device.

-----

## 🛠️ Hardware

  * **Microcontroller:** Wemos D1 Mini (or any other ESP8266-based board).
  * **Relay:** A standard relay module for Arduino/ESP.
  * **Button:** Any non-latching tactile button.
  * **(Optional) RTC Module:** DS1307 Real-Time Clock.

**Connections:**

  * Relay: `D3`
  * Button: `D6`
  * DS1307 SDA: `D2`
  * DS1307 SCL: `D1`
![](/docs/Schematic_Sun-Relay-with-Timer.png)

## 📚 Dependencies

  * **ESPHome:** Version 2023.8.0 or newer.
  * **(Optional) Home Assistant:** To use the remote control service.

## 📦 Installation

1.  Place the `sun-relay.yaml` and the required `sun_functions.h` file in your ESPHome configuration directory.
2.  Create a `secrets.yaml` file to add your Wi-Fi credentials.
3.  Compile and upload the firmware to your device.
    ```bash
    esphome run sun-relay.yaml
    ```
# [User guide](/docs/GUIDE.md)
-----

-----

# ESPHome Standalone Smart Sun Relay

[](https://www.google.com/search?q=https://github.com/kostyamat/esphome-standalone-smart-sun-relay/actions/workflows/ci.yaml)
[](https://www.google.com/search?q=https://github.com/kostyamat/esphome-standalone-smart-sun-relay/releases/latest)
[](https://www.google.com/search?q=./LICENSE)

Просунутий контролер для керування освітленням (або будь-яким іншим навантаженням) на базі ESP8266 та ESPHome. Пристрій може працювати як повністю автономно, так і в інтеграції з Home Assistant. Основна логіка базується на розрахунку сходу та заходу сонця для поточної геолокації, але гнучкі налаштування дозволяють використовувати його як багатофункціональний таймер.

*(Примітка: На скріншоті показана попередня версія інтерфейсу. Нова версія містить додатковий режим "Timer only" у списку "Operation Mode".)*

## 🚀 Ключові можливості

  * **Повністю автономний:** Не потребує центрального сервера (як Home Assistant) для роботи. Керування здійснюється через вбудований веб-інтерфейс.
  * **Три гнучкі режими роботи:**
    1.  `Sun Relay Only`: Повністю автоматичне керування на основі сходу/заходу сонця.
    2.  `Sun Relay with Timer`: Гібридний режим, де таймер можна активувати вночі.
    3.  `Timer only`: Ручний режим, де таймер можна активувати в будь-який час доби.
  * **Астрономічний розрахунок:** Автоматично визначає час сходу та заходу сонця на основі вказаних координат (широти та довготи).
  * **Резервне джерело часу (RTC):** Підтримує модуль DS1307 RTC, що дозволяє пристрою зберігати точний час навіть за відсутності підключення до Інтернету.
  * **Розширений веб-інтерфейс:** Дозволяє налаштовувати всі параметри "на льоту", включаючи:
      * Географічні координати та часовий пояс (UTC).
      * Зміщення для часу сходу/заходу сонця.
      * Тривалість таймера.
      * Налаштування Wi-Fi.
  * **Інтеграція з Home Assistant:** Надає сервіс для дистанційного запуску/перезапуску таймера, що дозволяє створювати складні автоматизації.
  * **Надійний захист від збоїв:** Система виявляє "залипання" фізичної кнопки та переходить у режим тривоги. Скасування тривоги відбувається **миттєво** після усунення проблеми.
  * **OTA Оновлення:** Підтримка оновлення прошивки "по повітрю" через ESPHome або веб-інтерфейс.

-----

## ⚙️ Режими роботи

Пристрій підтримує три режими, які можна перемикати через веб-інтерфейс.

### 1\. Sun Relay Only

Це базовий, повністю автоматичний режим.

  * Реле **вмикається** на заходи сонця (з урахуванням зміщення).
  * Реле **вимикається** на сході сонця (з урахуванням зміщення).
  * Фізична кнопка та таймер у цьому режимі неактивні.

### 2\. Sun Relay with Timer

Гібридний режим, ідеальний для прохідних зон (коридорів, сходів) у нічний час.

  * **Вдень:** Реле завжди вимкнене.
  * **Вночі:** Реле вимкнене за замовчуванням. Світло можна увімкнути на заданий час (наприклад, 60 секунд), натиснувши фізичну кнопку або викликавши сервіс з Home Assistant. Після закінчення зворотного відліку світло автоматично вимкнеться.

### 3\. Timer only

Повністю ручний режим, що ігнорує час сходу/заходу сонця.

  * Реле завжди вимкнене за замовчуванням.
  * Світло можна увімкнути на заданий час **у будь-який час доби**, натиснувши фізичну кнопку або викликавши сервіс з Home Assistant.

-----

## 🔌 Інтеграція з Home Assistant

Після додавання пристрою в Home Assistant стає доступним спеціальний сервіс для керування таймером.

**Сервіс:** `esphome.<device_name>_button_press`

**Можливості:**

  * **Запуск таймера:** Активує таймер так само, як і фізична кнопка.
  * **Перезапуск таймера:** Якщо таймер вже працює, виклик цього сервісу **перезапустить** зворотний відлік з самого початку.

**Логіка роботи сервісу:**

  * У режимі `Sun Relay with Timer`: Спрацює **тільки вночі**.
  * У режимі `Timer only`: Спрацює **в будь-який час доби**.
  * У режимі `Sun Relay Only`: Виклик сервісу буде проігноровано.

**Приклад автоматизації в Home Assistant (automation.yaml):**

```yaml
- alias: "Activate corridor light when motion detected at night"
  trigger:
    - platform: state
      entity_id: binary_sensor.motion_detector
      to: 'on'
  action:
    - service: esphome.sun_lights_controller_button_press
```

-----

## 🖥️ Елементи керування у веб-інтерфейсі

### Time & Sources

  * **Current Time:** Поточний час пристрою з урахуванням UTC зміщення.
  * **Time Source:** Джерело часу (SNTP, RTC, Manual).
  * **Next Sunrise/Sunset:** Розрахунковий час наступного сходу/заходу сонця.
  * **Set Local Time:** Поле для ручного встановлення дати та часу.

### Location & Offset

  * **Latitude / Longitude:** Географічні координати для розрахунку сонця.
  * **UTC Offset Hours:** Зміщення вашого часового поясу відносно UTC.
  * **Sunrise/Sunset Offset Hours:** Додаткове зміщення в годинах для точного налаштування часу ввімкнення/вимкнення реле.

### Control

  * **Operation Mode:** Вибір одного з трьох режимів роботи.
  * **Auto Mode:** Головний вимикач для всіх автоматизацій.
  * **Relay:** Ручне керування станом реле.
  * **Light On Duration:** Встановлення тривалості таймера в секундах.
  * **💡Control Status:** Інформаційний сенсор, що показує поточний стан системи (наприклад, "🌙 Night: Light is ON" або "Countdown: 45s ⏱️").

### WiFi control

  * **New Wi-Fi SSID / Password:** Поля для зміни мережі Wi-Fi без перепрошивки пристрою.

-----

## 🛠️ Апаратне забезпечення

  * **Мікроконтролер:** Wemos D1 Mini (або будь-яка інша плата на базі ESP8266).
  * **Реле:** Стандартний релейний модуль для Arduino/ESP.
  * **Кнопка:** Будь-яка тактова кнопка без фіксації.
  * **(Опціонально) RTC Модуль:** DS1307 Real-Time Clock.

**Підключення:**

  * Реле: `D3`
  * Кнопка: `D6`
  * DS1307 SDA: `D2`
  * DS1307 SCL: `D1`

![](/docs/Schematic_Sun-Relay-with-Timer_UA.png)

## 📚 Залежності

  * **ESPHome:** Версія 2023.8.0 або новіша.
  * **(Опціонально) Home Assistant:** Для використання сервісу дистанційного керування.

## 📦 Встановлення

1.  Розмістіть файли `sun-relay.yaml` та `sun_functions.h` в одній директорії конфігурації ESPHome.
2.  Створіть файл `secrets.yaml`, щоб додати облікові дані вашої мережі Wi-Fi.
3.  Скомпілюйте та завантажте прошивку на ваш пристрій.
    ```bash
    esphome run sun-relay.yaml
    ```
# [User guide](/docs/GUIDE.md)
